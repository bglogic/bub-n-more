CVS_CHECKOUT = /home/arigo/octogone/games
BUBBOB = $(CVS_CHECKOUT)/bubbob
DOC    = $(BUBBOB)/doc


all: clean htdocs-all
	rm -fr `find htdocs -name CVS`

FORCE:

clean: FORCE
	rm -fr htdocs/*.*

htdocs-all: $(addprefix htdocs/,$(wildcard *.html images/*.*) crazybonuses.html)

htdocs/%: %
	-mkdir -p $(dir $@)
	cp $< $@

htdocs/crazybonuses.html: $(DOC)/bonuses.html
	cp -r $(DOC)/images htdocs/
	cp $(DOC)/bonuses.html $@

$(DOC)/bonuses.html: $(BUBBOB)/bonuses.py $(DOC)/bonus-doc.py
	(cd $(DOC) && python bonus-doc.py)

sf: all
	rsync -r --rsh=ssh --delete -z htdocs arigo@shell.sourceforge.net:/home/groups/b/bu/bub-n-bros
