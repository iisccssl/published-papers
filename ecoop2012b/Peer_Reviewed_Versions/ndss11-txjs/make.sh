#!/bin/tcsh

setenv LATEX_PGF ~vinodg/private/research/tools/LaTeX-styles/
setenv TEXINPUTS .:$LATEX_PGF/:
make
