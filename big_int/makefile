# Makefile entries are arranged as sets of targets to build, dependencies
# required to build that target, and the system command to build the target:
#
# target: dependencies
# [tab] system_command
#
# We can also use variables in our makefile, to make it easier to change
# compilers, or compilation flags.  The variable values are substituted
# wherever you see the $(VARIABLE) in the makefile
CC = g++ -std=c++1y
CFLAGS = -Wall -c -g
LDFLAGS = -shared

big_int.o: big_int.cpp big_int.h
	$(CC) $(CFLAGS) big_int.cpp

clean:
	rm -f *.o
