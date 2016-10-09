
files=

EXTRA_DIST=tester.c driver.c $(files) 

SUBDIRS=input output

CC=gcc

MS=500
NS=500
KS=500
NREP=1
extra=
target=dgemm_3
th=""
comp=diff

tune:
	perl $(builddir)/../auto_tuning/tune.pl $(srcdir)/input/$(target).c

gen_spec:
	$(top_builddir)/src/pcg -L$(top_srcdir)/test/timerGeneration -pinfile=$(srcdir)/input/$(target).c -poutfile=$(target).spec $(top_srcdir)/test/timerGeneration/specGeneration.pt
	$(comp) $(target).spec $(srcdir)/input/$(target).spec
	rm $(target).spec

gen_test:
	$(top_builddir)/src/pcg -L$(top_srcdir)/test/timerGeneration -pinfile=$(srcdir)/input/$(target).spec -poutfile=$(target)_tester.c $(top_srcdir)/test/timerGeneration/testerGeneration.pt
	$(comp) $(target)_tester.c $(srcdir)/input/$(target)_tester.c
	rm $(target)_tester.c

gen_timer:
	$(top_builddir)/src/pcg -L$(top_srcdir)/test/timerGeneration -pinfile=$(srcdir)/input/$(target).spec -poutfile=$(target)_timer.c $(top_srcdir)/test/timerGeneration/timerGeneration.pt
	$(comp) $(target)_timer.c $(srcdir)/input/$(target)_timer.c
	rm $(target)_timer.c

test:	
	$(CC) -I. -I$(top_srcdir)/include -fopenmp input/$(target)_tester.c input/$(target)_opt.c 
	./a.out

SIZE=500

time:	
	$(CC) -O2 -I. -fopenmp -DSIZE=$(SIZE) -DMT=10 -DNREP=$(NREP) input/$(target)_timer.c input/$(target)_opt.c 
	./a.out

test_old:	
	cat input/$(target).c | sed s/$(target)/$(target)_ref/  > orig.c
	$(CC) -I. -fopenmp tester.c input/$(target)_opt.c -DMS=$(MS) -DNS=$(NS) -DKS=$(KS) -DCALL=$(target) -DCALL_orig=$(target)_ref -DDIM=$(dim) $(extra)
	./a.out

time_old:
	$(CC) -O2 -fopenmp driver.c input/$(target)_opt.c -DMS=$(MS) -DNS=$(NS) -DKS=$(KS) -DNREP=$(NREP) -DCALL=$(target) -DDIM=$(dim) -DFLOP="$(FLOP)" $(extra)
	./a.out

each:
	cd $(srcdir)/../highlevel_interface; make each debug=$(debug) th="$(th)" target=$(top_srcdir)/tools/test_files/input/$(target) save=$(top_srcdir)/tools/test_files/output/$(target)_save

splashX:
	cd $(srcdir)/../highlevel_interface; make each debug=$(debug) th="$(th)" target=$(top_srcdir)/tools/test_files/splash2/$(target) save=$(top_srcdir)/tools/test_files/splash2/$(target)_save

splashXclean:
	find splash2/barnes/ -type f \( -name '*.pt' -or -name '*_opt.c' \) -not -name '*_save.pt' | xargs rm -rf
	find splash2/fmm/ -type f \( -name '*.pt' -or -name '*_opt.c' \) -not -name '*_save.pt' | xargs rm -rf
	find splash2/raytrace/ -type f \( -name '*.pt' -or -name '*_opt.c' \) -not -name '*_save.pt' | xargs rm -rf
	find splash2/volrend/ -type f \( -name '*.pt' -or -name '*_opt.c' \) -not -name '*_save.pt' | xargs rm -rf
	find splash2/water_nsquared/ -type f \( -name '*.pt' -or -name '*_opt.c' \) -not -name '*_save.pt' | xargs rm -rf
	find splash2/ocean_cp/ -type f \( -name '*.pt' -or -name '*_opt.c' \) -not -name '*_save.pt' | xargs rm -rf
	find splash2/ocean_ncp/ -type f \( -name '*.pt' -or -name '*_opt.c' \) -not -name '*_save.pt' | xargs rm -rf
	find splash2/radiosity -type f \( -name '*.pt' -or -name '*_opt.c' \) -not -name '*_save.pt' | xargs rm -rf
	find splash2/water_spatial -type f \( -name '*.pt' -or -name '*_opt.c' \) -not -name '*_save.pt' | xargs rm -rf

check:
#	make splashX target=water_nsquared/poteng_inlined
	make splashX target=water_spatial/poteng_unrolled
	make splashX target=volrend/raytrace
#QY: result lost a loop nest at the end from ScalarRepl
	make splashX target=water_spatial/poteng_inlined
	make splashX target=water_spatial/poteng_inline
#	make splashX target=water_spatial/interf_unrolled
	make splashX target=water_spatial/interf_inlined
	make splashX target=water_spatial/interf_inline
	make splashX target=radiosity/visible
	make splashX target=ocean_ncp/laplacalc
	make splashX target=ocean_ncp/jacobcalc
	make splashX target=ocean_ncp/multi_fuse
	make splashX target=ocean_cp/jacobcalc2
	make splashX target=ocean_cp/jacobcalc
	make splashX target=ocean_cp/multi_fused
	make splashX target=ocean_cp/multi_fuse
	make splashX target=fmm/interactions_dist
	make splashX target=fmm/interactions_disted
	make splashX target=fmm/interactions_disted_unrolled
	make splashX target=water_nsquared/poteng_inline
#QY: result lost a loop nest at the end from ScalarRepl
#	make splashX target=water_nsquared/interf_inlined
	make splashX target=water_nsquared/interf_inline
	make splashX target=volrend/raytrace_prefetch
	make splashX target=raytrace/tri
	make splashX target=raytrace/husetup
	make splashX target=barnes/grav_inlined
	make splashX target=barnes/grav_inline
	make each target=DistributeLoop1
	make each target=DistributeLoop2
	make each target=DistributeLoop3
	make each target=jacobi7
	make each target=dger_2
#	make test target=jacobi7 dim=4 MS=50 NS=50 KS=50
#	make time  target=jacobi7 dim=4 MS=100 NS=100 KS=100 extra="-DTIME_STEPS=30" FLOP="M*N*K*TIME_STEPS"
	make gen_spec target=jacobi7_3
	make gen_test target=jacobi7_3
#	make gen_timer target=jacobi7_3
	make each target=jacobi7_3
#	make test target=jacobi7_3 SIZE=30
#	make time target=jacobi7_3 SIZE=100 
#	make time_old target=jacobi7_3 dim=4 MS=100 NS=100 KS=100 extra="-DTIME_STEPS=30" FLOP="M*N*K*TIME_STEPS"
	make each target=dgemm_2
	make each target=dgemm_3
#	make test target=dgemm_2 dim=3
#	make time target=dgemm_2 dim=3 FLOP="2*M*N*K+M*N" #16GFlops on 3.4G i7 
	make gen_spec target=dgemvN
	make gen_test target=dgemvN
	make gen_timer target=dgemvN
	make each target=dgemvN
#	make test target=dgemvN 
#	make time target=dgemvN NREP=50
	make each target=dgemvT
#	make test target=dgemvT dim=2  
#	make time target=dgemvT dim=2 NREP=50 FLOP="2*M*N" 
	make gen_spec target=dgemm_1
	make gen_test target=dgemm_1
	make gen_timer target=dgemm_1
	make each target=dgemm_1  
#	make test target=dgemm_1
#	make time target=dgemm_1
#	make test_old target=dgemm_1 dim=3
#	make time_old target=dgemm_1 dim=3 FLOP="2*M*N*K+M*N" 
	make each target=jacobi7_2
#	make test target=jacobi7_2 dim=4 MS=50 NS=50 KS=50
#	make time  target=jacobi7_2 dim=4 MS=100 NS=100 KS=100 extra="-DTIME_STEPS=30" FLOP="M*N*K*TIME_STEPS"
	make each target=vmult_1
#	make test_old target=vmult_1 dim=2 extra="-DLDA=50000"
#	make time_old target=vmult_1 dim=2 extra="-DLDA=50000" NREP=50 FLOP="2*M*N" 
	make each target=vmult_2
#	make test_old target=vmult_2 dim=2 extra="-DLDA=50000"
#	make time_old target=vmult_2 dim=2 extra="-DLDA=50000" NREP=50 FLOP="2*M*N" 
	make each target=jacobi7_4

clean:
	make splashXclean
	rm -rf *.o a.out a.out.* orig.c output/opt_files/out.c output/pt_scripts/*.pt
