# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex)

default: web

web: transcript.pdf
	cp transcript.pdf /res/users/vinodg/public_html/downloads/pending/

pdf: transcript.pdf

ps: transcript.ps

transcript.ps: transcript.pdf
	pdftops transcript.pdf 

transcript.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf transcript.pdf
	rm -f *.cb *.cb2 *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
