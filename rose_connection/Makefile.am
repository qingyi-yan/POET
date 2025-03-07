
bin_PROGRAMS = rose_pcg
rose_pcg_SOURCES= eval_ext_rose.cpp main.cpp

AM_YFLAGS=-d -v
AM_CPPFLAGS = -DPOET_LIB_DIR=\"$(abs_top_srcdir)/lib\" -DPOET_DEST_DIR=\"$(DESTDIR)/$(libdir)/\"

INCLUDES = $(ROSE_INCLUDES) -I$(rose_install)/include/rose -I../src

LDADD = $(LIBS_WITH_RPATH) $(rose_install)/lib/librose.so  ../src/libpoet.a 

AM_YFLAGS=-d -v
AM_CPPFLAGS = -DPOET_LIB_DIR=\"$(abs_top_srcdir)/lib\" -DPOET_DEST_DIR=\"$(DESTDIR)/$(libdir)/\"

include ${top_srcdir}/Make.inc

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

compile_now: 
	g++ out.C -I $(srcdir)/manycore-stencil/include $(srcdir)/manycore-stencil/multicore.C $(srcdir)/manycore-stencil/core.C $(srcdir)/manycore-stencil/highresTimer.C -lrt -fopenmp

now: 
	./rose_pcg -L$(srcdir)/test $(srcdir)/test/opt_uj.pt
