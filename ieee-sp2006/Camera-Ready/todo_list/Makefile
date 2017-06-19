# Makefile for the Paper

SRC=$(shell ls *.tex)

default: ps

ps: todo.ps

todo.ps: $(SRC)
	latex todo
	dvips -o todo.ps todo.dvi
	rm -f *.log *.aux *.blg *.cb *.out
	
clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out
