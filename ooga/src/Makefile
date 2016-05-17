
.PHONY: all clean


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
DEP_LIBS      =
TEST_DEP_LIBS = unity

# flags
CFLAGS      = -g -I$(HDR_DIR) -std=c99 -Wall -D__USE_FIXED_PROTOTYPES__
ARFLAGS     = rcs
PIC_FLAG    = -fpic
SHARED_FLAG = -shared
LFLAGS      = $(call MAP_LFLAGS,$(DEP_LIBS))
TEST_LFLAGS = $(call MAP_LFLAGS,$(TEST_DEP_LIBS))
RM_FLAGS    = -rf

# unity test runner generator script
GEN_TRNR_BASE = generate_test_runner.rb
GEN_TRNR_DIR  = $(call PATH_JOIN,$(HOME) my_projects c unity auto)
GEN_TRNR_ABS  = $(call PATH_JOIN,$(GEN_TRNR_DIR) $(GEN_TRNR_BASE))


# directory config
# ==============================================================================
# source files
SRC    = src
# header files
HDR    = $(SRC)
# all built object files
OBJ    = obj
# built module binary files
BIN    = bin
# built shared library files
SHARED = shared
# built static library files
STATIC = static
# test source and built test binary files
TEST   = test
# built test_runner source files
TRNR   = test_runners

# paths relative project root, $(ROOT_DIR)
ROOT_DIR      = ..
SRC_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(SRC))
HDR_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(HDR))
TEST_SRC_DIR  = $(call PATH_JOIN,$(ROOT_DIR) $(TEST))
TRNR_SRC_DIR  = $(call PATH_JOIN,$(TEST_SRC_DIR) $(TRNR))
OBJ_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(OBJ))
PIC_OBJ_DIR   = $(OBJ_DIR)
TEST_OBJ_DIR  = $(OBJ_DIR)
TRNR_OBJ_DIR  = $(OBJ_DIR)
BIN_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(BIN))
TEST_BIN_DIR  = $(TEST_SRC_DIR)
SHARED_DIR    = $(call PATH_JOIN,$(ROOT_DIR) $(SHARED))
STATIC_DIR    = $(call PATH_JOIN,$(ROOT_DIR) $(STATIC))


# filename config
# ==============================================================================
LIB_PFX  = lib
TEST_SFX = _test
TRNR_SFX = _test_runner

# prefixes
SRC_PFX       = $(EMPTY)
HDR_PFX       = $(EMPTY)
TEST_SRC_PFX  = $(EMPTY)
TRNR_SRC_PFX  = $(EMPTY)
OBJ_PFX       = $(EMPTY)
PIC_OBJ_PFX   = pic_
TRNR_OBJ_PFX  = $(EMPTY)
TEST_OBJ_PFX  = $(EMPTY)
BIN_PFX       = $(EMPTY)
TEST_BIN_PFX  = $(EMPTY)
SHARED_PFX    = $(LIB_PFX)
STATIC_PFX    = $(LIB_PFX)
MKDIR_HDR_PFX = $(EMPTY)
CP_BIN_PFX    = $(BIN_PFX)
CP_HDR_PFX    = $(HDR_PFX)

# suffixes (including extensions)
SRC_SFX       = .c
HDR_SFX       = .h
TEST_SRC_SFX  = $(call CONCAT,$(TEST_SFX) $(SRC_SFX))
TRNR_SRC_SFX  = $(call CONCAT,$(TRNR_SFX) $(SRC_SFX))
OBJ_SFX       = .o
PIC_OBJ_SFX   = $(OBJ_SFX)
TEST_OBJ_SFX  = $(call CONCAT,$(TEST_SFX) $(OBJ_SFX))
TRNR_OBJ_SFX  = $(call CONCAT,$(TRNR_SFX) $(OBJ_SFX))
BIN_SFX       = $(EMPTY)
TEST_BIN_SFX  = $(TEST_SFX)
SHARED_SFX    = $(call CONCAT,_ $(SHARED) .so)
STATIC_SFX    = $(call CONCAT,_ $(STATIC) .a)
MKDIR_HDR_SFX = $(EMPTY)
CP_BIN_SFX    = $(BIN_SFX)
CP_HDR_SFX    = $(HDR_SFX)


# functions
# ==============================================================================
# string operations
JOIN       = $(subst $(SPACE),$2,$(strip $1))
CONCAT     = $(call JOIN,$1,$(EMPTY))
PATH_JOIN  = $(call JOIN,$1,$(PATH_DELIM))
VAR_JOIN   = $(call JOIN,$1,$(VAR_DELIM))
MAP_LFLAGS = $(foreach lib,$1,$(call CONCAT,-l $(lib)))

# variable generation, expansion
EXPAND_VAR      = $($(call VAR_JOIN,$1))
EXPAND_DIR      = $(call EXPAND_VAR,$1 DIR)
EXPAND_PFX      = $(call EXPAND_VAR,$1 PFX)
EXPAND_SFX      = $(call EXPAND_VAR,$1 SFX)
EXPAND_BASE     = $(call CONCAT,$(call EXPAND_PFX,$2) $1 $(call EXPAND_SFX,$2))
EXPAND_PATH     = $(call PATH_JOIN,$1 $(call EXPAND_BASE,$2,$3))
EXPAND_DIR_PATH = $(call EXPAND_PATH,$(call EXPAND_DIR,$2),$1,$2)
EXPAND_MODULES  = $(call EXPAND_VAR,$1 MODULES)
EXPAND_TARGETS  = $(foreach module,$(call EXPAND_MODULES,$1),$(call EXPAND_VAR,$(module) $1))
EXPAND_DEP_LINE = $(call EXPAND_VAR,$1 $2): $(call EXPAND_VAR,$1 $2 DEP)
EXPAND_RECIPE   = $(call EXPAND_VAR,$1 RECIPE)
EXPAND_RULE     = $(call EXPAND_DEP_LINE,$1,$2)$(CMD_SPACE)$(call EXPAND_RECIPE,$2)


# placeholders
# ==============================================================================
# list of all make targets
TARGET_TYPES = TRNR_SRC OBJ PIC_OBJ TRNR_OBJ TEST_OBJ BIN TEST_BIN \
               SHARED STATIC MKDIR_HDR CP_HDR CP_BIN
ALL_TARGETS  = $(foreach type,$(TARGET_TYPES),$(call EXPAND_TARGETS,$(type)))

# make recipes
TRNR_SRC_RECIPE  = $(RUBY) $(GEN_TRNR_ABS) $$< $$@
OBJ_RECIPE       = $(CC) $(CFLAGS) -c -o $$@ $$< $(LFLAGS)
PIC_OBJ_RECIPE   = $(OBJ_RECIPE) $(PIC_FLAG)
TRNR_OBJ_RECIPE  = $(OBJ_RECIPE)
TEST_OBJ_RECIPE  = $(OBJ_RECIPE)
BIN_RECIPE       = $(CC) $(CFLAGS) -o $$@ $$^ $(LFLAGS)
TEST_BIN_RECIPE  = $(BIN_RECIPE) $(TEST_LFLAGS)
STATIC_RECIPE    = $(AR) $(ARFLAGS) $$@ $$^
SHARED_RECIPE    = $(BIN_RECIPE) $(SHARED_FLAG)
MKDIR_HDR_RECIPE = $(MKDIR) $$@
CP_HDR_RECIPE    = $(CP_BIN_RECIPE)
CP_BIN_RECIPE    = $(CP) $$< $$@

# misc
EMPTY =
SPACE = $(EMPTY) $(EMPTY)
TAB   = $(EMPTY)	$(EMPTY)
define NEWLINE


endef
CMD_SPACE  = $(NEWLINE)$(TAB)
VAR_DELIM  = _
PATH_DELIM = /


# ooga config
# ==============================================================================
# module name
OOGA = ooga

# source files
OOGA_SRC      = $(call EXPAND_DIR_PATH,$(OOGA),SRC)
OOGA_HDR      = $(call EXPAND_DIR_PATH,$(OOGA),HDR)
OOGA_TEST_SRC = $(call EXPAND_DIR_PATH,$(OOGA),TEST_SRC)

# module targets
OOGA_TRNR_SRC  = $(call EXPAND_DIR_PATH,$(OOGA),TRNR_SRC)
OOGA_OBJ       = $(call EXPAND_DIR_PATH,$(OOGA),OBJ)
OOGA_PIC_OBJ   = $(call EXPAND_DIR_PATH,$(OOGA),PIC_OBJ)
OOGA_TRNR_OBJ  = $(call EXPAND_DIR_PATH,$(OOGA),TRNR_OBJ)
OOGA_TEST_OBJ  = $(call EXPAND_DIR_PATH,$(OOGA),TEST_OBJ)
OOGA_BIN       = $(call EXPAND_DIR_PATH,$(OOGA),BIN)
OOGA_TEST_BIN  = $(call EXPAND_DIR_PATH,$(OOGA),TEST_BIN)
OOGA_SHARED    = $(call EXPAND_DIR_PATH,$(OOGA),SHARED)
OOGA_STATIC    = $(call EXPAND_DIR_PATH,$(OOGA),STATIC)
OOGA_MKDIR_HDR = $(call EXPAND_PATH,$(C_LIBRARY_HEADERS),$(OOGA),MKDIR_HDR)
OOGA_CP_HDR    = $(call EXPAND_PATH,$(OOGA_MKDIR_HDR),$(OOGA),HDR)
OOGA_CP_BIN    = $(call EXPAND_PATH,$(USER_BIN),$(OOGA),BIN)


# module target dependencies
OOGA_TRNR_SRC_DEP  = $(OOGA_TEST_SRC)
OOGA_OBJ_DEP       = $(OOGA_SRC) $(OOGA_HDR)
OOGA_PIC_OBJ_DEP   = $(OOGA_OBJ_DEP)
OOGA_TRNR_OBJ_DEP  = $(OOGA_TRNR_SRC)
OOGA_TEST_OBJ_DEP  = $(OOGA_TEST_SRC) $(OOGA_OBJ_DEP)
OOGA_BIN_DEP       = $(OOGA_OBJ)
OOGA_TEST_BIN_DEP  = $(OOGA_TEST_OBJ) $(OOGA_TRNR_OBJ)
OOGA_SHARED_DEP    = $(OOGA_PIC_OBJ)
OOGA_STATIC_DEP    = $(OOGA_OBJ)
OOGA_MKDIR_HDR_DEP = $(EMPTY)
OOGA_CP_HDR_DEP    = $(OOGA_HDR) $(OOGA_MKDIR_HDR)
OOGA_CP_BIN_DEP    = $(OOGA_BIN)

# update target groups
TRNR_SRC_MODULES  += OOGA
OBJ_MODULES       += OOGA
PIC_OBJ_MODULES   += OOGA
TRNR_OBJ_MODULES  += OOGA
TEST_OBJ_MODULES  += OOGA
BIN_MODULES       += OOGA
TEST_BIN_MODULES  += OOGA
SHARED_MODULES    += OOGA
STATIC_MODULES    += OOGA
MKDIR_HDR_MODULES += OOGA
CP_HDR_MODULES    += OOGA
CP_BIN_MODULES    += OOGA


# make commands
# ==============================================================================
# rules
all: $(ALL_TARGETS)

# unity test runners
# ooga/test/test_runners/<module>_test_runner.c
$(foreach module,$(TRNR_SRC_MODULES),$(eval $(call EXPAND_RULE,$(module),TRNR_SRC)))

# objects
# ooga/obj/<module>.o
$(foreach module,$(OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),OBJ)))

# "position independent code" objects
# ooga/obj/pic_<module>.o
$(foreach module,$(PIC_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),PIC_OBJ)))

# unity test runner objects
# ooga/obj/<module>_test_runner.o
$(foreach module,$(TRNR_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),TRNR_OBJ)))

# unity test objects
# ooga/obj/<module>_test.o
$(foreach module,$(TEST_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),TEST_OBJ)))

# binary files
# ooga/bin/<module>
$(foreach module,$(BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),BIN)))

# test binary files
# ooga/test/<module>_test
$(foreach module,$(TEST_BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),TEST_BIN)))

# dynamic (shared) libraries
# ooga/shared/lib<module>_shared.so
$(foreach module,$(SHARED_MODULES),$(eval $(call EXPAND_RULE,$(module),SHARED)))

# archive (static) libraries
# ooga/shared/lib<module>_static.a
$(foreach module,$(STATIC_MODULES),$(eval $(call EXPAND_RULE,$(module),STATIC)))

# make directories at root of header file include path  ~C_LIBRARY_HEADERS
# ~C_LIBRARY_HEADERS/<module>
$(foreach module,$(CP_HDR_MODULES),$(eval $(call EXPAND_RULE,$(module),MKDIR_HDR)))

# copy header files to ~C_LIBRARY_HEADERS/<module>
# ~C_LIBRARY_HEADERS/<module>/<module>.h
$(foreach module,$(CP_HDR_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_HDR)))

# copy binary files to ~/bin
# ~/bin/<module>
$(foreach module,$(CP_BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_BIN)))

clean:
	$(RM) $(RM_FLAGS) $(ALL_TARGETS)