# Makefile for the Paper

FIGDIR = fig
EPSDIR = eps
PDFDIR = pdf

all: eps pdf

eps: $(shell ls $(FIGDIR)/*.fig | perl -p -e 's/fig/eps/g')

pdf: $(shell ls $(FIGDIR)/*.fig | perl -p -e 's/fig/pdf/g')

$(EPSDIR)/%.eps: $(FIGDIR)/%.fig
	fig2dev -Leps $< $@

$(PDFDIR)/%.pdf: $(EPSDIR)/%.eps
	epstopdf $< -o $@

clean:
	rm -f *.bak $(FIGDIR)/*.bak $(EPSDIR)/*.eps $(PDFDIR)/*.pdf
