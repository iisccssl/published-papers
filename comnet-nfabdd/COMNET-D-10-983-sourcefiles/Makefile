# Makefile for the Paper

SRC=$(shell ls *.tex *.bib sections/*.tex figures/*.pdf figures/*.png)

default: web

web: comnet.pdf
	cp comnet.pdf /res/users/vinodg/public_html/downloads/pending/comnet.pdf

pdf: comnet.pdf

comnet.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf comnet.pdf
	rm -f main.spl *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f main.spl *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi comnet.pdf *.out sections/*.bak
	rm -i *~ 
	cd sections/; rm -i *~
#	cd figures; make clean; cd -
