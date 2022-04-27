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

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void convolution1(signed int llvm_cbe_mRow, signed int llvm_cbe_mCol, float *llvm_cbe_m, signed int llvm_cbe_kRow, signed int llvm_cbe_kCol, signed int llvm_cbe_kNum, float *llvm_cbe_k, float *llvm_cbe_bias, float *llvm_cbe_out);
void convolution2(signed int llvm_cbe_mRow, signed int llvm_cbe_mCol, signed int llvm_cbe_mDep, float *llvm_cbe_m, signed int llvm_cbe_kRow, signed int llvm_cbe_kCol, signed int llvm_cbe_kNum, float *llvm_cbe_k, float *llvm_cbe_bias, float *llvm_cbe_out);
void maxPool(signed int llvm_cbe_mRow, signed int llvm_cbe_mCol, signed int llvm_cbe_mDep, float *llvm_cbe_m, signed int llvm_cbe_oRow, signed int llvm_cbe_oCol, float *llvm_cbe_out, signed int llvm_cbe_kRow, signed int llvm_cbe_kCol);
void dense1(signed int llvm_cbe_mRow, signed int llvm_cbe_mCol, signed int llvm_cbe_mDep, float *llvm_cbe_m, signed int llvm_cbe_kRow, signed int llvm_cbe_kCol, signed int llvm_cbe_kNum, float *llvm_cbe_k, float *llvm_cbe_bias, signed int llvm_cbe_oSize, float *llvm_cbe_out);
void dense2(signed int llvm_cbe_mSize, float *llvm_cbe_m, signed int llvm_cbe_kSize, signed int llvm_cbe_kNum, float *llvm_cbe_k, float *llvm_cbe_bias, signed int llvm_cbe_oSize, float *llvm_cbe_out);
void softmax(signed int llvm_cbe_mSize, float *llvm_cbe_m, float *llvm_cbe_out);


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

void convolution1(signed int llvm_cbe_mRow, signed int llvm_cbe_mCol, float *llvm_cbe_m, signed int llvm_cbe_kRow, signed int llvm_cbe_kCol, signed int llvm_cbe_kNum, float *llvm_cbe_k, float *llvm_cbe_bias, float *llvm_cbe_out) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned long long llvm_cbe_tmp__4;
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
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
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
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned long long llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge77_count = 0;
  unsigned int llvm_cbe_storemerge77;
  unsigned int llvm_cbe_storemerge77__PHI_TEMPORARY;
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
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe__2e_sum3_count = 0;
  unsigned long long llvm_cbe__2e_sum3;
  static  unsigned long long aesl_llvm_cbe__2e_sum4_count = 0;
  unsigned long long llvm_cbe__2e_sum4;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  float *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  float *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe__2e_sum57_count = 0;
  unsigned long long llvm_cbe__2e_sum57;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  float *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  float *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  float *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe__2e_sum61_count = 0;
  unsigned long long llvm_cbe__2e_sum61;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  float *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe__2e_sum64_count = 0;
  unsigned long long llvm_cbe__2e_sum64;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  float *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe__2e_sum26_count = 0;
  unsigned long long llvm_cbe__2e_sum26;
  static  unsigned long long aesl_llvm_cbe__2e_sum27_count = 0;
  unsigned long long llvm_cbe__2e_sum27;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  float *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe__2e_sum29_count = 0;
  unsigned long long llvm_cbe__2e_sum29;
  static  unsigned long long aesl_llvm_cbe__2e_sum30_count = 0;
  unsigned long long llvm_cbe__2e_sum30;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  float *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  float *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  float *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe__2e_sum35_count = 0;
  unsigned long long llvm_cbe__2e_sum35;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  float *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe__2e_sum38_count = 0;
  unsigned long long llvm_cbe__2e_sum38;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  float *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge175_count = 0;
  unsigned int llvm_cbe_storemerge175;
  unsigned int llvm_cbe_storemerge175__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
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
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  unsigned long long llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  unsigned long long llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  unsigned long long llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  unsigned long long llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  unsigned long long llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge273_count = 0;
  unsigned int llvm_cbe_storemerge273;
  unsigned int llvm_cbe_storemerge273__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  unsigned long long llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  float *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  float llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  float llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  float llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  float llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  float llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_tmp72_count = 0;
  unsigned long long llvm_cbe_tmp72;
  static  unsigned long long aesl_llvm_cbe__2e_sum6_count = 0;
  unsigned long long llvm_cbe__2e_sum6;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  float *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_sum56_count = 0;
  unsigned long long llvm_cbe__2e_sum56;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  float *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  float llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  float llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  float llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  float llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe__2e_sum67_count = 0;
  unsigned long long llvm_cbe__2e_sum67;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  float *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  float llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  float llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  float llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe__2e_sum68_count = 0;
  unsigned long long llvm_cbe__2e_sum68;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  float *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  float llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  float llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  float llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  float llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  float llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  float llvm_cbe_tmp__59;
  float llvm_cbe_tmp__59__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  unsigned long long llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe__2e_sum60_count = 0;
  unsigned long long llvm_cbe__2e_sum60;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  float *llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  float llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  float llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  float llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe__2e_sum62_count = 0;
  unsigned long long llvm_cbe__2e_sum62;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  float *llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  float llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  float llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  float llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  float llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  float llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  unsigned int llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  unsigned long long llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe__2e_sum52_count = 0;
  unsigned long long llvm_cbe__2e_sum52;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  float *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  float llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  float llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  float llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  float llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  float llvm_cbe_tmp__79;
  float llvm_cbe_tmp__79__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  unsigned long long llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe__2e_sum47_count = 0;
  unsigned long long llvm_cbe__2e_sum47;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  float *llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  float llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  float llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  float llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  float llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  float llvm_cbe_tmp__87;
  float llvm_cbe_tmp__87__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_sum25_count = 0;
  unsigned long long llvm_cbe__2e_sum25;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  float *llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  float llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  float llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  float llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe__2e_sum28_count = 0;
  unsigned long long llvm_cbe__2e_sum28;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  float *llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  float llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  float llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  float llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  float llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  float llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  unsigned int llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  unsigned long long llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe__2e_sum41_count = 0;
  unsigned long long llvm_cbe__2e_sum41;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  float *llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  float llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  float llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  float llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe__2e_sum43_count = 0;
  unsigned long long llvm_cbe__2e_sum43;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  float *llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  float llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  float llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  float llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  float llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  float llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  float llvm_cbe_tmp__110;
  float llvm_cbe_tmp__110__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  unsigned int llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  unsigned long long llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe__2e_sum33_count = 0;
  unsigned long long llvm_cbe__2e_sum33;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  float *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  float llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  float llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  float llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe__2e_sum36_count = 0;
  unsigned long long llvm_cbe__2e_sum36;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  float *llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  float llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  float llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  float llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  float llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  float llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_sum11_count = 0;
  unsigned long long llvm_cbe__2e_sum11;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  float *llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  float llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  float llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  float llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  float llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  unsigned int llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  unsigned long long llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe__2e_sum21_count = 0;
  unsigned long long llvm_cbe__2e_sum21;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  float *llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  float llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  float llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  float llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  float llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  float llvm_cbe_tmp__135;
  float llvm_cbe_tmp__135__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  unsigned int llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  unsigned long long llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe__2e_sum16_count = 0;
  unsigned long long llvm_cbe__2e_sum16;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  float *llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  float llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  float llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  float llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  float llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  float llvm_cbe_tmp__143;
  float llvm_cbe_tmp__143__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  unsigned int llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  unsigned int llvm_cbe_tmp__145;
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
  static  unsigned long long aesl_llvm_cbe_exitcond79_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  unsigned int llvm_cbe_tmp__146;
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
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond80_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @convolution1\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i32 %%mCol to i6 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__1 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_mCol&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%kRow to i6 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__2 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_kRow&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%kCol to i6 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__3 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_kCol&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i32 %%kNum to i6 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__4 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_kNum&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__4);
  if ((((signed int )llvm_cbe_kNum) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader74_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge78;
  }

llvm_cbe__2e_preheader74_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = mul i64 %%3, %%2, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__5 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__3&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__5&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = shl nuw nsw i64 %%3, 1, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__6 = (unsigned long long )llvm_cbe_tmp__3 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = mul nsw i64 %%3, 3, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__7 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__3&18446744073709551615ull)) * ((unsigned long long )(3ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__7&18446744073709551615ull)));
  llvm_cbe_storemerge77__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader74;

  do {     /* Syntactic loop '.preheader74' to make GCC happy */
llvm_cbe__2e_preheader74:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge77 = phi i32 [ 0, %%.preheader74.lr.ph ], [ %%183, %%._crit_edge76  for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_storemerge77_count);
  llvm_cbe_storemerge77 = (unsigned int )llvm_cbe_storemerge77__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge77 = 0x%X",llvm_cbe_storemerge77);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__146);
}
  if ((((signed int )llvm_cbe_mRow) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge76;
  }

llvm_cbe__2e__crit_edge76:
if (AESL_DEBUG_TRACE)
printf("\n  %%183 = add nsw i32 %%storemerge77, 1, !dbg !12 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_466_count);
  llvm_cbe_tmp__146 = (unsigned int )((unsigned int )(llvm_cbe_storemerge77&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__146&4294967295ull)));
  if (((llvm_cbe_tmp__146&4294967295U) == (llvm_cbe_kNum&4294967295U))) {
    goto llvm_cbe__2e__crit_edge78;
  } else {
    llvm_cbe_storemerge77__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__146;   /* for PHI node */
    goto llvm_cbe__2e_preheader74;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge175 = phi i32 [ 0, %%.preheader.lr.ph ], [ %%182, %%._crit_edge  for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_storemerge175_count);
  llvm_cbe_storemerge175 = (unsigned int )llvm_cbe_storemerge175__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge175 = 0x%X",llvm_cbe_storemerge175);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__145);
}
  if ((((signed int )llvm_cbe_mCol) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%182 = add nsw i32 %%storemerge175, 1, !dbg !12 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_427_count);
  llvm_cbe_tmp__145 = (unsigned int )((unsigned int )(llvm_cbe_storemerge175&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__145&4294967295ull)));
  if (((llvm_cbe_tmp__145&4294967295U) == (llvm_cbe_mRow&4294967295U))) {
    goto llvm_cbe__2e__crit_edge76;
  } else {
    llvm_cbe_storemerge175__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__145;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__147:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge273 = phi i32 [ 0, %%.lr.ph ], [ %%181, %%180  for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_storemerge273_count);
  llvm_cbe_storemerge273 = (unsigned int )llvm_cbe_storemerge273__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge273 = 0x%X",llvm_cbe_storemerge273);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__144);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = sext i32 %%storemerge273 to i64, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_230_count);
  llvm_cbe_tmp__34 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge273);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%41, %%27, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__34&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__24&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds float* %%m, i64 %%.sum, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_231_count);
  llvm_cbe_tmp__35 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load float* %%42, align 4, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_232_count);
  llvm_cbe_tmp__36 = (float )*llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__36, *(int*)(&llvm_cbe_tmp__36));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load float* %%13, align 4, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_233_count);
  llvm_cbe_tmp__37 = (float )*llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__37, *(int*)(&llvm_cbe_tmp__37));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = fmul float %%43, %%44, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_234_count);
  llvm_cbe_tmp__38 = (float )((float )(llvm_cbe_tmp__36 * llvm_cbe_tmp__37));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__38, *(int*)(&llvm_cbe_tmp__38));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load float* %%14, align 4, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_235_count);
  llvm_cbe_tmp__39 = (float )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__39, *(int*)(&llvm_cbe_tmp__39));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = fadd float %%45, %%46, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_236_count);
  llvm_cbe_tmp__40 = (float )((float )(llvm_cbe_tmp__38 + llvm_cbe_tmp__39));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__40, *(int*)(&llvm_cbe_tmp__40));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp72 = mul i64 %%.sum, %% for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_tmp72_count);
  llvm_cbe_tmp72 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__4&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp72 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp72&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum6 = add i64 %%tmp72, %%11, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum6_count);
  llvm_cbe__2e_sum6 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp72&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__8&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum6 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum6&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds float* %%out, i64 %%.sum6, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_237_count);
  llvm_cbe_tmp__41 = (float *)(&llvm_cbe_out[(((signed long long )llvm_cbe__2e_sum6))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum6 = 0x%I64X",((signed long long )llvm_cbe__2e_sum6));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%47, float* %%48, align 4, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_238_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__40);
  if ((((signed int )llvm_cbe_storemerge175) > ((signed int )0u))) {
    goto llvm_cbe_tmp__148;
  } else {
    goto llvm_cbe_tmp__149;
  }

llvm_cbe_tmp__150:
if (AESL_DEBUG_TRACE)
printf("\n  %%181 = add nsw i32 %%storemerge273, 1, !dbg !13 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_383_count);
  llvm_cbe_tmp__144 = (unsigned int )((unsigned int )(llvm_cbe_storemerge273&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__144&4294967295ull)));
  if (((llvm_cbe_tmp__144&4294967295U) == (llvm_cbe_mCol&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge273__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__144;   /* for PHI node */
    goto llvm_cbe_tmp__147;
  }

llvm_cbe_tmp__151:
if (AESL_DEBUG_TRACE)
printf("\n  %%177 = phi float [ %%148, %%137 ], [ %%134, %%133 ], [ %%107, %%149 ], [ %%175, %%169 ], [ %%166, %%165  for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_378_count);
  llvm_cbe_tmp__143 = (float )llvm_cbe_tmp__143__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__143);
printf("\n = %f",llvm_cbe_tmp__122);
printf("\n = %f",llvm_cbe_tmp__110);
printf("\n = %f",llvm_cbe_tmp__87);
printf("\n = %f",llvm_cbe_tmp__142);
printf("\n = %f",llvm_cbe_tmp__135);
}
  if ((llvm_fcmp_olt(llvm_cbe_tmp__143, 0x0p0))) {
    goto llvm_cbe_tmp__152;
  } else {
    goto llvm_cbe_tmp__150;
  }

llvm_cbe_tmp__153:
if (AESL_DEBUG_TRACE)
printf("\n  %%134 = phi float [ %%132, %%120 ], [ %%118, %%108  for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_331_count);
  llvm_cbe_tmp__110 = (float )llvm_cbe_tmp__110__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__110);
printf("\n = %f",llvm_cbe_tmp__109);
printf("\n = %f",llvm_cbe_tmp__97);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%135 = add nsw i32 %%storemerge273, 1, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_332_count);
  llvm_cbe_tmp__111 = (unsigned int )((unsigned int )(llvm_cbe_storemerge273&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__111&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__111) < ((signed int )llvm_cbe_mCol))) {
    goto llvm_cbe_tmp__154;
  } else {
    llvm_cbe_tmp__143__PHI_TEMPORARY = (float )llvm_cbe_tmp__110;   /* for PHI node */
    goto llvm_cbe_tmp__151;
  }

llvm_cbe_tmp__155:
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum25 = add i64 %%41, %%36, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum25_count);
  llvm_cbe__2e_sum25 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__34&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum25 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum25&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = getelementptr inbounds float* %%m, i64 %%.sum25, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_304_count);
  llvm_cbe_tmp__88 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum25))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum25 = 0x%I64X",((signed long long )llvm_cbe__2e_sum25));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = load float* %%109, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__89 = (float )*llvm_cbe_tmp__88;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__89, *(int*)(&llvm_cbe_tmp__89));
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = load float* %%20, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_306_count);
  llvm_cbe_tmp__90 = (float )*llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__90, *(int*)(&llvm_cbe_tmp__90));
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = fmul float %%110, %%111, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_307_count);
  llvm_cbe_tmp__91 = (float )((float )(llvm_cbe_tmp__89 * llvm_cbe_tmp__90));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__91, *(int*)(&llvm_cbe_tmp__91));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum28 = add i64 %%41, %%38, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum28_count);
  llvm_cbe__2e_sum28 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__34&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__33&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum28 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum28&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = getelementptr inbounds float* %%m, i64 %%.sum28, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_308_count);
  llvm_cbe_tmp__92 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum28))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum28 = 0x%I64X",((signed long long )llvm_cbe__2e_sum28));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = load float* %%113, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_309_count);
  llvm_cbe_tmp__93 = (float )*llvm_cbe_tmp__92;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__93, *(int*)(&llvm_cbe_tmp__93));
if (AESL_DEBUG_TRACE)
printf("\n  %%115 = load float* %%21, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_310_count);
  llvm_cbe_tmp__94 = (float )*llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__94, *(int*)(&llvm_cbe_tmp__94));
if (AESL_DEBUG_TRACE)
printf("\n  %%116 = fmul float %%114, %%115, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_311_count);
  llvm_cbe_tmp__95 = (float )((float )(llvm_cbe_tmp__93 * llvm_cbe_tmp__94));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__95, *(int*)(&llvm_cbe_tmp__95));
if (AESL_DEBUG_TRACE)
printf("\n  %%117 = fadd float %%112, %%116, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__96 = (float )((float )(llvm_cbe_tmp__91 + llvm_cbe_tmp__95));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__96, *(int*)(&llvm_cbe_tmp__96));
if (AESL_DEBUG_TRACE)
printf("\n  %%118 = fadd float %%107, %%117, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__97 = (float )((float )(llvm_cbe_tmp__87 + llvm_cbe_tmp__96));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__97, *(int*)(&llvm_cbe_tmp__97));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%118, float* %%48, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_314_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__97);
  if ((((signed int )llvm_cbe_storemerge273) > ((signed int )0u))) {
    goto llvm_cbe_tmp__156;
  } else {
    llvm_cbe_tmp__110__PHI_TEMPORARY = (float )llvm_cbe_tmp__97;   /* for PHI node */
    goto llvm_cbe_tmp__153;
  }

llvm_cbe_tmp__157:
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = phi float [ %%84, %%73 ], [ %%70, %%69 ], [ %%105, %%99 ], [ %%96, %%95  for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__87 = (float )llvm_cbe_tmp__87__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__87);
printf("\n = %f",llvm_cbe_tmp__71);
printf("\n = %f",llvm_cbe_tmp__59);
printf("\n = %f",llvm_cbe_tmp__86);
printf("\n = %f",llvm_cbe_tmp__79);
}
  if ((((signed int )llvm_cbe_tmp__28) < ((signed int )llvm_cbe_mRow))) {
    goto llvm_cbe_tmp__155;
  } else {
    goto llvm_cbe_tmp__158;
  }

llvm_cbe_tmp__159:
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = phi float [ %%68, %%56 ], [ %%54, %%49  for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_262_count);
  llvm_cbe_tmp__59 = (float )llvm_cbe_tmp__59__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__59);
printf("\n = %f",llvm_cbe_tmp__58);
printf("\n = %f",llvm_cbe_tmp__46);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = add nsw i32 %%storemerge273, 1, !dbg !8 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__60 = (unsigned int )((unsigned int )(llvm_cbe_storemerge273&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__60&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__60) < ((signed int )llvm_cbe_mCol))) {
    goto llvm_cbe_tmp__160;
  } else {
    llvm_cbe_tmp__87__PHI_TEMPORARY = (float )llvm_cbe_tmp__59;   /* for PHI node */
    goto llvm_cbe_tmp__157;
  }

llvm_cbe_tmp__148:
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum56 = add i64 %%41, %%31, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum56_count);
  llvm_cbe__2e_sum56 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__34&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__27&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum56 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum56&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds float* %%m, i64 %%.sum56, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__42 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum56))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum56 = 0x%I64X",((signed long long )llvm_cbe__2e_sum56));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load float* %%50, align 4, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_241_count);
  llvm_cbe_tmp__43 = (float )*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__43, *(int*)(&llvm_cbe_tmp__43));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load float* %%15, align 4, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__44 = (float )*llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__44, *(int*)(&llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = fmul float %%51, %%52, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_243_count);
  llvm_cbe_tmp__45 = (float )((float )(llvm_cbe_tmp__43 * llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__45, *(int*)(&llvm_cbe_tmp__45));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = fadd float %%47, %%53, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_244_count);
  llvm_cbe_tmp__46 = (float )((float )(llvm_cbe_tmp__40 + llvm_cbe_tmp__45));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__46, *(int*)(&llvm_cbe_tmp__46));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%54, float* %%48, align 4, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_245_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__46);
  if ((((signed int )llvm_cbe_storemerge273) > ((signed int )0u))) {
    goto llvm_cbe_tmp__161;
  } else {
    llvm_cbe_tmp__59__PHI_TEMPORARY = (float )llvm_cbe_tmp__46;   /* for PHI node */
    goto llvm_cbe_tmp__159;
  }

llvm_cbe_tmp__161:
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = add nsw i32 %%storemerge273, -1, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_248_count);
  llvm_cbe_tmp__47 = (unsigned int )((unsigned int )(llvm_cbe_storemerge273&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__47&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = sext i32 %%57 to i64, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_249_count);
  llvm_cbe_tmp__48 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum67 = add i64 %%58, %%31, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum67_count);
  llvm_cbe__2e_sum67 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__48&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__27&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum67 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum67&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = getelementptr inbounds float* %%m, i64 %%.sum67, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__49 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum67))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum67 = 0x%I64X",((signed long long )llvm_cbe__2e_sum67));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load float* %%59, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__50 = (float )*llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__50, *(int*)(&llvm_cbe_tmp__50));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = load float* %%16, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__51 = (float )*llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__51, *(int*)(&llvm_cbe_tmp__51));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = fmul float %%60, %%61, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_253_count);
  llvm_cbe_tmp__52 = (float )((float )(llvm_cbe_tmp__50 * llvm_cbe_tmp__51));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__52, *(int*)(&llvm_cbe_tmp__52));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum68 = add i64 %%58, %%27, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum68_count);
  llvm_cbe__2e_sum68 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__48&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__24&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum68 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum68&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds float* %%m, i64 %%.sum68, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_254_count);
  llvm_cbe_tmp__53 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum68))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum68 = 0x%I64X",((signed long long )llvm_cbe__2e_sum68));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load float* %%63, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_255_count);
  llvm_cbe_tmp__54 = (float )*llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__54, *(int*)(&llvm_cbe_tmp__54));
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = load float* %%17, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__55 = (float )*llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__55, *(int*)(&llvm_cbe_tmp__55));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = fmul float %%64, %%65, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_257_count);
  llvm_cbe_tmp__56 = (float )((float )(llvm_cbe_tmp__54 * llvm_cbe_tmp__55));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__56, *(int*)(&llvm_cbe_tmp__56));
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = fadd float %%62, %%66, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_258_count);
  llvm_cbe_tmp__57 = (float )((float )(llvm_cbe_tmp__52 + llvm_cbe_tmp__56));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__57, *(int*)(&llvm_cbe_tmp__57));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = fadd float %%54, %%67, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_259_count);
  llvm_cbe_tmp__58 = (float )((float )(llvm_cbe_tmp__46 + llvm_cbe_tmp__57));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__58, *(int*)(&llvm_cbe_tmp__58));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%68, float* %%48, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_260_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__58;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__58);
  llvm_cbe_tmp__59__PHI_TEMPORARY = (float )llvm_cbe_tmp__58;   /* for PHI node */
  goto llvm_cbe_tmp__159;

llvm_cbe_tmp__160:
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = sext i32 %%71 to i64, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_266_count);
  llvm_cbe_tmp__61 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum60 = add i64 %%74, %%31, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum60_count);
  llvm_cbe__2e_sum60 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__61&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__27&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum60 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum60&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = getelementptr inbounds float* %%m, i64 %%.sum60, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_267_count);
  llvm_cbe_tmp__62 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum60))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum60 = 0x%I64X",((signed long long )llvm_cbe__2e_sum60));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = load float* %%75, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_268_count);
  llvm_cbe_tmp__63 = (float )*llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__63, *(int*)(&llvm_cbe_tmp__63));
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = load float* %%18, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_269_count);
  llvm_cbe_tmp__64 = (float )*llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__64, *(int*)(&llvm_cbe_tmp__64));
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = fmul float %%76, %%77, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_270_count);
  llvm_cbe_tmp__65 = (float )((float )(llvm_cbe_tmp__63 * llvm_cbe_tmp__64));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__65, *(int*)(&llvm_cbe_tmp__65));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum62 = add i64 %%74, %%27, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum62_count);
  llvm_cbe__2e_sum62 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__61&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__24&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum62 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum62&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds float* %%m, i64 %%.sum62, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_271_count);
  llvm_cbe_tmp__66 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum62))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum62 = 0x%I64X",((signed long long )llvm_cbe__2e_sum62));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load float* %%79, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_272_count);
  llvm_cbe_tmp__67 = (float )*llvm_cbe_tmp__66;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__67, *(int*)(&llvm_cbe_tmp__67));
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = load float* %%19, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_273_count);
  llvm_cbe_tmp__68 = (float )*llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__68, *(int*)(&llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = fmul float %%80, %%81, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_274_count);
  llvm_cbe_tmp__69 = (float )((float )(llvm_cbe_tmp__67 * llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__69, *(int*)(&llvm_cbe_tmp__69));
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = fadd float %%78, %%82, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__70 = (float )((float )(llvm_cbe_tmp__65 + llvm_cbe_tmp__69));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__70, *(int*)(&llvm_cbe_tmp__70));
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = fadd float %%70, %%83, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_276_count);
  llvm_cbe_tmp__71 = (float )((float )(llvm_cbe_tmp__59 + llvm_cbe_tmp__70));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__71, *(int*)(&llvm_cbe_tmp__71));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%84, float* %%48, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_277_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__71;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__71);
  llvm_cbe_tmp__87__PHI_TEMPORARY = (float )llvm_cbe_tmp__71;   /* for PHI node */
  goto llvm_cbe_tmp__157;

llvm_cbe_tmp__162:
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = phi float [ %%94, %%87 ], [ %%47, %%85  for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_290_count);
  llvm_cbe_tmp__79 = (float )llvm_cbe_tmp__79__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__79);
printf("\n = %f",llvm_cbe_tmp__78);
printf("\n = %f",llvm_cbe_tmp__40);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = add nsw i32 %%storemerge273, 1, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_291_count);
  llvm_cbe_tmp__80 = (unsigned int )((unsigned int )(llvm_cbe_storemerge273&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__80&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__80) < ((signed int )llvm_cbe_mCol))) {
    goto llvm_cbe_tmp__163;
  } else {
    llvm_cbe_tmp__87__PHI_TEMPORARY = (float )llvm_cbe_tmp__79;   /* for PHI node */
    goto llvm_cbe_tmp__157;
  }

llvm_cbe_tmp__149:
  if ((((signed int )llvm_cbe_storemerge273) > ((signed int )0u))) {
    goto llvm_cbe_tmp__164;
  } else {
    llvm_cbe_tmp__79__PHI_TEMPORARY = (float )llvm_cbe_tmp__40;   /* for PHI node */
    goto llvm_cbe_tmp__162;
  }

llvm_cbe_tmp__164:
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = add nsw i32 %%storemerge273, -1, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_281_count);
  llvm_cbe_tmp__72 = (unsigned int )((unsigned int )(llvm_cbe_storemerge273&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__72&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = sext i32 %%88 to i64, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__73 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum52 = add i64 %%89, %%27, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum52_count);
  llvm_cbe__2e_sum52 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__73&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__24&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum52 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum52&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = getelementptr inbounds float* %%m, i64 %%.sum52, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_283_count);
  llvm_cbe_tmp__74 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum52))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum52 = 0x%I64X",((signed long long )llvm_cbe__2e_sum52));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = load float* %%90, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_284_count);
  llvm_cbe_tmp__75 = (float )*llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__75, *(int*)(&llvm_cbe_tmp__75));
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = load float* %%17, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_285_count);
  llvm_cbe_tmp__76 = (float )*llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__76, *(int*)(&llvm_cbe_tmp__76));
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = fmul float %%91, %%92, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_286_count);
  llvm_cbe_tmp__77 = (float )((float )(llvm_cbe_tmp__75 * llvm_cbe_tmp__76));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__77, *(int*)(&llvm_cbe_tmp__77));
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = fadd float %%47, %%93, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_287_count);
  llvm_cbe_tmp__78 = (float )((float )(llvm_cbe_tmp__40 + llvm_cbe_tmp__77));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__78, *(int*)(&llvm_cbe_tmp__78));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%94, float* %%48, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_288_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__78;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__78);
  llvm_cbe_tmp__79__PHI_TEMPORARY = (float )llvm_cbe_tmp__78;   /* for PHI node */
  goto llvm_cbe_tmp__162;

llvm_cbe_tmp__163:
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = sext i32 %%97 to i64, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_294_count);
  llvm_cbe_tmp__81 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum47 = add i64 %%100, %%27, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum47_count);
  llvm_cbe__2e_sum47 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__81&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__24&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum47 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum47&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = getelementptr inbounds float* %%m, i64 %%.sum47, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_295_count);
  llvm_cbe_tmp__82 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum47))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum47 = 0x%I64X",((signed long long )llvm_cbe__2e_sum47));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = load float* %%101, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_296_count);
  llvm_cbe_tmp__83 = (float )*llvm_cbe_tmp__82;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__83, *(int*)(&llvm_cbe_tmp__83));
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = load float* %%19, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_297_count);
  llvm_cbe_tmp__84 = (float )*llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__84, *(int*)(&llvm_cbe_tmp__84));
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = fmul float %%102, %%103, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_298_count);
  llvm_cbe_tmp__85 = (float )((float )(llvm_cbe_tmp__83 * llvm_cbe_tmp__84));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__85, *(int*)(&llvm_cbe_tmp__85));
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = fadd float %%96, %%104, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_299_count);
  llvm_cbe_tmp__86 = (float )((float )(llvm_cbe_tmp__79 + llvm_cbe_tmp__85));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__86, *(int*)(&llvm_cbe_tmp__86));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%105, float* %%48, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_300_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__86;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__86);
  llvm_cbe_tmp__87__PHI_TEMPORARY = (float )llvm_cbe_tmp__86;   /* for PHI node */
  goto llvm_cbe_tmp__157;

llvm_cbe_tmp__156:
if (AESL_DEBUG_TRACE)
printf("\n  %%121 = add nsw i32 %%storemerge273, -1, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_317_count);
  llvm_cbe_tmp__98 = (unsigned int )((unsigned int )(llvm_cbe_storemerge273&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__98&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%122 = sext i32 %%121 to i64, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__99 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum41 = add i64 %%122, %%36, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum41_count);
  llvm_cbe__2e_sum41 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__99&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum41 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum41&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%123 = getelementptr inbounds float* %%m, i64 %%.sum41, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_319_count);
  llvm_cbe_tmp__100 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum41))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum41 = 0x%I64X",((signed long long )llvm_cbe__2e_sum41));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%124 = load float* %%123, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_320_count);
  llvm_cbe_tmp__101 = (float )*llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__101, *(int*)(&llvm_cbe_tmp__101));
if (AESL_DEBUG_TRACE)
printf("\n  %%125 = load float* %%22, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_321_count);
  llvm_cbe_tmp__102 = (float )*llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__102, *(int*)(&llvm_cbe_tmp__102));
if (AESL_DEBUG_TRACE)
printf("\n  %%126 = fmul float %%124, %%125, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_322_count);
  llvm_cbe_tmp__103 = (float )((float )(llvm_cbe_tmp__101 * llvm_cbe_tmp__102));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__103, *(int*)(&llvm_cbe_tmp__103));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum43 = add i64 %%122, %%38, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum43_count);
  llvm_cbe__2e_sum43 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__99&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__33&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum43 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum43&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%127 = getelementptr inbounds float* %%m, i64 %%.sum43, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_323_count);
  llvm_cbe_tmp__104 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum43))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum43 = 0x%I64X",((signed long long )llvm_cbe__2e_sum43));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%128 = load float* %%127, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__105 = (float )*llvm_cbe_tmp__104;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__105, *(int*)(&llvm_cbe_tmp__105));
if (AESL_DEBUG_TRACE)
printf("\n  %%129 = load float* %%23, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_325_count);
  llvm_cbe_tmp__106 = (float )*llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__106, *(int*)(&llvm_cbe_tmp__106));
if (AESL_DEBUG_TRACE)
printf("\n  %%130 = fmul float %%128, %%129, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__107 = (float )((float )(llvm_cbe_tmp__105 * llvm_cbe_tmp__106));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__107, *(int*)(&llvm_cbe_tmp__107));
if (AESL_DEBUG_TRACE)
printf("\n  %%131 = fadd float %%126, %%130, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_327_count);
  llvm_cbe_tmp__108 = (float )((float )(llvm_cbe_tmp__103 + llvm_cbe_tmp__107));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__108, *(int*)(&llvm_cbe_tmp__108));
if (AESL_DEBUG_TRACE)
printf("\n  %%132 = fadd float %%118, %%131, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__109 = (float )((float )(llvm_cbe_tmp__97 + llvm_cbe_tmp__108));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__109, *(int*)(&llvm_cbe_tmp__109));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%132, float* %%48, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_329_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__109;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__109);
  llvm_cbe_tmp__110__PHI_TEMPORARY = (float )llvm_cbe_tmp__109;   /* for PHI node */
  goto llvm_cbe_tmp__153;

llvm_cbe_tmp__154:
if (AESL_DEBUG_TRACE)
printf("\n  %%138 = sext i32 %%135 to i64, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_335_count);
  llvm_cbe_tmp__112 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__112);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum33 = add i64 %%138, %%36, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum33_count);
  llvm_cbe__2e_sum33 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__112&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum33 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum33&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%139 = getelementptr inbounds float* %%m, i64 %%.sum33, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_336_count);
  llvm_cbe_tmp__113 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum33))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum33 = 0x%I64X",((signed long long )llvm_cbe__2e_sum33));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%140 = load float* %%139, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_337_count);
  llvm_cbe_tmp__114 = (float )*llvm_cbe_tmp__113;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__114, *(int*)(&llvm_cbe_tmp__114));
if (AESL_DEBUG_TRACE)
printf("\n  %%141 = load float* %%24, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_338_count);
  llvm_cbe_tmp__115 = (float )*llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__115, *(int*)(&llvm_cbe_tmp__115));
if (AESL_DEBUG_TRACE)
printf("\n  %%142 = fmul float %%140, %%141, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_339_count);
  llvm_cbe_tmp__116 = (float )((float )(llvm_cbe_tmp__114 * llvm_cbe_tmp__115));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__116, *(int*)(&llvm_cbe_tmp__116));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum36 = add i64 %%138, %%38, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum36_count);
  llvm_cbe__2e_sum36 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__112&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__33&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum36 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum36&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%143 = getelementptr inbounds float* %%m, i64 %%.sum36, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_340_count);
  llvm_cbe_tmp__117 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum36))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum36 = 0x%I64X",((signed long long )llvm_cbe__2e_sum36));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%144 = load float* %%143, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_341_count);
  llvm_cbe_tmp__118 = (float )*llvm_cbe_tmp__117;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__118, *(int*)(&llvm_cbe_tmp__118));
if (AESL_DEBUG_TRACE)
printf("\n  %%145 = load float* %%25, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_342_count);
  llvm_cbe_tmp__119 = (float )*llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__119, *(int*)(&llvm_cbe_tmp__119));
if (AESL_DEBUG_TRACE)
printf("\n  %%146 = fmul float %%144, %%145, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_343_count);
  llvm_cbe_tmp__120 = (float )((float )(llvm_cbe_tmp__118 * llvm_cbe_tmp__119));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__120, *(int*)(&llvm_cbe_tmp__120));
if (AESL_DEBUG_TRACE)
printf("\n  %%147 = fadd float %%142, %%146, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_344_count);
  llvm_cbe_tmp__121 = (float )((float )(llvm_cbe_tmp__116 + llvm_cbe_tmp__120));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__121, *(int*)(&llvm_cbe_tmp__121));
if (AESL_DEBUG_TRACE)
printf("\n  %%148 = fadd float %%134, %%147, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_345_count);
  llvm_cbe_tmp__122 = (float )((float )(llvm_cbe_tmp__110 + llvm_cbe_tmp__121));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__122, *(int*)(&llvm_cbe_tmp__122));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%148, float* %%48, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_346_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__122;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__122);
  llvm_cbe_tmp__143__PHI_TEMPORARY = (float )llvm_cbe_tmp__122;   /* for PHI node */
  goto llvm_cbe_tmp__151;

llvm_cbe_tmp__158:
  if ((((signed int )llvm_cbe_tmp__29) < ((signed int )llvm_cbe_mRow))) {
    goto llvm_cbe_tmp__165;
  } else {
    llvm_cbe_tmp__143__PHI_TEMPORARY = (float )llvm_cbe_tmp__87;   /* for PHI node */
    goto llvm_cbe_tmp__151;
  }

llvm_cbe_tmp__166:
if (AESL_DEBUG_TRACE)
printf("\n  %%166 = phi float [ %%164, %%157 ], [ %%155, %%150  for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_366_count);
  llvm_cbe_tmp__135 = (float )llvm_cbe_tmp__135__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__135);
printf("\n = %f",llvm_cbe_tmp__134);
printf("\n = %f",llvm_cbe_tmp__127);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%167 = add nsw i32 %%storemerge273, 1, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_367_count);
  llvm_cbe_tmp__136 = (unsigned int )((unsigned int )(llvm_cbe_storemerge273&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__136&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__136) < ((signed int )llvm_cbe_mCol))) {
    goto llvm_cbe_tmp__167;
  } else {
    llvm_cbe_tmp__143__PHI_TEMPORARY = (float )llvm_cbe_tmp__135;   /* for PHI node */
    goto llvm_cbe_tmp__151;
  }

llvm_cbe_tmp__165:
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum11 = add i64 %%41, %%36, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum11_count);
  llvm_cbe__2e_sum11 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__34&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum11 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum11&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%151 = getelementptr inbounds float* %%m, i64 %%.sum11, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__123 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum11))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum11 = 0x%I64X",((signed long long )llvm_cbe__2e_sum11));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%152 = load float* %%151, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_350_count);
  llvm_cbe_tmp__124 = (float )*llvm_cbe_tmp__123;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__124, *(int*)(&llvm_cbe_tmp__124));
if (AESL_DEBUG_TRACE)
printf("\n  %%153 = load float* %%20, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__125 = (float )*llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__125, *(int*)(&llvm_cbe_tmp__125));
if (AESL_DEBUG_TRACE)
printf("\n  %%154 = fmul float %%152, %%153, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__126 = (float )((float )(llvm_cbe_tmp__124 * llvm_cbe_tmp__125));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__126, *(int*)(&llvm_cbe_tmp__126));
if (AESL_DEBUG_TRACE)
printf("\n  %%155 = fadd float %%107, %%154, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__127 = (float )((float )(llvm_cbe_tmp__87 + llvm_cbe_tmp__126));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__127, *(int*)(&llvm_cbe_tmp__127));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%155, float* %%48, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_354_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__127;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__127);
  if ((((signed int )llvm_cbe_storemerge273) > ((signed int )0u))) {
    goto llvm_cbe_tmp__168;
  } else {
    llvm_cbe_tmp__135__PHI_TEMPORARY = (float )llvm_cbe_tmp__127;   /* for PHI node */
    goto llvm_cbe_tmp__166;
  }

llvm_cbe_tmp__168:
if (AESL_DEBUG_TRACE)
printf("\n  %%158 = add nsw i32 %%storemerge273, -1, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__128 = (unsigned int )((unsigned int )(llvm_cbe_storemerge273&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__128&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%159 = sext i32 %%158 to i64, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__129 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__128);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum21 = add i64 %%159, %%36, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum21_count);
  llvm_cbe__2e_sum21 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__129&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum21 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum21&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%160 = getelementptr inbounds float* %%m, i64 %%.sum21, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_359_count);
  llvm_cbe_tmp__130 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum21))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum21 = 0x%I64X",((signed long long )llvm_cbe__2e_sum21));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%161 = load float* %%160, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_360_count);
  llvm_cbe_tmp__131 = (float )*llvm_cbe_tmp__130;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__131, *(int*)(&llvm_cbe_tmp__131));
if (AESL_DEBUG_TRACE)
printf("\n  %%162 = load float* %%22, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_361_count);
  llvm_cbe_tmp__132 = (float )*llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__132, *(int*)(&llvm_cbe_tmp__132));
if (AESL_DEBUG_TRACE)
printf("\n  %%163 = fmul float %%161, %%162, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_362_count);
  llvm_cbe_tmp__133 = (float )((float )(llvm_cbe_tmp__131 * llvm_cbe_tmp__132));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__133, *(int*)(&llvm_cbe_tmp__133));
if (AESL_DEBUG_TRACE)
printf("\n  %%164 = fadd float %%155, %%163, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_363_count);
  llvm_cbe_tmp__134 = (float )((float )(llvm_cbe_tmp__127 + llvm_cbe_tmp__133));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__134, *(int*)(&llvm_cbe_tmp__134));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%164, float* %%48, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_364_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__134;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__134);
  llvm_cbe_tmp__135__PHI_TEMPORARY = (float )llvm_cbe_tmp__134;   /* for PHI node */
  goto llvm_cbe_tmp__166;

llvm_cbe_tmp__167:
if (AESL_DEBUG_TRACE)
printf("\n  %%170 = sext i32 %%167 to i64, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_370_count);
  llvm_cbe_tmp__137 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__136);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum16 = add i64 %%170, %%36, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum16_count);
  llvm_cbe__2e_sum16 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__137&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum16 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum16&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%171 = getelementptr inbounds float* %%m, i64 %%.sum16, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_371_count);
  llvm_cbe_tmp__138 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum16))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum16 = 0x%I64X",((signed long long )llvm_cbe__2e_sum16));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%172 = load float* %%171, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_372_count);
  llvm_cbe_tmp__139 = (float )*llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__139, *(int*)(&llvm_cbe_tmp__139));
if (AESL_DEBUG_TRACE)
printf("\n  %%173 = load float* %%24, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_373_count);
  llvm_cbe_tmp__140 = (float )*llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__140, *(int*)(&llvm_cbe_tmp__140));
if (AESL_DEBUG_TRACE)
printf("\n  %%174 = fmul float %%172, %%173, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__141 = (float )((float )(llvm_cbe_tmp__139 * llvm_cbe_tmp__140));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__141, *(int*)(&llvm_cbe_tmp__141));
if (AESL_DEBUG_TRACE)
printf("\n  %%175 = fadd float %%166, %%174, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__142 = (float )((float )(llvm_cbe_tmp__135 + llvm_cbe_tmp__141));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__142, *(int*)(&llvm_cbe_tmp__142));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%175, float* %%48, align 4, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_376_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__142;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__142);
  llvm_cbe_tmp__143__PHI_TEMPORARY = (float )llvm_cbe_tmp__142;   /* for PHI node */
  goto llvm_cbe_tmp__151;

llvm_cbe_tmp__152:
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%48, align 4, !dbg !12 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_381_count);
  *llvm_cbe_tmp__41 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  goto llvm_cbe_tmp__150;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = sext i32 %%storemerge175 to i64, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_215_count);
  llvm_cbe_tmp__23 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge175);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = mul nsw i64 %%26, %%1, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__24 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__23&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__1&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__24&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add nsw i32 %%storemerge175, -1, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_218_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(llvm_cbe_storemerge175&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__25&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = sext i32 %%29 to i64, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_219_count);
  llvm_cbe_tmp__26 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = mul nsw i64 %%30, %%1, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_220_count);
  llvm_cbe_tmp__27 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__26&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__1&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__27&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add nsw i32 %%storemerge175, 2, !dbg !8 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_221_count);
  llvm_cbe_tmp__28 = (unsigned int )((unsigned int )(llvm_cbe_storemerge175&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__28&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add nsw i32 %%storemerge175, 1, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_223_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(llvm_cbe_storemerge175&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__29&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = sext i32 %%34 to i64, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_224_count);
  llvm_cbe_tmp__30 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = mul nsw i64 %%35, %%1, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_225_count);
  llvm_cbe_tmp__31 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__30&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__1&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = sext i32 %%32 to i64, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__32 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = mul nsw i64 %%37, %%1, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__33 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__32&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__1&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__33&18446744073709551615ull)));
  llvm_cbe_storemerge273__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__147;

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%storemerge77 to i64, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__8 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge77);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = mul i64 %%8, %%11, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__9 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__5&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__8&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum3 = add i64 %%12, %%3, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum3_count);
  llvm_cbe__2e_sum3 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__3&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum3 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum3&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum4 = add i64 %%.sum3, 1, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum4_count);
  llvm_cbe__2e_sum4 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_sum3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum4 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum4&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds float* %%k, i64 %%.sum4, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_159_count);
  llvm_cbe_tmp__10 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum4))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum4 = 0x%I64X",((signed long long )llvm_cbe__2e_sum4));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds float* %%bias, i64 %%11, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_160_count);
  llvm_cbe_tmp__11 = (float *)(&llvm_cbe_bias[(((signed long long )llvm_cbe_tmp__8))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum57 = add i64 %%12, 1, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum57_count);
  llvm_cbe__2e_sum57 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum57 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum57&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds float* %%k, i64 %%.sum57, !dbg !9 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__12 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum57))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum57 = 0x%I64X",((signed long long )llvm_cbe__2e_sum57));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds float* %%k, i64 %%12, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__13 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe_tmp__9))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__9));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds float* %%k, i64 %%.sum3, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__14 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum3))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum3 = 0x%I64X",((signed long long )llvm_cbe__2e_sum3));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum61 = add i64 %%12, 2, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum61_count);
  llvm_cbe__2e_sum61 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum61 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum61&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds float* %%k, i64 %%.sum61, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__15 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum61))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum61 = 0x%I64X",((signed long long )llvm_cbe__2e_sum61));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum64 = add i64 %%.sum3, 2, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum64_count);
  llvm_cbe__2e_sum64 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_sum3&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum64 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum64&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds float* %%k, i64 %%.sum64, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__16 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum64))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum64 = 0x%I64X",((signed long long )llvm_cbe__2e_sum64));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum26 = add i64 %%12, %%9, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum26_count);
  llvm_cbe__2e_sum26 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__6&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum26 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum26&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum27 = add i64 %%.sum26, 1, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum27_count);
  llvm_cbe__2e_sum27 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_sum26&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum27 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum27&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds float* %%k, i64 %%.sum27, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__17 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum27))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum27 = 0x%I64X",((signed long long )llvm_cbe__2e_sum27));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum29 = add i64 %%12, %%10, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum29_count);
  llvm_cbe__2e_sum29 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__7&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum29 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum29&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum30 = add i64 %%.sum29, 1, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum30_count);
  llvm_cbe__2e_sum30 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_sum29&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum30 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum30&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds float* %%k, i64 %%.sum30, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__18 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum30))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum30 = 0x%I64X",((signed long long )llvm_cbe__2e_sum30));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds float* %%k, i64 %%.sum26, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__19 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum26))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum26 = 0x%I64X",((signed long long )llvm_cbe__2e_sum26));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds float* %%k, i64 %%.sum29, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__20 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum29))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum29 = 0x%I64X",((signed long long )llvm_cbe__2e_sum29));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum35 = add i64 %%.sum26, 2, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum35_count);
  llvm_cbe__2e_sum35 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_sum26&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum35 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum35&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds float* %%k, i64 %%.sum35, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__21 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum35))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum35 = 0x%I64X",((signed long long )llvm_cbe__2e_sum35));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum38 = add i64 %%.sum29, 2, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe__2e_sum38_count);
  llvm_cbe__2e_sum38 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_sum29&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum38 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum38&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds float* %%k, i64 %%.sum38, !dbg !10 for 0x%I64xth hint within @convolution1  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__22 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum38))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum38 = 0x%I64X",((signed long long )llvm_cbe__2e_sum38));
}
  llvm_cbe_storemerge175__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  } while (1); /* end of syntactic loop '.preheader74' */
llvm_cbe__2e__crit_edge78:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @convolution1}\n");
  return;
}


void convolution2(signed int llvm_cbe_mRow, signed int llvm_cbe_mCol, signed int llvm_cbe_mDep, float *llvm_cbe_m, signed int llvm_cbe_kRow, signed int llvm_cbe_kCol, signed int llvm_cbe_kNum, float *llvm_cbe_k, float *llvm_cbe_bias, float *llvm_cbe_out) {
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  unsigned long long llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  unsigned long long llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  unsigned long long llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  unsigned long long llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  unsigned long long llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  unsigned long long llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  unsigned long long llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  unsigned long long llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  unsigned long long llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge66_count = 0;
  unsigned int llvm_cbe_storemerge66;
  unsigned int llvm_cbe_storemerge66__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  unsigned long long llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  float *llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  unsigned long long llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_tmp46_count = 0;
  unsigned long long llvm_cbe_tmp46;
  static  unsigned long long aesl_llvm_cbe_tmp47_count = 0;
  unsigned long long llvm_cbe_tmp47;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  unsigned long long llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe__2e_sum19_count = 0;
  unsigned long long llvm_cbe__2e_sum19;
  static  unsigned long long aesl_llvm_cbe__2e_sum23_count = 0;
  unsigned long long llvm_cbe__2e_sum23;
  static  unsigned long long aesl_llvm_cbe__2e_sum35_count = 0;
  unsigned long long llvm_cbe__2e_sum35;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge164_count = 0;
  unsigned int llvm_cbe_storemerge164;
  unsigned int llvm_cbe_storemerge164__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  unsigned long long llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  unsigned long long llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  unsigned int llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  unsigned int llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  unsigned long long llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  unsigned long long llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  unsigned long long llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  unsigned long long llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  unsigned long long llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  unsigned int llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  unsigned long long llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  unsigned long long llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge260_count = 0;
  unsigned int llvm_cbe_storemerge260;
  unsigned int llvm_cbe_storemerge260__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  float llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  unsigned long long llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_tmp_count = 0;
  unsigned long long llvm_cbe_tmp;
  static  unsigned long long aesl_llvm_cbe_tmp39_count = 0;
  unsigned long long llvm_cbe_tmp39;
  static  unsigned long long aesl_llvm_cbe__2e_sum3_count = 0;
  unsigned long long llvm_cbe__2e_sum3;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  float *llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  static  unsigned long long aesl_llvm_cbe_tmp41_count = 0;
  unsigned long long llvm_cbe_tmp41;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
  float llvm_cbe_tmp__197;
  float llvm_cbe_tmp__197__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge457_count = 0;
  unsigned int llvm_cbe_storemerge457;
  unsigned int llvm_cbe_storemerge457__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  unsigned long long llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe__2e_sum34_count = 0;
  unsigned long long llvm_cbe__2e_sum34;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
  float *llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  float llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe__2e_sum36_count = 0;
  unsigned long long llvm_cbe__2e_sum36;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  float *llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  float llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
  float llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  float llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  unsigned int llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond70_count = 0;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  float llvm_cbe_tmp__206;
  float llvm_cbe_tmp__206__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_not_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_not74_count = 0;
  bool llvm_cbe__2e_not74;
  static  unsigned long long aesl_llvm_cbe_brmerge_count = 0;
  bool llvm_cbe_brmerge;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  static  unsigned long long aesl_llvm_cbe_tmp42_count = 0;
  unsigned long long llvm_cbe_tmp42;
  static  unsigned long long aesl_llvm_cbe_tmp43_count = 0;
  unsigned long long llvm_cbe_tmp43;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  float llvm_cbe_tmp__207;
  float llvm_cbe_tmp__207__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge2755_count = 0;
  unsigned int llvm_cbe_storemerge2755;
  unsigned int llvm_cbe_storemerge2755__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
  unsigned long long llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe__2e_sum29_count = 0;
  unsigned long long llvm_cbe__2e_sum29;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  float *llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  float llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe__2e_sum30_count = 0;
  unsigned long long llvm_cbe__2e_sum30;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  float *llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  float llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  float llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  float llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  unsigned int llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond69_count = 0;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  float llvm_cbe_tmp__216;
  float llvm_cbe_tmp__216__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  unsigned long long llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe__2e_sum17_count = 0;
  unsigned long long llvm_cbe__2e_sum17;
  static  unsigned long long aesl_llvm_cbe__2e_sum21_count = 0;
  unsigned long long llvm_cbe__2e_sum21;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  float llvm_cbe_tmp__218;
  float llvm_cbe_tmp__218__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1651_count = 0;
  unsigned int llvm_cbe_storemerge1651;
  unsigned int llvm_cbe_storemerge1651__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  unsigned long long llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe__2e_sum18_count = 0;
  unsigned long long llvm_cbe__2e_sum18;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  float *llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  float llvm_cbe_tmp__221;
  static  unsigned long long aesl_llvm_cbe__2e_sum20_count = 0;
  unsigned long long llvm_cbe__2e_sum20;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  float *llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  float llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  float llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe__2e_sum22_count = 0;
  unsigned long long llvm_cbe__2e_sum22;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  float *llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  float llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe__2e_sum24_count = 0;
  unsigned long long llvm_cbe__2e_sum24;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  float *llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  float llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  float llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  float llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  float llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  unsigned int llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond68_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_not75_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_not76_count = 0;
  bool llvm_cbe__2e_not76;
  static  unsigned long long aesl_llvm_cbe_brmerge77_count = 0;
  bool llvm_cbe_brmerge77;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  static  unsigned long long aesl_llvm_cbe_tmp44_count = 0;
  unsigned long long llvm_cbe_tmp44;
  static  unsigned long long aesl_llvm_cbe_tmp45_count = 0;
  unsigned long long llvm_cbe_tmp45;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  float llvm_cbe_tmp__233;
  float llvm_cbe_tmp__233__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge948_count = 0;
  unsigned int llvm_cbe_storemerge948;
  unsigned int llvm_cbe_storemerge948__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  unsigned long long llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe__2e_sum11_count = 0;
  unsigned long long llvm_cbe__2e_sum11;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  float *llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  float llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe__2e_sum13_count = 0;
  unsigned long long llvm_cbe__2e_sum13;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  float *llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  float llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  float llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  float llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  unsigned int llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  float llvm_cbe_tmp__242;
  float llvm_cbe_tmp__242__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  unsigned int llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond71_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  unsigned int llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond72_count = 0;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  unsigned int llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond73_count = 0;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @convolution2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i32 %%mCol to i6 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_547_count);
  llvm_cbe_tmp__169 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_mCol&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__169);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%mDep to i6 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_548_count);
  llvm_cbe_tmp__170 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_mDep&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__170);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%kRow to i6 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_549_count);
  llvm_cbe_tmp__171 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_kRow&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__171);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i32 %%kCol to i6 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_550_count);
  llvm_cbe_tmp__172 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_kCol&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__172);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i32 %%kNum to i6 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_551_count);
  llvm_cbe_tmp__173 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_kNum&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__173);
  if ((((signed int )llvm_cbe_kNum) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader63_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge67;
  }

llvm_cbe__2e_preheader63_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = mul nuw i64 %%2, %%1, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_573_count);
  llvm_cbe_tmp__174 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__170&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__169&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__174&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = mul i64 %%4, %%3, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_574_count);
  llvm_cbe_tmp__175 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__172&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__171&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__175&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = shl nuw nsw i64 %%4, 1, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_575_count);
  llvm_cbe_tmp__176 = (unsigned long long )llvm_cbe_tmp__172 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__176);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = mul nsw i64 %%4, 3, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_576_count);
  llvm_cbe_tmp__177 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__172&18446744073709551615ull)) * ((unsigned long long )(3ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull)));
  llvm_cbe_storemerge66__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader63;

  do {     /* Syntactic loop '.preheader63' to make GCC happy */
llvm_cbe__2e_preheader63:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge66 = phi i32 [ 0, %%.preheader63.lr.ph ], [ %%91, %%._crit_edge65  for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_storemerge66_count);
  llvm_cbe_storemerge66 = (unsigned int )llvm_cbe_storemerge66__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge66 = 0x%X",llvm_cbe_storemerge66);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__245);
}
  if ((((signed int )llvm_cbe_mRow) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader59_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge65;
  }

llvm_cbe__2e__crit_edge65:
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = add nsw i32 %%storemerge66, 1, !dbg !12 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_851_count);
  llvm_cbe_tmp__245 = (unsigned int )((unsigned int )(llvm_cbe_storemerge66&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__245&4294967295ull)));
  if (((llvm_cbe_tmp__245&4294967295U) == (llvm_cbe_kNum&4294967295U))) {
    goto llvm_cbe__2e__crit_edge67;
  } else {
    llvm_cbe_storemerge66__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__245;   /* for PHI node */
    goto llvm_cbe__2e_preheader63;
  }

  do {     /* Syntactic loop '.preheader59' to make GCC happy */
llvm_cbe__2e_preheader59:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge164 = phi i32 [ 0, %%.preheader59.lr.ph ], [ %%90, %%._crit_edge62  for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_storemerge164_count);
  llvm_cbe_storemerge164 = (unsigned int )llvm_cbe_storemerge164__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge164 = 0x%X",llvm_cbe_storemerge164);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__244);
}
  if ((((signed int )llvm_cbe_mCol) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph61;
  } else {
    goto llvm_cbe__2e__crit_edge62;
  }

llvm_cbe__2e__crit_edge62:
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = add nsw i32 %%storemerge164, 1, !dbg !13 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_831_count);
  llvm_cbe_tmp__244 = (unsigned int )((unsigned int )(llvm_cbe_storemerge164&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__244&4294967295ull)));
  if (((llvm_cbe_tmp__244&4294967295U) == (llvm_cbe_mRow&4294967295U))) {
    goto llvm_cbe__2e__crit_edge65;
  } else {
    llvm_cbe_storemerge164__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__244;   /* for PHI node */
    goto llvm_cbe__2e_preheader59;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__246:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge260 = phi i32 [ 0, %%.lr.ph61 ], [ %%89, %%88  for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_storemerge260_count);
  llvm_cbe_storemerge260 = (unsigned int )llvm_cbe_storemerge260__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge260 = 0x%X",llvm_cbe_storemerge260);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__243);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load float* %%15, align 4, !dbg !12 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_630_count);
  llvm_cbe_tmp__194 = (float )*llvm_cbe_tmp__179;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__194, *(int*)(&llvm_cbe_tmp__194));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%storemerge260 to i64, !dbg !12 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_631_count);
  llvm_cbe_tmp__195 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge260);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__195);
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp = add i64 %%33, %%1 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_tmp_count);
  llvm_cbe_tmp = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__195&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__183&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp39 = mul i64 %%tmp, %% for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_tmp39_count);
  llvm_cbe_tmp39 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__173&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp39 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp39&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum3 = add i64 %%tmp39, %%14, !dbg !12 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum3_count);
  llvm_cbe__2e_sum3 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp39&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__178&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum3 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum3&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds float* %%out, i64 %%.sum3, !dbg !12 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_632_count);
  llvm_cbe_tmp__196 = (float *)(&llvm_cbe_out[(((signed long long )llvm_cbe__2e_sum3))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum3 = 0x%I64X",((signed long long )llvm_cbe__2e_sum3));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%32, float* %%34, align 4, !dbg !12 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_633_count);
  *llvm_cbe_tmp__196 = llvm_cbe_tmp__194;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__194);
  if ((((signed int )llvm_cbe_mDep) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph58;
  } else {
    llvm_cbe_tmp__206__PHI_TEMPORARY = (float )llvm_cbe_tmp__194;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe_tmp__247:
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = add nsw i32 %%storemerge260, 1, !dbg !13 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_814_count);
  llvm_cbe_tmp__243 = (unsigned int )((unsigned int )(llvm_cbe_storemerge260&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__243&4294967295ull)));
  if (((llvm_cbe_tmp__243&4294967295U) == (llvm_cbe_mCol&4294967295U))) {
    goto llvm_cbe__2e__crit_edge62;
  } else {
    llvm_cbe_storemerge260__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__243;   /* for PHI node */
    goto llvm_cbe_tmp__246;
  }

llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = phi float [ %%56, %%74 ], [ %%83, %%75 ], [ %%56, %%.preheader49 ], [ %%72, %%58  for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_809_count);
  llvm_cbe_tmp__242 = (float )llvm_cbe_tmp__242__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__242);
printf("\n = %f",llvm_cbe_tmp__216);
printf("\n = %f",llvm_cbe_tmp__240);
printf("\n = %f",llvm_cbe_tmp__216);
printf("\n = %f",llvm_cbe_tmp__231);
}
  if ((llvm_fcmp_olt(llvm_cbe_tmp__242, 0x0p0))) {
    goto llvm_cbe_tmp__248;
  } else {
    goto llvm_cbe_tmp__247;
  }

llvm_cbe__2e_preheader49:
  if ((((signed int )llvm_cbe_mDep) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph52;
  } else {
    llvm_cbe_tmp__242__PHI_TEMPORARY = (float )llvm_cbe_tmp__216;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe__2e_loopexit54:
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = phi float [ %%45, %%._crit_edge ], [ %%54, %%46  for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_718_count);
  llvm_cbe_tmp__216 = (float )llvm_cbe_tmp__216__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__216);
printf("\n = %f",llvm_cbe_tmp__206);
printf("\n = %f",llvm_cbe_tmp__214);
}
  if ((((signed int )llvm_cbe_tmp__184) < ((signed int )llvm_cbe_mRow))) {
    goto llvm_cbe__2e_preheader49;
  } else {
    goto llvm_cbe_tmp__249;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = phi float [ %%32, %%31 ], [ %%43, %%35  for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_685_count);
  llvm_cbe_tmp__206 = (float )llvm_cbe_tmp__206__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__206);
printf("\n = %f",llvm_cbe_tmp__194);
printf("\n = %f",llvm_cbe_tmp__204);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.not74 = xor i1 %%9, true, !dbg !13 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_not74_count);
  llvm_cbe__2e_not74 = (bool )(((((signed int )llvm_cbe_mDep) > ((signed int )0u)) ^ 1)&1);
if (AESL_DEBUG_TRACE)
printf("\n.not74 = 0x%X\n", llvm_cbe__2e_not74);
if (AESL_DEBUG_TRACE)
printf("\n  %%brmerge = or i1 %%.not, %%.not74, !dbg !13 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_brmerge_count);
  llvm_cbe_brmerge = (bool )(((((signed int )llvm_cbe_storemerge164) < ((signed int )1u)) | llvm_cbe__2e_not74)&1);
if (AESL_DEBUG_TRACE)
printf("\nbrmerge = 0x%X\n", llvm_cbe_brmerge);
  if (llvm_cbe_brmerge) {
    llvm_cbe_tmp__216__PHI_TEMPORARY = (float )llvm_cbe_tmp__206;   /* for PHI node */
    goto llvm_cbe__2e_loopexit54;
  } else {
    goto llvm_cbe__2e_lr_2e_ph56;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__250:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = phi float [ %%32, %%.lr.ph58 ], [ %%43, %%35 ], !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_655_count);
  llvm_cbe_tmp__197 = (float )llvm_cbe_tmp__197__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__197);
printf("\n = %f",llvm_cbe_tmp__194);
printf("\n = %f",llvm_cbe_tmp__204);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge457 = phi i32 [ 0, %%.lr.ph58 ], [ %%44, %%35  for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_storemerge457_count);
  llvm_cbe_storemerge457 = (unsigned int )llvm_cbe_storemerge457__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge457 = 0x%X",llvm_cbe_storemerge457);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__205);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = sext i32 %%storemerge457 to i64, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_656_count);
  llvm_cbe_tmp__198 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge457);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__198);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum34 = add i64 %%tmp41, %%37, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum34_count);
  llvm_cbe__2e_sum34 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp41&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__198&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum34 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum34&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds float* %%m, i64 %%.sum34, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_657_count);
  llvm_cbe_tmp__199 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum34))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum34 = 0x%I64X",((signed long long )llvm_cbe__2e_sum34));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load float* %%38, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_658_count);
  llvm_cbe_tmp__200 = (float )*llvm_cbe_tmp__199;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__200, *(int*)(&llvm_cbe_tmp__200));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum36 = add i64 %%.sum35, %%37, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum36_count);
  llvm_cbe__2e_sum36 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_sum35&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__198&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum36 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum36&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds float* %%k, i64 %%.sum36, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_659_count);
  llvm_cbe_tmp__201 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum36))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum36 = 0x%I64X",((signed long long )llvm_cbe__2e_sum36));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load float* %%40, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_660_count);
  llvm_cbe_tmp__202 = (float )*llvm_cbe_tmp__201;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__202, *(int*)(&llvm_cbe_tmp__202));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = fmul float %%39, %%41, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_661_count);
  llvm_cbe_tmp__203 = (float )((float )(llvm_cbe_tmp__200 * llvm_cbe_tmp__202));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__203, *(int*)(&llvm_cbe_tmp__203));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = fadd float %%36, %%42, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_662_count);
  llvm_cbe_tmp__204 = (float )((float )(llvm_cbe_tmp__197 + llvm_cbe_tmp__203));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__204, *(int*)(&llvm_cbe_tmp__204));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%43, float* %%34, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_663_count);
  *llvm_cbe_tmp__196 = llvm_cbe_tmp__204;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__204);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = add nsw i32 %%storemerge457, 1, !dbg !13 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_664_count);
  llvm_cbe_tmp__205 = (unsigned int )((unsigned int )(llvm_cbe_storemerge457&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__205&4294967295ull)));
  if (((llvm_cbe_tmp__205&4294967295U) == (llvm_cbe_mDep&4294967295U))) {
    llvm_cbe_tmp__206__PHI_TEMPORARY = (float )llvm_cbe_tmp__204;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_tmp__197__PHI_TEMPORARY = (float )llvm_cbe_tmp__204;   /* for PHI node */
    llvm_cbe_storemerge457__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__205;   /* for PHI node */
    goto llvm_cbe_tmp__250;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph58:
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp41 = mul i64 %%tmp, %% for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_tmp41_count);
  llvm_cbe_tmp41 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__170&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp41 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp41&18446744073709551615ull)));
  llvm_cbe_tmp__197__PHI_TEMPORARY = (float )llvm_cbe_tmp__194;   /* for PHI node */
  llvm_cbe_storemerge457__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__250;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__251:
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = phi float [ %%45, %%.lr.ph56 ], [ %%54, %%46 ], !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_688_count);
  llvm_cbe_tmp__207 = (float )llvm_cbe_tmp__207__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__207);
printf("\n = %f",llvm_cbe_tmp__206);
printf("\n = %f",llvm_cbe_tmp__214);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2755 = phi i32 [ 0, %%.lr.ph56 ], [ %%55, %%46  for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_storemerge2755_count);
  llvm_cbe_storemerge2755 = (unsigned int )llvm_cbe_storemerge2755__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2755 = 0x%X",llvm_cbe_storemerge2755);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__215);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = sext i32 %%storemerge2755 to i64, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_689_count);
  llvm_cbe_tmp__208 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge2755);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__208);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum29 = add i64 %%tmp43, %%48, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum29_count);
  llvm_cbe__2e_sum29 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp43&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum29 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum29&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds float* %%m, i64 %%.sum29, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_690_count);
  llvm_cbe_tmp__209 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum29))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum29 = 0x%I64X",((signed long long )llvm_cbe__2e_sum29));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load float* %%49, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_691_count);
  llvm_cbe_tmp__210 = (float )*llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__210, *(int*)(&llvm_cbe_tmp__210));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum30 = add i64 %%48, %%17, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum30_count);
  llvm_cbe__2e_sum30 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__181&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum30 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum30&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds float* %%k, i64 %%.sum30, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_692_count);
  llvm_cbe_tmp__211 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum30))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum30 = 0x%I64X",((signed long long )llvm_cbe__2e_sum30));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load float* %%51, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_693_count);
  llvm_cbe_tmp__212 = (float )*llvm_cbe_tmp__211;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__212, *(int*)(&llvm_cbe_tmp__212));
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = fmul float %%50, %%52, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_694_count);
  llvm_cbe_tmp__213 = (float )((float )(llvm_cbe_tmp__210 * llvm_cbe_tmp__212));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__213, *(int*)(&llvm_cbe_tmp__213));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = fadd float %%47, %%53, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_695_count);
  llvm_cbe_tmp__214 = (float )((float )(llvm_cbe_tmp__207 + llvm_cbe_tmp__213));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__214, *(int*)(&llvm_cbe_tmp__214));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%54, float* %%34, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_696_count);
  *llvm_cbe_tmp__196 = llvm_cbe_tmp__214;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__214);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = add nsw i32 %%storemerge2755, 1, !dbg !13 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_697_count);
  llvm_cbe_tmp__215 = (unsigned int )((unsigned int )(llvm_cbe_storemerge2755&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__215&4294967295ull)));
  if (((llvm_cbe_tmp__215&4294967295U) == (llvm_cbe_mDep&4294967295U))) {
    llvm_cbe_tmp__216__PHI_TEMPORARY = (float )llvm_cbe_tmp__214;   /* for PHI node */
    goto llvm_cbe__2e_loopexit54;
  } else {
    llvm_cbe_tmp__207__PHI_TEMPORARY = (float )llvm_cbe_tmp__214;   /* for PHI node */
    llvm_cbe_storemerge2755__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__215;   /* for PHI node */
    goto llvm_cbe_tmp__251;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph56:
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp42 = add i64 %%33, %%3 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_tmp42_count);
  llvm_cbe_tmp42 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__195&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__193&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp42 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp42&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp43 = mul i64 %%tmp42, %% for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_tmp43_count);
  llvm_cbe_tmp43 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp42&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__170&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp43 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp43&18446744073709551615ull)));
  llvm_cbe_tmp__207__PHI_TEMPORARY = (float )llvm_cbe_tmp__206;   /* for PHI node */
  llvm_cbe_storemerge2755__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__251;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__252:
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = phi float [ %%56, %%.lr.ph52 ], [ %%72, %%58 ], !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_741_count);
  llvm_cbe_tmp__218 = (float )llvm_cbe_tmp__218__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__218);
printf("\n = %f",llvm_cbe_tmp__216);
printf("\n = %f",llvm_cbe_tmp__231);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1651 = phi i32 [ 0, %%.lr.ph52 ], [ %%73, %%58  for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_storemerge1651_count);
  llvm_cbe_storemerge1651 = (unsigned int )llvm_cbe_storemerge1651__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1651 = 0x%X",llvm_cbe_storemerge1651);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__232);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = sext i32 %%storemerge1651 to i64, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_742_count);
  llvm_cbe_tmp__219 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1651);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__219);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum18 = add i64 %%.sum17, %%60, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum18_count);
  llvm_cbe__2e_sum18 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_sum17&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__219&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum18 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum18&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds float* %%m, i64 %%.sum18, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_743_count);
  llvm_cbe_tmp__220 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum18))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum18 = 0x%I64X",((signed long long )llvm_cbe__2e_sum18));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = load float* %%61, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_744_count);
  llvm_cbe_tmp__221 = (float )*llvm_cbe_tmp__220;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__221, *(int*)(&llvm_cbe_tmp__221));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum20 = add i64 %%.sum19, %%60, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum20_count);
  llvm_cbe__2e_sum20 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_sum19&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__219&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum20 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum20&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds float* %%k, i64 %%.sum20, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_745_count);
  llvm_cbe_tmp__222 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum20))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum20 = 0x%I64X",((signed long long )llvm_cbe__2e_sum20));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load float* %%63, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_746_count);
  llvm_cbe_tmp__223 = (float )*llvm_cbe_tmp__222;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__223, *(int*)(&llvm_cbe_tmp__223));
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = fmul float %%62, %%64, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_747_count);
  llvm_cbe_tmp__224 = (float )((float )(llvm_cbe_tmp__221 * llvm_cbe_tmp__223));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__224, *(int*)(&llvm_cbe_tmp__224));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum22 = add i64 %%.sum21, %%60, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum22_count);
  llvm_cbe__2e_sum22 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_sum21&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__219&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum22 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum22&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = getelementptr inbounds float* %%m, i64 %%.sum22, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_748_count);
  llvm_cbe_tmp__225 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum22))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum22 = 0x%I64X",((signed long long )llvm_cbe__2e_sum22));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = load float* %%66, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_749_count);
  llvm_cbe_tmp__226 = (float )*llvm_cbe_tmp__225;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__226, *(int*)(&llvm_cbe_tmp__226));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum24 = add i64 %%.sum23, %%60, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum24_count);
  llvm_cbe__2e_sum24 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_sum23&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__219&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum24 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum24&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = getelementptr inbounds float* %%k, i64 %%.sum24, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_750_count);
  llvm_cbe_tmp__227 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum24))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum24 = 0x%I64X",((signed long long )llvm_cbe__2e_sum24));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = load float* %%68, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_751_count);
  llvm_cbe_tmp__228 = (float )*llvm_cbe_tmp__227;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__228, *(int*)(&llvm_cbe_tmp__228));
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = fmul float %%67, %%69, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_752_count);
  llvm_cbe_tmp__229 = (float )((float )(llvm_cbe_tmp__226 * llvm_cbe_tmp__228));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__229, *(int*)(&llvm_cbe_tmp__229));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = fadd float %%65, %%70, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_753_count);
  llvm_cbe_tmp__230 = (float )((float )(llvm_cbe_tmp__224 + llvm_cbe_tmp__229));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__230, *(int*)(&llvm_cbe_tmp__230));
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = fadd float %%59, %%71, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_754_count);
  llvm_cbe_tmp__231 = (float )((float )(llvm_cbe_tmp__218 + llvm_cbe_tmp__230));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__231, *(int*)(&llvm_cbe_tmp__231));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%72, float* %%34, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_755_count);
  *llvm_cbe_tmp__196 = llvm_cbe_tmp__231;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__231);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = add nsw i32 %%storemerge1651, 1, !dbg !13 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_756_count);
  llvm_cbe_tmp__232 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1651&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__232&4294967295ull)));
  if (((llvm_cbe_tmp__232&4294967295U) == (llvm_cbe_mDep&4294967295U))) {
    llvm_cbe_tmp__242__PHI_TEMPORARY = (float )llvm_cbe_tmp__231;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_tmp__218__PHI_TEMPORARY = (float )llvm_cbe_tmp__231;   /* for PHI node */
    llvm_cbe_storemerge1651__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__232;   /* for PHI node */
    goto llvm_cbe_tmp__252;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph52:
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = mul nsw i64 %%33, %%2, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_739_count);
  llvm_cbe_tmp__217 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__195&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__170&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__217&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum17 = add i64 %%57, %%25, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum17_count);
  llvm_cbe__2e_sum17 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__217&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__188&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum17 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum17&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum21 = add i64 %%57, %%27, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum21_count);
  llvm_cbe__2e_sum21 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__217&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__190&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum21 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum21&18446744073709551615ull)));
  llvm_cbe_tmp__218__PHI_TEMPORARY = (float )llvm_cbe_tmp__216;   /* for PHI node */
  llvm_cbe_storemerge1651__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__252;

llvm_cbe_tmp__249:
if (AESL_DEBUG_TRACE)
printf("\n  %%.not76 = xor i1 %%9, true, !dbg !8 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_not76_count);
  llvm_cbe__2e_not76 = (bool )(((((signed int )llvm_cbe_mDep) > ((signed int )0u)) ^ 1)&1);
if (AESL_DEBUG_TRACE)
printf("\n.not76 = 0x%X\n", llvm_cbe__2e_not76);
if (AESL_DEBUG_TRACE)
printf("\n  %%brmerge77 = or i1 %%.not75, %%.not76, !dbg !8 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_brmerge77_count);
  llvm_cbe_brmerge77 = (bool )(((((signed int )llvm_cbe_tmp__185) >= ((signed int )llvm_cbe_mRow)) | llvm_cbe__2e_not76)&1);
if (AESL_DEBUG_TRACE)
printf("\nbrmerge77 = 0x%X\n", llvm_cbe_brmerge77);
  if (llvm_cbe_brmerge77) {
    llvm_cbe_tmp__242__PHI_TEMPORARY = (float )llvm_cbe_tmp__216;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__253:
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = phi float [ %%56, %%.lr.ph ], [ %%83, %%75 ], !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_779_count);
  llvm_cbe_tmp__233 = (float )llvm_cbe_tmp__233__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__233);
printf("\n = %f",llvm_cbe_tmp__216);
printf("\n = %f",llvm_cbe_tmp__240);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge948 = phi i32 [ 0, %%.lr.ph ], [ %%84, %%75  for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_storemerge948_count);
  llvm_cbe_storemerge948 = (unsigned int )llvm_cbe_storemerge948__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge948 = 0x%X",llvm_cbe_storemerge948);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__241);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = sext i32 %%storemerge948 to i64, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_780_count);
  llvm_cbe_tmp__234 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge948);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__234);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum11 = add i64 %%tmp45, %%77, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum11_count);
  llvm_cbe__2e_sum11 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp45&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__234&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum11 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum11&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = getelementptr inbounds float* %%m, i64 %%.sum11, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_781_count);
  llvm_cbe_tmp__235 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum11))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum11 = 0x%I64X",((signed long long )llvm_cbe__2e_sum11));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = load float* %%78, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_782_count);
  llvm_cbe_tmp__236 = (float )*llvm_cbe_tmp__235;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__236, *(int*)(&llvm_cbe_tmp__236));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum13 = add i64 %%tmp47, %%77, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum13_count);
  llvm_cbe__2e_sum13 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp47&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__234&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum13 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum13&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = getelementptr inbounds float* %%k, i64 %%.sum13, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_783_count);
  llvm_cbe_tmp__237 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum13))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum13 = 0x%I64X",((signed long long )llvm_cbe__2e_sum13));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = load float* %%80, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_784_count);
  llvm_cbe_tmp__238 = (float )*llvm_cbe_tmp__237;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__238, *(int*)(&llvm_cbe_tmp__238));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = fmul float %%79, %%81, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_785_count);
  llvm_cbe_tmp__239 = (float )((float )(llvm_cbe_tmp__236 * llvm_cbe_tmp__238));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__239, *(int*)(&llvm_cbe_tmp__239));
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = fadd float %%76, %%82, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_786_count);
  llvm_cbe_tmp__240 = (float )((float )(llvm_cbe_tmp__233 + llvm_cbe_tmp__239));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__240, *(int*)(&llvm_cbe_tmp__240));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%83, float* %%34, align 4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_787_count);
  *llvm_cbe_tmp__196 = llvm_cbe_tmp__240;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__240);
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = add nsw i32 %%storemerge948, 1, !dbg !13 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_788_count);
  llvm_cbe_tmp__241 = (unsigned int )((unsigned int )(llvm_cbe_storemerge948&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__241&4294967295ull)));
  if (((llvm_cbe_tmp__241&4294967295U) == (llvm_cbe_mDep&4294967295U))) {
    llvm_cbe_tmp__242__PHI_TEMPORARY = (float )llvm_cbe_tmp__240;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_tmp__233__PHI_TEMPORARY = (float )llvm_cbe_tmp__240;   /* for PHI node */
    llvm_cbe_storemerge948__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__241;   /* for PHI node */
    goto llvm_cbe_tmp__253;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp44 = add i64 %%33, %%2 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_tmp44_count);
  llvm_cbe_tmp44 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__195&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__187&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp44 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp44&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp45 = mul i64 %%tmp44, %% for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_tmp45_count);
  llvm_cbe_tmp45 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp44&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__170&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp45 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp45&18446744073709551615ull)));
  llvm_cbe_tmp__233__PHI_TEMPORARY = (float )llvm_cbe_tmp__216;   /* for PHI node */
  llvm_cbe_storemerge948__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__253;

llvm_cbe_tmp__248:
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%34, align 4, !dbg !12 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_812_count);
  *llvm_cbe_tmp__196 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  goto llvm_cbe_tmp__247;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph61:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sext i32 %%storemerge164 to i64, !dbg !12 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_616_count);
  llvm_cbe_tmp__182 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge164);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__182);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = mul i64 %%1, %%18, !dbg !12 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_617_count);
  llvm_cbe_tmp__183 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__169&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__182&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__183&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add nsw i32 %%storemerge164, 2, !dbg !8 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_618_count);
  llvm_cbe_tmp__184 = (unsigned int )((unsigned int )(llvm_cbe_storemerge164&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__184&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add nsw i32 %%storemerge164, 1, !dbg !8 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_620_count);
  llvm_cbe_tmp__185 = (unsigned int )((unsigned int )(llvm_cbe_storemerge164&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__185&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sext i32 %%22 to i64, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_621_count);
  llvm_cbe_tmp__186 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__185);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__186);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = mul i64 %%1, %%23, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_622_count);
  llvm_cbe_tmp__187 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__169&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__186&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__187&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = mul nsw i64 %%23, %%10, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_623_count);
  llvm_cbe_tmp__188 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__186&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__174&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__188&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = sext i32 %%20 to i64, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_624_count);
  llvm_cbe_tmp__189 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__184);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__189);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = mul nsw i64 %%26, %%10, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_625_count);
  llvm_cbe_tmp__190 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__189&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__174&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__190&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%storemerge164, -1, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_626_count);
  llvm_cbe_tmp__191 = (unsigned int )((unsigned int )(llvm_cbe_storemerge164&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__191&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = sext i32 %%28 to i64, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_627_count);
  llvm_cbe_tmp__192 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__191);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__192);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = mul i64 %%1, %%29, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_628_count);
  llvm_cbe_tmp__193 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__169&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__192&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__193&18446744073709551615ull)));
  llvm_cbe_storemerge260__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__246;

  } while (1); /* end of syntactic loop '.preheader59' */
llvm_cbe__2e_preheader59_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i32 %%storemerge66 to i64, !dbg !12 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_596_count);
  llvm_cbe_tmp__178 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge66);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__178);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds float* %%bias, i64 %%14, !dbg !12 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_597_count);
  llvm_cbe_tmp__179 = (float *)(&llvm_cbe_bias[(((signed long long )llvm_cbe_tmp__178))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__178));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = mul i64 %%3, %%14, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_598_count);
  llvm_cbe_tmp__180 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__171&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__178&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__180&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp46 = add i64 %%16,  for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_tmp46_count);
  llvm_cbe_tmp46 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__180&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp46 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp46&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp47 = mul i64 %%tmp46, %% for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_tmp47_count);
  llvm_cbe_tmp47 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp46&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__172&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp47 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp47&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = mul i64 %%11, %%14, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe_599_count);
  llvm_cbe_tmp__181 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__175&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__178&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__181&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum19 = add i64 %%17, %%12, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum19_count);
  llvm_cbe__2e_sum19 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__181&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__176&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum19 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum19&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum23 = add i64 %%17, %%13, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum23_count);
  llvm_cbe__2e_sum23 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__181&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum23 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum23&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum35 = add i64 %%17, %%4, !dbg !10 for 0x%I64xth hint within @convolution2  --> \n", ++aesl_llvm_cbe__2e_sum35_count);
  llvm_cbe__2e_sum35 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__181&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__172&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum35 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum35&18446744073709551615ull)));
  llvm_cbe_storemerge164__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader59;

  } while (1); /* end of syntactic loop '.preheader63' */
llvm_cbe__2e__crit_edge67:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @convolution2}\n");
  return;
}


void maxPool(signed int llvm_cbe_mRow, signed int llvm_cbe_mCol, signed int llvm_cbe_mDep, float *llvm_cbe_m, signed int llvm_cbe_oRow, signed int llvm_cbe_oCol, float *llvm_cbe_out, signed int llvm_cbe_kRow, signed int llvm_cbe_kCol) {
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  unsigned long long llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  unsigned long long llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  unsigned long long llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  unsigned long long llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge9_count = 0;
  unsigned int llvm_cbe_storemerge9;
  unsigned int llvm_cbe_storemerge9__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  unsigned long long llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge1_2e_us;
  unsigned int llvm_cbe_storemerge1_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
  unsigned int llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
  unsigned int llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  unsigned int llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  unsigned long long llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  unsigned long long llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe__2e_sum6_2e_us_count = 0;
  unsigned long long llvm_cbe__2e_sum6_2e_us;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  float *llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge28_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge28_2e_us;
  unsigned int llvm_cbe_storemerge28_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  float llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
  double llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  unsigned long long llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_tmp_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp7_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp7_2e_us;
  static  unsigned long long aesl_llvm_cbe__2e_sum4_2e_us_count = 0;
  unsigned long long llvm_cbe__2e_sum4_2e_us;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  float *llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  float llvm_cbe_tmp__269;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  double llvm_cbe_tmp__270;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  double llvm_cbe_tmp__271;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  float llvm_cbe_tmp__272;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  unsigned int llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  unsigned long long llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  unsigned long long llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe__2e_sum_2e_us_count = 0;
  unsigned long long llvm_cbe__2e_sum_2e_us;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  float *llvm_cbe_tmp__276;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  unsigned long long llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  unsigned long long llvm_cbe_tmp__278;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  unsigned int llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  unsigned int llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  unsigned long long llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  unsigned long long llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe__2e_sum6_count = 0;
  unsigned long long llvm_cbe__2e_sum6;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  float *llvm_cbe_tmp__283;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  unsigned int llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  unsigned int llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @maxPool\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i32 %%mCol to i6 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_896_count);
  llvm_cbe_tmp__254 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_mCol&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__254);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%mDep to i6 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_897_count);
  llvm_cbe_tmp__255 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_mDep&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__255);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%oCol to i6 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_898_count);
  llvm_cbe_tmp__256 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_oCol&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__256);
  if ((((signed int )llvm_cbe_mDep) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge10;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = mul i64 %%3, %%2, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_908_count);
  llvm_cbe_tmp__257 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__256&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__255&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__257&18446744073709551615ull)));
  llvm_cbe_storemerge9__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge9 = phi i32 [ 0, %%.preheader.lr.ph ], [ %%49, %%48  for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_storemerge9_count);
  llvm_cbe_storemerge9 = (unsigned int )llvm_cbe_storemerge9__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge9 = 0x%X",llvm_cbe_storemerge9);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__285);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%storemerge9 to i64, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_911_count);
  llvm_cbe_tmp__258 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge9);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__258);
  if ((((signed int )llvm_cbe_mCol) > ((signed int )0u))) {
    llvm_cbe_storemerge1_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_split_2e_us;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e__2e_preheader_2e_split_crit_edge;
  }

llvm_cbe_tmp__286:
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add nsw i32 %%storemerge9, 1, !dbg !10 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_992_count);
  llvm_cbe_tmp__285 = (unsigned int )((unsigned int )(llvm_cbe_storemerge9&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__285&4294967295ull)));
  if (((llvm_cbe_tmp__285&4294967295U) == (llvm_cbe_mDep&4294967295U))) {
    goto llvm_cbe__2e__crit_edge10;
  } else {
    llvm_cbe_storemerge9__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__285;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe__2e_us_2d_lcssa_2e_us:
  goto llvm_cbe_tmp__286;

  do {     /* Syntactic loop '.preheader.split.us' to make GCC happy */
llvm_cbe__2e_preheader_2e_split_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1.us = phi i32 [ %%9, %%._crit_edge.us ], [ 0, %%.preheader  for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_storemerge1_2e_us_count);
  llvm_cbe_storemerge1_2e_us = (unsigned int )llvm_cbe_storemerge1_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1.us = 0x%X",llvm_cbe_storemerge1_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__259);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1_2e_us) < ((signed int )llvm_cbe_mRow))) {
    goto llvm_cbe_tmp__287;
  } else {
    goto llvm_cbe__2e_us_2d_lcssa_2e_us;
  }

llvm_cbe__2e__crit_edge_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%storemerge1.us, 1, !dbg !10 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_923_count);
  llvm_cbe_tmp__259 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__259&4294967295ull)));
  llvm_cbe_storemerge1_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__259;   /* for PHI node */
  goto llvm_cbe__2e_preheader_2e_split_2e_us;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__288:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge28.us = phi i32 [ 0, %%.lr.ph.us ], [ %%29, %%20  for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_storemerge28_2e_us_count);
  llvm_cbe_storemerge28_2e_us = (unsigned int )llvm_cbe_storemerge28_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge28.us = 0x%X",llvm_cbe_storemerge28_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__273);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load float* %%32, align 4, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_937_count);
  llvm_cbe_tmp__265 = (float )*llvm_cbe_tmp__276;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__265, *(int*)(&llvm_cbe_tmp__265));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = fpext float %%21 to double, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_938_count);
  llvm_cbe_tmp__266 = (double )((double )llvm_cbe_tmp__265);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__266, *(long long*)(&llvm_cbe_tmp__266));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sext i32 %%storemerge28.us to i64, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_939_count);
  llvm_cbe_tmp__267 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge28_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__267);
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp.us = add i64 %%23, %%3 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_tmp_2e_us_count);
  llvm_cbe_tmp_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__267&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__278&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp7.us = mul i64 %%tmp.us, %% for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_tmp7_2e_us_count);
  llvm_cbe_tmp7_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__255&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp7.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp7_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum4.us = add i64 %%tmp7.us, %%7, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe__2e_sum4_2e_us_count);
  llvm_cbe__2e_sum4_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp7_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__258&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum4.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum4_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds float* %%m, i64 %%.sum4.us, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_940_count);
  llvm_cbe_tmp__268 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum4_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum4.us = 0x%I64X",((signed long long )llvm_cbe__2e_sum4_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load float* %%24, align 4, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_941_count);
  llvm_cbe_tmp__269 = (float )*llvm_cbe_tmp__268;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__269, *(int*)(&llvm_cbe_tmp__269));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = fpext float %%25 to double, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_942_count);
  llvm_cbe_tmp__270 = (double )((double )llvm_cbe_tmp__269);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__270, *(long long*)(&llvm_cbe_tmp__270));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = tail call double @fmax(double %%22, double %%26) nounwind, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_943_count);
  llvm_cbe_tmp__271 = (double ) /*tail*/ fmax(llvm_cbe_tmp__266, llvm_cbe_tmp__270);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__266, *(long long*)(&llvm_cbe_tmp__266));
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__270, *(long long*)(&llvm_cbe_tmp__270));
printf("\nReturn  = %lf",llvm_cbe_tmp__271);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = fptrunc double %%27 to float, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_944_count);
  llvm_cbe_tmp__272 = (float )((float )llvm_cbe_tmp__271);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__272, *(int*)(&llvm_cbe_tmp__272));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%28, float* %%32, align 4, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_945_count);
  *llvm_cbe_tmp__276 = llvm_cbe_tmp__272;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__272);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add nsw i32 %%storemerge28.us, 1, !dbg !11 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_946_count);
  llvm_cbe_tmp__273 = (unsigned int )((unsigned int )(llvm_cbe_storemerge28_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__273&4294967295ull)));
  if (((llvm_cbe_tmp__273&4294967295U) == (llvm_cbe_mCol&4294967295U))) {
    goto llvm_cbe__2e__crit_edge_2e_us;
  } else {
    llvm_cbe_storemerge28_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__273;   /* for PHI node */
    goto llvm_cbe_tmp__288;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = sext i32 %%14 to i64, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_956_count);
  llvm_cbe_tmp__274 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__261);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__274);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = mul i64 %%5, %%30, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_957_count);
  llvm_cbe_tmp__275 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__257&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__274&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__275&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum.us = add i64 %%31, %%7, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe__2e_sum_2e_us_count);
  llvm_cbe__2e_sum_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__275&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__258&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds float* %%out, i64 %%.sum.us, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_958_count);
  llvm_cbe_tmp__276 = (float *)(&llvm_cbe_out[(((signed long long )llvm_cbe__2e_sum_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum.us = 0x%I64X",((signed long long )llvm_cbe__2e_sum_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%storemerge1.us to i64, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_959_count);
  llvm_cbe_tmp__277 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__277);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = mul i64 %%1, %%33, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_960_count);
  llvm_cbe_tmp__278 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__254&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__277&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__278&18446744073709551615ull)));
  llvm_cbe_storemerge28_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__288;

llvm_cbe_tmp__289:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = srem i32 %%storemerge1.us, %%kRow, !dbg !10 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_926_count);
  llvm_cbe_tmp__260 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge1_2e_us) % ((signed int )llvm_cbe_kRow)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__260));
  if (((llvm_cbe_tmp__260&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__290;
  } else {
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

llvm_cbe_tmp__287:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sdiv i32 %%storemerge1.us, %%kRow, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_929_count);
  llvm_cbe_tmp__261 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge1_2e_us) / ((signed int )llvm_cbe_kRow)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__261));
  if (((llvm_cbe_tmp__261&4294967295U) == (llvm_cbe_oRow&4294967295U))) {
    goto llvm_cbe__2e_us_2d_lcssa_2e_us;
  } else {
    goto llvm_cbe_tmp__289;
  }

llvm_cbe_tmp__290:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = sext i32 %%14 to i64, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_932_count);
  llvm_cbe_tmp__262 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__261);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__262);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = mul i64 %%5, %%17, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_933_count);
  llvm_cbe_tmp__263 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__257&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__262&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__263&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum6.us = add i64 %%18, %%7, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe__2e_sum6_2e_us_count);
  llvm_cbe__2e_sum6_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__263&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__258&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum6.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum6_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds float* %%out, i64 %%.sum6.us, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_934_count);
  llvm_cbe_tmp__264 = (float *)(&llvm_cbe_out[(((signed long long )llvm_cbe__2e_sum6_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum6.us = 0x%I64X",((signed long long )llvm_cbe__2e_sum6_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%19, align 4, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_935_count);
  *llvm_cbe_tmp__264 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  goto llvm_cbe__2e_lr_2e_ph_2e_us;

  } while (1); /* end of syntactic loop '.preheader.split.us' */
llvm_cbe__2e_us_2d_lcssa:
  goto llvm_cbe_tmp__286;

  do {     /* Syntactic loop '.preheader..preheader.split_crit_edge' to make GCC happy */
llvm_cbe__2e_preheader_2e__2e_preheader_2e_split_crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%47, %%46 ], [ 0, %%.preheader  for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__284);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1) < ((signed int )llvm_cbe_mRow))) {
    goto llvm_cbe_tmp__291;
  } else {
    goto llvm_cbe__2e_us_2d_lcssa;
  }

llvm_cbe_tmp__292:
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = add nsw i32 %%storemerge1, 1, !dbg !10 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_988_count);
  llvm_cbe_tmp__284 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__284&4294967295ull)));
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__284;   /* for PHI node */
  goto llvm_cbe__2e_preheader_2e__2e_preheader_2e_split_crit_edge;

llvm_cbe_tmp__293:
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = srem i32 %%storemerge1, %%kRow, !dbg !10 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_976_count);
  llvm_cbe_tmp__280 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge1) % ((signed int )llvm_cbe_kRow)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__280));
  if (((llvm_cbe_tmp__280&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__294;
  } else {
    goto llvm_cbe_tmp__292;
  }

llvm_cbe_tmp__291:
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = sdiv i32 %%storemerge1, %%kRow, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_973_count);
  llvm_cbe_tmp__279 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge1) / ((signed int )llvm_cbe_kRow)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__279));
  if (((llvm_cbe_tmp__279&4294967295U) == (llvm_cbe_oRow&4294967295U))) {
    goto llvm_cbe__2e_us_2d_lcssa;
  } else {
    goto llvm_cbe_tmp__293;
  }

llvm_cbe_tmp__294:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = sext i32 %%37 to i64, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_979_count);
  llvm_cbe_tmp__281 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__279);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__281);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = mul i64 %%5, %%43, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_980_count);
  llvm_cbe_tmp__282 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__257&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__281&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__282&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum6 = add i64 %%44, %%7, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe__2e_sum6_count);
  llvm_cbe__2e_sum6 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__282&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__258&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum6 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum6&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds float* %%out, i64 %%.sum6, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_981_count);
  llvm_cbe_tmp__283 = (float *)(&llvm_cbe_out[(((signed long long )llvm_cbe__2e_sum6))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum6 = 0x%I64X",((signed long long )llvm_cbe__2e_sum6));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%45, align 4, !dbg !9 for 0x%I64xth hint within @maxPool  --> \n", ++aesl_llvm_cbe_982_count);
  *llvm_cbe_tmp__283 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  goto llvm_cbe_tmp__292;

  } while (1); /* end of syntactic loop '.preheader..preheader.split_crit_edge' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge10:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @maxPool}\n");
  return;
}


void dense1(signed int llvm_cbe_mRow, signed int llvm_cbe_mCol, signed int llvm_cbe_mDep, float *llvm_cbe_m, signed int llvm_cbe_kRow, signed int llvm_cbe_kCol, signed int llvm_cbe_kNum, float *llvm_cbe_k, float *llvm_cbe_bias, signed int llvm_cbe_oSize, float *llvm_cbe_out) {
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  unsigned long long llvm_cbe_tmp__295;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  unsigned long long llvm_cbe_tmp__296;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  unsigned long long llvm_cbe_tmp__297;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  unsigned long long llvm_cbe_tmp__298;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge16_count = 0;
  unsigned int llvm_cbe_storemerge16;
  unsigned int llvm_cbe_storemerge16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  unsigned long long llvm_cbe_tmp__299;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  float *llvm_cbe_tmp__300;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  float llvm_cbe_tmp__301;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  float *llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  unsigned long long llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  float llvm_cbe_tmp__304;
  float llvm_cbe_tmp__304__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge114_count = 0;
  unsigned int llvm_cbe_storemerge114;
  unsigned int llvm_cbe_storemerge114__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  unsigned long long llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  unsigned long long llvm_cbe_tmp__306;
  static  unsigned long long aesl_llvm_cbe_tmp8_count = 0;
  unsigned long long llvm_cbe_tmp8;
  static  unsigned long long aesl_llvm_cbe_tmp9_count = 0;
  unsigned long long llvm_cbe_tmp9;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  unsigned int llvm_cbe_tmp__307;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond20_count = 0;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
  float llvm_cbe_tmp__308;
  float llvm_cbe_tmp__308__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge310_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge310_2e_us;
  unsigned int llvm_cbe_storemerge310_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1075_count = 0;
  unsigned long long llvm_cbe_tmp__309;
  static  unsigned long long aesl_llvm_cbe__2e_sum4_2e_us_count = 0;
  unsigned long long llvm_cbe__2e_sum4_2e_us;
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
  float *llvm_cbe_tmp__310;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
  float llvm_cbe_tmp__311;
  static  unsigned long long aesl_llvm_cbe__2e_sum6_2e_us_count = 0;
  unsigned long long llvm_cbe__2e_sum6_2e_us;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  float *llvm_cbe_tmp__312;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;
  float llvm_cbe_tmp__313;
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
  float llvm_cbe_tmp__314;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  float llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
  unsigned int llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  float llvm_cbe_tmp__317;
  float llvm_cbe_tmp__317__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge212_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge212_2e_us;
  unsigned int llvm_cbe_storemerge212_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  unsigned long long llvm_cbe_tmp__318;
  static  unsigned long long aesl_llvm_cbe_tmp_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp7_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp7_2e_us;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  float llvm_cbe_tmp__319;
  float llvm_cbe_tmp__319__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  unsigned int llvm_cbe_tmp__320;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond22_count = 0;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  float llvm_cbe_tmp__321;
  float llvm_cbe_tmp__321__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  unsigned int llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond23_count = 0;
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @dense1\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i32 %%mCol to i6 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1028_count);
  llvm_cbe_tmp__295 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_mCol&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__295);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%mDep to i6 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1029_count);
  llvm_cbe_tmp__296 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_mDep&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__296);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%kRow to i6 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1030_count);
  llvm_cbe_tmp__297 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_kRow&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__297);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i32 %%kCol to i6 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1031_count);
  llvm_cbe_tmp__298 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_kCol&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__298);
  if ((((signed int )llvm_cbe_kNum) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph18;
  } else {
    goto llvm_cbe__2e__crit_edge19;
  }

llvm_cbe__2e_lr_2e_ph18:
  llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__323;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__323:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge16 = phi i32 [ 0, %%.lr.ph18 ], [ %%38, %%37  for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_storemerge16_count);
  llvm_cbe_storemerge16 = (unsigned int )llvm_cbe_storemerge16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge16 = 0x%X",llvm_cbe_storemerge16);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__322);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%storemerge16 to i64, !dbg !10 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1047_count);
  llvm_cbe_tmp__299 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge16);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__299);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds float* %%bias, i64 %%10, !dbg !10 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1048_count);
  llvm_cbe_tmp__300 = (float *)(&llvm_cbe_bias[(((signed long long )llvm_cbe_tmp__299))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__299));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !10 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1049_count);
  llvm_cbe_tmp__301 = (float )*llvm_cbe_tmp__300;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__301, *(int*)(&llvm_cbe_tmp__301));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds float* %%out, i64 %%10, !dbg !10 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1050_count);
  llvm_cbe_tmp__302 = (float *)(&llvm_cbe_out[(((signed long long )llvm_cbe_tmp__299))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__299));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* %%13, align 4, !dbg !10 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1051_count);
  *llvm_cbe_tmp__302 = llvm_cbe_tmp__301;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__301);
  if ((((signed int )llvm_cbe_mRow) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader11_2e_lr_2e_ph;
  } else {
    llvm_cbe_tmp__321__PHI_TEMPORARY = (float )llvm_cbe_tmp__301;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge15;
  }

llvm_cbe_tmp__324:
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add nsw i32 %%storemerge16, 1, !dbg !11 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1110_count);
  llvm_cbe_tmp__322 = (unsigned int )((unsigned int )(llvm_cbe_storemerge16&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__322&4294967295ull)));
  if (((llvm_cbe_tmp__322&4294967295U) == (llvm_cbe_kNum&4294967295U))) {
    goto llvm_cbe__2e__crit_edge19;
  } else {
    llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__322;   /* for PHI node */
    goto llvm_cbe_tmp__323;
  }

llvm_cbe__2e__crit_edge15:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = phi float [ %%12, %%9 ], [ %%32, %%._crit_edge13  for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1105_count);
  llvm_cbe_tmp__321 = (float )llvm_cbe_tmp__321__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__321);
printf("\n = %f",llvm_cbe_tmp__301);
printf("\n = %f",llvm_cbe_tmp__319);
}
  if ((llvm_fcmp_olt(llvm_cbe_tmp__321, 0x0p0))) {
    goto llvm_cbe_tmp__325;
  } else {
    goto llvm_cbe_tmp__324;
  }

  do {     /* Syntactic loop '.preheader11' to make GCC happy */
llvm_cbe__2e_preheader11:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = phi float [ %%12, %%.preheader11.lr.ph ], [ %%32, %%._crit_edge13  for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1060_count);
  llvm_cbe_tmp__304 = (float )llvm_cbe_tmp__304__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__304);
printf("\n = %f",llvm_cbe_tmp__301);
printf("\n = %f",llvm_cbe_tmp__319);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge114 = phi i32 [ 0, %%.preheader11.lr.ph ], [ %%33, %%._crit_edge13  for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_storemerge114_count);
  llvm_cbe_storemerge114 = (unsigned int )llvm_cbe_storemerge114__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge114 = 0x%X",llvm_cbe_storemerge114);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__320);
}
  if ((((signed int )llvm_cbe_mCol) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    llvm_cbe_tmp__319__PHI_TEMPORARY = (float )llvm_cbe_tmp__304;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge13;
  }

llvm_cbe__2e__crit_edge13:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = phi float [ %%15, %%.preheader11 ], [ %%15, %%.preheader.lr.ph ], [ %%28, %%18  for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1097_count);
  llvm_cbe_tmp__319 = (float )llvm_cbe_tmp__319__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__319);
printf("\n = %f",llvm_cbe_tmp__304);
printf("\n = %f",llvm_cbe_tmp__304);
printf("\n = %f",llvm_cbe_tmp__315);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%storemerge114, 1, !dbg !11 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1098_count);
  llvm_cbe_tmp__320 = (unsigned int )((unsigned int )(llvm_cbe_storemerge114&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__320&4294967295ull)));
  if (((llvm_cbe_tmp__320&4294967295U) == (llvm_cbe_mRow&4294967295U))) {
    llvm_cbe_tmp__321__PHI_TEMPORARY = (float )llvm_cbe_tmp__319;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge15;
  } else {
    llvm_cbe_tmp__304__PHI_TEMPORARY = (float )llvm_cbe_tmp__319;   /* for PHI node */
    llvm_cbe_storemerge114__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__320;   /* for PHI node */
    goto llvm_cbe__2e_preheader11;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%storemerge114 to i64, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1065_count);
  llvm_cbe_tmp__305 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge114);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__305);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = mul i64 %%1, %%16, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1066_count);
  llvm_cbe_tmp__306 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__295&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__305&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__306&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp8 = add i64 %%16, %%1 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_tmp8_count);
  llvm_cbe_tmp8 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__305&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__303&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp8 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp8&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp9 = mul i64 %%tmp8, %% for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_tmp9_count);
  llvm_cbe_tmp9 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp8&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__298&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp9 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp9&18446744073709551615ull)));
  if ((((signed int )llvm_cbe_mDep) > ((signed int )0u))) {
    llvm_cbe_tmp__317__PHI_TEMPORARY = (float )llvm_cbe_tmp__304;   /* for PHI node */
    llvm_cbe_storemerge212_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    llvm_cbe_tmp__319__PHI_TEMPORARY = (float )llvm_cbe_tmp__304;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge13;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = phi float [ %%28, %%18 ], [ %%15, %%.preheader.lr.ph  for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1090_count);
  llvm_cbe_tmp__317 = (float )llvm_cbe_tmp__317__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__317);
printf("\n = %f",llvm_cbe_tmp__315);
printf("\n = %f",llvm_cbe_tmp__304);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge212.us = phi i32 [ %%19, %%18 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_storemerge212_2e_us_count);
  llvm_cbe_storemerge212_2e_us = (unsigned int )llvm_cbe_storemerge212_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge212.us = 0x%X",llvm_cbe_storemerge212_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__307);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = sext i32 %%storemerge212.us to i64, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1095_count);
  llvm_cbe_tmp__318 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge212_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__318);
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp.us = add i64 %%31, %%1 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_tmp_2e_us_count);
  llvm_cbe_tmp_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__318&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__306&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp7.us = mul i64 %%tmp.us, %% for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_tmp7_2e_us_count);
  llvm_cbe_tmp7_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__296&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp7.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp7_2e_us&18446744073709551615ull)));
  llvm_cbe_tmp__308__PHI_TEMPORARY = (float )llvm_cbe_tmp__317;   /* for PHI node */
  llvm_cbe_storemerge310_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__326;

llvm_cbe_tmp__327:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add nsw i32 %%storemerge212.us, 1, !dbg !11 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1068_count);
  llvm_cbe_tmp__307 = (unsigned int )((unsigned int )(llvm_cbe_storemerge212_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__307&4294967295ull)));
  if (((llvm_cbe_tmp__307&4294967295U) == (llvm_cbe_mCol&4294967295U))) {
    llvm_cbe_tmp__319__PHI_TEMPORARY = (float )llvm_cbe_tmp__315;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge13;
  } else {
    llvm_cbe_tmp__317__PHI_TEMPORARY = (float )llvm_cbe_tmp__315;   /* for PHI node */
    llvm_cbe_storemerge212_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__307;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__326:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = phi float [ %%30, %%.lr.ph.us ], [ %%28, %%20 ], !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1074_count);
  llvm_cbe_tmp__308 = (float )llvm_cbe_tmp__308__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__308);
printf("\n = %f",llvm_cbe_tmp__317);
printf("\n = %f",llvm_cbe_tmp__315);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge310.us = phi i32 [ 0, %%.lr.ph.us ], [ %%29, %%20  for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_storemerge310_2e_us_count);
  llvm_cbe_storemerge310_2e_us = (unsigned int )llvm_cbe_storemerge310_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge310.us = 0x%X",llvm_cbe_storemerge310_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__316);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sext i32 %%storemerge310.us to i64, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1075_count);
  llvm_cbe_tmp__309 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge310_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__309);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum4.us = add i64 %%tmp7.us, %%22, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe__2e_sum4_2e_us_count);
  llvm_cbe__2e_sum4_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp7_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__309&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum4.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum4_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds float* %%m, i64 %%.sum4.us, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1076_count);
  llvm_cbe_tmp__310 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_sum4_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum4.us = 0x%I64X",((signed long long )llvm_cbe__2e_sum4_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load float* %%23, align 4, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1077_count);
  llvm_cbe_tmp__311 = (float )*llvm_cbe_tmp__310;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__311, *(int*)(&llvm_cbe_tmp__311));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum6.us = add i64 %%tmp9, %%22, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe__2e_sum6_2e_us_count);
  llvm_cbe__2e_sum6_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp9&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__309&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum6.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum6_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds float* %%k, i64 %%.sum6.us, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1078_count);
  llvm_cbe_tmp__312 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum6_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum6.us = 0x%I64X",((signed long long )llvm_cbe__2e_sum6_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load float* %%25, align 4, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1079_count);
  llvm_cbe_tmp__313 = (float )*llvm_cbe_tmp__312;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__313, *(int*)(&llvm_cbe_tmp__313));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = fmul float %%24, %%26, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1080_count);
  llvm_cbe_tmp__314 = (float )((float )(llvm_cbe_tmp__311 * llvm_cbe_tmp__313));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__314, *(int*)(&llvm_cbe_tmp__314));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = fadd float %%21, %%27, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1081_count);
  llvm_cbe_tmp__315 = (float )((float )(llvm_cbe_tmp__308 + llvm_cbe_tmp__314));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__315, *(int*)(&llvm_cbe_tmp__315));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%28, float* %%13, align 4, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1082_count);
  *llvm_cbe_tmp__302 = llvm_cbe_tmp__315;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__315);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add nsw i32 %%storemerge310.us, 1, !dbg !11 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1083_count);
  llvm_cbe_tmp__316 = (unsigned int )((unsigned int )(llvm_cbe_storemerge310_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__316&4294967295ull)));
  if (((llvm_cbe_tmp__316&4294967295U) == (llvm_cbe_mDep&4294967295U))) {
    goto llvm_cbe_tmp__327;
  } else {
    llvm_cbe_tmp__308__PHI_TEMPORARY = (float )llvm_cbe_tmp__315;   /* for PHI node */
    llvm_cbe_storemerge310_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__316;   /* for PHI node */
    goto llvm_cbe_tmp__326;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  } while (1); /* end of syntactic loop '.preheader11' */
llvm_cbe__2e_preheader11_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = mul i64 %%3, %%10, !dbg !9 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1058_count);
  llvm_cbe_tmp__303 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__297&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__299&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__303&18446744073709551615ull)));
  llvm_cbe_tmp__304__PHI_TEMPORARY = (float )llvm_cbe_tmp__301;   /* for PHI node */
  llvm_cbe_storemerge114__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader11;

llvm_cbe_tmp__325:
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%13, align 4, !dbg !11 for 0x%I64xth hint within @dense1  --> \n", ++aesl_llvm_cbe_1108_count);
  *llvm_cbe_tmp__302 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  goto llvm_cbe_tmp__324;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge19:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @dense1}\n");
  return;
}


void dense2(signed int llvm_cbe_mSize, float *llvm_cbe_m, signed int llvm_cbe_kSize, signed int llvm_cbe_kNum, float *llvm_cbe_k, float *llvm_cbe_bias, signed int llvm_cbe_oSize, float *llvm_cbe_out) {
  static  unsigned long long aesl_llvm_cbe_1122_count = 0;
  static  unsigned long long aesl_llvm_cbe_1123_count = 0;
  static  unsigned long long aesl_llvm_cbe_1124_count = 0;
  static  unsigned long long aesl_llvm_cbe_1125_count = 0;
  static  unsigned long long aesl_llvm_cbe_1126_count = 0;
  static  unsigned long long aesl_llvm_cbe_1127_count = 0;
  static  unsigned long long aesl_llvm_cbe_1128_count = 0;
  static  unsigned long long aesl_llvm_cbe_1129_count = 0;
  static  unsigned long long aesl_llvm_cbe_1130_count = 0;
  static  unsigned long long aesl_llvm_cbe_1131_count = 0;
  static  unsigned long long aesl_llvm_cbe_1132_count = 0;
  static  unsigned long long aesl_llvm_cbe_1133_count = 0;
  static  unsigned long long aesl_llvm_cbe_1134_count = 0;
  static  unsigned long long aesl_llvm_cbe_1135_count = 0;
  static  unsigned long long aesl_llvm_cbe_1136_count = 0;
  static  unsigned long long aesl_llvm_cbe_1137_count = 0;
  static  unsigned long long aesl_llvm_cbe_1138_count = 0;
  unsigned long long llvm_cbe_tmp__328;
  static  unsigned long long aesl_llvm_cbe_1139_count = 0;
  static  unsigned long long aesl_llvm_cbe_1140_count = 0;
  static  unsigned long long aesl_llvm_cbe_1141_count = 0;
  static  unsigned long long aesl_llvm_cbe_1142_count = 0;
  static  unsigned long long aesl_llvm_cbe_1143_count = 0;
  static  unsigned long long aesl_llvm_cbe_1144_count = 0;
  static  unsigned long long aesl_llvm_cbe_1145_count = 0;
  static  unsigned long long aesl_llvm_cbe_1146_count = 0;
  static  unsigned long long aesl_llvm_cbe_1147_count = 0;
  static  unsigned long long aesl_llvm_cbe_1148_count = 0;
  static  unsigned long long aesl_llvm_cbe_1149_count = 0;
  static  unsigned long long aesl_llvm_cbe_1150_count = 0;
  unsigned int llvm_cbe_tmp__329;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond7_count = 0;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
  float llvm_cbe_tmp__330;
  float llvm_cbe_tmp__330__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge12_2e_us;
  unsigned int llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  unsigned long long llvm_cbe_tmp__331;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
  float *llvm_cbe_tmp__332;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  float llvm_cbe_tmp__333;
  static  unsigned long long aesl_llvm_cbe__2e_sum_2e_us_count = 0;
  unsigned long long llvm_cbe__2e_sum_2e_us;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  float *llvm_cbe_tmp__334;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  float llvm_cbe_tmp__335;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  float llvm_cbe_tmp__336;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  float llvm_cbe_tmp__337;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  unsigned int llvm_cbe_tmp__338;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1174_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge3_2e_us;
  unsigned int llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1175_count = 0;
  unsigned long long llvm_cbe_tmp__339;
  static  unsigned long long aesl_llvm_cbe_1176_count = 0;
  float *llvm_cbe_tmp__340;
  static  unsigned long long aesl_llvm_cbe_1177_count = 0;
  float llvm_cbe_tmp__341;
  static  unsigned long long aesl_llvm_cbe_1178_count = 0;
  float *llvm_cbe_tmp__342;
  static  unsigned long long aesl_llvm_cbe_1179_count = 0;
  static  unsigned long long aesl_llvm_cbe_1180_count = 0;
  static  unsigned long long aesl_llvm_cbe_1181_count = 0;
  static  unsigned long long aesl_llvm_cbe_1182_count = 0;
  static  unsigned long long aesl_llvm_cbe_1183_count = 0;
  static  unsigned long long aesl_llvm_cbe_1184_count = 0;
  static  unsigned long long aesl_llvm_cbe_1185_count = 0;
  unsigned long long llvm_cbe_tmp__343;
  static  unsigned long long aesl_llvm_cbe_1186_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1187_count = 0;
  unsigned long long llvm_cbe_tmp__344;
  static  unsigned long long aesl_llvm_cbe_1188_count = 0;
  float *llvm_cbe_tmp__345;
  static  unsigned long long aesl_llvm_cbe_1189_count = 0;
  float llvm_cbe_tmp__346;
  static  unsigned long long aesl_llvm_cbe_1190_count = 0;
  float *llvm_cbe_tmp__347;
  static  unsigned long long aesl_llvm_cbe_1191_count = 0;
  static  unsigned long long aesl_llvm_cbe_1192_count = 0;
  static  unsigned long long aesl_llvm_cbe_1193_count = 0;
  static  unsigned long long aesl_llvm_cbe_1194_count = 0;
  static  unsigned long long aesl_llvm_cbe_1195_count = 0;
  static  unsigned long long aesl_llvm_cbe_1196_count = 0;
  static  unsigned long long aesl_llvm_cbe_1197_count = 0;
  unsigned int llvm_cbe_tmp__348;
  static  unsigned long long aesl_llvm_cbe_1198_count = 0;
  static  unsigned long long aesl_llvm_cbe_1199_count = 0;
  static  unsigned long long aesl_llvm_cbe_1200_count = 0;
  static  unsigned long long aesl_llvm_cbe_1201_count = 0;
  static  unsigned long long aesl_llvm_cbe_1202_count = 0;
  static  unsigned long long aesl_llvm_cbe_1203_count = 0;
  static  unsigned long long aesl_llvm_cbe_1204_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond8_count = 0;
  static  unsigned long long aesl_llvm_cbe_1205_count = 0;
  static  unsigned long long aesl_llvm_cbe_1206_count = 0;
  static  unsigned long long aesl_llvm_cbe_1207_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @dense2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i32 %%kSize to i6 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1138_count);
  llvm_cbe_tmp__328 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_kSize&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__328);
  if ((((signed int )llvm_cbe_kNum) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph5;
  } else {
    goto llvm_cbe_tmp__349;
  }

llvm_cbe__2e_lr_2e_ph5:
  if ((((signed int )llvm_cbe_mSize) > ((signed int )0u))) {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__350;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.us = phi i32 [ %%5, %%4 ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_storemerge3_2e_us_count);
  llvm_cbe_storemerge3_2e_us = (unsigned int )llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%X",llvm_cbe_storemerge3_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__329);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%storemerge3.us to i64, !dbg !9 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1175_count);
  llvm_cbe_tmp__339 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__339);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds float* %%bias, i64 %%16, !dbg !9 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1176_count);
  llvm_cbe_tmp__340 = (float *)(&llvm_cbe_bias[(((signed long long )llvm_cbe_tmp__339))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__339));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* %%17, align 4, !dbg !9 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1177_count);
  llvm_cbe_tmp__341 = (float )*llvm_cbe_tmp__340;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__341, *(int*)(&llvm_cbe_tmp__341));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds float* %%out, i64 %%16, !dbg !9 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1178_count);
  llvm_cbe_tmp__342 = (float *)(&llvm_cbe_out[(((signed long long )llvm_cbe_tmp__339))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__339));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%18, float* %%19, align 4, !dbg !9 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1179_count);
  *llvm_cbe_tmp__342 = llvm_cbe_tmp__341;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__341);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = mul nsw i64 %%16, %%1, !dbg !8 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1185_count);
  llvm_cbe_tmp__343 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__339&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__328&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__343&18446744073709551615ull)));
  llvm_cbe_tmp__330__PHI_TEMPORARY = (float )llvm_cbe_tmp__341;   /* for PHI node */
  llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__351;

llvm_cbe_tmp__352:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add nsw i32 %%storemerge3.us, 1, !dbg !10 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1150_count);
  llvm_cbe_tmp__329 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__329&4294967295ull)));
  if (((llvm_cbe_tmp__329&4294967295U) == (llvm_cbe_kNum&4294967295U))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__329;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__351:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = phi float [ %%18, %%.lr.ph.us ], [ %%14, %%6 ], !dbg !8 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1159_count);
  llvm_cbe_tmp__330 = (float )llvm_cbe_tmp__330__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__330);
printf("\n = %f",llvm_cbe_tmp__341);
printf("\n = %f",llvm_cbe_tmp__337);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i32 [ 0, %%.lr.ph.us ], [ %%15, %%6  for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned int )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__338);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i32 %%storemerge12.us to i64, !dbg !8 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1160_count);
  llvm_cbe_tmp__331 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__331);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds float* %%m, i64 %%8, !dbg !8 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1161_count);
  llvm_cbe_tmp__332 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe_tmp__331))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__331));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* %%9, align 4, !dbg !8 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1162_count);
  llvm_cbe_tmp__333 = (float )*llvm_cbe_tmp__332;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__333, *(int*)(&llvm_cbe_tmp__333));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum.us = add i64 %%8, %%20, !dbg !8 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe__2e_sum_2e_us_count);
  llvm_cbe__2e_sum_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__331&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__343&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds float* %%k, i64 %%.sum.us, !dbg !8 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1163_count);
  llvm_cbe_tmp__334 = (float *)(&llvm_cbe_k[(((signed long long )llvm_cbe__2e_sum_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum.us = 0x%I64X",((signed long long )llvm_cbe__2e_sum_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !8 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1164_count);
  llvm_cbe_tmp__335 = (float )*llvm_cbe_tmp__334;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__335, *(int*)(&llvm_cbe_tmp__335));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = fmul float %%10, %%12, !dbg !8 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1165_count);
  llvm_cbe_tmp__336 = (float )((float )(llvm_cbe_tmp__333 * llvm_cbe_tmp__335));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__336, *(int*)(&llvm_cbe_tmp__336));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = fadd float %%7, %%13, !dbg !8 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1166_count);
  llvm_cbe_tmp__337 = (float )((float )(llvm_cbe_tmp__330 + llvm_cbe_tmp__336));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__337, *(int*)(&llvm_cbe_tmp__337));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%14, float* %%19, align 4, !dbg !8 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1167_count);
  *llvm_cbe_tmp__342 = llvm_cbe_tmp__337;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__337);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge12.us, 1, !dbg !10 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1168_count);
  llvm_cbe_tmp__338 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__338&4294967295ull)));
  if (((llvm_cbe_tmp__338&4294967295U) == (llvm_cbe_mSize&4294967295U))) {
    goto llvm_cbe_tmp__352;
  } else {
    llvm_cbe_tmp__330__PHI_TEMPORARY = (float )llvm_cbe_tmp__337;   /* for PHI node */
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__338;   /* for PHI node */
    goto llvm_cbe_tmp__351;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__350:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ %%26, %%21 ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",llvm_cbe_tmp__348);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sext i32 %%storemerge3 to i64, !dbg !9 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1187_count);
  llvm_cbe_tmp__344 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__344);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds float* %%bias, i64 %%22, !dbg !9 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1188_count);
  llvm_cbe_tmp__345 = (float *)(&llvm_cbe_bias[(((signed long long )llvm_cbe_tmp__344))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__344));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load float* %%23, align 4, !dbg !9 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1189_count);
  llvm_cbe_tmp__346 = (float )*llvm_cbe_tmp__345;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__346, *(int*)(&llvm_cbe_tmp__346));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds float* %%out, i64 %%22, !dbg !9 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1190_count);
  llvm_cbe_tmp__347 = (float *)(&llvm_cbe_out[(((signed long long )llvm_cbe_tmp__344))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__344));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%24, float* %%25, align 4, !dbg !9 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1191_count);
  *llvm_cbe_tmp__347 = llvm_cbe_tmp__346;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__346);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add nsw i32 %%storemerge3, 1, !dbg !10 for 0x%I64xth hint within @dense2  --> \n", ++aesl_llvm_cbe_1197_count);
  llvm_cbe_tmp__348 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__348&4294967295ull)));
  if (((llvm_cbe_tmp__348&4294967295U) == (llvm_cbe_kNum&4294967295U))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__348;   /* for PHI node */
    goto llvm_cbe_tmp__350;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge6:
  goto llvm_cbe_tmp__349;

llvm_cbe_tmp__349:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @dense2}\n");
  return;
}


void softmax(signed int llvm_cbe_mSize, float *llvm_cbe_m, float *llvm_cbe_out) {
  static  unsigned long long aesl_llvm_cbe_1208_count = 0;
  static  unsigned long long aesl_llvm_cbe_1209_count = 0;
  static  unsigned long long aesl_llvm_cbe_1210_count = 0;
  static  unsigned long long aesl_llvm_cbe_1211_count = 0;
  static  unsigned long long aesl_llvm_cbe_1212_count = 0;
  static  unsigned long long aesl_llvm_cbe_1213_count = 0;
  static  unsigned long long aesl_llvm_cbe_1214_count = 0;
  static  unsigned long long aesl_llvm_cbe_1215_count = 0;
  static  unsigned long long aesl_llvm_cbe_1216_count = 0;
  static  unsigned long long aesl_llvm_cbe_1217_count = 0;
  static  unsigned long long aesl_llvm_cbe_1218_count = 0;
  static  unsigned long long aesl_llvm_cbe_1219_count = 0;
  static  unsigned long long aesl_llvm_cbe_1220_count = 0;
  static  unsigned long long aesl_llvm_cbe_1221_count = 0;
  static  unsigned long long aesl_llvm_cbe_1222_count = 0;
  static  unsigned long long aesl_llvm_cbe_1223_count = 0;
  static  unsigned long long aesl_llvm_cbe_1224_count = 0;
  static  unsigned long long aesl_llvm_cbe_1225_count = 0;
  static  unsigned long long aesl_llvm_cbe_1226_count = 0;
  static  unsigned long long aesl_llvm_cbe_1227_count = 0;
  static  unsigned long long aesl_llvm_cbe_1228_count = 0;
  static  unsigned long long aesl_llvm_cbe_1229_count = 0;
  static  unsigned long long aesl_llvm_cbe_1230_count = 0;
  static  unsigned long long aesl_llvm_cbe_1231_count = 0;
  static  unsigned long long aesl_llvm_cbe_1232_count = 0;
  static  unsigned long long aesl_llvm_cbe_1233_count = 0;
  static  unsigned long long aesl_llvm_cbe_1234_count = 0;
  static  unsigned long long aesl_llvm_cbe_1235_count = 0;
  static  unsigned long long aesl_llvm_cbe_1236_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1237_count = 0;
  double llvm_cbe_tmp__353;
  double llvm_cbe_tmp__353__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1238_count = 0;
  unsigned long long llvm_cbe_tmp__354;
  static  unsigned long long aesl_llvm_cbe_1239_count = 0;
  float *llvm_cbe_tmp__355;
  static  unsigned long long aesl_llvm_cbe_1240_count = 0;
  float llvm_cbe_tmp__356;
  static  unsigned long long aesl_llvm_cbe_1241_count = 0;
  double llvm_cbe_tmp__357;
  static  unsigned long long aesl_llvm_cbe_1242_count = 0;
  double llvm_cbe_tmp__358;
  static  unsigned long long aesl_llvm_cbe_1243_count = 0;
  double llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe_1244_count = 0;
  static  unsigned long long aesl_llvm_cbe_1245_count = 0;
  static  unsigned long long aesl_llvm_cbe_1246_count = 0;
  static  unsigned long long aesl_llvm_cbe_1247_count = 0;
  unsigned int llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_1248_count = 0;
  static  unsigned long long aesl_llvm_cbe_1249_count = 0;
  static  unsigned long long aesl_llvm_cbe_1250_count = 0;
  static  unsigned long long aesl_llvm_cbe_1251_count = 0;
  static  unsigned long long aesl_llvm_cbe_1252_count = 0;
  static  unsigned long long aesl_llvm_cbe_1253_count = 0;
  static  unsigned long long aesl_llvm_cbe_1254_count = 0;
  static  unsigned long long aesl_llvm_cbe_1255_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond7_count = 0;
  static  unsigned long long aesl_llvm_cbe_1256_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1257_count = 0;
  unsigned long long llvm_cbe_tmp__361;
  static  unsigned long long aesl_llvm_cbe_1258_count = 0;
  float *llvm_cbe_tmp__362;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
  float llvm_cbe_tmp__363;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
  double llvm_cbe_tmp__364;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
  double llvm_cbe_tmp__365;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  double llvm_cbe_tmp__366;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  float llvm_cbe_tmp__367;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  float *llvm_cbe_tmp__368;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
  unsigned int llvm_cbe_tmp__369;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @softmax\n");
  if ((((signed int )llvm_cbe_mSize) > ((signed int )0u))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_tmp__353__PHI_TEMPORARY = (double )0x0p0;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e_preheader:
  if ((((signed int )llvm_cbe_mSize) > ((signed int )0u))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph5' to make GCC happy */
llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ %%9, %%.lr.ph5 ], [ 0, %%0  for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",llvm_cbe_tmp__360);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = phi double [ %%8, %%.lr.ph5 ], [ 0.000000e+00, %%0  for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1237_count);
  llvm_cbe_tmp__353 = (double )llvm_cbe_tmp__353__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %lf",llvm_cbe_tmp__353);
printf("\n = %lf",llvm_cbe_tmp__359);
printf("\n = %lf",0x0p0);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%storemerge3 to i64, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1238_count);
  llvm_cbe_tmp__354 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__354);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds float* %%m, i64 %%3, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1239_count);
  llvm_cbe_tmp__355 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe_tmp__354))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__354));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load float* %%4, align 4, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1240_count);
  llvm_cbe_tmp__356 = (float )*llvm_cbe_tmp__355;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__356, *(int*)(&llvm_cbe_tmp__356));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = fpext float %%5 to double, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1241_count);
  llvm_cbe_tmp__357 = (double )((double )llvm_cbe_tmp__356);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__357, *(long long*)(&llvm_cbe_tmp__357));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call double @exp(double %%6) nounwind, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1242_count);
  llvm_cbe_tmp__358 = (double ) /*tail*/ exp(llvm_cbe_tmp__357);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__357, *(long long*)(&llvm_cbe_tmp__357));
printf("\nReturn  = %lf",llvm_cbe_tmp__358);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = fadd double %%2, %%7, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1243_count);
  llvm_cbe_tmp__359 = (double )llvm_cbe_tmp__353 + llvm_cbe_tmp__358;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__359, *(long long*)(&llvm_cbe_tmp__359));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%storemerge3, 1, !dbg !9 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1247_count);
  llvm_cbe_tmp__360 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__360&4294967295ull)));
  if (((llvm_cbe_tmp__360&4294967295U) == (llvm_cbe_mSize&4294967295U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__360;   /* for PHI node */
    llvm_cbe_tmp__353__PHI_TEMPORARY = (double )llvm_cbe_tmp__359;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  } while (1); /* end of syntactic loop '.lr.ph5' */
  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%18, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__369);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%storemerge12 to i64, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1257_count);
  llvm_cbe_tmp__361 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__361);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds float* %%m, i64 %%10, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1258_count);
  llvm_cbe_tmp__362 = (float *)(&llvm_cbe_m[(((signed long long )llvm_cbe_tmp__361))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__361));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1259_count);
  llvm_cbe_tmp__363 = (float )*llvm_cbe_tmp__362;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__363, *(int*)(&llvm_cbe_tmp__363));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = fpext float %%12 to double, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1260_count);
  llvm_cbe_tmp__364 = (double )((double )llvm_cbe_tmp__363);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__364, *(long long*)(&llvm_cbe_tmp__364));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = tail call double @exp(double %%13) nounwind, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1261_count);
  llvm_cbe_tmp__365 = (double ) /*tail*/ exp(llvm_cbe_tmp__364);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__364, *(long long*)(&llvm_cbe_tmp__364));
printf("\nReturn  = %lf",llvm_cbe_tmp__365);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fdiv double %%14, %%8, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1262_count);
  llvm_cbe_tmp__366 = (double )llvm_cbe_tmp__365 / llvm_cbe_tmp__359;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__366, *(long long*)(&llvm_cbe_tmp__366));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = fptrunc double %%15 to float, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1263_count);
  llvm_cbe_tmp__367 = (float )((float )llvm_cbe_tmp__366);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__367, *(int*)(&llvm_cbe_tmp__367));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds float* %%out, i64 %%10, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1264_count);
  llvm_cbe_tmp__368 = (float *)(&llvm_cbe_out[(((signed long long )llvm_cbe_tmp__361))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__361));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%16, float* %%17, align 4, !dbg !8 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1265_count);
  *llvm_cbe_tmp__368 = llvm_cbe_tmp__367;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__367);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge12, 1, !dbg !9 for 0x%I64xth hint within @softmax  --> \n", ++aesl_llvm_cbe_1266_count);
  llvm_cbe_tmp__369 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__369&4294967295ull)));
  if (((llvm_cbe_tmp__369&4294967295U) == (llvm_cbe_mSize&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__369;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @softmax}\n");
  return;
}

