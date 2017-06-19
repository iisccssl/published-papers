paper:
	pdflatex paper
	bibtex paper
	pdflatex paper
	pdflatex paper
	rm -f paper.aux paper.bbl paper.blg paper.log paper.out paper.cb *.bak

clean:
	rm -f paper.pdf *.aux *.bbl *.blg *.log *.out *.cb *.cb2 *.bak

web:
	cp paper.pdf ~/public_html/downloads/ssc.pdf

all: paper web
