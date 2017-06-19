# Makefile for the Paper

SRC=$(shell ls *.cls *.bib *.tex sections/*.tex figures/*.eps)

default: pdf 

pdf: asplos011-chilimbi.pdf

all: asplos011-chilimbi.pdf asplos011-chilimbi.ps

asplos011-chilimbi.pdf: $(SRC)
	pdflatex asplos011-chilimbi
	bibtex asplos011-chilimbi
	pdflatex asplos011-chilimbi
	pdflatex asplos011-chilimbi
	rm *.log *.cb *.aux *.blg *.out #*.bbl

asplos011-chilimbi.ps: $(SRC)
	pdftops asplos011-chilimbi.pdf

clean:
	rm -f sections/*.bak figures/*.bak *.cb *.bak *.bbl *.blg *.log *.aux *.dvi asplos011-chilimbi.pdf asplos011-chilimbi.ps
