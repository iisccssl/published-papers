
# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex)

default: web

web: jsejetpack.pdf
	cp jsejetpack.pdf /res/users/vinodg/public_html/downloads/pending/

pdf: jsejetpack.pdf

ps: jsejetpack.ps

jsejetpack.ps: jsejetpack.pdf
	pdftops jsejetpack.pdf 

jsejetpack.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf jsejetpack.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
