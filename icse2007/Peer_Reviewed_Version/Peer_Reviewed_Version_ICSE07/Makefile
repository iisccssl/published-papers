# Makefile for the Paper

SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)

default: pdf 

web: webversion.pdf

pdf: icse07.pdf

ps: icse07.ps

icse07.dvi: $(SRC)
	cd figures; make eps; cd -
	latex icse07
	bibtex icse07
	latex icse07
	latex icse07
	rm *.log *.aux *.blg
	
icse07.ps: icse07.dvi
	dvips icse07.dvi

icse07.pdf: icse07.dvi
	dvipdf icse07.dvi 

webversion.pdf:	icse07.pdf
	cp icse07.pdf webversion.pdf
	mv webversion.pdf /u/v/g/vg/public/html/downloads/icse07
	
clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	cd figures; make clean; cd -
