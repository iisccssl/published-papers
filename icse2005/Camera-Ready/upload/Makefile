# Makefile for the Paper

SRC=$(shell ls *.bib *.tex figures/*.eps)

default: p184-ganapathy.ps

pdf: p184-ganapathy.pdf

ps: p184-ganapathy.ps

all: p184-ganapathy.ps p184-ganapathy.pdf 

p184-ganapathy.ps: $(SRC)
	latex p184-ganapathy
#	bibtex p184-ganapathy
	latex p184-ganapathy
	latex p184-ganapathy
	dvips -o p184-ganapathy.ps p184-ganapathy.dvi
	rm *.aux *.log

p184-ganapathy.pdf: $(SRC)
	pdflatex p184-ganapathy
#	bibtex p184-ganapathy
	pdflatex p184-ganapathy
	pdflatex p184-ganapathy
	rm *.aux *.log *.out

clean:
	rm -f figures/*.bak *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out
