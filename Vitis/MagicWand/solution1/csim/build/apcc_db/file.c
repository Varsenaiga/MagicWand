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
l_struct_OC__iobuf *openFile( char *llvm_cbe_name,  char *llvm_cbe_mode);
void closeFile(l_struct_OC__iobuf *llvm_cbe_file);
void readFile(l_struct_OC__iobuf *llvm_cbe_file);
void master(float (*)[3], float (*)[4]);
void printData2D(signed int , signed int , float *);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str1[9] = "test.txt";
static  char aesl_internal__OC_str2[2] = "w";
static  char aesl_internal__OC_str6[7] = "%.30f\n";
static  char aesl_internal__OC_str7[2] = "\n";
static  char aesl_internal__OC_str8[8] = " -,-,-\n";
static  char aesl_internal__OC_str9[7] = "-,-,-\n";
static  char aesl_internal__OC_str10[2] = ",";
static  char aesl_internal_str[22] = "File can't be opened ";
static  char aesl_internal_str1[20] = "Error opening file!";
static  char aesl_internal_str2[6] = "\nOut:";
static  char aesl_internal_str3[4] = "\n\n\n";


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
printf("\n  %%1 = tail call %%struct._iobuf* @fopen(i8* %%name, i8* %%mode) nounwind, !dbg !5 for 0x%I64xth hint within @openFile  --> \n", ++aesl_llvm_cbe_5_count);
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
printf("\n  %%puts = tail call i32 @puts(i8* getelementptr inbounds ([22 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !6 for 0x%I64xth hint within @openFile  --> \n", ++aesl_llvm_cbe_puts_count);
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
printf("\n  %%1 = tail call i32 @fclose(%%struct._iobuf* %%file) nounwind, !dbg !5 for 0x%I64xth hint within @closeFile  --> \n", ++aesl_llvm_cbe_15_count);
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
  float (*llvm_cbe_tmp__8)[3];
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  float (*llvm_cbe_tmp__9)[4];
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  float *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge26_count = 0;
  unsigned int llvm_cbe_storemerge26;
  unsigned int llvm_cbe_storemerge26__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  float *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  float *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  float *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_exitcond28_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1922_count = 0;
  bool llvm_cbe_storemerge1922;
  bool llvm_cbe_storemerge1922__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge191021_count = 0;
  bool llvm_cbe_storemerge191021;
  bool llvm_cbe_storemerge191021__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  unsigned int llvm_cbe_tmp__16;
  unsigned int llvm_cbe_tmp__16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1910_2e_not_count = 0;
  bool llvm_cbe_storemerge1910_2e_not;
  static  unsigned long long aesl_llvm_cbe_brmerge_count = 0;
  bool llvm_cbe_brmerge;
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
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge217_count = 0;
  unsigned int llvm_cbe_storemerge217;
  unsigned int llvm_cbe_storemerge217__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  float *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  float llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned long long llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  float *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  float *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  float llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  float *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  float *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  float llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  float *llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_exitcond27_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge315_count = 0;
  unsigned int llvm_cbe_storemerge315;
  unsigned int llvm_cbe_storemerge315__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  float *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  float *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  float *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned int llvm_cbe_tmp__36;
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
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts11_count = 0;
  unsigned int llvm_cbe_puts11;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts12_count = 0;
  unsigned int llvm_cbe_puts12;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
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
  float llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  double llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  unsigned int llvm_cbe_tmp__39;
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
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
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
  float *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  float llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  double llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  unsigned int llvm_cbe_tmp__43;
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
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
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
  float *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  float llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  double llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  unsigned int llvm_cbe_tmp__47;
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
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
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
  float *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  float llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  double llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  unsigned int llvm_cbe_tmp__51;
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
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_count = 0;
  unsigned int llvm_cbe_fputc;
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
   char *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
   char *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  unsigned int llvm_cbe_tmp__54;
  unsigned int llvm_cbe_tmp__54__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  unsigned int llvm_cbe_tmp__56;
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
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1922_2e_not_count = 0;
  bool llvm_cbe_storemerge1922_2e_not;
  static  unsigned long long aesl_llvm_cbe_brmerge29_count = 0;
  bool llvm_cbe_brmerge29;
  static  unsigned long long aesl_llvm_cbe_storemerge1922_2e_mux_count = 0;
  bool llvm_cbe_storemerge1922_2e_mux;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
   char *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_be_count = 0;
  unsigned int llvm_cbe__2e_be;
  unsigned int llvm_cbe__2e_be__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1910_2e_be_count = 0;
  bool llvm_cbe_storemerge1910_2e_be;
  bool llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge19_2e_be_count = 0;
  bool llvm_cbe_storemerge19_2e_be;
  bool llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
   char *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  float llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
   char *llvm_cbe_tmp__61;
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
  float llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
   char *llvm_cbe_tmp__63;
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
  float llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  unsigned long long llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  float *llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  float *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  float *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_not_2e__count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @readFile\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call %%struct._iobuf* @fopen(i8* getelementptr inbounds ([9 x i8]* @aesl_internal_.str1, i64 0, i64 0), i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str2, i64 0, i64 0)) nounwind, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_44_count);
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
    goto llvm_cbe_tmp__71;
  } else {
    llvm_cbe_storemerge26__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader25;
  }

llvm_cbe_tmp__71:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([20 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 20
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @exit(i32 1) noreturn nounwind, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_52_count);
  exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe__2e_preheader19:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [500 x i8]* %%buff, i64 0, i64 0, !dbg !6 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__6 = ( char *)(&llvm_cbe_buff[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 500
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @fgets(i8* %%4, i32 500, %%struct._iobuf* %%file) nounwind, !dbg !6 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_56_count);
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
printf("\n  %%7 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 0, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__8 = (float (*)[3])(&llvm_cbe_data[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 128
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [1 x [4 x float]]* %%sMax, i64 0, i64 0, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__9 = (float (*)[4])(&llvm_cbe_sMax[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [1 x [4 x float]]* %%sMax, i64 0, i64 0, i64 0, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__10 = (float *)(&llvm_cbe_sMax[(((signed long long )0ull))
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
  llvm_cbe_tmp__16__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__72;

  do {     /* Syntactic loop '.preheader25' to make GCC happy */
llvm_cbe__2e_preheader25:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge26 = phi i32 [ %%14, %%.preheader25 ], [ 0, %%0  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge26_count);
  llvm_cbe_storemerge26 = (unsigned int )llvm_cbe_storemerge26__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge26 = 0x%X",llvm_cbe_storemerge26);
printf("\n = 0x%X",llvm_cbe_tmp__15);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%storemerge26 to i64, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__11 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge26);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%10, i64 0, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__12 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__11))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__11));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__11) < 128 && "Write access out of array 'dt' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'dt' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%11, align 4, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_65_count);
  *llvm_cbe_tmp__12 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%10, i64 1, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__13 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__11))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__11));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__11) < 128 && "Write access out of array 'dt' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'dt' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%12, align 4, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_67_count);
  *llvm_cbe_tmp__13 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%10, i64 2, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__14 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__11))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__11));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__11) < 128 && "Write access out of array 'dt' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'dt' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%13, align 4, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_69_count);
  *llvm_cbe_tmp__14 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%storemerge26, 1, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__15 = (unsigned int )((unsigned int )(llvm_cbe_storemerge26&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__15&4294967295ull)));
  if (((llvm_cbe_tmp__15&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe__2e_preheader19;
  } else {
    llvm_cbe_storemerge26__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__15;   /* for PHI node */
    goto llvm_cbe__2e_preheader25;
  }

  } while (1); /* end of syntactic loop '.preheader25' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__72:
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
printf("\n  %%16 = phi i32 [ 0, %%.lr.ph23 ], [ %%.be, %%.backedge  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__16 = (unsigned int )llvm_cbe_tmp__16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__16);
printf("\n = 0x%X",0u);
printf("\n.be = 0x%X",llvm_cbe__2e_be);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1910.not = xor i1 %%storemerge191021, true, !dbg !7 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge1910_2e_not_count);
  llvm_cbe_storemerge1910_2e_not = (bool )((llvm_cbe_storemerge191021 ^ 1)&1);
if (AESL_DEBUG_TRACE)
printf("\nstoremerge1910.not = 0x%X\n", llvm_cbe_storemerge1910_2e_not);
if (AESL_DEBUG_TRACE)
printf("\n  %%brmerge = or i1 %%storemerge1922, %%storemerge1910.not, !dbg !7 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_brmerge_count);
  llvm_cbe_brmerge = (bool )((llvm_cbe_storemerge1922 | llvm_cbe_storemerge1910_2e_not)&1);
if (AESL_DEBUG_TRACE)
printf("\nbrmerge = 0x%X\n", llvm_cbe_brmerge);
  if (llvm_cbe_brmerge) {
    llvm_cbe_tmp__54__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__16;   /* for PHI node */
    goto llvm_cbe_tmp__73;
  } else {
    goto llvm_cbe__2e_preheader16;
  }

llvm_cbe__2e_backedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.be = phi i32 [ %%59, %%78 ], [ %%59, %%74 ], [ %%59, %%69 ], [ %%59, %%65 ], [ %%59, %%66 ], [ %%88, %%82  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe__2e_be_count);
  llvm_cbe__2e_be = (unsigned int )llvm_cbe__2e_be__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.be = 0x%X",llvm_cbe__2e_be);
printf("\n = 0x%X",llvm_cbe_tmp__54);
printf("\n = 0x%X",llvm_cbe_tmp__54);
printf("\n = 0x%X",llvm_cbe_tmp__54);
printf("\n = 0x%X",llvm_cbe_tmp__54);
printf("\n = 0x%X",llvm_cbe_tmp__54);
printf("\n = 0x%X",llvm_cbe_tmp__69);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1910.be = phi i1 [ true, %%78 ], [ true, %%74 ], [ true, %%69 ], [ %%storemerge1922, %%65 ], [ %%storemerge1922.mux, %%66 ], [ true, %%82  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge1910_2e_be_count);
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
printf("\n  %%storemerge19.be = phi i1 [ false, %%78 ], [ false, %%74 ], [ false, %%69 ], [ true, %%65 ], [ false, %%66 ], [ %%not., %%82  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge19_2e_be_count);
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
printf("\n  %%72 = call i8* @fgets(i8* %%4, i32 500, %%struct._iobuf* %%file) nounwind, !dbg !6 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_510_count);
  llvm_cbe_tmp__59 = ( char *)( char *)fgets(( char *)llvm_cbe_tmp__6, 500u, (l_struct_OC__iobuf *)llvm_cbe_file);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",500u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__59);
}
  if (((llvm_cbe_tmp__59) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe__2e__crit_edge24;
  } else {
    llvm_cbe_storemerge1922__PHI_TEMPORARY = (bool )llvm_cbe_storemerge19_2e_be;   /* for PHI node */
    llvm_cbe_storemerge191021__PHI_TEMPORARY = (bool )llvm_cbe_storemerge1910_2e_be;   /* for PHI node */
    llvm_cbe_tmp__16__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_be;   /* for PHI node */
    goto llvm_cbe_tmp__72;
  }

llvm_cbe_tmp__74:
  llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__54;   /* for PHI node */
  llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY = (bool )llvm_cbe_storemerge1922;   /* for PHI node */
  llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY = (bool )1;   /* for PHI node */
  goto llvm_cbe__2e_backedge;

llvm_cbe_tmp__73:
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = phi i32 [ %%16, %%15 ], [ 0, %%.loopexit  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_479_count);
  llvm_cbe_tmp__54 = (unsigned int )llvm_cbe_tmp__54__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__54);
printf("\n = 0x%X",llvm_cbe_tmp__16);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = call i32 @strcmp(i8* %%4, i8* getelementptr inbounds ([8 x i8]* @aesl_internal_.str8, i64 0, i64 0)) nounwind, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_480_count);
  llvm_cbe_tmp__55 = (unsigned int )strcmp(( char *)llvm_cbe_tmp__6, ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__55);
}
  if (((llvm_cbe_tmp__55&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__74;
  } else {
    goto llvm_cbe_tmp__75;
  }

llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  call void @master([3 x float]* %%7, [4 x float]* %%8) nounwind, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_216_count);
  master(llvm_cbe_tmp__8, llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts11 = call i32 @puts(i8* getelementptr inbounds ([6 x i8]* @aesl_internal_str2, i64 0, i64 0)), !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_puts11_count);
  puts(( char *)((&aesl_internal_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts11 = 0x%X",llvm_cbe_puts11);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @printData2D(i32 1, i32 4, float* %%9) nounwind, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_217_count);
  printData2D(1u, 4u, (float *)llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",4u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts12 = call i32 @puts(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_str3, i64 0, i64 0)), !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_puts12_count);
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
printf("\n  %%41 = load float* %%9, align 16, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__37 = (float )*llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__37, *(int*)(&llvm_cbe_tmp__37));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = fpext float %%41 to double, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__38 = (double )((double )llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__38, *(long long*)(&llvm_cbe_tmp__38));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str6, i64 0, i64 0), double %%42) nounwind, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_247_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__5, ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__38, *(long long*)(&llvm_cbe_tmp__38));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds [1 x [4 x float]]* %%sMax, i64 0, i64 0, i64 1, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__40 = (float *)(&llvm_cbe_sMax[(((signed long long )0ull))
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
printf("\n  %%45 = load float* %%44, align 4, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_276_count);
  llvm_cbe_tmp__41 = (float )*llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__41, *(int*)(&llvm_cbe_tmp__41));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = fpext float %%45 to double, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_277_count);
  llvm_cbe_tmp__42 = (double )((double )llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__42, *(long long*)(&llvm_cbe_tmp__42));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str6, i64 0, i64 0), double %%46) nounwind, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_278_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__5, ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__42, *(long long*)(&llvm_cbe_tmp__42));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__43);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [1 x [4 x float]]* %%sMax, i64 0, i64 0, i64 2, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_306_count);
  llvm_cbe_tmp__44 = (float *)(&llvm_cbe_sMax[(((signed long long )0ull))
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
printf("\n  %%49 = load float* %%48, align 8, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_307_count);
  llvm_cbe_tmp__45 = (float )*llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__45, *(int*)(&llvm_cbe_tmp__45));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = fpext float %%49 to double, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_308_count);
  llvm_cbe_tmp__46 = (double )((double )llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__46, *(long long*)(&llvm_cbe_tmp__46));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str6, i64 0, i64 0), double %%50) nounwind, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_309_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__5, ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__46, *(long long*)(&llvm_cbe_tmp__46));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__47);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = getelementptr inbounds [1 x [4 x float]]* %%sMax, i64 0, i64 0, i64 3, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_337_count);
  llvm_cbe_tmp__48 = (float *)(&llvm_cbe_sMax[(((signed long long )0ull))
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
printf("\n  %%53 = load float* %%52, align 4, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_338_count);
  llvm_cbe_tmp__49 = (float )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__49, *(int*)(&llvm_cbe_tmp__49));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = fpext float %%53 to double, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_339_count);
  llvm_cbe_tmp__50 = (double )((double )llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__50, *(long long*)(&llvm_cbe_tmp__50));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str6, i64 0, i64 0), double %%54) nounwind, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_340_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__5, ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__50, *(long long*)(&llvm_cbe_tmp__50));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__51);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc = call i32 @fputc(i32 10, %%struct._iobuf* %%1), !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_fputc_count);
  fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc = 0x%X",llvm_cbe_fputc);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = bitcast [128 x [3 x float]]* %%dt to i8 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_476_count);
  llvm_cbe_tmp__52 = ( char *)(( char *)(&llvm_cbe_dt));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = call i8* @memset(i8* %%56, i32 0, i64 36 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_477_count);
  ( char *)memset(( char *)llvm_cbe_tmp__52, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__53);
}
  llvm_cbe_tmp__54__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__73;

llvm_cbe__2e_preheader:
  if ((((signed int )llvm_cbe_tmp__16) < ((signed int )128u))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__76:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge217 = phi i32 [ 0, %%.lr.ph18 ], [ %%33, %%20  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge217_count);
  llvm_cbe_storemerge217 = (unsigned int )llvm_cbe_storemerge217__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge217 = 0x%X",llvm_cbe_storemerge217);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__30);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sext i32 %%storemerge217 to i64, !dbg !8 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__18 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge217);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%21, i64 0, !dbg !8 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__19 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__18))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__18));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__18) < 128)) fprintf(stderr, "%s:%d: warning: Read access out of array 'dt' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'dt' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load float* %%22, align 4, !dbg !8 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__20 = (float )*llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__20, *(int*)(&llvm_cbe_tmp__20));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i32 %%18, %%storemerge217, !dbg !8 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__21 = (unsigned int )((unsigned int )(llvm_cbe_tmp__17&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge217&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__21&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = sext i32 %%24 to i64, !dbg !8 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__22 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 %%25, i64 0, !dbg !8 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__23 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__22))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__22));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__22) < 128 && "Write access out of array 'data' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'data' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%23, float* %%26, align 4, !dbg !8 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_140_count);
  *llvm_cbe_tmp__23 = llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%21, i64 1, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__24 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__18))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__18));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__18) < 128)) fprintf(stderr, "%s:%d: warning: Read access out of array 'dt' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'dt' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load float* %%27, align 4, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__25 = (float )*llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__25, *(int*)(&llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 %%25, i64 1, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__26 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__22))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__22));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__22) < 128 && "Write access out of array 'data' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'data' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%28, float* %%29, align 4, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_144_count);
  *llvm_cbe_tmp__26 = llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%21, i64 2, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__27 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__18))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__18));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__18) < 128)) fprintf(stderr, "%s:%d: warning: Read access out of array 'dt' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'dt' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load float* %%30, align 4, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__28 = (float )*llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__28, *(int*)(&llvm_cbe_tmp__28));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 %%25, i64 2, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__29 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__22))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__22));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__22) < 128 && "Write access out of array 'data' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'data' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%31, float* %%32, align 4, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_148_count);
  *llvm_cbe_tmp__29 = llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%storemerge217, 1, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__30 = (unsigned int )((unsigned int )(llvm_cbe_storemerge217&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__30&4294967295ull)));
  if (((llvm_cbe_tmp__30&4294967295U) == (llvm_cbe_tmp__16&4294967295U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge217__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__30;   /* for PHI node */
    goto llvm_cbe_tmp__76;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph18:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sub i32 128, %%16, !dbg !8 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(128u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__16&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
  llvm_cbe_storemerge217__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__76;

llvm_cbe__2e_preheader16:
  if ((((signed int )llvm_cbe_tmp__16) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph18;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__77:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge315 = phi i32 [ %%16, %%.lr.ph ], [ %%40, %%34  for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge315_count);
  llvm_cbe_storemerge315 = (unsigned int )llvm_cbe_storemerge315__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge315 = 0x%X",llvm_cbe_storemerge315);
printf("\n = 0x%X",llvm_cbe_tmp__16);
printf("\n = 0x%X",llvm_cbe_tmp__36);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = sub nsw i32 %%storemerge315, %%16, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__31 = (unsigned int )((unsigned int )(llvm_cbe_storemerge315&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__16&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__31&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sext i32 %%35 to i64, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__32 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 %%36, i64 0, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__33 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__32))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__32));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__32) < 128 && "Write access out of array 'data' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'data' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%37, align 4, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_181_count);
  *llvm_cbe_tmp__33 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 %%36, i64 1, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__34 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__32))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__32));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__32) < 128 && "Write access out of array 'data' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'data' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%38, align 4, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_183_count);
  *llvm_cbe_tmp__34 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds [128 x [3 x float]]* %%data, i64 0, i64 %%36, i64 2, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__35 = (float *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__32))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__32));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__32) < 128 && "Write access out of array 'data' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'data' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%39, align 4, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_185_count);
  *llvm_cbe_tmp__35 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add nsw i32 %%storemerge315, 1, !dbg !12 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__36 = (unsigned int )((unsigned int )(llvm_cbe_storemerge315&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__36&4294967295ull)));
  if (((llvm_cbe_tmp__36&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge315__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__36;   /* for PHI node */
    goto llvm_cbe_tmp__77;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
  llvm_cbe_storemerge315__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__16;   /* for PHI node */
  goto llvm_cbe_tmp__77;

llvm_cbe_tmp__75:
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = call i32 @strcmp(i8* %%4, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str9, i64 0, i64 0)) nounwind, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_483_count);
  llvm_cbe_tmp__56 = (unsigned int )strcmp(( char *)llvm_cbe_tmp__6, ( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__56);
}
  if (((llvm_cbe_tmp__56&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__74;
  } else {
    goto llvm_cbe_tmp__78;
  }

llvm_cbe_tmp__78:
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = call i32 @strcmp(i8* %%4, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str7, i64 0, i64 0)) nounwind, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_493_count);
  llvm_cbe_tmp__57 = (unsigned int )strcmp(( char *)llvm_cbe_tmp__6, ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__57);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1922.not = xor i1 %%storemerge1922, true, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge1922_2e_not_count);
  llvm_cbe_storemerge1922_2e_not = (bool )((llvm_cbe_storemerge1922 ^ 1)&1);
if (AESL_DEBUG_TRACE)
printf("\nstoremerge1922.not = 0x%X\n", llvm_cbe_storemerge1922_2e_not);
if (AESL_DEBUG_TRACE)
printf("\n  %%brmerge29 = or i1 %%68, %%storemerge1922.not, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_brmerge29_count);
  llvm_cbe_brmerge29 = (bool )((((llvm_cbe_tmp__57&4294967295U) == (0u&4294967295U)) | llvm_cbe_storemerge1922_2e_not)&1);
if (AESL_DEBUG_TRACE)
printf("\nbrmerge29 = 0x%X\n", llvm_cbe_brmerge29);
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1922.mux = and i1 %%68, %%storemerge1922, !dbg !14 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_storemerge1922_2e_mux_count);
  llvm_cbe_storemerge1922_2e_mux = (bool )((((llvm_cbe_tmp__57&4294967295U) == (0u&4294967295U)) & llvm_cbe_storemerge1922)&1);
if (AESL_DEBUG_TRACE)
printf("\nstoremerge1922.mux = 0x%X\n", llvm_cbe_storemerge1922_2e_mux);
  if (llvm_cbe_brmerge29) {
    llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__54;   /* for PHI node */
    llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY = (bool )llvm_cbe_storemerge1922_2e_mux;   /* for PHI node */
    llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY = (bool )0;   /* for PHI node */
    goto llvm_cbe__2e_backedge;
  } else {
    goto llvm_cbe_tmp__79;
  }

llvm_cbe_tmp__79:
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = call i8* @strtok(i8* %%4, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str10, i64 0, i64 0)) nounwind, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_500_count);
  llvm_cbe_tmp__58 = ( char *)( char *)strtok(( char *)llvm_cbe_tmp__6, ( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__58);
}
  if (((llvm_cbe_tmp__58) == ((( char *)/*NULL*/0)))) {
    llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__54;   /* for PHI node */
    llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY = (bool )1;   /* for PHI node */
    llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY = (bool )0;   /* for PHI node */
    goto llvm_cbe__2e_backedge;
  } else {
    goto llvm_cbe_tmp__80;
  }

llvm_cbe_tmp__80:
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = call float @strtof(i8* nocapture %%70, i8** null) nounwind, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_513_count);
  llvm_cbe_tmp__60 = (float )strtof(( char *)llvm_cbe_tmp__58, ( char **)(( char **)/*NULL*/0));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__60);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = call i8* @strtok(i8* null, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str10, i64 0, i64 0)) nounwind, !dbg !16 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_516_count);
  llvm_cbe_tmp__61 = ( char *)( char *)strtok(( char *)(( char *)/*NULL*/0), ( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__61);
}
  if (((llvm_cbe_tmp__61) == ((( char *)/*NULL*/0)))) {
    llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__54;   /* for PHI node */
    llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY = (bool )1;   /* for PHI node */
    llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY = (bool )0;   /* for PHI node */
    goto llvm_cbe__2e_backedge;
  } else {
    goto llvm_cbe_tmp__81;
  }

llvm_cbe_tmp__81:
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = call float @strtof(i8* nocapture %%76, i8** null) nounwind, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_526_count);
  llvm_cbe_tmp__62 = (float )strtof(( char *)llvm_cbe_tmp__61, ( char **)(( char **)/*NULL*/0));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = call i8* @strtok(i8* null, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str10, i64 0, i64 0)) nounwind, !dbg !16 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_529_count);
  llvm_cbe_tmp__63 = ( char *)( char *)strtok(( char *)(( char *)/*NULL*/0), ( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__63);
}
  if (((llvm_cbe_tmp__63) == ((( char *)/*NULL*/0)))) {
    llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__54;   /* for PHI node */
    llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY = (bool )1;   /* for PHI node */
    llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY = (bool )0;   /* for PHI node */
    goto llvm_cbe__2e_backedge;
  } else {
    goto llvm_cbe_tmp__82;
  }

llvm_cbe_tmp__82:
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = call float @strtof(i8* nocapture %%80, i8** null) nounwind, !dbg !15 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_539_count);
  llvm_cbe_tmp__64 = (float )strtof(( char *)llvm_cbe_tmp__63, ( char **)(( char **)/*NULL*/0));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__64);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = sext i32 %%59 to i64, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_542_count);
  llvm_cbe_tmp__65 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%84, i64 0, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_543_count);
  llvm_cbe_tmp__66 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__65))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__65));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__65) < 128 && "Write access out of array 'dt' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'dt' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%75, float* %%85, align 4, !dbg !9 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_544_count);
  *llvm_cbe_tmp__66 = llvm_cbe_tmp__60;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%84, i64 1, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_545_count);
  llvm_cbe_tmp__67 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__65))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__65));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__65) < 128 && "Write access out of array 'dt' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'dt' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%79, float* %%86, align 4, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_546_count);
  *llvm_cbe_tmp__67 = llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = getelementptr inbounds [128 x [3 x float]]* %%dt, i64 0, i64 %%84, i64 2, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_547_count);
  llvm_cbe_tmp__68 = (float *)(&llvm_cbe_dt[(((signed long long )llvm_cbe_tmp__65))
#ifdef AESL_BC_SIM
 % 128
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__65));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__65) < 128 && "Write access out of array 'dt' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'dt' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%83, float* %%87, align 4, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_548_count);
  *llvm_cbe_tmp__68 = llvm_cbe_tmp__64;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = add nsw i32 %%59, 1, !dbg !10 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_549_count);
  llvm_cbe_tmp__69 = (unsigned int )((unsigned int )(llvm_cbe_tmp__54&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__69&4294967295ull)));
  llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__69;   /* for PHI node */
  llvm_cbe_storemerge1910_2e_be__PHI_TEMPORARY = (bool )1;   /* for PHI node */
  llvm_cbe_storemerge19_2e_be__PHI_TEMPORARY = (bool )((llvm_cbe_tmp__69&4294967295U) != (128u&4294967295U));   /* for PHI node */
  goto llvm_cbe__2e_backedge;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge24:
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = call i32 @fclose(%%struct._iobuf* %%1) nounwind, !dbg !11 for 0x%I64xth hint within @readFile  --> \n", ++aesl_llvm_cbe_569_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__70);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @readFile}\n");
  return;
}

