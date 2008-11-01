using GLib;
using Rss;

public class Example.Main {
	static void main (string[] args) {
		Parser parser = new Parser ();

		if (!parser.load_from_file ("/tmp/atom.xml")) {
			error ("Couldn't parse the file");
		}
		else {
			var doc = parser.get_document ();

			foreach (Item item in doc.get_items ()) {
				stdout.printf ("Title: %s\n", item.title);
			}
		}
	}
}
