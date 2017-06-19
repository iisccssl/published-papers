# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex)

default:	web

web:	pdf
	cp socc14.pdf ~/public_html/drafts/socc14.pdf
	chmod 644 ~/public_html/drafts/socc14.pdf

pdf: paper.pdf

paper.pdf: $(SRC)
	pdflatex paper
	bibtex paper
	pdflatex paper
	pdflatex paper
	mv paper.pdf socc14.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out *.cb2 sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
