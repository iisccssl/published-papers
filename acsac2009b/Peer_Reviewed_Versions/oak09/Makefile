# Makefile for the Paper

SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex)

default: pdf

#web: webversion.pdf

pdf: ieee-sp09.pdf

ps: ieee-sp09.ps

ieee-sp09.ps: $(SRC)
	latex main
	bibtex main
	latex main
	latex main
	dvips -o main.ps main.dvi
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

ieee-sp09.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf ieee-sp09.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
