# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex)

default: pdf ps

pdf: ccs2012a.pdf

ps:	ccs2012a.ps

ccs2012a.pdf: $(SRC)
	pdflatex fp007-butt
	bibtex fp007-butt
	pdflatex fp007-butt
	pdflatex fp007-butt
	mv fp007-butt.pdf ccs2012a.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

ccs2012a.ps: $(SRC)
	latex fp007-butt
	bibtex fp007-butt
	latex fp007-butt
	latex fp007-butt
	mv fp007-butt.dvi Self_Service_Cloud_Computing.dvi
	dvips -t letter -o ccs2012a.ps Self_Service_Cloud_Computing.dvi
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out *.dvi sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
