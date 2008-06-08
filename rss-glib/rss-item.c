/* rss-item.c - RSS-GLib versioning information
 * 
 * This file is part of RSS-GLib.
 * Copyright (C) 2008  Christian Hergert <chris@dronelabs.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author:
 *   Christian Hergert  <chris@dronelabs.com>
 */

#include "rss-item.h"
#include "rss-item-private.h"

G_DEFINE_TYPE (RssItem, rss_item, G_TYPE_OBJECT)

enum {
	PROP_0,

	TITLE,
	LINK,
	DESCRIPTION,
	COPYRIGHT,
	AUTHOR,
	AUTHOR_URI,
	AUTHOR_EMAIL,
	CONTRIBUTOR,
	CONTRIBUTOR_URI,
	CONTRIBUTOR_EMAIL,
	COMMENTS,
	PUB_DATE,
	GUID,
	SOURCE,
	SOURCE_URL
};

static void
rss_item_get_property (GObject    *object,
                       guint       property_id,
                       GValue     *value,
                       GParamSpec *pspec)
{
	switch (property_id) {
	case TITLE:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->title);
		break;
	case LINK:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->link);
		break;
	case DESCRIPTION:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->description);
		break;
	case COPYRIGHT:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->copyright);
		break;
	case AUTHOR:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->author);
		break;
	case AUTHOR_URI:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->author_uri);
		break;
	case AUTHOR_EMAIL:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->author_email);
		break;
	case CONTRIBUTOR:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->contributor);
		break;
	case CONTRIBUTOR_URI:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->contributor_uri);
		break;
	case CONTRIBUTOR_EMAIL:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->contributor_email);
		break;
	case COMMENTS:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->comments);
		break;
	case PUB_DATE:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->pub_date);
		break;
	case GUID:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->guid);
		break;
	case SOURCE:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->source);
		break;
	case SOURCE_URL:
		g_value_set_string (value,
				ITEM_PRIVATE (object)->source_url);
		break;

	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
	}
}

static void
rss_item_set_property (GObject      *object,
                       guint         property_id,
                       const GValue *value,
		       GParamSpec   *pspec)
{
	switch (property_id) {
	case TITLE:
		g_free (ITEM_PRIVATE (object)->title);
		ITEM_PRIVATE (object)->title
			= g_strdup (g_value_get_string (value));
		break;
	case LINK:
		g_free (ITEM_PRIVATE (object)->link);
		ITEM_PRIVATE (object)->link
			= g_strdup (g_value_get_string (value));
		break;
	case DESCRIPTION:
		g_free (ITEM_PRIVATE (object)->description);
		ITEM_PRIVATE (object)->description
			= g_strdup (g_value_get_string (value));
		break;
	case COPYRIGHT:
		g_free (ITEM_PRIVATE (object)->copyright);
		ITEM_PRIVATE (object)->copyright
			= g_strdup (g_value_get_string (value));
		break;
	case AUTHOR:
		g_free (ITEM_PRIVATE (object)->author);
		ITEM_PRIVATE (object)->author
			= g_strdup (g_value_get_string (value));
		break;
	case AUTHOR_URI:
		g_free (ITEM_PRIVATE (object)->author_uri);
		ITEM_PRIVATE (object)->author_uri
			= g_strdup (g_value_get_string (value));
		break;
	case AUTHOR_EMAIL:
		g_free (ITEM_PRIVATE (object)->author_email);
		ITEM_PRIVATE (object)->author_email
			= g_strdup (g_value_get_string (value));
		break;
	case CONTRIBUTOR:
		g_free (ITEM_PRIVATE (object)->contributor);
		ITEM_PRIVATE (object)->contributor
			= g_strdup (g_value_get_string (value));
		break;
	case CONTRIBUTOR_URI:
		g_free (ITEM_PRIVATE (object)->contributor_uri);
		ITEM_PRIVATE (object)->contributor_uri
			= g_strdup (g_value_get_string (value));
		break;
	case CONTRIBUTOR_EMAIL:
		g_free (ITEM_PRIVATE (object)->contributor_email);
		ITEM_PRIVATE (object)->contributor_email
			= g_strdup (g_value_get_string (value));
		break;
	case COMMENTS:
		g_free (ITEM_PRIVATE (object)->comments);
		ITEM_PRIVATE (object)->comments
			= g_strdup (g_value_get_string (value));
		break;
	case PUB_DATE:
		g_free (ITEM_PRIVATE (object)->pub_date);
		ITEM_PRIVATE (object)->pub_date
			= g_strdup (g_value_get_string (value));
		break;
	case GUID:
		g_free (ITEM_PRIVATE (object)->guid);
		ITEM_PRIVATE (object)->guid
			= g_strdup (g_value_get_string (value));
		break;
	case SOURCE:
		g_free (ITEM_PRIVATE (object)->source);
		ITEM_PRIVATE (object)->source
			= g_strdup (g_value_get_string (value));
		break;
	case SOURCE_URL:
		g_free (ITEM_PRIVATE (object)->source_url);
		ITEM_PRIVATE (object)->source_url
			= g_strdup (g_value_get_string (value));
		break;

	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
	}
}

static void
rss_item_dispose (GObject *object)
{
	if (G_OBJECT_CLASS (rss_item_parent_class)->dispose)
		G_OBJECT_CLASS (rss_item_parent_class)->dispose (object);
}

static void
rss_item_class_init (RssItemClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);
	g_type_class_add_private (klass, sizeof (RssItemPrivate));
	object_class->get_property = rss_item_get_property;
	object_class->set_property = rss_item_set_property;
	object_class->dispose = rss_item_dispose;

	g_object_class_install_property (object_class, TITLE,
			g_param_spec_string ("title", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, LINK,
			g_param_spec_string ("link", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, DESCRIPTION,
			g_param_spec_string ("description", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, COPYRIGHT,
			g_param_spec_string ("copyright", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, AUTHOR,
			g_param_spec_string ("author", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, AUTHOR_URI,
			g_param_spec_string ("author-uri", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, AUTHOR_EMAIL,
			g_param_spec_string ("author-email", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, CONTRIBUTOR,
			g_param_spec_string ("contributor", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, CONTRIBUTOR_URI,
			g_param_spec_string ("contributor-uri", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, CONTRIBUTOR_EMAIL,
			g_param_spec_string ("contributor-email", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, COMMENTS,
			g_param_spec_string ("comments", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, PUB_DATE,
			g_param_spec_string ("pub-date", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, GUID,
			g_param_spec_string ("guid", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, SOURCE,
			g_param_spec_string ("source", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (object_class, SOURCE_URL,
			g_param_spec_string ("source-url", NULL, NULL, NULL,
					G_PARAM_READABLE | G_PARAM_WRITABLE));
}

static void
rss_item_init (RssItem *self)
{
}

RssItem*
rss_item_new (void)
{
	return g_object_new (RSS_TYPE_ITEM, NULL);
}
