# Makefile for haskell.pdf

PLATEX=platex
DVIPDF=dvipdfmx
RM=rm

%.dvi: %.tex
	$(PLATEX) $<

%.pdf: %.dvi
	$(DVIPDF) $<

all: haskell.pdf

clean:
	$(RM) *.aux *.dvi *.idx *.log *.toc