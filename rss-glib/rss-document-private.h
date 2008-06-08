/* rss-document-private.h - RSS-GLib versioning information
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

#ifndef __RSS_DOCUMENT_PRIVATE_H__
#define __RSS_DOCUMENT_PRIVATE_H__

#include <mrss.h>

#define DOCUMENT_PRIVATE(o)				\
	(G_TYPE_INSTANCE_GET_PRIVATE ((o),		\
	RSS_TYPE_DOCUMENT,				\
	RssDocumentPrivate))

enum {
	ENCODING = 1,
	GUID,
	TITLE,
	DESCRIPTION,
	LINK,
	LANGUAGE,
	RATING,
	COPYRIGHT,
	PUB_DATE,
	PUB_DATE_PARSED,
	EDITOR,
	EDITOR_EMAIL,
	EDITOR_URI,
	TTL,
	ABOUT,
	CONTRIBUTOR,
	CONTRIBUTOR_EMAIL,
	CONTRIBUTOR_URI,
	GENERATOR,
	GENERATOR_URI,
	GENERATOR_VERSION,
	IMAGE_TITLE,
	IMAGE_URL,
	IMAGE_LINK,

	LAST_PROP
};

typedef struct _RssDocumentPrivate RssDocumentPrivate;

struct _RssDocumentPrivate {
	gchar *encoding;
	gchar *guid;
	gchar *title;
	gchar *description;
	gchar *link;
	gchar *language;
	gchar *rating;
	gchar *copyright;
	gchar *pub_date;
	gchar *editor;
	gchar *editor_email;
	gchar *editor_uri;
	gint   ttl;
	gchar *about;
	gchar *contributor;
	gchar *contributor_email;
	gchar *contributor_uri;
	gchar *generator;
	gchar *generator_uri;
	gchar *generator_version;
	gchar *image_title;
	gchar *image_url;
	gchar *image_link;

	GList *items;
	GList *tags;
	GList *categories;
};

#endif /* __RSS_DOCUMENT_PRIVATE_H__ */
