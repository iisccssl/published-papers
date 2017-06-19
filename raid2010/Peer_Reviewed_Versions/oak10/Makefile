# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex figures/*.pdf figures/*.png)

default: pdf

pdf: oak10-bdd.pdf

oak10-bdd.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf oak10-bdd.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak
	cp oak10-bdd.pdf /res/users/vinodg/public_html/downloads/pending/bdd.pdf

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -i *~ 
	cd sections/; rm -i *~
#	cd figures; make clean; cd -
