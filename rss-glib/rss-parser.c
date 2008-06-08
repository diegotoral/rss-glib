/* rss-generator.c - RSS-GLib versioning information
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

#include "rss-parser.h"

#include "rss-item.h"
#include "rss-item-private.h"

#include "rss-document.h"
#include "rss-document-private.h"

#define PARSER_QUARK g_quark_from_static_string ("RssParser")
#define parser_error_new(...) (g_error_new (PARSER_QUARK, 0, __VA_ARGS__))

G_DEFINE_TYPE (RssParser, rss_parser, G_TYPE_OBJECT)

#define PARSER_PRIVATE(o)				\
	(G_TYPE_INSTANCE_GET_PRIVATE ((o),		\
	RSS_TYPE_PARSER,				\
	RssParserPrivate))

typedef struct _RssParserPrivate RssParserPrivate;

struct _RssParserPrivate {
	RssDocument *document;
};

static void
rss_parser_dispose (GObject *object)
{
	if (G_OBJECT_CLASS (rss_parser_parent_class)->dispose)
		G_OBJECT_CLASS (rss_parser_parent_class)->dispose (object);
}

static void
rss_parser_class_init (RssParserClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);
	g_type_class_add_private (klass, sizeof (RssParserPrivate));
	object_class->dispose = rss_parser_dispose;
}

static void
rss_parser_init (RssParser *self)
{
	PARSER_PRIVATE (self)->document = NULL;
}

RssParser*
rss_parser_new (void)
{
	return g_object_new (RSS_TYPE_PARSER, NULL);
}

static RssDocument*
rss_parser_parse (RssParser *self, mrss_t *mrss)
{
	RssDocument     *document;
	RssItem         *rss_item;
	GList           *list, *list2;
	mrss_category_t *cat;
	mrss_item_t     *item;

	g_return_val_if_fail (RSS_IS_PARSER (self), NULL);
	g_return_val_if_fail (mrss != NULL, NULL);

	/* create our document object */
	document = rss_document_new ();

	/* set our document level properties */
	g_object_set (document,
		      "encoding",		mrss->encoding,
		      "guid",			mrss->id,
		      "title",			mrss->title,
		      "description",		mrss->description,
		      "link",			mrss->link,
		      "language",		mrss->language,
		      "rating",			mrss->rating,
		      "copyright",		mrss->copyright,
		      "pub-date",		mrss->pubDate,
		      "ttl",			mrss->ttl,
		      "about",			mrss->about,
		      "contributor",		mrss->contributor,
		      "contributor-email",	mrss->contributor_email,
		      "contributor-uri",	mrss->contributor_uri,
		      "generator",		mrss->generator,
		      "generator-uri",		mrss->generator_uri,
		      "generator-version",	mrss->generator_version,
		      "image-title",		mrss->image_title,
		      "image-url",		mrss->image_url,
		      "image-link",		mrss->image_link,
		      NULL);

	/* build the list of categories */
	if (NULL != (cat = mrss->category)) {
		list = NULL;
		do {
			list = g_list_insert (list, g_strdup (cat->category), 0);
		} while (NULL != (cat = cat->next));
		DOCUMENT_PRIVATE (document)->categories = list;
	}

	/* build the list of items */
	if (NULL != (item = mrss->item)) {
		list = NULL;
		do {
			rss_item = rss_item_new ();

			/* set the rss item properties */
			g_object_set (rss_item,
				      "guid",			item->guid,
				      "title",			item->title,
				      "link",			item->link,
				      "description",		item->description,
				      "copyright",		item->copyright,
				      "author",			item->author,
				      "author-uri",		item->author_uri,
				      "author-email",		item->author_email,
				      "contributor",		item->contributor,
				      "contributor-uri",	item->contributor_uri,
				      "contributor-email",	item->contributor_email,
				      "comments",		item->comments,
				      "pub-date",		item->pubDate,
				      "source",			item->source,
				      "source-url",		item->source_url,
				      NULL);

			/* parse the items categories */
			if (NULL != (cat = item->category)) {
				list2 = NULL;
				do {
					list2 = g_list_insert (list2, g_strdup (cat->category), 0);
				} while (NULL != (cat = cat->next));
				ITEM_PRIVATE (rss_item)->categories = list2;
			}

			list = g_list_insert (list, rss_item, 0);
		} while (NULL != (item = item->next));
		DOCUMENT_PRIVATE (document)->items = list;
	}

	return document;
}

/**
 * RssParser::load_from_data
 * @self: a #RssParser
 * @data: a buffer containing the syndication data
 * @length: the length of the buffer
 * @error: a location to place a newly created GError in case of error
 *
 * Parses the contents found at @data as an rss file. You can retrieve
 * the parsed document with rss_parser_get_document().
 *
 * Returns: TRUE on success.
 */
gboolean
rss_parser_load_from_data (RssParser  *self,
			   gchar      *data,
			   gsize       length,
			   GError    **error)
{
	mrss_t       *mrss;
	mrss_error_t  res;

	/* parse the buffer */
	res = mrss_parse_buffer (data, length, &mrss);

	/* if there was an error parsing, set the error and return false */
	if (MRSS_OK != res) {
		if (error)
			*error = parser_error_new ("Could not parse data");
		return FALSE;
	}

	/* keep a copy of our parsed document */
	PARSER_PRIVATE (self)->document = rss_parser_parse (self, mrss);

	/* free our mrss data */
	mrss_free (mrss);

	return TRUE;
}

/**
 * RssParser::load_from_file
 * @self: a #RssParser
 * @filename: the path to the file to parse
 * @error: a location for a newly created #GError
 *
 * Parses the file found at @filename as an rss file. You can retrieve
 * the parsed document with rss_parser_get_document().
 *
 * Returns: TRUE if the parse was successful
 */
gboolean
rss_parser_load_from_file (RssParser  *self,
			   gchar      *filename,
			   GError    **error)
{
	mrss_t       *mrss;
	mrss_error_t  res;

	/* parse the buffer */
	res = mrss_parse_file (filename, &mrss);

	/* if there was an error parsing, set the error and return false */
	if (MRSS_OK != res) {
		if (error)
			*error = parser_error_new ("Could not parse file");
		return FALSE;
	}

	/* keep a copy of our parsed document */
	PARSER_PRIVATE (self)->document = rss_parser_parse (self, mrss);

	/* free our mrss data */
	mrss_free (mrss);

	return TRUE;
}

/**
 * RssParser::get_document
 *
 * Returns the document result from parsing rss data from either
 * a buffer or a file. The document's ref-count is increased, so
 * call g_object_unref when you are done.
 *
 * Returns: a #RssDocument
 */
RssDocument*
rss_parser_get_document (RssParser *self)
{
	return g_object_ref (PARSER_PRIVATE (self)->document);
}
