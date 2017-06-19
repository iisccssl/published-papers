# Makefile for the Paper

#SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)
SRC=$(shell ls *.tex *.bib sections/*.tex)

default: web

web: ppopp2011.pdf
	cp ppopp2011.pdf /res/users/vinodg/public_html/downloads/pending/

pdf: ppopp2011.pdf

ps: ppopp2011.ps

ppopp2011.ps: ppopp2011.pdf
	pdftops ppopp2011.pdf 

#ppopp2011.pdf: ppopp2011.dvi
#	dvipdf ppopp2011.dvi 

ppopp2011.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf ppopp2011.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
#	cd figures; make clean; cd -
