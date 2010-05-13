#include <dbus/dbus-glib.h>
#include <gio/gio.h>


#define ONLINE_URL "http://help.meego.com/"
#define OFFLINE_URL "file://"PKG_DATA_DIR"/index.html"

static GMainLoop *loop;

static void
got_state_cb (DBusGProxy     *proxy,
              DBusGProxyCall *call,
              void           *user_data)
{
  gboolean online;
  const char *state = NULL;
  GError *error = NULL;

  if (!dbus_g_proxy_end_call (proxy, call, &error,
			      G_TYPE_STRING, &state,
			      G_TYPE_INVALID)) {
    g_printerr ("Cannot get current online state: %s", error->message);
    g_error_free (error);
    return;
  }

  online = (g_strcmp0 (state, "online") == 0);

  if (online)
  {
    g_app_info_launch_default_for_uri (ONLINE_URL,
                                       NULL,
                                       NULL);
  } else {
    g_app_info_launch_default_for_uri (OFFLINE_URL,
                                       NULL,
                                       NULL);
  }

  g_main_loop_quit (loop);
}

int
main (int    argc,
      char **argv)
{
  DBusGConnection *conn;
  DBusGProxy *proxy = NULL;

  g_type_init ();

  loop = g_main_loop_new (NULL, FALSE);

  conn = dbus_g_bus_get (DBUS_BUS_SYSTEM, NULL);
  if (!conn) {
    g_warning ("Cannot get connection to system message bus");
    return 1;
  }

  proxy = dbus_g_proxy_new_for_name (conn,
                                     "org.moblin.connman",
                                     "/",
                                     "org.moblin.connman.Manager");

  dbus_g_object_register_marshaller (g_cclosure_marshal_VOID__STRING,
                                     G_TYPE_NONE, G_TYPE_STRING,
                                     G_TYPE_INVALID);
  dbus_g_proxy_begin_call (proxy, "GetState", got_state_cb,
                           NULL, NULL, G_TYPE_INVALID);

  g_main_loop_run (loop);
}
