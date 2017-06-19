# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex)

default: web 

pdf: paper.pdf

web: paper.pdf
	cp paper.pdf ~/public_html/downloads/vee14.pdf
	chmod 644 ~/public_html/downloads/vee14.pdf

paper.pdf: $(SRC)
	pdflatex paper
	bibtex paper
	pdflatex paper
	pdflatex paper
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out *.cb2 sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
