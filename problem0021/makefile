CC = g++ -std=c++1y
CFLAGS = -c -g -Wall
LIB = divisor
LIB_LOC = ../$(LIB)/$(LIB)
PROG = problem21

$(PROG).out: $(PROG).o $(LIB).o
	$(CC) $^ -g -o $(PROG).out

$(PROG).o: $(PROG).cpp
	$(CC) $(CFLAGS) $<

$(LIB).o: $(LIB_LOC).cpp $(LIB_LOC).h
	$(CC) $(CFLAGS) $<

.PHONY:clean
clean:
	-rm -f *.o *.out
