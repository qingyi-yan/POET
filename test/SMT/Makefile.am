POET_LIB=$(top_srcdir)/lib
pcg = ${top_builddir}/src/pcg
debug=
input=
output=
comp=diff
F95=0

files = test1.pt test2.pt test3.pt
EXTRA_DIST = $(files)

all: now

now:
	$(pcg) $(debug) -L$(POET_LIB) test1.pt
	$(pcg) $(debug) -L$(POET_LIB) test2.pt
	$(pcg) $(debug) -L$(POET_LIB) test3.pt

check: 
	make now

distclean: 
	make clean
	rm Makefile

clean :
	rm -f *.smt2

include ../../Make.inc
