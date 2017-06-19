SRC=$(shell ls *.tex *.bib sections/*.tex figures/*.pdf figures/*.png)

default: pdf 

pdf: nfa-obdd-submatch.pdf

nfa-obdd-submatch.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf nfa-obdd-submatch.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -i *~ 
	cd sections/; rm -i *~
