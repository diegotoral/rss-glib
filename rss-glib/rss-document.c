/* rss-document.c - RSS-GLib versioning information
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

#include "rss-document.h"
#include "rss-document-private.h"

G_DEFINE_TYPE (RssDocument, rss_document, G_TYPE_OBJECT)

static void
rss_document_get_property (GObject    *object,
                           guint       property_id,
                           GValue     *value,
                           GParamSpec *pspec)
{
	switch (property_id) {
	case ENCODING:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->encoding);
		break;
	case GUID:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->guid);
		break;
	case TITLE:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->title);
		break;
	case DESCRIPTION:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->description);
		break;
	case LINK:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->link);
		break;
	case LANGUAGE:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->language);
		break;
	case RATING:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->rating);
		break;
	case COPYRIGHT:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->copyright);
		break;
	case PUB_DATE:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->pub_date);
		break;
	case EDITOR:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->editor);
		break;
	case EDITOR_EMAIL:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->editor_email);
		break;
	case EDITOR_URI:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->editor_uri);
		break;
	case ABOUT:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->about);
		break;
	case CONTRIBUTOR:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->contributor);
		break;
	case CONTRIBUTOR_EMAIL:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->contributor_email);
		break;
	case CONTRIBUTOR_URI:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->contributor_uri);
		break;
	case GENERATOR:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->generator);
		break;
	case GENERATOR_URI:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->generator_uri);
		break;
	case GENERATOR_VERSION:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->generator_version);
		break;
	case IMAGE_TITLE:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->image_title);
		break;
	case IMAGE_URL:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->image_url);
		break;
	case IMAGE_LINK:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->image_link);
		break;
	case TTL:
		g_value_set_int (value, DOCUMENT_PRIVATE (object)->ttl);
		break;

	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
	}
}

static void
rss_document_set_property (GObject      *object,
                           guint         property_id,
                           const GValue *value,
                           GParamSpec   *pspec)
{
	switch (property_id) {
	case ENCODING:
		g_free (DOCUMENT_PRIVATE (object)->encoding);
		DOCUMENT_PRIVATE (object)->encoding
			= g_strdup (g_value_get_string (value));
		break;
	case GUID:
		g_free (DOCUMENT_PRIVATE (object)->guid);
		DOCUMENT_PRIVATE (object)->guid
			= g_strdup (g_value_get_string (value));
		break;
	case TITLE:
		g_free (DOCUMENT_PRIVATE (object)->title);
		DOCUMENT_PRIVATE (object)->title
			= g_strdup (g_value_get_string (value));
		break;
	case DESCRIPTION:
		g_free (DOCUMENT_PRIVATE (object)->description);
		DOCUMENT_PRIVATE (object)->description
			= g_strdup (g_value_get_string (value));
		break;
	case LINK:
		g_free (DOCUMENT_PRIVATE (object)->link);
		DOCUMENT_PRIVATE (object)->link
			= g_strdup (g_value_get_string (value));
		break;
	case LANGUAGE:
		g_free (DOCUMENT_PRIVATE (object)->language);
		DOCUMENT_PRIVATE (object)->language
			= g_strdup (g_value_get_string (value));
		break;
	case RATING:
		g_free (DOCUMENT_PRIVATE (object)->rating);
		DOCUMENT_PRIVATE (object)->rating
			= g_strdup (g_value_get_string (value));
		break;
	case COPYRIGHT:
		g_free (DOCUMENT_PRIVATE (object)->copyright);
		DOCUMENT_PRIVATE (object)->copyright
			= g_strdup (g_value_get_string (value));
		break;
	case PUB_DATE:
		g_free (DOCUMENT_PRIVATE (object)->pub_date);
		DOCUMENT_PRIVATE (object)->pub_date
			= g_strdup (g_value_get_string (value));
		break;
	case EDITOR:
		g_free (DOCUMENT_PRIVATE (object)->editor);
		DOCUMENT_PRIVATE (object)->editor
			= g_strdup (g_value_get_string (value));
		break;
	case EDITOR_EMAIL:
		g_free (DOCUMENT_PRIVATE (object)->editor_email);
		DOCUMENT_PRIVATE (object)->editor_email
			= g_strdup (g_value_get_string (value));
		break;
	case EDITOR_URI:
		g_free (DOCUMENT_PRIVATE (object)->editor_uri);
		DOCUMENT_PRIVATE (object)->editor_uri
			= g_strdup (g_value_get_string (value));
		break;
	case ABOUT:
		g_free (DOCUMENT_PRIVATE (object)->about);
		DOCUMENT_PRIVATE (object)->about
			= g_strdup (g_value_get_string (value));
		break;
	case CONTRIBUTOR:
		g_free (DOCUMENT_PRIVATE (object)->contributor);
		DOCUMENT_PRIVATE (object)->contributor
			= g_strdup (g_value_get_string (value));
		break;
	case CONTRIBUTOR_EMAIL:
		g_free (DOCUMENT_PRIVATE (object)->contributor_email);
		DOCUMENT_PRIVATE (object)->contributor_email
			= g_strdup (g_value_get_string (value));
		break;
	case CONTRIBUTOR_URI:
		g_free (DOCUMENT_PRIVATE (object)->contributor_uri);
		DOCUMENT_PRIVATE (object)->contributor_uri
			= g_strdup (g_value_get_string (value));
		break;
	case GENERATOR:
		g_free (DOCUMENT_PRIVATE (object)->generator);
		DOCUMENT_PRIVATE (object)->generator
			= g_strdup (g_value_get_string (value));
		break;
	case GENERATOR_URI:
		g_free (DOCUMENT_PRIVATE (object)->generator_uri);
		DOCUMENT_PRIVATE (object)->generator_uri
			= g_strdup (g_value_get_string (value));
		break;
	case GENERATOR_VERSION:
		g_free (DOCUMENT_PRIVATE (object)->generator_version);
		DOCUMENT_PRIVATE (object)->generator_version
			= g_strdup (g_value_get_string (value));
		break;
	case IMAGE_TITLE:
		g_free (DOCUMENT_PRIVATE (object)->image_title);
		DOCUMENT_PRIVATE (object)->image_title
			= g_strdup (g_value_get_string (value));
		break;
	case IMAGE_URL:
		g_free (DOCUMENT_PRIVATE (object)->image_url);
		DOCUMENT_PRIVATE (object)->image_url
			= g_strdup (g_value_get_string (value));
		break;
	case IMAGE_LINK:
		g_free (DOCUMENT_PRIVATE (object)->image_link);
		DOCUMENT_PRIVATE (object)->image_link
			= g_strdup (g_value_get_string (value));
		break;
	case TTL:
		DOCUMENT_PRIVATE (object)->ttl
			= g_value_get_int (value);
		break;

	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
	}
}

static void
rss_document_dispose (GObject *object)
{
	g_free (DOCUMENT_PRIVATE (object)->encoding);
	g_free (DOCUMENT_PRIVATE (object)->guid);
	g_free (DOCUMENT_PRIVATE (object)->title);
	g_free (DOCUMENT_PRIVATE (object)->description);
	g_free (DOCUMENT_PRIVATE (object)->link);
	g_free (DOCUMENT_PRIVATE (object)->language);
	g_free (DOCUMENT_PRIVATE (object)->rating);
	g_free (DOCUMENT_PRIVATE (object)->copyright);
	g_free (DOCUMENT_PRIVATE (object)->pub_date);
	g_free (DOCUMENT_PRIVATE (object)->editor);
	g_free (DOCUMENT_PRIVATE (object)->editor_email);
	g_free (DOCUMENT_PRIVATE (object)->editor_uri);
	g_free (DOCUMENT_PRIVATE (object)->about);
	g_free (DOCUMENT_PRIVATE (object)->contributor);
	g_free (DOCUMENT_PRIVATE (object)->contributor_email);
	g_free (DOCUMENT_PRIVATE (object)->contributor_uri);
	g_free (DOCUMENT_PRIVATE (object)->generator);
	g_free (DOCUMENT_PRIVATE (object)->generator_uri);
	g_free (DOCUMENT_PRIVATE (object)->generator_version);
	g_free (DOCUMENT_PRIVATE (object)->image_title);
	g_free (DOCUMENT_PRIVATE (object)->image_url);
	g_free (DOCUMENT_PRIVATE (object)->image_link);

	if (G_OBJECT_CLASS (rss_document_parent_class)->dispose)
		G_OBJECT_CLASS (rss_document_parent_class)->dispose (object);
}

static void
string_prop (GObjectClass *object_class, guint prop, gchar *name)
{
	g_object_class_install_property (object_class, prop,
		g_param_spec_string (name, NULL, NULL, NULL,
				     G_PARAM_READABLE | G_PARAM_WRITABLE));

}

static void
rss_document_class_init (RssDocumentClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);
	g_type_class_add_private (klass, sizeof (RssDocumentPrivate));
	object_class->get_property = rss_document_get_property;
	object_class->set_property = rss_document_set_property;
	object_class->dispose = rss_document_dispose;

	string_prop (object_class, ENCODING,		"encoding");
	string_prop (object_class, GUID,		"guid");
	string_prop (object_class, TITLE,		"title");
	string_prop (object_class, DESCRIPTION,		"description");
	string_prop (object_class, LINK,		"link");
	string_prop (object_class, LANGUAGE,		"language");
	string_prop (object_class, RATING,		"rating");
	string_prop (object_class, COPYRIGHT,		"copyright");
	string_prop (object_class, PUB_DATE,		"pub-date");
	string_prop (object_class, EDITOR,		"editor");
	string_prop (object_class, EDITOR_EMAIL,	"editor-email");
	string_prop (object_class, EDITOR_URI,		"editor-uri");
	string_prop (object_class, ABOUT,		"about");
	string_prop (object_class, CONTRIBUTOR,		"contributor");
	string_prop (object_class, CONTRIBUTOR_EMAIL,	"contributor-email");
	string_prop (object_class, CONTRIBUTOR_URI,	"contributor-uri");
	string_prop (object_class, GENERATOR,		"generator");
	string_prop (object_class, GENERATOR_URI,	"generator-uri");
	string_prop (object_class, GENERATOR_VERSION,	"generator-version");
	string_prop (object_class, IMAGE_TITLE,		"image-title");
	string_prop (object_class, IMAGE_URL,		"image-url");
	string_prop (object_class, IMAGE_LINK,		"image-link");

	g_object_class_install_property (object_class, TTL,
		g_param_spec_int ("ttl", NULL, NULL,
			0, G_MAXINT32, 0,
			G_PARAM_READABLE | G_PARAM_WRITABLE));
}

static void
rss_document_init (RssDocument *self)
{
}

RssDocument*
rss_document_new (void)
{
	return g_object_new (RSS_TYPE_DOCUMENT, NULL);
}

/**
 * RssDocument::get_items
 * @self: a #RssDocument
 *
 * Creates a #GList of items that were found in the syndication. The objects
 * in the list are weak references. Consumers of those objects should ref
 * them with g_object_ref.
 *
 * Returns: a new #GList owned by the caller.
 */
GList*
rss_document_get_items (RssDocument *self)
{
	return NULL;
}

/**
 * RssDocument::get_tags
 * @self: a #RssDocument
 *
 * Creates a #GList of tags found in the syndication. The objects in the list
 * are weak references. Consumers of those objects should ref them with
 * g_object_ref.
 *
 * Returns: a new #GList owned by the caller.
 */
GList*
rss_document_get_tags (RssDocument *self)
{
	return NULL;
}

/**
 * RssDocument::get_categories
 * @self: a #RssDocument
 *
 * Creates a #GList of categories found in the syndication. The objects
 * in the list are weak references. Consumers of those objects should
 * ref them with g_object_ref.
 *
 * Returns: a new #GList owned by the caller
 */
GList*
rss_document_get_categories (RssDocument *self)
{
	return NULL;
}
