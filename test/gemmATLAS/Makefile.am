mu=12
nu=1
ku=72
nb=72
PF=1
SP=1
alpha=0
orig=0
SSENO=16
SSELEN=16
pre="d"
debug=
sel= 20
permute1=(1,2,3,4)
permute2=(1,2)
threeAddress=1
AT=0
comp = diff

all: 

gemm :
	${top_builddir}/src/pcg ${debug} -L$(srcdir) -porig=${orig} -pmu=${mu} -pnu=${nu} -pku=${ku} -ppre=${pre} -pSSELEN=${SSELEN} -pSSENO=${SSENO} -palpha=${alpha} -pSP=${SP} -pNB=$(nb) -pMB=$(nb) -pKB=$(nb) -pPF=${PF} -psel=${sel} -ppermuteReg="${permute1}" -ppermuteUnroll="${permute2}" -pthreeAddress=${threeAddress} -paddressTranslate=${AT} ${srcdir}/gemm.pt;

files=gemm.pt gemmKernel.pt

EXTRA_DIST= $(files) dgemm_kernel.c.save dgemm_kernel.c.permute2431.save dgemm_kernel.c.permute3214.save 

check : 
	make gemm;
	$(comp) dgemm_kernel.c ${srcdir}/dgemm_kernel.c.save
	rm dgemm_kernel.c 
	make gemm permute1="(2,4,3,1)"
	$(comp) dgemm_kernel.c ${srcdir}/dgemm_kernel.c.permute2431.save
	rm dgemm_kernel.c 
	make gemm permute1="(3,2,1,4)"
	$(comp) dgemm_kernel.c ${srcdir}/dgemm_kernel.c.permute3214.save
	rm dgemm_kernel.c 

test:	
	cp dgemm_kernel.c ${atlas_obj}/tune/blas/gemm
	cd ${atlas_obj}/tune/blas/gemm;  make  mmutstcase pre=${pre}  nb=${nb} mmrout=./dgemm_kernel.c$

atlas:
	cp dgemm_kernel.c ${atlas_obj}/tune/blas/gemm
	cd ${atlas_obj}/tune/blas/gemm;  make ummcase pre=${pre} nb=${nb} mu=${mu} nu=${nu} ku=${ku} mmrout=./dgemm_kernel.c moves=${moves}

try_gemm: 
	make gemm
	make atlas

bk_sel = 32 40 48 56 64 72 80 88 96
tune_bk:
	for s in $(bk_sel); do make try_gemm nb="$$s" ku=$$s; done

tune_uj1:
	for s in 1 2 3 4 5 6 7 8 9 10 12; do make tune_bk mu=$$s; done	

tune_uj2:
	for s in 1 2 3 4 5 6 7 8 9 10 12; do make tune_uj1 nu=$$s; done	

include ../../Make.inc
