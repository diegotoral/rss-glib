using System;
using System.IO;
using Rss;

public class Test {
	public static void Main () {
		// only needed when no other gtk/glib/gobject libs are beind
		// used. gtk for example will init the gobject type system.
		Global.Init ();

		var data = File.ReadAllText ("/tmp/atom.xml");
		var parser = new Parser ();
		if (parser.LoadFromData (data)) {
			var doc = parser.Document;
			foreach (Item item in doc.Items)
				Console.WriteLine (item.Title);
		}
	}
}
