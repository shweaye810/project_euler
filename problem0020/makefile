CC = g++ -std=c++1y
CFLAGS = -c -g -Wall
LIB_DIR = ../big_int

all: driver

driver: problem20.o big_int.o
	$(CC) problem20.o big_int.o -g -o driver

problem20.o: problem20.cpp
	$(CC) $(CFLAGS) $^

big_int.o: $(LIB_DIR)/big_int.cpp $(LIB_DIR)/big_int.h
	$(CC) $(CFLAGS) $^

.PHONY:clean
clean:
	-rm -f *.o driver
