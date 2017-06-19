# Makefile for the Paper

SRC=$(shell ls *.cls *.bib *.tex figures/*.eps)

default: pdf 

pdf: pldi05.pdf

all: pldi05.pdf pldi05.ps

pldi05.pdf: $(SRC)
	pdflatex hifi
	bibtex hifi
	pdflatex hifi
	pdflatex hifi
	rm *.log *.aux *.blg *.out *.bbl
	mv hifi.pdf pldi05.pdf

pldi05.ps: $(SRC)
	pdftops hifi.pdf

clean:
	rm -f figures/*.bak *.cb *.bak *.bbl *.blg *.log *.aux *.dvi hifi.pdf hifi.ps
	rm -f pldi05.ps pldi05.pdf
