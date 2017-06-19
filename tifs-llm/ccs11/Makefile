# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex figures/*.pdf)

default: pdf

pdf: ccs11.pdf

ps: ccs11.ps

ccs11.ps: ccs11.pdf
	pdftops ccs11.pdf 

ccs11.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf ccs11.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
