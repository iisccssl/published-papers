# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex figures/*.*)

default: pdf

pdf: engarde.pdf
	cp engarde.pdf ~/public_html/drafts/engarde.pdf
	chmod 644 ~/public_html/drafts/engarde.pdf

engarde.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf engarde.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
