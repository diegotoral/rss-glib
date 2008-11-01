SUBDIRS = rss-glib bindings doc tests

pcfiles = rss-glib-1.0.pc

rss-glib-1.0.pc: rss-glib.pc
	@cp -f $< $@

pkgconfig_DATA = $(pcfiles)
pkgconfigdir = $(libdir)/pkgconfig

EXTRA_DIST = rss-glib.pc.in
CLEANFILES = $(pcfiles)

DISTCHECK_CONFIGURE_FLAGS = --enable-gtk-doc --enable-maintainer-flags

dist-hook:
	git-log --stat > ChangeLog.in && \
	cp -f ChangeLog.in $(distdir)/ChangeLog && \
	rm -f ChangeLog.in
