/* locator.c generated by valac, the Vala compiler
 * generated from locator.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct _Locator Locator;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))

struct _Locator {
	int dummy;
};



void locator_free (Locator* self);
static Locator* locator_new (void);
static Locator* locator_new (void);
GtkMenuItem* locator_locate (GtkMenuBar* menubar, const char* path);
static void locator_instance_init (Locator * self);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);



static Locator* locator_new (void) {
	Locator* self;
	self = g_slice_new0 (Locator);
	locator_instance_init (self);
	return self;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


GtkMenuItem* locator_locate (GtkMenuBar* menubar, const char* path) {
	GtkMenuItem* result = NULL;
	char** _tmp1_;
	gint _tokens_size_;
	gint tokens_length1;
	char** _tmp0_;
	char** tokens;
	GtkMenuShell* shell;
	g_return_val_if_fail (menubar != NULL, NULL);
	g_return_val_if_fail (path != NULL, NULL);
	tokens = (_tmp1_ = _tmp0_ = g_strsplit_set (path, "/", -1), tokens_length1 = _vala_array_length (_tmp0_), _tokens_size_ = tokens_length1, _tmp1_);
	tokens_length1 = (gint) g_strv_length (tokens);
	shell = _g_object_ref0 ((GtkMenuShell*) menubar);
	{
		gint i;
		i = 1;
		{
			gboolean _tmp2_;
			_tmp2_ = TRUE;
			while (TRUE) {
				const char* token;
				GtkMenuItem* item;
				GList* children;
				GtkMenuShell* _tmp7_;
				if (!_tmp2_) {
					i++;
				}
				_tmp2_ = FALSE;
				if (!(i < tokens_length1)) {
					break;
				}
				token = tokens[i];
				item = NULL;
				children = gtk_container_get_children ((GtkContainer*) shell);
				if (g_str_has_prefix (token, "W")) {
					gulong pointer;
					pointer = strtoul (g_utf8_offset_to_pointer (token, (glong) 1), NULL, 0);
					{
						GList* child_collection;
						GList* child_it;
						child_collection = children;
						for (child_it = child_collection; child_it != NULL; child_it = child_it->next) {
							GtkWidget* child;
							child = (GtkWidget*) child_it->data;
							{
								if (((gulong) child) == pointer) {
									GtkMenuItem* _tmp4_;
									GtkWidget* _tmp3_;
									item = (_tmp4_ = _g_object_ref0 ((_tmp3_ = child, GTK_IS_MENU_ITEM (_tmp3_) ? ((GtkMenuItem*) _tmp3_) : NULL)), _g_object_unref0 (item), _tmp4_);
									break;
								}
							}
						}
					}
				} else {
					gint position;
					position = atoi (token);
					{
						GList* child_collection;
						GList* child_it;
						child_collection = children;
						for (child_it = child_collection; child_it != NULL; child_it = child_it->next) {
							GtkWidget* child;
							child = (GtkWidget*) child_it->data;
							{
								if (GTK_IS_TEAROFF_MENU_ITEM (child)) {
									continue;
								}
								if (position == 0) {
									GtkMenuItem* _tmp6_;
									GtkWidget* _tmp5_;
									item = (_tmp6_ = _g_object_ref0 ((_tmp5_ = child, GTK_IS_MENU_ITEM (_tmp5_) ? ((GtkMenuItem*) _tmp5_) : NULL)), _g_object_unref0 (item), _tmp6_);
									break;
								}
								position--;
							}
						}
					}
				}
				if (i == (tokens_length1 - 1)) {
					result = item;
					_g_list_free0 (children);
					_g_object_unref0 (shell);
					tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
					return result;
				}
				if (item == NULL) {
					result = NULL;
					_g_list_free0 (children);
					_g_object_unref0 (item);
					_g_object_unref0 (shell);
					tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
					return result;
				}
				shell = (_tmp7_ = _g_object_ref0 ((GtkMenuShell*) gtk_menu_item_get_submenu (item)), _g_object_unref0 (shell), _tmp7_);
				if (shell == NULL) {
					result = NULL;
					_g_list_free0 (children);
					_g_object_unref0 (item);
					_g_object_unref0 (shell);
					tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
					return result;
				}
				_g_list_free0 (children);
				_g_object_unref0 (item);
			}
		}
	}
	result = NULL;
	_g_object_unref0 (shell);
	tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
	return result;
}


static void locator_instance_init (Locator * self) {
}


void locator_free (Locator* self) {
	g_slice_free (Locator, self);
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



