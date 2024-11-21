
INPUT = 
OUTPUT= 
POET_LIB=$(top_srcdir)/lib
pcg = ${top_builddir}/src/pcg
DEBUG_FLAG=


all : defuse_array_access

defuse_array_access :
	$(pcg) $(DEBUG_FLAG) -L$(POET_LIB) -pinputFile=input_defuse_arrayaccess.c -poutfile=out test_defuse_arrayaccess.pt

substract_list :
	$(pcg) $(DEBUG_FLAG) -L$(POET_LIB) test_substract_list.pt

check: 
	make defuse_array_access
	
