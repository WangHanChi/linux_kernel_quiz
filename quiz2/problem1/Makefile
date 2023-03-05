CC = gcc
CFLAGS = -O1

OBJS := builtin_pow2
SOURCES := builtin_pow2.c

OBJS_test := builtin_test
SOURCES_test := builtin_test.c

OBJS_2 := pow2
SOURCES_2 := pow2.c

OBJS_C := compare
SOURCES_C := compare.c

builtin_pow2: $(OBJS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(OBJS)
	./$(OBJS)

builtin_test: $(OBJS_test)
	$(CC) $(CFLAGS) $(SOURCES_test) -o $(OBJS_test)
	./$(OBJS_test)

compare: $(OBJS_C)
	$(CC) $(CFLAGS) $(SOURCES_C) -o $(OBJS_C)
	./$(OBJS_C)

pow2: $(OBJS_2)
	$(CC) $(CFLAGS) $(SOURCES_2) -o $(OBJS_2)
	./$(OBJS_2)

clean:
	$(RM) *.out