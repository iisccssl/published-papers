# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex figs/*.png)

default: pdf

pdf: ubicomp09.pdf

ubicomp09.pdf: $(SRC)
	pdflatex ubicomp09
	bibtex ubicomp09
	pdflatex ubicomp09
	pdflatex ubicomp09
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux ubicomp09.pdf *.out sections/*.bak
