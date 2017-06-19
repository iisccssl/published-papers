# Makefile for the Paper

FIGDIR = fig
EPSDIR = eps
PDFDIR = pdf

all: pdf eps

pdf: $(shell ls $(FIGDIR)/*.fig | perl -p -e 's/fig/pdf/g')

eps: $(shell ls $(FIGDIR)/*.fig | perl -p -e 's/fig/eps/g')

$(EPSDIR)/%.eps: $(FIGDIR)/%.fig
	fig2dev -Leps $< $@

$(PDFDIR)/%.pdf: $(FIGDIR)/%.fig 
	fig2dev -Lpdf $< $@

clean:
	rm -f *.bak $(FIGDIR)/*.bak $(PDFDIR)/*.pdf $(EPSDIR)/*.eps
