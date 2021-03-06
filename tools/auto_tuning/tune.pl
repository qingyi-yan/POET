#!/usr/bin/perl -w

$POETDIR="/home/qyi/POET";
$POETTRUNK="$POETDIR/trunk";
#$POETSE="$POETDIR/SearchEngine";

$POETCMD="$POETTRUNK/src/pcg";

$POETHLI="$POETTRUNK/tools/highlevel_interface";
$POETHLIPT="$POETHLI/xforms2pt.pt";

$POETTG="$POETTRUNK/test/timerGeneration";
$POETSPECPT="$POETTG/specGeneration.pt";
$POETTESTERPT="$POETTG/testerGeneration.pt";
$POETTIMERPT="$POETTG/timerGeneration.pt";

#$POETTUNE="$POETTRUNK/test/tune";
#$POETTUNEPT="$POETTUNE/gen_searchInfo.pt";
#$POETTUNEFT="search_spec.code";
#$POETMAKEFT="$POETSE/benchmarks/scripts/search_make.code";
#$POETCC="gcc -fopenmp -O2";

$SPECINPUTSIZE=400;
$TIMERMT=3;
$TIMERCacheKB=1000;#default, will be set based on machine
$TIMERCacheFlushMethod="generic";
$TIMERNREP=100;

$RESULT="./.tmpXXX";

$FULL_STEPS=8;
$SIMPLE_STEPS=5;

my $total_steps;			# total steps to be executed
my $taget_file_suffix;			# target file with suffix: xxx.c
my $target_file;			# target file name: xxx
my $gen_xs_file;			# generated xs file: xxx.xs
my $gen_c_file;				# generated c file: xxx.c
my $gen_opt_c_file;			# generated opt c file: opt_xxx.c
my $gen_pt_file;			# generated pt file: xxx.pt
my $gen_spec_file;			# generated spec file: xxx.spec
my $gen_tester_file="tester.c";		# generated tester file: tester.c
my $gen_timer_file="timer.c";		# generated timer file: timer.c
my $gen_tune_file;			# generated tune file: xxx.tune;
my $gen_makefile="Makefile";		# generated makefile;
my $gen_pseat_file;			# generated pseat file: xxx.pseat

my $c_file_make;			# original c file for make
my $opt_c_file_make;			# opt c file for make
my $tester_file_make="tester.c";	# tester file for make
my $timer_file_make="timer.c";       	# timer file for make

my $IS_X8664 = 0;
my $HAS_SSE = 0;
my $HAS_SSE2 = 0;
my $HAS_SSE3 = 0;
my $HAS_3DNOW = 0;
my $HAS_AVX = 0;

# Print Version
sub version ()
{
  print "AutoExtract 0.1\n";
  exit 0;
}

# Print usage and exit
sub usage ()
{
  my $me = $0;

  print <<END;

Usage: $me [OPTIONS] [input C file]

OPTIONS:
	--version		print version number
	--help			print this help
	to be implement

END

  exit 0;
}

# Parse command line arguments
sub parse_arguments ()
{
  my %cmd_options = (
    'version'	=> \&version,
    'help'	=> sub {usage()},
  );

  use Getopt::Long qw(:config bundling pass_through);
  Getopt::Long::GetOptions %cmd_options or exit 0;

  # Check parameters.
  @ARGV == 1 or usage();

  $target_file_suffix = shift @ARGV;

  $_ = reverse $target_file_suffix;
  my $temp = index($_, "/");
  if (substr($_, 0, 2) ne "c.")
  {
    print "Error file name format: $target_file_suffix, must be in \"*.c\" format.\n";
    exit 0;
  }
  if ($temp ne -1) {
    $target_file = reverse substr($_, 2, $temp-2);
  } else {
    $target_file = reverse substr($_, 2, length($_));
  }
  $gen_xs_file = $target_file.".xs";
  $gen_c_file = $target_file.".c";
  $gen_opt_c_file = "opt_".$target_file.".c";
  $gen_pt_file = $target_file.".pt";
  $gen_spec_file = $target_file.".spec";
  $gen_tune_file = $target_file.".tune";
}

sub check
{
  my $CMD = $_[0];
  @ret = readpipe("grep -E \"error|Error|No such file or directory|mismatch|Segmentation fault|Invalid\" $RESULT");
  if (@ret) {
    print "Failed\n";
    print "$CMD\n\n";
    system("cat $RESULT");
    print "\n";
    `rm $RESULT`;
    exit -1;
  }
  `rm $RESULT`;
  print "Success\n";
  print "$CMD\n\n";
}

# Check Architecture for SIMD Optimization Macro
sub arch_info
{
  $ARCH = `arch`;
  if ($ARCH eq "x86_64\n") {
    $IS_X8664 = 1;
  #  print " x86_64.. yes\n";
  }
  @ret = readpipe("cat /proc/cpuinfo | grep sse");
  if (@ret) {
    $HAS_SSE = 1;
  #  print " SSE..... yes\n";
  }
  @ret = readpipe("cat /proc/cpuinfo | grep sse2");
  if (@ret) {
    $HAS_SSE2 = 1;
  #  print " SSE2.... yes\n";
  }
  @ret = readpipe("cat /proc/cpuinfo | grep pni");
  if (@ret) {
    $HAS_SSE3 = 1;
  #  print " SSE3.... yes\n";
  }
  @ret = readpipe("cat /proc/cpuinfo | grep 3dnow");
  if (@ret) {
    $HAS_3DNOW = 1;
  #  print " 3DNOW... yes\n";
  }
  @ret = readpipe("cat /proc/cpuinfo | grep avx");
  if (@ret) {
    $HAS_AVX = 1;
  #  print " AVX..... yes\n";
  }

  # get cache size info, usually L3
  $CacheInfo=`grep . /sys/devices/system/cpu/cpu0/cache/index*/* | grep size | tail -n 1`;
  $pos1 = index($CacheInfo, ":", 0);
  $pos2 = index($CacheInfo, "K", 0);
  $TIMERCacheKB = substr($CacheInfo, $pos1+1, $pos2-$pos1-1);
}

#################### Main Program ######################

parse_arguments;

if (-e $target_file_suffix) {
  #pass;
} else {
  print "Error: $target_file_suffix not exist.\n";
  exit 0;
}

# Check the type of the input file.
# Intermediate file or optimized source file?
# For intermediate file: generate xs file and pt file firstly
# For optimized source file: generate tester and timer

@ret = readpipe("grep -E \"PermuteLoops|ParallelizeLoop|FuseLoops|BlockLoops|CopyRepl|UnrollLoop|UnrollJam|ScalarRepl|DistributeLoop|InlineFunction|StrengthReduction|RedundancyElimination|SoftwarePrefetch\" $target_file_suffix");
if (@ret) {
  $total_steps=$FULL_STEPS;
  print "\nI guess: need to generate xs and pt files.\n";
} else {
  $total_steps=$SIMPLE_STEPS;;
  print "\nI guess: no need to generate xs and pt files.\n";
}

#$target_file="./".$target_file;
$current_step=1;
print "\n[$current_step/$total_steps] Create directory $target_file ...  ";
$ret = mkdir ($target_file);
if ($ret) {
  print "Success\n\n";
} else {
  print ("Failed.\n      $!: $target_file\n\n");
  exit -1;
}

$c_file_make=$gen_c_file;
$opt_c_file_make=$gen_opt_c_file;

$gen_xs_file=$target_file."/".$gen_xs_file;
$gen_c_file=$target_file."/".$gen_c_file;
$gen_opt_c_file=$target_file."/".$gen_opt_c_file;
$gen_pt_file=$target_file."/".$gen_pt_file;
$gen_spec_file=$target_file."/".$gen_spec_file;
$gen_tester_file=$target_file."/".$gen_tester_file;
$gen_timer_file=$target_file."/".$gen_timer_file;
#$gen_tester=$target_file."/".$gen_tester;
#$gen_timer=$target_file."/".$gen_timer;
$gen_tune_file=$target_file."/".$gen_tune_file;
$gen_makefile=$target_file."/".$gen_makefile;

if ($total_steps eq $FULL_STEPS) {
  $current_step=$current_step+1;
  print "[$current_step/$total_steps] Generate $gen_xs_file & $gen_c_file ...  ";

  open (INPUTFILE, $target_file_suffix) || die ("Could not open file: $target_file_suffix");
  open (GEN_XS_FILE, ">$gen_xs_file") || die ("Could not open file: $gen_xs_file");
  open (GEN_C_FILE, ">$gen_c_file") || die ("Could not open file: $gen_c_file");

  my $xs_flag = 1;
  while(<INPUTFILE>)
  {
    if (m/#begin/) {
      next;
    }
    if (m/#end/) {
      $xs_flag = 0;
      next;
    }
    if ($xs_flag eq 1) {
      print GEN_XS_FILE $_;
    } else {
      print GEN_C_FILE $_;
    }
  }

  close (INPUTFILE);
  close (GEN_XS_FILE);
  close (GEN_C_FILE);

  print "Success\n\n";

  # Generate PT file
  $current_step=$current_step+1;
  print "[$current_step/$total_steps] Generate $gen_pt_file ...  ";
  $GPT_CMD="$POETCMD -t -L$POETHLI -pinputFile=$gen_xs_file -poutputFile=$gen_pt_file $POETHLIPT 1>$RESULT 2>&1";
  `$GPT_CMD`;
  check($GPT_CMD);

  # Generate optimized c file
  $current_step=$current_step+1;
  print "[$current_step/$total_steps] Generate $gen_opt_c_file ...  ";
  $GOC_CMD="$POETCMD -t -L$POETHLI -pinputFile=$gen_c_file -poutputFile=$gen_opt_c_file $gen_pt_file 1>$RESULT 2>&1";
  `$GOC_CMD`;
  check($GOC_CMD);
}
else {
  `cp $target_file_suffix $gen_c_file`;
  `cp $target_file_suffix $gen_opt_c_file`;
}

# Generate SPEC file
$current_step=$current_step+1;
print "[$current_step/$total_steps] Generate $gen_spec_file... ";
$GSPEC_CMD="$POETCMD -L$POETTG -pin=$gen_c_file -pout=$gen_spec_file -pDEFAULT_SIZE=$SPECINPUTSIZE $POETSPECPT 1>$RESULT 2>&1";
`$GSPEC_CMD`;
check($GSPEC_CMD);

# Generate TESTER file
$current_step=$current_step+1;
print "[$current_step/$total_steps] Generate $gen_tester_file... ";
$GTESTER_CMD="$POETCMD -L$POETTG -pin=$gen_spec_file -pout=$gen_tester_file $POETTESTERPT 1>$RESULT 2>&1";
`$GTESTER_CMD`;
check($GTESTER_CMD);

# Check Architecture information
arch_info;

# Generate TIMER file
$current_step=$current_step+1;
print "[$current_step/$total_steps] Generate $gen_timer_file... ";
$GTIMER_CMD="$POETCMD -L$POETTG -pin=$gen_spec_file -pout=$gen_timer_file -pMT=$TIMERMT -pCacheKB=$TIMERCacheKB -pNREP=$TIMERNREP -pCacheFlushMethod=$TIMERCacheFlushMethod $POETTIMERPT 1>$RESULT 2>&1";
`$GTIMER_CMD`;
check($GTIMER_CMD);

# Generate Makefile
$current_step=$current_step+1;
print "[$current_step/$total_steps] Generate $gen_makefile... ";
open (GEN_MAKEFILE, ">$gen_makefile") || die ("Could not open file: $gen_xs_file");
print GEN_MAKEFILE "TARGETS=tester timer_without_opt timer_with_opt\n";
print GEN_MAKEFILE "CC=icc\n";
print GEN_MAKEFILE "CFLAGS=-g -O3 -fopenmp -fp-model precise\n";
print GEN_MAKEFILE "CFLAGS+=-I\$(HOME)/POET/trunk/include\n";
if ($HAS_AVX) {
  print GEN_MAKEFILE "CFLAGS+=-DINS_256BIT\n";
} elsif ($HAS_SSE3) {
  print GEN_MAKEFILE "CFLAGS+=-DSSE2 -DATL_SSE3\n";
} elsif ($HAS_SSE2) {
  print GEN_MAKEFILE "CFLAGS+=-DSSE2\n";
} elsif ($HAS_SSE) {
  print GEN_MAKEFILE "CFLAGS+=-DSSE\n";
} elsif ($HAS_3DNOW) {
  print GEN_MAKEFILE "CFLAGS+=-DTHREEDNOW\n";
}
if ($IS_X8664) {
  print GEN_MAKEFILE "CFLAGS+=-DATL_GAS_x8664\n";
}
print GEN_MAKEFILE "LDFLAGS=-lm\n\n";
print GEN_MAKEFILE "all:\$(TARGETS)\n\n";
print GEN_MAKEFILE "test:\n";
print GEN_MAKEFILE "\t\@make\n";
print GEN_MAKEFILE "\t\@echo \"\"\n";
print GEN_MAKEFILE "\t\@echo \"====================Tester====================\"\n";
print GEN_MAKEFILE "\t./tester\n";
print GEN_MAKEFILE "\t\@echo \"==============================================\"\n";
print GEN_MAKEFILE "\t\@echo \"\"\n";
print GEN_MAKEFILE "\t\@echo \"=====================Timer====================\"\n";
print GEN_MAKEFILE "\t\@echo \"------------------Before OPT-----------------\"\n";
print GEN_MAKEFILE "\t./timer_without_opt\n";
print GEN_MAKEFILE "\t\@echo \"---------------------------------------------\"\n";
print GEN_MAKEFILE "\t\@echo \"------------------After OPT------------------\"\n";
print GEN_MAKEFILE "\t./timer_with_opt\n";
print GEN_MAKEFILE "\t\@echo \"---------------------------------------------\"\n";
print GEN_MAKEFILE "\t\@echo \"==============================================\"\n";
print GEN_MAKEFILE "\t\@echo \"\"\n\n";
print GEN_MAKEFILE "tester: $tester_file_make $opt_c_file_make\n";
print GEN_MAKEFILE "\t\$(CC) \$(CFLAGS) -o tester $tester_file_make $opt_c_file_make \$(LDFLAGS)\n\n";
print GEN_MAKEFILE "timer_without_opt: $timer_file_make $c_file_make\n";
print GEN_MAKEFILE "\t\$(CC) \$(CFLAGS) -o timer_without_opt  $timer_file_make $c_file_make \$(LDFLAGS)\n\n";
print GEN_MAKEFILE "timer_with_opt: $timer_file_make $opt_c_file_make\n";
print GEN_MAKEFILE "\t\$(CC) \$(CFLAGS) -o timer_with_opt  $timer_file_make $opt_c_file_make \$(LDFLAGS)\n\n";
print GEN_MAKEFILE "clean:\n";
print GEN_MAKEFILE "\trm -rf \$(TARGETS)\n";
close (GEN_MAKEFILE);
print "Success\n\n";

print "Generation finished.\n\n";
print "Please cd ./$target_file and type \"make test\" to test your optimization. Good Luck!\n\n";
