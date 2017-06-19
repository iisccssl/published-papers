# Makefile for the Paper

SRC=$(shell ls *.sty *.bib *.tex figures/eps/*.eps figures/pdf/*.pdf figures/fig/*.fig)

default: pdf ps

pdf: f17-ganapathy.pdf

ps: f17-ganapathy.ps

f17-ganapathy.ps: $(SRC)
	cd figures; make eps; cd -
	latex f17-ganapathy
	bibtex f17-ganapathy
	latex f17-ganapathy
	latex f17-ganapathy
	dvips -o f17-ganapathy.ps f17-ganapathy.dvi
	rm *.log *.aux *.blg

f17-ganapathy.pdf: $(SRC)
	cd figures; make pdf; cd -
	pdflatex f17-ganapathy
	bibtex f17-ganapathy
	pdflatex f17-ganapathy
	pdflatex f17-ganapathy
	rm *.log *.aux *.blg
	
clean:
	cd figures; make clean; cd -
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out
