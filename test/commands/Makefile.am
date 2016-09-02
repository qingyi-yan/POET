comp=diff
debug=
input=

all : 

files=test1.pt test2.pt test3.pt test4.pt

single:
	$(top_builddir)/src/pcg $(srcdir)/$(input) 

check : 
	$(top_builddir)/src/pcg $(srcdir)/test1.pt 2>&1 | sed '/make/d; /reading/d; /Reading/d; /pcg/d' > out1
	$(comp) out1 $(srcdir)/test1.out
	rm out1
	$(top_builddir)/src/pcg -L$(top_builddir)/lib $(srcdir)/test2.pt 2>&1 | sed '/make/d; /reading/d; /Reading/d; /pcg/d' > out2
	$(comp) out2 $(srcdir)/test2.out
	rm out2
	$(top_builddir)/src/pcg -L$(top_builddir)/lib $(srcdir)/test3.pt 2>&1 | sed '/make/d; /reading/d; /Reading/d; /pcg/d' > out3
	$(comp) out3 $(srcdir)/test3.out
	rm out3
	$(top_builddir)/src/pcg -L$(top_builddir)/lib $(srcdir)/test4.pt 2>&1 | sed '/make/d; /reading/d; /Reading/d; /pcg/d' > out4
	$(comp) out4 $(srcdir)/test4.out
	rm out4
	$(top_builddir)/src/pcg -L$(top_builddir)/lib -pA="1 3 2" -pB="4 (5,7) (9,10)" -pC="(1,3),2" -pD="5" $(srcdir)/test4.pt 2>&1 | sed '/make/d; /reading/d; /Reading/d; /pcg/d' > out5
	$(comp) out5 $(srcdir)/test4.out2
	rm out5

EXTRA_DIST = $(files) test1.out test2.out test3.out test4.out test4.out2

include ../../Make.inc
