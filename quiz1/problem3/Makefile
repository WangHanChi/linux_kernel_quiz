CC = gcc
CFLAGS = -O1

OBJS := xor_linked_list.o
SOURCES := xor_linked_list.c

test : xor
	./$(OBJS)

xor: $(OBJS)
	$(CC) $(SOURCES) -o $(OBJS)