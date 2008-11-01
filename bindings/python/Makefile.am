INCLUDES = $(PYTHON_INCLUDES) $(PYGTK_CFLAGS)

defsdir = $(datadir)/pygtk/2.0/defs
defs_DATA = rss.defs

pkgpythondir = $(pyexecdir)/gtk-2.0
pkgpyexecdir = $(pyexecdir)/gtk-2.0

pkgpyexec_LTLIBRARIES = rss.la
rss_la_CFLAGS = $(RSS_CFLAGS) $(GTHREAD_CFLAGS)
rss_la_LDFLAGS = -module -avoid-version -export-symbols-regex initrss
rss_la_LIBADD = $(RSS_LIBS) $(GLIB_LIBS) $(top_builddir)/rss-glib/librss-glib-1.0.la
rss_la_SOURCES = rssmodule.c 

nodist_rss_la_SOURCES = rss.c

CLEANFILES = rss.c
EXTRA_DIST = rss.defs rss.override
rss.c: rss.defs rss.override

.defs.c:
	(cd $(srcdir) \
	 && $(PYGOBJECT_CODEGEN) \
	    --override $*.override \
	    --prefix py$* $*.defs) > gen-$*.c \
	&& cp gen-$*.c $*.c \
	&& rm -f gen-$*.c

