# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex figures/*.png)

default: pdf

pdf: paper.pdf

paper.pdf: $(SRC)
	pdflatex paper
	bibtex paper
	pdflatex paper
	pdflatex paper
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
