POET_LIB=$(top_srcdir)/lib
pcg = ${top_builddir}/src/pcg
debug=
output=

test-graph-functions:
	$(pcg) $(debug) -L$(POET_LIB) test_create_nodes.pt

check:
	make test-graph-functions

include ../../Make.inc
