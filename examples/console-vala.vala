using GLib;
using Rss;

public class Test {
	static void main () {
		var parser = new Parser ();
		if (parser.load_from_file ("/tmp/atom.xml")) {
			var doc = parser.get_document ();
			foreach (var item in doc.get_items ())
				stdout.printf ("%s\n", item.title);
		}
	}
}
