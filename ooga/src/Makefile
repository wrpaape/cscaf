.PHONY: all clean

# relative directories
# ==============================================================================
ROOT_DIR = ..
SRC_DIR  = $(ROOT_DIR)/src
OBJ_DIR  = $(ROOT_DIR)/obj
BIN_DIR  = $(ROOT_DIR)/bin
TEST_DIR = $(ROOT_DIR)/test
TRNR_DIR = $(TEST_DIR)/test_runners


# user config
# ==============================================================================
CC          = gcc
CFLAGS      = -g -I$(SRC_DIR) -std=c99 -Wall -D__USE_FIXED_PROTOTYPES__
AR          = ar
ARFLAGS     = rcs
SRC_LIBS    =
TEST_LIBS   = unity
SRC_LFLAGS  = $(addprefix -l, $(SRC_LIBS))
TEST_LFLAGS = $(addprefix -l, $(TEST_LIBS))
TRNR_SCRIPT = $(HOME)/my_projects/c/unity/auto/generate_test_runner.rb

# user targets
# ==============================================================================
# root/bin/ooga
OOGA      = ooga
OOGA_DIR  = $(SRC_DIR)
OOGA_SRC  = $(addprefix $(OOGA_DIR)/, $(addsuffix .c, $(OOGA)))
OOGA_HDR  = $(addprefix $(OOGA_DIR)/, $(addsuffix .h, $(OOGA)))
OOGA_OBJ  = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(OOGA)))
OOGA_BIN  = $(addprefix $(BIN_DIR)/, $(OOGA))
OOGA_ODEP = $(OOGA_SRC) $(OOGA_HDR)
OOGA_BDEP = $(OOGA_OBJ)

# root/test/ooga_test
OOGA_TEST      = $(addsuffix _test, $(OOGA))
OOGA_TRNR      = $(addsuffix _runner, $(OOGA_TEST))
OOGA_TEST_DIR  = $(TEST_DIR)
OOGA_TEST_SRC  = $(addprefix $(OOGA_TEST_DIR)/, $(addsuffix .c, $(OOGA_TEST)))
OOGA_TRNR_SRC  = $(addprefix $(TRNR_DIR)/, $(addsuffix .c, $(OOGA_TRNR)))
OOGA_TEST_OBJ  = $(addprefix $(OBJ_DIR)/,  $(addsuffix .o, $(OOGA_TEST)))
OOGA_TRNR_OBJ  = $(addprefix $(OBJ_DIR)/,  $(addsuffix .o, $(OOGA_TRNR)))
OOGA_TEST_BIN  = $(addprefix $(TEST_DIR)/, $(OOGA_TEST))
OOGA_TEST_ODEP = $(OOGA_TEST_SRC)
OOGA_TRNR_ODEP = $(OOGA_TRNR_SRC)
OOGA_TEST_BDEP = $(OOGA_TEST_OBJ) $(OOGA_TRNR_OBJ)


# target groups
# ==============================================================================
EXPAND_GROUP  = $(foreach item, $(patsubst %, %_$1, $2), $($(item)))

ITEMS       = OOGA
SRC_OBJS    = $(call EXPAND_GROUP,OBJ,$(ITEMS))
SRC_BINS    = $(call EXPAND_GROUP,BIN,$(ITEMS))
TRNR_SRCS   = $(call EXPAND_GROUP,TRNR_SRC,$(ITEMS))
TRNR_OBJS   = $(call EXPAND_GROUP,TRNR_OBJ,$(ITEMS))
TEST_OBJS   = $(call EXPAND_GROUP,TEST_OBJ,$(ITEMS))
TEST_BINS   = $(call EXPAND_GROUP,TEST_BIN,$(ITEMS))
ALL_TARGETS = $(SRC_OBJS) $(SRC_BINS) $(TRNR_SRCS) $(TRNR_OBJS) $(TEST_OBJS) $(TEST_BINS)


# make targets
# ==============================================================================
all: $(ALL_TARGETS)


# root/obj/ooga.o
$(OOGA_OBJ): $(OOGA_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

# root/bin/ooga
$(OOGA_BIN): $(OOGA_BDEP)
	$(CC) $(CFLAGS) $(SRC_LFLAGS) -o $@ $^


# root/test/test_runners/ooga_test_runner.c
$(OOGA_TRNR_SRC):
	ruby $(TRNR_SCRIPT) $(OOGA_TEST_SRC) $(OOGA_TRNR_SRC)

# root/obj/ooga_test_runner.o
$(OOGA_TRNR_OBJ): $(OOGA_TRNR_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

# root/obj/ooga_test.o
$(OOGA_TEST_OBJ): $(OOGA_TEST_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

# root/test/ooga_test
$(OOGA_TEST_BIN): $(OOGA_TEST_BDEP)
	$(CC) $(CFLAGS) $(SRC_LFLAGS) $(TEST_LFLAGS) -o $@ $^


clean:
	$(RM) $(ALL_TARGETS)