# Makefile for the Paper

#SRC=$(shell ls *.tex  *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)
SRC=$(shell ls *.tex *.bib sections/*.tex)

default: pdf

pdf: paper.pdf 

ps: paper.ps

# Make rules for latex
#
paper.ps: paper.dvi
	dvips -t letter -o paper.ps main.dvi
	rm -f *.log *.aux *.blg *.cb *.out *.bbl 

paper.dvi: $(SRC)
	latex main
	bibtex main
	latex main
	latex main

paper.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf paper.pdf
#	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak sections/*.aux

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak sections/*.aux
	rm -f *~ 
	cd sections/; rm -f *~
