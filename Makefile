PRODUCT := obdh-controller
SRCDIR := ./src
BUILDDIR := ./build
TESTDIR := ./test
TESTOBJDIR := $(BUILDDIR)/test

HDRS := $(filter-out $(SRCDIR)/dummy_subsystems.h, $(shell find $(SRCDIR) -name '*.h'))
SRCS := $(filter-out $(SRCDIR)/dummy_subsystems.c, $(shell find $(SRCDIR) -name '*.c'))
OBJS := $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
BINARY := $(filter-out $(TESTOBJDIR), $(BUILDDIR)/$(PRODUCT))

BUILDSRCS := $(filter-out $(SRCDIR)/main.c, $(shell find $(SRCDIR) -name '*.c'))
BUILDOBJS := $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(BUILDSRCS))

TESTS := $(wildcard $(TESTDIR)/*.c)
TESTOBJS := $(patsubst $(TESTDIR)/%.c, $(TESTOBJDIR)/%, $(TESTS))

CC := gcc

CFLAGS := -g -Wall -Werror

.PHONY: all build check clean

all: $(BINARY)

build: $(BUILDOBJS)

check: $(TESTOBJS)

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

$(TESTOBJDIR)/%: $(TESTDIR)/%.c $(BUILDOBJS)
	$(maketargetdir)
	$(CC) $(CFLAGS) $< $(BUILDOBJS) -o $@
	@echo running test $@
	@./$@

$(TESTOBJDIR)/%.o : $(TESTDIR)/%.c
	@echo compiling $<
	$(maketargetdir)
	$(CC) $(CFLAGS) $(CINCLUDES) -c -o $@ $<

define maketargetdir
	-@mkdir -p $(dir $@) > /dev/null 2>&1
endef
