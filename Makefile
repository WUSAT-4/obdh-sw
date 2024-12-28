PRODUCT := obdh-controller
SRCDIR := ./src
BUILDDIR := ./build
TESTDIR := ./test
TESTOBJDIR := $(BUILDDIR)/test

HDRS := $(shell find $(SRCDIR) -name '*.h')
SRCS := $(shell find $(SRCDIR) -name '*.c')
OBJS := $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
BINARY := $(BUILDDIR)/$(PRODUCT)

BUILDSRCS := $(filter-out $(SRCDIR)/main.c, $(shell find $(SRCDIR) -name '*.c'))
BUILDOBJS := $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(BUILDSRCS))

TESTS := $(filter-out $(TESTDIR)/dummy_%, $(wildcard $(TESTDIR)/*.c))
TESTOBJS := $(patsubst $(TESTDIR)/%.c, $(TESTOBJDIR)/%, $(TESTS))

DEVS := $(filter-out $(TESTDIR)/test_%, $(wildcard $(TESTDIR)/*.c))
DEVOBJS := $(patsubst $(TESTDIR)/%.c, $(TESTOBJDIR)/%.o, $(DEVS))

CC := gcc

CFLAGS := -g -Wall -Werror

.PHONY: all build check clean

all: $(BINARY)

build: $(BUILDOBJS)

check: $(TESTOBJS) $(DEVOBJS)

clean:
	rm -rf $(BUILDDIR)

$(BINARY): $(OBJS)
	echo $(OBJS)
	@echo linking $@
	$(maketargetdir)
	$(CC) -o $@ $^

$(BUILDDIR)/%.o : $(SRCDIR)/%.c
	@echo compiling $<
	$(maketargetdir)
	$(CC) $(CFLAGS) $(CINCLUDES) -c -o $@ $<

$(TESTOBJDIR)/%: $(TESTDIR)/%.c $(BUILDOBJS) $(DEVOBJS)
	$(maketargetdir)
	$(CC) $(CFLAGS) $< $(BUILDOBJS) $(DEVOBJS) -o $@
	@echo running test $@
	@./$@
	@echo -e test $@ '\033[0;32m'PASSED'\033[0m'

$(TESTOBJDIR)/%.o : $(TESTDIR)/%.c
	@echo compiling $<
	$(maketargetdir)
	$(CC) $(CFLAGS) $(CINCLUDES) -c -o $@ $<

define maketargetdir
	-@mkdir -p $(dir $@) > /dev/null 2>&1
endef
