/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;

/* Structure contents */
struct l_struct_OC__iobuf {
   char *field0;
  unsigned int field1;
   char *field2;
  unsigned int field3;
  unsigned int field4;
  unsigned int field5;
  unsigned int field6;
   char *field7;
};


/* External Global Variable Declarations */
extern float data1[128][3];
extern float firstKernel[8][4][3];
extern float firstBias[8];
extern float secondKernel[16][4][8];
extern float secondBias[16];
extern float firstDense[16][14][16];
extern float thirdBias[16];
extern float secondDense[4][16];
extern float fourthBias[4];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
l_struct_OC__iobuf *openFile( char *llvm_cbe_name,  char *llvm_cbe_mode);
void closeFile(l_struct_OC__iobuf *llvm_cbe_file);
void readFile(l_struct_OC__iobuf *llvm_cbe_file);
void convolution1(signed int , signed int , float *, signed int , signed int , signed int , float *, float *, float *);
void printData3D(signed int , signed int , signed int , float *);
void maxPool(signed int , signed int , signed int , float *, signed int , signed int , float *, signed int , signed int );
void convolution2(signed int , signed int , signed int , float *, signed int , signed int , signed int , float *, float *, float *);
void dense1(signed int , signed int , signed int , float *, signed int , signed int , signed int , float *, float *, signed int , float *);
void dense2(signed int , float *, signed int , signed int , float *, float *, signed int , float *);
void softmax(signed int , float *, float *);
void printData2D(signed int , signed int , float *);


/* Global Variable Definitions and Initialization */
float data1[128][3] = { { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { 0x0p0, 0x0p0, 0x0p0 }, { -0x1.4c8p9, 0x1.c8p7, 0x1.9d8p9 }, { -0x1.54p9, 0x1.53p8, 0x1.66p9 }, { -0x1.54p9, 0x1.1ap9, 0x1.96p9 }, { -0x1.538p9, 0x1.14p9, 0x1.99p9 }, { -0x1.4c8p9, 0x1.08p9, 0x1.778p9 }, { -0x1.49p9, 0x1.bp8, 0x1.35p9 }, { -0x1.478p9, 0x1.bdp8, 0x1.28p9 }, { -0x1.4d8p9, 0x1.e4p8, 0x1.16p9 }, { -0x1.56p9, 0x1.27p9, 0x1.fep8 }, { -0x1.51p9, 0x1.5p9, 0x1.dbp8 }, { -0x1.4ap9, 0x1.89p9, 0x1.86p8 }, { -0x1.19p9, 0x1.19p10, 0x1p7 }, { -0x1.07p9, 0x1.1dp10, 0x1.bcp6 }, { -0x1.e6p8, 0x1.05p10, 0x1.08p5 }, { -0x1.ap8, 0x1.46p9, -0x1.0cp7 }, { -0x1.86p8, 0x1.0bp9, -0x1.1ep7 }, { -0x1.6dp8, 0x1.7dp8, -0x1.d4p6 }, { -0x1.3ap8, 0x1.ep5, 0x1.78p6 }, { -0x1.42p8, 0x1.cp2, 0x1.7cp7 }, { -0x1.52p8, -0x1.7cp6, 0x1.56p8 }, { -0x1.68p8, -0x1.a8p6, 0x1.a5p9 }, { -0x1.5fp8, -0x1.48p5, 0x1.e28p9 }, { -0x1.6p8, 0x1.8p3, 0x1.ep9 }, { -0x1.6ep8, 0x1.5p5, 0x1.19p10 }, { -0x1.42p8, 0x1.cp5, 0x1.268p10 }, { -0x1.38p8, 0x1.ep3, 0x1.4e8p10 }, { -0x1.fcp7, 0x1.4p3, 0x1.7fp10 }, { -0x1.e2p7, 0x1.4p2, 0x1.8d8p10 }, { -0x1.c6p7, 0x1.ep5, 0x1.874p10 }, { -0x1.98p7, 0x1.1ap8, 0x1.86p10 }, { -0x1.68p7, 0x1.06p8, 0x1.7dp10 }, { -0x1.14p7, 0x1.81p8, 0x1.7c8p10 }, { -0x1.5p6, 0x1.2ap9, 0x1.968p10 }, { -0x1.b8p5, 0x1.3f8p9, 0x1.91p10 }, { -0x1.3p4, 0x1.818p9, 0x1.79cp10 }, { 0x1p4, 0x1.d2p9, 0x1.1bp10 }, { 0x1.ep3, 0x1.cep9, 0x1.fa8p9 }, { 0x1p0, 0x1.a88p9, 0x1.96p9 }, { -0x1.6p6, 0x1.3ap9, 0x1.f4p8 }, { -0x1.c8p6, 0x1.308p9, 0x1.cfp8 }, { -0x1.36p7, 0x1.178p9, 0x1.7ep8 }, { -0x1.d4p7, 0x1.a4p8, 0x1.16p8 }, { -0x1.fcp7, 0x1.86p8, 0x1.1p8 }, { -0x1.47p8, 0x1.9p7, 0x1.5p8 }, { -0x1.17p9, -0x1.16p9, 0x1.3bp9 }, { -0x1.4p9, -0x1.2f8p9, 0x1.72p9 }, { -0x1.61p9, -0x1.aep8, 0x1.b2p9 }, { -0x1.85p9, 0x1.5p5, 0x1.048p10 }, { -0x1.7d8p9, 0x1.5p6, 0x1.e68p9 }, { -0x1.6f8p9, 0x1.72p7, 0x1.d18p9 }, { -0x1.55p9, 0x1.f8p7, 0x1.7fp9 }, { -0x1.508p9, 0x1.ccp7, 0x1.7a8p9 }, { -0x1.4f8p9, 0x1.b4p7, 0x1.7a8p9 }, { -0x1.48p9, 0x1.bcp7, 0x1.65p9 }, { -0x1.498p9, 0x1.dcp7, 0x1.75p9 }, { -0x1.4p9, 0x1.14p8, 0x1.6d8p9 }, { -0x1.3dp9, 0x1.acp7, 0x1.79p9 }, { -0x1.3e8p9, 0x1.9ep7, 0x1.6f8p9 }, { -0x1.3e8p9, 0x1.84p7, 0x1.73p9 }, { -0x1.3dp9, 0x1.fp7, 0x1.66p9 }, { -0x1.3b8p9, 0x1.09p8, 0x1.5c8p9 }, { -0x1.3ap9, 0x1.f8p7, 0x1.8e8p9 }, { -0x1.28p9, 0x1.98p7, 0x1.98p9 }, { -0x1.35p9, 0x1.b4p7, 0x1.96p9 }, { -0x1.3c8p9, 0x1.cep7, 0x1.9ep9 }, { -0x1.4p9, 0x1.bcp7, 0x1.7p9 }, { -0x1.3dp9, 0x1.bap7, 0x1.898p9 } };
float firstKernel[8][4][3] = { { { -0x1.ecd438p-4, -0x1.79bb8ep-8, 0x1.8de21ep-3 }, { -0x1.4e23acp-7, -0x1.4342e8p-4, 0x1.5bbc2ep-4 }, { -0x1.d0976ap-6, 0x1.4b72fcp-6, 0x1.55467cp-5 }, { 0x1.254eb4p-4, -0x1.5dbfc6p-4, -0x1.b41de2p-4 } }, { { 0x1.fa2d54p-6, -0x1.49390ep-3, -0x1.057a38p-1 }, { 0x1.e6fd98p-4, -0x1.3a918ep-3, -0x1.e9ddaep-5 }, { -0x1.b80a9p-3, 0x1.92e09cp-3, 0x1.62e742p-5 }, { -0x1.6ac17p-3, -0x1.b2bdp-3, -0x1.70129p-2 } }, { { 0x1.41b3ecp-3, -0x1.d410e4p-5, 0x1.0f78acp-3 }, { 0x1.549be6p-4, 0x1.64a674p-8, 0x1.84b96cp-4 }, { 0x1.1bf55ep-3, -0x1.25fc72p-3, -0x1.078f9p-5 }, { 0x1.1fbf4ep-4, -0x1.802b1p-4, -0x1.9bc55ap-3 } }, { { 0x1.bbf0c8p-4, 0x1.c2362p-3, -0x1.7324c6p-3 }, { 0x1.511578p-3, -0x1.4aa324p-4, -0x1.cb1238p-3 }, { 0x1.4908e8p-4, -0x1.0317f4p-3, -0x1.5ee20ep-4 }, { 0x1.85f978p-3, -0x1.550dd4p-4, -0x1.324cd2p-2 } }, { { -0x1.05800ep-2, -0x1.3092f2p-3, 0x1.09bc9cp-2 }, { -0x1.b56b44p-4, -0x1.7988d4p-5, 0x1.9189fap-3 }, { 0x1.090898p-3, -0x1.cd1d72p-6, -0x1.56d764p-3 }, { -0x1.fb0c84p-7, 0x1.c89476p-5, -0x1.9a790cp-2 } }, { { -0x1.71473cp-5, -0x1.1013b4p-2, -0x1.1070c8p-4 }, { -0x1.6c3524p-4, -0x1.dac3b6p-5, 0x1.265364p-5 }, { 0x1.74f412p-6, -0x1.665f9p-4, -0x1.3f840cp-3 }, { 0x1.b1a074p-6, -0x1.844b12p-3, -0x1.9dcc0ap-5 } }, { { 0x1.428226p-4, 0x1.9ae05ap-5, -0x1.86654p-4 }, { 0x1.629334p-4, -0x1.073efp-3, 0x1.26ad98p-5 }, { 0x1.0f4d66p-3, -0x1.3c5636p-4, -0x1.617e76p-3 }, { -0x1.808bd4p-7, -0x1.265384p-2, 0x1.f71fb6p-4 } }, { { -0x1.21036p-4, -0x1.3c94b8p-4, -0x1.6f281ep-2 }, { 0x1.3927f8p-5, -0x1.603e8p-5, -0x1.379dfp-7 }, { 0x1.cbcafap-4, 0x1.1cffcep-5, 0x1.44a2fcp-3 }, { -0x1.3ba608p-16, 0x1.010ac4p-3, 0x1.2feb8cp-2 } } };
float firstBias[8] = { -0x1.7dcbc8p1, 0x1.25ce44p0, -0x1.bc08aep0, 0x1.391fb4p-3, -0x1.0b7e8ep1, -0x1.9756a6p0, -0x1.d4d4dp-1, -0x1.c817a4p0 };
float secondKernel[16][4][8] = { { { -0x1.20f48p-1, -0x1.99e336p-2, -0x1.3b10fp-1, -0x1.136f84p-1, -0x1.5fad7ap-2, -0x1.da53eap-2, -0x1.e0315ap-3, 0x1.81227ap-9 }, { -0x1.ab9e5ep-3, 0x1.da178cp-2, -0x1.00f57cp-2, 0x1.627878p-10, 0x1.4dd556p-4, -0x1.aaaf1p-3, -0x1.b8c418p-2, 0x1.7cd60ep-2 }, { 0x1.501b3cp-5, 0x1.63a5b2p-4, -0x1.7a8a98p-4, 0x1.3fc078p-5, -0x1.916aecp-5, -0x1.75d056p-3, -0x1.ae43a6p-3, 0x1.e043b8p-3 }, { 0x1.d8e2p-4, 0x1.c3d738p-5, 0x1.39141ap-4, 0x1.066a54p-5, 0x1.503836p-9, -0x1.53f34cp-4, -0x1.5ff64p-3, 0x1.099718p-5 } }, { { 0x1.c8c486p-5, 0x1.accbfp-4, -0x1.757de6p-5, 0x1.a6575ep-5, -0x1.f0b132p-4, -0x1.877c74p-5, -0x1.81cfap-6, 0x1.e71b48p-4 }, { -0x1.39af44p-6, 0x1.60370ep-2, -0x1.10403p-4, 0x1.8b3ddcp-2, 0x1.5e6b82p-6, -0x1.732f8p-5, -0x1.08df4ap-5, -0x1.3806f6p-3 }, { -0x1.76ea1ep-4, -0x1.a837bep-5, -0x1.997ff6p-4, -0x1.200236p-5, -0x1.68ce4p-6, 0x1.814dbep-7, 0x1.5168e8p-5, -0x1.87cecap-4 }, { -0x1.22711ap-4, -0x1.8b751ep-7, -0x1.938ed2p-7, 0x1.f19746p-6, 0x1.5bdad2p-3, -0x1.8de81ap-6, -0x1.fdcfacp-4, -0x1.0d41f4p-4 } }, { { -0x1.e1066p-4, -0x1.a373eap-4, -0x1.207238p-2, -0x1.b0c4e8p-4, -0x1.0e5026p-3, -0x1.7f7b7ep-4, -0x1.519e2ap-8, -0x1.1e3538p-4 }, { 0x1.264722p-4, -0x1.88c6f2p-4, -0x1.e5bbd8p-3, -0x1.59b1a4p-2, -0x1.423d7ep-3, -0x1.41575cp-5, 0x1.21d31ep-4, 0x1.ba8f76p-4 }, { -0x1.6f2762p-5, -0x1.8b9fd6p-7, -0x1.2b1e66p-3, -0x1.3e33d6p-2, -0x1.c642ccp-4, 0x1.c104a6p-7, -0x1.e3b822p-6, 0x1.3c0218p-5 }, { 0x1.3babb6p-1, 0x1.c346bp-5, -0x1.2c5614p-3, -0x1.a13a02p-3, 0x1.c75958p-3, -0x1.15b6ecp-6, -0x1.1fd8aep-6, 0x1.ac415ap-4 } }, { { 0x1.12c784p-4, 0x1.d23d86p-2, -0x1.3c835p-4, -0x1.565958p-3, 0x1.7ee73p-4, -0x1.a844f4p-5, -0x1.595e88p-3, -0x1.b28a0ap-6 }, { 0x1.4154e8p-3, 0x1.2a3cdcp-2, -0x1.2440a8p-7, 0x1.9e417cp-4, -0x1.50054cp-3, -0x1.d1fda2p-4, -0x1.06543ep-2, 0x1.e68866p-4 }, { -0x1.b491fep-4, 0x1.f23d1ap-3, 0x1.65ddb6p-4, -0x1.b7bdb6p-3, -0x1.92aeaap-3, -0x1.5296c4p-1, -0x1.477f26p-1, 0x1.e347d4p-5 }, { -0x1.00a14ap-3, -0x1.81a36cp0, -0x1.fa443ap-5, 0x1.0212p-4, -0x1.ea51bcp-3, -0x1.5c3606p-1, -0x1.767478p-1, -0x1.cc34a4p-4 } }, { { -0x1.d5d33ap-4, 0x1.58e292p-5, -0x1.ab17dp-9, -0x1.492ed8p-3, -0x1.c1d088p-10, 0x1.968adap-1, 0x1.704cfep-3, -0x1.dc0956p-3 }, { -0x1.1cb2ep-3, 0x1.f5f7acp-5, -0x1.44e48ap-4, -0x1.5cdf6ap-3, 0x1.0febb4p-3, -0x1.5857cp-4, -0x1.ec6b5ep-4, -0x1.5857ap-4 }, { -0x1.225a4cp-3, 0x1.0ff4fcp-4, -0x1.ed6e74p-4, -0x1.c5a162p-6, -0x1.0d459p-4, -0x1.63ea32p-4, -0x1.9acbecp-3, 0x1.8ec646p-3 }, { -0x1.a64d6ep-4, -0x1.25e8aep-1, -0x1.73a926p-3, 0x1.c5e4eep-5, -0x1.867becp-2, -0x1.57eb6cp-3, -0x1.ed157cp-3, 0x1.c67362p-3 } }, { { -0x1.797dbcp-3, -0x1.2803a8p-2, -0x1.2e3432p-8, -0x1.9d0796p-3, -0x1.2832ap-4, -0x1.2b15fp-2, -0x1.0d579p-2, 0x1.daae3p-3 }, { 0x1.175b0ep-6, 0x1.1af6e4p-2, 0x1.2a72a8p-4, -0x1.97f43ap-3, -0x1.f5a52ep-3, -0x1.9694dp-2, -0x1.0821ep-1, 0x1.056a56p-2 }, { 0x1.34e3fp-3, 0x1.53e052p-5, 0x1.34b4e8p-3, -0x1.a2eabp-4, 0x1.32d87p-2, -0x1.c7a8d8p-3, -0x1.20a386p-2, -0x1.5dff9ep-2 }, { 0x1.01e3fcp-5, -0x1.20c8a4p-4, -0x1.9c3404p-4, 0x1.00e90cp-5, 0x1.088104p-3, 0x1.04067p-2, 0x1.e8391ep-2, -0x1.d008dep-3 } }, { { 0x1.c624p-4, 0x1.6bec02p-4, 0x1.6d33b2p-5, 0x1.bd5a8p-2, 0x1.82e95ep-4, -0x1.df1d6ep-3, -0x1.654d66p-3, 0x1.4795fep-3 }, { 0x1.85e218p-3, 0x1.590bc6p-5, -0x1.6f9194p-10, -0x1.a72834p-5, 0x1.546734p-4, -0x1.f2f938p-3, -0x1.e36508p-3, -0x1.57829p-5 }, { -0x1.d913e8p-5, -0x1.e5a43ep-4, -0x1.509fa4p-5, -0x1.677768p-4, -0x1.572cdep-6, -0x1.053a46p-2, -0x1.b2d7ccp-5, -0x1.06124ep-3 }, { -0x1.594c84p-4, 0x1.40256cp-5, -0x1.48c614p-3, -0x1.504eeap-3, -0x1.56c54ap-3, -0x1.0c903ep-3, -0x1.65a0fcp-4, 0x1.01ad52p-10 } }, { { -0x1.22f5fep-3, 0x1.82beecp-3, -0x1.f5522ep-4, -0x1.e3a2b6p-5, -0x1.5e47e6p-4, -0x1.c048c6p-6, 0x1.3ac58cp-2, -0x1.8e33acp-3 }, { -0x1.e2d324p-4, 0x1.04cf14p-4, 0x1.d2662ep-5, -0x1.4b2234p-3, 0x1.5d57e2p-4, 0x1.824274p-2, -0x1.bb89bp-5, -0x1.4cb18ep-2 }, { 0x1.db618cp-8, 0x1.45aceap-6, -0x1.3b50c8p-3, -0x1.743fcap-3, -0x1.7206f6p-5, 0x1.034428p-4, -0x1.65fbb6p-6, -0x1.352d94p-2 }, { 0x1.9398f8p-6, 0x1.10fb7p-4, -0x1.16726cp-5, -0x1.783ebcp-3, 0x1.066c4ep-6, -0x1.47427p-5, 0x1.edf574p-8, -0x1.87531ap-2 } }, { { -0x1.e068ap-4, -0x1.661f24p-4, -0x1.bd5bb2p-3, 0x1.644f82p-6, -0x1.0e52d4p-3, -0x1.4d6a1ep-3, 0x1.4ff39p-3, 0x1.492e54p-2 }, { 0x1.a68bc2p-3, 0x1.41afd8p-4, -0x1.1835fap-2, -0x1.ac983ap-4, -0x1.c6f094p-3, -0x1.b3483p-6, 0x1.6f54b4p-5, -0x1.77d1fep-3 }, { 0x1.cf18d6p-3, -0x1.25d826p-7, -0x1.57995cp-6, -0x1.e5365cp-5, 0x1.687e8cp-2, -0x1.a775b6p-4, -0x1.0db6f6p-2, -0x1.b2ccd4p-2 }, { 0x1.00b918p-4, -0x1.9ac8cp-3, 0x1.b1229ap-3, -0x1.1df952p-3, 0x1.9d9064p-2, -0x1.67915p-2, -0x1.5c0e9ap-2, -0x1.594778p-1 } }, { { -0x1.4338aep-3, -0x1.dcda1cp-3, -0x1.2b4c6p-1, -0x1.02edacp-1, -0x1.567dp-2, -0x1.5b317cp-3, -0x1.9005c4p-3, -0x1.2c979p-2 }, { 0x1.5d549p-3, 0x1.023344p-1, -0x1.1fd95p-2, 0x1.49a42ap-3, -0x1.8500b8p-6, -0x1.52f1ep-3, -0x1.c63bfcp-3, -0x1.45e264p-5 }, { 0x1.3b186ap-3, 0x1.844572p-2, -0x1.80ebbcp-2, -0x1.e6e24ep-9, 0x1.bc826ep-4, -0x1.fce214p-4, -0x1.eccd3cp-4, -0x1.0f2656p-7 }, { 0x1.203ceap-4, 0x1.b29202p-3, -0x1.7d6414p-2, -0x1.3ecba8p-6, 0x1.ba4086p-4, -0x1.e803dep-5, 0x1.ab4964p-8, -0x1.f26148p-6 } }, { { -0x1.d02b7p-15, -0x1.4f44bp-2, 0x1.4a4ab4p-4, -0x1.650c5ap-2, 0x1.846392p-2, 0x1.50c3a4p-5, 0x1.75fd4cp-4, -0x1.ecd896p-4 }, { -0x1.b82954p-6, -0x1.b8fbecp-4, -0x1.eb6d9cp-5, -0x1.514a16p-2, 0x1.956b36p-3, 0x1.31f5f8p-4, 0x1.73ac4ep-5, 0x1.cf7e34p-5 }, { -0x1.08087ep-7, -0x1.84ac0ep-5, -0x1.a5cdbp-3, -0x1.8ffee4p-4, -0x1.74b7bp-4, -0x1.9173d2p-4, -0x1.0aa9c4p-3, 0x1.e51f6ap-2 }, { -0x1.d1d2e8p-5, -0x1.9a2cdep-2, 0x1.804454p-7, 0x1.e407f8p-4, 0x1.54e922p-4, -0x1.3f62fap-3, -0x1.29832ap-3, -0x1.13cb76p-2 } }, { { 0x1.b5ff5cp-5, -0x1.0ef262p-3, 0x1.75f60ep-2, -0x1.0da09cp-4, 0x1.526cdp-3, 0x1.8e29d8p-4, 0x1.0deddep-9, 0x1.d140ecp-6 }, { 0x1.58af2ep-6, -0x1.1a05d8p-2, 0x1.855e86p-5, 0x1.1c7226p-5, 0x1.b5dbe8p-3, -0x1.31e376p-3, -0x1.903ee2p-8, -0x1.1718dap-3 }, { -0x1.86bbfcp-4, -0x1.0f5c58p-2, 0x1.7ce8bp-5, -0x1.26a428p-3, -0x1.aa2282p-3, 0x1.1c0686p-3, 0x1.5c99fp-3, -0x1.d4d412p-4 }, { -0x1.87c3d8p-4, -0x1.55bfaap-3, -0x1.b3825cp-4, -0x1.e4b782p-3, -0x1.1fd2e6p-3, 0x1.198756p-3, 0x1.bda30ap-3, -0x1.1ae01p-3 } }, { { 0x1.036edep-5, -0x1.0c1e18p-4, 0x1.ac461ap-3, -0x1.20de2cp-7, -0x1.85309ep-1, -0x1.889d0ap-3, -0x1.1641ep-3, -0x1.1f46b6p-7 }, { -0x1.8a677ap-5, -0x1.91f708p-5, 0x1.193222p-6, 0x1.103c82p-3, -0x1.d87dc6p-1, -0x1.18572ep-3, -0x1.47d928p-9, 0x1.9e6b1ep-7 }, { -0x1.19d9d4p-5, -0x1.7a2608p-3, 0x1.46ec26p-3, 0x1.321a6ep-6, -0x1.e947a8p-2, -0x1.d8d43p-3, -0x1.ec787ap-4, -0x1.5ea3fp-6 }, { -0x1.14dc3ep-6, -0x1.198aaap-2, -0x1.f3393cp-5, -0x1.6e2826p-4, -0x1.359b12p-3, 0x1.5c28f2p-3, 0x1.e345bap-3, -0x1.7ce35ap-6 } }, { { 0x1.459346p-1, 0x1.1e96ccp-5, -0x1.52388ap-3, -0x1.26f3ecp-2, 0x1.6c30e2p-4, 0x1.3b9798p-6, -0x1.fb7742p-6, 0x1.0aeb92p-3 }, { -0x1.5a96eep-4, 0x1.b83b02p-3, -0x1.49985ap-5, -0x1.6d9c74p-3, -0x1.4e6f7p-3, 0x1.ea7dccp-9, -0x1.59696ep-5, 0x1.8e0a3ep-7 }, { 0x1.663b02p-3, 0x1.9ffb14p-3, 0x1.76f95ep-5, -0x1.b54p-4, -0x1.41a272p-1, -0x1.e6f192p-4, -0x1.46033ap-2, -0x1.768884p-6 }, { -0x1.a982b4p-4, -0x1.79cffap-1, 0x1.0a6e8cp-4, 0x1.789cf2p-4, -0x1.ff9b48p-1, -0x1.d3943ap-1, -0x1.d3d72ep-1, 0x1.3f9354p-6 } }, { { 0x1.3b0568p-2, 0x1.ef29e2p-3, -0x1.08e9e4p-2, -0x1.38cd1p-2, -0x1.e29dbep-4, 0x1.633d44p-3, 0x1.939316p-5, 0x1.b8c6b4p-3 }, { 0x1.9d4bf2p-5, 0x1.1a7f2ap-4, -0x1.d1c038p-3, -0x1.f9c36cp-3, -0x1.c65704p-3, -0x1.04d8ecp-3, -0x1.6c61fcp-3, 0x1.6cbf1ep-5 }, { 0x1.2aa42ep-7, -0x1.11903cp0, 0x1.bb4214p-5, 0x1.e263dp-3, -0x1.028ba4p-7, -0x1.4e7882p-3, -0x1.9b5376p-7, 0x1.3bbc1ep-6 }, { -0x1.866b7ep-4, -0x1.e01cb6p-1, 0x1.abe9d2p-8, 0x1.d936cp-4, -0x1.46eb16p-7, -0x1.08062ep-2, 0x1.a00932p-6, -0x1.1003bap-3 } }, { { -0x1.ebab04p-5, 0x1.d9540ap-6, 0x1.8a9b72p-5, -0x1.d22346p-9, 0x1.a16146p-3, -0x1.54bef4p-4, -0x1.7ce6d4p-4, -0x1.524b22p-4 }, { -0x1.c11c1ep-4, 0x1.1ea2ap-6, 0x1.72fbe8p-4, 0x1.a02344p-5, 0x1.656a74p-3, 0x1.0e51c2p-2, 0x1.130688p-3, -0x1.14bf86p-3 }, { -0x1.1f7188p-3, -0x1.576554p-4, -0x1.b88126p-5, -0x1.33e06ap-5, 0x1.055094p-9, 0x1.34a278p-7, -0x1.ba5b7cp-8, 0x1.86baaap-4 }, { -0x1.f8de2p-5, -0x1.8beec4p-3, 0x1.c3b5aap-4, 0x1.27aa4ap-3, -0x1.d5adep-4, -0x1.ac56c4p-5, 0x1.6219p-4, 0x1.4b7c32p-4 } } };
float secondBias[16] = { 0x1.6e2b46p-2, 0x1.2ace52p0, -0x1.c52c96p-3, 0x1.f8bec2p-2, -0x1.7da944p-1, -0x1.1a388ap-1, -0x1.e1ba52p-3, -0x1.2eeb34p0, -0x1.de15f8p-3, 0x1.4aad98p-1, -0x1.3159bep0, -0x1.16381cp0, 0x1.19b14ap0, 0x1.aa854ap-6, -0x1.f51d52p-1, -0x1.e3b73cp-3 };
static  char aesl_internal__OC_str2[2] = "w";
float firstDense[16][14][16] = { { { 0x1.3cf122p-4, 0x1.e4dc04p-3, -0x1.cabf5ep-7, 0x1.4b1306p-2, 0x1.ea3d32p-4, 0x1.240568p-4, 0x1.2c635ep-4, -0x1.44ee88p-2, -0x1.e679ep-3, 0x1.6bd81ep-1, -0x1.41a28ep-7, -0x1.911b5cp-3, 0x1.7b999cp-3, 0x1.f0935ap-3, -0x1.045c22p-4, 0x1.fde74ep-5 }, { 0x1.f5d4f6p-5, 0x1.3fcba2p-3, 0x1.f51924p-5, -0x1.8c45dp-3, 0x1.48b9c8p-3, 0x1.d61b44p-7, -0x1.4209f6p-5, -0x1.a2dc38p-2, -0x1.b38daap-6, 0x1.bfd16cp-4, 0x1.12e7bp-5, -0x1.628b96p-2, 0x1.1cd5b4p-5, -0x1.df7c8p-6, -0x1.9777c8p-4, 0x1.606becp-5 }, { -0x1.ac744ap-3, 0x1.146a3ep-5, 0x1.42632ap-5, -0x1.a955bcp-3, 0x1.d6151ap-3, -0x1.04e1aap-5, 0x1.5431b8p-6, -0x1.f21854p-3, 0x1.098bdcp-9, 0x1.7d7258p-4, -0x1.04aa1ep-6, -0x1.01ed28p-1, -0x1.054414p-3, -0x1.b05746p-5, -0x1.a69e12p-4, -0x1.6d30aep-3 }, { -0x1.03db9ap-2, -0x1.769afp-5, -0x1.b9f342p-4, -0x1.53883p-5, 0x1.64dbeap-2, 0x1.a6f686p-3, 0x1.d2d456p-7, -0x1.265dd8p-1, -0x1.581ad4p-3, 0x1.65c67ap-3, 0x1.7283e8p-5, -0x1.93a69p-3, -0x1.344afep-2, -0x1.166da6p-3, -0x1.13474ap-4, -0x1.ca6012p-4 }, { -0x1.062e26p-2, -0x1.889834p-6, -0x1.ce3d02p-3, -0x1.beef04p-4, 0x1.66fa04p-3, 0x1.046ba6p-3, 0x1.218114p-6, -0x1.2ba116p-2, -0x1.dece54p-3, 0x1.41e9e6p-3, 0x1.745002p-6, -0x1.54caaap-4, -0x1.203aecp-4, 0x1.9c6f4ap-4, -0x1.01af1ep-4, -0x1.fbd404p-7 }, { -0x1.cdffa2p-4, 0x1.416b2cp-4, -0x1.2161d4p-2, -0x1.33db3cp-4, 0x1.b3dc5cp-4, 0x1.6be9d2p-2, 0x1.fd6944p-4, 0x1.6097cap-5, -0x1.b1e60ep-3, 0x1.555052p-9, 0x1.8019ecp-3, -0x1.810f72p-6, 0x1.ce25e6p-5, -0x1.0467aep-4, -0x1.2a8f74p-5, 0x1.5394c8p-3 }, { 0x1.bae194p-3, 0x1.975138p-4, -0x1.5fc77cp-4, -0x1.59275ep-3, 0x1.6a6c0ep-2, 0x1.69fff8p-3, -0x1.7734e2p-4, 0x1.97255p-3, -0x1.524562p-3, 0x1.7cbb9cp-3, 0x1.8595b4p-3, 0x1.b0344p-5, 0x1.1814b8p-5, 0x1.e1ffc4p-4, 0x1.19faf2p-3, 0x1.06bed2p-3 }, { -0x1.5da6ccp-9, 0x1.c8c674p-7, -0x1.905e2p-3, -0x1.8f4f8ap-3, 0x1.2eb5b4p-2, -0x1.9add82p-6, -0x1.a33934p-5, 0x1.ba4e62p-4, -0x1.016416p-4, -0x1.4eeb7ep-6, 0x1.5ecbaap-3, 0x1.361b88p-3, 0x1.e4ff9ep-4, 0x1.e58ee6p-4, -0x1.305cd2p-8, 0x1.50b75p-4 }, { -0x1.7f61fap-4, -0x1.f89346p-4, -0x1.05eb5ap-3, -0x1.4c3ccp-3, 0x1.7b2c3ap-3, 0x1.5847eep-3, 0x1.0c3688p-4, -0x1.90ad1p-5, 0x1.dded5ap-6, 0x1.27021ap-5, 0x1.12edap-3, -0x1.070692p-4, -0x1.f3acap-3, 0x1.9e2f18p-5, 0x1.21cbd8p-4, 0x1.9e323cp-5 }, { -0x1.3e783ep-4, -0x1.968fcap-3, -0x1.29e066p-3, 0x1.437ebp-5, 0x1.8519a4p-3, 0x1.35cc62p-4, -0x1.569df2p-4, -0x1.3e8cdep-3, 0x1.43e33cp-5, 0x1.f6e408p-4, 0x1.499452p-3, -0x1.420264p-2, -0x1.8b360ep-3, 0x1.8a13f2p-4, -0x1.890992p-5, -0x1.d16bbcp-5 }, { -0x1.7dec14p-3, -0x1.78dcfp-4, -0x1.71f006p-5, -0x1.2fedd2p-5, 0x1.763234p-3, 0x1.b76286p-6, -0x1.3cb78ap-9, -0x1.013798p-3, -0x1.c9c802p-10, 0x1.4d1bcap-3, -0x1.141296p-7, -0x1.c09cap-2, -0x1.e727c6p-6, 0x1.41d3dp-5, 0x1.c54e46p-6, 0x1.4e0bc4p-4 }, { -0x1.53b5a8p-5, -0x1.4e8766p-6, -0x1.1ac25p-5, 0x1.4eaafcp-4, 0x1.7e4ebep-3, 0x1.943224p-8, -0x1.171392p-5, -0x1.6732aep-5, -0x1.b51ec2p-6, 0x1.b4a8d4p-3, 0x1.57d662p-5, -0x1.2f2b18p-2, 0x1.0a5ab6p-2, -0x1.e87e92p-6, 0x1.c5764p-7, -0x1.5cd202p-4 }, { -0x1.8659c2p-3, 0x1.08bbd2p-4, 0x1.2ec366p-3, -0x1.2a0e8ep-6, 0x1.0ef99ap-2, 0x1.0767b2p-5, 0x1.2afc38p-5, -0x1.6017c2p-4, 0x1.29fc46p-6, 0x1.ae6dep-4, 0x1.04573cp-6, -0x1.3686fp-2, -0x1.18bbf2p-3, 0x1.b48a0ep-4, 0x1.326cf2p-5, 0x1.79fe92p-6 }, { -0x1.d8ddacp-2, 0x1.ab64d8p-6, 0x1.256054p-8, 0x1.750e8ap-3, -0x1.71cba6p-4, 0x1.5c3524p-7, 0x1.786736p-3, -0x1.507a1ep-2, 0x1.4cf8a6p-4, -0x1.313c76p-2, 0x1.ad232cp-6, -0x1.32b6e2p-2, 0x1.0816e6p-3, 0x1.8115f4p-4, 0x1.ba36fep-4, -0x1.0803c8p-4 } }, { { -0x1.b6c79ep-4, -0x1.1abbb4p-4, -0x1.8dc288p-5, -0x1.0ad8cap-3, -0x1.630614p-4, -0x1.b2952ep-3, 0x1.4e4ceep-4, -0x1.d4441ap-4, -0x1.2890ep-3, 0x1.086202p-3, -0x1.70bdcp-4, -0x1.ddc7a6p-4, -0x1.88de9cp-6, 0x1.a7565ep-5, -0x1.58f3a4p-3, -0x1.b6bdd4p-4 }, { -0x1.9a8004p-5, -0x1.ba8f9ep-5, -0x1.2e903cp-4, 0x1.9476f8p-4, -0x1.863aeap-3, 0x1.0d576ep-8, 0x1.c4a3f4p-8, -0x1.341998p-3, 0x1.80adb4p-4, -0x1.d74ba4p-5, -0x1.4fd08cp-3, -0x1.9ce32ap-3, 0x1.61b4fp-4, -0x1.63fbd8p-3, -0x1.896abep-3, -0x1.0c9056p-3 }, { -0x1.e8b85p-4, 0x1.476234p-6, -0x1.dfaceep-4, -0x1.27c3d8p-4, -0x1.9b650ap-4, -0x1.a417fp-5, 0x1.af2a2cp-6, 0x1.520164p-7, 0x1.6d1884p-4, -0x1.3ef35p-3, -0x1.d1fd4ap-4, 0x1.70605p-4, 0x1.3c477p-4, -0x1.67c2fep-3, -0x1.7ff056p-3, -0x1.e1180ap-5 }, { -0x1.c0646p-4, -0x1.8ba7fep-3, -0x1.670452p-7, -0x1.270c56p-3, -0x1.0f0216p-5, 0x1.51a962p-6, -0x1.5bac84p-7, -0x1.6633f8p-11, -0x1.53efaap-3, -0x1.3173fep-3, -0x1.6d2c68p-3, -0x1.99011ap-4, -0x1.d23eaap-6, -0x1.d3bb42p-3, 0x1.690da6p-6, -0x1.1f8474p-3 }, { -0x1.9ac78p-6, -0x1.9ff196p-4, 0x1.befe8ap-5, 0x1.7ab32ap-4, -0x1.e138f6p-4, 0x1.f75eaep-6, -0x1.5e895ap-4, -0x1.79e74ap-4, -0x1.b3c368p-5, 0x1.52514cp-5, -0x1.a11796p-3, -0x1.2b0a4p-4, -0x1.f59e66p-8, 0x1.39f9bcp-5, -0x1.876d22p-3, -0x1.5f08a8p-4 }, { -0x1.09bdb8p-3, -0x1.338cd2p-3, -0x1.479e86p-5, -0x1.b076eep-3, -0x1.a012ap-5, -0x1.5b442ep-5, -0x1.6b5bcp-10, 0x1.993a8ep-4, 0x1.c6e40cp-4, 0x1.3f0324p-6, -0x1.0c3aaap-3, 0x1.38f34p-6, -0x1.cdd9c2p-4, -0x1.3418c6p-4, -0x1.bd0582p-3, -0x1.709802p-3 }, { -0x1.a40cc8p-5, -0x1.10a9a2p-3, 0x1.857018p-4, 0x1.69a4b4p-4, -0x1.499708p-3, 0x1.1f69p-6, -0x1.18d308p-3, -0x1.0bb47ap-3, 0x1.189098p-3, -0x1.9e6bb8p-6, -0x1.1637p-3, -0x1.387554p-6, 0x1.07a842p-4, 0x1.d0dc4cp-4, 0x1.5083c8p-5, -0x1.3a6b1p-3 }, { 0x1.65f658p-4, -0x1.1577c8p-3, -0x1.fc012ap-4, 0x1.130e7ap-6, -0x1.413e32p-6, -0x1.df9d58p-5, -0x1.42902cp-3, -0x1.2643bp-3, -0x1.f8922ap-4, 0x1.6220d8p-3, -0x1.440926p-4, -0x1.7d9d78p-4, -0x1.a39cb2p-5, 0x1.c1e3acp-5, -0x1.ed2474p-5, 0x1.cddf7p-9 }, { 0x1.1c584cp-4, -0x1.3dffe2p-3, 0x1.4cdf84p-5, -0x1.9d65cep-3, -0x1.883c62p-4, 0x1.02145ep-6, -0x1.d4e772p-4, -0x1.97be82p-5, -0x1.108f3ap-4, -0x1.d04356p-5, -0x1.f240eep-6, 0x1.54aa8p-4, -0x1.f3c24cp-4, 0x1.bb7d2ep-4, -0x1.23d0aep-4, -0x1.7d76p-3 }, { -0x1.22a244p-4, 0x1.43ccd6p-4, 0x1.4de2fap-4, 0x1.0d1352p-4, -0x1.df22aep-4, -0x1.020d96p-11, 0x1.95813ap-5, -0x1.6b5ee2p-3, -0x1.2c7a02p-7, -0x1.034802p-4, -0x1.5ded48p-5, -0x1.1bd36ep-5, -0x1.4ddf28p-3, -0x1.4063dcp-3, 0x1.611486p-5, -0x1.634612p-4 }, { 0x1.23704p-7, 0x1.3cf8aap-5, -0x1.9ec17ap-3, 0x1.460c0ap-6, -0x1.f49124p-8, -0x1.14a6d4p-3, -0x1.3203aap-7, -0x1.55ecd2p-3, -0x1.117df2p-3, 0x1.922e96p-7, 0x1.f22168p-5, -0x1.e5629ep-6, 0x1.14d788p-6, -0x1.6b4ed8p-3, -0x1.c1f7c4p-4, -0x1.5581e6p-5 }, { -0x1.7a8fccp-4, -0x1.cc6186p-3, 0x1.6a5bf6p-5, -0x1.5bac26p-4, -0x1.03a4fep-3, -0x1.afc33cp-5, 0x1.c40518p-6, -0x1.232042p-3, 0x1.571eacp-4, 0x1.b8b774p-4, -0x1.eebd54p-3, 0x1.c99238p-5, 0x1.a9edf4p-8, 0x1.947ae4p-5, -0x1.69ab18p-3, 0x1.506064p-8 }, { 0x1.1c18cp-6, 0x1.618ef6p-5, -0x1.72a30cp-8, 0x1.1ca1dap-3, -0x1.14e166p-6, -0x1.3a758cp-3, -0x1.129aeep-3, -0x1.72b76ep-5, 0x1.299246p-4, -0x1.fad718p-5, -0x1.8afd8ep-3, -0x1.7073eep-4, -0x1.828c44p-3, 0x1.c99938p-7, -0x1.22af9p-3, 0x0p0 }, { -0x1.5da668p-4, 0x1.98fd2ap-5, 0x1.027e2cp-4, -0x1.36fceep-6, -0x1.0ef68ep-6, -0x1.29837p-3, -0x1.fec89p-4, -0x1.c41282p-6, -0x1.5a0596p-5, -0x1.4caea4p-11, -0x1.072456p-4, -0x1.031024p-2, 0x1.c90e22p-4, -0x1.a24becp-3, -0x1.d25baap-4, -0x1.d78f94p-3 } }, { { 0x1.84664p-7, -0x1.a877fap-3, -0x1.30db98p-5, -0x1.3e62ap-3, 0x1.90b42ap-3, 0x1.3d50d4p-3, -0x1.3ae438p-2, 0x1.339f84p-3, 0x1.7d33b4p-5, -0x1.093866p0, 0x1.33e386p-5, -0x1.49ee7ep-5, 0x1.ee5452p-2, -0x1.91ea9p-3, -0x1.e979e8p-4, -0x1.fe89dap-5 }, { 0x1.152876p-2, -0x1.ba479ap-7, 0x1.17b6bp-2, -0x1.58e9cep-2, -0x1.08a6dcp-4, 0x1.94943p-3, 0x1.e3192cp-4, -0x1.b7815cp-7, 0x1.a50f24p-3, -0x1.ab9aa2p-5, 0x1.1f2c5ap-5, -0x1.2bdd74p-6, 0x1.65e4f2p-3, -0x1.b0d934p-2, -0x1.0dfacep-3, -0x1.aa408ep-6 }, { 0x1.ea40cep-4, 0x1.77096cp-8, 0x1.75224p-3, -0x1.57190cp-3, 0x1.d65728p-4, 0x1.2f7aaep-3, -0x1.30bf1ep-7, -0x1.cb1efap-5, 0x1.866f32p-2, -0x1.511808p-4, 0x1.a71b14p-4, -0x1.5233b8p-4, 0x1.082724p-4, -0x1.477122p-2, -0x1.0e62f6p-4, -0x1.53e8b6p-9 }, { 0x1.893532p-3, -0x1.4d32f4p-5, 0x1.07a3c2p-3, 0x1.43586ep-6, 0x1.1bc68cp-3, 0x1.2d5b98p-4, -0x1.f35668p-4, -0x1.6cfd96p-3, 0x1.194eeap-2, -0x1.82b0cap-3, -0x1.468a24p-10, -0x1.c4a3aap-6, -0x1.905958p-6, -0x1.e03b14p-3, 0x1.cb60bp-7, 0x1.b852p-4 }, { 0x1.3b29eep-2, -0x1.09f448p-4, 0x1.fc0d4p-4, -0x1.201108p-5, 0x1.8a15ep-4, 0x1.a7e5a8p-6, -0x1.ab47fap-4, -0x1.9d2b58p-9, 0x1.32da14p-2, 0x1.3b08b4p-7, -0x1.18ecacp-6, -0x1.51ff46p-6, 0x1.973b64p-7, -0x1.170fc6p-2, -0x1.cdd26p-4, -0x1.dfe72ep-6 }, { 0x1.3e80cep-2, -0x1.392afcp-4, 0x1.e9af42p-4, -0x1.880a28p-5, 0x1.80a064p-3, -0x1.1c9efep-3, -0x1.6b6848p-5, -0x1.260376p-3, 0x1.e52eeap-3, -0x1.896ae4p-6, -0x1.46065ap-2, -0x1.0b386p-4, 0x1.bb15d2p-4, -0x1.c30accp-4, -0x1.2cfp-3, -0x1.bbc14cp-5 }, { 0x1.c34e72p-3, -0x1.f5d28p-4, 0x1.f03406p-3, -0x1.21155cp-3, 0x1.e6d3fep-5, -0x1.a38306p-4, -0x1.03b9d2p-3, 0x1.bf4fdep-5, 0x1.7fc63ap-3, 0x1.6ce9c4p-5, -0x1.bb69b4p-3, -0x1.accfbep-5, 0x1.95d076p-4, -0x1.4229b6p-3, -0x1.421c4cp-3, -0x1.9ddcep-4 }, { 0x1.1ba39cp-2, -0x1.b731eep-4, 0x1.f1b0ecp-5, -0x1.4b8bb2p-3, 0x1.2e3cf6p-4, -0x1.22626cp-3, -0x1.122a36p-3, -0x1.174c4p-9, 0x1.41424ap-2, -0x1.776436p-4, -0x1.3ef0dap-2, -0x1.d5f7bep-5, -0x1.87b95cp-4, -0x1.15c364p-2, -0x1.210cb4p-4, -0x1.22586cp-4 }, { 0x1.169f42p-2, -0x1.2221dep-5, 0x1.51989cp-4, -0x1.f7e0a8p-3, 0x1.c0805p-5, 0x1.01375p-5, -0x1.519d9ep-5, 0x1.906278p-5, 0x1.494282p-2, -0x1.16554ep-2, -0x1.e9abbep-4, 0x1.458358p-8, -0x1.9e8988p-6, -0x1.b66e9ep-3, -0x1.9984cep-5, 0x1.642116p-6 }, { 0x1.4dc6ap-3, 0x1.84bdfp-4, 0x1.0a2406p-3, -0x1.3f7ac4p-3, 0x1.fdd838p-4, 0x1.a08edcp-5, 0x1.1264cp-4, -0x1.247358p-4, 0x1.787046p-3, 0x1.ec3cbep-7, -0x1.33c528p-5, -0x1.91aef4p-6, 0x1.23c7bp-8, -0x1.324c1ap-2, -0x1.bb5a54p-3, 0x1.131d28p-6 }, { 0x1.cd329ep-4, 0x1.31ae7p-8, 0x1.253bc4p-3, -0x1.1d63dp-2, 0x1.511258p-3, 0x1.7da11ep-3, -0x1.a00e44p-5, -0x1.6a9202p-4, 0x1.ecfc0cp-3, -0x1.411754p-4, -0x1.94874ap-7, -0x1.08c9cap-6, 0x1.6d62f8p-5, -0x1.8c015cp-2, -0x1.142efep-3, -0x1.78a74p-5 }, { 0x1.568764p-4, 0x1.9bffe4p-4, 0x1.6dbc84p-2, -0x1.0e0a6cp-1, -0x1.a88e5ap-5, 0x1.4340e6p-3, 0x1.0ac382p-3, -0x1.96d64ep-4, 0x1.b7c334p-3, -0x1.67b9fcp-5, 0x1.5e0a24p-3, -0x1.50f308p-7, -0x1.ccd07cp-3, -0x1.6e1ef4p-2, -0x1.4dff96p-2, 0x1.d899c2p-5 }, { 0x1.7c1e2p-2, -0x1.a7df2p-4, 0x1.1d304p-2, -0x1.77067ep-2, -0x1.901c44p-4, 0x1.1128b6p-3, 0x1.372deep-4, -0x1.8c88a6p-5, 0x1.788e62p-4, -0x1.dd3496p-4, 0x1.6bf27p-5, 0x1.7d679cp-5, 0x1.2b2b36p-4, -0x1.7edf9ap-2, -0x1.d48626p-3, 0x1.c49b4ep-4 }, { 0x1.1f68ecp-1, -0x1.41311cp-6, -0x1.67224cp-3, -0x1.f8878cp-3, -0x1.ab317cp-6, 0x1.86e49p-3, -0x1.10e9eep-6, 0x1.d8b184p-6, 0x1.4e2d6cp-4, 0x1.73182ep-3, -0x1.01eb08p-3, 0x1.c55188p-4, 0x1.4592acp-3, -0x1.2caf42p-2, -0x1.2e380cp-4, 0x1.0449b4p-4 } }, { { -0x1.3d5f62p-7, -0x1.fc7a98p-3, 0x1.79cd94p-4, -0x1.27a1d8p-4, -0x1.d66a26p-4, -0x1.1d1176p-5, 0x1.e857d6p-6, 0x1.8c4026p-3, -0x1.f13ea8p-5, -0x1.88227ap-5, -0x1.c67b64p-4, 0x1.50c27ap-4, -0x1.21f152p-5, 0x1.29b9c4p-4, -0x1.bc7228p-4, -0x1.bd48cap-4 }, { -0x1.25bae4p-4, -0x1.a60b66p-5, 0x1.3b1b9ep-5, -0x1.470814p-2, -0x1.0c06b8p-2, -0x1.976c2cp-2, -0x1.fa286p-2, 0x1.7ffddp-5, -0x1.8805d8p-4, 0x1.3296aap-6, -0x1.3d4b96p-5, 0x1.040d68p-4, -0x1.25b054p-2, -0x1.43d492p-4, -0x1.f6f04ap-3, -0x1.d1ac68p-4 }, { -0x1.2ad5e6p-2, -0x1.4219bcp-4, 0x1.f15902p-9, -0x1.ad4aaap-2, -0x1.cbf5f6p-3, -0x1.6541a4p-2, -0x1.9e6602p-3, 0x1.1f498cp-4, 0x1.e46b68p-5, -0x1.89f7fap-6, -0x1.058b14p-7, 0x1.37025cp-5, -0x1.e311e2p-3, -0x1.47ce2p-3, -0x1.37a9cap-4, -0x1.3924fcp-4 }, { -0x1.4aba64p-2, -0x1.20247ep-5, -0x1.49500cp-6, -0x1.61c102p-2, -0x1.bbde34p-3, -0x1.95362ap-2, -0x1.6d6946p-3, -0x1.a92dp-5, -0x1.a8824ep-6, 0x1.f52dc2p-5, 0x1.49e36p-4, 0x1.6f3e5cp-5, -0x1.4032d2p-2, 0x1.5db16p-4, -0x1.1d0084p-5, 0x1.1b777cp-6 }, { -0x1.26e23ep-2, -0x1.4027cap-6, -0x1.9b70aap-6, 0x1.81e0aap-8, -0x1.59c174p-3, -0x1.f8714ap-2, -0x1.b81006p-4, -0x1.28e518p-5, 0x1.cfb3dep-7, 0x1.c00792p-4, 0x1.41c4d2p-4, 0x1.0d0dc2p-5, -0x1.20a548p-2, -0x1.52adb4p-7, 0x1.7b3856p-4, -0x1.e7ee24p-6 }, { -0x1.835b2cp-5, -0x1.20956cp-5, -0x1.6bdcf4p-4, 0x1.55071p-4, -0x1.7a075cp-2, -0x1.c35e9ap-2, 0x1.944464p-7, -0x1.2144d6p-4, -0x1.2b02fcp-4, 0x1.79c38ep-4, -0x1.fc84acp-5, 0x1.97b768p-4, -0x1.1d1dfcp-1, 0x1.c1d2dp-3, 0x1.9d07d4p-6, -0x1.da1008p-9 }, { 0x1.7165fep-5, 0x1.05c44cp-6, -0x1.2040e2p-3, 0x1.26c904p-3, -0x1.8c354ep-2, -0x1.8fd07cp-2, 0x1.b03c6p-4, -0x1.a10eccp-3, -0x1.977ebap-3, -0x1.713df2p-4, 0x1.093c44p-5, 0x1.f51f12p-5, -0x1.2bb294p-3, 0x1.bcee9ep-3, 0x1.10338p-5, -0x1.8fadcp-5 }, { 0x1.6c57f6p-4, 0x1.e346c8p-6, -0x1.a3dc6cp-4, 0x1.c0c078p-5, -0x1.eb5c46p-3, -0x1.12019p-2, 0x1.453988p-3, -0x1.105392p-2, -0x1.84d5aap-2, -0x1.94e30ep-4, -0x1.4700ecp-6, -0x1.799f08p-4, -0x1.2f5898p-3, 0x1.23b154p-2, 0x1.a48952p-7, -0x1.f5dd8p-4 }, { 0x1.487658p-5, 0x1.18159p-4, 0x1.0e206ep-5, 0x1.bef13p-4, -0x1.cbc418p-4, -0x1.687058p-3, -0x1.6e93cap-4, -0x1.b19f8ep-2, -0x1.dde6a8p-3, -0x1.33785ap-3, 0x1.1a1fc8p-4, -0x1.b891e2p-4, 0x1.b84344p-6, 0x1.3a990cp-2, 0x1.cf9b26p-4, -0x1.7eee6p-4 }, { -0x1.3fa5cp-6, 0x1.1c74aap-4, -0x1.dc7fe4p-3, 0x1.2d69f8p-4, -0x1.43fde6p-2, -0x1.f9efp-4, 0x1.d9a868p-5, -0x1.88b662p-3, -0x1.8aa198p-3, -0x1.e857ap-4, -0x1.0427eep-3, -0x1.ae10cp-4, 0x1.2afdcap-2, 0x1.fc3ddap-3, 0x1.20be6p-5, -0x1.8fe58ep-3 }, { 0x1.1c78d2p-8, -0x1.a3dde2p-5, -0x1.82131cp-3, 0x1.7e7cdep-4, -0x1.131a6p-3, -0x1.335382p-3, -0x1.2d714ep-4, 0x1.05b0d8p-6, -0x1.7a8a8ap-5, -0x1.9f7102p-3, 0x1.65c3aap-5, -0x1.a30a4cp-7, 0x1.16130cp-2, 0x1.0e8b46p-2, 0x1.a5d6ap-3, 0x1.2fce2ep-6 }, { -0x1.30c78cp-3, -0x1.a9fe68p-6, -0x1.cbb9f2p-2, 0x1.0c0a98p-4, -0x1.e523dcp-6, -0x1.f5073ep-6, -0x1.3c7004p-4, -0x1.fd14f8p-6, -0x1.042734p-3, -0x1.119f86p-3, 0x1.1bf692p-5, -0x1.53ec2ep-5, 0x1.baf51p-2, 0x1.0276dep-3, 0x1.b7ba32p-3, -0x1.33788ep-5 }, { -0x1.358886p-4, 0x1.042dbap-4, -0x1.1211a8p-2, -0x1.b16a3ep-2, 0x1.d288b4p-5, -0x1.c02a6ap-3, -0x1.3c680cp-2, 0x1.42b5fep-2, -0x1.0cd2c2p-2, -0x1.15dd2p-4, -0x1.6caa94p-3, 0x1.aee286p-5, -0x1.1d9754p-1, -0x1.6b2368p-1, -0x1.1eb6dep-1, 0x1.07048p-3 }, { -0x1.30f00ep-2, -0x1.202b84p-2, -0x1.54e5f2p-2, -0x1.382fc4p-2, 0x1.527c1p-4, -0x1.355d3ep-1, -0x1.51efep-1, 0x1.f917c2p-4, -0x1.d96ab6p-2, 0x1.5228c8p-6, -0x1.b674bep-6, -0x1.a79184p-4, -0x1.a5443ap-1, 0x1.0a0d1ap-4, -0x1.5ff8b2p-2, 0x1.614356p-6 } }, { { -0x1.5f409ap-3, -0x1.a63e08p-8, -0x1.c4924p-6, 0x1.058e24p-5, 0x1.6312ecp-3, 0x1.91076cp-5, -0x1.9f908p-2, 0x1.b73d46p-4, 0x1.548e5ep-3, -0x1.1bef5p0, 0x1.4a75f8p-5, -0x1.673904p-4, 0x1.0a4bc8p-3, -0x1.80faacp-2, 0x1.3fd8f8p-4, -0x1.1cb29p-4 }, { 0x1.22979ap-2, 0x1.1adca6p-3, 0x1.273322p-2, -0x1.2d38a8p-3, 0x1.7f1edp-4, 0x1.43df7ap-4, 0x1.9f0788p-8, -0x1.8389acp-2, 0x1.7c8e22p-3, -0x1.eab86ep-4, 0x1.b64f84p-4, -0x1.2ef2bap-4, 0x1.19e53p-5, -0x1.554cd8p-2, -0x1.6a61b2p-4, 0x1.020b2p-11 }, { 0x1.6b1fe2p-3, -0x1.fabb04p-6, 0x1.a9f18ep-3, -0x1.b1c33cp-6, 0x1.473b74p-3, 0x1.0d0f8ap-3, 0x1.ddced6p-6, -0x1.54eb5cp-3, 0x1.59eb36p-3, -0x1.3ab18ap-6, 0x1.767696p-6, 0x1.f4672cp-7, -0x1.57a7aep-2, -0x1.bc0666p-3, 0x1.59c848p-5, -0x1.12cd8cp-7 }, { 0x1.1c2cdep-2, 0x1.0e83a2p-9, 0x1.81984ap-3, 0x1.1e31c4p-5, 0x1.05d02ap-2, 0x1.b6d282p-4, -0x1.6e4fc2p-3, -0x1.3ab6p-2, 0x1.81b796p-3, -0x1.d479c2p-8, -0x1.60c21cp-7, 0x1.2a6f74p-4, -0x1.e62ffap-2, -0x1.a0e984p-3, -0x1.fcf534p-5, 0x1.86686p-4 }, { 0x1.87c4a8p-2, 0x1.354cdap-4, 0x1.11455ep-2, 0x1.e223bp-5, 0x1.4d5096p-3, 0x1.d65f7p-8, -0x1.56c6cap-5, 0x1.6fa724p-7, 0x1.4de12ap-2, -0x1.2ad4p-3, 0x1.6eaa6cp-5, 0x1.9ab23ap-5, -0x1.23bef8p-2, -0x1.ded744p-3, 0x1.c4964ep-6, -0x1.a00034p-7 }, { 0x1.3c81d2p-2, -0x1.035532p-3, -0x1.e0b184p-9, 0x1.b31906p-6, 0x1.cc7c1ap-4, 0x1.02dfe2p-4, 0x1.f70796p-7, -0x1.77fefp-5, 0x1.f35dc2p-3, -0x1.0ae44ep-6, -0x1.1562e4p-3, 0x1.158db4p-8, -0x1.29cad6p-3, -0x1.3ce15ep-4, 0x1.877544p-4, -0x1.20c87cp-5 }, { 0x1.29c4d8p-2, -0x1.10d4cap-5, 0x1.34ccep-2, -0x1.a92d3cp-4, 0x1.e19b66p-3, 0x1.1ef526p-3, -0x1.f52918p-4, -0x1.c72148p-5, 0x1.100f96p-2, 0x1.91560cp-5, 0x1.7cb688p-3, -0x1.d9acfep-9, -0x1.e1da08p-6, -0x1.f987c8p-3, -0x1.59284cp-5, 0x1.984e94p-6 }, { 0x1.2585f8p-2, -0x1.4e3704p-5, 0x1.37e934p-2, -0x1.16a66cp-2, 0x1.19381ep-2, 0x1.32d05ep-4, 0x1.54c44p-6, -0x1.de3d76p-7, 0x1.963f3ap-3, -0x1.8afea8p-3, 0x1.6b7536p-6, 0x1.563296p-7, 0x1.6fcd32p-6, -0x1.468a16p-3, 0x1.55acfp-5, 0x1.0fc404p-3 }, { 0x1.cc4dacp-3, -0x1.565074p-3, 0x1.6cee8ap-3, -0x1.ede65cp-4, 0x1.d45172p-4, 0x1.b7bee8p-4, 0x1.04d22ap-10, 0x1.4313c4p-6, 0x1.6dfc08p-2, 0x1.38b784p-3, -0x1.10f4e6p-5, 0x1.1ca09ap-5, -0x1.66ab4p-4, -0x1.3a483p-3, -0x1.a2b778p-4, 0x1.b36198p-4 }, { 0x1.2a5942p-4, -0x1.10e0f2p-3, 0x1.30a7d6p-3, -0x1.871b8ap-5, 0x1.dd46bap-5, 0x1.1e0accp-3, -0x1.160348p-4, -0x1.8f70aep-5, 0x1.152fdp-2, -0x1.26a4eep-5, 0x1.5d448p-4, 0x1.a9791ep-10, -0x1.a81116p-4, -0x1.8834acp-3, -0x1.6b0e44p-5, -0x1.525362p-6 }, { 0x1.180dfcp-2, -0x1.711194p-5, 0x1.09bb74p-3, -0x1.5216ccp-2, -0x1.3b513ap-2, 0x1.64c0aap-9, 0x1.1212fap-3, -0x1.7f6a9ep-7, 0x1.bcf2e2p-2, -0x1.71d25ap-3, -0x1.ec9934p-5, -0x1.41d144p-6, -0x1.218fe8p-5, 0x1.400ee2p-7, 0x1.8d90dap-5, -0x1.2c7888p-5 }, { 0x1.b4b5f6p-3, -0x1.c00286p-2, -0x1.837e5cp-1, -0x1.3cfe28p-1, -0x1.9b119ep-1, -0x1.4d610ap-2, 0x1.35a0cap-4, -0x1.397d5ap-7, 0x1.0b83f4p-4, -0x1.5ce5f8p-4, -0x1.91ea28p-4, 0x1.104018p-5, 0x1.c66bdp-3, 0x1.e9eb8p-5, -0x1.1bab16p-1, 0x1.97287ap-5 }, { -0x1.67fed2p-3, -0x1.036edep0, -0x1.bc0a54p-1, -0x1.283242p-2, -0x1.da5468p-2, -0x1.07e22p-1, -0x1.01e08p0, -0x1.3c881p-5, -0x1.8cb21ap-1, -0x1.674c62p-2, -0x1.88babp-2, -0x1.200a34p-5, 0x1.c3cd4ep-2, -0x1.720deep-2, -0x1.41e19cp0, -0x1.0b9fe8p-6 }, { -0x1.05c474p-2, -0x1.e70bfap-1, -0x1.aa4448p-1, -0x1.415a92p-1, -0x1.7eb12p-7, -0x1.697ebap-2, -0x1.c29646p-1, 0x1.9b3494p-7, -0x1.7a40f4p-1, 0x1.4319fap-8, -0x1.1c2b88p-3, -0x1.ad7054p-7, 0x1.18836ap-1, -0x1.9ff5ecp-2, -0x1.f83876p-2, -0x1.49176ap-5 } }, { { 0x1.fbc194p-2, 0x1.93e654p-2, 0x1.3516bp-9, 0x1.1e6e0cp-1, -0x1.b4f3cap-3, 0x1.4ad996p-4, 0x1.8d40c2p-2, 0x1.784f0cp-6, -0x1.96a3dcp-3, 0x1.1a951p-1, -0x1.041c2cp-2, -0x1.9bb394p-4, 0x1.d84ca6p-2, 0x1.134ccep-2, 0x1.43127cp-5, -0x1.152912p-10 }, { -0x1.33789cp-2, 0x1.b9e172p-4, -0x1.4ec296p-2, -0x1.5c78b4p-3, 0x1.045d5p-2, -0x1.0a20dp-4, -0x1.f8465p-3, 0x1.02f704p-3, -0x1.378782p-3, 0x1.8b16cp-2, -0x1.62abb4p-4, 0x1.528daep-5, 0x1.9bff1cp-4, -0x1.c759e2p-4, -0x1.86f0e4p-3, 0x1.a5dba6p-3 }, { -0x1.d13cdap-2, 0x1.3534f2p-4, -0x1.c7ed3p-3, -0x1.7ef818p-2, 0x1.348b06p-2, -0x1.166a3ap-3, 0x1.ce018ap-9, 0x1.e87ceap-4, -0x1.3656eep-3, -0x1.d7ff4ap-6, 0x1.e9676cp-3, -0x1.7b7ea4p-5, -0x1.5bb8f4p-3, -0x1.7ab714p-3, -0x1.da61f6p-3, 0x1.6bb0cep-3 }, { -0x1.70e41cp-2, 0x1.0015a4p-10, 0x1.1b1686p-4, -0x1.351fb2p-2, 0x1.150174p-2, -0x1.04378ep-5, -0x1.015c54p-8, 0x1.106262p-3, -0x1.5eeaaap-3, -0x1.918d5ap-5, 0x1.fc0686p-3, -0x1.71c89p-4, -0x1.d18ceap-4, -0x1.42780cp-4, 0x1.8545aep-4, 0x1.0e8fcap-3 }, { -0x1.b6854cp-2, -0x1.0b7ed6p-3, -0x1.8ec508p-4, -0x1.2e5d6ep-2, 0x1.3c53b8p-2, 0x1.158a76p-5, -0x1.51a4fp-5, -0x1.160082p-7, -0x1.89981p-6, -0x1.c11144p-4, 0x1.609046p-2, -0x1.5e1cp-3, 0x1.0960d2p-4, -0x1.073a4p-4, -0x1.4dc6a6p-6, 0x1.a2e932p-4 }, { -0x1.1a666cp-2, -0x1.fc5c6ap-6, -0x1.edd5a8p-6, -0x1.21f384p-2, 0x1.4ecee4p-4, 0x1.115c88p-3, 0x1.92dfdap-5, -0x1.49c7dap-4, 0x1.4a239p-5, -0x1.60f78p-5, 0x1.eeddp-4, -0x1.29d372p-2, 0x1.750024p-4, -0x1.59f606p-6, -0x1.e8a77cp-6, -0x1.4e4d18p-5 }, { -0x1.8e26e2p-2, -0x1.058adcp-3, 0x1.473aa8p-5, -0x1.73754ap-3, 0x1.a44dep-5, 0x1.93edfcp-4, 0x1.503128p-4, -0x1.39a7ccp-3, -0x1.cda534p-4, -0x1.3b6178p-5, 0x1.601444p-4, -0x1.e81e12p-3, 0x1.bc6c44p-4, 0x1.418d56p-5, -0x1.a3d6b6p-4, -0x1.34135ep-5 }, { -0x1.630754p-3, -0x1.7b3a5ap-6, -0x1.6d951ep-4, -0x1.954118p-3, 0x1.f4ce96p-4, 0x1.03327ep-3, 0x1.4ac81cp-4, -0x1.a7d3c6p-10, -0x1.d4133ap-7, 0x1.049e5p-2, 0x1.1499c6p-3, -0x1.ddfa88p-5, 0x1.41f928p-4, 0x1.066b1cp-4, -0x1.d429dep-6, -0x1.21f296p-5 }, { -0x1.1c8684p-4, -0x1.76f016p-5, -0x1.5f901ap-5, -0x1.638086p-2, 0x1.0b25e8p-2, 0x1.d421fap-4, 0x1.13427ep-4, -0x1.55a572p-5, -0x1.33fad8p-2, 0x1.45e0dp-3, -0x1.f0769cp-4, -0x1.3140d4p-3, -0x1.3bdd22p-5, 0x1.1c289p-5, -0x1.6456c8p-4, 0x1.5a688ep-6 }, { -0x1.cf3962p-4, 0x1.1735ap-4, 0x1.cab78cp-4, -0x1.423f4ap-3, 0x1.164c14p-3, -0x1.b43548p-5, -0x1.d0a67cp-4, 0x1.936bb4p-8, -0x1.a6d18p-3, 0x1.34630ap-2, 0x1.34c9f2p-3, -0x1.6a95cp-5, -0x1.4155dp-4, 0x1.7bef58p-4, -0x1.357b7ep-3, 0x1.827ce2p-5 }, { -0x1.f6aab8p-4, 0x1.c0f296p-4, 0x1.0e1d82p-4, -0x1.07f558p-4, 0x1.3c3638p-3, 0x1.4fcd9ap-4, -0x1.4655bap-4, 0x1.8091a4p-6, -0x1.aa949cp-2, 0x1.2d44c2p-3, -0x1.05cd2ep-6, -0x1.5efcf2p-4, 0x1.f63476p-4, 0x1.7a6192p-3, -0x1.0c4e7ap-2, 0x1.be63a2p-3 }, { -0x1.33f884p-2, 0x1.8705cp-4, 0x1.a30b22p-4, 0x1.d57f2ap-6, 0x1.c83272p-4, -0x1.2e809ep-3, -0x1.b11eb6p-4, -0x1.c7162cp-5, 0x1.4225aap-8, 0x1.d1ab8p-7, -0x1.712caap-4, -0x1.3be778p-2, 0x1.aaf3fp-4, 0x1.aa3558p-4, -0x1.2801ap-5, -0x1.5a3b94p-10 }, { -0x1.59daf2p-3, -0x1.8c0b88p-6, 0x1.ee381ap-4, -0x1.1fa1bp-4, 0x1.741cf2p-4, 0x1.606678p-5, -0x1.7e1058p-4, -0x1.e2f494p-5, -0x1.8a7784p-7, -0x1.1d58f4p-2, -0x1.520c26p-4, -0x1.77a81cp-3, 0x1.8e978ap-5, -0x1.0b6b2p-4, -0x1.1f9dcap-3, 0x1.8f5c04p-6 }, { -0x1.9b3982p-3, 0x1.1e0ecp-4, -0x1.f0af4p-5, 0x1.0d269p-2, -0x1.f7dbc8p-4, 0x1.e8aedcp-5, -0x1.02a70ap-5, -0x1.ff5eacp-4, 0x1.0fc5fcp-3, -0x1.b76826p-4, -0x1.3f13f6p-2, -0x1.c572e8p-4, 0x1.195896p-2, -0x1.1a55fp-4, -0x1.10faecp-3, 0x1.099072p-4 } }, { { -0x1.d204c4p-4, 0x1.f8396p-10, -0x1.0cfca4p-5, -0x1.9de3d8p-6, 0x1.8676p-6, 0x1.7c9c1p-5, -0x1.8a32b8p-3, -0x1.7a0d76p-4, -0x1.ef773ap-10, 0x1.0f4b38p-8, -0x1.0b0634p-4, -0x1.d67146p-6, 0x1.b8cb06p-4, 0x1.1d1ab8p-3, 0x1.ccff9ep-8, -0x1.5e58fap-4 }, { 0x1.5f8b38p-6, -0x1.8ed5aep-6, -0x1.9184f4p-3, 0x1.1c35f8p-5, 0x1.7d2f3cp-5, -0x1.a069e2p-10, -0x1.dcc176p-4, -0x1.d85f0ap-4, 0x1.f6df1cp-7, -0x1.f85172p-4, -0x1.d7089ap-3, -0x1.986a4cp-5, -0x1.5fd314p-5, -0x1.382254p-3, -0x1.10fd76p-3, -0x1.02e7ecp-2 }, { -0x1.23fa6cp-5, -0x1.9f0ad4p-4, -0x1.273ec8p-4, -0x1.fffd7p-4, -0x1.334a9ep-3, -0x1.6937b2p-3, 0x1.b7582ep-10, -0x1.42385ap-4, 0x1.212844p-6, -0x1.db5396p-9, 0x1.3d5b08p-4, -0x1.2335fap-3, 0x1.275526p-5, -0x1.16c284p-4, -0x1.5042bap-3, -0x1.a4f62ap-4 }, { 0x1.a8fdeap-5, 0x1.02ed82p-4, -0x1.ce268ap-4, 0x1.249f58p-5, 0x1.1c391ep-7, 0x1.e0db66p-7, -0x1.b9f4d6p-8, -0x1.f357acp-6, -0x1.ee9292p-6, -0x1.b2a096p-5, -0x1.603c2p-4, -0x1.72e286p-5, -0x1.83c1aap-4, 0x1.bf8466p-5, -0x1.954e9p-3, -0x1.6b1bdep-3 }, { -0x1.793d42p-5, -0x1.4a756p-4, 0x1.433b5p-4, 0x1.e760c2p-5, 0x1.7a6db6p-4, -0x1.078342p-5, -0x1.5931bcp-4, 0x1.a8b5c2p-4, -0x1.42090ep-4, 0x1.5f9e44p-5, -0x1.85e75cp-4, -0x1.61c0fap-3, -0x1.066c3ap-3, 0x1.630d86p-4, -0x1.77e2p-4, -0x1.ad30bep-5 }, { -0x1.0d9bbap-3, 0x1.4add9ep-8, -0x1.114154p-4, -0x1.ad0f32p-3, 0x1.6f9cb2p-5, -0x1.383d8cp-8, -0x1.3e49f2p-3, 0x1.13dcdcp-4, -0x1.d1ab4ap-8, -0x1.fa8fbcp-5, -0x1.4c8dc6p-3, 0x1.8e8516p-4, -0x1.8d916ap-4, -0x1.8782bp-4, 0x1.9ece9ap-5, -0x1.57bb3ep-3 }, { -0x1.044826p-5, -0x1.546118p-5, 0x1.a86132p-7, 0x1.499d0cp-6, 0x1.37d478p-7, 0x1.00403p-5, -0x1.143beap-7, 0x1.e9807ep-5, -0x1.e89eb4p-8, -0x1.8aee3cp-4, -0x1.c82ddcp-4, 0x1.c1696ap-5, -0x1.db444ap-4, -0x1.3cfb2ep-4, -0x1.6da992p-5, 0x1.4c377ep-6 }, { 0x1.4f72dcp-5, 0x1.5c23dp-5, -0x1.7b5d4ap-4, -0x1.09f5bap-5, -0x1.ca03ccp-4, 0x1.ca8606p-5, -0x1.69e86cp-5, -0x1.a2679p-4, -0x1.380c0cp-3, 0x1.6f282ep-8, -0x1.0222c8p-3, -0x1.cd63bep-4, -0x1.76f14ap-3, -0x1.b02c1ap-5, 0x1.a97896p-6, -0x1.a44724p-3 }, { -0x1.2a7e1ap-3, -0x1.a5a718p-3, 0x1.6b48p-9, 0x1.4b086ep-4, -0x1.05c7bep-3, -0x1.1f337ap-3, -0x1.666f3ap-3, 0x1.fba30ep-4, -0x1.724d96p-3, -0x1.1c7ebap-3, -0x1.5b63ccp-3, -0x1.fa0098p-5, 0x1.b065eep-8, 0x1.0d9f8ap-4, -0x1.50c4cp-4, -0x1.5e1a88p-3 }, { 0x1.f23ddap-4, -0x1.a2f29ap-3, -0x1.a1ba44p-3, -0x1.3c76e8p-3, -0x1.ee9fc2p-5, -0x1.3a04p-3, -0x1.88be0ep-5, 0x1.707e88p-6, -0x1.532b3ap-8, 0x1.abd094p-5, 0x1.baddfap-5, -0x1.40f99ap-3, 0x1.44476ap-4, 0x1.099124p-4, -0x1.7e9548p-3, -0x1.ebaf5cp-5 }, { -0x1.88bc8cp-4, -0x1.49c172p-5, -0x1.077454p-4, 0x1.b3fdbap-4, 0x1.28e53p-4, 0x1.1322d6p-5, 0x1.115ca2p-8, -0x1.b0d4cap-8, -0x1.2e2a88p-3, 0x1.67779ep-4, -0x1.7f43fcp-3, -0x1.b17eaep-4, 0x1.3b8b9ep-4, -0x1.b3019cp-7, -0x1.ba7028p-4, -0x1.ad6a92p-3 }, { 0x1.4b618ap-4, -0x1.213352p-5, -0x1.2bd472p-6, -0x1.7eaae6p-3, -0x1.0aaffap-4, 0x1.cbe23ap-5, -0x1.0dd356p-5, -0x1.f0a6eep-6, -0x1.eb79f4p-5, 0x1.d99064p-5, -0x1.85f7d8p-3, -0x1.15c69ep-4, -0x1.65a992p-7, 0x1.7c29cp-4, -0x1.55a5bap-3, -0x1.85e65ap-3 }, { 0x1.dcc314p-5, -0x1.0bda68p-8, -0x1.790798p-5, -0x1.1fc9e8p-6, -0x1.549cd4p-5, -0x1.377064p-3, 0x1.e7a48ap-5, -0x1.c8c752p-5, -0x1.6a4668p-4, 0x1.002dc6p-3, -0x1.e1594ap-4, 0x1.7bde38p-5, 0x1.ff75f8p-6, 0x1.17f578p-5, -0x1.c1aff8p-5, -0x1.ba2122p-8 }, { 0x1.7cd1c8p-4, -0x1.a1254ap-3, -0x1.4ef73p-3, -0x1.45c6fp-2, -0x1.42c74cp-5, 0x1.81c8dap-4, -0x1.a538dp-4, 0x1.2368b6p-3, -0x1.53df4ep-4, 0x1.07f7f2p-4, 0x1.cadbbp-6, -0x1.7ab384p-5, -0x1.c604dep-6, -0x1.9ea5bap-8, -0x1.7868bp-4, -0x1.8a8752p-5 } }, { { -0x1.35e03cp-4, 0x1.c287p-5, -0x1.e548eep-3, 0x1.602f42p-2, 0x1.a2be6cp-2, -0x1.fc4024p-4, -0x1.f89abap-7, 0x1.7a15fcp-3, 0x1.459faap-9, 0x1.1e5db8p-7, 0x1.2078f2p-4, 0x1.5d0758p-5, -0x1.459ceap-1, -0x1.6a9c46p-3, 0x1.c21724p-7, 0x1.e1b99ep-3 }, { -0x1.45c87ep-2, 0x1.3c02c6p-4, -0x1.500ac2p-2, 0x1.c0fa36p-4, 0x1.98776ap-2, -0x1.3b2fb8p-2, 0x1.c1e226p-5, -0x1.2ab7f8p-4, 0x1.0c4fbp-3, -0x1.ca7c4ep-5, -0x1.f78674p-5, 0x1.6f4aeep-5, -0x1.28ce6p-3, -0x1.7c21f2p-2, 0x1.a7d89ep-3, 0x1.b24deap-4 }, { -0x1.5a769p-1, -0x1.6b37a2p-7, 0x1.5cc0fcp-4, 0x1.b611bep-5, -0x1.37d2bp-2, -0x1.ed8d6cp-2, 0x1.8b46aep-3, -0x1.322342p-5, 0x1.5b715ep-3, 0x1.0d377p-3, -0x1.620778p-3, 0x1.49c092p-6, -0x1.2c7acep-5, -0x1.a944bap-3, 0x1.370b8ep-5, -0x1.0aedf6p-9 }, { -0x1.aa3e4p-8, -0x1.ca2586p-3, 0x1.3ac03cp-2, -0x1.071ae8p-5, -0x1.030fccp-1, -0x1.86b09cp-2, 0x1.127c16p-3, -0x1.2e1f5cp-5, 0x1.b7d756p-5, 0x1.128266p-2, -0x1.28cdfcp-3, -0x1.c7fb04p-7, -0x1.763a0ep-2, 0x1.fc27p-5, -0x1.bea6a2p-2, 0x1.22f166p-4 }, { -0x1.58f2fcp-4, -0x1.7fc45cp-3, 0x1.030a8cp-5, 0x1.c9f1d8p-3, -0x1.db1c0cp-2, -0x1.38f7eep-1, 0x1.84b612p-5, 0x1.05fab6p-8, -0x1.c94bbcp-4, 0x1.04f996p-2, -0x1.efcfacp-3, -0x1.c71c5p-10, -0x1.2c33eap-1, 0x1.19f28ep-3, -0x1.4f4926p-2, -0x1.17fb42p-5 }, { -0x1.544a68p-3, -0x1.7d4cf2p-3, 0x1.f48ce4p-3, 0x1.a963bap-2, 0x1.af5d4cp-4, -0x1.71479ap-2, -0x1.d5e506p-4, -0x1.f833b4p-6, -0x1.44ed1ap-6, 0x1.44ac2ep-6, -0x1.0153e8p-3, 0x1.6dbcb6p-5, -0x1.5af01ep-1, -0x1.fdb8fep-5, -0x1.264716p-4, 0x1.1c8816p-5 }, { -0x1.e7b5a2p-3, -0x1.b73f9ep-3, 0x1.4bd2ap-3, 0x1.2ad906p-2, 0x1.ec10e4p-5, -0x1.a3cb5cp-3, -0x1.49e1a8p-4, -0x1.9c0df2p-4, 0x1.29312p-3, 0x1.405248p-7, -0x1.38ea22p-3, 0x1.56ed32p-7, -0x1.82c936p-2, -0x1.10babp-3, 0x1.1e1398p-3, -0x1.3c2adcp-5 }, { -0x1.da8a2ep-4, -0x1.01682ap-3, 0x1.060ce2p-4, 0x1.64fdcap-2, 0x1.af2ae4p-3, -0x1.f0562p-3, -0x1.2f171ep-3, -0x1.d396f4p-5, -0x1.6bd326p-5, 0x1.2694ep-3, -0x1.bc5e52p-4, 0x1.1e5892p-5, 0x1.f7a368p-3, -0x1.35fe2ap-5, 0x1.2dd612p-5, 0x1.28402cp-4 }, { -0x1.6f02c4p-3, -0x1.5369e8p-6, -0x1.f7d342p-6, 0x1.f9c0d4p-4, 0x1.9e7c68p-3, -0x1.6e8b86p-3, 0x1.26f97ap-5, 0x1.438bp-6, -0x1.285b2ap-4, 0x1.87e46ep-4, -0x1.6a99d4p-6, 0x1.1cd878p-5, 0x1.d4072ap-4, -0x1.4b96p-4, 0x1.29b78cp-4, 0x1.3eebcp-4 }, { -0x1.9a566ap-6, -0x1.3bac96p-6, 0x1.69cc32p-3, 0x1.518f2ap-4, 0x1.9b5072p-3, -0x1.5dfc34p-3, 0x1.188cc6p-4, -0x1.18c764p-3, -0x1.04a796p-6, 0x1.47981ap-5, 0x1.ffdd26p-6, -0x1.217542p-5, -0x1.fb3fe8p-8, -0x1.a4c7c8p-3, 0x1.b67f4p-4, -0x1.4319c6p-4 }, { -0x1.ea9eeap-5, 0x1.cd86c8p-6, 0x1.2cd522p-2, 0x1.831eb6p-3, 0x1.1bda16p-2, -0x1.8ff5c2p-5, 0x1.4cf3dp-4, 0x1.ee9cfep-7, -0x1.e37e7ap-10, 0x1.245d06p-4, -0x1.879028p-4, 0x1.00d284p-5, 0x1.17270cp-4, -0x1.6f678cp-3, -0x1.4f18bap-7, -0x1.92e1dcp-6 }, { -0x1.2debeep-2, 0x1.c2407ep-4, 0x1.16f40ep-2, 0x1.2e8d82p-5, 0x1.799872p-3, -0x1.2341a8p-3, 0x1.c71648p-4, 0x1.926536p-5, -0x1.10df82p-3, 0x1.1c42bep-5, 0x1.35838p-5, 0x1.1c609ap-4, 0x1.5dbe1ap-3, -0x1.9708bp-3, 0x1.0a112cp-4, 0x1.9e5d34p-7 }, { -0x1.849a4cp-2, 0x1.d4ecfp-4, 0x1.1403acp-5, -0x1.f1dfeap-3, 0x1.0536ccp-2, -0x1.bed72p-3, 0x1.f3bf18p-4, -0x1.d33108p-2, 0x1.e69c7p-7, 0x1.55599cp-3, 0x1.00523ap-4, -0x1.29a808p-2, -0x1.5f16bap-3, -0x1.8bbc04p-2, -0x1.1cd778p-5, -0x1.64681cp-4 }, { -0x1.e383f8p-3, -0x1.493566p-6, 0x1.aa51a4p-3, 0x1.2a9732p-3, -0x1.173cd6p-2, -0x1.4d4e1ep-2, 0x1.fe393ep-5, -0x1.ad2e06p-2, -0x1.fc5bd8p-5, 0x1.5544b4p-3, 0x1.f2032cp-6, -0x1.a75404p-2, -0x1.3c7562p-1, 0x1.a1dc96p-3, -0x1.950866p-3, -0x1.94bd5cp-2 } }, { { -0x1.7b5adap-3, -0x1.17b86ap-4, -0x1.3276fep-3, -0x1.d27feep-4, -0x1.521a72p-2, -0x1.5f5ec4p-3, -0x1.e484ap-4, 0x1.d94416p-4, -0x1.dc730ep-3, -0x1.31c54p-5, -0x1.3bf3ap-4, 0x1.399488p-7, 0x1.86a644p-2, -0x1.271316p-2, -0x1.5580b6p-3, -0x1.d2118ap-6 }, { -0x1.76f4aap-4, -0x1.88b34cp-3, -0x1.3cb524p-2, -0x1.244288p-2, -0x1.ae9f2ep-3, -0x1.324dccp-3, -0x1.f234f8p-2, 0x1.345b4ep-6, -0x1.72d942p-2, -0x1.e03e2ep-2, -0x1.c6826cp-3, -0x1.e5f7c2p-5, 0x1.c0a4eep-2, -0x1.02475p-1, -0x1.684668p-3, -0x1.7cf90cp-4 }, { -0x1.bc632ap-2, -0x1.08f3d4p-3, -0x1.990446p-2, -0x1.3993ecp-1, 0x1.82fa34p-7, -0x1.d78396p-3, -0x1.5a8feep-1, -0x1.650ffcp-5, -0x1.04e75ap-2, -0x1.7da344p-3, -0x1.11f498p-5, -0x1.7bc3dep-5, 0x1.e4995ep-3, -0x1.428cf2p-2, -0x1.c2e6b4p-2, -0x1.90161ap-4 }, { 0x1.22445ap-2, -0x1.fa127ep-3, -0x1.4bce3p-3, -0x1.92a04p-5, -0x1.96521p-7, -0x1.05ad9cp-2, -0x1.d9c13p-2, 0x1.5a7b9ap-5, -0x1.61f1e8p-4, -0x1.e7dcf4p-4, -0x1.b1a842p-14, -0x1.03e7e2p-4, 0x1.18105ep-5, 0x1.328dp-3, -0x1.3879p-2, -0x1.e48d82p-4 }, { 0x1.75123ap-3, -0x1.14c952p-3, -0x1.5fc76ap-5, -0x1.ab1b32p-3, -0x1.9e2232p-4, -0x1.74bap-5, -0x1.70e1dep-2, -0x1.9dce5ep-7, 0x1.4378aep-2, -0x1.b39b78p-6, -0x1.7cd4fap-4, -0x1.74dc46p-5, -0x1.eecb9p-5, -0x1.35d364p-3, -0x1.f5669ep-3, -0x1.7a5324p-5 }, { 0x1.59e384p-2, -0x1.726acp-5, 0x1.d14c92p-6, 0x1.09e86ap-3, -0x1.124c82p-7, 0x1.469ca2p-2, -0x1.34e8acp-4, 0x1.28215cp-4, 0x1.a3d202p-5, 0x1.8a3b8p-5, -0x1.6963p-6, -0x1.96a336p-4, -0x1.5b955p-5, -0x1.a42546p-7, -0x1.0bdc44p-3, -0x1.cc99ep-5 }, { 0x1.461424p-2, -0x1.1bcf5cp-6, 0x1.906544p-3, -0x1.8c4bb2p-4, 0x1.1dcf3ep-3, 0x1.41a906p-3, -0x1.e023eap-6, 0x1.1963bp-4, 0x1.aa075ap-8, 0x1.809f0ep-4, 0x1.6c2f6ap-5, -0x1.11b826p-5, 0x1.4650dap-5, -0x1.289048p-2, -0x1.9f7db2p-5, -0x1.203016p-4 }, { 0x1.23dc08p-2, 0x1.4024cp-3, 0x1.62a148p-3, -0x1.2368f2p-4, 0x1.fa776cp-4, 0x1.9c750ep-4, 0x1.784b56p-5, 0x1.ed745cp-8, 0x1.117c44p-2, 0x1.223a82p-4, 0x1.245c8p-4, 0x1.21b004p-4, -0x1.b07edp-3, -0x1.af5936p-4, -0x1.14da3p-8, -0x1.fbe83ep-7 }, { 0x1.128bd2p-3, 0x1.2bfd3ep-4, 0x1.55f13ap-3, -0x1.30b2aap-3, 0x1.6dfb62p-3, 0x1.775454p-3, -0x1.73ed4cp-11, -0x1.e89b42p-5, 0x1.1bcdb2p-2, -0x1.194bp-6, 0x1.4ae8c2p-5, 0x1.e3fc68p-5, -0x1.1f6b78p-2, -0x1.e8828cp-2, 0x1.3de42ep-10, 0x1.9c8bp-6 }, { 0x1.1fa348p-2, -0x1.865dc6p-7, 0x1.68487ap-2, -0x1.603d62p-5, 0x1.9a6d3p-4, 0x1.aa9018p-5, -0x1.2cde72p-3, -0x1.69043ap-3, 0x1.02fb8p-2, -0x1.15c2e6p-3, 0x1.272a3ap-5, -0x1.ead6a4p-8, -0x1.78fc84p-2, -0x1.98b418p-2, -0x1.8782d6p-6, 0x1.ef450ap-6 }, { 0x1.97de22p-3, 0x1.0b7348p-4, 0x1.7cec36p-2, -0x1.a8413ep-4, 0x1.542acap-3, 0x1.fdbadcp-4, -0x1.426ae4p-5, -0x1.901ea8p-3, 0x1.8dcffcp-3, -0x1.0100dep-4, 0x1.9059e8p-4, -0x1.1c168ap-4, -0x1.33a766p-2, -0x1.32c824p-3, 0x1.69311cp-7, 0x1.b9047ep-5 }, { 0x1.1ab80ap-2, 0x1.3adaccp-5, 0x1.f3c9dp-3, -0x1.180c12p-5, 0x1.204bf8p-4, 0x1.e3b5bp-4, 0x1.30fd76p-3, 0x1.c2f34ep-6, 0x1.62cadp-5, -0x1.1e2dp-3, 0x1.f2554cp-7, 0x1.ead49ep-4, -0x1.071c5ap-2, -0x1.0c35dep-4, -0x1.a731aep-6, 0x1.f733b8p-4 }, { 0x1.a05bdp-2, -0x1.473326p-3, 0x1.09ba6cp-2, 0x1.141e82p-3, -0x1.aa972p-6, 0x1.5881a6p-4, 0x1.2a111cp-6, -0x1.deb798p-3, 0x1.12f604p-2, -0x1.aa54dep-3, -0x1.9aaec8p-4, 0x1.51451ap-4, -0x1.843f54p-5, -0x1.b84424p-3, -0x1.87f534p-5, -0x1.0327cp-4 }, { -0x1.e8f14cp-5, -0x1.a91afp-2, -0x1.658efcp-1, -0x1.0d8002p-1, -0x1.ff5bbp-5, -0x1.4f8fa4p-2, -0x1.ff8b7cp-2, 0x1.07ea3cp-7, -0x1.0f5d2cp-1, -0x1.c1ec86p-3, -0x1.18fc38p-2, -0x1.a20ba8p-5, 0x1.192042p-2, -0x1.0b9626p-2, -0x1.0b69bep-1, 0x1.4ef386p-8 } }, { { 0x1.72a8cp-7, 0x1.233424p-4, 0x1.1aa7c4p-4, -0x1.b693dp-9, -0x1.2b985p-2, -0x1.aef2p-6, 0x1.00fc54p-6, -0x1.2abf92p-3, 0x1.98fc9ep-5, -0x1.b0da94p-7, -0x1.2f44dap-3, -0x1.22c838p-3, 0x1.fbe40ap-3, 0x1.682c1ep-8, 0x1.106d3p-4, -0x1.81230ep-2 }, { 0x1.9b7674p-6, -0x1.50bb12p-2, 0x1.c5b6cep-4, -0x1.bfc7ap-5, -0x1.1d5a56p-3, -0x1.483c98p-3, -0x1.1edfcep-2, 0x1.6b4614p-6, -0x1.17e7fcp-4, 0x1.85f684p-4, -0x1.6060f6p-5, -0x1.937f7ap-3, 0x1.29256cp-3, -0x1.7a2b2ep-5, -0x1.16b1f4p-4, -0x1.12bb1p-2 }, { -0x1.c9011ap-3, -0x1.d96676p-3, -0x1.b5a90ep-8, -0x1.c86324p-3, -0x1.e90b14p-4, -0x1.49133cp-4, -0x1.bbaebcp-3, -0x1.8ae77ep-3, 0x1.a54aeep-7, -0x1.4e9474p-4, -0x1.7df66ep-7, -0x1.1d3848p-4, -0x1.22a83cp-6, -0x1.8b5e9p-5, 0x1.3d184ap-5, -0x1.2435e4p-4 }, { 0x1.756ef6p-3, -0x1.31d218p-2, 0x1.62e8ep-4, -0x1.b35286p-3, 0x1.31c7c2p-5, -0x1.210386p-2, -0x1.1018a6p-3, -0x1.4ab20cp-4, 0x1.44e212p-6, 0x1.4c60f8p-4, 0x1.5675aep-8, -0x1.d1f2p-5, -0x1.3254f2p-3, -0x1.6306dap-4, -0x1.2b864p-5, -0x1.2adcep-4 }, { -0x1.a649b4p-5, -0x1.6d10d8p-2, 0x1.beca28p-5, -0x1.83abp-3, 0x1.6e635ep-3, -0x1.395b46p-5, -0x1.17f45ep-3, -0x1.5cb3dap-3, 0x1.b73ad4p-3, -0x1.1fbc6ep-4, 0x1.613672p-4, -0x1.07815ep-5, 0x1.09870ap-3, -0x1.709e1ep-7, -0x1.0d661ep-3, -0x1.5640c8p-3 }, { 0x1.3b6102p-3, -0x1.1810aep-2, 0x1.cf78c4p-4, 0x1.9dbe8ap-5, 0x1.52fb4p-5, -0x1.89a90ep-4, -0x1.a94f64p-5, 0x1.1ff50ep-4, 0x1.680a96p-3, 0x1.52b5dep-4, -0x1.93a5aap-4, -0x1.2d7accp-5, 0x1.119ea8p-3, 0x1.e914a8p-6, 0x1.639b8cp-3, -0x1.f8dbecp-7 }, { -0x1.203cfcp-5, -0x1.3a8c6p-3, -0x1.38cabap-6, -0x1.9b7dd4p-3, -0x1.2380ecp-6, 0x1.6708dap-5, -0x1.358ac6p-3, 0x1.55409p-4, 0x1.4eaa58p-3, 0x1.2883dcp-4, 0x1.445674p-6, -0x1.2b4028p-3, 0x1.b6ea66p-8, -0x1.ba1dc4p-5, 0x1.87291ap-6, -0x1.871cecp-2 }, { -0x1.0ba04cp-3, -0x1.86f966p-4, 0x1.477b2ap-4, -0x1.8e0f3p-6, -0x1.ef8176p-5, 0x1.010e16p-6, -0x1.11b476p-4, 0x1.06a786p-3, -0x1.00fbc6p-3, 0x1.81e2aep-7, -0x1.47e5a6p-5, -0x1.9e8f9ep-4, -0x1.186aaap-5, -0x1.c08274p-5, 0x1.438366p-3, -0x1.f2f22ep-3 }, { -0x1.1d3c9ep-3, -0x1.012302p-3, -0x1.78b75ep-6, -0x1.a179c4p-6, 0x1.3bfd4ap-4, -0x1.277a06p-2, -0x1.52b23cp-4, -0x1.a1d43ep-4, 0x1.06c392p-3, 0x1.2c99dp-3, -0x1.8307cap-9, -0x1.a4efa6p-4, -0x1.1b3d3cp-6, -0x1.6e82eap-7, -0x1.e080c2p-5, -0x1.bdd97ep-4 }, { -0x1.dcc718p-6, -0x1.d00d82p-4, 0x1.9c2e2ap-7, -0x1.e155dcp-4, -0x1.04242ep-5, -0x1.cf7f76p-3, -0x1.89966ap-3, 0x1.455e8p-4, -0x1.3bd382p-6, 0x1.c2a308p-3, 0x1.ff5bd4p-5, 0x1.0426bep-6, -0x1.ea390ep-6, 0x1.d188b8p-6, -0x1.d14782p-5, -0x1.317e58p-2 }, { 0x1.a543eep-8, 0x1.4898ep-7, -0x1.1633c4p-4, -0x1.2f2bap-3, -0x1.56bd48p-3, -0x1.a622aap-3, -0x1.f9b866p-3, 0x1.00bf46p-3, 0x1.e4b882p-4, -0x1.d1561ap-4, 0x1.49f3bap-5, 0x1.0c0efep-3, 0x1.4da0c4p-5, -0x1.f264e4p-4, -0x1.9cf5p-4, -0x1.38015p-3 }, { -0x1.66745p-3, -0x1.cdf9dep-6, 0x1.c9a8d2p-4, -0x1.66bb34p-3, 0x1.b23f62p-6, -0x1.b9d15p-5, -0x1.3abdb6p-2, -0x1.71582ep-6, 0x1.9aa4b4p-5, -0x1.2e007ap-6, -0x1.a75534p-3, -0x1.31198p-3, -0x1.5127bap-5, 0x1.2ed54ap-4, -0x1.aa13c2p-5, -0x1.55b7d4p-2 }, { -0x1.401b62p-4, -0x1.196e66p-3, 0x1.caf9e6p-4, -0x1.380b3cp-2, -0x1.1cf6a4p-3, -0x1.16a0fap-3, -0x1.353314p-3, 0x1.bd20ep-6, -0x1.ff30e6p-7, 0x1.36e5e4p-3, -0x1.e4e2c8p-5, -0x1.f9b7aap-3, -0x1.8d696p-6, -0x1.8615p-7, 0x1.507cf8p-4, -0x1.b5b334p-2 }, { -0x1.433bccp-3, -0x1.606cbcp-3, 0x1.70298ap-3, 0x1.4743a2p-4, -0x1.7bba44p-3, -0x1.32e3acp-4, 0x1.1b57dp-2, 0x1.70d004p-11, -0x1.8c9e98p-4, 0x1.716664p-3, -0x1.461a52p-3, -0x1.b07308p-4, 0x1.5f2704p-4, 0x1.3176b6p-6, 0x1.4f2e66p-4, -0x1.2d244ap-2 } }, { { -0x1.f23ea2p-3, -0x1.16f048p-3, -0x1.f10a56p-3, 0x1.81a3eep-1, 0x1.35ab44p-2, -0x1.c7ff36p-3, -0x1.119618p-3, 0x1.33157p-4, 0x1.4b73a2p-5, -0x1.6323ap-5, 0x1.100c7ap-4, 0x1.daca8ep-4, -0x1.a58954p-2, -0x1.88d9b2p-2, 0x1.85dd42p-4, 0x1.c578acp-3 }, { -0x1.82faecp-3, 0x1.acc06ap-5, -0x1.3aa0d8p-3, 0x1.09e99ep-4, 0x1.9c3ac2p-3, -0x1.6d9bd4p-3, 0x1.ef8588p-7, -0x1.28d542p-5, 0x1.9603e4p-4, 0x1.1bcce6p-3, -0x1.9aa9eep-5, 0x1.e01636p-4, 0x1.98d7bp-3, -0x1.7fb20ap-2, 0x1.14b452p-3, 0x1.542aa8p-4 }, { -0x1.5ba0d4p-2, 0x1.fd536ap-5, -0x1.4536b6p-4, 0x1.3dd6ccp-3, 0x1.67f5bep-4, -0x1.d77202p-4, 0x1.f6c1dap-5, -0x1.5787bap-6, 0x1.4ff338p-4, 0x1.ae0af8p-4, -0x1.6ec5e6p-2, 0x1.f7133ap-5, 0x1.404a5cp-7, -0x1.7bc9b6p-3, 0x1.7bdc1cp-5, 0x1.b9a738p-6 }, { -0x1.709ap-3, -0x1.3c79acp-5, 0x1.288316p-3, 0x1.42d6acp-3, -0x1.6817f8p-2, -0x1.49dd18p-3, 0x1.91ed24p-3, 0x1.9d4802p-7, 0x1.17e70cp-5, 0x1.3b09bcp-3, -0x1.0153c2p-1, 0x1.4e074ap-4, -0x1.65e856p-5, -0x1.61daf6p-5, -0x1.556daep-3, -0x1.554f48p-4 }, { 0x1.b350ecp-3, -0x1.7e56c6p-5, 0x1.1b62d4p-6, 0x1.21ee38p-2, -0x1.65515ap-4, -0x1.01c4bcp-2, -0x1.ce7762p-5, -0x1.10b154p-6, -0x1.cd279cp-3, 0x1.0bc87ap-4, -0x1.b0fbf8p-2, -0x1.d71ae6p-6, -0x1.d8cbeep-3, 0x1.a3a98ap-5, -0x1.961ac4p-3, -0x1.3f876p-5 }, { 0x1.d3310ep-5, -0x1.a5009ap-6, 0x1.701938p-3, 0x1.031712p-2, 0x1.d4f2aap-4, -0x1.91e5ap-4, 0x1.533968p-4, -0x1.060afep-4, 0x1.60ee0ap-8, 0x1.997ac4p-5, -0x1.928892p-4, 0x1.727fb8p-4, -0x1.c78aacp-2, 0x1.4cc2bcp-5, -0x1.241c62p-7, 0x1.27d056p-8 }, { -0x1.202b8p-3, -0x1.a8d7b6p-4, 0x1.2fef4ep-4, 0x1.1140c2p-3, 0x1.cb14a8p-3, -0x1.3b98bp-3, 0x1.c68866p-7, -0x1.ec28d2p-4, 0x1.a8c5fep-4, 0x1.16560ap-4, -0x1.265844p-3, 0x1.1e18a4p-5, -0x1.8f2c9p-4, 0x1.566a9ap-4, 0x1.d77c4p-4, -0x1.0de0c8p-4 }, { -0x1.4ae396p-4, 0x1.2a55aap-6, 0x1.0d54aep-3, 0x1.7828bcp-3, 0x1.23f196p-3, 0x1.da6868p-5, 0x1.16cd48p-7, -0x1.3ab6a4p-8, -0x1.2108f4p-4, 0x1.959022p-3, -0x1.15f2eap-4, -0x1.44cb06p-5, -0x1.2abac8p-5, -0x1.bc4522p-7, 0x1.24137ap-5, 0x1.d633fcp-6 }, { -0x1.5cf146p-5, 0x1.ffe6c4p-7, 0x1.06bc0ap-3, 0x1.6f3cd8p-4, 0x1.9a0762p-3, -0x1.fae4ccp-4, 0x1.22258ap-5, 0x1.567332p-6, -0x1.b5eb9p-5, 0x1.310866p-6, 0x1.33ac14p-4, -0x1.6b969ep-8, 0x1.8272p-3, -0x1.4e41b8p-7, 0x1.77b668p-4, 0x1.4c7866p-5 }, { 0x1.573274p-5, 0x1.ec6348p-5, 0x1.22f2ap-4, 0x1.86a1p-4, 0x1.727ab8p-3, -0x1.daf792p-6, 0x1.1177e4p-4, -0x1.bd64ecp-3, -0x1.730018p-4, 0x1.25222p-5, 0x1.8ff794p-5, -0x1.888788p-4, -0x1.046da6p-4, -0x1.b52c06p-4, 0x1.7e8d58p-4, 0x1.4cd64cp-5 }, { -0x1.1f4204p-3, 0x1.8412dp-3, 0x1.bbee64p-3, 0x1.d94b5ap-4, 0x1.63152ep-2, -0x1.dc1d8ep-4, 0x1.e05a24p-4, -0x1.5c040ap-2, 0x1.c658c6p-6, 0x1.8f0c38p-3, 0x1.8d4dcap-3, -0x1.1910d6p-4, 0x1.5108d6p-3, -0x1.f3895ap-3, -0x1.f88ceep-6, 0x1.504e8p-3 }, { -0x1.c06058p-4, 0x1.b16dcap-6, 0x1.2158dp-2, -0x1.38ea28p-3, -0x1.3d921ap-2, -0x1.9fd896p-3, 0x1.96f036p-4, -0x1.a7d7ecp-2, -0x1.db567p-4, 0x1.e8350cp-4, 0x1.a47e86p-6, -0x1.87237ep-2, 0x1.d432ecp-5, -0x1.6a53b2p-3, -0x1.cf0676p-10, -0x1.5d9adcp-1 }, { 0x1.4abfd8p-3, 0x1.3e036cp-4, 0x1.6eddacp-3, -0x1.930412p-3, -0x1.ceca62p-1, -0x1.f9ee34p-2, -0x1.f50152p-7, -0x1.40fc12p-2, -0x1.7038c4p-5, 0x1.3ca19cp-4, -0x1.8e96d2p-3, -0x1.1edaa6p-2, -0x1.482fdcp-2, 0x1.a4ea84p-7, -0x1.34cfcap-3, -0x1.a76e68p-1 }, { -0x1.67bf8ep-4, -0x1.00c0d4p-3, 0x1.81b264p-4, 0x1.39062ap-8, -0x1.3528f2p-2, -0x1.e21758p-2, -0x1.23b026p-3, -0x1.664c4ap-2, 0x1.8f9c26p-4, 0x1.2f6c74p-3, 0x1.dfb16ep-5, -0x1.c5823ep-2, -0x1.4c42b4p-3, 0x1.72177ap-3, 0x1.0f65e6p-4, -0x1.e02e8ep-2 } }, { { 0x1.b17212p-4, 0x1.02c278p-2, -0x1.75ca42p-4, 0x1.19004cp-3, -0x1.347d2ap-4, -0x1.63828ap-3, -0x1.29407ap-5, -0x1.64b004p-5, 0x1.ff8eb2p-6, 0x1.c40a2ap-2, -0x1.1e3b0cp-3, -0x1.78814p-2, 0x1.88bcdp-3, 0x1.f63f32p-4, -0x1.421dfcp-3, -0x1.cfe826p-3 }, { -0x1.c30472p-6, 0x1.b61be8p-4, -0x1.300bacp-2, -0x1.872daap-3, -0x1.09161ap-3, -0x1.3637b6p-4, -0x1.0d714ep-2, 0x1.914f26p-3, -0x1.e107fep-3, 0x1.6d2502p-2, -0x1.5bbcp-3, -0x1.a3d596p-2, 0x1.12be4cp-4, -0x1.28f152p-6, -0x1.81c88cp-6, -0x1.fef5fp-3 }, { -0x1.b4d8fep-4, 0x1.f44dep-5, -0x1.d1c39p-3, -0x1.44f1f2p-5, -0x1.fdc38cp-3, -0x1.434e9p-4, -0x1.c7b8f2p-7, 0x1.4a6676p-3, -0x1.14bbd2p-2, -0x1.84d4dp-3, -0x1.482b6cp-5, -0x1.d95714p-2, 0x1.e01aaep-4, -0x1.a01dd4p-4, -0x1.a9ccdcp-4, -0x1.087982p-2 }, { -0x1.1f8ffcp-3, -0x1.76ddcp-5, -0x1.eab76ap-3, -0x1.e164aep-3, 0x1.8b7334p-7, -0x1.a5c38p-6, -0x1.7986e2p-4, 0x1.167582p-5, -0x1.a9241ap-6, -0x1.28e52p-5, 0x1.f21e32p-7, -0x1.93611ap-2, 0x1.c117d8p-4, -0x1.25d6c2p-4, -0x1.e32198p-4, -0x1.247188p-4 }, { -0x1.674112p-7, -0x1.9bca9cp-5, -0x1.07a4f4p-4, 0x1.a134c2p-4, -0x1.299466p-4, 0x1.663518p-4, 0x1.a20c9cp-3, 0x1.66f5aap-4, -0x1.023ad4p-3, 0x1.898074p-2, -0x1.ddefccp-4, -0x1.3f1dc4p-3, 0x1.2dfb84p-2, -0x1.c5c2d8p-3, -0x1.27b1fep-3, -0x1.036d7ap-4 }, { 0x1.95b9bp-9, 0x1.97c5cap-10, -0x1.869892p-4, 0x1.4271f6p-4, -0x1.4ebd2cp-6, 0x1.47bd96p-5, 0x1.1e1a1ep-2, 0x1.08a936p-3, -0x1.f036fap-5, 0x1.545e0cp-3, -0x1.9d347cp-2, -0x1.4f4144p-2, 0x1.bc3ebp-3, 0x1.8bc846p-6, -0x1.3f884ap-3, 0x1.ad0134p-9 }, { 0x1.2f72d2p-3, 0x1.e3ac9ap-4, -0x1.94c7e6p-3, 0x1.9b4056p-4, -0x1.518628p-3, 0x1.0ae2c2p-3, 0x1.0f70d4p-5, 0x1.57f2aap-3, -0x1.1f0c72p-5, 0x1.c3aa7p-3, -0x1.4c49b6p-2, -0x1.59bc4p-3, 0x1.907e2ap-4, 0x1.8b373cp-5, -0x1.4413dap-3, -0x1.665854p-3 }, { -0x1.a9146ep-5, -0x1.08189p-10, -0x1.24465ep-3, 0x1.90f988p-3, -0x1.2bab04p-2, 0x1.0db4f2p-7, 0x1.67e25ap-5, -0x1.eec0aap-5, -0x1.0ac23ap-3, 0x1.1b9702p-2, -0x1.02100cp-3, -0x1.a38f2ap-5, -0x1.32e5ep-4, 0x1.8d640cp-4, 0x1.941ff6p-4, 0x1.fce71cp-9 }, { -0x1.ce69fap-5, -0x1.ba64ep-6, -0x1.d5325ap-2, -0x1.c8e784p-5, -0x1.1f28p-3, -0x1.74f4eap-4, 0x1.55890ap-5, 0x1.6110ecp-5, -0x1.3ae4a6p-4, 0x1.02ae6p-2, -0x1.2b2cdcp-4, 0x1.706a78p-5, -0x1.df3136p-9, 0x1.4ef1ep-5, 0x1.274fb8p-5, 0x1.024cdap-3 }, { 0x1.1aac18p-7, 0x1.4ce668p-5, -0x1.cba338p-2, -0x1.007a74p-4, -0x1.f07c24p-4, -0x1.042b5ep-4, -0x1.9240ap-3, 0x1.7c8ad2p-3, -0x1.5be354p-3, -0x1.b5308cp-3, -0x1.701274p-2, -0x1.d74e2p-3, 0x1.e255e8p-3, -0x1.35bc68p-5, 0x1.8a4a28p-4, -0x1.1c2158p-5 }, { 0x1.d9adbap-3, 0x1.da2094p-5, -0x1.8a0514p-3, 0x1.0400f2p-4, 0x1.da5b4p-3, -0x1.54779ep-4, 0x1.7778c4p-5, 0x1.0b083ap-2, -0x1.92eae8p-3, -0x1.027ae4p-2, -0x1.2763aap-3, -0x1.2adc2ap-2, 0x1.2a48dep-2, 0x1.45860ep-3, -0x1.384ee2p-5, -0x1.aaadfp-3 }, { -0x1.a0969ap-3, -0x1.c26c9cp-5, -0x1.104368p-1, -0x1.c2f23p-6, 0x1.b01c0ap-3, -0x1.ff475ep-4, -0x1.f09c4p-5, -0x1.fcf59cp-6, -0x1.05951ap-3, -0x1.704c18p-2, -0x1.5600c8p-2, -0x1.564ba4p-3, -0x1.9c8c3ep-5, -0x1.40246p-4, 0x1.535dd4p-3, -0x1.1fc0fep-2 }, { 0x1.56313cp-5, -0x1.2951c4p-3, 0x1.2fc646p-7, 0x1.4387dcp-3, 0x1.9dbe86p-4, -0x1.a43824p-8, 0x1.95aafep-4, 0x1.e2b878p-4, 0x1.88e32ap-5, -0x1.75e726p-2, -0x1.b926dp-3, -0x1.e2ce2p-2, 0x1.302a54p-5, 0x1.05c4e6p-8, 0x1.7923acp-4, -0x1.7396a4p-2 }, { 0x1.ae9596p-6, -0x1.46e4d8p-2, -0x1.db6deep-6, 0x1.f097e4p-11, -0x1.247644p-2, 0x1.21b326p-2, -0x1.2a8e8ap-3, -0x1.536a2ap-7, -0x1.c60024p-4, -0x1.4f65f6p-2, -0x1.36331p-2, -0x1.528e3p-3, -0x1.d9d0cap-8, -0x1.bd2baep-3, -0x1.5de088p-4, -0x1.c764bcp-3 } }, { { -0x1.b5191ep-4, 0x1.9dd842p-6, -0x1.93d8c2p-4, -0x1.5d7988p-2, -0x1.4eeeaap-2, -0x1.86deb6p-3, 0x1.e4f812p-5, -0x1.3b380ep-2, 0x1.a07f46p-7, -0x1.195238p-3, -0x1.765acep-5, 0x1.21db88p-5, -0x1.a944ap-2, -0x1.18528ep-3, 0x1.25233ap-5, -0x1.cfbb1p-15 }, { -0x1.5e0e7p-3, -0x1.6e0c34p-7, -0x1.4730c4p-2, 0x1.03993p-2, -0x1.ad2edcp-4, -0x1.bb172ap-4, 0x1.e748f2p-6, -0x1.23856ap-3, -0x1.cdd9a6p-3, -0x1.00ad46p-6, 0x1.c60002p-7, 0x1.0f12acp-8, -0x1.72b3c4p-3, 0x1.f6da9ap-4, 0x1.98734p-4, -0x1.1c8ad2p-4 }, { 0x1.ad08bep-4, 0x1.7b0942p-4, -0x1.700e2p-3, 0x1.21f53cp-3, -0x1.534f6ep-3, -0x1.d5112ep-5, -0x1.92897cp-7, -0x1.a55edap-3, -0x1.c08e36p-5, 0x1.129a5ap-3, 0x1.9b375ep-5, 0x1.1ac21cp-8, 0x1.87e0f2p-3, 0x1.ddc9e2p-3, 0x1.69046p-4, -0x1.3f3562p-3 }, { 0x1.cedbep-4, 0x1.e40748p-5, 0x1.4a57ecp-8, 0x1.b239ap-4, -0x1.54448cp-2, -0x1.a811a6p-5, -0x1.85639ap-10, -0x1.6de40ep-4, 0x1.e6ebfcp-7, -0x1.1537c8p-5, -0x1.3d218ep-4, 0x1.4fd5e2p-6, 0x1.a44d9p-3, 0x1.8e4ff8p-2, 0x1.52df2ep-4, -0x1.4996fep-3 }, { -0x1.700cfap-4, 0x1.bc8146p-5, -0x1.568e4ep-3, 0x1.1ac288p-2, -0x1.184c08p-2, -0x1.f4b2b8p-4, -0x1.4de19ep-4, 0x1.39bb8cp-4, -0x1.e1d088p-3, -0x1.6229b4p-3, -0x1.a5b67p-4, 0x1.334eap-5, 0x1.765bep-3, 0x1.cf39fap-2, 0x1.76c566p-4, 0x1.2bc9ccp-6 }, { 0x1.204d48p-3, 0x1.9b2decp-5, -0x1.6927bp-5, -0x1.033b0ep-4, -0x1.0b689ep-4, -0x1.ab6cf4p-3, 0x1.09fb7ap-4, 0x1.2b44a6p-3, -0x1.263c2p-2, -0x1.8b569cp-4, 0x1.bfb2aap-4, 0x1.dbe994p-5, 0x1.09fdb6p-2, 0x1.6d312ap-3, 0x1.fa7d26p-6, -0x1.08e0c2p-5 }, { 0x1.c8e48cp-6, -0x1.b01d52p-3, 0x1.670dcap-5, -0x1.068c5ap-3, -0x1.e1b928p-4, -0x1.4e9154p-3, -0x1.c76068p-5, -0x1.6e3eacp-8, -0x1.bd9d9ap-4, 0x1.9b618ep-5, 0x1.0222cap-3, 0x1.1557eap-4, -0x1.21c268p-3, -0x1.fe0c92p-4, -0x1.d3c96cp-3, -0x1.f0919p-5 }, { 0x1.56c634p-5, -0x1.6ae6fep-3, -0x1.ea023cp-4, -0x1.d75b12p-3, 0x1.130ad4p-5, -0x1.ecd2e8p-4, -0x1.9272c4p-2, 0x1.1c00e4p-4, -0x1.394bf8p-2, -0x1.2a9ca6p-4, -0x1.5cfb8ep-8, -0x1.72c34ep-10, -0x1.9d357p-2, -0x1.a599p-2, -0x1.b9d79ep-3, -0x1.1d48d2p-5 }, { -0x1.3d5224p-3, -0x1.a0db92p-3, -0x1.cdabf8p-4, -0x1.a0b93ep-2, -0x1.779e66p-4, -0x1.4accep-2, -0x1.f524d6p-2, 0x1.97404ep-5, -0x1.ea4cbap-3, -0x1.18c68cp-2, -0x1.5ecaaep-4, 0x1.39b1d4p-5, -0x1.849f9ap-2, -0x1.17e10ep-1, -0x1.b3be4ap-2, 0x1.9cd4bap-5 }, { -0x1.e20d54p-4, -0x1.c1c462p-3, -0x1.e4dee4p-6, -0x1.3c9572p-2, -0x1.af61f6p-4, -0x1.2df53ep-2, -0x1.26299p-1, -0x1.72d554p-7, -0x1.b448fep-5, 0x1.526c24p-4, 0x1.c10d3cp-5, 0x1.0a6778p-6, -0x1.e4e498p-2, -0x1.753e72p-2, -0x1.d14b84p-3, 0x1.420c6ap-6 }, { 0x1.a75b6ap-5, -0x1.45a07cp-4, 0x1.5537fap-6, 0x1.511e14p-2, -0x1.139448p-5, -0x1.985828p-3, -0x1.5c36acp-4, -0x1.c08b3ap-7, -0x1.be2d6ep-3, 0x1.1b1eaep-2, -0x1.a156bap-5, 0x1.602398p-6, -0x1.a242a4p-2, -0x1.65fff6p-6, -0x1.29a336p-3, -0x1.fc59f8p-5 }, { -0x1.f72872p-12, -0x1.952794p-4, -0x1.f94e14p-4, 0x1.ffa7ecp-3, -0x1.17b5a6p-3, -0x1.33f31cp-4, -0x1.e7c98ap-5, -0x1.5cfb74p-4, 0x1.481cb6p-5, 0x1.208d9ep-4, -0x1.110084p-6, 0x1.408926p-6, -0x1.a65804p-9, 0x1.be1b66p-2, 0x1.908de6p-6, -0x1.49098ap-4 }, { 0x1.5a27fp-8, 0x1.6a82dap-6, -0x1.bee9d6p-3, 0x1.a104cep-2, -0x1.39a078p-4, 0x1.912f4p-3, -0x1.6c143ep-3, -0x1.94a3ecp-5, -0x1.41ca9ep-3, -0x1.1b1d42p-5, -0x1.3826ep-4, -0x1.6287dp-8, 0x1.48b386p-2, 0x1.21ac0cp-3, 0x1.111d1cp-2, -0x1.c351dp-4 }, { -0x1.d6dd66p-3, -0x1.ff2c5p-3, -0x1.5799bcp-2, -0x1.4d936p-2, 0x1.8aeacp-4, 0x1.d46c72p-4, -0x1.d486a6p-2, 0x1.3d3b6p-4, -0x1.f8020cp-3, -0x1.a2937p-3, 0x1.d15af8p-6, 0x1.8c9dc4p-6, -0x1.ac3f3ep-3, 0x1.f3aeb4p-5, -0x1.02e6c4p-2, 0x1.a383ccp-6 } }, { { 0x1.30389cp-1, 0x1.49ce54p-2, 0x1.4901ecp-3, 0x1.01ee0cp-1, -0x1.231c68p-2, 0x1.e73e2ep-6, 0x1.2ad38ap-1, 0x1.57b03p-4, 0x1.aba53p-5, 0x1.b6bfe2p-2, -0x1.0a9042p-1, -0x1.ca89eep-5, 0x1.ec4f7ap-2, 0x1.54b09cp-2, 0x1.ab0e3ep-8, -0x1.50de9cp-4 }, { -0x1.a0103ep-2, 0x1.edaa0cp-5, 0x1.91f02ap-3, -0x1.1dc07p-1, -0x1.5eb954p-4, -0x1.7bc5fap-2, -0x1.5eb6a8p-1, 0x1.b3cc6ep-4, -0x1.12dba8p-2, 0x1.8941c8p-6, -0x1.c46eecp-2, 0x1.31e1a4p-6, 0x1.98f5cep-2, -0x1.227f54p-1, -0x1.7c950cp-1, 0x1.cb495cp-8 }, { -0x1.6330c4p-3, 0x1.009dfep-4, -0x1.75cef2p-4, -0x1.94b726p-2, 0x1.2f2e78p-4, -0x1.5a83e2p-1, -0x1.974992p-1, 0x1.bc553cp-4, -0x1.089d5ap-2, 0x1.b85e02p-9, -0x1.8a3956p-3, 0x1.568264p-7, 0x1.a0a6e6p-3, -0x1.0d89c4p-1, -0x1.27dec4p-1, 0x1.0c7adcp-6 }, { -0x1.dd34dap-4, 0x1.517892p-4, 0x1.23fcdp-3, -0x1.f471bcp-2, -0x1.020d78p-6, -0x1.870b6ep-2, -0x1.489e4cp-1, -0x1.7729dp-8, -0x1.361c2cp-2, -0x1.a5d194p-3, -0x1.a76f44p-5, 0x1.a5de08p-9, -0x1.3d5a1p-5, -0x1.0374e4p-1, -0x1.0e93aep-2, 0x1.e4f7e6p-6 }, { 0x1.091df8p-4, 0x1.75999ep-5, -0x1.c9c06ap-6, 0x1.0b111p-5, 0x1.565f1ap-4, -0x1.929e66p-3, -0x1.f8d18cp-2, -0x1.5f21f8p-9, -0x1.82704p-4, -0x1.4ea632p-5, -0x1.13dd44p-3, 0x1.d6debcp-5, 0x1.1bf23cp-5, -0x1.bbaaecp-2, -0x1.5951c6p-2, 0x1.1b5b54p-5 }, { -0x1.9cc522p-4, -0x1.76a506p-6, 0x1.309dfap-3, -0x1.1ee73p-4, 0x1.aa3eaap-13, -0x1.cf0b72p-3, -0x1.a79e34p-2, -0x1.28112ep-5, -0x1.23e394p-3, -0x1.729716p-3, -0x1.b1c1dp-6, -0x1.4de814p-7, -0x1.41b41ap-5, -0x1.63cea4p-2, -0x1.a6d3f8p-2, 0x1.9020dep-6 }, { -0x1.416b7p-3, 0x1.e5ad9ap-5, -0x1.943768p-4, -0x1.f74e38p-4, -0x1.2219e8p-4, -0x1.b5d92ap-6, -0x1.57fep-3, -0x1.8a962ep-5, -0x1.0a188ap-2, -0x1.10712ep-4, -0x1.15f6ecp-3, 0x1.bf6bc6p-6, 0x1.aa59p-4, -0x1.6b718ep-2, -0x1.74bb28p-2, 0x1.74e63cp-6 }, { -0x1.4b03ccp-3, 0x1.927bfep-5, 0x1.fa2182p-3, -0x1.aa9ec4p-3, -0x1.5e527cp-3, -0x1.d86318p-3, -0x1.be1f66p-2, -0x1.650ec6p-6, -0x1.7f15ep-3, 0x1.25cc48p-6, -0x1.4e4166p-4, 0x1.694d12p-8, 0x1.f9cee6p-4, -0x1.793bcep-2, -0x1.2e3212p-2, 0x1.f1f8f8p-5 }, { -0x1.46f75cp-3, 0x1.750dcap-5, -0x1.0eac0ep-4, -0x1.0f211cp-2, -0x1.9c4188p-3, -0x1.701c44p-7, -0x1.5c89cep-2, 0x1.35ab5p-5, -0x1.269d26p-2, -0x1.5f72p-7, -0x1.6b9e6p-2, -0x1.16a9f6p-8, 0x1.01a0cap-3, -0x1.b449aap-2, -0x1.b1899ep-2, 0x1.732668p-6 }, { -0x1.152e04p-2, 0x1.45a91ep-5, -0x1.51f934p-2, -0x1.b85278p-5, 0x1.ea1156p-6, -0x1.843c8ap-3, -0x1.92dd88p-2, 0x1.9d6014p-6, -0x1.29f2f8p-2, -0x1.3fd612p-3, -0x1.3cd504p-2, 0x1.3c3e52p-6, 0x1.1a32p-5, -0x1.eea88ep-3, -0x1.88d062p-1, 0x1.289814p-5 }, { 0x1.c121bap-4, 0x1.1d85a8p-4, -0x1.4ff6c8p-2, -0x1.c66aecp-3, -0x1.31cdbep-3, -0x1.10a104p-1, -0x1.372faap-1, -0x1.9d1a5p-6, -0x1.554012p-2, -0x1.9cff78p-4, -0x1.f5275cp-3, 0x1.d93ed8p-8, 0x1.12f9e4p-4, -0x1.371d4ep-2, -0x1.02fcfap-1, 0x1.fd5c1ap-5 }, { -0x1.13c1f8p-5, 0x1.b4e1e8p-5, -0x1.f267a6p-4, -0x1.77f18ap-2, -0x1.1b8daap-2, -0x1.bd6392p-3, -0x1.acdd26p-2, 0x1.95355cp-6, -0x1.c53ab2p-3, -0x1.c4df2ap-3, -0x1.58415p-2, 0x1.61648p-6, 0x1.dbe81p-4, -0x1.847872p-3, -0x1.c63862p-2, 0x1.1c3434p-7 }, { 0x1.d2f2b2p-8, -0x1.204544p-3, 0x1.4b546p-4, -0x1.0d1ee2p-1, -0x1.40482cp-2, -0x1.9364cep-2, -0x1.1ef6a4p-1, 0x1.9fd3f2p-5, -0x1.2e9358p-3, -0x1.d0915cp-5, -0x1.6c00f6p-2, 0x1.d16dd6p-7, 0x1.d38392p-4, -0x1.865bdap-2, -0x1.82c54p-1, 0x1.4a12c4p-5 }, { -0x1.ac0d36p-3, 0x1.2f173ep-3, 0x1.79ce68p-7, 0x1.2f7714p-3, 0x1.2bd33ap-7, -0x1.08ca48p-1, -0x1.183e7cp-3, 0x1.0667aep-6, -0x1.40ab8ep-6, -0x1.7f8d68p-4, -0x1.f762b4p-4, 0x1.173cc8p-5, 0x1.bf7834p-3, 0x1.90f076p-4, -0x1.ac20cp-4, 0x1.fbc85ap-5 } }, { { -0x1.36813ap-2, -0x1.a219d6p-6, -0x1.5c00bp-3, 0x1.feeb72p-2, 0x1.56409ap-2, -0x1.dac04cp-4, -0x1.bb7386p-2, 0x1.51b56ap-2, 0x1.44d066p-4, 0x1.53a086p-6, 0x1.16ffe2p-8, 0x1.7ed67ep-2, -0x1.68d2d8p-3, -0x1.e6b0f2p-2, -0x1.b65de2p-4, 0x1.3090c4p-2 }, { -0x1.eadab2p-5, 0x1.b4586ep-7, -0x1.61ce26p-5, 0x1.f95942p-6, 0x1.55b164p-3, -0x1.6c9644p-4, -0x1.0347a2p-2, -0x1.2b22e6p-5, 0x1.edf5cep-5, 0x1.b7e2cp-6, 0x1.859e0ep-6, 0x1.1554fap-6, 0x1.622744p-2, -0x1.4721f4p-2, 0x1.3e6f06p-3, 0x1.61d1a6p-4 }, { -0x1.d093b4p-3, 0x1.d6793ap-3, -0x1.3ab578p-7, 0x1.4a0592p-5, 0x1.2a2d3cp-3, -0x1.2e816ap-3, 0x1.342e32p-3, -0x1.192a2ep-4, -0x1.1485cap-5, 0x1.92dec2p-4, -0x1.b0782cp-3, -0x1.f42a32p-3, 0x1.456254p-2, -0x1.b944a4p-5, 0x1.22bf24p-3, -0x1.583f6ap-5 }, { -0x1.41f14ap-3, 0x1.92ea16p-4, 0x1.04003cp-2, 0x1.c343fcp-5, 0x1.827faap-3, 0x1.96ca12p-4, 0x1.3ceb8ap-7, -0x1.ec1f76p-3, 0x1.416d7ep-4, 0x1.5c09bep-4, -0x1.0db536p-1, -0x1.09187p-2, 0x1.18b924p-3, -0x1.f8cf7p-4, -0x1.2bd96ep-4, -0x1.2aa026p-3 }, { -0x1.1b62eap-4, 0x1.3ce214p-3, 0x1.f0f2fap-4, 0x1.ef2e8p-5, -0x1.3bce76p-2, 0x1.551164p-6, 0x1.882cf2p-5, -0x1.05b972p-3, -0x1.4797c2p-6, -0x1.ffb452p-8, -0x1.709564p-2, -0x1.f62bb2p-2, -0x1.8617e8p-5, -0x1.2f807cp-5, -0x1.5d4608p-6, -0x1.bfffap-2 }, { 0x1.1f96e4p-3, 0x1.fef206p-4, 0x1.80cb22p-3, -0x1.76ef6cp-4, -0x1.2b1f4ap-1, -0x1.3cc26p-3, 0x1.855316p-4, -0x1.0dbedcp-3, 0x1.bf123cp-4, 0x1.e51f14p-6, -0x1.879bfap-7, -0x1.449938p-2, -0x1.33686p-3, 0x1.8b2966p-5, -0x1.835ed8p-4, -0x1.248da8p-1 }, { 0x1.b7bd76p-3, 0x1.61686p-4, 0x1.085d9cp-4, -0x1.9cec7cp-4, -0x1.26b504p-2, 0x1.90405ap-4, -0x1.0e82p-5, -0x1.6cb562p-3, -0x1.9d3c8p-6, 0x1.14d408p-3, -0x1.0b8c3ap-3, -0x1.45709p-5, -0x1.2a93eep-2, -0x1.957bf6p-4, -0x1.62684ap-3, -0x1.1fc786p-1 }, { 0x1.65639ep-5, 0x1.0c1ae6p-4, -0x1.9f760ap-6, -0x1.1baa94p-4, -0x1.1add66p-1, -0x1.5fd8c8p-3, -0x1.2bf0a4p-3, 0x1.0145a6p-4, -0x1.d53f58p-5, -0x1.f38ebcp-4, -0x1.03219p-4, 0x1.933bcep-5, -0x1.0c95a8p-3, 0x1.000886p-5, -0x1.854a4ep-2, -0x1.f4d12p-2 }, { 0x1.3963d2p-3, -0x1.2880d8p-4, 0x1.73c7dcp-7, -0x1.afb28p-4, -0x1.8c33dp-3, -0x1.5408e4p-2, -0x1.a7b1p-4, -0x1.091dccp-3, -0x1.f1d5p-6, 0x1.a22f44p-3, 0x1.b257b2p-5, -0x1.eb1e18p-9, -0x1.04a7bap-4, 0x1.a1860cp-5, -0x1.a86be4p-3, -0x1.d5eb9cp-2 }, { -0x1.c26244p-7, -0x1.961e06p-3, 0x1.3ccc34p-5, -0x1.44d764p-3, -0x1.c12daep-2, -0x1.66de1p-2, -0x1.f2086p-4, -0x1.46afd4p-3, -0x1.167ef2p-4, 0x1.c545d4p-5, 0x1.f6b7b8p-6, 0x1.2ea322p-5, -0x1.b11bcep-3, -0x1.9f3556p-5, -0x1.5b56f8p-2, -0x1.0ccd5p-1 }, { 0x1.3df77ep-6, -0x1.3de29p-5, 0x1.295f5ap-6, -0x1.03b9eep-2, -0x1.b4ad54p-2, -0x1.359482p-3, -0x1.560d5ep-2, -0x1.476f3cp-4, 0x1.6cf21p-4, -0x1.086232p-5, -0x1.db6b2p-6, 0x1.15eebap-6, -0x1.6f0c2cp-3, 0x1.9a254cp-4, -0x1.852904p-3, -0x1.5a03aep-2 }, { 0x1.69d9a2p-4, 0x1.5bec86p-7, 0x1.9901d6p-4, -0x1.0a28cap-2, -0x1.b78d06p-2, -0x1.17a1e8p-2, -0x1.fa032ep-6, -0x1.3db932p-2, 0x1.138bf2p-3, 0x1.803424p-4, 0x1.58fb2ap-3, -0x1.102c8p-4, -0x1.770bap-3, 0x1.a3dfd4p-5, -0x1.b766c6p-3, -0x1.8a92ap-2 }, { 0x1.594d86p-3, 0x1.8ec87cp-9, 0x1.45c5fap-5, -0x1.a5e43cp-3, -0x1.ad1f3ap-2, -0x1.1df072p-3, -0x1.e4cecp-5, -0x1.14c00ap-3, 0x1.1e3286p-6, 0x1.7bc308p-3, 0x1.4916fap-5, -0x1.7dea2ep-5, -0x1.c7e556p-4, 0x1.398518p-4, -0x1.42abecp-5, -0x1.14eec8p-2 }, { -0x1.2ebd94p-8, 0x1.10a4aep-3, 0x1.a36504p-4, -0x1.16a6f8p-5, 0x1.3cf136p-6, -0x1.4bc5cap-4, -0x1.7c6234p-4, -0x1.14b26ep-4, 0x1.bc916ap-3, 0x1.c5a6dep-4, -0x1.4ce8fep-5, -0x1.19fd1ap-2, -0x1.eb786ap-3, 0x1.0f53bep-5, 0x1.e92058p-4, 0x1.3d60c6p-4 } }, { { 0x1.f1087p-3, 0x1.a2b948p-2, -0x1.513a18p-4, 0x1.1c9e1p-2, -0x1.2d8224p-2, -0x1.dc9934p-8, 0x1.34d3c4p-2, -0x1.8e28e2p-2, -0x1.d3559p-6, 0x1.5d0234p-2, -0x1.161e1ap-1, -0x1.2a813ep-1, 0x1.3fd932p-2, 0x1.8503fcp-3, -0x1.8560e8p-3, -0x1.2d264ap-2 }, { 0x1.6c6ddcp-5, 0x1.453f4ap-4, 0x1.7d1c0ep-3, 0x1.3e5512p-4, -0x1.b107cap-5, -0x1.03eee4p-3, -0x1.cf1738p-7, -0x1.ef825p-4, -0x1.0cba76p-4, -0x1.685b18p-5, -0x1.bd1edep-2, -0x1.e5e714p-2, 0x1.729276p-2, -0x1.06c7f6p-4, -0x1.265fb4p-2, -0x1.5089acp-2 }, { 0x1.ffd87ap-8, -0x1.09ad6ap-5, 0x1.3393c6p-5, 0x1.0fb6d8p-4, -0x1.3d78ep-6, 0x1.482cecp-3, 0x1.dd6cc6p-5, -0x1.34b16ep-2, 0x1.43a0f2p-3, 0x1.45ce2cp-9, -0x1.948898p-5, -0x1.9868fp-2, 0x1.0525fap-4, -0x1.36447ap-4, -0x1.977402p-4, -0x1.db59ep-6 }, { 0x1.12bf24p-3, -0x1.2edcecp-4, 0x1.30fadcp-5, 0x1.f0abdap-6, 0x1.955402p-3, 0x1.efee92p-3, 0x1.a9a552p-4, -0x1.58f4d6p-4, -0x1.20cf62p-4, -0x1.29ea6p-4, 0x1.af73bap-4, -0x1.085d86p-3, 0x1.5183fap-4, -0x1.83e1p-3, 0x1.1c475cp-6, -0x1.0b1406p-7 }, { 0x1.4c66ap-3, 0x1.9409bap-4, -0x1.05b222p-2, 0x1.845792p-3, 0x1.e52976p-3, 0x1.4b1fb6p-6, 0x1.a113bcp-4, -0x1.0d6c48p-2, -0x1.a94e36p-3, -0x1.a25c9p-4, 0x1.008ebap-3, 0x1.53af18p-4, -0x1.364592p-4, 0x1.d14138p-4, -0x1.38f78p-5, 0x1.bba44ep-4 }, { 0x1.411c48p-4, -0x1.a7e8c4p-7, -0x1.74702cp-2, 0x1.c6dcf8p-4, 0x1.881af6p-3, 0x1.1a795cp-4, 0x1.9e9c36p-5, -0x1.9aeae6p-3, -0x1.89373p-3, -0x1.e9d1a4p-3, 0x1.adb31ep-3, 0x1.9c54e8p-3, 0x1.b163b4p-4, 0x1.0bae7p-4, 0x1.797c12p-5, 0x1.da5048p-7 }, { 0x1.3f9b76p-5, -0x1.7eeff6p-3, -0x1.7dbc66p-6, 0x1.6742b8p-6, 0x1.3ba2d6p-4, 0x1.76f7e2p-3, 0x1.ea5898p-5, -0x1.65deep-2, -0x1.c02f6ap-4, -0x1.cb0ec2p-5, 0x1.7c1274p-3, -0x1.7e929p-8, 0x1.54605ep-4, 0x1.0eeacap-5, 0x1.3f857ap-3, -0x1.f119d2p-4 }, { 0x1.d12ef8p-6, -0x1.a38f3ap-9, -0x1.131a8p-4, 0x1.0e4faap-6, -0x1.cb4324p-5, -0x1.4cf5eep-6, 0x1.acf9d8p-6, -0x1.288feep-3, 0x1.241baap-6, -0x1.022274p-9, 0x1.067734p-3, -0x1.45bdcp-3, -0x1.c95a6ep-6, -0x1.07669cp-9, -0x1.edd07ep-4, -0x1.ee210ep-8 }, { -0x1.3587c4p-4, 0x1.16841cp-3, -0x1.3a4d24p-2, -0x1.65c69ep-7, 0x1.06144cp-3, 0x1.4ec1e6p-6, 0x1.0a4818p-5, -0x1.29907cp-2, -0x1.0462ap-3, -0x1.d3a9fep-5, 0x1.e4843ap-5, -0x1.ff19cep-3, 0x1.2d0e66p-5, -0x1.445926p-4, -0x1.c7e11p-8, 0x1.092d5p-4 }, { 0x1.8181b4p-3, 0x1.b0d114p-5, -0x1.33615ap-3, -0x1.4c9d2ep-7, 0x1.cc4c38p-4, 0x1.aad09p-5, 0x1.87c78cp-4, -0x1.91cd4ep-8, -0x1.3201e6p-4, 0x1.b4c65ap-6, 0x1.037b68p-2, -0x1.2573bep-2, -0x1.64749p-4, 0x1.a5973ep-4, 0x1.2e7016p-6, -0x1.6f2bc4p-6 }, { 0x1.2705ecp-13, 0x1.35318p-5, 0x1.a3e984p-5, 0x1.ebd61ap-6, 0x1.a5b43ap-5, 0x1.ef615ap-5, 0x1.a2b194p-5, 0x1.605ab4p-6, -0x1.d717ep-4, 0x1.a1b01ap-3, -0x1.304acap-3, -0x1.fa316p-2, -0x1.760588p-5, 0x1.04f7f4p-4, -0x1.9b419cp-3, -0x1.658c16p-5 }, { 0x1.80c508p-4, 0x1.3cdccp-5, 0x1.500262p-3, 0x1.08ec62p-3, -0x1.c0d722p-5, 0x1.41ea28p-3, -0x1.ce70b8p-5, 0x1.84426cp-4, -0x1.fc2026p-3, 0x1.3fa232p-2, -0x1.2c35ap-3, -0x1.5f6a68p-2, 0x1.2ccf0cp-5, -0x1.b00a22p-3, 0x1.a01bf6p-6, -0x1.41112p-5 }, { 0x1.3599b8p-4, 0x1.f45222p-3, -0x1.7e880ap-2, 0x1.1434a8p-3, -0x1.68dffep-4, 0x1.0d49d6p-4, 0x1.0086bcp-3, -0x1.b29ff4p-6, -0x1.44f75ap-4, 0x1.03ec1cp-3, -0x1.69e12p-4, -0x1.3443ap-2, 0x1.2886e8p-3, -0x1.17d09ap-3, -0x1.2657p-4, 0x1.6a730ep-3 }, { 0x1.70c72p-4, 0x1.06599ep-2, -0x1.17cb7ap-1, 0x1.21eebep-6, -0x1.a4c34p-7, -0x1.59111ep-6, 0x1.a6c818p-4, 0x1.17b338p-4, -0x1.736fp-3, 0x1.2a609cp-2, -0x1.b47ce6p-2, 0x1.08aca2p-4, 0x1.0a51ccp-4, -0x1.0fd372p-2, -0x1.d8028cp-5, 0x1.aac896p-4 } } };
float thirdBias[16] = { 0x1.275352p0, -0x1.43b478p-3, 0x1.7bc666p-5, -0x1.67dbbp-1, -0x1.7d3a98p-1, 0x1.4c8174p0, -0x1.4a9cdcp-3, 0x1.26bcdcp0, -0x1.8b449p-2, 0x1.6754cep-3, 0x1.40cd8p-1, -0x1.fc4b66p-3, -0x1.b25f14p-2, 0x1.90c9b4p0, -0x1.122834p-4, 0x1.1291d4p-2 };
float secondDense[4][16] = { { -0x1.14b88p-2, 0x1.55118ap-2, -0x1.3eed6p-3, 0x1.b0746ap-3, 0x1.474b08p-2, 0x1.93b27p-5, -0x1.f0c6bp-7, -0x1.5d2904p-3, -0x1.ddbd2ep-3, -0x1.3e4fd4p-2, 0x1.80483ap-4, 0x1.cc6242p-7, -0x1.11f1p-2, -0x1.320dbap-3, -0x1.66967ep-2, 0x1.1bb8ep-2 }, { -0x1.27dc4p-2, -0x1.7ef9bcp-2, -0x1.a075b4p-3, 0x1.dd221cp-3, 0x1.03783p-2, -0x1.fd383p-12, -0x1.365a22p-2, -0x1.7ee744p-3, -0x1.46d818p-2, -0x1.18966ep-2, 0x1.404d22p-4, 0x1.7a0966p-2, -0x1.e07c02p-3, -0x1.d3b7a2p-3, -0x1.318168p-2, 0x1.01b3a8p-2 }, { -0x1.e952c4p-3, -0x1.07d314p-2, -0x1.a924f4p-3, 0x1.86bb24p-3, 0x1.f66bc6p-3, 0x1.5d03dcp-5, 0x1.d8d176p-4, -0x1.36e4ep-3, -0x1.4840c8p-2, -0x1.1a3e9ep-4, 0x1.f1addcp-4, 0x1.6107b6p-2, -0x1.1933a2p-2, -0x1.8a4332p-3, -0x1.04092ep-2, 0x1.11be4ap-2 }, { -0x1.b7cdc4p-3, 0x1.d0a7cap-5, -0x1.819a16p-3, 0x1.abd49cp-3, 0x1.0bb0a8p-2, 0x1.057478p-4, 0x1.d380bp-2, -0x1.539818p-3, -0x1.44dc74p-2, 0x1.249508p-3, 0x1.97b264p-4, 0x1.a82d5ap-2, -0x1.0b51eap-2, -0x1.9068b8p-4, -0x1.580462p-2, 0x1.3c2a7cp-2 } };
float fourthBias[4] = { -0x1.6d3386p0, 0x1.170fd2p0, -0x1.350758p0, -0x1.7a9298p-3 };
static  char aesl_internal__OC_str1[9] = "test.txt";
static  char aesl_internal__OC_str6[7] = "%.30f\n";
static  char aesl_internal_str[22] = "File can't be opened ";
static  char aesl_internal__OC_str9[7] = "-,-,-\n";
static  char aesl_internal_str1[20] = "Error opening file!";
static  char aesl_internal__OC_str8[8] = " -,-,-\n";
static  char aesl_internal__OC_str10[2] = ",";
static  char aesl_internal_str2[6] = "\nOut:";
static  char aesl_internal_str3[4] = "\n\n\n";
static  char aesl_internal__OC_str7[2] = "\n";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

l_struct_OC__iobuf *openFile( char *llvm_cbe_name,  char *llvm_cbe_mode) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @openFile\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call %%struct._iobuf* @fopen(i8* %%name, i8* %%mode) nounwind, !dbg !9 for 0x%I64xth hint within @openFile  --> \n", ++aesl_llvm_cbe_5_count);
  llvm_cbe_tmp__1 = (l_struct_OC__iobuf *) /*tail*/ aesl_fopen(( char *)llvm_cbe_name, ( char *)llvm_cbe_mode);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
  if (((llvm_cbe_tmp__1) == (((l_struct_OC__iobuf *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__2;
  } else {
    goto llvm_cbe_tmp__3;
  }

llvm_cbe_tmp__2:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = tail call i32 @puts(i8* getelementptr inbounds ([22 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !9 for 0x%I64xth hint within @openFile  --> \n", ++aesl_llvm_cbe_puts_count);
   /*tail*/ puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 22
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  goto llvm_cbe_tmp__3;

llvm_cbe_tmp__3:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @openFile}\n");
  return llvm_cbe_tmp__1;
}


void closeFile(l_struct_OC__iobuf *llvm_cbe_file) {
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @closeFile\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i32 @fclose(%%struct._iobuf* %%file) nounwind, !dbg !8 for 0x%I64xth hint within @closeFile  --> \n", ++aesl_llvm_cbe_15_count);
   /*tail*/ fclose((l_struct_OC__iobuf *)llvm_cbe_file);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @closeFile}\n");
  return;
}


void readFile(l_struct_OC__iobuf *llvm_cbe_file) {
  static  unsigned long long aesl_llvm_cbe_buff_count = 0;
   char llvm_cbe_buff[500];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_dt_count = 0;
  float llvm_cbe_dt[128][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_data_count = 0;
  float llvm_cbe_data[128][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_conv1_count = 0;
  float llvm_cbe_conv1[128][3][8];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_max1_count = 0;
  float llvm_cbe_max1[42][1][8];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_conv2_count = 0;
  float llvm_cbe_conv2[42][1][16];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_max2_count = 0;
  float llvm_cbe_max2[14][1][16];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_den1_count = 0;
  float llvm_cbe_den1[1][16];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_den2_count = 0;
  float llvm_cbe_den2[1][4];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_sMax_count = 0;
  float llvm_cbe_sMax[1][4];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
   char *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
   char *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  float *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  float *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  float *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  float *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  float *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  float *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  float *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  float *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge26_count = 0;
  unsigned int llvm_cbe_storemerge26;
  unsigned int llvm_cbe_storemerge26__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  float *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  float *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  float *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond28_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1922_count = 0;
  bool llvm_cbe_storemerge1922;
  bool llvm_cbe_storemerge1922__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge191021_count = 0;
  bool llvm_cbe_storemerge191021;
  bool llvm_cbe_storemerge191021__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned int llvm_cbe_tmp__21;
  unsigned int llvm_cbe_tmp__21__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1910_2e_not_count = 0;
  bool llvm_cbe_storemerge1910_2e_not;
  static  unsigned long long aesl_llvm_cbe_brmerge_count = 0;
  bool llvm_cbe_brmerge;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge217_count = 0;
  unsigned int llvm_cbe_storemerge217;
  unsigned int llvm_cbe_storemerge217__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  float *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  float llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned long long llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  float *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  float *llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  float llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  float *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  float *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  float llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  float *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond27_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge315_count = 0;
  unsigned int llvm_cbe_storemerge315;
  unsigned int llvm_cbe_storemerge315__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  unsigned int llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  float *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  float *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  float *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts11_count = 0;
  unsigned int llvm_cbe_puts11;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts12_count = 0;
  unsigned int llvm_cbe_puts12;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  float llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  double llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  float *llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  float llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  double llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  float *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  float llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  double llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  unsigned int llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  float *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  float llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  double llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_count = 0;
  unsigned int llvm_cbe_fputc;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
   char *llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
   char *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  unsigned int llvm_cbe_tmp__59;
  unsigned int llvm_cbe_tmp__59__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  unsigned int llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  unsigned int llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1922_2e_not_count = 0;
  bool llvm_cbe_storemerge1922_2e_not;
  static  unsigned long long aesl_llvm_cbe_brmerge29_count = 0;
  bool llvm_cbe_brmerge29;
  static  unsigned long long aesl_llvm_cbe_storemerge1922_2e_mux_count = 0;
  bool llvm_cbe_storemerge1922_2e_mux;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
   char *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_be_count = 0;
  unsigned int llvm_cbe__2e_be;
  unsigned int llvm_cbe__2e_be__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1910_2e_be_count = 0;
  bool llvm_cbe_storemerge1910_2e_be;
  bool llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge19_2e_be_count = 0;
  bool llvm_cbe_storemerge19_2e_be;
  bool llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
   char *llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  float llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
   char *llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  float llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
   char *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  float llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  unsigned long long llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  float *llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  float *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  float *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  unsigned int llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_not_2e__count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @readFile\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call %%struct._iobuf* @fopen(i8* getelementptr inbounds ([9 x i8]* @aesl_internal_.str1, i64 0, i64 0), i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str2, i64 0, i64 0)) nounwind, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__5 = (l_struct_OC__iobuf *)aesl_fopen(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
])), ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__5);
}
  if (((llvm_cbe_tmp__5) == (((l_struct_OC__iobuf *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__76;
  } else {
    llvm_cbe_storemerge26__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader25;
  }

llvm_cbe_tmp__76:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([20 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 20
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @exit(i32 1) noreturn nounwind, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_52_count);
  exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe__2e_preheader19:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [500 x i8]* %%buff, i64 0, i64 0, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__6 = ( char *)(&llvm_cbe_buff[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 500
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @fgets(i8* %%4, i32 500, %%struct._iobuf* %%file) nounwind, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__7 = ( char *)( char *)fgets(( char *)llvm_cbe_tmp__6, 500u, (l_struct_OC__iobuf *)llvm_cbe_file);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",500u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__7);
}
  if (((llvm_cbe_tmp__7) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe__2e__crit_edge24;
  } else {
    goto llvm_cbe__2e_lr_2e_ph23;
  }

llvm_cbe__2e_lr_2e_ph23:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__8 = (float *)(&llvm_cbe_data[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = bitcast [128 x [3 x [8 x float]]]* %%conv1 to float*, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__9 = (float *)((float *)(&llvm_cbe_conv1));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = bitcast [42 x [1 x [8 x float]]]* %%max1 to float*, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__10 = (float *)((float *)(&llvm_cbe_max1));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = bitcast [42 x [1 x [16 x float]]]* %%conv2 to float*, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__11 = (float *)((float *)(&llvm_cbe_conv2));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = bitcast [14 x [1 x [16 x float]]]* %%max2 to float*, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__12 = (float *)((float *)(&llvm_cbe_max2));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [1 x [16 x float]]* %%den1, i64 0, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__13 = (float *)(&llvm_cbe_den1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [1 x [4 x float]]* %%den2, i64 0, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__14 = (float *)(&llvm_cbe_den2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [1 x [4 x float]]* %%sMax, i64 0, i64 0, i64 0, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__15 = (float *)(&llvm_cbe_sMax[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1922__PHI_TEMPORARY = (bool )0;   /* for PHI node */
  llvm_cbe_storemerge191021__PHI_TEMPORARY = (bool )0;   /* for PHI node */
  llvm_cbe_tmp__21__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__77;

  do {     /* Syntactic loop '.preheader25' to make GCC happy */
llvm_cbe__2e_preheader25:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge26 = phi i32 [ %%19, %%.preheader25 ], [ 0, %%0  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge26_count);
  llvm_cbe_storemerge26 = (unsigned int )llvm_cbe_storemerge26__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge26 = 0x%X",llvm_cbe_storemerge26);
printf("\n = 0x%X",llvm_cbe_tmp__20);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i32 %%storemerge26 to i64, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__16 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge26);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%15, i64 0, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__17 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__16))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__16));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__16) < 128 && "Write access out of array 'dt' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'dt' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%16, align 4, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_70_count);
  *llvm_cbe_tmp__17 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%15, i64 1, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__18 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__16))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__16));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__16) < 128 && "Write access out of array 'dt' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'dt' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%17, align 4, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_72_count);
  *llvm_cbe_tmp__18 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%15, i64 2, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__19 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__16))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__16));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__16) < 128 && "Write access out of array 'dt' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'dt' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%18, align 4, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_74_count);
  *llvm_cbe_tmp__19 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add nsw i32 %%storemerge26, 1, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__20 = (unsigned int )((unsigned int )(llvm_cbe_storemerge26&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__20&4294967295ull)));
  if (((llvm_cbe_tmp__20&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe__2e_preheader19;
  } else {
    llvm_cbe_storemerge26__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__20;   /* for PHI node */
    goto llvm_cbe__2e_preheader25;
  }

  } while (1); /* end of syntactic loop '.preheader25' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__77:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1922 = phi i1 [ false, %%.lr.ph23 ], [ %%storemerge19.be, %%.backedge  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge1922_count);
  llvm_cbe_storemerge1922 = (bool )((llvm_cbe_storemerge1922__PHI_TEMPORARY)&1);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1922 = 0x%X",llvm_cbe_storemerge1922);
printf("\n = 0x%X",0);
printf("\nstoremerge19.be = 0x%X",llvm_cbe_storemerge19_2e_be);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge191021 = phi i1 [ false, %%.lr.ph23 ], [ %%storemerge1910.be, %%.backedge  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge191021_count);
  llvm_cbe_storemerge191021 = (bool )((llvm_cbe_storemerge191021__PHI_TEMPORARY)&1);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge191021 = 0x%X",llvm_cbe_storemerge191021);
printf("\n = 0x%X",0);
printf("\nstoremerge1910.be = 0x%X",llvm_cbe_storemerge1910_2e_be);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = phi i32 [ 0, %%.lr.ph23 ], [ %%.be, %%.backedge  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__21 = (unsigned int )llvm_cbe_tmp__21__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__21);
printf("\n = 0x%X",0u);
printf("\n.be = 0x%X",llvm_cbe__2e_be);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1910.not = xor i1 %%storemerge191021, true, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge1910_2e_not_count);
  llvm_cbe_storemerge1910_2e_not = (bool )((llvm_cbe_storemerge191021 ^ 1)&1);
if (AESL_DEBUG_TRACE)
printf("\nstoremerge1910.not = 0x%X\n", llvm_cbe_storemerge1910_2e_not);
if (AESL_DEBUG_TRACE)
printf("\n  %%brmerge = or i1 %%storemerge1922, %%storemerge1910.not, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_brmerge_count);
  llvm_cbe_brmerge = (bool )((llvm_cbe_storemerge1922 | llvm_cbe_storemerge1910_2e_not)&1);
if (AESL_DEBUG_TRACE)
printf("\nbrmerge = 0x%X\n", llvm_cbe_brmerge);
  if (llvm_cbe_brmerge) {
    llvm_cbe_tmp__59__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__21;   /* for PHI node */
    goto llvm_cbe_tmp__78;
  } else {
    goto llvm_cbe__2e_preheader16;
  }

llvm_cbe__2e_backedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.be = phi i32 [ %%64, %%83 ], [ %%64, %%79 ], [ %%64, %%74 ], [ %%64, %%70 ], [ %%64, %%71 ], [ %%93, %%87  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe__2e_be_count);
  llvm_cbe__2e_be = (unsigned int )llvm_cbe__2e_be__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.be = 0x%X",llvm_cbe__2e_be);
printf("\n = 0x%X",llvm_cbe_tmp__59);
printf("\n = 0x%X",llvm_cbe_tmp__59);
printf("\n = 0x%X",llvm_cbe_tmp__59);
printf("\n = 0x%X",llvm_cbe_tmp__59);
printf("\n = 0x%X",llvm_cbe_tmp__59);
printf("\n = 0x%X",llvm_cbe_tmp__74);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1910.be = phi i1 [ true, %%83 ], [ true, %%79 ], [ true, %%74 ], [ %%storemerge1922, %%70 ], [ %%storemerge1922.mux, %%71 ], [ true, %%87  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge1910_2e_be_count);
  llvm_cbe_storemerge1910_2e_be = (bool )((llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY)&1);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1910.be = 0x%X",llvm_cbe_storemerge1910_2e_be);
printf("\n = 0x%X",1);
printf("\n = 0x%X",1);
printf("\n = 0x%X",1);
printf("\nstoremerge1922 = 0x%X",llvm_cbe_storemerge1922);
printf("\nstoremerge1922.mux = 0x%X",llvm_cbe_storemerge1922_2e_mux);
printf("\n = 0x%X",1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge19.be = phi i1 [ false, %%83 ], [ false, %%79 ], [ false, %%74 ], [ true, %%70 ], [ false, %%71 ], [ %%not., %%87  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge19_2e_be_count);
  llvm_cbe_storemerge19_2e_be = (bool )((llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY)&1);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge19.be = 0x%X",llvm_cbe_storemerge19_2e_be);
printf("\n = 0x%X",0);
printf("\n = 0x%X",0);
printf("\n = 0x%X",0);
printf("\n = 0x%X",1);
printf("\n = 0x%X",0);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = call i8* @fgets(i8* %%4, i32 500, %%struct._iobuf* %%file) nounwind, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_528_count);
  llvm_cbe_tmp__64 = ( char *)( char *)fgets(( char *)llvm_cbe_tmp__6, 500u, (l_struct_OC__iobuf *)llvm_cbe_file);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",500u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__64);
}
  if (((llvm_cbe_tmp__64) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe__2e__crit_edge24;
  } else {
    llvm_cbe_storemerge1922__PHI_TEMPORARY = (bool )llvm_cbe_storemerge19_2e_be;   /* for PHI node */
    llvm_cbe_storemerge191021__PHI_TEMPORARY = (bool )llvm_cbe_storemerge1910_2e_be;   /* for PHI node */
    llvm_cbe_tmp__21__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_be;   /* for PHI node */
    goto llvm_cbe_tmp__77;
  }

llvm_cbe_tmp__79:
  llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__59;   /* for PHI node */
  llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY = (bool )llvm_cbe_storemerge1922;   /* for PHI node */
  llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY = (bool )1;   /* for PHI node */
  goto llvm_cbe__2e_backedge;

llvm_cbe_tmp__78:
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = phi i32 [ %%21, %%20 ], [ 0, %%.loopexit  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_497_count);
  llvm_cbe_tmp__59 = (unsigned int )llvm_cbe_tmp__59__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__59);
printf("\n = 0x%X",llvm_cbe_tmp__21);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = call i32 @strcmp(i8* %%4, i8* getelementptr inbounds ([8 x i8]* @aesl_internal_.str8, i64 0, i64 0)) nounwind, !dbg !20 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_498_count);
  llvm_cbe_tmp__60 = (unsigned int )strcmp(( char *)llvm_cbe_tmp__6, ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__60);
}
  if (((llvm_cbe_tmp__60&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__79;
  } else {
    goto llvm_cbe_tmp__80;
  }

llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  call void @convolution1(i32 128, i32 3, float* %%7, i32 4, i32 3, i32 8, float* getelementptr inbounds ([8 x [4 x [3 x float]]]* @firstKernel, i64 0, i64 0, i64 0, i64 0), float* getelementptr inbounds ([8 x float]* @firstBias, i64 0, i64 0), float* %%8) nounwind, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_227_count);
  convolution1(128u, 3u, (float *)llvm_cbe_tmp__8, 4u, 3u, 8u, (float *)((&firstKernel[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (float *)((&firstBias[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])), (float *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",128u);
printf("\nArgument  = 0x%X",3u);
printf("\nArgument  = 0x%X",4u);
printf("\nArgument  = 0x%X",3u);
printf("\nArgument  = 0x%X",8u);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @printData3D(i32 128, i32 3, i32 8, float* %%8) nounwind, !dbg !19 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_228_count);
  printData3D(128u, 3u, 8u, (float *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",128u);
printf("\nArgument  = 0x%X",3u);
printf("\nArgument  = 0x%X",8u);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @maxPool(i32 128, i32 3, i32 8, float* %%8, i32 42, i32 1, float* %%9, i32 3, i32 3) nounwind, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_229_count);
  maxPool(128u, 3u, 8u, (float *)llvm_cbe_tmp__9, 42u, 1u, (float *)llvm_cbe_tmp__10, 3u, 3u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",128u);
printf("\nArgument  = 0x%X",3u);
printf("\nArgument  = 0x%X",8u);
printf("\nArgument  = 0x%X",42u);
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",3u);
printf("\nArgument  = 0x%X",3u);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @convolution2(i32 42, i32 1, i32 8, float* %%9, i32 4, i32 8, i32 16, float* getelementptr inbounds ([16 x [4 x [8 x float]]]* @secondKernel, i64 0, i64 0, i64 0, i64 0), float* getelementptr inbounds ([16 x float]* @secondBias, i64 0, i64 0), float* %%10) nounwind, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_230_count);
  convolution2(42u, 1u, 8u, (float *)llvm_cbe_tmp__10, 4u, 8u, 16u, (float *)((&secondKernel[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])), (float *)((&secondBias[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
])), (float *)llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",42u);
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",8u);
printf("\nArgument  = 0x%X",4u);
printf("\nArgument  = 0x%X",8u);
printf("\nArgument  = 0x%X",16u);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @maxPool(i32 42, i32 1, i32 16, float* %%10, i32 14, i32 1, float* %%11, i32 3, i32 1) nounwind, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_231_count);
  maxPool(42u, 1u, 16u, (float *)llvm_cbe_tmp__11, 14u, 1u, (float *)llvm_cbe_tmp__12, 3u, 1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",42u);
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",16u);
printf("\nArgument  = 0x%X",14u);
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",3u);
printf("\nArgument  = 0x%X",1u);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @dense1(i32 14, i32 1, i32 16, float* %%11, i32 14, i32 16, i32 16, float* getelementptr inbounds ([16 x [14 x [16 x float]]]* @firstDense, i64 0, i64 0, i64 0, i64 0), float* getelementptr inbounds ([16 x float]* @thirdBias, i64 0, i64 0), i32 16, float* %%12) nounwind, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_232_count);
  dense1(14u, 1u, 16u, (float *)llvm_cbe_tmp__12, 14u, 16u, 16u, (float *)((&firstDense[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 14
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
])), (float *)((&thirdBias[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
])), 16u, (float *)llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",14u);
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",16u);
printf("\nArgument  = 0x%X",14u);
printf("\nArgument  = 0x%X",16u);
printf("\nArgument  = 0x%X",16u);
printf("\nArgument  = 0x%X",16u);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @dense2(i32 16, float* %%12, i32 16, i32 4, float* getelementptr inbounds ([4 x [16 x float]]* @secondDense, i64 0, i64 0, i64 0), float* getelementptr inbounds ([4 x float]* @fourthBias, i64 0, i64 0), i32 4, float* %%13) nounwind, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_233_count);
  dense2(16u, (float *)llvm_cbe_tmp__13, 16u, 4u, (float *)((&secondDense[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
])), (float *)((&fourthBias[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), 4u, (float *)llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",16u);
printf("\nArgument  = 0x%X",16u);
printf("\nArgument  = 0x%X",4u);
printf("\nArgument  = 0x%X",4u);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @softmax(i32 4, float* %%13, float* %%14) nounwind, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_234_count);
  softmax(4u, (float *)llvm_cbe_tmp__14, (float *)llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",4u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts11 = call i32 @puts(i8* getelementptr inbounds ([6 x i8]* @aesl_internal_str2, i64 0, i64 0)), !dbg !19 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_puts11_count);
  puts(( char *)((&aesl_internal_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts11 = 0x%X",llvm_cbe_puts11);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @printData2D(i32 1, i32 4, float* %%14) nounwind, !dbg !19 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_235_count);
  printData2D(1u, 4u, (float *)llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",4u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts12 = call i32 @puts(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_str3, i64 0, i64 0)), !dbg !20 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_puts12_count);
  puts(( char *)((&aesl_internal_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts12 = 0x%X",llvm_cbe_puts12);
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 1)) fprintf(stderr, "%s:%d: warning: Read access out of array 'sMax' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )0ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'sMax' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load float* %%14, align 16, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__42 = (float )*llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__42, *(int*)(&llvm_cbe_tmp__42));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = fpext float %%46 to double, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_264_count);
  llvm_cbe_tmp__43 = (double )((double )llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__43, *(long long*)(&llvm_cbe_tmp__43));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str6, i64 0, i64 0), double %%47) nounwind, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_265_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__5, ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__43, *(long long*)(&llvm_cbe_tmp__43));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__44);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds [1 x [4 x float]]* %%sMax, i64 0, i64 0, i64 1, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_293_count);
  llvm_cbe_tmp__45 = (float *)(&llvm_cbe_sMax[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 1)) fprintf(stderr, "%s:%d: warning: Read access out of array 'sMax' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )1ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'sMax' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load float* %%49, align 4, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_294_count);
  llvm_cbe_tmp__46 = (float )*llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__46, *(int*)(&llvm_cbe_tmp__46));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = fpext float %%50 to double, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_295_count);
  llvm_cbe_tmp__47 = (double )((double )llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__47, *(long long*)(&llvm_cbe_tmp__47));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str6, i64 0, i64 0), double %%51) nounwind, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_296_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__5, ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__47, *(long long*)(&llvm_cbe_tmp__47));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__48);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds [1 x [4 x float]]* %%sMax, i64 0, i64 0, i64 2, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__49 = (float *)(&llvm_cbe_sMax[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 1)) fprintf(stderr, "%s:%d: warning: Read access out of array 'sMax' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )2ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'sMax' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load float* %%53, align 8, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_325_count);
  llvm_cbe_tmp__50 = (float )*llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__50, *(int*)(&llvm_cbe_tmp__50));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = fpext float %%54 to double, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__51 = (double )((double )llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__51, *(long long*)(&llvm_cbe_tmp__51));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str6, i64 0, i64 0), double %%55) nounwind, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_327_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__5, ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__51, *(long long*)(&llvm_cbe_tmp__51));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__52);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds [1 x [4 x float]]* %%sMax, i64 0, i64 0, i64 3, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_355_count);
  llvm_cbe_tmp__53 = (float *)(&llvm_cbe_sMax[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 1)) fprintf(stderr, "%s:%d: warning: Read access out of array 'sMax' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )3ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'sMax' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = load float* %%57, align 4, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_356_count);
  llvm_cbe_tmp__54 = (float )*llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__54, *(int*)(&llvm_cbe_tmp__54));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = fpext float %%58 to double, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__55 = (double )((double )llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__55, *(long long*)(&llvm_cbe_tmp__55));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str6, i64 0, i64 0), double %%59) nounwind, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_358_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__5, ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__55, *(long long*)(&llvm_cbe_tmp__55));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__56);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc = call i32 @fputc(i32 10, %%struct._iobuf* %%1), !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_fputc_count);
  fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc = 0x%X",llvm_cbe_fputc);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = bitcast [128 x [3 x float]]* %%dt to i8 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_494_count);
  llvm_cbe_tmp__57 = ( char *)(( char *)(&llvm_cbe_dt));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = call i8* @memset(i8* %%61, i32 0, i64 36 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_495_count);
  ( char *)memset(( char *)llvm_cbe_tmp__57, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__58);
}
  llvm_cbe_tmp__59__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__78;

llvm_cbe__2e_preheader:
  if ((((signed int )llvm_cbe_tmp__21) < ((signed int )128u))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__81:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge217 = phi i32 [ 0, %%.lr.ph18 ], [ %%38, %%25  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge217_count);
  llvm_cbe_storemerge217 = (unsigned int )llvm_cbe_storemerge217__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge217 = 0x%X",llvm_cbe_storemerge217);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__35);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = sext i32 %%storemerge217 to i64, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__23 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge217);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%26, i64 0, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__24 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__23))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__23));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__23) < 128)) fprintf(stderr, "%s:%d: warning: Read access out of array 'dt' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'dt' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load float* %%27, align 4, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__25 = (float )*llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__25, *(int*)(&llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i32 %%23, %%storemerge217, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__26 = (unsigned int )((unsigned int )(llvm_cbe_tmp__22&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge217&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__26&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = sext i32 %%29 to i64, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__27 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 %%30, i64 0, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__28 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__27))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__27));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__27) < 128 && "Write access out of array 'data' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'data' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%28, float* %%31, align 4, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_145_count);
  *llvm_cbe_tmp__28 = llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%26, i64 1, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__29 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__23))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__23));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__23) < 128)) fprintf(stderr, "%s:%d: warning: Read access out of array 'dt' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'dt' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load float* %%32, align 4, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__30 = (float )*llvm_cbe_tmp__29;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__30, *(int*)(&llvm_cbe_tmp__30));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 %%30, i64 1, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__31 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__27))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__27));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__27) < 128 && "Write access out of array 'data' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'data' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%33, float* %%34, align 4, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_149_count);
  *llvm_cbe_tmp__31 = llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%26, i64 2, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__32 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__23))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__23));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__23) < 128)) fprintf(stderr, "%s:%d: warning: Read access out of array 'dt' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'dt' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load float* %%35, align 4, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__33 = (float )*llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__33, *(int*)(&llvm_cbe_tmp__33));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 %%30, i64 2, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__34 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__27))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__27));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__27) < 128 && "Write access out of array 'data' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'data' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%36, float* %%37, align 4, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_153_count);
  *llvm_cbe_tmp__34 = llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add nsw i32 %%storemerge217, 1, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__35 = (unsigned int )((unsigned int )(llvm_cbe_storemerge217&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__35&4294967295ull)));
  if (((llvm_cbe_tmp__35&4294967295U) == (llvm_cbe_tmp__21&4294967295U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge217__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__35;   /* for PHI node */
    goto llvm_cbe_tmp__81;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph18:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sub i32 128, %%21, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(128u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__21&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__22&4294967295ull)));
  llvm_cbe_storemerge217__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__81;

llvm_cbe__2e_preheader16:
  if ((((signed int )llvm_cbe_tmp__21) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph18;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__82:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge315 = phi i32 [ %%21, %%.lr.ph ], [ %%45, %%39  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge315_count);
  llvm_cbe_storemerge315 = (unsigned int )llvm_cbe_storemerge315__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge315 = 0x%X",llvm_cbe_storemerge315);
printf("\n = 0x%X",llvm_cbe_tmp__21);
printf("\n = 0x%X",llvm_cbe_tmp__41);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = sub nsw i32 %%storemerge315, %%21, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__36 = (unsigned int )((unsigned int )(llvm_cbe_storemerge315&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__21&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__36&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = sext i32 %%40 to i64, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__37 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 %%41, i64 0, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__38 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__37))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__37));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__37) < 128 && "Write access out of array 'data' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'data' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%42, align 4, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_186_count);
  *llvm_cbe_tmp__38 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 %%41, i64 1, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__39 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__37))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__37));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__37) < 128 && "Write access out of array 'data' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'data' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%43, align 4, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_188_count);
  *llvm_cbe_tmp__39 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 %%41, i64 2, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__40 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__37))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__37));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__37) < 128 && "Write access out of array 'data' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'data' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%44, align 4, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_190_count);
  *llvm_cbe_tmp__40 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add nsw i32 %%storemerge315, 1, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__41 = (unsigned int )((unsigned int )(llvm_cbe_storemerge315&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__41&4294967295ull)));
  if (((llvm_cbe_tmp__41&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge315__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__41;   /* for PHI node */
    goto llvm_cbe_tmp__82;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
  llvm_cbe_storemerge315__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__21;   /* for PHI node */
  goto llvm_cbe_tmp__82;

llvm_cbe_tmp__80:
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = call i32 @strcmp(i8* %%4, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str9, i64 0, i64 0)) nounwind, !dbg !20 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_501_count);
  llvm_cbe_tmp__61 = (unsigned int )strcmp(( char *)llvm_cbe_tmp__6, ( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__61);
}
  if (((llvm_cbe_tmp__61&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__79;
  } else {
    goto llvm_cbe_tmp__83;
  }

llvm_cbe_tmp__83:
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = call i32 @strcmp(i8* %%4, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str7, i64 0, i64 0)) nounwind, !dbg !20 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_511_count);
  llvm_cbe_tmp__62 = (unsigned int )strcmp(( char *)llvm_cbe_tmp__6, ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1922.not = xor i1 %%storemerge1922, true, !dbg !20 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge1922_2e_not_count);
  llvm_cbe_storemerge1922_2e_not = (bool )((llvm_cbe_storemerge1922 ^ 1)&1);
if (AESL_DEBUG_TRACE)
printf("\nstoremerge1922.not = 0x%X\n", llvm_cbe_storemerge1922_2e_not);
if (AESL_DEBUG_TRACE)
printf("\n  %%brmerge29 = or i1 %%73, %%storemerge1922.not, !dbg !20 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_brmerge29_count);
  llvm_cbe_brmerge29 = (bool )((((llvm_cbe_tmp__62&4294967295U) == (0u&4294967295U)) | llvm_cbe_storemerge1922_2e_not)&1);
if (AESL_DEBUG_TRACE)
printf("\nbrmerge29 = 0x%X\n", llvm_cbe_brmerge29);
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1922.mux = and i1 %%73, %%storemerge1922, !dbg !20 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge1922_2e_mux_count);
  llvm_cbe_storemerge1922_2e_mux = (bool )((((llvm_cbe_tmp__62&4294967295U) == (0u&4294967295U)) & llvm_cbe_storemerge1922)&1);
if (AESL_DEBUG_TRACE)
printf("\nstoremerge1922.mux = 0x%X\n", llvm_cbe_storemerge1922_2e_mux);
  if (llvm_cbe_brmerge29) {
    llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__59;   /* for PHI node */
    llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY = (bool )llvm_cbe_storemerge1922_2e_mux;   /* for PHI node */
    llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY = (bool )0;   /* for PHI node */
    goto llvm_cbe__2e_backedge;
  } else {
    goto llvm_cbe_tmp__84;
  }

llvm_cbe_tmp__84:
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = call i8* @strtok(i8* %%4, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str10, i64 0, i64 0)) nounwind, !dbg !20 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_518_count);
  llvm_cbe_tmp__63 = ( char *)( char *)strtok(( char *)llvm_cbe_tmp__6, ( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__63);
}
  if (((llvm_cbe_tmp__63) == ((( char *)/*NULL*/0)))) {
    llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__59;   /* for PHI node */
    llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY = (bool )1;   /* for PHI node */
    llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY = (bool )0;   /* for PHI node */
    goto llvm_cbe__2e_backedge;
  } else {
    goto llvm_cbe_tmp__85;
  }

llvm_cbe_tmp__85:
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = call float @strtof(i8* nocapture %%75, i8** null) nounwind, !dbg !21 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_531_count);
  llvm_cbe_tmp__65 = (float )strtof(( char *)llvm_cbe_tmp__63, ( char **)(( char **)/*NULL*/0));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__65);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = call i8* @strtok(i8* null, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str10, i64 0, i64 0)) nounwind, !dbg !21 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_534_count);
  llvm_cbe_tmp__66 = ( char *)( char *)strtok(( char *)(( char *)/*NULL*/0), ( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__66);
}
  if (((llvm_cbe_tmp__66) == ((( char *)/*NULL*/0)))) {
    llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__59;   /* for PHI node */
    llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY = (bool )1;   /* for PHI node */
    llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY = (bool )0;   /* for PHI node */
    goto llvm_cbe__2e_backedge;
  } else {
    goto llvm_cbe_tmp__86;
  }

llvm_cbe_tmp__86:
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = call float @strtof(i8* nocapture %%81, i8** null) nounwind, !dbg !21 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__67 = (float )strtof(( char *)llvm_cbe_tmp__66, ( char **)(( char **)/*NULL*/0));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__67);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = call i8* @strtok(i8* null, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str10, i64 0, i64 0)) nounwind, !dbg !22 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_547_count);
  llvm_cbe_tmp__68 = ( char *)( char *)strtok(( char *)(( char *)/*NULL*/0), ( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__68);
}
  if (((llvm_cbe_tmp__68) == ((( char *)/*NULL*/0)))) {
    llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__59;   /* for PHI node */
    llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY = (bool )1;   /* for PHI node */
    llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY = (bool )0;   /* for PHI node */
    goto llvm_cbe__2e_backedge;
  } else {
    goto llvm_cbe_tmp__87;
  }

llvm_cbe_tmp__87:
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = call float @strtof(i8* nocapture %%85, i8** null) nounwind, !dbg !21 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_557_count);
  llvm_cbe_tmp__69 = (float )strtof(( char *)llvm_cbe_tmp__68, ( char **)(( char **)/*NULL*/0));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__69);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = sext i32 %%64 to i64, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_560_count);
  llvm_cbe_tmp__70 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%89, i64 0, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_561_count);
  llvm_cbe_tmp__71 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__70))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__70));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__70) < 128 && "Write access out of array 'dt' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'dt' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%80, float* %%90, align 4, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_562_count);
  *llvm_cbe_tmp__71 = llvm_cbe_tmp__65;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%89, i64 1, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_563_count);
  llvm_cbe_tmp__72 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__70))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__70));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__70) < 128 && "Write access out of array 'dt' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'dt' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%84, float* %%91, align 4, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_564_count);
  *llvm_cbe_tmp__72 = llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%89, i64 2, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_565_count);
  llvm_cbe_tmp__73 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__70))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__70));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__70) < 128 && "Write access out of array 'dt' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'dt' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%88, float* %%92, align 4, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_566_count);
  *llvm_cbe_tmp__73 = llvm_cbe_tmp__69;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = add nsw i32 %%64, 1, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_567_count);
  llvm_cbe_tmp__74 = (unsigned int )((unsigned int )(llvm_cbe_tmp__59&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__74&4294967295ull)));
  llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__74;   /* for PHI node */
  llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY = (bool )1;   /* for PHI node */
  llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY = (bool )((llvm_cbe_tmp__74&4294967295U) != (128u&4294967295U));   /* for PHI node */
  goto llvm_cbe__2e_backedge;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge24:
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = call i32 @fclose(%%struct._iobuf* %%1) nounwind, !dbg !13 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_587_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__75);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @readFile}\n");
  return;
}

