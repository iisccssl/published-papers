# Makefile for the Paper

#SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)
SRC=$(shell ls *.tex *.bib sections/*.tex)

default: web

web: paper.pdf
	cp paper.pdf /res/users/vinodg/public_html/downloads/pending/

pdf: paper.pdf

ps: paper.ps

paper.ps: paper.pdf
	pdftops paper.pdf 

#paper.pdf: paper.dvi
#	dvipdf paper.dvi 

paper.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf paper.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
#	cd figures; make clean; cd -
