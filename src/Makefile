PRODUCT := obdh-controller
BUILDDIR := ../build
TESTDIR := ../test
TESTOBJDIR := $(BUILDDIR)/test

HDRS := $(wildcard ./*.h)
SRCS := $(wildcard ./*.c)
BINARY := $(BUILDDIR)/$(PRODUCT)
OBJS := $(SRCS:./%.c=$(BUILDDIR)/%.o)
TESTS := $(wildcard $(TESTDIR)/*.c)
TESTOBJS := $(patsubst $(TESTDIR)/%.c, $(TESTOBJDIR)/%, $(TESTS))

CC := gcc

CFLAGS := -g -DDEBUG -Wall

.PHONY: all clean check

all: $(BINARY)

clean:
	rm -rf $(BUILDDIR)

check: $(TESTOBJS)

$(BINARY): $(OBJS)
	echo $(OBJS)
	@echo linking $@
	$(maketargetdir)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o : ./%.c
	@echo compiling $<
	$(maketargetdir)
	$(CC) $(CFLAGS) $(CINCLUDES) -c -o $@ $<

$(TESTOBJDIR)/%: $(TESTDIR)/%.c $(OBJS)
	mkdir -p $(TESTOBJDIR)
	$(CC) $(CFLAGS) $< $(OBJS) -o $@

define maketargetdir
	-@mkdir -p $(dir $@) > /dev/null 2>&1
endef