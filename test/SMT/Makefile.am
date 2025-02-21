POET_LIB=$(top_srcdir)/lib
pcg = ${top_builddir}/src/pcg
debug=
input=
output=
comp=diff
F95=0

files = test1.pt
EXTRA_DIST = $(files)

all: now

now:
	$(pcg) $(debug) -L$(POET_LIB) test1.pt

check: 
	make now

distclean: 
	make clean
	rm Makefile

clean :
	rm -f *.smt

include ../../Make.inc
