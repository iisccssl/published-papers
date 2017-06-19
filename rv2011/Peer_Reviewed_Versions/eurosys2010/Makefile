# Makefile for the Paper

#SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)
SRC=$(shell ls *.tex *.bib sections/*.tex)

default: web

web: eurosys2010.pdf
	cp eurosys2010.pdf /res/users/vinodg/public_html/downloads/pending/

pdf: eurosys2010.pdf

ps: eurosys2010.ps

eurosys2010.ps: eurosys2010.pdf
	pdftops eurosys2010.pdf 

#eurosys2010.pdf: eurosys2010.dvi
#	dvipdf eurosys2010.dvi 

eurosys2010.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf eurosys2010.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
#	cd figures; make clean; cd -
