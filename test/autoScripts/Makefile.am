POET_LIB=$(top_srcdir)/lib
loopProc=$(top_srcdir)/../SLICE/loopOptimization/testROSE/LoopProcessor

input=
config1=
config2=
config3=
comp=diff

MS=500
NS=500
KS=500

scripts=chfac.pt trmm.pt dgemm.pt dgemm1.pt dgemm2.pt dgetrf.pt dgemvT.pt dger.pt
EXTRA_DIST= $(scripts) chfac.h trmm.h rose_chfac.C rose_trmm.C rose_dgemm.C rose_dgemvT.C rose_dger.C rose_dgetrf.C dgemm.c_save dgemm1.c_save dgemm2.c_save dgemm_1.c_save dgemm_2.c_save dgemm_3.c_save dgetrf.c_save dgetrf_1.c_save dgetrf_2.c_save dgemvT.c_save dger.c_save trmm_tester.c chfac_tester.c trmm_timer.c chfac_timer.c chfac.c_save trmm.c_save dgemm_tester.c dgemm_timer.c

all: 

single1:
	$(top_builddir)/src/pcg $(debug) -L$(srcdir) $(config1) $(srcdir)/$(input)$(config2).pt > out.c

#	if [ "$(config2)" != "" ]; then cp $(srcdir)/rose_$(input)$(config2).C rose_$(input).C; fi;

slice: 
	$(loopProc) $(config1) $(srcdir)/rose_$(input)$(config2).C
	mv rose_rose_$(input)$(config2).C out.c

single:
	make single1
	$(comp) out.c $(srcdir)/$(input)$(config3).c_save

check : 
	make single input=dgemm
	make single input=dgetrf config1="" config3="_1"
	make single input=dgetrf config1="-pbsize_nest1=\"16 1\"" 
	make single input=dgetrf config1="-pbsize_nest1=\"16 1\" -pujsize_nest1=1" config3="_2"
	make single input=chfac
	make single input=trmm
	make single input=dgemm config1="-ppthread_nest1=2" config3="_1"
	make single input=dgemm config2="1" config3="1"
	make single input=dgemm config2="2" config3="2"
	make single input=dgemm config1="-ppsize_nest1=144 -ppthread_nest1=2 -pcopy1_config_C=2 -pbsize_nest1=\"72 72 72\" -pujsize_nest1=\"12 1\" -pusize_nest2=36" config3="_2"
	make single input=dgemm config1="-ppsize_nest1=144 -ppthread_nest1=2 -pcopy1_config_C=2 -pbsize_nest1=\"72 72 72\" -pujsize_nest1=\"12 1\" -pusize_nest2=72" config3="_3"
	make single input=dgemvT config1="-ppthread_nest1=2 -pbsize_nest1=\"16 16\" -pujsize_nest1=2 -pcopy1_config_Y=2 -pcopy2_config_X=0"
	make single config1="-ppthread_nest1=2" input=dger 
	rm out.c

test_chfac:
	gcc chfac_tester.c out.c
	./a.out

time_chfac:
	gcc chfac_timer.c out.c
	./a.out

test_trmm:
	gcc trmm_tester.c out.c
	./a.out

time_trmm:
	gcc trmm_timer.c out.c
	./a.out


test_dgetrf:	
	cp out.c out_dgetrf.c
	echo "" > arrayAccess.h
	gcc dgetrf_tester.c
	./a.out

test_gemm:	
	gcc -fopenmp gemm_tester.c out.c -DMS=$(MS) -DNS=$(NS) -DKS=$(KS)
	./a.out

test_gemv:	
	gcc -fopenmp gemvT_tester.c out.c -DMS=$(MS) -DNS=$(NS) -DKS=$(KS)
	./a.out

test_ger:	
	gcc -fopenmp ger_tester.c out.c -DMS=$(MS) -DNS=$(NS) -DKS=$(KS)
	./a.out

tester:
	cd $(top_builddir)/test/testerGeneration; make tester_c input="$(top_builddir)/test/autoScripts/gemvT"; make tester_c input="$(top_builddir)/test/autoScripts/ger"; make tester_c input="$(top_builddir)/test/autoScripts/dgetrf"; make tester_c input="$(top_builddir)/test/autoScripts/gemm"

NREP=1

time_gemm:	
	gcc -fopenmp -O2 -DMS=$(MS) -DNS=$(NS) -DKS=$(KS) -DNREP=$(NREP) gemm2_timer.c out_dgemm_test.c
	./a.out

time_gemv:	
	gcc -O2 -DMS=$(MS) -DNS=$(NS) -DNREP=$(NREP) -fopenmp gemvT2_timer.c out_dgemvT.c
	./a.out

time_ger:	
	gcc -O2 -fopenmp -DMS=$(MS) -DNS=$(NS) -DNREP=$(NREP) ger2_timer.c out_dger.c
	./a.out

time_getrf:	
	echo "#define arr_ref(a,i,j) a[(i)*n+(j)]" > arrayAccess.h
	gcc -O2 -DNS=$(NS) -DMS=$(MS) -DNREP=$(NREP) dgetrf2_timer.c out_dgetrf.c
	./a.out


bk=32
cp1=2
cp2=2
cp3=2
uj1=4
uj2=1
scalar1=1
scalar2=1
scalar3=2
ur2=16

try_slice:
	echo "extern double& arr_ref( double* a, int a1, int a2);" > arrayAccess.h
	make slice input=dgetrf config1="-fs01 -bk2 $(bk) -cp 0" 
	make test_dgetrf
	make time_getrf
	make slice input=dgetrf config1="-fs01 -bk3 $(bk) -cp 0" 
	make test_dgetrf
	make time_getrf
	make slice input=dgemm config1="-fs01 -bk3 $(bk) -cp 0 -unroll $(ur2)" 
	make test_gemm
	make time_gemm
	make slice input=dger config1="-bk3 $(bk) -cp 0 -unroll $(ur2)" 
	make test_ger
	make time_ger
	make slice input=dgemvT config1="-bk3 $(bk) -cp 0 -unroll $(ur2)" 
	make test_gemv
	make time_gemv


try_ger:
	make single1 input=dger config1="-pbsize_nest1=\"$(bk) $(bk)\" -pcopy1_config_X=$(cp1) -pujsize_nest1=$(uj1) -pscalarRepl1_nest1_X=$(scalar1) -pscalarRepl2_nest1_Y=$(scalar2) -pusize_nest2=$(ur2)" 
	make test_ger
	make time_ger

try_gemv:
	make single1 input=dgemvT config1="-pbsize_nest1=\"$(bk) $(bk)\" -pcopy1_config_Y=$(cp1) -pcopy2_config_X=$(cp2) -pujsize_nest1=$(uj1) -pscalarRepl1_nest1_Y=$(scalar1) -pscalarRepl2_nest1_X=$(scalar2) -pusize_nest2=$(ur2)" 
	make test_gemv
	make time_gemv

try_getrf:
	make single1 input=dgetrf_bk_cp config1="-pbsize_nest1=\"$(bk) $(bk)\" -pujsize_nest1=$(uj1) -pscalarRepl1_body1_a=$(scalar1) -pscalarRepl2_body2_p=$(scalar2) -pscalarRepl3_nest4_a=$(scalar3)" 
	make test_dgetrf
	make time_getrf
	make single1 input=dgetrf_bk_cp config1="-pbsize_nest1=\"$(bk) 1\" -pujsize_nest1=$(uj1) -pscalarRepl1_body1_a=$(scalar1) -pscalarRepl2_body2_p=$(scalar2) -pscalarRepl3_nest4_a=$(scalar3)" 
	make test_dgetrf
	make time_getrf

try_gemm:
	make single1 input=dgemm_opt2_unroll config1="-pbsize_nest1=\"$(bk) $(bk) $(bk)\" -pcopy1_config_C=$(cp1) -pcopy2_config_A=$(cp2) -pcopy3_config_B=$(cp3) -pujsize_nest1=\"$(uj1) $(uj2)\" -pscalarRepl1_nest1_C=$(scalar1) -pscalarRepl2_nest1_A=$(scalar2) -pscalarRepl3_nest1_B=$(scalar3) -pusize_nest2=$(ur2)" 
	make test_gemm
	make time_gemm

bk_sel = 1 8 16 24 32 40 48 56 64 72 80 88 96
tune_bk:
	for s in $(bk_sel); do if [[ $$s > $(ur2) ]]; then make try_$(input) bk=$$s; fi; done

tune_bk_slice:
	time make tune_bk input=slice

tune_bk_all:
	time make tune_bk input=getrf 
	time make tune_bk input=gemm
	time make tune_bk input=gemv
	time make tune_bk input=ger

ur_sel = 1 8 16 24 32 40 48 56 64 72 80 88 96

tune_ur_gemm:
	time for ur_i in $(ur_sel); do make tune_bk input=gemm ur2=$${ur_i}; done

tune_ur_slice:
	time for ur_i in $(ur_sel); do make tune_bk_slice ur2=$${ur_i}; done

tune_ur:
	time make tune_bk input=getrf 
	make tune_ur_gemm
	time for ur_i in $(ur_sel); do make tune_bk input=ger ur2=$${ur_i}; done
	time for ur_i in $(ur_sel); do make tune_bk input=gemv ur2=$${ur_i}; done

scalar3_sel=1 2
scalar2_sel=1 2
scalar1_sel=1 2

tune_scalar1: 
	for s in $(scalar1_sel); do make tune_ur$(input) scalar1=$$s; done

tune_scalar2:
	for s in $(scalar2_sel); do make tune_scalar1 scalar2=$$s; done

tune_scalar3:
	for s in $(scalar3_sel); do make tune_scalar2 scalar3=$$s; done

cp3_sel=1 2
cp2_sel=1 2
cp1_sel=1 2


tune_cp1:
	for s in $(cp1_sel); do make tune_scalar3 cp1=$$s; done

tune_cp2:
	for s in $(cp2_sel); do make tune_cp1 cp2=$$s; done

tune_cp3:
	for s in $(cp3_sel); do make tune_cp2 cp3=$$s; done

uj2_sel= 1 2 3 4 5 6 7 8 9 10 11 12
uj1_sel= 1 2 3 4 5 6 7 8 9 10 11 12

tune_uj1:
	for s in $(uj1_sel); do if [[  $$s<=12-$(uj2) ]]; then make tune_cp3 uj1=$$s; fi; done	

tune_uj2:
	for s in $(uj2_sel); do make tune_uj1 uj2=$$s; done	

tune:
	for s in 100 500 1000; do make tune_uj2 MS=$$s NS=$$s KS=$$s; done

timer:
	cd $(top_builddir)/test/timerGeneration; make timer_c input="$(top_builddir)/test/autoScripts/gemvT2"; make timer_c input="$(top_builddir)/test/autoScripts/ger2"; make timer_c input="$(top_builddir)/test/autoScripts/dgetrf2"; make timer_c input="$(top_builddir)/test/autoScripts/gemm2"

time:	
	$(ICC) $(ICCFLAGS) -I${top_srcdir}/include -o dgemm.o -c dgemm.c || exit
	cd ${atlas_obj}/bin;  make xdmmtst; ./xdmmtst -b 1 $(beta) -N $(min) $(max) $(incr) -A 2 n n > ./ex.out; ./xstattime -# 2 -fd ex.out > ./ex.csv
	cp $(atlas_obj)/bin/ex.csv $(srcdir)


include ../../Make.inc
