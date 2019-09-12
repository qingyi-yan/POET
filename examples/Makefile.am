
POET_LIB=$(top_srcdir)/lib
pcg = ${top_builddir}/src/pcg
debug=
in=
out=
arrref=
comp=diff
f95=0


files = IdentityTranslator.pt StringTranslator.pt C2C.pt C2F.pt F2C.pt Parse.pt Parse_2.pt CFG.pt BNFexp.code opt_all.pt opt_copy.pt opt_block.pt opt_fusion.pt opt_unroll.pt opt_uj.pt opt_permute.pt Transformation.pt Transformation_syntax.code compiler_1.pt compiler_input_1.code compiler_2.pt compiler_input_2.code compiler_input_3.code compiler_input_4.code compiler_3.pt compiler_4.pt compiler_5.pt compiler_6.pt

EXTRA_DIST = $(files) dgemm_orig.c dgemm.f.save dgemm_test.C poet_dgemm_test.C.save poet_dgemm_test_2.C.save poet_dgemm_test_3.C.save poet_dgemm_test_5.C.save poet_dgemm_test_6.C.save parse.out av1.input exp.input mgrid.f poet_mgrid.f.save cfg.out Transformation.out.save tomcatv.C poet_tomcatv.C.save poet_tomcatv_2.C.save chfac.f chfac.c.save chfac.c.macro compiler_output_2.save compiler_output_3.save compiler_output_4.save compiler_output_5.save compiler_output_6.save compiler.input

all:  


test_gemm:
	cp out.C ../test/autoScripts
	cd ../test/autoScripts; make test_gemm

xform:
	$(pcg) -L$(srcdir) -pinfile=dgemm_orig.c -poutfile=out $(srcdir)/Transformation.pt
	diff out $(srcdir)/Transformation.out.save
	rm out


check :
	make F2C in=$(srcdir)/chfac.f out=chfac.c
	$(comp) chfac.c $(srcdir)/chfac.c.save
	rm chfac.c
	make F2C in=$(srcdir)/chfac.f out=chfac.c arrref="a"
	$(comp) chfac.c $(srcdir)/chfac.c.macro
	rm chfac.c
	$(pcg) $(debug) -pinfile="$(srcdir)/av1.input" -pinputLang="$(srcdir)/AVstack.code" -poutfile="av1.output" -poutputLang="$(srcdir)/AVstack.code" $(srcdir)/IdentityTranslator.pt 
	$(comp) av1.output $(srcdir)/av1.input
	rm av1.output
	$(pcg) $(debug) -pinfile="$(srcdir)/opt_fusion.pt" -poutfile="out" $(srcdir)/IdentityTranslator.pt 
	$(comp) out $(srcdir)/opt_fusion.pt
	rm out
	$(pcg) $(debug) -pinfile="$(srcdir)/Parse.pt" -poutfile="out.pt" -poutputString="(car cdr)" -pinputString="(HEAD TAIL)" $(srcdir)/StringTranslator.pt 
	$(comp) out.pt $(srcdir)/Parse_2.pt
	rm out.pt
	$(pcg) $(debug) -pinfile="$(srcdir)/dgemm_orig.c" -poutfile="dgemm.c" $(srcdir)/C2C.pt
	$(comp) dgemm.c $(srcdir)/dgemm_orig.c
	rm dgemm.c
	$(pcg) $(debug) -pinfile="$(srcdir)/dgemm_orig.c" -poutfile="dgemm.f" $(srcdir)/C2F.pt 
	$(comp) dgemm.f $(srcdir)/dgemm.f.save
	rm dgemm.f
	make parseExp in="$(srcdir)/exp.input" out="out"
	$(comp) out $(srcdir)/parse.out
	rm out
	make analysis out="out"
	$(comp) out $(srcdir)/cfg.out
	rm out
	make apply_opt
	make xform
	make compiler

test_opt=0

now:
	$(pcg) $(debug) -L$(srcdir) -poutfile="out.C" -ppar=2 -pcache_bk="16 16 16" $(srcdir)/opt_all.pt

apply_opt:
	$(pcg) $(debug) -L$(srcdir) -poutfile="out.C" -ppar=2 -pcache_bk="16 16 16" $(srcdir)/opt_all.pt
	if [ $(test_opt) = 1 ]; then make test_gemm; fi;
	$(comp) out.C $(srcdir)/poet_dgemm_test_6.C.save
	rm out.C
	$(pcg) $(debug) -L$(srcdir) -poutfile="out.C" -ppar=1 -pbk="16 16 16" $(srcdir)/opt_copy.pt
	if [ $(test_opt) = 1 ]; then make test_gemm; fi;
	$(comp) out.C $(srcdir)/poet_dgemm_test_5.C.save
	rm out.C
	$(pcg) $(debug) -L$(srcdir) -poutfile="out.C" -pbk="16 16 16" $(srcdir)/opt_block.pt
	if [ $(test_opt) = 1 ]; then make test_gemm; fi;
	$(comp) out.C $(srcdir)/poet_dgemm_test_3.C.save
	rm out.C
	$(pcg) $(debug) -L$(srcdir) -pinfile=$(srcdir)/tomcatv.C -poutfile=poet_tomcatv.C -pfs=2 $(srcdir)/opt_fusion.pt
	$(comp) poet_tomcatv.C $(srcdir)/poet_tomcatv.C.save
	rm poet_tomcatv.C
	$(pcg) $(debug) -L$(srcdir) -pinfile=$(srcdir)/tomcatv.C -poutfile=poet_tomcatv.C -pfs=2 -pdis=1 $(srcdir)/opt_fusion.pt
	$(comp) poet_tomcatv.C $(srcdir)/poet_tomcatv_2.C.save
	rm poet_tomcatv.C
	$(pcg) $(debug) -L$(srcdir) -pinfile=$(srcdir)/dgemm_test.C -poutfile=out.C -pic="2 1" $(srcdir)/opt_permute.pt
	if [ $(test_opt) = 1 ]; then make test_gemm; fi;
	$(comp) out.C $(srcdir)/poet_dgemm_test_2.C.save
	rm out.C
	$(pcg) $(debug) -L$(srcdir) -poutfile=out.f $(srcdir)/opt_unroll.pt
	$(comp) out.f $(srcdir)/poet_mgrid.f.save
	rm out.f
	$(pcg) $(debug) -L$(srcdir) -pinfile=$(srcdir)/dgemm_test.C -poutfile=out.C -puj="1 4" $(srcdir)/opt_uj.pt
	if [ $(test_opt) = 1 ]; then make test_gemm; fi;
	$(comp) out.C $(srcdir)/poet_dgemm_test.C.save
	rm out.C

C2F: 
	$(pcg) $(debug) -pinfile=$(in) -poutfile=$(out) $(srcdir)/C2F.pt

F2C:
	$(pcg) $(debug) -pf95=$(f95) -pinfile=$(in) -poutfile=$(out) -parrref=$(arrref) $(srcdir)/F2C.pt

analysis:
	$(pcg) $(debug) -pinfile="$(srcdir)/dgemm_orig.c" -pinputLang="Cfront.code" -poutfile=$(out) $(srcdir)/CFG.pt

parseExp:
	$(pcg) $(debug) -L$(srcdir) -pinfile=$(in) $(debug) -poutfile=$(out) $(srcdir)/Parse.pt

compiler:
	$(pcg) $(debug) -L$(srcdir) -pinfile=compiler.input $(debug) $(srcdir)/compiler_1.pt
	$(pcg) $(debug) -L$(srcdir) -pinfile=compiler.input $(debug) -poutfile=$(out) $(srcdir)/compiler_2.pt 2>&1 | sed '/make/d; /reading/d; /Reading/d; /pcg/d' > out2
	diff out2 $(srcdir)/compiler_output_2.save
	rm out2
	$(pcg) $(debug) -L$(srcdir) -pinfile=compiler.input $(debug) -poutfile=$(out) $(srcdir)/compiler_3.pt 2>&1 | sed '/make/d; /reading/d; /Reading/d; /pcg/d' > out3
	diff out3 $(srcdir)/compiler_output_3.save
	rm out3
	$(pcg) $(debug) -L$(srcdir) -pinfile=compiler.input $(debug) -poutfile=$(out) $(srcdir)/compiler_4.pt 2>&1 | sed '/make/d; /reading/d; /Reading/d; /pcg/d' > out4
	diff out4 $(srcdir)/compiler_output_4.save
	rm out4
	$(pcg) $(debug) -L$(srcdir) -pinfile=compiler.input $(debug) -poutfile=$(out) $(srcdir)/compiler_5.pt 2>&1 | sed '/make/d; /reading/d; /Reading/d; /pcg/d' > out5
	diff out5 $(srcdir)/compiler_output_5.save
	rm out5
	$(pcg) $(debug) -L$(srcdir) -pinfile=compiler.input $(debug) -poutfile=$(out) $(srcdir)/compiler_6.pt 2>&1 | sed '/make/d; /reading/d; /Reading/d; /pcg/d' > out6
	diff out6 $(srcdir)/compiler_output_6.save
	rm out6

include ../Make.inc
