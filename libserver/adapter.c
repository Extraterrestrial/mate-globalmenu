/* adapter.c generated by valac, the Vala compiler
 * generated from adapter.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


#define MATENU_TYPE_SHELL (matenu_shell_get_type ())
#define MATENU_SHELL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MATENU_TYPE_SHELL, MatenuShell))
#define MATENU_IS_SHELL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MATENU_TYPE_SHELL))
#define MATENU_SHELL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), MATENU_TYPE_SHELL, MatenuShellIface))

typedef struct _MatenuShell MatenuShell;
typedef struct _MatenuShellIface MatenuShellIface;

#define MATENU_TYPE_ITEM (matenu_item_get_type ())
#define MATENU_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MATENU_TYPE_ITEM, MatenuItem))
#define MATENU_IS_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MATENU_TYPE_ITEM))
#define MATENU_ITEM_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), MATENU_TYPE_ITEM, MatenuItemIface))

typedef struct _MatenuItem MatenuItem;
typedef struct _MatenuItemIface MatenuItemIface;

#define MATENU_TYPE_ITEM_TYPE (matenu_item_type_get_type ())

#define MATENU_TYPE_ITEM_STATE (matenu_item_state_get_type ())

#define MATENU_TYPE_ADAPTER (matenu_adapter_get_type ())
#define MATENU_ADAPTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MATENU_TYPE_ADAPTER, MatenuAdapter))
#define MATENU_ADAPTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), MATENU_TYPE_ADAPTER, MatenuAdapterClass))
#define MATENU_IS_ADAPTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MATENU_TYPE_ADAPTER))
#define MATENU_IS_ADAPTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MATENU_TYPE_ADAPTER))
#define MATENU_ADAPTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), MATENU_TYPE_ADAPTER, MatenuAdapterClass))

typedef struct _MatenuAdapter MatenuAdapter;
typedef struct _MatenuAdapterClass MatenuAdapterClass;
typedef struct _MatenuAdapterPrivate MatenuAdapterPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

typedef enum  {
	MATENU_ITEM_TYPE_NORMAL = 0,
	MATENU_ITEM_TYPE_CHECK = 1,
	MATENU_ITEM_TYPE_RADIO = 2,
	MATENU_ITEM_TYPE_IMAGE = 3,
	MATENU_ITEM_TYPE_SEPARATOR = 4,
	MATENU_ITEM_TYPE_ARROW = 5,
	MATENU_ITEM_TYPE_ICON = 6
} MatenuItemType;

typedef enum  {
	MATENU_ITEM_STATE_UNTOGGLED = 0,
	MATENU_ITEM_STATE_TOGGLED = 1,
	MATENU_ITEM_STATE_TRISTATE = 2
} MatenuItemState;

struct _MatenuItemIface {
	GTypeInterface parent_iface;
	MatenuShell* (*get_shell) (MatenuItem* self);
	MatenuShell* (*get_sub_shell) (MatenuItem* self);
	gboolean (*get_has_sub_shell) (MatenuItem* self);
	void (*set_has_sub_shell) (MatenuItem* self, gboolean value);
	gboolean (*get_client_side_sub_shell) (MatenuItem* self);
	void (*set_client_side_sub_shell) (MatenuItem* self, gboolean value);
	const char* (*get_item_id) (MatenuItem* self);
	void (*set_item_id) (MatenuItem* self, const char* value);
	MatenuItemType (*get_item_type) (MatenuItem* self);
	void (*set_item_type) (MatenuItem* self, MatenuItemType value);
	gboolean (*get_item_use_underline) (MatenuItem* self);
	void (*set_item_use_underline) (MatenuItem* self, gboolean value);
	gboolean (*get_item_sensitive) (MatenuItem* self);
	void (*set_item_sensitive) (MatenuItem* self, gboolean value);
	gboolean (*get_item_visible) (MatenuItem* self);
	void (*set_item_visible) (MatenuItem* self, gboolean value);
	MatenuItemState (*get_item_state) (MatenuItem* self);
	void (*set_item_state) (MatenuItem* self, MatenuItemState value);
	const char* (*get_item_label) (MatenuItem* self);
	void (*set_item_label) (MatenuItem* self, const char* value);
	const char* (*get_item_icon) (MatenuItem* self);
	void (*set_item_icon) (MatenuItem* self, const char* value);
	const char* (*get_item_accel_text) (MatenuItem* self);
	void (*set_item_accel_text) (MatenuItem* self, const char* value);
	const char* (*get_item_font) (MatenuItem* self);
	void (*set_item_font) (MatenuItem* self, const char* value);
};

struct _MatenuShellIface {
	GTypeInterface parent_iface;
	MatenuItem* (*get_item) (MatenuShell* self, gint position);
	MatenuItem* (*get_item_by_id) (MatenuShell* self, const char* id);
	gint (*get_item_position) (MatenuShell* self, MatenuItem* item);
	MatenuItem* (*get_owner) (MatenuShell* self);
	gint (*get_length) (MatenuShell* self);
	void (*set_length) (MatenuShell* self, gint value);
};

struct _MatenuAdapter {
	GObject parent_instance;
	MatenuAdapterPrivate * priv;
};

struct _MatenuAdapterClass {
	GObjectClass parent_class;
};

struct _MatenuAdapterPrivate {
	GtkMenuShell* _gtk_shell;
	gboolean disposed;
	gboolean _is_topmost;
};


static GHashTable* matenu_adapter_a2g;
static GHashTable* matenu_adapter_a2g = NULL;
static GHashTable* matenu_adapter_g2a;
static GHashTable* matenu_adapter_g2a = NULL;
static gpointer matenu_adapter_parent_class = NULL;
static MatenuShellIface* matenu_adapter_matenu_shell_parent_iface = NULL;

GType matenu_item_type_get_type (void) G_GNUC_CONST;
GType matenu_item_state_get_type (void) G_GNUC_CONST;
GType matenu_item_get_type (void) G_GNUC_CONST;
GType matenu_shell_get_type (void) G_GNUC_CONST;
GType matenu_adapter_get_type (void) G_GNUC_CONST;
#define MATENU_ADAPTER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), MATENU_TYPE_ADAPTER, MatenuAdapterPrivate))
enum  {
	MATENU_ADAPTER_DUMMY_PROPERTY,
	MATENU_ADAPTER_GTK_SHELL,
	MATENU_ADAPTER_IS_TOPMOST,
	MATENU_ADAPTER_OWNER,
	MATENU_ADAPTER_LENGTH
};
void matenu_adapter_set_gtk_shell (MatenuAdapter* self, GtkMenuShell* value);
MatenuAdapter* matenu_adapter_new (GtkMenuShell* gtk_shell);
MatenuAdapter* matenu_adapter_construct (GType object_type, GtkMenuShell* gtk_shell);
GtkMenuShell* matenu_adapter_get_gtk_shell (MatenuAdapter* self);
static void matenu_adapter_real_dispose (GObject* base);
MatenuAdapter* matenu_adapter_get_adapter (GtkMenuShell* gtk_shell);
GtkMenuItem* gtk_menu_shell_get_item (GtkMenuShell* menu_shell, gint position);
static MatenuItem* matenu_adapter_real_get_item (MatenuShell* base, gint position);
gint matenu_shell_get_length (MatenuShell* self);
MatenuItem* matenu_shell_get_item (MatenuShell* self, gint position);
const char* matenu_item_get_item_id (MatenuItem* self);
static MatenuItem* matenu_adapter_real_get_item_by_id (MatenuShell* base, const char* id);
gint gtk_menu_shell_get_item_position (GtkMenuShell* menu_shell, GtkMenuItem* item);
static gint matenu_adapter_real_get_item_position (MatenuShell* base, MatenuItem* item);
gboolean matenu_adapter_get_is_topmost (MatenuAdapter* self);
void matenu_adapter_set_is_topmost (MatenuAdapter* self, gboolean value);
gint gtk_menu_shell_get_length (GtkMenuShell* menushell);
void gtk_menu_shell_set_length (GtkMenuShell* menushell, gint length);
static GObject * matenu_adapter_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void matenu_adapter_finalize (GObject* obj);
MatenuItem* matenu_shell_get_owner (MatenuShell* self);
static void matenu_adapter_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
void matenu_shell_set_length (MatenuShell* self, gint value);
static void matenu_adapter_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);



MatenuAdapter* matenu_adapter_construct (GType object_type, GtkMenuShell* gtk_shell) {
	GParameter * __params;
	GParameter * __params_it;
	MatenuAdapter * self;
	g_return_val_if_fail (gtk_shell != NULL, NULL);
	__params = g_new0 (GParameter, 1);
	__params_it = __params;
	__params_it->name = "gtk-shell";
	g_value_init (&__params_it->value, GTK_TYPE_MENU_SHELL);
	g_value_set_object (&__params_it->value, gtk_shell);
	__params_it++;
	self = g_object_newv (object_type, __params_it - __params, __params);
	while (__params_it > __params) {
		--__params_it;
		g_value_unset (&__params_it->value);
	}
	g_free (__params);
	return self;
}


MatenuAdapter* matenu_adapter_new (GtkMenuShell* gtk_shell) {
	return matenu_adapter_construct (MATENU_TYPE_ADAPTER, gtk_shell);
}


static void matenu_adapter_real_dispose (GObject* base) {
	MatenuAdapter * self;
	self = (MatenuAdapter*) base;
	if (!self->priv->disposed) {
		g_hash_table_remove (matenu_adapter_a2g, self);
		g_hash_table_remove (matenu_adapter_g2a, self->priv->_gtk_shell);
		self->priv->disposed = TRUE;
	}
	G_OBJECT_CLASS (matenu_adapter_parent_class)->dispose (G_OBJECT (self));
}


MatenuAdapter* matenu_adapter_get_adapter (GtkMenuShell* gtk_shell) {
	MatenuAdapter* result = NULL;
	MatenuAdapter* a;
	g_return_val_if_fail (gtk_shell != NULL, NULL);
	if (matenu_adapter_g2a == NULL) {
		result = NULL;
		return result;
	}
	a = (MatenuAdapter*) g_hash_table_lookup (matenu_adapter_g2a, gtk_shell);
	result = a;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static MatenuItem* matenu_adapter_real_get_item (MatenuShell* base, gint position) {
	MatenuAdapter * self;
	MatenuItem* result = NULL;
	GtkMenuItem* _tmp0_;
	self = (MatenuAdapter*) base;
	result = _g_object_ref0 ((_tmp0_ = gtk_menu_shell_get_item (self->priv->_gtk_shell, position), MATENU_IS_ITEM (_tmp0_) ? ((MatenuItem*) _tmp0_) : NULL));
	return result;
}


static MatenuItem* matenu_adapter_real_get_item_by_id (MatenuShell* base, const char* id) {
	MatenuAdapter * self;
	MatenuItem* result = NULL;
	gint length;
	self = (MatenuAdapter*) base;
	g_return_val_if_fail (id != NULL, NULL);
	length = matenu_shell_get_length ((MatenuShell*) self);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				MatenuItem* item;
				if (!_tmp0_) {
					i++;
				}
				_tmp0_ = FALSE;
				if (!(i < length)) {
					break;
				}
				item = matenu_shell_get_item ((MatenuShell*) self, i);
				if (_vala_strcmp0 (matenu_item_get_item_id (item), id) == 0) {
					result = item;
					return result;
				}
				_g_object_unref0 (item);
			}
		}
	}
	result = NULL;
	return result;
}


static gint matenu_adapter_real_get_item_position (MatenuShell* base, MatenuItem* item) {
	MatenuAdapter * self;
	gint result = 0;
	self = (MatenuAdapter*) base;
	g_return_val_if_fail (item != NULL, 0);
	result = gtk_menu_shell_get_item_position (self->priv->_gtk_shell, (GtkMenuItem*) item);
	return result;
}


GtkMenuShell* matenu_adapter_get_gtk_shell (MatenuAdapter* self) {
	GtkMenuShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_gtk_shell;
	return result;
}


void matenu_adapter_set_gtk_shell (MatenuAdapter* self, GtkMenuShell* value) {
	GtkMenuShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_gtk_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_gtk_shell), _tmp0_);
	g_object_notify ((GObject *) self, "gtk-shell");
}


gboolean matenu_adapter_get_is_topmost (MatenuAdapter* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_topmost;
	return result;
}


void matenu_adapter_set_is_topmost (MatenuAdapter* self, gboolean value) {
	g_return_if_fail (self != NULL);
	self->priv->_is_topmost = value;
	g_object_notify ((GObject *) self, "is-topmost");
}


static MatenuItem* matenu_adapter_real_get_owner (MatenuShell* base) {
	MatenuItem* result;
	MatenuAdapter* self;
	self = (MatenuAdapter*) base;
	if (self->priv->_is_topmost) {
		result = NULL;
		return result;
	}
	if (GTK_IS_MENU_BAR (self->priv->_gtk_shell)) {
		result = NULL;
		return result;
	}
	if (GTK_IS_MENU (self->priv->_gtk_shell)) {
		GtkMenuShell* _tmp0_;
		GtkWidget* _tmp1_;
		result = (_tmp1_ = gtk_menu_get_attach_widget ((_tmp0_ = self->priv->_gtk_shell, GTK_IS_MENU (_tmp0_) ? ((GtkMenu*) _tmp0_) : NULL)), MATENU_IS_ITEM (_tmp1_) ? ((MatenuItem*) _tmp1_) : NULL);
		return result;
	}
	result = NULL;
	return result;
}


static gint matenu_adapter_real_get_length (MatenuShell* base) {
	gint result;
	MatenuAdapter* self;
	self = (MatenuAdapter*) base;
	result = gtk_menu_shell_get_length (self->priv->_gtk_shell);
	return result;
}


static void matenu_adapter_real_set_length (MatenuShell* base, gint value) {
	MatenuAdapter* self;
	self = (MatenuAdapter*) base;
	gtk_menu_shell_set_length (self->priv->_gtk_shell, value);
	g_object_notify ((GObject *) self, "length");
}


static GObject * matenu_adapter_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	MatenuAdapter * self;
	parent_class = G_OBJECT_CLASS (matenu_adapter_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = MATENU_ADAPTER (obj);
	{
		g_hash_table_insert (matenu_adapter_a2g, self, _g_object_ref0 (self->priv->_gtk_shell));
		g_hash_table_insert (matenu_adapter_g2a, _g_object_ref0 (self->priv->_gtk_shell), self);
	}
	return obj;
}


static void matenu_adapter_class_init (MatenuAdapterClass * klass) {
	matenu_adapter_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (MatenuAdapterPrivate));
	G_OBJECT_CLASS (klass)->dispose = matenu_adapter_real_dispose;
	G_OBJECT_CLASS (klass)->get_property = matenu_adapter_get_property;
	G_OBJECT_CLASS (klass)->set_property = matenu_adapter_set_property;
	G_OBJECT_CLASS (klass)->constructor = matenu_adapter_constructor;
	G_OBJECT_CLASS (klass)->finalize = matenu_adapter_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), MATENU_ADAPTER_GTK_SHELL, g_param_spec_object ("gtk-shell", "gtk-shell", "gtk-shell", GTK_TYPE_MENU_SHELL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
	g_object_class_install_property (G_OBJECT_CLASS (klass), MATENU_ADAPTER_IS_TOPMOST, g_param_spec_boolean ("is-topmost", "is-topmost", "is-topmost", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_override_property (G_OBJECT_CLASS (klass), MATENU_ADAPTER_OWNER, "owner");
	g_object_class_override_property (G_OBJECT_CLASS (klass), MATENU_ADAPTER_LENGTH, "length");
	matenu_adapter_a2g = g_hash_table_new_full (g_direct_hash, g_direct_equal, NULL, g_object_unref);
	matenu_adapter_g2a = g_hash_table_new_full (g_direct_hash, g_direct_equal, g_object_unref, NULL);
}


static void matenu_adapter_matenu_shell_interface_init (MatenuShellIface * iface) {
	matenu_adapter_matenu_shell_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_item = matenu_adapter_real_get_item;
	iface->get_item_by_id = matenu_adapter_real_get_item_by_id;
	iface->get_item_position = matenu_adapter_real_get_item_position;
	iface->get_owner = matenu_adapter_real_get_owner;
	iface->get_length = matenu_adapter_real_get_length;
	iface->set_length = matenu_adapter_real_set_length;
}


static void matenu_adapter_instance_init (MatenuAdapter * self) {
	self->priv = MATENU_ADAPTER_GET_PRIVATE (self);
	self->priv->disposed = FALSE;
	self->priv->_is_topmost = FALSE;
}


static void matenu_adapter_finalize (GObject* obj) {
	MatenuAdapter * self;
	self = MATENU_ADAPTER (obj);
	_g_object_unref0 (self->priv->_gtk_shell);
	G_OBJECT_CLASS (matenu_adapter_parent_class)->finalize (obj);
}


GType matenu_adapter_get_type (void) {
	static volatile gsize matenu_adapter_type_id__volatile = 0;
	if (g_once_init_enter (&matenu_adapter_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MatenuAdapterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) matenu_adapter_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (MatenuAdapter), 0, (GInstanceInitFunc) matenu_adapter_instance_init, NULL };
		static const GInterfaceInfo matenu_shell_info = { (GInterfaceInitFunc) matenu_adapter_matenu_shell_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType matenu_adapter_type_id;
		matenu_adapter_type_id = g_type_register_static (G_TYPE_OBJECT, "MatenuAdapter", &g_define_type_info, 0);
		g_type_add_interface_static (matenu_adapter_type_id, MATENU_TYPE_SHELL, &matenu_shell_info);
		g_once_init_leave (&matenu_adapter_type_id__volatile, matenu_adapter_type_id);
	}
	return matenu_adapter_type_id__volatile;
}


static void matenu_adapter_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	MatenuAdapter * self;
	self = MATENU_ADAPTER (object);
	switch (property_id) {
		case MATENU_ADAPTER_GTK_SHELL:
		g_value_set_object (value, matenu_adapter_get_gtk_shell (self));
		break;
		case MATENU_ADAPTER_IS_TOPMOST:
		g_value_set_boolean (value, matenu_adapter_get_is_topmost (self));
		break;
		case MATENU_ADAPTER_OWNER:
		g_value_set_object (value, matenu_shell_get_owner ((MatenuShell*) self));
		break;
		case MATENU_ADAPTER_LENGTH:
		g_value_set_int (value, matenu_shell_get_length ((MatenuShell*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void matenu_adapter_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	MatenuAdapter * self;
	self = MATENU_ADAPTER (object);
	switch (property_id) {
		case MATENU_ADAPTER_GTK_SHELL:
		matenu_adapter_set_gtk_shell (self, g_value_get_object (value));
		break;
		case MATENU_ADAPTER_IS_TOPMOST:
		matenu_adapter_set_is_topmost (self, g_value_get_boolean (value));
		break;
		case MATENU_ADAPTER_LENGTH:
		matenu_shell_set_length ((MatenuShell*) self, g_value_get_int (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




