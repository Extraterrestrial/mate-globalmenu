/* settings.c generated by valac, the Vala compiler
 * generated from settings.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gdk/gdk.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <X11/Xregion.h>
#include <gdk/gdkx.h>
#include <stdio.h>


#define MATENU_TYPE_SETTINGS (matenu_settings_get_type ())
#define MATENU_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MATENU_TYPE_SETTINGS, MatenuSettings))
#define MATENU_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), MATENU_TYPE_SETTINGS, MatenuSettingsClass))
#define MATENU_IS_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MATENU_TYPE_SETTINGS))
#define MATENU_IS_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MATENU_TYPE_SETTINGS))
#define MATENU_SETTINGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), MATENU_TYPE_SETTINGS, MatenuSettingsClass))

typedef struct _MatenuSettings MatenuSettings;
typedef struct _MatenuSettingsClass MatenuSettingsClass;
typedef struct _MatenuSettingsPrivate MatenuSettingsPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_key_file_free0(var) ((var == NULL) ? NULL : (var = (g_key_file_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _MatenuSettings {
	GObject parent_instance;
	MatenuSettingsPrivate * priv;
	GKeyFile* keyfile;
};

struct _MatenuSettingsClass {
	GObjectClass parent_class;
	void (*attach_to_window) (MatenuSettings* self, GdkWindow* window);
	gboolean (*get_show_local_menu) (MatenuSettings* self);
	void (*set_show_local_menu) (MatenuSettings* self, gboolean value);
	gboolean (*get_show_menu_icons) (MatenuSettings* self);
	void (*set_show_menu_icons) (MatenuSettings* self, gboolean value);
	gint (*get_changed_notify_timeout) (MatenuSettings* self);
	void (*set_changed_notify_timeout) (MatenuSettings* self, gint value);
};

struct _MatenuSettingsPrivate {
	GdkWindow* _window;
	GdkAtom atom;
	gboolean _show_local_menu;
	gboolean _show_menu_icons;
	gint _changed_notify_timeout;
};


static gpointer matenu_settings_parent_class = NULL;

GType matenu_settings_get_type (void) G_GNUC_CONST;
#define MATENU_SETTINGS_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), MATENU_TYPE_SETTINGS, MatenuSettingsPrivate))
enum  {
	MATENU_SETTINGS_DUMMY_PROPERTY,
	MATENU_SETTINGS_WINDOW,
	MATENU_SETTINGS_SHOW_LOCAL_MENU,
	MATENU_SETTINGS_SHOW_MENU_ICONS,
	MATENU_SETTINGS_CHANGED_NOTIFY_TIMEOUT
};
GdkWindow* matenu_settings_get_window (MatenuSettings* self);
static GdkFilterReturn matenu_settings_event_filter (GdkXEvent* xevent, GdkEvent* event, MatenuSettings* self);
static GdkFilterReturn _matenu_settings_event_filter_gdk_filter_func (GdkXEvent* xevent, GdkEvent* event, gpointer self);
static void matenu_settings_set_window (MatenuSettings* self, GdkWindow* value);
void matenu_settings_pull (MatenuSettings* self);
void matenu_settings_attach_to_window (MatenuSettings* self, GdkWindow* window);
static void matenu_settings_real_attach_to_window (MatenuSettings* self, GdkWindow* window);
static GdkFilterReturn matenu_settings_real_event_filter (XEvent* xevent, GdkEvent* event, MatenuSettings* self);
static gboolean matenu_settings_atom_equal (MatenuSettings* self, GdkAtom a1, GdkAtom a2);
static gboolean matenu_settings_is_tristate (gboolean boolean);
static gboolean matenu_settings_load_boolean (MatenuSettings* self, const char* key);
static gint matenu_settings_load_int (MatenuSettings* self, const char* key);
static char* matenu_settings_load_string (MatenuSettings* self, const char* key);
static void matenu_settings_save_boolean (MatenuSettings* self, const char* key, gboolean value);
static void matenu_settings_save_string (MatenuSettings* self, const char* key, const char* value);
static void matenu_settings_save_int (MatenuSettings* self, const char* key, gint value);
static void matenu_settings_save_property (MatenuSettings* self, const char* key);
static void matenu_settings_load_property (MatenuSettings* self, const char* key);
char* matenu_settings_to_string (MatenuSettings* self);
char* matenu_settings_get_by_atom (MatenuSettings* self, GdkAtom atom);
void matenu_settings_set_by_atom (MatenuSettings* self, GdkAtom atom, const char* value);
void matenu_settings_push (MatenuSettings* self);
MatenuSettings* matenu_settings_new (void);
MatenuSettings* matenu_settings_construct (GType object_type);
gboolean matenu_settings_get_show_local_menu (MatenuSettings* self);
void matenu_settings_set_show_local_menu (MatenuSettings* self, gboolean value);
gboolean matenu_settings_get_show_menu_icons (MatenuSettings* self);
void matenu_settings_set_show_menu_icons (MatenuSettings* self, gboolean value);
gint matenu_settings_get_changed_notify_timeout (MatenuSettings* self);
void matenu_settings_set_changed_notify_timeout (MatenuSettings* self, gint value);
static void matenu_settings_finalize (GObject* obj);
static void matenu_settings_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void matenu_settings_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);

const char* MATENU_SETTINGS_KEYS[3] = {"show-local-menu", "show-menu-icons", "changed-notify-timeout"};


static GdkFilterReturn _matenu_settings_event_filter_gdk_filter_func (GdkXEvent* xevent, GdkEvent* event, gpointer self) {
	GdkFilterReturn result;
	result = matenu_settings_event_filter (xevent, event, self);
	return result;
}


static void matenu_settings_real_attach_to_window (MatenuSettings* self, GdkWindow* window) {
	GdkEventMask events;
	g_return_if_fail (self != NULL);
	if (self->priv->_window != NULL) {
		gdk_window_remove_filter (window, _matenu_settings_event_filter_gdk_filter_func, self);
	}
	if (window == NULL) {
		return;
	}
	matenu_settings_set_window (self, window);
	gdk_window_add_filter (self->priv->_window, _matenu_settings_event_filter_gdk_filter_func, self);
	events = gdk_window_get_events (self->priv->_window);
	gdk_window_set_events (self->priv->_window, events | GDK_PROPERTY_CHANGE_MASK);
	matenu_settings_pull (self);
}


void matenu_settings_attach_to_window (MatenuSettings* self, GdkWindow* window) {
	MATENU_SETTINGS_GET_CLASS (self)->attach_to_window (self, window);
}


static GdkFilterReturn matenu_settings_event_filter (GdkXEvent* xevent, GdkEvent* event, MatenuSettings* self) {
	GdkFilterReturn result = 0;
	void* pointer;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (event != NULL, 0);
	pointer = xevent;
	result = matenu_settings_real_event_filter ((XEvent*) pointer, event, self);
	return result;
}


static gboolean matenu_settings_atom_equal (MatenuSettings* self, GdkAtom a1, GdkAtom a2) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	result = ((gint) a1) == ((gint) a2);
	return result;
}


static GdkFilterReturn matenu_settings_real_event_filter (XEvent* xevent, GdkEvent* event, MatenuSettings* self) {
	GdkFilterReturn result = 0;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (event != NULL, 0);
	switch ((*xevent).type) {
		case PropertyNotify:
		{
			GdkAtom atom_in;
			atom_in = gdk_x11_xatom_to_atom ((*xevent).xproperty.atom);
			if (matenu_settings_atom_equal (self, self->priv->atom, atom_in)) {
				matenu_settings_pull (self);
			}
			break;
		}
	}
	result = GDK_FILTER_CONTINUE;
	return result;
}


static gboolean matenu_settings_is_tristate (gboolean boolean) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	if (boolean != TRUE) {
		_tmp0_ = boolean != FALSE;
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}


static gboolean matenu_settings_load_boolean (MatenuSettings* self, const char* key) {
	gboolean result = FALSE;
	GError * _inner_error_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (key != NULL, FALSE);
	_inner_error_ = NULL;
	{
		gboolean _tmp0_;
		_tmp0_ = g_key_file_get_boolean (self->keyfile, "GlobalMenu:Client", key, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
		result = _tmp0_;
		return result;
	}
	goto __finally0;
	__catch0_g_error:
	{
		g_clear_error (&_inner_error_);
		_inner_error_ = NULL;
		{
			result = (gboolean) 30;
			return result;
		}
	}
	__finally0:
	{
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
}


static gint matenu_settings_load_int (MatenuSettings* self, const char* key) {
	gint result = 0;
	GError * _inner_error_;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (key != NULL, 0);
	_inner_error_ = NULL;
	{
		gint _tmp0_;
		_tmp0_ = g_key_file_get_integer (self->keyfile, "GlobalMenu:Client", key, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
		}
		result = _tmp0_;
		return result;
	}
	goto __finally1;
	__catch1_g_error:
	{
		g_clear_error (&_inner_error_);
		_inner_error_ = NULL;
		{
			result = -1;
			return result;
		}
	}
	__finally1:
	{
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
}


static char* matenu_settings_load_string (MatenuSettings* self, const char* key) {
	char* result = NULL;
	GError * _inner_error_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_inner_error_ = NULL;
	{
		char* _tmp0_;
		_tmp0_ = g_key_file_get_string (self->keyfile, "GlobalMenu:Client", key, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch2_g_error;
		}
		result = _tmp0_;
		return result;
	}
	goto __finally2;
	__catch2_g_error:
	{
		g_clear_error (&_inner_error_);
		_inner_error_ = NULL;
		{
			result = NULL;
			return result;
		}
	}
	__finally2:
	{
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


static void matenu_settings_save_boolean (MatenuSettings* self, const char* key, gboolean value) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (key != NULL);
	_inner_error_ = NULL;
	{
		if (!matenu_settings_is_tristate (value)) {
			g_key_file_set_boolean (self->keyfile, "GlobalMenu:Client", key, value);
		} else {
			g_key_file_remove_key (self->keyfile, "GlobalMenu:Client", key, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch3_g_error;
			}
		}
	}
	goto __finally3;
	__catch3_g_error:
	{
		g_clear_error (&_inner_error_);
		_inner_error_ = NULL;
		{
		}
	}
	__finally3:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void matenu_settings_save_string (MatenuSettings* self, const char* key, const char* value) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (key != NULL);
	_inner_error_ = NULL;
	{
		if (value != NULL) {
			g_key_file_set_string (self->keyfile, "GlobalMenu:Client", key, value);
		} else {
			g_key_file_remove_key (self->keyfile, "GlobalMenu:Client", key, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch4_g_error;
			}
		}
	}
	goto __finally4;
	__catch4_g_error:
	{
		g_clear_error (&_inner_error_);
		_inner_error_ = NULL;
		{
		}
	}
	__finally4:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void matenu_settings_save_int (MatenuSettings* self, const char* key, gint value) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (key != NULL);
	g_key_file_set_integer (self->keyfile, "GlobalMenu:Client", key, value);
}


static void matenu_settings_save_property (MatenuSettings* self, const char* key) {
	GObjectClass* klass;
	GParamSpec* pspec;
	GValue value = {0};
	g_return_if_fail (self != NULL);
	g_return_if_fail (key != NULL);
	klass = (GObjectClass*) G_OBJECT_GET_CLASS ((GObject*) self);
	pspec = g_object_class_find_property (klass, key);
	g_value_init (&value, pspec->value_type);
	g_object_get_property ((GObject*) self, key, &value);
	if (pspec->value_type == G_TYPE_BOOLEAN) {
		matenu_settings_save_boolean (self, key, g_value_get_boolean (&value));
	} else {
		if (pspec->value_type == G_TYPE_STRING) {
			matenu_settings_save_string (self, key, g_value_get_string (&value));
		} else {
			if (pspec->value_type == G_TYPE_INT) {
				matenu_settings_save_int (self, key, g_value_get_int (&value));
			} else {
				fprintf (stdout, "unsupported value type `%s'.\n", g_type_name (pspec->value_type));
				G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
				return;
			}
		}
	}
	G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
}


static void matenu_settings_load_property (MatenuSettings* self, const char* key) {
	GObjectClass* klass;
	GParamSpec* pspec;
	GValue value = {0};
	g_return_if_fail (self != NULL);
	g_return_if_fail (key != NULL);
	klass = (GObjectClass*) G_OBJECT_GET_CLASS ((GObject*) self);
	pspec = g_object_class_find_property (klass, key);
	g_value_init (&value, pspec->value_type);
	if (pspec->value_type == G_TYPE_BOOLEAN) {
		g_value_set_boolean (&value, matenu_settings_load_boolean (self, key));
	} else {
		if (pspec->value_type == G_TYPE_STRING) {
			char* _tmp0_;
			g_value_set_string (&value, _tmp0_ = matenu_settings_load_string (self, key));
			_g_free0 (_tmp0_);
		} else {
			if (pspec->value_type == G_TYPE_INT) {
				g_value_set_int (&value, matenu_settings_load_int (self, key));
			} else {
				fprintf (stdout, "unsupported value type `%s'.\n", g_type_name (pspec->value_type));
				G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
				return;
			}
		}
	}
	g_object_set_property ((GObject*) self, key, &value);
	G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
}


char* matenu_settings_to_string (MatenuSettings* self) {
	char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	{
		const char** key_collection;
		int key_collection_length1;
		int key_it;
		key_collection = MATENU_SETTINGS_KEYS;
		key_collection_length1 = G_N_ELEMENTS (MATENU_SETTINGS_KEYS);
		for (key_it = 0; key_it < G_N_ELEMENTS (MATENU_SETTINGS_KEYS); key_it = key_it + 1) {
			const char* key;
			key = key_collection[key_it];
			{
				matenu_settings_save_property (self, key);
			}
		}
	}
	result = g_key_file_to_data (self->keyfile, NULL, NULL);
	return result;
}


static glong string_get_length (const char* self) {
	glong result;
	g_return_val_if_fail (self != NULL, 0L);
	result = g_utf8_strlen (self, -1);
	return result;
}


void matenu_settings_pull (MatenuSettings* self) {
	GError * _inner_error_;
	char* data;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	data = matenu_settings_get_by_atom (self, self->priv->atom);
	if (data == NULL) {
		_g_free0 (data);
		return;
	}
	g_key_file_load_from_data (self->keyfile, data, (gsize) string_get_length (data), G_KEY_FILE_NONE, &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_free0 (data);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	{
		const char** key_collection;
		int key_collection_length1;
		int key_it;
		key_collection = MATENU_SETTINGS_KEYS;
		key_collection_length1 = G_N_ELEMENTS (MATENU_SETTINGS_KEYS);
		for (key_it = 0; key_it < G_N_ELEMENTS (MATENU_SETTINGS_KEYS); key_it = key_it + 1) {
			const char* key;
			key = key_collection[key_it];
			{
				matenu_settings_load_property (self, key);
			}
		}
	}
	_g_free0 (data);
}


void matenu_settings_push (MatenuSettings* self) {
	char* str;
	g_return_if_fail (self != NULL);
	str = matenu_settings_to_string (self);
	matenu_settings_set_by_atom (self, self->priv->atom, str);
	_g_free0 (str);
}


char* matenu_settings_get_by_atom (MatenuSettings* self, GdkAtom atom) {
	char* result = NULL;
	char* context;
	GdkAtom actual_type;
	GdkAtom type;
	gint actual_format = 0;
	gint actual_length = 0;
	char* _tmp1_;
	char* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	context = NULL;
	type = gdk_atom_intern ("STRING", FALSE);
	gdk_property_get (self->priv->_window, atom, type, (gulong) 0, (gulong) G_MAXLONG, FALSE, &actual_type, &actual_format, &actual_length, &_tmp0_);
	context = (_tmp1_ = _tmp0_, _g_free0 (context), _tmp1_);
	result = context;
	return result;
}


void matenu_settings_set_by_atom (MatenuSettings* self, GdkAtom atom, const char* value) {
	g_return_if_fail (self != NULL);
	if (value != NULL) {
		GdkAtom type;
		type = gdk_atom_intern ("STRING", FALSE);
		gdk_property_change (self->priv->_window, atom, type, 8, GDK_PROP_MODE_REPLACE, value, ((gint) strlen (value)) + 1);
	} else {
		gdk_property_delete (self->priv->_window, atom);
	}
}


MatenuSettings* matenu_settings_construct (GType object_type) {
	MatenuSettings * self;
	self = (MatenuSettings*) g_object_new (object_type, NULL);
	return self;
}


MatenuSettings* matenu_settings_new (void) {
	return matenu_settings_construct (MATENU_TYPE_SETTINGS);
}


GdkWindow* matenu_settings_get_window (MatenuSettings* self) {
	GdkWindow* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_window;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void matenu_settings_set_window (MatenuSettings* self, GdkWindow* value) {
	GdkWindow* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_window = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_window), _tmp0_);
	g_object_notify ((GObject *) self, "window");
}


gboolean matenu_settings_get_show_local_menu (MatenuSettings* self) {
	return MATENU_SETTINGS_GET_CLASS (self)->get_show_local_menu (self);
}


static gboolean matenu_settings_real_get_show_local_menu (MatenuSettings* base) {
	gboolean result;
	MatenuSettings* self;
	self = base;
	result = self->priv->_show_local_menu;
	return result;
}


void matenu_settings_set_show_local_menu (MatenuSettings* self, gboolean value) {
	MATENU_SETTINGS_GET_CLASS (self)->set_show_local_menu (self, value);
}


static void matenu_settings_real_set_show_local_menu (MatenuSettings* base, gboolean value) {
	MatenuSettings* self;
	self = base;
	self->priv->_show_local_menu = value;
	g_object_notify ((GObject *) self, "show-local-menu");
}


gboolean matenu_settings_get_show_menu_icons (MatenuSettings* self) {
	return MATENU_SETTINGS_GET_CLASS (self)->get_show_menu_icons (self);
}


static gboolean matenu_settings_real_get_show_menu_icons (MatenuSettings* base) {
	gboolean result;
	MatenuSettings* self;
	self = base;
	result = self->priv->_show_menu_icons;
	return result;
}


void matenu_settings_set_show_menu_icons (MatenuSettings* self, gboolean value) {
	MATENU_SETTINGS_GET_CLASS (self)->set_show_menu_icons (self, value);
}


static void matenu_settings_real_set_show_menu_icons (MatenuSettings* base, gboolean value) {
	MatenuSettings* self;
	self = base;
	self->priv->_show_menu_icons = value;
	g_object_notify ((GObject *) self, "show-menu-icons");
}


gint matenu_settings_get_changed_notify_timeout (MatenuSettings* self) {
	return MATENU_SETTINGS_GET_CLASS (self)->get_changed_notify_timeout (self);
}


static gint matenu_settings_real_get_changed_notify_timeout (MatenuSettings* base) {
	gint result;
	MatenuSettings* self;
	self = base;
	result = self->priv->_changed_notify_timeout;
	return result;
}


void matenu_settings_set_changed_notify_timeout (MatenuSettings* self, gint value) {
	MATENU_SETTINGS_GET_CLASS (self)->set_changed_notify_timeout (self, value);
}


static void matenu_settings_real_set_changed_notify_timeout (MatenuSettings* base, gint value) {
	MatenuSettings* self;
	self = base;
	self->priv->_changed_notify_timeout = value;
	g_object_notify ((GObject *) self, "changed-notify-timeout");
}


static void matenu_settings_class_init (MatenuSettingsClass * klass) {
	matenu_settings_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (MatenuSettingsPrivate));
	MATENU_SETTINGS_CLASS (klass)->attach_to_window = matenu_settings_real_attach_to_window;
	MATENU_SETTINGS_CLASS (klass)->get_show_local_menu = matenu_settings_real_get_show_local_menu;
	MATENU_SETTINGS_CLASS (klass)->set_show_local_menu = matenu_settings_real_set_show_local_menu;
	MATENU_SETTINGS_CLASS (klass)->get_show_menu_icons = matenu_settings_real_get_show_menu_icons;
	MATENU_SETTINGS_CLASS (klass)->set_show_menu_icons = matenu_settings_real_set_show_menu_icons;
	MATENU_SETTINGS_CLASS (klass)->get_changed_notify_timeout = matenu_settings_real_get_changed_notify_timeout;
	MATENU_SETTINGS_CLASS (klass)->set_changed_notify_timeout = matenu_settings_real_set_changed_notify_timeout;
	G_OBJECT_CLASS (klass)->get_property = matenu_settings_get_property;
	G_OBJECT_CLASS (klass)->set_property = matenu_settings_set_property;
	G_OBJECT_CLASS (klass)->finalize = matenu_settings_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), MATENU_SETTINGS_WINDOW, g_param_spec_object ("window", "window", "window", GDK_TYPE_WINDOW, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), MATENU_SETTINGS_SHOW_LOCAL_MENU, g_param_spec_boolean ("show-local-menu", "show-local-menu", "show-local-menu", TRUE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), MATENU_SETTINGS_SHOW_MENU_ICONS, g_param_spec_boolean ("show-menu-icons", "show-menu-icons", "show-menu-icons", TRUE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), MATENU_SETTINGS_CHANGED_NOTIFY_TIMEOUT, g_param_spec_int ("changed-notify-timeout", "changed-notify-timeout", "changed-notify-timeout", G_MININT, G_MAXINT, 500, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void matenu_settings_instance_init (MatenuSettings * self) {
	self->priv = MATENU_SETTINGS_GET_PRIVATE (self);
	self->priv->atom = gdk_atom_intern ("_NET_GLOBALMENU_SETTINGS", FALSE);
	self->keyfile = g_key_file_new ();
	self->priv->_show_local_menu = TRUE;
	self->priv->_show_menu_icons = TRUE;
	self->priv->_changed_notify_timeout = 500;
}


static void matenu_settings_finalize (GObject* obj) {
	MatenuSettings * self;
	self = MATENU_SETTINGS (obj);
	{
		matenu_settings_attach_to_window (self, NULL);
	}
	_g_object_unref0 (self->priv->_window);
	_g_key_file_free0 (self->keyfile);
	G_OBJECT_CLASS (matenu_settings_parent_class)->finalize (obj);
}


GType matenu_settings_get_type (void) {
	static volatile gsize matenu_settings_type_id__volatile = 0;
	if (g_once_init_enter (&matenu_settings_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MatenuSettingsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) matenu_settings_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (MatenuSettings), 0, (GInstanceInitFunc) matenu_settings_instance_init, NULL };
		GType matenu_settings_type_id;
		matenu_settings_type_id = g_type_register_static (G_TYPE_OBJECT, "MatenuSettings", &g_define_type_info, 0);
		g_once_init_leave (&matenu_settings_type_id__volatile, matenu_settings_type_id);
	}
	return matenu_settings_type_id__volatile;
}


static void matenu_settings_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	MatenuSettings * self;
	self = MATENU_SETTINGS (object);
	switch (property_id) {
		case MATENU_SETTINGS_WINDOW:
		g_value_set_object (value, matenu_settings_get_window (self));
		break;
		case MATENU_SETTINGS_SHOW_LOCAL_MENU:
		g_value_set_boolean (value, matenu_settings_get_show_local_menu (self));
		break;
		case MATENU_SETTINGS_SHOW_MENU_ICONS:
		g_value_set_boolean (value, matenu_settings_get_show_menu_icons (self));
		break;
		case MATENU_SETTINGS_CHANGED_NOTIFY_TIMEOUT:
		g_value_set_int (value, matenu_settings_get_changed_notify_timeout (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void matenu_settings_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	MatenuSettings * self;
	self = MATENU_SETTINGS (object);
	switch (property_id) {
		case MATENU_SETTINGS_WINDOW:
		matenu_settings_set_window (self, g_value_get_object (value));
		break;
		case MATENU_SETTINGS_SHOW_LOCAL_MENU:
		matenu_settings_set_show_local_menu (self, g_value_get_boolean (value));
		break;
		case MATENU_SETTINGS_SHOW_MENU_ICONS:
		matenu_settings_set_show_menu_icons (self, g_value_get_boolean (value));
		break;
		case MATENU_SETTINGS_CHANGED_NOTIFY_TIMEOUT:
		matenu_settings_set_changed_notify_timeout (self, g_value_get_int (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



