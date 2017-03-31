
POET_LIB=$(top_srcdir)/lib
pcg = ${top_builddir}/src/pcg
debug=
input=2mm
output=
syntax=$(srcdir)/parseC.pt
comp=diff
F95=0


files = parseC.pt
EXTRA_DIST = $(files) tri.c jacobi7_4_opt.c poet_tri.c.save poet_tri.out.save poet_jacobi7_4_opt.c.save poet_jacobi7_4_opt.out.save


parse:
	$(pcg) $(debug) -pinputFile="$(srcdir)/$(input).c" -poutputFile="poet_$(input).c" "$(syntax)"

check1:
	make parse 2>& 1 | sed '/make/d; /reading/d; /Reading/d; /pcg/d' > out
	$(comp) out $(srcdir)/poet_$(input).out.save
	$(comp) poet_$(input).c $(srcdir)/poet_$(input).c.save
	rm poet_$(input).c
	rm out

check:
	make check1 input=tri
	make check1 input=jacobi7_4_opt

include ../../Make.inc
