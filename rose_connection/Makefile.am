#include $(rose_srcdir)/config/Makefile.for.ROSE.includes.and.libs

bin_PROGRAMS = rose_pcg
rose_pcg_SOURCES=  main.cpp eval_ext_rose.cpp

poet_dir=${rose_srcdir}/src/3rdPartyLibraries/POET
comp=diff

EXTRA_DIST=Cpp_ROSE.incl 


check:
	./rose_pcg -L$(poet_dir)/lib -L$(srcdir) -pinfile="$(srcdir)/test/dgemm_test.C" -poutfile=cfg.out $(srcdir)/test/CFG.pt
	$(comp) cfg.out $(srcdir)/test/cfg.out
	./rose_pcg $(debug) -L$(srcdir) -L$(srcdir)/manycore-stencil -L$(srcdir)/manycore-stencil/include -L$(poet_dir)/lib -pin="$(srcdir)/manycore-stencil/benchmarks/tmp.C" $(srcdir)/manycore-stencil/stencil_opt.pt 
	$(comp) rose_tmp.C $(srcdir)/manycore-stencil/benchmarks/tmp-save.C
	./rose_pcg $(debug) -L$(srcdir)/manycore-stencil -L$(srcdir)/manycore-stencil/include -L$(poet_dir)/lib -L$(srcdir) -pin=$(srcdir)/manycore-stencil/benchmarks/"test6cell2.C" -pout="rose_test6cell2.C" $(srcdir)/manycore-stencil/stencil_opt.pt
	$(comp) rose_test6cell2.C $(srcdir)/manycore-stencil/benchmarks/test6cell2-save.C
	./rose_pcg $(debug) -pcp_num=8 -L$(srcdir)/manycore-stencil -L$(srcdir)/manycore-stencil/include -L$(poet_dir)/lib -L$(srcdir) -pin=$(srcdir)/manycore-stencil/benchmarks/"test6cell.C" $(srcdir)/manycore-stencil/stencil_opt.pt
	$(comp) rose_test6cell.C $(srcdir)/manycore-stencil/benchmarks/test6cell_rmem-save.C
	./rose_pcg $(debug) -L$(srcdir)/manycore-stencil -L$(srcdir)/manycore-stencil/include -L$(poet_dir)/lib -L$(srcdir) -pin=$(srcdir)/manycore-stencil/benchmarks/"test6cell.C" $(srcdir)/manycore-stencil/stencil_opt.pt
	$(comp) rose_test6cell.C $(srcdir)/manycore-stencil/benchmarks/test6cell-save.C

AM_YFLAGS=-d -v

INCLUDES = $(ROSE_INCLUDES) -I$(rose_srcdir)/src -I$(rose_srcdir)/src/util/support -I$(rose_srcdir)/src/util -I$(rose_srcdir)/src/midend/astProcessing -I$(rose_srcdir)/src/midend/abstractHandle -I$(rose_srcdir)/src/midend/astUtil/astInterface  -I$(rose_srcdir)/src/midend/astUtil/astSupport -I$(rose_srcdir)/src/midend/astUtil/symbolicVal  -I$(rose_srcdir)/src/3rdPartyLibraries/POET -I$(rose_srcdir)/src/frontend/SageIII -I$(rose_srcdir)/src/frontend/SageIII/astPostProcessing -I$(rose_srcdir)/src/frontend/SageIII/sageInterface -I$(rose_srcdir)/src/backend/unparser  -I$(rose_srcdir)/src/backend/unparser/languageIndependenceSupport  -I$(rose_srcdir)/src/backend/unparser/formatSupport

LDADD = $(LIBS_WITH_RPATH) $(ROSE_SEPARATE_LIBS)  ${top_builddir}/src/3rdPartyLibraries/POET/libpoet.la

compile_now: 
	g++ out.C -I $(srcdir)/manycore-stencil/include $(srcdir)/manycore-stencil/multicore.C $(srcdir)/manycore-stencil/core.C $(srcdir)/manycore-stencil/highresTimer.C -lrt -fopenmp

now: 
	./rose_pcg -L$(srcdir)/test $(srcdir)/test/opt_uj.pt
