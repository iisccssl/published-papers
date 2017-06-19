DOCUMENT=paper

LATEX=latex
BIBTEX=bibtex
DVIPS=dvips
DVIPDF=dvipdf
FIG2DEV=fig2dev
FIGFILES=overview.pstex_t
#############################################################################
#  Rules 
#############################################################################

default: $(DOCUMENT).pdf $(DOCUMENT).ps

$(DOCUMENT).pdf: $(DOCUMENT).ps
	@$(LATEX) $(DOCUMENT)
	@$(LATEX) $(DOCUMENT)
	@$(DVIPDF) $(DOCUMENT)

$(DOCUMENT).ps: clean $(DOCUMENT).bbl $(FIGFILES) redo
	@$(LATEX) $(DOCUMENT)
	@$(LATEX) $(DOCUMENT)
	@$(DVIPS) $(DOCUMENT)

${DOCUMENT}.bbl:
	@$(LATEX) $(DOCUMENT).tex
	@$(BIBTEX) $(DOCUMENT)

$(FIGFILES): figs/overview.fig
	$(FIG2DEV) -L pstex figs/overview.fig > figs/overview.pstex
	$(FIG2DEV) -L pstex_t -p figs/overview.pstex figs/overview.fig > figs/overview.pstex_t


redo: 	$(DOCUMENT).bbl
	@$(LATEX) $(DOCUMENT).tex
	@$(LATEX) $(DOCUMENT).tex

clean:
	@rm -f $(DOCUMENT).ps $(DOCUMENT).dvi $(DOCUMENT).pdf
	@rm -f $(DOCUMENT).aux $(DOCUMENT).log $(DOCUMENT).tpt \
               $(DOCUMENT).brf $(DOCUMENT).out texput.log  \
				$(DOCUMENT).blg $(DOCUMENT).bbl
