# Makefile for the Paper

SRC=$(shell ls *.tex *.bib figures/*.pdf sections/*.tex)

default: pdf

web: mobi036-bickford.pdf
	cp mobi036-bickford.pdf /res/users/vinodg/public_html/downloads/pending/

pdf: mobi036-bickford.pdf

ps: mobi036-bickford.ps

mobi036-bickford.ps: mobi036-bickford.pdf
	pdftops mobi036-bickford.pdf 

mobi036-bickford.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf mobi036-bickford.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
