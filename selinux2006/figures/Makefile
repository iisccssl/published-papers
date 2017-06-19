# Makefile for the Paper

FIGDIR = fig
EPSDIR = eps

all: eps

eps: $(shell ls $(FIGDIR)/*.fig | perl -p -e 's/fig/eps/g')

$(EPSDIR)/%.eps: $(FIGDIR)/%.fig
	fig2dev -Leps $< $@

clean:
	rm -f *.bak $(FIGDIR)/*.bak $(EPSDIR)/*.eps
