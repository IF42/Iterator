
CC = gcc
CFLAGS = -Wall -Wextra -pedantic 
LIBS = 

INDIR=/usr/include
CACHE=.cache
RELEASE=$(CACHE)/release
OUTPUT=test

all: env test/test.c src/iterator/iterator.h
	$(CC) $(CFLAGS) test/test.c $(LIBS) -o $(RELEASE)/$(OUTPUT)


test: all
	./$(RELEASE)/$(OUTPUT)


.PHONY: install clean env test

env:
	mkdir -pv $(CACHE)
	mkdir -pv $(RELEASE)

clean:
	rm -rvf $(CACHE)

install:
	cp -vf src/iterator $(INDIR) 



