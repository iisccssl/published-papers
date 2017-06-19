# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex)

default: pdf web

pdf: ieee_tdsc_gibraltar.pdf

ieee_tdsc_gibraltar.pdf: $(SRC)
	pdflatex paper
	pdflatex paper
	pdflatex paper
	mv main.pdf ieee_tdsc_gibraltar.pdf
	rm -f *.cb *.cb2 *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

web: ieee_tdsc_gibraltar.pdf
	cp ieee_tdsc_gibraltar.pdf /res/users/vinodg/public_html/downloads/pending/rkt-tdsc.pdf 

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi ieee_tdsc_gibraltar.pdf *.out sections/*.bak
	rm -i *~ 
	cd sections/; rm -i *~
#	cd figures; make clean; cd -
