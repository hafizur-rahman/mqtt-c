#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([mqtt-sample], [0.1], [bibagimon@gmail.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/mqtt-pub.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.
AC_SEARCH_LIBS([MQTTClient_create], [paho-mqtt3c], [], [
	AC_MSG_ERROR([unable to find the paho-mqtt3c lib])
])

# Checks for header files.
AC_CHECK_HEADERS([MQTTClient.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
