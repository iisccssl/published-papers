# Makefile for the Paper

#SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)
SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex)

default: pdf

#web: webversion.pdf

pdf: tm-sec08.pdf

ps: tm-sec08.ps

tm-sec08.ps: tm-sec08.pdf
	pdftops tm-sec08.pdf 

#tm-sec08.pdf: tm-sec08.dvi
#	dvipdf tm-sec08.dvi 

tm-sec08.pdf: $(SRC)
	cd figures; make pdf; cd -
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf tm-sec08.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -i *~ 
	cd sections/; rm -i *~
#	cd figures; make clean; cd -
