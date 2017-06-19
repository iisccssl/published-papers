# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex)

default: web

web: plas10.pdf
	cp plas10.pdf /res/users/vinodg/public_html/downloads/pending/plas10.pdf

pdf: plas10.pdf

ps: plas10.ps

plas10.ps: plas10.pdf
	pdftops plas10.pdf 

#plas10.pdf: plas10.dvi
#	dvipdf plas10.dvi 

plas10.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf plas10.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
#	cd figures; make clean; cd -
