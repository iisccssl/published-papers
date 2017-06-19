# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex)

default: web

web: ccs2010.pdf
	cp ccs2010.pdf /res/users/vinodg/public_html/downloads/pending/

pdf: ccs2010.pdf

ps: ccs2010.ps

ccs2010.ps: ccs2010.pdf
	pdftops ccs2010.pdf 

ccs2010.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf ccs2010.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
