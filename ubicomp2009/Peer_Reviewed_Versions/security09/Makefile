# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex figs/*.png)

default: pdf

pdf: security09.pdf

security09.pdf: $(SRC)
	pdflatex security09
	bibtex security09
	pdflatex security09
	pdflatex security09
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux security09.pdf *.out sections/*.bak
