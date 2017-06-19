# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex figures/*.png)

default: web 

web: pdf
	cp mobisys16.pdf ~/public_html/drafts/mobisys16.pdf
	chmod 644 ~/public_html/drafts/mobisys16.pdf

pdf: mobisys16.pdf

mobisys16.pdf: $(SRC)
	pdflatex paper
	bibtex paper
	pdflatex paper
	pdflatex paper
	mv paper.pdf mobisys16.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
