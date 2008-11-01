/* rss-item.c
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

/**
 * SECTION:rss-item
 * @short_description: a RSS entry representation
 *
 * #RssItem is the representation of an individual item parsed from a
 * #RssDocument.  This would mean an individual article, or note within
 * the source feed.
 */

#include "rss-item.h"
#include "rss-item-private.h"

G_DEFINE_TYPE (RssItem, rss_item, G_TYPE_OBJECT)

enum {
	PROP_0,

	PROP_TITLE,
	PROP_LINK,
	PROP_DESCRIPTION,
	PROP_COPYRIGHT,
	PROP_AUTHOR,
	PROP_AUTHOR_URI,
	PROP_AUTHOR_EMAIL,
	PROP_CONTRIBUTOR,
	PROP_CONTRIBUTOR_URI,
	PROP_CONTRIBUTOR_EMAIL,
	PROP_COMMENTS,
	PROP_PUB_DATE,
	PROP_GUID,
	PROP_SOURCE,
	PROP_SOURCE_URL
};

static void
rss_item_get_property (GObject    *object,
                       guint       property_id,
                       GValue     *value,
                       GParamSpec *pspec)
{
	switch (property_id) {
	case PROP_TITLE:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->title);
		break;
	case PROP_LINK:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->link);
		break;
	case PROP_DESCRIPTION:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->description);
		break;
	case PROP_COPYRIGHT:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->copyright);
		break;
	case PROP_AUTHOR:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->author);
		break;
	case PROP_AUTHOR_URI:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->author_uri);
		break;
	case PROP_AUTHOR_EMAIL:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->author_email);
		break;
	case PROP_CONTRIBUTOR:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->contributor);
		break;
	case PROP_CONTRIBUTOR_URI:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->contributor_uri);
		break;
	case PROP_CONTRIBUTOR_EMAIL:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->contributor_email);
		break;
	case PROP_COMMENTS:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->comments);
		break;
	case PROP_PUB_DATE:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->pub_date);
		break;
	case PROP_GUID:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->guid);
		break;
	case PROP_SOURCE:
		g_value_set_string (value,
		                    ITEM_PRIVATE (object)->source);
		break;
	case PROP_SOURCE_URL:
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
	case PROP_TITLE:
		g_free (ITEM_PRIVATE (object)->title);
		ITEM_PRIVATE (object)->title
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_LINK:
		g_free (ITEM_PRIVATE (object)->link);
		ITEM_PRIVATE (object)->link
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_DESCRIPTION:
		g_free (ITEM_PRIVATE (object)->description);
		ITEM_PRIVATE (object)->description
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_COPYRIGHT:
		g_free (ITEM_PRIVATE (object)->copyright);
		ITEM_PRIVATE (object)->copyright
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_AUTHOR:
		g_free (ITEM_PRIVATE (object)->author);
		ITEM_PRIVATE (object)->author
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_AUTHOR_URI:
		g_free (ITEM_PRIVATE (object)->author_uri);
		ITEM_PRIVATE (object)->author_uri
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_AUTHOR_EMAIL:
		g_free (ITEM_PRIVATE (object)->author_email);
		ITEM_PRIVATE (object)->author_email
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_CONTRIBUTOR:
		g_free (ITEM_PRIVATE (object)->contributor);
		ITEM_PRIVATE (object)->contributor
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_CONTRIBUTOR_URI:
		g_free (ITEM_PRIVATE (object)->contributor_uri);
		ITEM_PRIVATE (object)->contributor_uri
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_CONTRIBUTOR_EMAIL:
		g_free (ITEM_PRIVATE (object)->contributor_email);
		ITEM_PRIVATE (object)->contributor_email
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_COMMENTS:
		g_free (ITEM_PRIVATE (object)->comments);
		ITEM_PRIVATE (object)->comments
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_PUB_DATE:
		g_free (ITEM_PRIVATE (object)->pub_date);
		ITEM_PRIVATE (object)->pub_date
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_GUID:
		g_free (ITEM_PRIVATE (object)->guid);
		ITEM_PRIVATE (object)->guid
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_SOURCE:
		g_free (ITEM_PRIVATE (object)->source);
		ITEM_PRIVATE (object)->source
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_SOURCE_URL:
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
	GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
	g_type_class_add_private (klass, sizeof (RssItemPrivate));
	gobject_class->get_property = rss_item_get_property;
	gobject_class->set_property = rss_item_set_property;
	gobject_class->dispose = rss_item_dispose;

	/**
	 * RssItem:title:
	 *
	 * The title of the item.
	 */
	g_object_class_install_property (
		gobject_class, PROP_TITLE,
		g_param_spec_string ("title", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:link:
	 *
	 * The link to the upstream source of the item.
	 */
	g_object_class_install_property (
		gobject_class, PROP_LINK,
		g_param_spec_string ("link", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:description:
	 *
	 * The description of the item.  This is often where the actual
	 * content for the item is stored.
	 */
	g_object_class_install_property (
		gobject_class, PROP_DESCRIPTION,
		g_param_spec_string ("description", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:copyright:
	 *
	 * Any associated copyright that may exist for the content.
	 */
	g_object_class_install_property (
		gobject_class, PROP_COPYRIGHT,
		g_param_spec_string ("copyright", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:author:
	 *
	 * The authors name.
	 */
	g_object_class_install_property (
		gobject_class, PROP_AUTHOR,
		g_param_spec_string ("author", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:author-uri:
	 *
	 * The authors uri, often a website.
	 */
	g_object_class_install_property (
		gobject_class, PROP_AUTHOR_URI,
		g_param_spec_string ("author-uri", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:author-email:
	 *
	 * The authors email.
	 */
	g_object_class_install_property (
		gobject_class, PROP_AUTHOR_EMAIL,
		g_param_spec_string ("author-email", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:contributor:
	 *
	 * The contributors name.
	 */
	g_object_class_install_property (
		gobject_class, PROP_CONTRIBUTOR,
		g_param_spec_string ("contributor", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:contributor-uri:
	 *
	 * The contributors uri, often a website.
	 */
	g_object_class_install_property (
		gobject_class, PROP_CONTRIBUTOR_URI,
		g_param_spec_string ("contributor-uri", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:contributor-email:
	 *
	 * The contributors email.
	 */
	g_object_class_install_property (
		gobject_class, PROP_CONTRIBUTOR_EMAIL,
		g_param_spec_string ("contributor-email", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:comments:
	 *
	 * Any comments that may have been associated with the item.
	 */
	g_object_class_install_property (
		gobject_class, PROP_COMMENTS,
		g_param_spec_string ("comments", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:pub-date:
	 *
	 * The string representation of the publish date.
	 */
	g_object_class_install_property (
		gobject_class, PROP_PUB_DATE,
		g_param_spec_string ("pub-date", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:guid:
	 *
	 * The guid of the item. Many feed engines will use the url here
	 * plus some tag metadata.
	 */
	g_object_class_install_property (
		gobject_class, PROP_GUID,
		g_param_spec_string ("guid", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:source:
	 *
	 * The name of the source of the item.
	 */
	g_object_class_install_property (
		gobject_class, PROP_SOURCE,
		g_param_spec_string ("source", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssItem:source-url:
	 *
	 * The url of the source of the item.
	 */
	g_object_class_install_property (
		gobject_class, PROP_SOURCE_URL,
		g_param_spec_string ("source-url", NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));
}

static void
rss_item_init (RssItem *self)
{
}

/**
 * rss_item_new:
 *
 * Creates a new #RssItem.  This isn't incredibly useful yet as we do not
 * have an RssGenerator written.  However, that will come eventuall and
 * make creating feeds much simpler.
 *
 * Returns: a new #RssItem which should be unref'd with g_object_unref().
 */
RssItem*
rss_item_new (void)
{
	return g_object_new (RSS_TYPE_ITEM, NULL);
}
