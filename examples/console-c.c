#include <glib.h>
#include <rss-glib/rss-glib.h>

int
main (int argc, char **argv)
{
	g_type_init ();

	RssParser *parser = rss_parser_new ();

	if (rss_parser_load_from_file (parser, "/tmp/atom.xml", NULL)) {
		RssDocument *doc = rss_parser_get_document (parser);
		GList *list, *tmp;
		gchar *title;

		list = rss_document_get_items (doc);

		for (tmp = list; tmp != NULL; tmp = tmp->next) {
			g_object_get (tmp->data, "title", &title, NULL);
			g_print ("%s\n", title);
			g_free (title);
		}

		g_list_free (list);
		g_object_unref (doc);
	}

	g_object_unref (parser);
}
