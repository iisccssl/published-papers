# Makefile for the Paper

SRC=$(shell ls *.bib *.tex figures/*.eps)

default: paper.ps	paper.pdf

pdf: paper.pdf

ps: paper.ps

paper.ps: $(SRC)
	latex main
	bibtex main
	latex main
	latex main
	dvips -o paper.ps main.dvi
	rm *.log *.aux *.blg

paper.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	rm *.log *.aux *.blg
	mv main.pdf paper.pdf
#	\cp paper.pdf ~/public/html/paper.pdf

clean:
	rm -f figures/*.bak *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out
