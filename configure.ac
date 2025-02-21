AC_INIT([POET], 1.07.03, qyi@uccs.edu)
AC_PREREQ([2.61])
AC_PROG_RANLIB
AC_PROG_CXX
AC_PROG_CC
AC_DECL_YYTEXT
AC_PROG_YACC
AM_PROG_LEX
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([src/Makefile])
AC_CONFIG_FILES([lib/Makefile])
AC_CONFIG_FILES([doc/Makefile])
AC_CONFIG_FILES([test/Makefile])
AC_CONFIG_FILES([test/gemmATLAS/Makefile])
AC_CONFIG_FILES([test/gemvATLAS/Makefile])
AC_CONFIG_FILES([test/gerATLAS/Makefile])
AC_CONFIG_FILES([test/autoScripts/Makefile])
AC_CONFIG_FILES([test/commands/Makefile])
AC_CONFIG_FILES([test/timerGeneration/Makefile])
AC_CONFIG_FILES([test/parseF/Makefile])
AC_CONFIG_FILES([test/tune/Makefile])
AC_CONFIG_FILES([examples/Makefile])
AC_CONFIG_FILES([test/parseC/Makefile])
AC_CONFIG_FILES([test/parsePy/Makefile])
AC_CONFIG_FILES([test/libFunctions/Makefile])
AC_CONFIG_FILES([test/SMT/Makefile])
AC_CONFIG_FILES([tools/Makefile])
#AC_CONFIG_FILES([tools/highlevel_interface/Makefile])
#AC_CONFIG_FILES([tools/test_files/Makefile])
#AC_CONFIG_FILES([tools/test_files/input/Makefile])
#AC_CONFIG_FILES([tools/test_files/output/Makefile])
#AC_CONFIG_FILES([tools/auto_tuning/Makefile])
#AC_CONFIG_FILES([tools/matrixOpt/Makefile])
#AC_CONFIG_FILES([tools/stencil-codegen/Makefile])
#AC_CONFIG_FILES([tools/splash2Prof/Makefile])

test -n "$atlas_obj" || atlas_obj="";
test -n "$rose_srcdir" || rose_srcdir="";
test -n "$atlas_exe" || atlas_exe=xdmmtst;
test -e "$atlas_obj" && atlas_inc="${atlas_obj}/Make.inc";

testdirs="commands gemmATLAS gemvATLAS gerATLAS autoScripts timerGeneration parseF parseC SMT tune libFunctions"; 
#tooldirs="highlevel_interface test_files auto_tuning matrixOpt stencil-codegen splash2Prof";
tooldirs="";

AC_SUBST(atlas_obj)
AC_SUBST(atlas_exe)
AC_SUBST(atlas_inc)
AC_SUBST(testdirs)
AC_SUBST(tooldirs)
AC_SUBST(rose_srcdir)
AM_INIT_AUTOMAKE([1.10])
AC_OUTPUT
