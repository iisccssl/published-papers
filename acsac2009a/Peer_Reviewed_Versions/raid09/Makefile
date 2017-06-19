# Makefile for the Paper

#SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)
SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex)

default: pdf

#web: webversion.pdf

pdf: raid09.pdf

ps: raid09.ps

raid09.ps: raid09.pdf
	pdftops raid09.pdf 

#raid09.pdf: raid09.dvi
#	dvipdf raid09.dvi 

raid09.pdf: $(SRC)
	cd figures; make pdf; cd -
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf raid09.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
#	cd figures; make clean; cd -
