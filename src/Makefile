include $(MAKEFILE_SCAFFOLD)

LD_FLAGS += -lstring_utils_static

define RULES
$(call USER_BINARY,cscaf)
$(call TEST_BINARY,cscaf)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
