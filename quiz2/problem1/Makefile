CC = gcc
CFLAGS = -O1
DIR := ../../build

OBJS := builtin_pow2
SOURCES := builtin_pow2.c

OBJS_test := builtin_test
SOURCES_test := builtin_test.c

OBJS_2 := pow2
SOURCES_2 := pow2.c

OBJS_C := compare
SOURCES_C := compare.c

all: builtin_pow2 builtin_test compare pow2

builtin_pow2: $(OBJS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(DIR)/$(OBJS)

builtin_test: $(OBJS_test)
	$(CC) $(CFLAGS) $(SOURCES_test) -o $(DIR)/$(OBJS_test)

compare: $(OBJS_C)
	$(CC) $(CFLAGS) $(SOURCES_C) -o $(DIR)/$(OBJS_C)

pow2: $(OBJS_2)
	$(CC) $(CFLAGS) $(SOURCES_2) -o $(DIR)/$(OBJS_2)
