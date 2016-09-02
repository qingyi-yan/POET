yu=2
xu=8
PF=1
SSENO=16
SSELEN=16
pre="d"
align=1
moves="-DMoveA -DMoveB"
permute1 = (1,2,3,4)
permute2 = (1,2)
threeAddress=1
AT=0
debug=
PCG = $(top_builddir)/src/pcg 
comp=diff

files=gemv-T.pt gemv-N.pt
EXTRA_DIST= $(files) dgemv_kernel-T.c.save dgemv_kernel-T.c.permute3214.save dgemv_kernel-N.c.save dgemv_kernel-N.c.permute3214.save dgemv_kernel-T.c.permute2431.save dgemv_kernel-N.c.permute2431.save dgemv_kernel-T.c.permute21.save dgemv_kernel-N.c.permute21.save

all: 

gemvT :
	${PCG} ${debug} -pyu=${yu} -pxu=${xu} -ppre=${pre} -palign=${align} -pSSELEN=${SSELEN} -pSSENO=${SSENO} -pPF=${PF} -ppermuteReg="${permute1}" -pthreeAddress=${threeAddress} -ppermuteUnroll="${permute2}" -paddressTranslate=${AT} $(srcdir)/gemv-T.pt;

gemvN :
	${PCG} ${debug} -pyu=${yu} -pxu=${xu} -ppre=${pre} -palign=${align} -pSSELEN=${SSELEN} -pSSENO=${SSENO} -pPF=${PF} -ppermuteReg="${permute1}" -pthreeAddress=${threeAddress} -ppermuteUnroll="${permute2}" -paddressTranslate=${AT} $(srcdir)/gemv-N.pt;

check : 
	make gemvT;
	$(comp) dgemv_kernel.c ${srcdir}/dgemv_kernel-T.c.save
	make gemvN;
	$(comp) dgemv_kernel.c ${srcdir}/dgemv_kernel-N.c.save
	rm dgemv_kernel.c orig.c
	make gemvT permute1="(3,2,1,4)"
	$(comp) dgemv_kernel.c ${srcdir}/dgemv_kernel-T.c.permute3214.save
	rm dgemv_kernel.c orig.c
	make gemvN permute1="(3,2,1,4)"
	$(comp) dgemv_kernel.c ${srcdir}/dgemv_kernel-N.c.permute3214.save
	rm dgemv_kernel.c orig.c
	make gemvT permute1="(2,4,3,1)"
	$(comp) dgemv_kernel.c ${srcdir}/dgemv_kernel-T.c.permute2431.save
	rm dgemv_kernel.c orig.c
	make gemvN permute1="(2,4,3,1)"
	$(comp) dgemv_kernel.c ${srcdir}/dgemv_kernel-N.c.permute2431.save
	rm dgemv_kernel.c orig.c
	make gemvT permute2="(2,1)"
	$(comp) dgemv_kernel.c ${srcdir}/dgemv_kernel-T.c.permute21.save
	rm dgemv_kernel.c orig.c
	make gemvN permute2="(2,1)"
	$(comp) dgemv_kernel.c ${srcdir}/dgemv_kernel-N.c.permute21.save
	rm dgemv_kernel.c orig.c


testN:
	cp dgemv_kernel.c ${atlas_obj}/tune/blas/gemv/CASES
	cd $(atlas_obj)/tune/blas/gemv;  make ${pre}mvtstcaseN mvrout=./dgemv_kernel.c yu=${yu} xu=${xu}

testT:
	cp dgemv_kernel.c ${atlas_obj}/tune/blas/gemv/CASES
	cd $(atlas_obj)/tune/blas/gemv;  make ${pre}mvtstcaseT mvrout=dgemv_kernel.c yu=${yu} xu=${xu}

atlasN:
	cp dgemv_kernel.c ${atlas_obj}/tune/blas/gemv/CASES
	cd $(atlas_obj)/tune/blas/gemv;  make ${pre}mvcaseN mvrout=dgemv_kernel.c moves=${moves} yu=${yu} xu=${xu}

atlasT:	
	cp dgemv_kernel.c ${atlas_obj}/tune/blas/gemv/CASES
	cd $(atlas_obj)/tune/blas/gemv;  make ${pre}mvcaseT mvrout=./dgemv_kernel.c moves=${moves} yu=${yu} xu=${xu}


try_gemvT: 
	make gemvT
	make atlasT

tune_uj1:
	for s in 1 2 3 4 5 6 7 8 9 10 11 12; do make try_gemvT xu=$$s; done	

tune_uj2:
	for s in 1 2 3 4 5 6 7 8 9 10 11 12; do make tune_uj1 yu=$$s; done	

include ../../Make.inc
