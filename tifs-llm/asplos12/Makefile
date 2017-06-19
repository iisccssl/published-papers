# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex figures/*.pdf)

default: pdf

pdf: asplos12.pdf

ps: asplos12.ps

asplos12.ps: asplos12.pdf
	pdftops asplos12.pdf 

asplos12.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf asplos12.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
