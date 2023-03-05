CC = gcc
CFLAGS = -O1

OBJS := concatenatedBinary.o
SOURCES := concatenatedBinary.c


concatenatedBinary: $(OBJS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(OBJS)
	./$(OBJS)

clean:
	$(RM) *.o