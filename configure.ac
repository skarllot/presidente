#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.54])
AC_INIT([PRESIDENTE], [0.1], [http://github.com/skarllot/presidente/issues])
AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([1.9 -Wall -Werror])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
PKG_CHECK_MODULES([DEPS],[libccext2])
AC_SUBST(DEPS_CFLAGS)
AC_SUBST(DEPS_LIBS)

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                    src/Makefile
                    src/client/Makefile
                    src/server/Makefile
                ])
AC_OUTPUT
