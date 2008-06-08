m4_define([rss_major_version], [0])
m4_define([rss_minor_version], [1])
m4_define([rss_micro_version], [0])

m4_define([rss_version],
          [rss_major_version.rss_minor_version.rss_micro_version])

m4_define([rss_interface_age], [0])
m4_define([rss_binary_age],
          [m4_eval(100 * rss_minor_version + rss_micro_version)])

m4_define([lt_current],
          [m4_eval(100 * rss_minor_version + rss_micro_version - rss_interface_age)])
m4_define([lt_revision], [rss_interface_age])
m4_define([lt_age],
          [m4_eval(rss_binary_age - rss_interface_age)])

m4_define([glib_req_version], [2.15])

AC_PREREQ([2.59])

AC_INIT([rss-glib],
        [rss_version],
        [http://bugzilla.dronelabs.com/enter_bug.cgi],
        [rss-glib])

AC_CONFIG_SRCDIR([rss-glib/rss-glib.h])

AM_INIT_AUTOMAKE([1.9])
AM_CONFIG_HEADER([config.h])

AM_DISABLE_STATIC
AM_PATH_GLIB_2_0
AM_PROG_LIBTOOL

RSS_MAJOR_VERSION=rss_major_version
RSS_MINOR_VERSION=rss_minor_version
RSS_MICRO_VERSION=rss_micro_version
RSS_VERSION=rss_version
AC_SUBST(RSS_MAJOR_VERSION)
AC_SUBST(RSS_MICRO_VERSION)
AC_SUBST(RSS_MINOR_VERSION)
AC_SUBST(RSS_VERSION)

RSS_LT_CURRENT=lt_current
RSS_LT_REVISION=lt_revision
RSS_LT_AGE=lt_age
RSS_LT_VERSION="$RSS_LT_CURRENT:$RSS_LT_REVISION:$RSS_LT_AGE"
RSS_LT_LDFLAGS="-version-info $RSS_LT_VERSION"
AC_SUBST(RSS_LT_LDFLAGS)

AC_PROG_CC
AC_HEADER_STDC
AC_CHECK_HEADERS([unistd.h])
AC_C_CONST
AC_FUNC_MALLOC
AC_FUNC_MMAP

GLIB_PREFIX="`$PKG_CONFIG --variable=prefix glib-2.0`"
AC_SUBST(GLIB_PREFIX)

PKG_CHECK_MODULES(MRSS, mrss >= 0.18)
AC_SUBST(MRSS_CFLAGS)
AC_SUBST(MRSS_LIBS)

PKG_CHECK_MODULES(RSS, gobject-2.0 >= glib_req_version)
AC_SUBST(RSS_CFLAGS)
AC_SUBST(RSS_LIBS)

dnl = Enable debug level ===================================================

m4_define([debug_default],
          m4_if(m4_eval(rss_minor_version % 2), [1], [yes], [minimum]))

AC_ARG_ENABLE([debug],
              AC_HELP_STRING([--enable-debug=@<:@no/minimum/yes@:>@],
                             [turn on debugging @<:@default=debug_default@:>@]),
,
              enable_debug=debug_default)

if test "x$enable_debug" = "xyes"; then
  test "$cflags_set" = set || CFLAGS="$CFLAGS -g"
  RSS_DEBUG_CFLAGS="-DRSS_ENABLE_DEBUG"
else
  if test "x$enable_debug" = "xno"; then
    RSS_DEBUG_CFLAGS="-DG_DISABLE_ASSERT -DG_DISABLE_CHECKS -DG_DISABLE_CAST_CHECKS"
  else # minimum
    RSS_DEBUG_CFLAGS="-DRSS_ENABLE_DEBUG -DG_DISABLE_CAST_CHECKS"
  fi
fi

AC_SUBST(RSS_DEBUG_CFLAGS)

dnl = Enable strict compiler flags =========================================

# use strict compiler flags only on development releases
#m4_define([maintainer_flags_default],
#          m4_if(m4_eval(rss_minor_version % 2), [1], [yes], [no]))
m4_define([maintainer_flags_default], [no])
AC_ARG_ENABLE([maintainer-flags],
              AC_HELP_STRING([--enable-maintainer-flags=@<:@no/yes@:>@],
                             [Use strict compiler flags @<:@default=maintainer_flags_default@:>@]),,
              enable_maintainer_flags=maintainer_flags_default)

if test "x$enable_maintainer_flags" = "xyes"; then
  CPPFLAGS="$CPPFLAGS -g -Wall -Wshadow -Wcast-align -Wno-uninitialized -Werror"
else
  CPPFLAGS="$CPPFLAGS -g -Wall"
fi

GTK_DOC_CHECK([1.8])

AC_CONFIG_FILES([
        Makefile
        rss-glib/Makefile
        rss-glib/rss-version.h
        tests/Makefile
        doc/Makefile
        rss-glib.pc
])

AC_OUTPUT

echo ""
echo " Rss-GLib $VERSION"
echo ""
echo "                Prefix: ${prefix}"
echo "           Debug level: ${enable_debug}"
echo "        Compiler flags: ${CPPFLAGS}"
echo "         API reference: ${enable_gtk_doc}"
echo ""
