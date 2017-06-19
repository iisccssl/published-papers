# Makefile for the Paper

FIGDIR = fig
EPSDIR = eps
PDFDIR = pdf

all: eps pdf
#all: eps 

pdf: $(shell ls $(FIGDIR)/*.fig | perl -p -e 's/fig/pdf/g')

dot: $(shell ls $(DOTDIR)/*.dot)

eps: $(shell ls $(FIGDIR)/*.fig | perl -p -e 's/fig/eps/g')

$(EPSDIR)/%.eps: $(FIGDIR)/%.fig
	fig2dev -Leps $< $@

$(FIGDIR)/%.fig: $(DOTDIR)/%.dot
	dot -Tfig $< >$@

$(PDFDIR)/%.pdf: $(EPSDIR)/%.eps
	epstopdf $< -o $@

clean:
	rm -f *.bak $(FIGDIR)/*.bak $(PDFDIR)/*.pdf $(EPSDIR)/*.eps
#clean:
#	rm -f *.bak $(FIGDIR)/*.bak $(EPSDIR)/*.eps
