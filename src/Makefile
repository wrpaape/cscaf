.PHONY: all clean

# relative directories
# ==============================================================================
ROOT_DIR = ..
SRC_DIR  = $(ROOT_DIR)/src
OBJ_DIR  = $(ROOT_DIR)/obj
LIB_DIR  = $(ROOT_DIR)/lib
TEST_DIR = $(ROOT_DIR)/tests


# user config
# ==============================================================================
CC      = gcc
CFLAGS  = -g -I$(SRC_DIR) -std=c99 -Wall -D__USE_FIXED_PROTOTYPES__
AR      = ar
ARFLAGS = rcs


# user targets
# ==============================================================================
# root/bin/cscaf
CSCAF      = cscaf
CSCAF_DIR  = $(SRC_DIR)
CSCAF_SRC  = $(addprefix $(CSCAF_DIR)/, $(addsuffix .c, $(CSCAF)))
CSCAF_HDR  = $(addprefix $(CSCAF_DIR)/, $(addsuffix .h, $(CSCAF)))
CSCAF_OBJ  = $(addprefix $(OBJ_DIR)/, 	$(addsuffix .o, $(CSCAF)))
CSCAF_BIN  = $(addprefix $(BIN_DIR)/, 	$(CSCAF))
CSCAF_ODEP = $(CSCAF_SRC) $(CSCAF_HDR)
CSCAF_BDEP = $(CSCAF_OBJ)


# target groups
# ==============================================================================
USER_ITEMS = CSCAF
ALL_ITEMS  = $(USER_ITEMS)

EXPAND_GROUP = $(foreach item, $(patsubst %, %_$1, $2), $($(item)))

ALL_OBJS    = $(call EXPAND_GROUP,OBJ,$(ALL_ITEMS))
ALL_BINS    = $(call EXPAND_GROUP,BIN,$(ALL_ITEMS))
ALL_TARGETS = $(ALL_OBJS) $(ALL_BINS)


# make targets
# ==============================================================================
all: $(ALL_TARGETS)

$(CSCAF_BIN): $(CSCAF_BDEP)
	$(CC) $(CFLAGS) -o $@ $^

$(CSCAF_OBJ): $(CSCAF_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(ALL_TARGETS)
