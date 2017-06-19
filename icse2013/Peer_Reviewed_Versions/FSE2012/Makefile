# Makefile for the Paper

SRC=$(shell ls *.tex *.bib section/*.tex)

default: pdf

web: paper.pdf
	cp paper.pdf /res/users/vinodg/public_html/downloads/pending/fse11.pdf

pdf: paper.pdf

ps: paper.ps

paper.ps: paper.pdf
	pdftops paper.pdf 

paper.pdf: $(SRC)
	pdflatex paper
	bibtex paper
	pdflatex paper
	pdflatex paper
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out section/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out section/*.bak
	rm -f *~ 
	cd section/; rm -f *~
