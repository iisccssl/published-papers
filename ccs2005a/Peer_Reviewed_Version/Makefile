# Makefile for the Paper

SRC=$(shell ls *.sty *.bib *.tex figures/eps/*.eps figures/pdf/*.pdf figures/fig/*.fig)

default: pdf ps

pdf: ccs05.pdf

ps: ccs05.ps

ccs05.ps: $(SRC)
	cd figures; make eps; cd -
	latex main
	bibtex main
	latex main
	latex main
	dvips -o ccs05.ps main.dvi
	rm *.log *.aux *.blg

ccs05.pdf: $(SRC)
	cd figures; make pdf; cd -
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf ccs05.pdf
	rm *.log *.aux *.blg
	
clean:
	cd figures; make clean; cd -
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out
