/* rss-glib-1.0.vapi
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

[Import ()]
[CCode (cprefix = "Rss", lower_case_cprefix = "rss_", cheader_filename = "rss-glib/rss-glib.h")]
namespace Rss {
	public class Parser : GLib.Object {
		public Parser ();
		public bool load_from_data (string data, ulong length) throws GLib.Error;
		public bool load_from_file (string filename) throws GLib.Error;
		public Rss.Document get_document ();
	}

	public class Document : GLib.Object {
		[NoAccessorMethod]
		public string encoding { get; set; }
		[NoAccessorMethod]
		public string guid { get; set; }
		[NoAccessorMethod]
		public string title { get; set; }
		[NoAccessorMethod]
		public string description { get; set; }
		[NoAccessorMethod]
		public string link { get; set; }
		[NoAccessorMethod]
		public string language { get; set; }
		[NoAccessorMethod]
		public string rating { get; set; }
		[NoAccessorMethod]
		public string copyright { get; set; }
		[NoAccessorMethod]
		public string pub_date { get; set; }
		[NoAccessorMethod]
		public string editor { get; set; }
		[NoAccessorMethod]
		public string editor_email { get; set; }
		[NoAccessorMethod]
		public string editor_uri { get; set; }
		[NoAccessorMethod]
		public int ttl { get; set; }
		[NoAccessorMethod]
		public string about { get; set; }
		[NoAccessorMethod]
		public string contributor { get; set; }
		[NoAccessorMethod]
		public string contributor_email { get; set; }
		[NoAccessorMethod]
		public string contributor_uri { get; set; }
		[NoAccessorMethod]
		public string generator { get; set; }
		[NoAccessorMethod]
		public string generator_uri { get; set; }
		[NoAccessorMethod]
		public string generator_version { get; set; }
		[NoAccessorMethod]
		public string image_title { get; set; }
		[NoAccessorMethod]
		public string image_url { get; set; }
		[NoAccessorMethod]
		public string image_link { get; set; }
		public Document ();
		public GLib.List<Rss.Item> get_items ();
		public GLib.List<string> get_categories ();
	}

	public class Item : GLib.Object {
		[NoAccessorMethod]
		public string guid { get; set; }
		[NoAccessorMethod]
		public string title { get; set; }
		[NoAccessorMethod]
		public string link { get; set; }
		[NoAccessorMethod]
		public string description { get; set; }
		[NoAccessorMethod]
		public string copyright{ get; set; }
		[NoAccessorMethod]
		public string author { get; set; }
		[NoAccessorMethod]
		public string author_uri { get; set; }
		[NoAccessorMethod]
		public string author_email { get; set; }
		[NoAccessorMethod]
		public string contributor { get; set; }
		[NoAccessorMethod]
		public string contributor_uri { get; set; }
		[NoAccessorMethod]
		public string contributor_email { get; set; }
		[NoAccessorMethod]
		public string comments { get; set; }
		[NoAccessorMethod]
		public string pub_date { get; set; }
		[NoAccessorMethod]
		public string source { get; set; }
		[NoAccessorMethod]
		public string source_url { get; set; }
		public Item ();
		public GLib.List<string> get_categories ();
	}
}
