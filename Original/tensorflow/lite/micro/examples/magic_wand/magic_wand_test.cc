/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <iostream>
#include <fstream>
#include <string>

#include "tensorflow/lite/micro/examples/magic_wand/magic_wand_model_data.h"
#include "tensorflow/lite/micro/examples/magic_wand/ring_micro_features_data.h"
#include "tensorflow/lite/micro/examples/magic_wand/slope_micro_features_data.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/micro/testing/micro_test.h"
#include "tensorflow/lite/schema/schema_generated.h"
using namespace std;

#define BATCH 128
#define DATA_SIZE 3
#define BUFFER_SIZE 500

TF_LITE_MICRO_TESTS_BEGIN

TF_LITE_MICRO_TEST(LoadModelAndPerformInference) {
  cout << '\n';

  // Set up logging
  tflite::MicroErrorReporter micro_error_reporter;

  // Map the model into a usable data structure. This doesn't involve any
  // copying or parsing, it's a very lightweight operation.
  const tflite::Model* model = ::tflite::GetModel(g_magic_wand_model_data);
  if (model->version() != TFLITE_SCHEMA_VERSION) {
    TF_LITE_REPORT_ERROR(&micro_error_reporter,
                         "Model provided is schema version %d not equal "
                         "to supported version %d.\n",
                         model->version(), TFLITE_SCHEMA_VERSION);
  }

  // Pull in only the operation implementations we need.
  // This relies on a complete list of all the ops needed by this graph.
  // An easier approach is to just use the AllOpsResolver, but this will
  // incur some penalty in code space for op implementations that are not
  // needed by this graph.
  static tflite::MicroMutableOpResolver<5> micro_op_resolver;  // NOLINT
  micro_op_resolver.AddConv2D();
  micro_op_resolver.AddDepthwiseConv2D();
  micro_op_resolver.AddFullyConnected();
  micro_op_resolver.AddMaxPool2D();
  micro_op_resolver.AddSoftmax();

  // Create an area of memory to use for input, output, and intermediate arrays.
  // Finding the minimum value for your model may require some trial and error.
  const int tensor_arena_size = 60 * 1024;
  uint8_t tensor_arena[tensor_arena_size];

  // Build an interpreter to run the model with
  tflite::MicroInterpreter interpreter(model, micro_op_resolver, tensor_arena,
                                       tensor_arena_size,
                                       &micro_error_reporter);

  // Allocate memory from the tensor_arena for the model's tensors
  interpreter.AllocateTensors();

  // Obtain a pointer to the model's input tensor
  TfLiteTensor* input = interpreter.input(0);

  // Make sure the input has the properties we expect
  TF_LITE_MICRO_EXPECT_NE(nullptr, input);
  TF_LITE_MICRO_EXPECT_EQ(4, input->dims->size);
  // The value of each element gives the length of the corresponding tensor.
  TF_LITE_MICRO_EXPECT_EQ(1, input->dims->data[0]);
  TF_LITE_MICRO_EXPECT_EQ(128, input->dims->data[1]);
  TF_LITE_MICRO_EXPECT_EQ(3, input->dims->data[2]);
  TF_LITE_MICRO_EXPECT_EQ(1, input->dims->data[3]);
  // The input is a 32 bit floating point value
  TF_LITE_MICRO_EXPECT_EQ(kTfLiteFloat32, input->type);

  /*
  // Provide an input value
  const float* ring_features_data = g_ring_micro_f9643d42_nohash_4_data;
  TF_LITE_REPORT_ERROR(&micro_error_reporter, "%d", input->bytes);
  for (size_t i = 0; i < (input->bytes / sizeof(float)); ++i) {
    input->data.f[i] = ring_features_data[i];
  }

  for (size_t i = 0; i < (input->bytes / sizeof(float)); i+=3) {
    std::cout << "\t";
    std::cout << "Input Data " << i/3 << std::left << std::setw(27) << std::setfill(' ') << ": ";
    std::cout << "(" << std::left << std::setw(15) << std::setfill(' ') << input->data.f[i];
    std::cout << std::left << std::setw(15) << std::setfill(' ') << input->data.f[i+1];
    std::cout << input->data.f[i+2] << std::left << std::setw(15) << std::setfill(' ') << ")";
    std::cout << std::endl;
  }

  // Run the model on this input and check that it succeeds
  TfLiteStatus invoke_status = interpreter.Invoke();
  if (invoke_status != kTfLiteOk) {
    TF_LITE_REPORT_ERROR(&micro_error_reporter, "Invoke failed\n");
  }
  TF_LITE_MICRO_EXPECT_EQ(kTfLiteOk, invoke_status);

  // Obtain a pointer to the output tensor and make sure it has the
  // properties we expect.
  TfLiteTensor* output = interpreter.output(0);
  TF_LITE_MICRO_EXPECT_EQ(2, output->dims->size);
  TF_LITE_MICRO_EXPECT_EQ(1, output->dims->data[0]);
  TF_LITE_MICRO_EXPECT_EQ(4, output->dims->data[1]);
  TF_LITE_MICRO_EXPECT_EQ(kTfLiteFloat32, output->type);

  std::cout << "Ring Output Data" << std::endl;
  for(size_t i = 0; i < (output->bytes / sizeof(float)); ++i) {
    std::cout << "Output Data "<< i << ": " << output->data.f[i] << std::endl;
  }
  std::cout << std::endl;
  
  FILE *file = fopen("output.txt", "w");
  if (file == NULL)
  {
    printf("Error opening file!\n");
    exit(1);
  }
  for(size_t i = 0; i < 4; i++) {
    fprintf(file, "%.20f\n", (double)output->data.f[i]);
  }

  // There are four possible classes in the output, each with a score.
  const int kWingIndex = 0;
  const int kRingIndex = 1;
  const int kSlopeIndex = 2;
  const int kNegativeIndex = 3;

  // Make sure that the expected "Ring" score is higher than the other
  // classes.
  float wing_score = output->data.f[kWingIndex];
  float ring_score = output->data.f[kRingIndex];
  float slope_score = output->data.f[kSlopeIndex];
  float negative_score = output->data.f[kNegativeIndex];
  TF_LITE_MICRO_EXPECT_GT(ring_score, wing_score);
  TF_LITE_MICRO_EXPECT_GT(ring_score, slope_score);
  TF_LITE_MICRO_EXPECT_GT(ring_score, negative_score);

  // Now test with a different input, from a recording of "Slope".
  const float* slope_features_data = g_slope_micro_f2e59fea_nohash_1_data;
  for (size_t i = 0; i < (input->bytes / sizeof(float)); ++i) {
    input->data.f[i] = slope_features_data[i];
  }

  for (size_t i = 0; i < (input->bytes / sizeof(float)); i+=3) {
    std::cout << "\t";
    std::cout << "Input Data " << i/3 << std::left << std::setw(27) << std::setfill(' ') << ": ";
    std::cout << "(" << std::left << std::setw(15) << std::setfill(' ') << input->data.f[i];
    std::cout << std::left << std::setw(15) << std::setfill(' ') << input->data.f[i+1];
    std::cout << input->data.f[i+2] << std::left << std::setw(15) << std::setfill(' ') << ")";
    std::cout << std::endl;
  }

  // Run the model on this "Slope" input.
  invoke_status = interpreter.Invoke();
  if (invoke_status != kTfLiteOk) {
    TF_LITE_REPORT_ERROR(&micro_error_reporter, "Invoke failed\n");
  }
  TF_LITE_MICRO_EXPECT_EQ(kTfLiteOk, invoke_status);

  for (size_t i = 0; i < (input->bytes / sizeof(float)); i+=3) {
    std::cout << "\t";
    std::cout << "New input Data " << i/3 << std::left << std::setw(27) << std::setfill(' ') << ": ";
    std::cout << "(" << std::left << std::setw(15) << std::setfill(' ') << input->data.f[i];
    std::cout << std::left << std::setw(15) << std::setfill(' ') << input->data.f[i+1];
    std::cout << input->data.f[i+2] << std::left << std::setw(15) << std::setfill(' ') << ")";
    std::cout << std::endl;
  }

  // Get the output from the model, and make sure it's the expected size and
  // type.
  output = interpreter.output(0);
  TF_LITE_MICRO_EXPECT_EQ(2, output->dims->size);
  TF_LITE_MICRO_EXPECT_EQ(1, output->dims->data[0]);
  TF_LITE_MICRO_EXPECT_EQ(4, output->dims->data[1]);
  TF_LITE_MICRO_EXPECT_EQ(kTfLiteFloat32, output->type);

  std::cout << "Slope Output Data" << std::endl;
  for(size_t i = 0; i < (output->bytes / sizeof(float)); ++i) {
    std::cout << "Output Data "<< i << ": " << output->data.f[i] << std::endl;
  }
  std::cout << std::endl;
  for(size_t i = 0; i < 4; i++) {
    fprintf(file, "%.20f\n", (double)output->data.f[i]);
  }
  fclose(file);

  // Make sure that the expected "Slope" score is higher than the other classes.
  wing_score = output->data.f[kWingIndex];
  ring_score = output->data.f[kRingIndex];
  slope_score = output->data.f[kSlopeIndex];
  negative_score = output->data.f[kNegativeIndex];
  TF_LITE_MICRO_EXPECT_GT(slope_score, wing_score);
  TF_LITE_MICRO_EXPECT_GT(slope_score, ring_score);
  TF_LITE_MICRO_EXPECT_GT(slope_score, negative_score);*/


    FILE * file, *out;

    file = fopen("tensorflow/lite/micro/examples/magic_wand/data/negative/output_teste.txt", "r");
    if (NULL == file) {
        printf("Error opening file!\n");
        exit(1);
    }

    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char buff[BUFFER_SIZE];
    bool init = true, isReading = false, wasReading = false;
    float dt[BATCH][DATA_SIZE];
    int i, cnt = 0;

    for (i = 0; i < BATCH; i++) {
        dt[i][0] = 0;
        dt[i][1] = 0;
        dt[i][2] = 0;
    }

    while (fgets(buff, BUFFER_SIZE, file) != NULL) {
        if (wasReading && !isReading) {

            cnt *= 3;
            for (i = 0; i < cnt; i+=3) {
                input->data.f[BATCH*DATA_SIZE-cnt+i] = dt[i/3][0];
                input->data.f[BATCH*DATA_SIZE-cnt+i+1] = dt[i/3][1];
                input->data.f[BATCH*DATA_SIZE-cnt+i+2] = dt[i/3][2];
            }
            for (i = cnt; i < BATCH*DATA_SIZE; i+=3) {
                input->data.f[i-cnt] = 0.0;
                input->data.f[i-cnt+1] = 0.0;
                input->data.f[i-cnt+2] = 0.0;
            }

            /*std::cout << std::endl;
            for (size_t j = 0; j < (input->bytes / sizeof(float)); j+=3) {
                std::cout << "\t";
                std::cout << "Input Data " << j/3 << std::left << std::setw(27) << std::setfill(' ') << ": ";
                std::cout << "(" << std::left << std::setw(15) << std::setfill(' ') << input->data.f[j];
                std::cout << std::left << std::setw(15) << std::setfill(' ') << input->data.f[j+1];
                std::cout << input->data.f[j+2] << std::left << std::setw(15) << std::setfill(' ') << ")";
                std::cout << std::endl;
            }*/
            std::cout << std::endl;

            // Run the model on this input and check that it succeeds
            TfLiteStatus invoke_status = interpreter.Invoke();
            if (invoke_status != kTfLiteOk) {
                TF_LITE_REPORT_ERROR(&micro_error_reporter, "Invoke failed\n");
            }
            TF_LITE_MICRO_EXPECT_EQ(kTfLiteOk, invoke_status);

            // Obtain a pointer to the output tensor and make sure it has the
            // properties we expect.
            TfLiteTensor* output = interpreter.output(0);
            TF_LITE_MICRO_EXPECT_EQ(2, output->dims->size);
            TF_LITE_MICRO_EXPECT_EQ(1, output->dims->data[0]);
            TF_LITE_MICRO_EXPECT_EQ(4, output->dims->data[1]);
            TF_LITE_MICRO_EXPECT_EQ(kTfLiteFloat32, output->type);

            for(size_t j = 0; j < (output->bytes / sizeof(float)); ++j) {
                std::cout << "Output Data "<< j << ": " << output->data.f[j] << std::endl;
            }
            std::cout << std::endl;

            for(size_t j = 0; j < 4; j++) {
                fprintf(out, "%.30f\n", (double)output->data.f[j]);
            }
            fprintf(out, "\n");

            for (i = 0; i < DATA_SIZE; i++) {
                dt[0][i] = 0;
                dt[1][i] = 0;
                dt[2][i] = 0;
            }
            cnt = 0;
        }
        wasReading = isReading;

        if (strcmp(buff, " -,-,-\n") == 0 || strcmp(buff, "-,-,-\n") == 0) isReading = true;
        else if (strcmp(buff, "\n") == 0) isReading = false;
        else if (isReading){
            float f1, f2, f3;
            isReading = false;

            char *pt = strtok(buff, ",");
            if (pt != NULL) {
                f1 = strtof(pt, NULL);
            } else continue;
            pt = strtok(NULL, ",");
            if (pt != NULL) {
                f2 = strtof(pt, NULL);
            } else continue;
            pt = strtok(NULL, ",");
            if (pt != NULL) {
                f3 = strtof(pt, NULL);
            } else continue;

            if (init) init = false;

            dt[cnt][0] = f1;
            dt[cnt][1] = f2;
            dt[cnt][2] = f3;
            cnt++;
            if (cnt == 128) isReading = false;
            else isReading = true;
        }
    }

    cnt *= 3;
    for (i = 0; i < cnt; i+=3) {
        input->data.f[BATCH*DATA_SIZE-cnt+i] = dt[i/3][0];
        input->data.f[BATCH*DATA_SIZE-cnt+i+1] = dt[i/3][1];
        input->data.f[BATCH*DATA_SIZE-cnt+i+2] = dt[i/3][2];
    }

    for (i = cnt; i < BATCH*DATA_SIZE; i+=3) {
        input->data.f[i-cnt] = 0.0;
        input->data.f[i-cnt+1] = 0.0;
        input->data.f[i-cnt+2] = 0.0;
    }

    /*std::cout << std::endl;
    for (size_t j = 0; j < (input->bytes / sizeof(float)); j+=3) {
        std::cout << "\t";
        std::cout << "Input Data " << j/3 << std::left << std::setw(27) << std::setfill(' ') << ": ";
        std::cout << "(" << std::left << std::setw(15) << std::setfill(' ') << input->data.f[j];
        std::cout << std::left << std::setw(15) << std::setfill(' ') << input->data.f[j+1];
        std::cout << input->data.f[j+2] << std::left << std::setw(15) << std::setfill(' ') << ")";
        std::cout << std::endl;
    }*/
    std::cout << std::endl;

    // Run the model on this input and check that it succeeds
    TfLiteStatus invoke_status = interpreter.Invoke();
    if (invoke_status != kTfLiteOk) {
        TF_LITE_REPORT_ERROR(&micro_error_reporter, "Invoke failed\n");
    }
    TF_LITE_MICRO_EXPECT_EQ(kTfLiteOk, invoke_status);

    // Obtain a pointer to the output tensor and make sure it has the
    // properties we expect.
    TfLiteTensor* output = interpreter.output(0);
    TF_LITE_MICRO_EXPECT_EQ(2, output->dims->size);
    TF_LITE_MICRO_EXPECT_EQ(1, output->dims->data[0]);
    TF_LITE_MICRO_EXPECT_EQ(4, output->dims->data[1]);
    TF_LITE_MICRO_EXPECT_EQ(kTfLiteFloat32, output->type);

    for(size_t j = 0; j < (output->bytes / sizeof(float)); ++j) {
        std::cout << "Output Data "<< j << ": " << output->data.f[j] << std::endl;
    }
    std::cout << std::endl;

    for(size_t j = 0; j < 4; j++) {
        fprintf(out, "%.30f\n", (double)output->data.f[j]);
    }

    fclose(file);
    fclose(out);
}

TF_LITE_MICRO_TESTS_END
