# Makefile for the Paper

SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)

default: pdf ps 

web: webversion.pdf

pdf: uw-cs-tr1580.pdf

ps: uw-cs-tr1580.ps

uw-cs-tr1580.dvi: $(SRC)
	cd figures; make eps; cd -
	latex uw-cs-tr1580
	bibtex uw-cs-tr1580
	latex uw-cs-tr1580
	latex uw-cs-tr1580
	rm *.log *.aux *.blg
	
uw-cs-tr1580.ps: uw-cs-tr1580.dvi
	dvips uw-cs-tr1580.dvi

uw-cs-tr1580.pdf: $(SRC)
	cd figures; make pdf; cd -
	pdflatex uw-cs-tr1580
	pdflatex uw-cs-tr1580
	bibtex uw-cs-tr1580
	pdflatex uw-cs-tr1580
	rm *.log *.aux *.blg

#uw-cs-tr1580.pdf: uw-cs-tr1580.dvi
#	dvipdf uw-cs-tr1580.dvi 

webversion.pdf:	uw-cs-tr1580.pdf
	cp uw-cs-tr1580.pdf webversion.pdf
	mv webversion.pdf /u/v/g/vg/public/html/downloads/uw-cs-tr1580
	
clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	cd figures; make clean; cd -
