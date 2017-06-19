# Makefile for the Paper

SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex)

default: pdf

#web: webversion.pdf

pdf: ndss09.pdf

ps: ndss09.ps

ndss09.ps: $(SRC)
	latex main
	bibtex main
	latex main
	latex main
	dvips -o main.ps main.dvi
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

ndss09.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf ndss09.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
