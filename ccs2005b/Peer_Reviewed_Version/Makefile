TITLE = paper
BIBFILE = bibliography.bib
SOURCES =0.preambleIEEE.tex Intro.tex  rw.tex threat.tex bidderProfile.tex   paper.tex  TableEbayData.tex AverageBid.tex StartBid.tex bibliography.bib CaseStudies.tex formalization.tex TableAbnormalSellers.tex   TableInterpetation.tex abstract.tex rw.tex IntroVinod.tex threatVinod.tex  conclusions.tex


all: dvi ps

clean: 
	rm -f *.pdf *.ps *.aux *.bbl *.blg *.dvi *.*~ *.bak *~


dvi:	$(TITLE).dvi
ps:	$(TITLE).ps
pdf:	$(TITLE).pdf


$(TITLE).bbl: $(BIBFILE)
	latex paper
	bibtex paper
	latex paper

$(TITLE).dvi: $(TITLE).bbl $(SOURCES)
	latex paper
	latex paper
	latex paper

$(TITLE).ps:	$(TITLE).dvi
	dvips -o $(TITLE).ps $(TITLE).dvi
$(TITLE).pdf:	$(TITLE).ps
	dvipdf $(TITLE).dvi
#	ps2pdf -dMaxSubsetPct=100 -dCompatibilityLevel=1.2 -dSubsetFonts=true -dEmbedAllFonts=true $(TITLE).ps


EPSFIGS=$(wildcard *.eps)
PDFFIGS=$(patsubst %.eps,%.pdf,$(EPSFIGS))

pdffigs: $(PDFFIGS)

%.pdf: %.eps
	@epstopdf $<
