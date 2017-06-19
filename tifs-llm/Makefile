# Makefile for the Paper

SRC=$(shell ls *.tex *.bib)

default: pdf

pdf: tifs-llm.pdf

ps: tifs-llm.ps

tifs-llm.ps: tifs-llm.pdf
	pdftops tifs-llm.pdf 

tifs-llm.pdf: $(SRC)
	pdflatex tifs-llm
	bibtex tifs-llm
	pdflatex tifs-llm
	pdflatex tifs-llm
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi tifs-llm.pdf *.out 
