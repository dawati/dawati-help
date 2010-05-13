bin_PROGRAMS = meego-help

meego_help_CFLAGS = $(DBUS_GLIB_CFLAGS) $(GIO_CFLAGS) \
		    -DPKG_DATA_DIR=\"$(pkgdatadir)\"
meego_help_SOURCES = meego-help.c
meego_help_LDFLAGS = $(DBUS_GLIB_LIBS) $(GIO_LIBS)

