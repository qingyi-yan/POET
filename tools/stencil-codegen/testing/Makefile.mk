include gmtt.mk

PCG=pcg
PCGFLAGS=-L..
DBG=

CC=gcc
CFLAGS=-O3
LDFLAGS:=-lm -lstencil_config -lacc_timer -lbenchtool
LDPARFLAGS:=-fopenmp
REF_TEST_DIR=#!date +%Y_%m_%d:%H_%M
PLUTO_HOME=/home/brandon/opt_devel/pluto/target
PLC=$(PLUTO_HOME)/bin/polycc
PLCFLAGS=--pet
PLCPARFLAGS=--parallel
PLCTILEFLAGS=--noparallel --tile
#PLCTILEFLAGS=--tile
PLCALLFLAGS=--parallel --tile
PLCFULLDIAMONDFLAGS=--noparallel --full-diamond-tile
PLCFULLDIAMONDPARFLAGS=--full-diamond-tile $(PLCPARFLAGS)
PLCNODIAMONDFLAGS=--noparallel --nodiamond-tile --tile 
PLCNODIAMONDPARFLAGS=--nodiamond-tile --tile $(PLCPARFLAGS)
PLCRECTSPATIALPARFLAGS=$(PLCNODIAMONDPARFLAGS)
PLCRECTSPATIALL2PARFLAGS=$(PLCRECTSPATIALPARFLAGS) --second-level-tile
PLCTWOTILEFLAGS=--noparallel --second-level-tile
PLCTWOTILEPARFLAGS=--second-level-tile $(PLCPARFLAGS)
PLCRECTL2PARFLAGS=$(PLCNODIAMONDPARFLAGS) --second-level-tile
PLCFULLDL2PARFLAGS=$(PLCFULLDIAMONDPARFLAGS) --second-level-tile 
POCHOIRFLAGS=0O3 -DNDEBUG -funroll-loops -xHOST -fno-alias -fno-fnalias -fp-model precise -std=C++0x

PLCNONEFLAGS:=--nointratileopt --noparallel --notile --nodiamond-tile

EXT_ORIG=orig
EXT_TILE=tile
EXT_PAR=par
EXT_TWOTILE=twotile
EXT_TWOTILEPAR=twotilepar
EXT_FULLDIAMOND=fulldiamond
EXT_FULLDIAMONDPAR=fulldiamondpar
EXT_NODIAMOND=nodiamond
EXT_NODIAMONDPAR=nodiamondpar
EXT_RECTSPATIALPAR=rectspatialpar
EXT_RECTSPATIALL2PAR=rectspatiall2par
EXT_RECTL2PAR=rectl2par
EXT_FULLDL2PAR=fulldl2par
EXT_ALLOPT=all
EXT_POCHOIR=pochoir

EQ_HEAT:=heat
EQ_WAVE:=wave
EQ_LAPLA:=lapla
EQ_LAPLAINV:=laplainv
EQ_ALLENCAHN:=allencahn
EQ_ISO:=iso
EQ_ANISO:=aniso
EQ_ACINV:=acinv
EQ_WAVEMOD:=wavemod
EQ_GENERIC:=generic

TEST_MODE=0
RUN_ID=1

OUTPUT_DIR=target
STAGE_DIR=stage
STAGE_PATH=$(OUTPUT_DIR)/$(STAGE_DIR)
TEST_DIR=test_results
TEST_PATH=$(OUTPUT_DIR)/$(TEST_DIR)/$(CC)/$(EQ)/$(OPT)/$(RUN_ID)

#SRC=$(EQ)$(D)d_$(OA)oa_exp
SRC=out

###################################
#### Compiler Parameters ##########
###################################
ifeq ($(CC),gcc)
CFLAGS:=$(CFLAGS) -march=native -mtune=native
#CFLAGS:=$(CFLAGS) -march=native -mtune=native -fopt-info-vec-optimized -mavx -msse2
endif

ifeq ($(CC),icc)
CFLAGS:=$(CFLAGS) -xHost -ansi-alias -ipo -fp-model precise
LDPARFLAGS=-qopenmp
endif

###################################
#### Dimensionality Parameters ####
###################################
T_MAX=250
D1_X = 3200000
D2_X = 5600
D2_Y = 5600
D3_X = 315 
D3_Y = 315
D3_Z = 315

ifeq ($(D), 1)
#DIM_PARAMS=16000 0 0 $(T_MAX)
DIM_PARAMS=$(D1_X) 0 0 $(T_MAX)
#DIM_PARAMS=6400000 0 0 $(T_MAX)
endif

ifeq ($(D), 2)
#DIM_PARAMS=100 100 0 $(T_MAX)
DIM_PARAMS=$(D2_X) $(D2_Y) 0 $(T_MAX)
#DIM_PARAMS=8000 8000 0 $(T_MAX)
endif

ifeq ($(D), 3)
#DIM_PARAMS=20 20 20 $(T_MAX)
DIM_PARAMS=$(D3_X) $(D3_Y) $(D3_Z) $(T_MAX)
#DIM_PARAMS=400 400 400 $(T_MAX)
endif

###################################
#### Tiling Overrides  ############
###################################
TILE_INPUT:= tile.$(D)d
ifeq ($(EQ),$(EQ_WAVE))
TILE_INPUT:=$(TILE_INPUT).2to
endif
ifeq ($(OPT),$(EXT_RECTSPATIALPAR))
TILE_INPUT:=$(TILE_INPUT).spatial
endif
ifeq ($(OPT),$(EXT_RECTSPATIALL2PAR))
TILE_INPUT:=$(TILE_INPUT).spatial
endif
TILE_INPUT:=$(TILE_INPUT).sizes


# rule names and file names cause conflict in target names, so we don't want any implicit rules
.SUFFIXES:

prep_parallel:
	$(eval LDFLAGS :=$(LDFLAGS) $(LDPARFLAGS))

#prep_tile: tile.$(D)d.sizes
prep_tile: $(TILE_INPUT)
	cp $(TILE_INPUT) tile.sizes

untile: 
	rm tile.sizes

prepare:
	mkdir -p $(STAGE_PATH)

clean:
	rm -rf $(OUTPUT_DIR)


$(SRC).$(EXT_ORIG).c: $(SRC).c prepare
	cp $(SRC).c $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_TILE).c: $(SRC).c prepare prep_tile
	$(PLC) $(SRC).c $(PLCTILEFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_NODIAMOND).c: $(SRC).c prepare prep_tile
	$(PLC) $(SRC).c $(PLCNODIAMONDFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_NODIAMONDPAR).c: $(SRC).c prepare prep_tile prep_parallel
	$(PLC) $(SRC).c $(PLCNODIAMONDPARFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_FULLDIAMOND).c: $(SRC).c prepare prep_tile
	$(PLC) $(SRC).c $(PLCFULLDIAMONDFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c
	
$(SRC).$(EXT_FULLDIAMONDPAR).c: $(SRC).c prepare prep_tile prep_parallel
	$(PLC) $(SRC).c $(PLCFULLDIAMONDPARFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_TWOTILE).c: $(SRC).c prepare prep_tile
	$(PLC) $(SRC).c $(PLCTWOTILEFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_TWOTILEPAR).c: $(SRC).c prepare prep_tile prep_parallel
	$(PLC) $(SRC).c $(PLCTWOTILEPARFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_RECTL2PAR).c: $(SRC).c prepare prep_tile prep_parallel
	$(PLC) $(SRC).c $(PLCRECTL2PARFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_FULLDL2PAR).c: $(SRC).c prepare prep_tile prep_parallel
	$(PLC) $(SRC).c $(PLCFULLDL2PARFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_RECTSPATIALPAR).c: $(SRC).c prepare untile prep_parallel
	$(PLC) $(SRC).c $(PLCRECTSPATIALPARFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_RECTSPATIALL2PAR).c: $(SRC).c prepare prep_tile prep_parallel
	$(PLC) $(SRC).c $(PLCRECTSPATIALL2PARFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_PAR).c: $(SRC).c prepare prep_parallel
	$(PLC) $(SRC).c $(PLCPARFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_ALLOPT).c: $(SRC).c prepare prep_parallel prep_tile
	$(PLC) $(SRC).c $(PLCALLFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

$(SRC).$(EXT_POCHOIR).c: $(SRC).cpp prepare
	$(PLC) $(SRC).c $(PLCALLFLAGS) $(PLCFLAGS) -o $(STAGE_PATH)/$(SRC).$(OPT).c

EQID=10
EQ=generic
ifeq ($(EQ), $(EQ_HEAT))
EQID=1
endif
ifeq ($(EQ), $(EQ_WAVE))
EQID=2
endif
ifeq ($(EQ), $(EQ_ALLENCAHN))
EQID=3
endif
ifeq ($(EQ), $(EQ_ISO))
EQID=4
endif
ifeq ($(EQ), $(EQ_ACINV))
EQID=5
endif
ifeq ($(EQ), $(EQ_WAVEMOD))
EQID=6
endif
ifeq ($(EQ), $(EQ_LAPLA))
EQID=7
endif
ifeq ($(EQ), $(EQ_LAPLAINV))
EQID=8
endif
ifeq ($(EQ), $(EQ_ANISO))
EQID=9
endif
ifeq ($(EQ), $(EQ_GENERIC))
EQID=10
endif

OPTID=0
ifeq ($(OPT), $(EXT_ORIG))
OPTID=1
endif
ifeq ($(OPT), $(EXT_NODIAMOND))
OPTID=2
endif
ifeq ($(OPT), $(EXT_TILE))
OPTID=3
endif
ifeq ($(OPT), $(EXT_FULLDIAMOND))
OPTID=4
endif
ifeq ($(OPT), $(EXT_PAR))
OPTID=5
endif
ifeq ($(OPT), $(EXT_NODIAMONDPAR))
OPTID=8
endif
ifeq ($(OPT), $(EXT_ALLOPT))
OPTID=9
endif
ifeq ($(OPT), $(EXT_FULLDIAMONDPAR))
OPTID=10
endif
ifeq ($(OPT), $(EXT_POCHOIR))
OPTID=11
endif

build:
	$(PCG) $(PCGFLAGS) $(DBG) -pdim=$(dim) -ptime=$(T_MAX) -poa=$(oa) -pto=$(to) -pdiv=$(div) -pmi=$(mi) -pcoeftype=$(coeftype) ../stencil-gen.pt > out.c

REPORT_PATH=stencilbench.csv
N_THREADS=1
opt: export BENCHTOOL_EQID=$(EQID)
opt: export BENCHTOOL_RUNID=$(RUN_ID)
opt: export BENCHTOOL_OPTID=$(OPTID)
opt: export BENCHTOOL_FILE=$(REPORT_PATH)
opt: export BENCHTOOL_NTHREADS=$(N_THREADS)
opt: export OMP_NUM_THREADS=$(N_THREADS)

#opt: $(SRC).c prepare $(SRC).$(OPT).c build
opt: prepare build $(SRC).$(OPT).c
	@echo "Working {dim:${dim}, oa:${oa}, to:${to}, ct:${coeftype}, div:${div}, mi:${mi}, nt:${N_THREADS}, rid:${RUN_ID}}"
	$(eval EXE_OUT=x$(SRC)_$(CC)_$(OPT))
	$(CC) $(CFLAGS) $(STAGE_PATH)/$(SRC).$(OPT).c -o $(OUTPUT_DIR)/$(EXE_OUT) $(LDFLAGS)
	@if [ "$(TEST_MODE)" = "1" ]; then\
		echo "INFO: Running: ./$(OUTPUT_DIR)/$(EXE_OUT) $(DIM_PARAMS) > $(TEST_PATH)/$(EXE_OUT);"; \
		mkdir -p $(TEST_PATH); \
		./$(OUTPUT_DIR)/$(EXE_OUT) $(DIM_PARAMS) > $(TEST_PATH)/$(EXE_OUT); \
	fi

stencil_id="generic"

generic: 
	@$(MAKE) opt

dim_sweep:
	@$(MAKE) dim=1 D=1 generic 
	@$(MAKE) dim=2 D=2 generic 
	@$(MAKE) dim=3 D=3 generic 
	
oa_sweep:
	@$(MAKE) oa=2 dim_sweep 
	@$(MAKE) oa=4 dim_sweep 
	
to_sweep:
	@$(MAKE) to=0 oa_sweep 
	@$(MAKE) to=1 oa_sweep 
	@$(MAKE) to=2 oa_sweep 

coef_sweep:
	@$(MAKE) coeftype=0 to_sweep
	@$(MAKE) coeftype=1 to_sweep

div_sweep:
	@$(MAKE) div=0 mi=0 coef_sweep
	@$(MAKE) div=1 mi=0 coef_sweep
	@$(MAKE) div=1 mi=1 coef_sweep
	@$(MAKE) div=4 mi=0 coef_sweep
	@$(MAKE) div=4 mi=1 coef_sweep

opt_sweep:
	@$(MAKE) CC=gcc OPT=fulldiamondpar div_sweep
	@$(MAKE) CC=gcc OPT=nodiamondpar div_sweep
	@$(MAKE) CC=gcc OPT=all div_sweep
	@$(MAKE) CC=gcc OPT=par div_sweep
#	@$(MAKE) CC=gcc OPT=orig div_sweep
#	@$(MAKE) CC=gcc OPT=tile div_sweep
#	@$(MAKE) CC=gcc OPT=nodiamond div_sweep
#	@$(MAKE) CC=gcc OPT=all div_sweep
#	@$(MAKE) CC=gcc OPT=nodiamondpar div_sweep

thread_sweep:
	@$(MAKE) N_THREADS=2 opt_sweep 
	@$(MAKE) N_THREADS=4 opt_sweep 
	@$(MAKE) N_THREADS=8 opt_sweep 
	@$(MAKE) N_THREADS=16 opt_sweep
#	@$(MAKE) N_THREADS=1 opt_sweep 
#	@$(MAKE) N_THREADS=4 opt_sweep 
#	@$(MAKE) N_THREADS=8 opt_sweep 
#	@$(MAKE) N_THREADS=16 opt_sweep
#	@$(MAKE) N_THREADS=1 opt_sweep 
#	@$(MAKE) N_THREADS=2 opt_sweep 
#	@$(MAKE) N_THREADS=4 opt_sweep 
#	@$(MAKE) N_THREADS=8 opt_sweep 
#	@$(MAKE) N_THREADS=16 opt_sweep

runid_sweep:
	@$(MAKE) RUN_ID=1 thread_sweep 
	@$(MAKE) RUN_ID=2 thread_sweep
#	@$(MAKE) RUN_ID=3 thread_sweep
#	@$(MAKE) RUN_ID=4 thread_sweep

input_params_sweep:
	@$(MAKE) T_MAX=16 runid_sweep
	@$(MAKE) T_MAX=32 runid_sweep
	@$(MAKE) T_MAX=64 runid_sweep
	@$(MAKE) D1_X=6400000 D2_X=8000 D2_Y=8000 D3_X=400 D3_Y=400 D3_Z=400 T_MAX=16 runid_sweep

do_test:
	@$(MAKE) TEST_MODE=1 input_params_sweep
