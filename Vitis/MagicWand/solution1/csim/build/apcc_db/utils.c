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

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void printData2D(signed int llvm_cbe_row, signed int llvm_cbe_column, float *llvm_cbe_matrix);
void printData3D(signed int llvm_cbe_row, signed int llvm_cbe_column, signed int llvm_cbe_depth, float *llvm_cbe_matrix);
void write2File(float *llvm_cbe_data, signed int llvm_cbe_size,  char *llvm_cbe_fileName);
void compareFiles( char *llvm_cbe_file1Name,  char *llvm_cbe_file2Name);
float fabsf(float );
void twoComplement(float llvm_cbe_val, signed int *llvm_cbe_out);
void twoComplement2File(l_struct_OC__iobuf *llvm_cbe_file, float llvm_cbe_val, signed int *llvm_cbe_out);
float ldexpf(float , signed int );


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str1[7] = "%.4f,\t";
static  char aesl_internal__OC_str2[5] = "%.4f";
static  char aesl_internal__OC_str5[8] = "%.20f,\t";
static  char aesl_internal__OC_str6[6] = "%.20f";
static  char aesl_internal__OC_str8[2] = "w";
static  char aesl_internal__OC_str15[7] = "%.30f\n";
static  char aesl_internal__OC_str10[7] = "%.20f\n";
static  char aesl_internal__OC_str11[2] = "r";
static  char aesl_internal__OC_str12[15] = "ErrorsFile.txt";
static  char aesl_internal__OC_str13[3] = "%s";
static  char aesl_internal__OC_str14[2] = "\n";
static  char aesl_internal__OC_str17[4] = "%d-";
static  char aesl_internal_str2[4] = "],\n";
static  char aesl_internal_str4[28] = "Files with different sizes!";
static  char aesl_internal_str3[20] = "Error opening file!";
static  char aesl_internal_str1[3] = "],";


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

void printData2D(signed int llvm_cbe_row, signed int llvm_cbe_column, float *llvm_cbe_matrix) {
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
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_putchar_count = 0;
  unsigned int llvm_cbe_putchar;
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
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar4_2e_us_count = 0;
  unsigned int llvm_cbe_putchar4_2e_us;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned long long llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe__2e_sum_2e_us_count = 0;
  unsigned long long llvm_cbe__2e_sum_2e_us;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  float *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  float llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  double llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge16_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge16_2e_us;
  unsigned int llvm_cbe_storemerge16_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe__2e_sum2_2e_us_count = 0;
  unsigned long long llvm_cbe__2e_sum2_2e_us;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  float *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  float llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  double llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_2e_us_count = 0;
  unsigned int llvm_cbe_puts_2e_us;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge7_2e_us;
  unsigned int llvm_cbe_storemerge7_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_putchar3_2e_us_count = 0;
  unsigned int llvm_cbe_putchar3_2e_us;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned int llvm_cbe_storemerge7;
  unsigned int llvm_cbe_storemerge7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_putchar3_count = 0;
  unsigned int llvm_cbe_putchar3;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar4_count = 0;
  unsigned int llvm_cbe_putchar4;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond12_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar5_count = 0;
  unsigned int llvm_cbe_putchar5;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @printData2D\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i32 %%column to i6 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__1 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_column&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar = tail call i32 @putchar(i32 91) nounwind, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_putchar_count);
   /*tail*/ putchar(91u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",91u);
printf("\nReturn putchar = 0x%X",llvm_cbe_putchar);
}
  if ((((signed int )llvm_cbe_row) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph9;
  } else {
    goto llvm_cbe_tmp__21;
  }

llvm_cbe__2e_lr_2e_ph9:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%row, -1, !dbg !9 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__2 = (unsigned int )((unsigned int )(llvm_cbe_row&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__2&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add nsw i32 %%column, -1, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__3 = (unsigned int )((unsigned int )(llvm_cbe_column&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__3&4294967295ull)));
  if ((((signed int )llvm_cbe_column) > ((signed int )0u))) {
    llvm_cbe_storemerge7_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__22;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7.us = phi i32 [ %%7, %%6 ], [ 0, %%.lr.ph9  for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_storemerge7_2e_us_count);
  llvm_cbe_storemerge7_2e_us = (unsigned int )llvm_cbe_storemerge7_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7.us = 0x%X",llvm_cbe_storemerge7_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__4);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar3.us = tail call i32 @putchar(i32 91) nounwind, !dbg !11 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_putchar3_2e_us_count);
   /*tail*/ putchar(91u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",91u);
printf("\nReturn putchar3.us = 0x%X",llvm_cbe_putchar3_2e_us);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = sext i32 %%storemerge7.us to i64, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__16 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge7_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = mul nsw i64 %%28, %%1, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__17 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__16&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__1&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__17&18446744073709551615ull)));
  llvm_cbe_storemerge16_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__23;

llvm_cbe_tmp__24:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%storemerge7.us, 1, !dbg !11 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__4 = (unsigned int )((unsigned int )(llvm_cbe_storemerge7_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__4&4294967295ull)));
  if (((llvm_cbe_tmp__4&4294967295U) == (llvm_cbe_row&4294967295U))) {
    goto llvm_cbe__2e__crit_edge10;
  } else {
    llvm_cbe_storemerge7_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__4;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

llvm_cbe_tmp__25:
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar4.us = tail call i32 @putchar(i32 93) nounwind, !dbg !11 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_putchar4_2e_us_count);
   /*tail*/ putchar(93u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",93u);
printf("\nReturn putchar4.us = 0x%X",llvm_cbe_putchar4_2e_us);
}
  goto llvm_cbe_tmp__24;

llvm_cbe_tmp__26:
  if ((((signed int )llvm_cbe_storemerge7_2e_us) < ((signed int )llvm_cbe_tmp__2))) {
    goto llvm_cbe_tmp__27;
  } else {
    goto llvm_cbe_tmp__25;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__23:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge16.us = phi i32 [ 0, %%.lr.ph.us ], [ %%12, %%11  for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_storemerge16_2e_us_count);
  llvm_cbe_storemerge16_2e_us = (unsigned int )llvm_cbe_storemerge16_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge16.us = 0x%X",llvm_cbe_storemerge16_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__5);
}
  if ((((signed int )llvm_cbe_storemerge16_2e_us) < ((signed int )llvm_cbe_tmp__3))) {
    goto llvm_cbe_tmp__28;
  } else {
    goto llvm_cbe_tmp__29;
  }

llvm_cbe_tmp__30:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%storemerge16.us, 1, !dbg !11 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__5 = (unsigned int )((unsigned int )(llvm_cbe_storemerge16_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__5&4294967295ull)));
  if (((llvm_cbe_tmp__5&4294967295U) == (llvm_cbe_column&4294967295U))) {
    goto llvm_cbe_tmp__26;
  } else {
    llvm_cbe_storemerge16_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__5;   /* for PHI node */
    goto llvm_cbe_tmp__23;
  }

llvm_cbe_tmp__29:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i32 %%storemerge16.us to i64, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__6 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge16_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum.us = add i64 %%14, %%29, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe__2e_sum_2e_us_count);
  llvm_cbe__2e_sum_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__6&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__17&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds float* %%matrix, i64 %%.sum.us, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__7 = (float *)(&llvm_cbe_matrix[(((signed long long )llvm_cbe__2e_sum_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum.us = 0x%I64X",((signed long long )llvm_cbe__2e_sum_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load float* %%15, align 4, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__8 = (float )*llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__8, *(int*)(&llvm_cbe_tmp__8));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = fpext float %%16 to double, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__9 = (double )((double )llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__9, *(long long*)(&llvm_cbe_tmp__9));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str2, i64 0, i64 0), double %%17) nounwind, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_47_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__9, *(long long*)(&llvm_cbe_tmp__9));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__10);
}
  goto llvm_cbe_tmp__30;

llvm_cbe_tmp__28:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sext i32 %%storemerge16.us to i64, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__11 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge16_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum2.us = add i64 %%22, %%29, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe__2e_sum2_2e_us_count);
  llvm_cbe__2e_sum2_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__11&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__17&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum2.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum2_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds float* %%matrix, i64 %%.sum2.us, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__12 = (float *)(&llvm_cbe_matrix[(((signed long long )llvm_cbe__2e_sum2_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum2.us = 0x%I64X",((signed long long )llvm_cbe__2e_sum2_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load float* %%23, align 4, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__13 = (float )*llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__13, *(int*)(&llvm_cbe_tmp__13));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = fpext float %%24 to double, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__14 = (double )((double )llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__14, *(long long*)(&llvm_cbe_tmp__14));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str1, i64 0, i64 0), double %%25) nounwind, !dbg !10 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_55_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__14, *(long long*)(&llvm_cbe_tmp__14));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__15);
}
  goto llvm_cbe_tmp__30;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__27:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts.us = tail call i32 @puts(i8* getelementptr inbounds ([3 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !11 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_puts_2e_us_count);
   /*tail*/ puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts.us = 0x%X",llvm_cbe_puts_2e_us);
}
  goto llvm_cbe_tmp__24;

  } while (1); /* end of syntactic loop '.lr.ph.us' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__22:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = phi i32 [ %%35, %%34 ], [ 0, %%.lr.ph9  for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned int )llvm_cbe_storemerge7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%X",llvm_cbe_storemerge7);
printf("\n = 0x%X",llvm_cbe_tmp__18);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar3 = tail call i32 @putchar(i32 91) nounwind, !dbg !11 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_putchar3_count);
   /*tail*/ putchar(91u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",91u);
printf("\nReturn putchar3 = 0x%X",llvm_cbe_putchar3);
}
  if ((((signed int )llvm_cbe_storemerge7) < ((signed int )llvm_cbe_tmp__2))) {
    goto llvm_cbe_tmp__31;
  } else {
    goto llvm_cbe_tmp__32;
  }

llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add nsw i32 %%storemerge7, 1, !dbg !11 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__18 = (unsigned int )((unsigned int )(llvm_cbe_storemerge7&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__18&4294967295ull)));
  if (((llvm_cbe_tmp__18&4294967295U) == (llvm_cbe_row&4294967295U))) {
    goto llvm_cbe__2e__crit_edge10;
  } else {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__18;   /* for PHI node */
    goto llvm_cbe_tmp__22;
  }

llvm_cbe_tmp__31:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = tail call i32 @puts(i8* getelementptr inbounds ([3 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !11 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_puts_count);
   /*tail*/ puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  goto llvm_cbe_tmp__33;

llvm_cbe_tmp__32:
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar4 = tail call i32 @putchar(i32 93) nounwind, !dbg !11 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_putchar4_count);
   /*tail*/ putchar(93u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",93u);
printf("\nReturn putchar4 = 0x%X",llvm_cbe_putchar4);
}
  goto llvm_cbe_tmp__33;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge10:
  goto llvm_cbe_tmp__21;

llvm_cbe_tmp__21:
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar5 = tail call i32 @putchar(i32 93) nounwind, !dbg !11 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_putchar5_count);
   /*tail*/ putchar(93u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",93u);
printf("\nReturn putchar5 = 0x%X",llvm_cbe_putchar5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !11 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__19 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = tail call i32 @fflush(%%struct._iobuf* %%37) nounwind, !dbg !11 for 0x%I64xth hint within @printData2D  --> \n", ++aesl_llvm_cbe_87_count);
   /*tail*/ fflush((l_struct_OC__iobuf *)llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__20);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @printData2D}\n");
  return;
}


void printData3D(signed int llvm_cbe_row, signed int llvm_cbe_column, signed int llvm_cbe_depth, float *llvm_cbe_matrix) {
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
  unsigned long long llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned long long llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_putchar_count = 0;
  unsigned int llvm_cbe_putchar;
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
  unsigned int llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge20_count = 0;
  unsigned int llvm_cbe_storemerge20;
  unsigned int llvm_cbe_storemerge20__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_putchar6_count = 0;
  unsigned int llvm_cbe_putchar6;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  unsigned long long llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond24_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar8_2e_us_count = 0;
  unsigned int llvm_cbe_putchar8_2e_us;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_tmp13_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp13_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp14_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp14_2e_us;
  static  unsigned long long aesl_llvm_cbe__2e_sum3_2e_us_count = 0;
  unsigned long long llvm_cbe__2e_sum3_2e_us;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  float *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  float llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  double llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge215_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge215_2e_us;
  unsigned int llvm_cbe_storemerge215_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  unsigned long long llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_tmp_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp12_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp12_2e_us;
  static  unsigned long long aesl_llvm_cbe__2e_sum5_2e_us_count = 0;
  unsigned long long llvm_cbe__2e_sum5_2e_us;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  float *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  float llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  double llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_2e_us_count = 0;
  unsigned int llvm_cbe_puts_2e_us;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge116_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge116_2e_us;
  unsigned int llvm_cbe_storemerge116_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_putchar7_2e_us_count = 0;
  unsigned int llvm_cbe_putchar7_2e_us;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  unsigned long long llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  unsigned long long llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge116_count = 0;
  unsigned int llvm_cbe_storemerge116;
  unsigned int llvm_cbe_storemerge116__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_putchar7_count = 0;
  unsigned int llvm_cbe_putchar7;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar8_count = 0;
  unsigned int llvm_cbe_putchar8;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond25_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts9_count = 0;
  unsigned int llvm_cbe_puts9;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar10_count = 0;
  unsigned int llvm_cbe_putchar10;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond26_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar11_count = 0;
  unsigned int llvm_cbe_putchar11;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @printData3D\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i32 %%column to i6 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__34 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_column&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%depth to i6 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__35 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_depth&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar = tail call i32 @putchar(i32 91) nounwind, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_putchar_count);
   /*tail*/ putchar(91u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",91u);
printf("\nReturn putchar = 0x%X",llvm_cbe_putchar);
}
  if ((((signed int )llvm_cbe_depth) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph22;
  } else {
    goto llvm_cbe__2e__crit_edge23;
  }

llvm_cbe__2e_lr_2e_ph22:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%row, -1, !dbg !9 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__36 = (unsigned int )((unsigned int )(llvm_cbe_row&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__36&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%column, -1, !dbg !10 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__37 = (unsigned int )((unsigned int )(llvm_cbe_column&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__37&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add nsw i32 %%depth, -1, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__38 = (unsigned int )((unsigned int )(llvm_cbe_depth&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__38&4294967295ull)));
  llvm_cbe_storemerge20__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__58;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__58:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge20 = phi i32 [ 0, %%.lr.ph22 ], [ %%46, %%45  for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_storemerge20_count);
  llvm_cbe_storemerge20 = (unsigned int )llvm_cbe_storemerge20__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge20 = 0x%X",llvm_cbe_storemerge20);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__55);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar6 = tail call i32 @putchar(i32 91) nounwind, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_putchar6_count);
   /*tail*/ putchar(91u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",91u);
printf("\nReturn putchar6 = 0x%X",llvm_cbe_putchar6);
}
  if ((((signed int )llvm_cbe_row) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph18;
  } else {
    goto llvm_cbe_tmp__59;
  }

llvm_cbe_tmp__60:
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add nsw i32 %%storemerge20, 1, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_194_count);
  llvm_cbe_tmp__55 = (unsigned int )((unsigned int )(llvm_cbe_storemerge20&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__55&4294967295ull)));
  if (((llvm_cbe_tmp__55&4294967295U) == (llvm_cbe_depth&4294967295U))) {
    goto llvm_cbe__2e__crit_edge23;
  } else {
    llvm_cbe_storemerge20__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__55;   /* for PHI node */
    goto llvm_cbe_tmp__58;
  }

llvm_cbe_tmp__61:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts9 = tail call i32 @puts(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_str2, i64 0, i64 0)), !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_puts9_count);
   /*tail*/ puts(( char *)((&aesl_internal_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts9 = 0x%X",llvm_cbe_puts9);
}
  goto llvm_cbe_tmp__60;

llvm_cbe_tmp__59:
  if ((((signed int )llvm_cbe_storemerge20) < ((signed int )llvm_cbe_tmp__38))) {
    goto llvm_cbe_tmp__61;
  } else {
    goto llvm_cbe_tmp__62;
  }

llvm_cbe__2e__crit_edge19:
  goto llvm_cbe_tmp__59;

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge116.us = phi i32 [ %%12, %%11 ], [ 0, %%.lr.ph18  for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_storemerge116_2e_us_count);
  llvm_cbe_storemerge116_2e_us = (unsigned int )llvm_cbe_storemerge116_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge116.us = 0x%X",llvm_cbe_storemerge116_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__40);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar7.us = tail call i32 @putchar(i32 91) nounwind, !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_putchar7_2e_us_count);
   /*tail*/ putchar(91u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",91u);
printf("\nReturn putchar7.us = 0x%X",llvm_cbe_putchar7_2e_us);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%storemerge116.us to i64, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__52 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge116_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = mul i64 %%1, %%33, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__53 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__34&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__52&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__53&18446744073709551615ull)));
  llvm_cbe_storemerge215_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__63;

llvm_cbe_tmp__64:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%storemerge116.us, 1, !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__40 = (unsigned int )((unsigned int )(llvm_cbe_storemerge116_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__40&4294967295ull)));
  if (((llvm_cbe_tmp__40&4294967295U) == (llvm_cbe_row&4294967295U))) {
    goto llvm_cbe__2e__crit_edge19;
  } else {
    llvm_cbe_storemerge116_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__40;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

llvm_cbe_tmp__65:
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar8.us = tail call i32 @putchar(i32 93) nounwind, !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_putchar8_2e_us_count);
   /*tail*/ putchar(93u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",93u);
printf("\nReturn putchar8.us = 0x%X",llvm_cbe_putchar8_2e_us);
}
  goto llvm_cbe_tmp__64;

llvm_cbe_tmp__66:
  if ((((signed int )llvm_cbe_storemerge116_2e_us) < ((signed int )llvm_cbe_tmp__36))) {
    goto llvm_cbe_tmp__67;
  } else {
    goto llvm_cbe_tmp__65;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__63:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge215.us = phi i32 [ 0, %%.lr.ph.us ], [ %%17, %%16  for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_storemerge215_2e_us_count);
  llvm_cbe_storemerge215_2e_us = (unsigned int )llvm_cbe_storemerge215_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge215.us = 0x%X",llvm_cbe_storemerge215_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__41);
}
  if ((((signed int )llvm_cbe_storemerge215_2e_us) < ((signed int )llvm_cbe_tmp__37))) {
    goto llvm_cbe_tmp__68;
  } else {
    goto llvm_cbe_tmp__69;
  }

llvm_cbe_tmp__70:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add nsw i32 %%storemerge215.us, 1, !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__41 = (unsigned int )((unsigned int )(llvm_cbe_storemerge215_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__41&4294967295ull)));
  if (((llvm_cbe_tmp__41&4294967295U) == (llvm_cbe_column&4294967295U))) {
    goto llvm_cbe_tmp__66;
  } else {
    llvm_cbe_storemerge215_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__41;   /* for PHI node */
    goto llvm_cbe_tmp__63;
  }

llvm_cbe_tmp__69:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%storemerge215.us to i64, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__42 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge215_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp13.us = add i64 %%19, %%3 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_tmp13_2e_us_count);
  llvm_cbe_tmp13_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__42&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__53&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp13.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp13_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp14.us = mul i64 %%tmp13.us, %% for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_tmp14_2e_us_count);
  llvm_cbe_tmp14_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp13_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__35&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp14.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp14_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum3.us = add i64 %%tmp14.us, %%10, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe__2e_sum3_2e_us_count);
  llvm_cbe__2e_sum3_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp14_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__39&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum3.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum3_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds float* %%matrix, i64 %%.sum3.us, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__43 = (float *)(&llvm_cbe_matrix[(((signed long long )llvm_cbe__2e_sum3_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum3.us = 0x%I64X",((signed long long )llvm_cbe__2e_sum3_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load float* %%20, align 4, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__44 = (float )*llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__44, *(int*)(&llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = fpext float %%21 to double, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__45 = (double )((double )llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__45, *(long long*)(&llvm_cbe_tmp__45));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str6, i64 0, i64 0), double %%22) nounwind, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_151_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__45, *(long long*)(&llvm_cbe_tmp__45));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__46);
}
  goto llvm_cbe_tmp__70;

llvm_cbe_tmp__68:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = sext i32 %%storemerge215.us to i64, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__47 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge215_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp.us = add i64 %%27, %%3 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_tmp_2e_us_count);
  llvm_cbe_tmp_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__47&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__53&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp12.us = mul i64 %%tmp.us, %% for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_tmp12_2e_us_count);
  llvm_cbe_tmp12_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__35&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp12.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp12_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum5.us = add i64 %%tmp12.us, %%10, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe__2e_sum5_2e_us_count);
  llvm_cbe__2e_sum5_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp12_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__39&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum5.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum5_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds float* %%matrix, i64 %%.sum5.us, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__48 = (float *)(&llvm_cbe_matrix[(((signed long long )llvm_cbe__2e_sum5_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum5.us = 0x%I64X",((signed long long )llvm_cbe__2e_sum5_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load float* %%28, align 4, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__49 = (float )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__49, *(int*)(&llvm_cbe_tmp__49));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = fpext float %%29 to double, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__50 = (double )((double )llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__50, *(long long*)(&llvm_cbe_tmp__50));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([8 x i8]* @aesl_internal_.str5, i64 0, i64 0), double %%30) nounwind, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_159_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])), llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__50, *(long long*)(&llvm_cbe_tmp__50));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__51);
}
  goto llvm_cbe_tmp__70;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__67:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts.us = tail call i32 @puts(i8* getelementptr inbounds ([3 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_puts_2e_us_count);
   /*tail*/ puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts.us = 0x%X",llvm_cbe_puts_2e_us);
}
  goto llvm_cbe_tmp__64;

  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e_lr_2e_ph18:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%storemerge20 to i64, !dbg !11 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__39 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge20);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__39);
  if ((((signed int )llvm_cbe_column) > ((signed int )0u))) {
    llvm_cbe_storemerge116_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    llvm_cbe_storemerge116__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__71;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__71:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge116 = phi i32 [ %%40, %%39 ], [ 0, %%.lr.ph18  for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_storemerge116_count);
  llvm_cbe_storemerge116 = (unsigned int )llvm_cbe_storemerge116__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge116 = 0x%X",llvm_cbe_storemerge116);
printf("\n = 0x%X",llvm_cbe_tmp__54);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar7 = tail call i32 @putchar(i32 91) nounwind, !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_putchar7_count);
   /*tail*/ putchar(91u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",91u);
printf("\nReturn putchar7 = 0x%X",llvm_cbe_putchar7);
}
  if ((((signed int )llvm_cbe_storemerge116) < ((signed int )llvm_cbe_tmp__36))) {
    goto llvm_cbe_tmp__72;
  } else {
    goto llvm_cbe_tmp__73;
  }

llvm_cbe_tmp__74:
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add nsw i32 %%storemerge116, 1, !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_181_count);
  llvm_cbe_tmp__54 = (unsigned int )((unsigned int )(llvm_cbe_storemerge116&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__54&4294967295ull)));
  if (((llvm_cbe_tmp__54&4294967295U) == (llvm_cbe_row&4294967295U))) {
    goto llvm_cbe__2e__crit_edge19;
  } else {
    llvm_cbe_storemerge116__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__54;   /* for PHI node */
    goto llvm_cbe_tmp__71;
  }

llvm_cbe_tmp__72:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = tail call i32 @puts(i8* getelementptr inbounds ([3 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_puts_count);
   /*tail*/ puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  goto llvm_cbe_tmp__74;

llvm_cbe_tmp__73:
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar8 = tail call i32 @putchar(i32 93) nounwind, !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_putchar8_count);
   /*tail*/ putchar(93u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",93u);
printf("\nReturn putchar8 = 0x%X",llvm_cbe_putchar8);
}
  goto llvm_cbe_tmp__74;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__62:
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar10 = tail call i32 @putchar(i32 93) nounwind, !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_putchar10_count);
   /*tail*/ putchar(93u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",93u);
printf("\nReturn putchar10 = 0x%X",llvm_cbe_putchar10);
}
  goto llvm_cbe_tmp__60;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge23:
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar11 = tail call i32 @putchar(i32 93) nounwind, !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_putchar11_count);
   /*tail*/ putchar(93u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",93u);
printf("\nReturn putchar11 = 0x%X",llvm_cbe_putchar11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__56 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__56);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = tail call i32 @fflush(%%struct._iobuf* %%47) nounwind, !dbg !12 for 0x%I64xth hint within @printData3D  --> \n", ++aesl_llvm_cbe_203_count);
   /*tail*/ fflush((l_struct_OC__iobuf *)llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__57);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @printData3D}\n");
  return;
}


void write2File(float *llvm_cbe_data, signed int llvm_cbe_size,  char *llvm_cbe_fileName) {
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  unsigned long long llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  float *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  float llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  double llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  unsigned int llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  unsigned int llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @write2File\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call %%struct._iobuf* @fopen(i8* %%fileName, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str8, i64 0, i64 0)) nounwind, !dbg !10 for 0x%I64xth hint within @write2File  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__75 = (l_struct_OC__iobuf *) /*tail*/ aesl_fopen(( char *)llvm_cbe_fileName, ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__75);
}
  if (((llvm_cbe_tmp__75) == (((l_struct_OC__iobuf *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__83;
  } else {
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe__2e_preheader:
  if ((((signed int )llvm_cbe_size) > ((signed int )0u))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe_tmp__83:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = tail call i32 @puts(i8* getelementptr inbounds ([20 x i8]* @aesl_internal_str3, i64 0, i64 0)), !dbg !11 for 0x%I64xth hint within @write2File  --> \n", ++aesl_llvm_cbe_puts_count);
   /*tail*/ puts(( char *)((&aesl_internal_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 20
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @exit(i32 1) noreturn nounwind, !dbg !11 for 0x%I64xth hint within @write2File  --> \n", ++aesl_llvm_cbe_223_count);
   /*tail*/ exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%10, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @write2File  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__81);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%storemerge1 to i64, !dbg !9 for 0x%I64xth hint within @write2File  --> \n", ++aesl_llvm_cbe_225_count);
  llvm_cbe_tmp__76 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds float* %%data, i64 %%5, !dbg !9 for 0x%I64xth hint within @write2File  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__77 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__76))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__76));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load float* %%6, align 4, !dbg !9 for 0x%I64xth hint within @write2File  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__78 = (float )*llvm_cbe_tmp__77;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__78, *(int*)(&llvm_cbe_tmp__78));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = fpext float %%7 to double, !dbg !9 for 0x%I64xth hint within @write2File  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__79 = (double )((double )llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__79, *(long long*)(&llvm_cbe_tmp__79));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str10, i64 0, i64 0), double %%8) nounwind, !dbg !9 for 0x%I64xth hint within @write2File  --> \n", ++aesl_llvm_cbe_229_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__75, ( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), llvm_cbe_tmp__79);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__79, *(long long*)(&llvm_cbe_tmp__79));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__80);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge1, 1, !dbg !10 for 0x%I64xth hint within @write2File  --> \n", ++aesl_llvm_cbe_230_count);
  llvm_cbe_tmp__81 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__81&4294967295ull)));
  if (((llvm_cbe_tmp__81&4294967295U) == (llvm_cbe_size&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__81;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = tail call i32 @fclose(%%struct._iobuf* %%1) nounwind, !dbg !10 for 0x%I64xth hint within @write2File  --> \n", ++aesl_llvm_cbe_236_count);
   /*tail*/ fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__82);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @write2File}\n");
  return;
}


void compareFiles( char *llvm_cbe_file1Name,  char *llvm_cbe_file2Name) {
  static  unsigned long long aesl_llvm_cbe_buffer_count = 0;
   char llvm_cbe_buffer[255];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__86;
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
   char *llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  unsigned int llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  float llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  float llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  float llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  float llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  double llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  unsigned int llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  unsigned int llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  unsigned int llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  unsigned int llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @compareFiles\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call %%struct._iobuf* @fopen(i8* %%file1Name, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str11, i64 0, i64 0)) nounwind, !dbg !9 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__84 = (l_struct_OC__iobuf *)aesl_fopen(( char *)llvm_cbe_file1Name, ( char *)((&aesl_internal__OC_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__84);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call %%struct._iobuf* @fopen(i8* %%file2Name, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str11, i64 0, i64 0)) nounwind, !dbg !9 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__85 = (l_struct_OC__iobuf *)aesl_fopen(( char *)llvm_cbe_file2Name, ( char *)((&aesl_internal__OC_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__85);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call %%struct._iobuf* @fopen(i8* getelementptr inbounds ([15 x i8]* @aesl_internal_.str12, i64 0, i64 0), i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str8, i64 0, i64 0)) nounwind, !dbg !10 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__86 = (l_struct_OC__iobuf *)aesl_fopen(( char *)((&aesl_internal__OC_str12[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 15
#endif
])), ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__86);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [255 x i8]* %%buffer, i64 0, i64 0, !dbg !10 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__87 = ( char *)(&llvm_cbe_buffer[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 255
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe__2e_backedge;

  do {     /* Syntactic loop '.backedge' to make GCC happy */
llvm_cbe__2e_backedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str13, i64 0, i64 0), i8* %%4) nounwind, !dbg !10 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_265_count);
  llvm_cbe_tmp__88 = (unsigned int )fscanf((l_struct_OC__iobuf *)llvm_cbe_tmp__84, ( char *)((&aesl_internal__OC_str13[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), ( char *)llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__88);
}
  if (((llvm_cbe_tmp__88&4294967295U) == (1u&4294967295U))) {
    goto llvm_cbe_tmp__100;
  } else {
    goto llvm_cbe_tmp__101;
  }

llvm_cbe_tmp__102:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i32 @strcmp(i8* %%4, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str14, i64 0, i64 0)) nounwind, !dbg !13 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_274_count);
  llvm_cbe_tmp__91 = (unsigned int )strcmp(( char *)llvm_cbe_tmp__87, ( char *)((&aesl_internal__OC_str14[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__91);
}
  if (((llvm_cbe_tmp__91&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_backedge;
  } else {
    goto llvm_cbe_tmp__103;
  }

llvm_cbe_tmp__100:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call float @strtof(i8* nocapture %%4, i8** null) nounwind, !dbg !13 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_268_count);
  llvm_cbe_tmp__89 = (float )strtof(( char *)llvm_cbe_tmp__87, ( char **)(( char **)/*NULL*/0));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__89);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%2, i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str13, i64 0, i64 0), i8* %%4) nounwind, !dbg !10 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_271_count);
  llvm_cbe_tmp__90 = (unsigned int )fscanf((l_struct_OC__iobuf *)llvm_cbe_tmp__85, ( char *)((&aesl_internal__OC_str13[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), ( char *)llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__90);
}
  if (((llvm_cbe_tmp__90&4294967295U) == (1u&4294967295U))) {
    goto llvm_cbe_tmp__102;
  } else {
    goto llvm_cbe_tmp__104;
  }

llvm_cbe_tmp__103:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = call float @strtof(i8* nocapture %%4, i8** null) nounwind, !dbg !13 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_277_count);
  llvm_cbe_tmp__92 = (float )strtof(( char *)llvm_cbe_tmp__87, ( char **)(( char **)/*NULL*/0));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__92);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = fsub float %%8, %%15, !dbg !13 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_280_count);
  llvm_cbe_tmp__93 = (float )((float )(llvm_cbe_tmp__89 - llvm_cbe_tmp__92));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__93, *(int*)(&llvm_cbe_tmp__93));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = call float @fabsf(float %%16) nounwind, !dbg !13 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_281_count);
  llvm_cbe_tmp__94 = (float )fabsf(llvm_cbe_tmp__93);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__93, *(int*)(&llvm_cbe_tmp__93));
printf("\nReturn  = %f",llvm_cbe_tmp__94);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = fpext float %%17 to double, !dbg !10 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_289_count);
  llvm_cbe_tmp__95 = (double )((double )llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__95, *(long long*)(&llvm_cbe_tmp__95));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%3, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str15, i64 0, i64 0), double %%18) nounwind, !dbg !10 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_290_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__86, ( char *)((&aesl_internal__OC_str15[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), llvm_cbe_tmp__95);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__95, *(long long*)(&llvm_cbe_tmp__95));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__96);
}
  goto llvm_cbe__2e_backedge;

  } while (1); /* end of syntactic loop '.backedge' */
llvm_cbe_tmp__104:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([28 x i8]* @aesl_internal_str4, i64 0, i64 0)), !dbg !14 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  goto llvm_cbe_tmp__105;

llvm_cbe_tmp__101:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = call i32 @fclose(%%struct._iobuf* %%1) nounwind, !dbg !10 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_295_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__97);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = call i32 @fclose(%%struct._iobuf* %%2) nounwind, !dbg !10 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_296_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__98);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call i32 @fclose(%%struct._iobuf* %%3) nounwind, !dbg !11 for 0x%I64xth hint within @compareFiles  --> \n", ++aesl_llvm_cbe_297_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__99);
}
  goto llvm_cbe_tmp__105;

llvm_cbe_tmp__105:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @compareFiles}\n");
  return;
}


void twoComplement(float llvm_cbe_val, signed int *llvm_cbe_out) {
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_val_2e_tr_count = 0;
  float llvm_cbe_val_2e_tr;
  float llvm_cbe_val_2e_tr__PHI_TEMPORARY;
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
  float llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  float llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  float llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  float llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  float llvm_cbe_tmp__110;
  float llvm_cbe_tmp__110__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  float llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  float llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  unsigned int llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  unsigned long long llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  signed int *llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  unsigned int llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  double llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_exp2_count = 0;
  double llvm_cbe_exp2;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  double llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_exp2f_count = 0;
  float llvm_cbe_exp2f;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  float llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @twoComplement\n");
  llvm_cbe_val_2e_tr__PHI_TEMPORARY = (float )llvm_cbe_val;   /* for PHI node */
  goto llvm_cbe_tailrecurse;

  do {     /* Syntactic loop 'tailrecurse' to make GCC happy */
llvm_cbe_tailrecurse:
if (AESL_DEBUG_TRACE)
printf("\n  %%val.tr = phi float [ %%val, %%0 ], [ %%20, %%19  for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_val_2e_tr_count);
  llvm_cbe_val_2e_tr = (float )llvm_cbe_val_2e_tr__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nval.tr = %f",llvm_cbe_val_2e_tr);
printf("\nval = %f",llvm_cbe_val);
printf("\n = %f",llvm_cbe_tmp__119);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call float @floorf(float %%val.tr) nounwind, !dbg !9 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__106 = (float ) /*tail*/ floorf(llvm_cbe_val_2e_tr);
if (AESL_DEBUG_TRACE) {
printf("\nArgument val.tr = %f,  0x%x",llvm_cbe_val_2e_tr, *(int*)(&llvm_cbe_val_2e_tr));
printf("\nReturn  = %f",llvm_cbe_tmp__106);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = fadd float %%1, 5.000000e-01, !dbg !9 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__107 = (float )((float )(llvm_cbe_tmp__106 + 0x1p-1));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__107, *(int*)(&llvm_cbe_tmp__107));
  if ((llvm_fcmp_olt(llvm_cbe_tmp__107, llvm_cbe_val_2e_tr))) {
    goto llvm_cbe_tmp__120;
  } else {
    goto llvm_cbe_tmp__121;
  }

llvm_cbe_tmp__122:
if (AESL_DEBUG_TRACE)
printf("\n  %%exp2f = tail call float @ldexpf(float 1.000000e+00, i32 %%12) nounwind, !dbg !10 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_exp2f_count);
  llvm_cbe_exp2f = (float ) /*tail*/ ldexpf(0x1p0, llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f",0x1p0);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__113);
printf("\nReturn exp2f = %f",llvm_cbe_exp2f);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = fsub float %%9, %%exp2f, !dbg !10 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_345_count);
  llvm_cbe_tmp__119 = (float )((float )(llvm_cbe_tmp__110 - llvm_cbe_exp2f));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__119, *(int*)(&llvm_cbe_tmp__119));
  llvm_cbe_val_2e_tr__PHI_TEMPORARY = (float )llvm_cbe_tmp__119;   /* for PHI node */
  goto llvm_cbe_tailrecurse;

llvm_cbe_tmp__123:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = phi float [ %%5, %%4 ], [ %%7, %%6 ], !dbg !9 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_320_count);
  llvm_cbe_tmp__110 = (float )llvm_cbe_tmp__110__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__110);
printf("\n = %f",llvm_cbe_tmp__108);
printf("\n = %f",llvm_cbe_tmp__109);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call float @log2f(float %%9) nounwind, !dbg !9 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_329_count);
  llvm_cbe_tmp__111 = (float ) /*tail*/ log2f(llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__110, *(int*)(&llvm_cbe_tmp__110));
printf("\nReturn  = %f",llvm_cbe_tmp__111);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = tail call float @floorf(float %%10) nounwind, !dbg !9 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_330_count);
  llvm_cbe_tmp__112 = (float ) /*tail*/ floorf(llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__111, *(int*)(&llvm_cbe_tmp__111));
printf("\nReturn  = %f",llvm_cbe_tmp__112);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = fptosi float %%11 to i32, !dbg !9 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_331_count);
  llvm_cbe_tmp__113 = (unsigned int )((signed int )llvm_cbe_tmp__112&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i32 %%12 to i64, !dbg !10 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_337_count);
  llvm_cbe_tmp__114 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i32* %%out, i64 %%13, !dbg !10 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_338_count);
  llvm_cbe_tmp__115 = (signed int *)(&llvm_cbe_out[(((signed long long )llvm_cbe_tmp__114))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__114));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%14, align 4, !dbg !10 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_339_count);
  *llvm_cbe_tmp__115 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str17, i64 0, i64 0), i32 %%12) nounwind, !dbg !10 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_340_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str17[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__113);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__116);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = fpext float %%9 to double, !dbg !10 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_341_count);
  llvm_cbe_tmp__117 = (double )((double )llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__117, *(long long*)(&llvm_cbe_tmp__117));
if (AESL_DEBUG_TRACE)
printf("\n  %%exp2 = tail call double @ldexp(double 1.000000e+00, i32 %%12) nounwind, !dbg !10 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_exp2_count);
  llvm_cbe_exp2 = (double ) /*tail*/ ldexp(0x1p0, llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf",0x1p0);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__113);
printf("\nReturn exp2 = %lf",llvm_cbe_exp2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = fsub double %%16, %%exp2, !dbg !10 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_342_count);
  llvm_cbe_tmp__118 = (double )llvm_cbe_tmp__117 - llvm_cbe_exp2;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__118, *(long long*)(&llvm_cbe_tmp__118));
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__118, 0x0p0))) {
    goto llvm_cbe_tmp__122;
  } else {
    goto llvm_cbe_tmp__124;
  }

llvm_cbe_tmp__120:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call float @ceilf(float %%val.tr) nounwind, !dbg !9 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_316_count);
  llvm_cbe_tmp__108 = (float ) /*tail*/ ceilf(llvm_cbe_val_2e_tr);
if (AESL_DEBUG_TRACE) {
printf("\nArgument val.tr = %f,  0x%x",llvm_cbe_val_2e_tr, *(int*)(&llvm_cbe_val_2e_tr));
printf("\nReturn  = %f",llvm_cbe_tmp__108);
}
  llvm_cbe_tmp__110__PHI_TEMPORARY = (float )llvm_cbe_tmp__108;   /* for PHI node */
  goto llvm_cbe_tmp__123;

llvm_cbe_tmp__121:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call float @floorf(float %%val.tr) nounwind, !dbg !9 for 0x%I64xth hint within @twoComplement  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__109 = (float ) /*tail*/ floorf(llvm_cbe_val_2e_tr);
if (AESL_DEBUG_TRACE) {
printf("\nArgument val.tr = %f,  0x%x",llvm_cbe_val_2e_tr, *(int*)(&llvm_cbe_val_2e_tr));
printf("\nReturn  = %f",llvm_cbe_tmp__109);
}
  llvm_cbe_tmp__110__PHI_TEMPORARY = (float )llvm_cbe_tmp__109;   /* for PHI node */
  goto llvm_cbe_tmp__123;

  } while (1); /* end of syntactic loop 'tailrecurse' */
llvm_cbe_tmp__124:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @twoComplement}\n");
  return;
}


void twoComplement2File(l_struct_OC__iobuf *llvm_cbe_file, float llvm_cbe_val, signed int *llvm_cbe_out) {
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_val_2e_tr_count = 0;
  float llvm_cbe_val_2e_tr;
  float llvm_cbe_val_2e_tr__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  float llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  float llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  float llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  float llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  float llvm_cbe_tmp__129;
  float llvm_cbe_tmp__129__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  float llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  float llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  unsigned int llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  unsigned long long llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  signed int *llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  unsigned int llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  double llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_exp2_count = 0;
  double llvm_cbe_exp2;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  double llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_exp2f_count = 0;
  float llvm_cbe_exp2f;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  float llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @twoComplement2File\n");
  llvm_cbe_val_2e_tr__PHI_TEMPORARY = (float )llvm_cbe_val;   /* for PHI node */
  goto llvm_cbe_tailrecurse;

  do {     /* Syntactic loop 'tailrecurse' to make GCC happy */
llvm_cbe_tailrecurse:
if (AESL_DEBUG_TRACE)
printf("\n  %%val.tr = phi float [ %%val, %%0 ], [ %%20, %%19  for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_val_2e_tr_count);
  llvm_cbe_val_2e_tr = (float )llvm_cbe_val_2e_tr__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nval.tr = %f",llvm_cbe_val_2e_tr);
printf("\nval = %f",llvm_cbe_val);
printf("\n = %f",llvm_cbe_tmp__138);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call float @floorf(float %%val.tr) nounwind, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_363_count);
  llvm_cbe_tmp__125 = (float ) /*tail*/ floorf(llvm_cbe_val_2e_tr);
if (AESL_DEBUG_TRACE) {
printf("\nArgument val.tr = %f,  0x%x",llvm_cbe_val_2e_tr, *(int*)(&llvm_cbe_val_2e_tr));
printf("\nReturn  = %f",llvm_cbe_tmp__125);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = fadd float %%1, 5.000000e-01, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__126 = (float )((float )(llvm_cbe_tmp__125 + 0x1p-1));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__126, *(int*)(&llvm_cbe_tmp__126));
  if ((llvm_fcmp_olt(llvm_cbe_tmp__126, llvm_cbe_val_2e_tr))) {
    goto llvm_cbe_tmp__139;
  } else {
    goto llvm_cbe_tmp__140;
  }

llvm_cbe_tmp__141:
if (AESL_DEBUG_TRACE)
printf("\n  %%exp2f = tail call float @ldexpf(float 1.000000e+00, i32 %%12) nounwind, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_exp2f_count);
  llvm_cbe_exp2f = (float ) /*tail*/ ldexpf(0x1p0, llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f",0x1p0);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__132);
printf("\nReturn exp2f = %f",llvm_cbe_exp2f);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = fsub float %%9, %%exp2f, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_396_count);
  llvm_cbe_tmp__138 = (float )((float )(llvm_cbe_tmp__129 - llvm_cbe_exp2f));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__138, *(int*)(&llvm_cbe_tmp__138));
  llvm_cbe_val_2e_tr__PHI_TEMPORARY = (float )llvm_cbe_tmp__138;   /* for PHI node */
  goto llvm_cbe_tailrecurse;

llvm_cbe_tmp__142:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = phi float [ %%5, %%4 ], [ %%7, %%6 ], !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_371_count);
  llvm_cbe_tmp__129 = (float )llvm_cbe_tmp__129__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__129);
printf("\n = %f",llvm_cbe_tmp__127);
printf("\n = %f",llvm_cbe_tmp__128);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call float @log2f(float %%9) nounwind, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_380_count);
  llvm_cbe_tmp__130 = (float ) /*tail*/ log2f(llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__129, *(int*)(&llvm_cbe_tmp__129));
printf("\nReturn  = %f",llvm_cbe_tmp__130);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = tail call float @floorf(float %%10) nounwind, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_381_count);
  llvm_cbe_tmp__131 = (float ) /*tail*/ floorf(llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__130, *(int*)(&llvm_cbe_tmp__130));
printf("\nReturn  = %f",llvm_cbe_tmp__131);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = fptosi float %%11 to i32, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_382_count);
  llvm_cbe_tmp__132 = (unsigned int )((signed int )llvm_cbe_tmp__131&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i32 %%12 to i64, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_388_count);
  llvm_cbe_tmp__133 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i32* %%out, i64 %%13, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_389_count);
  llvm_cbe_tmp__134 = (signed int *)(&llvm_cbe_out[(((signed long long )llvm_cbe_tmp__133))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__133));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%14, align 4, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_390_count);
  *llvm_cbe_tmp__134 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%file, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str17, i64 0, i64 0), i32 %%12) nounwind, !dbg !9 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_391_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_file, ( char *)((&aesl_internal__OC_str17[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__132);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__135);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = fpext float %%9 to double, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_392_count);
  llvm_cbe_tmp__136 = (double )((double )llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__136, *(long long*)(&llvm_cbe_tmp__136));
if (AESL_DEBUG_TRACE)
printf("\n  %%exp2 = tail call double @ldexp(double 1.000000e+00, i32 %%12) nounwind, !dbg !11 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_exp2_count);
  llvm_cbe_exp2 = (double ) /*tail*/ ldexp(0x1p0, llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf",0x1p0);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__132);
printf("\nReturn exp2 = %lf",llvm_cbe_exp2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = fsub double %%16, %%exp2, !dbg !11 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_393_count);
  llvm_cbe_tmp__137 = (double )llvm_cbe_tmp__136 - llvm_cbe_exp2;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__137, *(long long*)(&llvm_cbe_tmp__137));
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__137, 0x0p0))) {
    goto llvm_cbe_tmp__141;
  } else {
    goto llvm_cbe_tmp__143;
  }

llvm_cbe_tmp__139:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call float @ceilf(float %%val.tr) nounwind, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_367_count);
  llvm_cbe_tmp__127 = (float ) /*tail*/ ceilf(llvm_cbe_val_2e_tr);
if (AESL_DEBUG_TRACE) {
printf("\nArgument val.tr = %f,  0x%x",llvm_cbe_val_2e_tr, *(int*)(&llvm_cbe_val_2e_tr));
printf("\nReturn  = %f",llvm_cbe_tmp__127);
}
  llvm_cbe_tmp__129__PHI_TEMPORARY = (float )llvm_cbe_tmp__127;   /* for PHI node */
  goto llvm_cbe_tmp__142;

llvm_cbe_tmp__140:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call float @floorf(float %%val.tr) nounwind, !dbg !10 for 0x%I64xth hint within @twoComplement2File  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__128 = (float ) /*tail*/ floorf(llvm_cbe_val_2e_tr);
if (AESL_DEBUG_TRACE) {
printf("\nArgument val.tr = %f,  0x%x",llvm_cbe_val_2e_tr, *(int*)(&llvm_cbe_val_2e_tr));
printf("\nReturn  = %f",llvm_cbe_tmp__128);
}
  llvm_cbe_tmp__129__PHI_TEMPORARY = (float )llvm_cbe_tmp__128;   /* for PHI node */
  goto llvm_cbe_tmp__142;

  } while (1); /* end of syntactic loop 'tailrecurse' */
llvm_cbe_tmp__143:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @twoComplement2File}\n");
  return;
}

