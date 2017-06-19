# Makefile for the Paper

SRC=$(shell ls *.tex *.bib)

default: pdf

pdf: rv2011.pdf

rv2011.pdf: $(SRC)
	pdflatex rv2011
	bibtex rv2011
	pdflatex rv2011
	pdflatex rv2011
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux rv2011.pdf *.out 
