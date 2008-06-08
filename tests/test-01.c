#include <stdlib.h>

#include <glib.h>
#include <rss-glib/rss-glib.h>

void
print_tag (gchar *tag, gpointer user_data)
{
	g_print ("\t%s\n", tag);
}

int
main (int argc, char **argv)
{
	RssParser   *parser;
	RssDocument *document;
	GError      *error = NULL;
	gchar       *str;
	GList       *list;

	g_type_init ();

	parser = rss_parser_new ();
	g_assert (parser != NULL);

	if (!rss_parser_load_from_file (parser, "atom.xml", &error)) {
		g_error ("%s", error->message);
		return EXIT_FAILURE;
	}

	document = rss_parser_get_document (parser);

	g_object_get (document, "title", &str, NULL);
	g_print ("Title:        %s\n", str);

	g_object_get (document, "guid", &str, NULL);
	g_print ("Guid:         %s\n", str);

	g_object_get (document, "description", &str, NULL);
	g_print ("Description:  %s\n", str);

	g_object_get (document, "link", &str, NULL);
	g_print ("Link:         %s\n", str);

	g_object_get (document, "language", &str, NULL);
	g_print ("Language:     %s\n", str);

	g_object_get (document, "rating", &str, NULL);
	g_print ("Rating:       %s\n", str);

	g_object_get (document, "copyright", &str, NULL);
	g_print ("Copyright:    %s\n", str);

	g_object_get (document, "pub_date", &str, NULL);
	g_print ("Published:    %s\n", str);

	g_object_get (document, "editor", &str, NULL);
	g_print ("Editor:       %s\n", str);

	g_object_get (document, "generator", &str, NULL);
	g_print ("Generator:    %s\n", str);

	g_object_get (document, "image-title", &str, NULL);
	g_print ("Image Title:  %s\n", str);

	g_object_get (document, "image-url", &str, NULL);
	g_print ("Image Url:    %s\n", str);

	list = rss_document_get_tags (document);
	if (list != NULL ) {
		g_print ("Tags:\n");
		g_list_foreach (list, (GFunc) print_tag, NULL);
		g_list_free (list);
	}

	list = rss_document_get_categories (document);
	if (list != NULL ) {
		g_print ("Categories:\n");
		g_list_foreach (list, (GFunc) print_tag, NULL);
		g_list_free (list);
	}

	g_print ("\n");
	return EXIT_SUCCESS;
}
