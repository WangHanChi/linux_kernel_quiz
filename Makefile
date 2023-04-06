
test_dir := build
DIR ?= $(shell pwd)/build


all: dir		
	@echo "make start"	
	make -C quiz1		
	make -C quiz2
	make -C quiz3
	make -C quiz4		
	@echo "make done"


dir:
	$(shell if [ ! -e $(test_dir) ];then mkdir -p $(test_dir); fi)

clean:
	rm -f build/*
