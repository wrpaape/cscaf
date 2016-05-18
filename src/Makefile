.PHONY: all clean


# environment config
# ==============================================================================
# USER_BIN           = ~/bin                = export binaries dest dir
# C_LIBRARY_HEADERS  = ~C_LIBRARIES/include = module mkdir (for header) location
# C_SHARED_LIBRARIES = ~C_LIBRARIES/shared  = export shared libraries dest dir
# C_STATIC_LIBRARIES = ~C_LIBRARIES/static  = export static libraries dest dir
# UNITY_SCRIPTS      = ~C_ROOT/unity/auto   = unity scripts folder


# utility config
# ==============================================================================
# utilities
CC    = gcc
AR    = ar
RUBY  = ruby
MKDIR = mkdir
CP    = cp
RM    = rm

# library dependencies
DEP_LIBS      = string_utils_static
TEST_DEP_LIBS = unity_shared

# flags
C_FLAGS      = -g -I$(HDR_DIR) -std=c99 -Wall -D__USE_FIXED_PROTOTYPES__
LD_FLAGS     = -L$(C_STATIC_LIBRARIES) -L$(C_SHARED_LIBRARIES) -Wl,-rpath,$(C_SHARED_LIBRARIES)
AR_FLAGS     = rcs
PIC_FLAG     = -fpic
SHARED_FLAG  = -shared
L_FLAGS	     = $(call MAP_LFLAGS,$(DEP_LIBS))
TEST_L_FLAGS = $(call MAP_LFLAGS,$(TEST_DEP_LIBS))
RM_FLAGS     = -rf

# unity test runner generator script
GENERATE_TEST_RUNNER = $(call PATH_JOIN,$(UNITY_SCRIPTS) generate_test_runner.rb)


# directory config
# ==============================================================================
# header files
HDR      = $(SRC)
# source files
SRC      = src
# main source files
MAIN_SRC = $(SRC)
# all generated object files
OBJ      = obj
# generated module binary files
BIN      = bin
# generated shared library files
SHARED   = shared
# generated static library files
STATIC   = static
# test source and generated test binary files
TEST     = test
# generated test_runner source files
TRNR_SRC = test_runners

# paths relative project root, 'ROOT_DIR'
ROOT_DIR      = ..
HDR_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(HDR))
SRC_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(SRC))
MAIN_SRC_DIR  = $(call PATH_JOIN,$(ROOT_DIR) $(MAIN_SRC))
TEST_SRC_DIR  = $(call PATH_JOIN,$(ROOT_DIR) $(TEST))
TRNR_SRC_DIR  = $(call PATH_JOIN,$(TEST_SRC_DIR) $(TRNR_SRC))
OBJ_DIR	      = $(call PATH_JOIN,$(ROOT_DIR) $(OBJ))
PIC_OBJ_DIR   = $(OBJ_DIR)
TEST_OBJ_DIR  = $(OBJ_DIR)
TRNR_OBJ_DIR  = $(OBJ_DIR)
BIN_DIR	      = $(call PATH_JOIN,$(ROOT_DIR) $(BIN))
TEST_BIN_DIR  = $(TEST_SRC_DIR)
SHARED_DIR    = $(call PATH_JOIN,$(ROOT_DIR) $(SHARED))
STATIC_DIR    = $(call PATH_JOIN,$(ROOT_DIR) $(STATIC))


# filename config
# ==============================================================================
LIB_PFX	 = lib
MAIN_SFX = _main
TEST_SFX = _test
TRNR_SFX = _test_runner

# prefixes
HDR_PFX       = $(EMPTY)
SRC_PFX       = $(EMPTY)
MAIN_SRC_PFX  = $(EMPTY)
TEST_SRC_PFX  = $(EMPTY)
TRNR_SRC_PFX  = $(EMPTY)
OBJ_PFX       = $(EMPTY)
PIC_OBJ_PFX   = pic_
TRNR_OBJ_PFX  = $(EMPTY)
TEST_OBJ_PFX  = $(EMPTY)
BIN_PFX	      = $(EMPTY)
TEST_BIN_PFX  = $(EMPTY)
SHARED_PFX    = $(LIB_PFX)
STATIC_PFX    = $(LIB_PFX)
MKDIR_HDR_PFX = $(EMPTY)

# suffixes (including extensions)
HDR_SFX       = .h
SRC_SFX       = .c
MAIN_SRC_SFX  = $(call CONCAT,$(MAIN_SFX) $(SRC_SFX))
TEST_SRC_SFX  = $(call CONCAT,$(TEST_SFX) $(SRC_SFX))
TRNR_SRC_SFX  = $(call CONCAT,$(TRNR_SFX) $(SRC_SFX))
OBJ_SFX       = .o
PIC_OBJ_SFX   = $(OBJ_SFX)
TEST_OBJ_SFX  = $(call CONCAT,$(TEST_SFX) $(OBJ_SFX))
TRNR_OBJ_SFX  = $(call CONCAT,$(TRNR_SFX) $(OBJ_SFX))
BIN_SFX	      = $(EMPTY)
TEST_BIN_SFX  = $(TEST_SFX)
SHARED_SFX    = $(call CONCAT,_ $(SHARED) .so)
STATIC_SFX    = $(call CONCAT,_ $(STATIC) .a)
MKDIR_HDR_SFX = $(EMPTY)


# functions
# ==============================================================================
# string operations
JOIN	   = $(subst $(SPACE),$2,$(strip $1))
CONCAT     = $(call JOIN,$1,$(EMPTY))
PATH_JOIN  = $(call JOIN,$1,$(PATH_DELIM))
VAR_JOIN   = $(call JOIN,$1,$(VAR_DELIM))
MAP_LFLAGS = $(foreach lib,$1,$(call CONCAT,-l $(lib)))

# variable generation, expansion
EXPAND_VAR   	= $($(call VAR_JOIN,$1))
EXPAND_DIR 	= $(call EXPAND_VAR,$1 DIR)
EXPAND_PFX 	= $(call EXPAND_VAR,$1 PFX)
EXPAND_SFX 	= $(call EXPAND_VAR,$1 SFX)
EXPAND_BASE	= $(call CONCAT,$(call EXPAND_PFX,$2) $1 $(call EXPAND_SFX,$2))
EXPAND_PATH	= $(call PATH_JOIN,$1 $(call EXPAND_BASE,$2,$3))
EXPAND_DIR_PATH	= $(call EXPAND_PATH,$(call EXPAND_DIR,$2),$1,$2)
EXPAND_MODULES  = $(call EXPAND_VAR,$1 MODULES)
EXPAND_TARGETS  = $(foreach module,$(call EXPAND_MODULES,$1),$(call EXPAND_VAR,$(module) $1))
EXPAND_DEP_LINE = $(call EXPAND_VAR,$1 $2): $(call EXPAND_VAR,$1 $2 DEP)
EXPAND_RECIPE	= $(call EXPAND_VAR,$1 RECIPE)
EXPAND_RULE 	= $(call EXPAND_DEP_LINE,$1,$2)$(CMD_SPACE)$(call EXPAND_RECIPE,$2)


# placeholders
# ==============================================================================
# make target types
TARGET_TYPES = TRNR_SRC OBJ PIC_OBJ TRNR_OBJ TEST_OBJ BIN TEST_BIN	\
	       SHARED STATIC MKDIR_HDR CP_HDR CP_BIN CP_SHARED		\
	       CP_STATIC

# list of all make targets
ALL_TARGETS  = $(foreach type,$(TARGET_TYPES),$(call EXPAND_TARGETS,$(type)))

# make recipes
TRNR_SRC_RECIPE	 = $(RUBY) $(GENERATE_TEST_RUNNER) $$< $$@
OBJ_RECIPE 	 = $(CC) $(C_FLAGS) -c -o $$@ $$<
PIC_OBJ_RECIPE   = $(OBJ_RECIPE) $(PIC_FLAG)
TRNR_OBJ_RECIPE  = $(OBJ_RECIPE)
TEST_OBJ_RECIPE  = $(OBJ_RECIPE)
BIN_RECIPE       = $(CC) $(C_FLAGS) -o $$@ $$^ $(LD_FLAGS) $(L_FLAGS)
TEST_BIN_RECIPE  = $(BIN_RECIPE) $(TEST_L_FLAGS)
STATIC_RECIPE 	 = $(AR) $(AR_FLAGS) $$@ $$^
SHARED_RECIPE 	 = $(BIN_RECIPE) $(SHARED_FLAG)
MKDIR_HDR_RECIPE = $(MKDIR) $$@
CP_HDR_RECIPE 	 = $(CP) $$< $$@
CP_BIN_RECIPE 	 = $(CP_HDR_RECIPE)
CP_SHARED_RECIPE = $(CP_HDR_RECIPE)
CP_STATIC_RECIPE = $(CP_HDR_RECIPE)

# misc
EMPTY =
SPACE = $(EMPTY) $(EMPTY)
TAB   = $(EMPTY)	$(EMPTY)
define NEWLINE


endef
CMD_SPACE  = $(NEWLINE)$(TAB)
VAR_DELIM  = _
PATH_DELIM = /


# cscaf config
# ==============================================================================
# module name
CSCAF = cscaf

# module source files
CSCAF_HDR      = $(call EXPAND_DIR_PATH,$(CSCAF),HDR)
CSCAF_SRC      = $(call EXPAND_DIR_PATH,$(CSCAF),SRC)
CSCAF_MAIN_SRC = $(call EXPAND_DIR_PATH,$(CSCAF),MAIN_SRC)
CSCAF_TEST_SRC = $(call EXPAND_DIR_PATH,$(CSCAF),TEST_SRC)

# module targets
CSCAF_TRNR_SRC  = $(call EXPAND_DIR_PATH,$(CSCAF),TRNR_SRC)
CSCAF_OBJ       = $(call EXPAND_DIR_PATH,$(CSCAF),OBJ)
CSCAF_PIC_OBJ   = $(call EXPAND_DIR_PATH,$(CSCAF),PIC_OBJ)
CSCAF_TRNR_OBJ  = $(call EXPAND_DIR_PATH,$(CSCAF),TRNR_OBJ)
CSCAF_TEST_OBJ  = $(call EXPAND_DIR_PATH,$(CSCAF),TEST_OBJ)
CSCAF_BIN       = $(call EXPAND_DIR_PATH,$(CSCAF),BIN)
CSCAF_TEST_BIN  = $(call EXPAND_DIR_PATH,$(CSCAF),TEST_BIN)
CSCAF_SHARED    = $(call EXPAND_DIR_PATH,$(CSCAF),SHARED)
CSCAF_STATIC    = $(call EXPAND_DIR_PATH,$(CSCAF),STATIC)
CSCAF_MKDIR_HDR = $(call EXPAND_PATH,$(C_LIBRARY_HEADERS),$(CSCAF),MKDIR_HDR)
CSCAF_CP_HDR    = $(call EXPAND_PATH,$(CSCAF_MKDIR_HDR),$(CSCAF),HDR)
CSCAF_CP_BIN    = $(call EXPAND_PATH,$(USER_BIN),$(CSCAF),BIN)
CSCAF_CP_SHARED = $(call EXPAND_PATH,$(C_SHARED_LIBRARIES),$(CSCAF),SHARED)
CSCAF_CP_STATIC = $(call EXPAND_PATH,$(C_STATIC_LIBRARIES),$(CSCAF),STATIC)

# module target dependencies
CSCAF_TRNR_SRC_DEP  = $(CSCAF_TEST_SRC)
CSCAF_OBJ_DEP       = $(CSCAF_SRC) $(CSCAF_HDR)
CSCAF_PIC_OBJ_DEP   = $(CSCAF_OBJ_DEP)
CSCAF_TRNR_OBJ_DEP  = $(CSCAF_TRNR_SRC)
CSCAF_TEST_OBJ_DEP  = $(CSCAF_TEST_SRC) $(CSCAF_OBJ_DEP)
CSCAF_BIN_DEP	    = $(CSCAF_MAIN_SRC) $(CSCAF_OBJ)
CSCAF_TEST_BIN_DEP  = $(CSCAF_TEST_OBJ) $(CSCAF_TRNR_OBJ) $(CSCAF_OBJ)
CSCAF_SHARED_DEP    = $(CSCAF_PIC_OBJ)
CSCAF_STATIC_DEP    = $(CSCAF_OBJ)
CSCAF_MKDIR_HDR_DEP = $(EMPTY)
CSCAF_CP_HDR_DEP    = $(CSCAF_HDR) $(CSCAF_MKDIR_HDR)
CSCAF_CP_BIN_DEP    = $(CSCAF_BIN)
CSCAF_CP_SHARED_DEP = $(CSCAF_SHARED)
CSCAF_CP_STATIC_DEP = $(CSCAF_STATIC)

# update target groups
TRNR_SRC_MODULES  += CSCAF
OBJ_MODULES       += CSCAF
# PIC_OBJ_MODULES   += CSCAF
TRNR_OBJ_MODULES  += CSCAF
TEST_OBJ_MODULES  += CSCAF
BIN_MODULES       += CSCAF
TEST_BIN_MODULES  += CSCAF
# SHARED_MODULES    += CSCAF
# STATIC_MODULES    += CSCAF
# MKDIR_HDR_MODULES += CSCAF
# CP_HDR_MODULES    += CSCAF
CP_BIN_MODULES    += CSCAF
# CP_SHARED_MODULES += CSCAF
# CP_STATIC_MODULES += CSCAF


# make rules
# ==============================================================================
# rules
all: $(ALL_TARGETS)

# unity test runners
# cscaf/test/test_runners/<module>_test_runner.c
$(foreach module,$(TRNR_SRC_MODULES),$(eval $(call EXPAND_RULE,$(module),TRNR_SRC)))

# objects
# cscaf/obj/<module>.o
$(foreach module,$(OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),OBJ)))

# "position independent code" objects
# cscaf/obj/pic_<module>.o
$(foreach module,$(PIC_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),PIC_OBJ)))

# unity test runner objects
# cscaf/obj/<module>_test_runner.o
$(foreach module,$(TRNR_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),TRNR_OBJ)))

# unity test objects
# cscaf/obj/<module>_test.o
$(foreach module,$(TEST_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),TEST_OBJ)))

# binary files
# cscaf/bin/<module>
$(foreach module,$(BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),BIN)))

# test binary files
# cscaf/test/<module>_test
$(foreach module,$(TEST_BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),TEST_BIN)))

# dynamic (shared) libraries
# cscaf/shared/lib<module>_shared.so
$(foreach module,$(SHARED_MODULES),$(eval $(call EXPAND_RULE,$(module),SHARED)))

# archive (static) libraries
# cscaf/shared/lib<module>_static.a
$(foreach module,$(STATIC_MODULES),$(eval $(call EXPAND_RULE,$(module),STATIC)))

# make directories at root of header file include path, 'C_LIBRARY_HEADERS'
# ~C_LIBRARY_HEADERS/<module>
$(foreach module,$(MKDIR_HDR_MODULES),$(eval $(call EXPAND_RULE,$(module),MKDIR_HDR)))

# copy header files to module include path
# ~C_LIBRARY_HEADERS/<module>/<module>.h
$(foreach module,$(CP_HDR_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_HDR)))

# copy binary files to 'USER_BIN'
# ~USER_BIN/<module>
$(foreach module,$(CP_BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_BIN)))

# copy shared library files to 'C_SHARED_LIBRARIES'
# ~C_SHARED_LIBRARIES/lib<module>_shared.so
$(foreach module,$(CP_SHARED_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_SHARED)))

# copy static library files to 'C_STATIC_LIBRARIES'
# ~C_STATIC_LIBRARIES/lib<module>_static.a
$(foreach module,$(CP_STATIC_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_STATIC)))

clean:
	$(RM) $(RM_FLAGS) $(ALL_TARGETS)
