# Makefile for the Paper

#SRC=$(shell ls *.tex  *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)
SRC=$(shell ls *.tex *.bib sections/*.tex)

default: pdf

pdf: w2sp09.pdf

w2sp09.pdf: $(SRC)
	cd figures; make pdf; cd -
	pdflatex w2sp09
	bibtex w2sp09
	pdflatex w2sp09
	pdflatex w2sp09
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
