# Makefile for the Paper

SRC=$(shell ls *.tex *.bib figures/*.pdf sections/*.tex)

default: pdf

web: mobisys2011.pdf
	cp mobisys2011.pdf /res/users/vinodg/public_html/downloads/pending/

pdf: mobisys2011.pdf

ps: mobisys2011.ps

mobisys2011.ps: mobisys2011.pdf
	pdftops mobisys2011.pdf 

mobisys2011.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf mobisys2011.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
