rA=1
yu=2
xu=12
ayu=${yu}
PF=1
SP=1
alpha=0
SSENO=16
SSELEN=16
pre="d"
moves="-DMoveA -DMoveB"
permute1 = (1,2,3,4)
permute2 = (1,2)
threeAddress=1
N = 8
M=${N}
align=1
POET_LIB=$(top_srcdir)/lib
comp=diff
debug=
orig=0
ker=1
AT=0

all: 

gerc2: 
	make ger ker=2 pre=c SSENO=0 rA=0
	make test2 pre=c
	make atlas2 pre=c

gerz2: 
	make ger ker=2 pre=z SSENO=0 rA=0
	make test2 pre=z
	make atlas2 pre=z

ger2: 
	make ger ker=2 
	make test2 
	make atlas2 

gerc: 
	make ger pre=c  xu=6 yu=1 SSENO=0
	make test pre=c
	make atlas pre=c

gerz: 
	make ger pre=z xu=6 yu=1 SSENO=0 rA=0
	make test pre=z
	make atlas pre=z

ger:
	${top_builddir}/src/pcg $(debug) -prA=$(rA) -pker=$(ker) -ppermuteReg="${permute1}" -pthreeAddress=${threeAddress} -ppermuteUnroll="${permute2}" -pyu=${yu} -pxu=${xu} -palign=${align} -ppre=${pre} -pSSELEN=${SSELEN} -pSSENO=${SSENO} -pPF=${PF} -porig=$(orig) -paddressTranslate=${AT} $(srcdir)/ger.pt 

files=ger.pt

EXTRA_DIST= $(files) dger_kernel.c.save zger_kernel.c.save zger_kernel2.c.save dger_kernel2.c.save dger_kernel.c.permute3214.save dger_kernel.c.permute2431.save  dger_kernel.c.permute21.save dger_kernel.c.PF4.save

check : 
	make ger;
	$(comp) dger_kernel.c ${srcdir}/dger_kernel.c.save
	rm dger_kernel.c 
	make ger permute1="(3,2,1,4)"
	$(comp) dger_kernel.c ${srcdir}/dger_kernel.c.permute3214.save
	rm dger_kernel.c 
	make ger permute1="(2,4,3,1)"
	$(comp) dger_kernel.c ${srcdir}/dger_kernel.c.permute2431.save
	rm dger_kernel.c
	make ger permute2="(2,1)"
	$(comp) dger_kernel.c ${srcdir}/dger_kernel.c.permute21.save
	rm dger_kernel.c
	make ger PF=4
	$(comp) dger_kernel.c ${srcdir}/dger_kernel.c.PF4.save
	rm dger_kernel.c
	make ger ker=2 pre=z SSENO=0 rA=0
	$(comp) dger_kernel.c ${srcdir}/zger_kernel2.c.save
	rm dger_kernel.c
	make ger ker=2 
	$(comp) dger_kernel.c ${srcdir}/dger_kernel2.c.save
	rm dger_kernel.c
	make ger pre=z xu=6 yu=1 SSENO=0 rA=0
	$(comp) dger_kernel.c ${srcdir}/zger_kernel.c.save
	rm dger_kernel.c
	
oldtest:	
	cp dger_kernel.c ${atlas_obj}/tune/blas/ger/CASES
	cd ${atlas_obj}/tune/blas/ger;  make ${pre}r1tstcase r1rout=./dger_kernel.c yu=${yu} xu=${xu} Mt=${M} Nt=${N}

oldatlas:
	cp dger_kernel.c ${atlas_obj}/tune/blas/ger/CASES
	cd ${atlas_obj}/tune/blas/ger;  make ${pre}r1case r1rout=./dger_kernel.c moves=${moves} yu=${ayu} xu=${xu}

test:	
	echo "#define ATL_$(pre)ger1_a1_x1_yX ATL_UGERK" > ${atlas_obj}/tune/blas/ger/R1CASES/dger_kernel.c
	cat dger_kernel.c >> ${atlas_obj}/tune/blas/ger/R1CASES/dger_kernel.c
	cd ${atlas_obj}/tune/blas/ger;  make ${pre}r1ktest r1rout=./dger_kernel.c yu=${yu} xu=${xu} Mt=${M} Nt=${N}

test2:	
	echo "#define ATL_$(pre)ger2_a1_x1_yX ATL_UGER2K" > ${atlas_obj}/tune/blas/ger/R2CASES/dger_kernel.c
	cat dger_kernel.c >> ${atlas_obj}/tune/blas/ger/R2CASES/dger_kernel.c
	cd ${atlas_obj}/tune/blas/ger;  make ${pre}r2ktest r2rout=./dger_kernel.c yu=${yu} xu=${xu} Mt=${M} Nt=${N}

atlas:
	echo "#define ATL_$(pre)ger1_a1_x1_yX ATL_UGERK" > ${atlas_obj}/tune/blas/ger/R1CASES/dger_kernel.c
	cat dger_kernel.c >> ${atlas_obj}/tune/blas/ger/R1CASES/dger_kernel.c
	cd ${atlas_obj}/tune/blas/ger;  make ${pre}r1time r1rout=dger_kernel.c moves=${moves} yu=${ayu} xu=${xu};  

try_ger: 
	make ger
	make oldatlas

try_ger0: 
	make ger
	make atlas

tune_uj1:
	for s in 1 2 3 4 5 6 7 8 9 10 11 12; do make try_ger xu=$$s; done	

tune_uj2:
	for s in 1 2 3 4 5 6 7 8 9 10 11 12; do make tune_uj1 yu=$$s; done	


atlas2:
	cd ${atlas_obj}/tune/blas/ger;  make ${pre}r2time r2rout=dger_kernel.c moves=${moves} yu=${ayu} xu=${xu};  

compare:
	cd ${atlas_obj}/tune/blas/ger; make ${pre}r1time r1rout=ATL_gerk_4x4_1.c l1mul=0 N=8000

compare2:
	cd ${atlas_obj}/tune/blas/ger; make ${pre}r2time r2rout=ATL_gerk_4x4_1.c l2mul=0 N=8000

include ../../Make.inc
