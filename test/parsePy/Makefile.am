input=kmeans-ext.py
output = kmeans-ext-out.py
debug=
POET_LIB=$(top_srcdir)/lib
pcg = ${top_builddir}/src/pcg

all:
	${pcg} $(debug) -pinfile=$(input) -poutfile=$(output) Transformation.pt 

check: 
	make input=kmeans.py output=out
	diff out kmeans-out.py
	make input=kmeans-ext.py output=out
	diff out kmeans-ext-out.py
