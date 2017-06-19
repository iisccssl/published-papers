# Makefile for the Paper

SRC=$(shell ls *.cls *.bib *.tex sections/*.tex figures/*.eps)

default: pdf 

pdf: asplos2006.pdf

all: asplos2006.pdf asplos2006.ps

asplos2006.pdf: $(SRC)
	pdflatex asplos2006
	bibtex asplos2006
	pdflatex asplos2006
	pdflatex asplos2006
	rm *.log *.aux *.blg *.out *.bbl

asplos2006.ps: $(SRC)
	pdftops asplos2006.pdf
#	cp asplos2006.ps /u/v/g/vg/public/html/download/asplos06/

clean:
	rm -f figures/*.bak *.cb *.bak *.bbl *.blg *.log *.aux *.dvi asplos2006.pdf asplos2006.ps
