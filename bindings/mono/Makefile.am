RAW_API = rss-glib.raw
API = rss-glib.api
METADATA = rss-glib.metadata

ASSEMBLY_NAME = rss-glib-sharp
ASSEMBLY = $(ASSEMBLY_NAME).dll

sources = Global.cs
build_sources = $(addprefix $(srcdir)/, $(sources)) AssemblyInfo.cs

customs =

CLEANFILES = $(ASSEMBLY) generated-stamp generated/*.cs $(API)
DISTCLEANFILES = AssemblyInfo.cs

noinst_DATA = $(ASSEMBLY)

FIXUP = gapi2-fixup
CODEGEN = gapi2-codegen

all: generated-stamp $(ASSEMBLY)

$(API): $(srcdir)/$(RAW_API) $(srcdir)/$(METADATA)
	cp $(srcdir)/$(RAW_API) $(API)
	chmod u+w $(API)
	$(FIXUP) --api=$(srcdir)/$(API) --metadata=$(srcdir)/$(METADATA)

generated-stamp: $(API)
	$(CODEGEN) --generate $(srcdir)/$(API) $(GLIB_SHARP_CFLAGS) \
	--outdir=generated --customdir=$(srcdir) \
	--assembly-name=$(ASSEMBLY_NAME) && touch generated-stamp

$(ASSEMBLY): $(build_sources) generated-stamp
	$(CSC) -out:$@ -unsafe -target:library -debug+ $(GLIB_SHARP_LIBS) \
	$(build_sources) $(builddir)/generated/*.cs

install-data-local:
	echo "$(GACUTIL) /i $(ASSEMBLY) /f /package rss-glib-sharp-1.0 /root $(DESTDIR)$(libdir)";  \
	$(GACUTIL) /i $(ASSEMBLY) /f /package rss-glib-sharp-1.0 /root $(DESTDIR)$(libdir) || exit 1;

uninstall-local:
	echo "$(GACUTIL) /u $(ASSEMBLY_NAME) /package rss-glib-sharp-1.0 /root $(DESTDIR)$(libdir)"; \
	$(GACUTIL) /u $(ASSEMBLY_NAME) /package rss-glib-sharp-1.0 /root $(DESTDIR)$(libdir) || exit 1;

EXTRA_DIST = $(RAW_API) $(sources) $(customs) $(METADATA) AssemblyInfo.cs.in rss-glib-sharp.dll.config.in rss-glib-sharp.snk

