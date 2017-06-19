# Makefile for the Paper

SRC=$(shell ls *.tex acmstyle.cls styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)

default: pdf

pdf: asplos2008.pdf

asplos2008.pdf: $(SRC)
	latex asplos2008
	bibtex asplos2008
	latex asplos2008
	latex asplos2008
	dvipdf asplos2008
	rm -f *.log *.aux *.blg *.cb *.bak *.bbl *.blg *.log *.aux 

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out \
		sections/*.bak
