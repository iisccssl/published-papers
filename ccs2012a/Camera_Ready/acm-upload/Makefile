# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex)

default: pdf ps

pdf: fp007-butt.pdf

ps:	fp007-butt.ps

fp007-butt.pdf: $(SRC)
	pdflatex fp007-butt
	bibtex fp007-butt
	pdflatex fp007-butt
	pdflatex fp007-butt
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

fp007-butt.ps: $(SRC)
	latex fp007-butt
	bibtex fp007-butt
	latex fp007-butt
	latex fp007-butt
	dvips -t letter -o fp007-butt.ps fp007-butt.dvi
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out *.dvi sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
