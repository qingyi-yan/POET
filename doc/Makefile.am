EXTRA_DIST = manual.tex appendix.sty tutorial-compiler.tex

all: manual tutorial-compiler

manual: 
	pdflatex $(srcdir)/manual.tex

tutorial-compiler:
	pdflatex $(srcdir)/tutorial-compiler.tex

distclean: 
	make clean
	rm Makefile

clean :
	rm -f *.aux
	rm -f *.dvi
	rm -f *.idx	
	rm -f *.log
	rm -f *.out
	rm -f *.pdf
	rm -f *.ps
	rm -f *.toc
