# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex figures/*.pdf figures/*.png)

default: web

web: raid10.pdf
	cp raid10.pdf /res/users/vinodg/public_html/downloads/pending/

pdf: raid10.pdf

raid10.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf raid10.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -i *~ 
	cd sections/; rm -i *~
#	cd figures; make clean; cd -
