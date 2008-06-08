NULL =

INCLUDES = \
	-I$(top_srcdir) 		\
	-DPREFIX=\""$(prefix)"\" 	\
	-DLIBDIR=\""$(libdir)"\" 	\
	-DG_DISABLE_DEPRECATED 		\
	-DG_LOG_DOMAIN=\"Rss\" 	\
	$(RSS_CFLAGS) 			\
	$(RSS_DEBUG_CFLAGS) 		\
	$(NULL)

LDADD = \
	$(RSS_LT_LDFLAGS) \
	-export-dynamic \
	-rpath $(libdir)

#-export-symbols-regex "^rss.*"

BUILT_SOURCES = rss-marshal.h rss-marshal.c

STAMP_FILES = stamp-rss-marshal.h

source_h = \
	$(top_srcdir)/rss-glib/rss-generator.h \
	$(top_srcdir)/rss-glib/rss-parser.h \
	$(top_srcdir)/rss-glib/rss-version.h \
	$(NULL)

source_h_private = \
	$(NULL)

source_c = \
	rss-generator.c \
	rss-parser.c \
	$(NULL)

rss-marshal.h: stamp-rss-marshal.h
	@true
stamp-rss-marshal.h: Makefile rss-marshal.list
	$(GLIB_GENMARSHAL) \
		--prefix=_rss_marshal \
		--header \
	$(srcdir)/rss-marshal.list > xgen-jmh && \
	(cmp -s xgen-jmh rss-marshal.h || cp -f xgen-jmh rss-marshal.h) && \
	rm -f xgen-jmh && \
	echo timestamp > $(@F)

rss-marshal.c: Makefile rss-marshal.list
	(echo "#include \"rss-marshal.h\"" ; \
	 $(GLIB_GENMARSHAL) \
		--prefix=_rss_marshal \
		--body \
	 $(srcdir)/rss-marshal.list ) > xgen-jmc && \
	cp -f xgen-jmc rss-marshal.c && \
	rm -f xgen-jmc

rss-enum-types.h: stamp-rss-enum-types.h
	@true
stamp-rss-enum-types.h: $(source_h) Makefile
	( cd $(top_srcdir)/rss-glib && \
	  $(GLIB_MKENUMS) \
	  	--template $(top_srcdir)/rss-glib/rss-enum-types.h.in \
	  $(source_h) ) > xgen-ceth \
	&& (cmp xgen-ceth rss-enum-types.h || cp xgen-ceth rss-enum-types.h) \
	&& rm -f xgen-ceth \
	&& echo timestamp > $(@F)

rss-enum-types.c: rss-enum-types.h
	( cd $(top_srcdir)/rss-glib && \
	  $(GLIB_MKENUMS) \
	  	--template $(top_srcdir)/rss-glib/rss-enum-types.c.in \
	  $(source_h) ) > xgen-cetc \
	&& cp xgen-cetc rss-enum-types.c \
	&& rm -f xgen-cetc

lib_LTLIBRARIES = librss-glib-1.0.la

librss_glib_1_0_la_LIBADD = $(RSS_LIBS)
librss_glib_1_0_la_SOURCES = \
	$(source_c) \
	$(source_h) \
	$(source_h_priv) \
	$(BUILT_SOURCES) \
	$(NULL)
librss_glib_1_0_la_LDFLAGS = $(LDADD)

rssincludedir = $(includedir)/rss-glib-1.0/rss-glib
rssinclude_DATA = \
	$(source_h) \
	$(top_srcdir)/rss-glib/rss-glib.h

CLEANFILES = $(STAMP_FILES) $(BUILT_SOURCES)

DISTCLEANFILES = rss-version.h

EXTRA_DIST = \
	rss-version.h.in \
	rss-glib.h \
	rss-marshal.list
