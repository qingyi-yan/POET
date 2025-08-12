########################################################################
# POET parameters
########################################################################
POET_HOME:=../../../POET
POET_LIB:=$(POET_HOME)/lib
POET:=$(POET_HOME)/src/pcg
TEST_DIR:=$(POET_HOME)/test/analyzeConnectivity
TEST_FILE:=$(TEST_DIR)/linkedlist.h
DEBUG_FLAG:=

test:
	$(POET) $(DEBUG_FLAG) -L$(POET_LIB) -pinputFile=$(TEST_FILE) test0.pt
