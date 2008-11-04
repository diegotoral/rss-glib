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

G_DEFINE_TYPE (RssItem, rss_item, G_TYPE_OBJECT);

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
        RssItemPrivate *priv = RSS_ITEM (object)->priv;

	switch (property_id) {
	case PROP_TITLE:
		g_value_set_string (value, priv->title);
		break;
	case PROP_LINK:
		g_value_set_string (value, priv->link);
		break;
	case PROP_DESCRIPTION:
		g_value_set_string (value, priv->description);
		break;
	case PROP_COPYRIGHT:
		g_value_set_string (value, priv->copyright);
		break;
	case PROP_AUTHOR:
		g_value_set_string (value, priv->author);
		break;
	case PROP_AUTHOR_URI:
		g_value_set_string (value, priv->author_uri);
		break;
	case PROP_AUTHOR_EMAIL:
		g_value_set_string (value, priv->author_email);
		break;
	case PROP_CONTRIBUTOR:
		g_value_set_string (value, priv->contributor);
		break;
	case PROP_CONTRIBUTOR_URI:
		g_value_set_string (value, priv->contributor_uri);
		break;
	case PROP_CONTRIBUTOR_EMAIL:
		g_value_set_string (value, priv->contributor_email);
		break;
	case PROP_COMMENTS:
		g_value_set_string (value, priv->comments);
		break;
	case PROP_PUB_DATE:
		g_value_set_string (value, priv->pub_date);
		break;
	case PROP_GUID:
		g_value_set_string (value, priv->guid);
		break;
	case PROP_SOURCE:
		g_value_set_string (value, priv->source);
		break;
	case PROP_SOURCE_URL:
		g_value_set_string (value, priv->source_url);
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
        RssItemPrivate *priv = RSS_ITEM (object)->priv;

	switch (property_id) {
	case PROP_TITLE:
		g_free (priv->title);
		priv->title = g_value_dup_string (value);
		break;
	case PROP_LINK:
		g_free (priv->link);
		priv->link = g_value_dup_string (value);
		break;
	case PROP_DESCRIPTION:
		g_free (priv->description);
		priv->description = g_value_dup_string (value);
		break;
	case PROP_COPYRIGHT:
		g_free (priv->copyright);
		priv->copyright = g_value_dup_string (value);
		break;
	case PROP_AUTHOR:
		g_free (priv->author);
		priv->author = g_value_dup_string (value);
		break;
	case PROP_AUTHOR_URI:
		g_free (priv->author_uri);
		priv->author_uri = g_value_dup_string (value);
		break;
	case PROP_AUTHOR_EMAIL:
		g_free (priv->author_email);
		priv->author_email = g_value_dup_string (value);
		break;
	case PROP_CONTRIBUTOR:
		g_free (priv->contributor);
		priv->contributor = g_value_dup_string (value);
		break;
	case PROP_CONTRIBUTOR_URI:
		g_free (priv->contributor_uri);
		priv->contributor_uri = g_value_dup_string (value);
		break;
	case PROP_CONTRIBUTOR_EMAIL:
		g_free (priv->contributor_email);
		priv->contributor_email = g_value_dup_string (value);
		break;
	case PROP_COMMENTS:
		g_free (priv->comments);
		priv->comments = g_value_dup_string (value);
		break;
	case PROP_PUB_DATE:
		g_free (priv->pub_date);
		priv->pub_date = g_value_dup_string (value);
		break;
	case PROP_GUID:
		g_free (priv->guid);
		priv->guid = g_value_dup_string (value);
		break;
	case PROP_SOURCE:
		g_free (priv->source);
		priv->source = g_value_dup_string (value);
		break;
	case PROP_SOURCE_URL:
		g_free (priv->source_url);
		priv->source_url = g_value_dup_string (value);
		break;

	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
	}
}

static void
rss_item_finalize (GObject *object)
{
  RssItemPrivate *priv = RSS_ITEM (object)->priv;

  g_free (priv->guid);
  g_free (priv->title);
  g_free (priv->link);
  g_free (priv->description);
  g_free (priv->copyright);
  g_free (priv->author);
  g_free (priv->author_uri);
  g_free (priv->author_email);
  g_free (priv->contributor);
  g_free (priv->contributor_uri);
  g_free (priv->contributor_email);
  g_free (priv->comments);
  g_free (priv->pub_date);
  g_free (priv->source);
  g_free (priv->source_url);
  
  g_list_foreach (priv->categories, (GFunc) g_free, NULL);
  g_list_free (priv->categories);

  G_OBJECT_CLASS (rss_item_parent_class)->finalize (object);
}

static void
rss_item_class_init (RssItemClass *klass)
{
	GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
	g_type_class_add_private (klass, sizeof (RssItemPrivate));
	gobject_class->get_property = rss_item_get_property;
	gobject_class->set_property = rss_item_set_property;
	gobject_class->finalize = rss_item_finalize;

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
        pspec = g_param_spec_string ("guid",
                                     "GUID",
                                     "The guid of the item",
                                     NULL,
		                     G_PARAM_READWRITE);
	g_object_class_install_property (gobject_class,
                                         PROP_GUID,
                                         pspec);

	/**
	 * RssItem:source:
	 *
	 * The name of the source of the item.
	 */
        pspec = g_param_spec_string ("source",
                                     "Source",
                                     "Source of the item",
                                     NULL,
		                     G_PARAM_READWRITE);
	g_object_class_install_property (gobject_class,
                                         PROP_SOURCE,
                                         pspec);

	/**
	 * RssItem:source-url:
	 *
	 * The url of the source of the item.
	 */
        pspec = g_param_spec_string ("source-url",
                                     "Source URL",
                                     "URL of the source",
                                     NULL,
		                     G_PARAM_READWRITE);
	g_object_class_install_property (gobject_class,
                                         PROP_SOURCE_URL,
                                         pspec);
}

static void
rss_item_init (RssItem *self)
{
  self->priv =
    G_TYPE_INSTANCE_GET_PRIVATE (self, RSS_TYPE_ITEM, RssItemPrivate);
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

/**
 * rss_item_get_categories:
 * @self: a #RssItem
 *
 * Returns a copy of the list of categories for the #RssItem. The data
 * in the linked list are pointers to strings (char*).  They are owned
 * by the #RssItem and should not be modified.  Use g_strdup() to copy
 * the individual strings.
 *
 * Returns: a new #GList which should be freed with g_list_free().
 */
GList*
rss_item_get_categories (RssItem *self)
{
	g_return_val_if_fail (RSS_IS_ITEM (self), NULL);

	return g_list_copy (self->priv->categories);
}
