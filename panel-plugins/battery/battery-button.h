/*
 * * Copyright (C) 2014 Eric Koegel <eric@xfce.org>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __BATTERY_BUTTON_H
#define __BATTERY_BUTTON_H

#include <glib-object.h>
#include <gtk/gtk.h>
#ifdef XFCE_PLUGIN
#include <libxfce4panel/xfce-panel-plugin.h>
#endif
#ifdef LXDE_PLUGIN
#include <lxpanel/plugin.h>
#endif

G_BEGIN_DECLS

#define BATTERY_TYPE_BUTTON        (battery_button_get_type () )
#define BATTERY_BUTTON(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), BATTERY_TYPE_BUTTON, BatteryButton))
#define BATTERY_IS_BUTTON(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), BATTERY_TYPE_BUTTON))

typedef struct BatteryButtonPrivate BatteryButtonPrivate;

typedef struct
{
    GtkToggleButton           parent;
    BatteryButtonPrivate     *priv;

} BatteryButton;

typedef struct
{
    GtkToggleButtonClass parent_class;

} BatteryButtonClass;

GType                    battery_button_get_type (void) G_GNUC_CONST;

#ifdef XFCE_PLUGIN
GtkWidget               *battery_button_new       (XfcePanelPlugin *plugin);
#endif
#ifdef LXDE_PLUGIN
GtkWidget               *battery_button_new       (Plugin *plugin);
#endif

void                     battery_button_show      (BatteryButton *button);

void                     battery_button_set_width (BatteryButton *button, gint width);

G_END_DECLS

#endif /* __BATTERY_BUTTON_H */