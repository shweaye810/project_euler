CC = g++ -std=c++1y
CFLAGS = -c -g -Wall
LIB = calendar
PROG = problem19

$(PROG).out: $(PROG).o $(LIB).o
	$(CC) $^ -g -o $(PROG).out

$(PROG).o: $(PROG).cpp
	$(CC) $(CFLAGS) $^

$(LIB).o: $(LIB).cpp $(LIB).h
	$(CC) $(CFLAGS) $^

.PHONY:clean
clean:
	-rm -f *.o *.out
