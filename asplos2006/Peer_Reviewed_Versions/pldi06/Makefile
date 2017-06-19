# Makefile for the Paper

SRC=$(shell ls *.cls *.bib *.tex figures/*.eps)

default: pdf 

pdf: HIFI-paper.pdf

all: HIFI-paper.pdf HIFI-paper.ps

HIFI-paper.pdf: $(SRC)
	pdflatex hifi
	bibtex hifi
	pdflatex hifi
	pdflatex hifi
	rm *.log *.aux *.blg *.out *.bbl
	mv hifi.pdf HIFI-paper.pdf
	cp HIFI-paper.pdf /u/v/g/vg/public/html/download/pldi06/
	cp -r * /u/v/g/vg/public/html/download/pldi06/

HIFI-paper.ps: $(SRC)
	pdftops hifi.pdf
	cp HIFI-paper.ps /u/v/g/vg/public/html/download/pldi06/

clean:
	rm -f figures/*.bak *.cb *.bak *.bbl *.blg *.log *.aux *.dvi hifi.pdf hifi.ps
	rm -f /u/v/g/vg/public/html/download/pldi06/*
	rm -f HIFI-paper.ps HIFI-paper.pdf
