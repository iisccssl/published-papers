# Makefile for the Paper

SRC=$(shell ls *.bib *.tex figures/*.eps)

default: rp184-ganapathy.ps

pdf: rp184-ganapathy.pdf

ps: rp184-ganapathy.ps

all: rp184-ganapathy.ps rp184-ganapathy.pdf 

rp184-ganapathy.ps: $(SRC)
	latex rp184-ganapathy
#	bibtex rp184-ganapathy
	latex rp184-ganapathy
	latex rp184-ganapathy
	dvips -o rp184-ganapathy.ps rp184-ganapathy.dvi
	rm *.aux *.log

rp184-ganapathy.pdf: $(SRC)
	pdflatex rp184-ganapathy
#	bibtex rp184-ganapathy
	pdflatex rp184-ganapathy
	pdflatex rp184-ganapathy
	rm *.aux *.log *.out

clean:
	rm -f figures/*.bak *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out
	./mkbkp.sh rp184-ganapathy.tex 
