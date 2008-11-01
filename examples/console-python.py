#!/usr/bin/env python

import rss

p = rss.Parser()
p.load_from_file('/tmp/atom.xml')
for item in p.get_document().get_items():
    print item.props.title

