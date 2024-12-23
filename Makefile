PRODUCT := obdh-controller
SRCDIR := ./src
BUILDDIR := ./build
TESTDIR := ./test
TESTOBJDIR := $(BUILDDIR)/test

HDRS := $(wildcard $(SRCDIR)/*.h)
SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
BINARY := $(BUILDDIR)/$(PRODUCT)

BUILDSRCS := $(filter-out $(SRCDIR)/main.c, $(wildcard $(SRCDIR)/*.c))
BUILDOBJS := $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(BUILDSRCS))

TESTS := $(wildcard $(TESTDIR)/*.c)
TESTOBJS := $(patsubst $(TESTDIR)/%.c, $(TESTOBJDIR)/%, $(TESTS))

CC := gcc

CFLAGS := -g -DDEBUG -Wall

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
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o : $(SRCDIR)/%.c
	@echo compiling $<
	$(maketargetdir)
	$(CC) $(CFLAGS) $(CINCLUDES) -c -o $@ $<

$(TESTOBJDIR)/%: $(TESTDIR)/%.c $(BUILDOBJS)
	mkdir -p $(TESTOBJDIR)
	$(CC) $(CFLAGS) $< $(BUILDOBJS) -o $@

define maketargetdir
	-@mkdir -p $(dir $@) > /dev/null 2>&1
endef