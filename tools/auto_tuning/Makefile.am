
EXTRA_DIST= tune.pl 

PCG=${top_builddir}/src/pcg

all: 
	echo "#!/usr/bin/perl -w" > tune.pl
	echo "" >> tune.pl
	echo "\$$POETDIR=\"${subst /trunk,,${abs_top_builddir}}\";" >> tune.pl
	cat tune.def >> tune.pl
	chmod 755 tune.pl

