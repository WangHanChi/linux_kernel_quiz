CC = gcc
CFLAGS = -O0

OBJS := swar_count_utf8
SOURCES := swar_count_utf8.c
DIR := ../../build

SOURCES_perf := performance.c
TARGET := performance
HEADER += cpucycles.h
CYCLE ?= 10000

PERF = perf
PFLAGS = stat --repeat 10 -e cache-misses,cache-references,instructions,cycles
PERMISSION = sudo sh -c "echo -1 > /proc/sys/kernel/perf_event_paranoid"

swar_count_utf8:
	$(CC) $(CFLAGS) $(SOURCES) -o $(DIR)/$(OBJS)

perf:
	$(CC) $(CFLAGS) $(SOURCES_perf) -o $(TARGET).elf	
	$(PERMISSION)
	$(PERF) $(PFLAGS) ./$(TARGET).elf

test:
	$(CC) -D CYCLE=$(CYCLE) $(CFLAGS) $(HEADER) $(SOURCES_perf) -o $(TARGET).elf
	./$(TARGET).elf