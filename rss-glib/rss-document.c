/* rss-document.c
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
 * SECTION:rss-document
 * @short_description: a RSS document representation
 * @see_also: rss_parser_get_document()
 *
 * #RssDocument is the representation of the resource that was parsed. It
 * contains a list of RssItem's which in turn contain article information.
 */

#include "rss-document.h"
#include "rss-document-private.h"

G_DEFINE_TYPE (RssDocument, rss_document, G_TYPE_OBJECT)

enum {
	PROP_0,

	PROP_ENCODING,
	PROP_GUID,
	PROP_TITLE,
	PROP_DESCRIPTION,
	PROP_LINK,
	PROP_LANGUAGE,
	PROP_RATING,
	PROP_COPYRIGHT,
	PROP_PUB_DATE,
	PROP_PUB_DATE_PARSED,
	PROP_EDITOR,
	PROP_EDITOR_EMAIL,
	PROP_EDITOR_URI,
	PROP_TTL,
	PROP_ABOUT,
	PROP_CONTRIBUTOR,
	PROP_CONTRIBUTOR_EMAIL,
	PROP_CONTRIBUTOR_URI,
	PROP_GENERATOR,
	PROP_GENERATOR_URI,
	PROP_GENERATOR_VERSION,
	PROP_IMAGE_TITLE,
	PROP_IMAGE_URL,
	PROP_IMAGE_LINK
};

static void
rss_document_get_property (GObject    *object,
                           guint       property_id,
                           GValue     *value,
                           GParamSpec *pspec)
{
	switch (property_id) {
	case PROP_ENCODING:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->encoding);
		break;
	case PROP_GUID:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->guid);
		break;
	case PROP_TITLE:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->title);
		break;
	case PROP_DESCRIPTION:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->description);
		break;
	case PROP_LINK:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->link);
		break;
	case PROP_LANGUAGE:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->language);
		break;
	case PROP_RATING:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->rating);
		break;
	case PROP_COPYRIGHT:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->copyright);
		break;
	case PROP_PUB_DATE:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->pub_date);
		break;
	case PROP_EDITOR:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->editor);
		break;
	case PROP_EDITOR_EMAIL:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->editor_email);
		break;
	case PROP_EDITOR_URI:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->editor_uri);
		break;
	case PROP_ABOUT:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->about);
		break;
	case PROP_CONTRIBUTOR:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->contributor);
		break;
	case PROP_CONTRIBUTOR_EMAIL:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->contributor_email);
		break;
	case PROP_CONTRIBUTOR_URI:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->contributor_uri);
		break;
	case PROP_GENERATOR:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->generator);
		break;
	case PROP_GENERATOR_URI:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->generator_uri);
		break;
	case PROP_GENERATOR_VERSION:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->generator_version);
		break;
	case PROP_IMAGE_TITLE:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->image_title);
		break;
	case PROP_IMAGE_URL:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->image_url);
		break;
	case PROP_IMAGE_LINK:
		g_value_set_string (value,
			DOCUMENT_PRIVATE (object)->image_link);
		break;
	case PROP_TTL:
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
	case PROP_ENCODING:
		g_free (DOCUMENT_PRIVATE (object)->encoding);
		DOCUMENT_PRIVATE (object)->encoding
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_GUID:
		g_free (DOCUMENT_PRIVATE (object)->guid);
		DOCUMENT_PRIVATE (object)->guid
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_TITLE:
		g_free (DOCUMENT_PRIVATE (object)->title);
		DOCUMENT_PRIVATE (object)->title
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_DESCRIPTION:
		g_free (DOCUMENT_PRIVATE (object)->description);
		DOCUMENT_PRIVATE (object)->description
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_LINK:
		g_free (DOCUMENT_PRIVATE (object)->link);
		DOCUMENT_PRIVATE (object)->link
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_LANGUAGE:
		g_free (DOCUMENT_PRIVATE (object)->language);
		DOCUMENT_PRIVATE (object)->language
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_RATING:
		g_free (DOCUMENT_PRIVATE (object)->rating);
		DOCUMENT_PRIVATE (object)->rating
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_COPYRIGHT:
		g_free (DOCUMENT_PRIVATE (object)->copyright);
		DOCUMENT_PRIVATE (object)->copyright
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_PUB_DATE:
		g_free (DOCUMENT_PRIVATE (object)->pub_date);
		DOCUMENT_PRIVATE (object)->pub_date
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_EDITOR:
		g_free (DOCUMENT_PRIVATE (object)->editor);
		DOCUMENT_PRIVATE (object)->editor
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_EDITOR_EMAIL:
		g_free (DOCUMENT_PRIVATE (object)->editor_email);
		DOCUMENT_PRIVATE (object)->editor_email
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_EDITOR_URI:
		g_free (DOCUMENT_PRIVATE (object)->editor_uri);
		DOCUMENT_PRIVATE (object)->editor_uri
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_ABOUT:
		g_free (DOCUMENT_PRIVATE (object)->about);
		DOCUMENT_PRIVATE (object)->about
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_CONTRIBUTOR:
		g_free (DOCUMENT_PRIVATE (object)->contributor);
		DOCUMENT_PRIVATE (object)->contributor
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_CONTRIBUTOR_EMAIL:
		g_free (DOCUMENT_PRIVATE (object)->contributor_email);
		DOCUMENT_PRIVATE (object)->contributor_email
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_CONTRIBUTOR_URI:
		g_free (DOCUMENT_PRIVATE (object)->contributor_uri);
		DOCUMENT_PRIVATE (object)->contributor_uri
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_GENERATOR:
		g_free (DOCUMENT_PRIVATE (object)->generator);
		DOCUMENT_PRIVATE (object)->generator
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_GENERATOR_URI:
		g_free (DOCUMENT_PRIVATE (object)->generator_uri);
		DOCUMENT_PRIVATE (object)->generator_uri
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_GENERATOR_VERSION:
		g_free (DOCUMENT_PRIVATE (object)->generator_version);
		DOCUMENT_PRIVATE (object)->generator_version
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_IMAGE_TITLE:
		g_free (DOCUMENT_PRIVATE (object)->image_title);
		DOCUMENT_PRIVATE (object)->image_title
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_IMAGE_URL:
		g_free (DOCUMENT_PRIVATE (object)->image_url);
		DOCUMENT_PRIVATE (object)->image_url
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_IMAGE_LINK:
		g_free (DOCUMENT_PRIVATE (object)->image_link);
		DOCUMENT_PRIVATE (object)->image_link
			= g_strdup (g_value_get_string (value));
		break;
	case PROP_TTL:
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

	/* free the items */
	g_list_foreach (DOCUMENT_PRIVATE (object)->items,
	                (GFunc) g_object_unref, NULL);
	g_list_free (DOCUMENT_PRIVATE (object)->items);

	/* free the category strings */
	g_list_foreach (DOCUMENT_PRIVATE (object)->categories,
	                (GFunc) g_free, NULL);
	g_list_free (DOCUMENT_PRIVATE (object)->categories);

	if (G_OBJECT_CLASS (rss_document_parent_class)->dispose)
		G_OBJECT_CLASS (rss_document_parent_class)->dispose (object);
}

static void
rss_document_class_init (RssDocumentClass *klass)
{
	GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
	g_type_class_add_private (klass, sizeof (RssDocumentPrivate));
	gobject_class->get_property = rss_document_get_property;
	gobject_class->set_property = rss_document_set_property;
	gobject_class->dispose = rss_document_dispose;

	/**
	 * RssDocument:encoding:
	 *
	 * The encoding of the #RssDocument.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_ENCODING,
		g_param_spec_string ("encoding",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:guid:
	 *
	 * The guid associated with the feed. This is often the url of the
	 * feed.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_GUID,
		g_param_spec_string ("guid",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:title:
	 *
	 * The title of the #RssDocument.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_TITLE,
		g_param_spec_string ("title",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:description:
	 *
	 * The description of the #RssDocument.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_DESCRIPTION,
		g_param_spec_string ("description",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:link:
	 *
	 * The link to the source document.  This is parsed from the actual
	 * document and can point to whatever the source publisher choses.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_LINK,
		g_param_spec_string ("link",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:language:
	 *
	 * The language the #RssDocument was published in.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_LANGUAGE,
		g_param_spec_string ("language",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:rating:
	 *
	 * The rating associated with the #RssDocument.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_RATING,
		g_param_spec_string ("rating",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:copyright:
	 *
	 * The copyright of the #RssDocument.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_COPYRIGHT,
		g_param_spec_string ("copyright",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:pub-date:
	 *
	 * The string representation of the date the document was published.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_PUB_DATE,
		g_param_spec_string ("pub-date",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:editor:
	 *
	 * The name of the editor.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_EDITOR,
		g_param_spec_string ("editor",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:editor-email:
	 *
	 * The email address of the editor.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_EDITOR_EMAIL,
		g_param_spec_string ("editor-email",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:editor-uri:
	 *
	 * The uri for more information about the editor.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_EDITOR_URI,
		g_param_spec_string ("editor-uri",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:about:
	 *
	 * Information about the #RssDocument.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_ABOUT,
		g_param_spec_string ("about",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:contributor:
	 *
	 * The name of the particular contributor.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_CONTRIBUTOR,
		g_param_spec_string ("contributor",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:contributor-email:
	 *
	 * The email of the particular contributor.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_CONTRIBUTOR_EMAIL,
		g_param_spec_string ("contributor-email",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:contributor-uri:
	 *
	 * The uri to more information on the particular contributer.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_CONTRIBUTOR_URI,
		g_param_spec_string ("contributor-uri",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:generator:
	 *
	 * The name of the generator on the server side.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_GENERATOR,
		g_param_spec_string ("generator",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:generator-uri:
	 *
	 * Url to more information about the generator on the server side.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_GENERATOR_URI,
		g_param_spec_string ("generator-uri",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:generator-version:
	 *
	 * The version of the server side generator.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_GENERATOR_VERSION,
		g_param_spec_string ("generator-version",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:image-title:
	 *
	 * The title for the image.  This is often the alt="" tag in HTML.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_IMAGE_TITLE,
		g_param_spec_string ("image-title",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:image-url:
	 *
	 * A url to the image for the RssDocument.  Use this before checking
	 * for a favicon.ico.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_IMAGE_URL,
		g_param_spec_string ("image-url",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:image-link:
	 *
	 * The url a user should be redirected to when clicking on the image
	 * for the #RssDocument.  Of course, its up to UI designers if they
	 * wish to implement this in any sort of way.
	 */
	g_object_class_install_property (
		gobject_class,
		PROP_IMAGE_LINK,
		g_param_spec_string ("image-link",
		                     NULL, NULL, NULL,
		                     G_PARAM_READABLE | G_PARAM_WRITABLE));

	/**
	 * RssDocument:ttl:
	 *
	 * The publisher determined TTL for the source. Readers should try
	 * to respect this value and not update feeds any more often than
	 * necessary.
	 */
	g_object_class_install_property (gobject_class, PROP_TTL,
		g_param_spec_int ("ttl", NULL, NULL,
			0, G_MAXINT32, 0,
			G_PARAM_READABLE | G_PARAM_WRITABLE));
}

static void
rss_document_init (RssDocument *self)
{
}

/**
 * rss_document_new:
 *
 * Creates a new instance of #RssDocument.  This isn't incredibly useful
 * currently, but is here none-the-less.  The desire is to create an
 * rss generator that will allow for building rss streams out of the
 * document hierarchy.
 *
 * Returns: a new #RssDocument. Use g_object_unref() when you are done.
 */
RssDocument*
rss_document_new (void)
{
	return g_object_new (RSS_TYPE_DOCUMENT, NULL);
}

/**
 * rss_document_get_items:
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
	g_return_val_if_fail (RSS_IS_DOCUMENT (self), NULL);
	return g_list_copy (DOCUMENT_PRIVATE (self)->items);
}

/**
 * rss_document_get_categories:
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
	g_return_val_if_fail (RSS_IS_DOCUMENT (self), NULL);
	return DOCUMENT_PRIVATE (self)->categories;
}
