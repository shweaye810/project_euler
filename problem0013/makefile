CC = g++ -std=c++1y
CFLAGS = -c -g -Wall
LIB_DIR = ../big_int

prog = problem13

$(prog).out: $(prog).o big_int.o
	$(CC) $^ -g -o $(prog).out

$(prog).o: $(prog).cpp
	$(CC) $(CFLAGS) $^

big_int.o: $(LIB_DIR)/big_int.cpp $(LIB_DIR)/big_int.h
	$(CC) $(CFLAGS) $^

.PHONY:clean
clean:
	-rm -f *.o driver
