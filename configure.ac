#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

m4_define(LIBPOSTAL_MAJOR_VERSION, [1])
m4_define(LIBPOSTAL_MINOR_VERSION, [1])
m4_define(LIBPOSTAL_PATCH_VERSION, [0])

AC_INIT([libpostal], LIBPOSTAL_MAJOR_VERSION.LIBPOSTAL_MINOR_VERSION.LIBPOSTAL_PATCH_VERSION)

AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([src])
LT_INIT([shared])

AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC_C99
AC_PROG_INSTALL

LDFLAGS="$LDFLAGS -L/usr/local/lib"

# Checks for libraries.
AC_SEARCH_LIBS([log],
  [m],,[AC_MSG_ERROR([Could not find math library])])

# Checks for header files.
AC_HEADER_STDC
AC_HEADER_TIME
AC_HEADER_DIRENT
AC_HEADER_STDBOOL
AC_CHECK_HEADERS([fcntl.h float.h inttypes.h limits.h locale.h malloc.h memory.h stddef.h stdint.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_CHECK_FUNCS([malloc realloc drand48 getcwd gettimeofday memmove memset regcomp setlocale sqrt strdup strndup])

AC_SUBST([LIBPOSTAL_DATA_DIR_VERSION_STRING], [v1])

DATA_FILE_LATEST_VERSION=$(cat $srcdir/versions/base_data)
PARSER_MODEL_LATEST_VERSION=$(cat $srcdir/versions/parser)
LANG_CLASS_MODEL_LATEST_VERSION=$(cat $srcdir/versions/language_classifier)

AC_SUBST([LIBPOSTAL_DATA_FILE_LATEST_VERSION], [$DATA_FILE_LATEST_VERSION])
AC_SUBST([LIBPOSTAL_PARSER_MODEL_LATEST_VERSION], [$PARSER_MODEL_LATEST_VERSION])
AC_SUBST([LIBPOSTAL_LANG_CLASS_MODEL_LATEST_VERSION], [$LANG_CLASS_MODEL_LATEST_VERSION])

AC_CONFIG_FILES([Makefile
                 libpostal.pc
                 src/Makefile
                 src/libpostal_data
                 test/Makefile], [chmod +x src/libpostal_data])

AC_CHECK_PROG([FOUND_SHUF], [shuf], [yes])
AC_CHECK_PROG([FOUND_GSHUF], [gshuf], [yes])

AS_IF([test "x$FOUND_SHUF" = xyes],  [AC_DEFINE([HAVE_SHUF], [1], [shuf available])])
AS_IF([test "x$FOUND_GSHUF" = xyes],  [AC_DEFINE([HAVE_GSHUF], [1], [gshuf available])])

# ------------------------------------------------------------------
# Architecture-specific options
# ------------------------------------------------------------------

# allow enabling hardware optimization on any system:
case "$host_cpu" in
   arm*|aarch64*)
     enable_arm_neon=yes
     enable_intel_sse=no
     AC_DEFINE([ARM_NEON], [1],
       [Enable ARM_NEON optimizations])
     ;;
   i?86|x86_64)
     enable_intel_sse=yes
     enable_arm_neon=no
     AC_DEFINE([INTEL_SSE], [1],
       [Enable Intel SSE optimizations])
     ;;
esac

AC_ARG_ENABLE([neon],
  AS_HELP_STRING([[[--disable-neon]]],
    [Disable ARM NEON hardware optimizations]),
  [
   enable_arm_neon=no
   AC_DEFINE([ARM_NEON], [0],
     [Disable ARM_NEON optimizations])
  ])

AC_ARG_ENABLE([sse2],
  AS_HELP_STRING([[[--disable-sse2]]],
    [Disable Intel SSE2 hardware optimizations]),
  [
    enable_intel_sse=no
    AC_DEFINE([INTEL_SSE], [0],
      [Disable INTEL_SSE optimizations])
  ])

SIMDFLAGS=""

AS_IF([test "x$enable_intel_sse" != "xno"], [
  SIMDFLAGS="-mfpmath=sse -msse2 -DINTEL_SSE"
])

AS_IF([test "x$enable_arm_neon" != "xno"], [
  SIMDFLAGS="-march=armv8-a+fp+simd+crypto+crc -DARM_NEON"
])

CFLAGS="${SIMDFLAGS} ${CFLAGS}"

AC_SUBST([SIMDFLAGS], [$SIMDFLAGS])

AC_CHECK_HEADER(cblas.h, [AX_CBLAS])

AC_ARG_ENABLE([data-download],
              [  --disable-data-download    Disable downloading data],
              [case "${enableval}" in
                yes)  DOWNLOAD_DATA=true ;;
                no) DOWNLOAD_DATA=false ;;
                *) AC_MSG_ERROR([bad value ${enableval} for --disable-data-download]) ;;
              esac], [DOWNLOAD_DATA=true])


AM_CONDITIONAL([DOWNLOAD_DATA], [test "x$DOWNLOAD_DATA" = "xtrue"])

AC_ARG_WITH(cflags-scanner-extra, [AS_HELP_STRING([--with-cflags-scanner-extra@<:@=VALUE@:>@], [Extra compilation options for scanner.c])],
[
 if test "x$withval" = "xno"; then
    CFLAGS_SCANNER_EXTRA=""
 else
   CFLAGS_SCANNER_EXTRA="$withval"
 fi
],
[ CFLAGS_SCANNER_EXTRA="" ]
)

AC_MSG_NOTICE([extra cflags for scanner.c: $CFLAGS_SCANNER_EXTRA])
AC_SUBST(CFLAGS_SCANNER_EXTRA)
AC_SUBST(LIBPOSTAL_SO_VERSION, LIBPOSTAL_MAJOR_VERSION:LIBPOSTAL_MINOR_VERSION:LIBPOSTAL_PATCH_VERSION)

AC_OUTPUT
