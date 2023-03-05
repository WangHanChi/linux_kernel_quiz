CC = gcc
CFLAGS = -O1

dirs = $(filter %/, $(wildcard [^_]*/))
SUBDIRS = $(subst /,,$(subst common,,$(dirs)))

all: $(SUBDIRS)

$(SUBDIRS): common
	@if [ -f $@/Makefile ]; then \
		$(MAKE) -C $@; \
	fi

common:
	$(MAKE) -C $@
