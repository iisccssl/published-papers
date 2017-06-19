# vim: noexpandtab

FILES = paper.tex abstract.tex intro.tex related.tex
ARTFILES = artifact.tex artifactcontent.tex
# background.tex overview.tex algorithm.tex cost.tex experiments.tex conclusions.tex

all: 	pdf

re:
	touch paper.tex
	$(MAKE)

clean:
	rm -f *~ *.aux *.dvi *.log *.ps \
	  paper.bbl paper paper.blg \
	  paper.cb paper.cb2 paper.pdf \
	  artifact artifact.blg \
	  artifact.cb artifact.cb2 artifact.pdf

pdf: $(FILES)
	pdflatex paper.tex
	bibtex paper
	pdflatex paper.tex
	pdflatex paper.tex
	pdflatex paper.tex
	pdflatex paper.tex

artifact: $(ARTFILES)
	pdflatex artifact.tex
	pdflatex artifact.tex
	pdflatex artifact.tex

paper.ps: paper.dvi
	dvips -D600 -e0 -tletter paper.dvi

paper.dvi: $(FILES)
	latex paper.tex
	bibtex paper
	latex paper.tex
	latex paper.tex
	latex paper.tex
	latex paper.tex

spell:	paper.tex
	detex paper.tex | spell

wc:	paper.tex
	detex paper.tex | wc -w
