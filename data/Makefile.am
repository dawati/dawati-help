desktopdir = $(datadir)/applications
desktop_in_files = \
	meego-help.desktop.in \
	$(NULL)
desktop_DATA = $(desktop_in_files:.desktop.in=.desktop)
@INTLTOOL_DESKTOP_RULE@

htmldir = $(datadir)/meego-help

install-data-local:
	@$(NORMAL_INSTALL)
	$(MKDIR_P) $(DESTDIR)$(htmldir)/css
	$(MKDIR_P) $(DESTDIR)$(htmldir)/images
	$(INSTALL_DATA) $(top_srcdir)/data/html/index.html $(DESTDIR)$(htmldir)
	$(INSTALL_DATA) $(top_srcdir)/data/html/css/* $(DESTDIR)$(htmldir)/css
	$(INSTALL_DATA) $(top_srcdir)/data/html/images/* $(DESTDIR)$(htmldir)/images

uninstall-local:
	@$(NORMAL_UNINSTALL)
	-rm -rf $(DESTDIR)$(htmldir)

EXTRA_DIST = $(desktop_in_files) \
	     $(desktop_DATA) \
	     $(top_srcdir)/data/html

