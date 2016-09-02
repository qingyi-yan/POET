
POET_LIB=$(top_srcdir)/lib
pcg = ${top_builddir}/src/pcg
debug=
input=
output=
syntax=$(srcdir)/parseF.pt
comp=diff
F95=0


files = parseF.pt
EXTRA_DIST = $(files)  \
      example1.f  poet_example1.f.save poet_example1.out.save \
      example2.f  poet_example2.f.save poet_example2.out.save \
      erlebacher.f poet_erle.f.save poet_erle.out.save \
      swim.f poet_swim.f.save poet_swim.out.save \
      tomcatv.f poet_tomcatv.f.save poet_tomcatv.out.save \
      mgrid.f poet_mgrid.f.save  poet_mgrid.out.save


all:  


now:


parse:
	$(pcg) $(debug) -pinputFile="$(srcdir)/$(input).f" -poutputFile="poet_$(input).f" -pF95=$(F95) "$(syntax)"

check1:
	make parse 2>& 1 | sed '/make/d; /reading/d; /Reading/d; /pcg/d' > out
	$(comp) out $(srcdir)/poet_$(input).out.save
	$(comp) poet_$(input).f $(srcdir)/poet_$(input).f.save
	rm poet_$(input).f
	rm out

check:
	make check1 input=tomcatv
	make check1 input=example2 F95=1
	make check1 input=mgrid
	make check1 input=swim
	make check1 input=example1

include ../../Make.inc
