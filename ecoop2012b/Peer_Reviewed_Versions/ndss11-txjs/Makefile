# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex)

default: web

web: ndss2011.pdf
	cp ndss2011.pdf /res/users/vinodg/public_html/downloads/pending/

pdf: ndss2011.pdf

ps: ndss2011.ps

ndss2011.ps: ndss2011.pdf
	pdftops ndss2011.pdf 

ndss2011.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf ndss2011.pdf
	rm -f *.cb *.cb2 *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
