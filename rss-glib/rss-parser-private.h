/* rss-parser-private.h
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

#ifndef __RSS_PARSER_PRIVATE_H__
#define __RSS_PARSER_PRIVATE_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define PARSER_PRIVATE(o)				\
	(G_TYPE_INSTANCE_GET_PRIVATE ((o),		\
	RSS_TYPE_PARSER,				\
	RssParserPrivate))

typedef struct _RssParserPrivate RssParserPrivate;

struct _RssParserPrivate
{
	RssDocument *document;
};

G_END_DECLS

#endif /* __RSS_PARSER_PRIVATE_H__ */
