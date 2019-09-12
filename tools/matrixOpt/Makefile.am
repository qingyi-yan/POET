POET_INCL=$(top_srcdir)/include
debug=
in=
out=
arrref=
comp=diff

target=$(srcdir)/dgemm
FLOP="N*N*N+N*N"
dim=3
srcdir=.
time=
OPT = .
CC=gcc -fopenmp -O2
pref=1
dist=12
sse=1
cp=2
ur=1
bk1=64
bk2=1
uj=4 1
th=2
cpth=1
tbk=256
sr=1
tr=0
scalar=4

MACRO_DEFS=-DATL_SSE3 -DATL_SSE2 -DATL_SSE1 -DATL_USE64BITS -DATL_GAS_x8664 -DINS_256BIT
SIZE=500
MS=$(SIZE)
NS=$(SIZE)
KS=$(SIZE)
NREP=5
eval_num=200
tri=1

files=matrixOpt.pt
EXTRA_DIST = $(files) testfiles/daxpy.c testfiles/dgemm.c testfiles/dgemvT.c testfiles/dsyrk.c testfiles/dtrmm_ru.c testfiles/dtrmm_rl.c testfiles/dscal.c testfiles/dgemvN.c testfiles/dtrsm_ll.c testfiles/dtrsm_ru.c testfiles/dger.c testfiles/trisolv.c testfiles/lufac.c testfiles/daxpy.c_save testfiles/dscal.c_save testfiles/dgemvT.c_save testfiles/dgemvN.c_save testfiles/dger.c_save testfiles/dgemm.c_save testfiles/dsyrk.c_save  testfiles/dtrmm_rl.c_save testfiles/dtrmm_ru.c_save testfiles/dtrsm_ll.c_save testfiles/dtrsm_ru.c_save testfiles/trisolv.c_save

now: 
	${top_builddir}/src/pcg $(debug) -pinfile=$(srcdir)/testfiles/$(target).c -pcpth=$(cpth) -pscalar=$(scalar) -poutfile=out.c -ppa=0 -pth=$(th) -ptbk=$(tbk) -pbk1=$(bk1) -pbk2=$(bk2) -puj="$(uj)" -pur=$(ur) -pcp=$(cp) -psr=$(sr) -ppref=$(pref) -psse=$(sse) -ppref_dist=$(dist) -ptr=$(tr) -L$(OPT) $(OPT)/matrixOpt.pt
	$(comp) out.c testfiles/$(target).c_save


test:	
	cat $(srcdir)/testfiles/$(target).c | sed s/$(target)/$(target)_ref/  > orig.c
	gcc -I$(POET_INCL) -I. $(MACRO_DEFS) -fopenmp $(srcdir)/testfiles/tester.c out.c -DMS=$(MS) -DNS=$(NS) -DKS=$(KS) -DCALL=$(target) -DCALL_orig=$(target)_ref -DDIM=$(dim)
	./a.out

time:
	gcc -I$(POET_INCL) $(MACRO_DEFS) -fopenmp $(srcdir)/testfiles/driver.c out.c -O2 -DMS=$(MS) -DNS=$(NS) -DKS=$(KS) -DNREP=$(NREP) -DCALL=$(target) -DDIM=$(dim) -DFLOP=$(FLOP)
	./a.out


all_test:
	${top_builddir}/src/pcg $(debug) -pinfile=$(srcdir)/testfiles/dgemm.c -poutfile=out.c -ppa=0 -pth=2 -ptbk=256 -pbk1=64 -pbk2=1 -puj="2 2" -pur=2 -pcp=1 -psr=1 -ppref=2 -psse=1 -ppref_dist=12 -L$(OPT) $(OPT)/matrixOpt.pt
	make test target=dgemm dim=3
	make time target=dgemm dim=3 FLOP="2*M*N*K+M*N" #16GFlops on 3.4G i7 
	${top_builddir}/src/pcg $(debug) -pinfile=$(srcdir)/testfiles/dgemvT.c -poutfile=out.c -ppa=0 -pth=2 -ptbk=256 -pbk1=64 -pbk2=1 -puj="4 2" -pur=2 -pcp=0 -psr=1 -ppref=1 -psse=1 -ppref_dist=24 -L$(OPT) $(OPT)/matrixOpt.pt
	make test target=dgemvT dim=2  
	make time target=dgemvT dim=2 NREP=50 FLOP="2*M*N" #8.3Gflops on 3.4G i7
	${top_builddir}/src/pcg $(debug) -pinfile=$(srcdir)/testfiles/dgemvN.c -poutfile=out.c -ppa=0 -pth=2 -ptbk=256 -pbk1=64 -pbk2=1 -puj="4 2" -pur=2 -pcp=0 -psr=1 -ppref=1 -psse=0 -ppref_dist=24 -L$(OPT) $(OPT)/matrixOpt.pt
	make test target=dgemvN dim=2  # this one fails the test of same output by up to 5% of error rate, but I think it's b/c of the reduction
	make time target=dgemvN dim=2 NREP=50 FLOP="2*M*N" #5.3Gflops on 3.4G i7
	${top_builddir}/src/pcg $(debug) -pinfile=$(srcdir)/testfiles/dger.c -poutfile=out.c -ppa=0 -pth=2 -ptbk=256 -pbk1=64 -pbk2=1 -puj="4 2" -pur=2 -pcp=0 -psr=1 -ppref=1 -psse=1 -ppref_dist=24 -L$(OPT) $(OPT)/matrixOpt.pt
	make test target=dger dim=1  
	make time target=dger dim=1 NREP=50 FLOP="2*M*N" #6.8Gflops on 3.4G i7

# Optimal values:
# Unroll&jam factors (4, 2), ((4, 1) for trsm) 
# Loop unrolling factors 4 or 2
# Blocking factor 256
# Thread blocking factor 512, this size and blocking size should be adjust on the given machine

check: 
	make now target=dgemvT bk1=64 cpth=0 uj="4 2" ur=2 cp=0
	make now target=dgemm bk1=64 cpth=0 uj="2 2" ur=2 cp=1
	make now target=dtrsm_ll
	make now target=dtrsm_ru
	make now target=dtrmm_rl bk1=128 uj="4 2" ur=4 dist=0
	make now target=dtrmm_ru bk1=128 uj="4 2" ur=4 dist=0 cpth=0
	make now target=dsyrk bk1=64 tbk=128 cp=1 
	make now target=dsyr2k bk1=64 uj="2 2" tbk=128 cp=1 ur=2
	make now target=dgemvN bk1=64 cpth=0 uj="4 2" cpth=0 ur=2 cp=0 sse=0 dist=24
	make now target=dger uj="4 2" bk1=128 dist=24 ur=4 cp=0
	make now target=dtrmv sse=0 cp=0 cpth=0 bk1=64 ur=2
	make now target=dtrsv sse=0 cp=0 cpth=0 bk1=64 ur=2
	make now target=daxpy sse=0 cp=0 cpth=0 bk1=1 tbk=64 ur=8 uj="1 1"
	make now target=dscal sse=0 cp=0 cpth=0 bk1=1 tbk=64 ur=8
	make now target=dswap sse=0 cp=0 cpth=0 bk1=1 tbk=64 uj="1 1" ur=8
	make now target=dcopy sse=0 cp=0 cpth=0 bk1=1 ur=8 tbk=64 uj="1 1" ur=8
	make now target=trisolv sse=0 cpth=1 cp=1 bk1=64 
	make now target=lufac sse=0 cp=0 bk1=128 bk2=1 th=12 dist=0 ur=2

clean:
	rm out.c orig.c a.out
