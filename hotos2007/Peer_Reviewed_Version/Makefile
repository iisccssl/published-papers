# Makefile for the Paper

SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)

default: pdf

pdf: hotos07.pdf

hotos07.pdf: $(SRC)
	cd figures; make pdf; cd -
	pdflatex hotos07
	bibtex hotos07
	pdflatex hotos07
	pdflatex hotos07
	rm -f *.log *.aux *.blg *.cb *.bak *.bbl *.blg *.log *.aux 

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out \
		sections/*.bak
