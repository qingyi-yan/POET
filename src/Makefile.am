
bin_PROGRAMS = pcg
pcg_SOURCES=  poet_AST.cpp main.cpp codegen.cpp parse.cpp tokenize.cpp eval.cpp eval_ext.cpp evalOp.cpp driver.cpp timing.cpp poet_yacc.y poet_lex.l 

noinst_LIBRARIES = libpoet.a
libpoet_a_SOURCES=poet_AST.cpp codegen.cpp parse.cpp eval.cpp eval_ext.cpp evalOp.cpp driver.cpp tokenize.cpp timing.cpp poet_yacc.c poet_lex.c

EXTRA_DIST = poet_ASTfactory.h poet_SymbolTable.h poet_AST.h poet_ASTinterface.h poet_ASTvisitor.h poet_error.h poet_config.h poet_ASTeval.h timing.h

files = $(EXTRA_DIST) $(pcg_SOURCES)

AM_YFLAGS=-d -v
AM_CPPFLAGS = -DPOET_LIB_DIR=\"$(abs_top_srcdir)/lib\" -DPOET_DEST_DIR=\"$(DESTDIR)/$(libdir)/\"

include ${top_srcdir}/Make.inc
rosedir= $(rose_srcdir)/src/3rdPartyLibraries/POET
