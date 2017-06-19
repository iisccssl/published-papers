# Makefile for the Paper

SRC=$(shell ls *.tex *.bib)

default: pdf

pdf: leet08.pdf

leet08.pdf: $(SRC)
	pdflatex leet08
	bibtex leet08
	pdflatex leet08
	pdflatex leet08
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi leet08.pdf *.out sections/*.bak
	rm -i *~ 
#	cd figures; make clean; cd -
