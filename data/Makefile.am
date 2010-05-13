desktopdir = $(datadir)/applications
desktop_in_files = \
	meego-help.desktop.in \
	$(NULL)
desktop_DATA = $(desktop_in_files:.desktop.in=.desktop)
@INTLTOOL_DESKTOP_RULE@

htmldir = $(datadir)/meego-help
html_DATA = offline.html \
	    $(NULL)

EXTRA_DIST = $(desktop_in_files) \
	     $(desktop_DATA) \
	     $(html_DATA)

