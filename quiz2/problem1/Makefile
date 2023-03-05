CC = gcc
CFLAGS = -O1

OBJS := builtin_pow2.o
SOURCES := builtin_pow2.c

OBJS_test := builtin_test.o
SOURCES_test := builtin_test.c

OBJS_2 := pow2.o
SOURCES_2 := pow2.c

OBJS_C := compare.o
SOURCES_C := compare.c

builtin_pow2: $(OBJS)
	$(CC) $(SOURCES) -o $(OBJS)
	./$(OBJS)

builtin_test: $(OBJS_test)
	$(CC) $(SOURCES_test) -o $(OBJS_test)
	./$(OBJS_test)

compare: $(OBJS_C)
	$(CC) $(SOURCES_C) -o $(OBJS_C)
	./$(OBJS_C)

pow2: $(OBJS_2)
	$(CC) $(SOURCES_2) -o $(OBJS_2)
	./$(OBJS_2)