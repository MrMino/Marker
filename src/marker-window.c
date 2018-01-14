/*
 * marker-window.c
 *
 * Copyright (C) 2017 - 2018 Fabio Colacio
 *
 * Marker is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * Marker is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with Marker; see the file LICENSE.md. If not,
 * see <http://www.gnu.org/licenses/>.
 *
 */

#include "marker-editor.h"

#include "marker-window.h"

struct _MarkerWindow
{
  GtkApplicationWindow  parent_instance;
  
  GtkBox               *vbox;
  MarkerEditor         *editor;
};

G_DEFINE_TYPE (MarkerWindow, marker_window, GTK_TYPE_APPLICATION_WINDOW);

static void
init_ui (MarkerWindow *window)
{
  gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET (window->vbox));
  gtk_box_pack_start (window->vbox, GTK_WIDGET (window->editor), TRUE, TRUE, 0);
}

static void
marker_window_init (MarkerWindow *window)
{
  window->vbox = GTK_BOX (gtk_box_new (GTK_ORIENTATION_VERTICAL, 0));
  window->editor = marker_editor_new ();
  
  init_ui (window);
}

static void
marker_window_class_init (MarkerWindowClass *class)
{

}

MarkerWindow *
marker_window_new (GtkApplication *app)
{
  return g_object_new (MARKER_TYPE_WINDOW, "application", app, NULL);
}

MarkerWindow *
marker_window_new_from_file (GtkApplication *app,
                             GFile          *file)
{
  return g_object_new (MARKER_TYPE_WINDOW, "application", app, NULL);
}
