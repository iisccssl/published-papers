
# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex)

default: web

web: ecoop2012a.pdf
	cp ecoop2012a.pdf /res/users/vinodg/public_html/downloads/pending/

pdf: ecoop2012a.pdf

ps: ecoop2012a.ps

ecoop2012a.ps: ecoop2012a.pdf
	pdftops ecoop2012a.pdf 

ecoop2012a.pdf: $(SRC)
	pdflatex paper
	bibtex paper
	pdflatex paper
	pdflatex paper
	mv paper.pdf ecoop2012a.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
