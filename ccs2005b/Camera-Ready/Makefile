TITLE = p12-rubin
BIBFILE = bibliography.bib
SOURCES = $(TITLE).tex abstract.tex Intro.tex rw.tex \
          sec3.tex sec4.tex sec5.tex sec6.tex conclusions.tex \
          appendix.tex ./tables/TableInterpetation.tex
# sec5.tex 
EPSFIGS=$(wildcard figures/*.eps)
PDFFIGS=$(patsubst %.eps,%.pdf,$(EPSFIGS))

# -------------------------------------------------------------------------
#
# Generic targets

all: dvi ps

clean: 
	@rm -f *.pdf *.ps *.aux *.bbl *.blg *.dvi *.*~ *.bak *~


dvi:	$(TITLE).dvi
ps:	$(TITLE).ps
pdf:	$(TITLE).pdf
pdffigs: $(PDFFIGS)

.PHONY : dvi ps pdf directpdf pdffigs

# -------------------------------------------------------------------------
#
# Latex to Postscript

$(TITLE).bbl: $(BIBFILE)
	@latex $(TITLE)
	@bibtex $(TITLE)
	@latex $(TITLE)

$(TITLE).dvi: $(TITLE).bbl  $(SOURCES)
	@latex $(TITLE)
	@latex $(TITLE)
	@latex $(TITLE)

$(TITLE).ps: $(TITLE).dvi
	@dvips -o $(TITLE).ps $(TITLE).dvi
#	@kill -SIGHUP 11828

# -------------------------------------------------------------------------
#
# Latex to PDF

$(TITLE).pdf:	$(TITLE).dvi
	@dvipdf $(TITLE).dvi
#	ps2pdf -dMaxSubsetPct=100 -dCompatibilityLevel=1.2 -dSubsetFonts=true -dEmbedAllFonts=true $(TITLE).ps


%.pdf: %.eps
	@echo "Creating $@ from $<..."
	@gs -q -sDEVICE=pdfwrite -dCompatibilityLevel=1.3 -dEmbedAllFonts=true -dPDFSETTINGS=/printer -dEPSCrop -dNOPAUSE -dBATCH "-sOutputFile=$@" "$<"
	@echo "	done."

directpdf: pdffigs
	@pdflatex $(TITLE)
	@bibtex $(TITLE)
	@pdflatex $(TITLE)
	@pdflatex $(TITLE)
