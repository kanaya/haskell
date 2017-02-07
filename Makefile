# Makefile for haskell.pdf

PLATEX=platex
DVIPDF=dvipdfmx

%.dvi: %.tex
	$(PLATEX) $<

%.pdf: %.dvi
	$(DVIPDF) $<

all: haskell.pdf
