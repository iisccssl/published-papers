#!/bin/sh

pdflatex engarde
bibtex engarde
pdflatex engarde
pdflatex engarde
rm engarde.bbl engarde.aux engarde.blg engarde.log engarde.out
