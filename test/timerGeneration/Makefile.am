
files=testerGeneration.pt testerGeneration.incl timerGeneration.pt timerGeneration.incl specification.code testerCodeTemplates.code timerCodeTemplates.code testerGeneration.incl testerGeneration.pt testerCodeTemplates.code specification.incl specGeneration.pt

EXTRA_DIST=$(files) trmm.spec gemm.spec gemm1.spec gemv.spec ger.spec chfac.spec gemm_timer_1_1_Pentium.c gemm_timer_1_1_generic.c gemm_timer_1_1_x86.c gemm_timer_10_1_generic.c gemm_timer_10_500_generic.c gemv_timer_1_100_generic.c ger_timer_5_100_generic.c dgemm.spec

FLUSHMETHOD=generic
FLUSHSZ=4098
arch=generic
mhz=2160
mt=10
nrep=500
UseWallTime=1
debug=
comp=diff


input=dgemm
output=
WF=GetCycleCount.S

spec:
	$(top_builddir)/src/pcg -L$(srcdir) $(debug) -pinfile=$(srcdir)/../autoScripts/rose_$(input).C -poutfile=out.spec specGeneration.pt
	diff out.spec $(srcdir)/$(input).spec
	rm out.spec

	
all : 

check:
	make spec input=dgemm
	make tester_c input=dgemm
	$(comp) dgemm_tester.c $(srcdir)/../autoScripts/dgemm_tester.c
	rm dgemm_tester.c
	make timer_c input=dgemm
	$(comp) dgemm_timer.c $(srcdir)/../autoScripts/dgemm_timer.c
	rm dgemm_timer.c
	make tester_c input=trmm
	$(comp) trmm_tester.c $(srcdir)/../autoScripts/trmm_tester.c
	rm trmm_tester.c
	make timer_c input=trmm mt=10 nrep=1 arch="generic"
	$(comp) trmm_timer.c $(srcdir)/../autoScripts/trmm_timer.c
	rm trmm_timer.c
	make tester_c input=chfac 
	$(comp) chfac_tester.c $(srcdir)/../autoScripts/chfac_tester.c
	rm chfac_tester.c
	make timer_c input=chfac mt=10 nrep=1 arch="generic"
	$(comp) chfac_timer.c $(srcdir)/../autoScripts/chfac_timer.c
	rm chfac_timer.c
	make timer_c input=gemm1 mt=1 nrep=1 arch="Pentium"
	$(comp) gemm1_timer.c $(srcdir)/gemm_timer_1_1_Pentium.c
	rm gemm1_timer.c
	make timer_c input=gemm1 mt=1 nrep=1 arch="generic"
	$(comp) gemm1_timer.c $(srcdir)/gemm_timer_1_1_generic.c
	rm gemm1_timer.c
	make timer_c input=gemm1 mt=1 nrep=1 arch="x86"
	$(comp) gemm1_timer.c $(srcdir)/gemm_timer_1_1_x86.c
	rm gemm1_timer.c
	rm GetCycleCount.S
	make timer_c input=gemm1 mt=10 nrep=1 
	$(comp) gemm1_timer.c $(srcdir)/gemm_timer_10_1_generic.c
	rm gemm1_timer.c
	make timer_c input=gemm mt=10 nrep=500 
	$(comp) gemm_timer.c $(srcdir)/gemm_timer_10_500_generic.c
	rm gemm_timer.c
	make timer_c input=gemv mt=1 nrep=100 arch="generic"
	$(comp) gemv_timer.c $(srcdir)/gemv_timer_1_100_generic.c
	rm gemv_timer.c
	make timer_c input=ger mt=5 nrep=100 arch="generic"
	$(comp) ger_timer.c $(srcdir)/ger_timer_5_100_generic.c
	rm ger_timer.c


timer_gemm :
	$(CC) -O -o $@ gemm_timer.c dgemm_kernel.c 

timer_gemv :
	$(CC) -O -o $@ gemv_timer.c dgemv_kernel.c -DBETAX

#makes the timer source from the input specification

timer_c:
	$(top_builddir)/src/pcg -L$(srcdir) $(debug) -md -pCacheFlushMethod=$(FLUSHMETHOD) -pCacheKB=$(FLUSHSZ) -pISA=$(arch) -pMHZ=$(mhz) -pNREP=$(nrep) -pUseWallTime=$(UseWallTime) -pMT=$(mt) -pinfile=$(srcdir)/$(input).spec -poutfile=$(input)_timer.c -poutLang="Cfront.code" $(srcdir)/timerGeneration.pt 

tester_c:
	$(top_builddir)/src/pcg -L$(srcdir) -L$(top_srcdir)/lib $(debug) -md -pinfile=$(srcdir)/$(input).spec -poutfile=$(input)_tester.c -poutLang="Cfront.code" $(srcdir)/testerGeneration.pt 

clean:
	rm -rfv *.o *.S *~ *_timer.c 

include ../../Make.inc
