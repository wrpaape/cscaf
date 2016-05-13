.PHONY: all copy clean

SRCDIR = src
MFLAGS = -j5 LAST=550

all copy clean:
	$(MAKE) $(MFLAGS) -C $(SRCDIR) $@
