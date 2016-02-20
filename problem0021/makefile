# Makefile entries are arranged as sets of targets to build, dependencies
# required to build that target, and the system command to build the target:
#
# target: dependencies
# [tab] system_command
#
# We can also use variables in our makefile, to make it easier to change
# compilers, or compilation flags.  The variable values are substituted
# wherever you see the $(VARIABLE) in the makefile
CC=g++ -std=c++11
CFLAGS=-c -g -Wall

all: driver

driver: problem21.o divisor.o
	$(CC) problem21.o divisor.o -g -o driver

problem21.o: problem21.cpp
	$(CC) $(CFLAGS) problem21.cpp

divisor.o: divisor.cpp divisor.h
	$(CC) $(CFLAGS) divisor.cpp

clean:
	rm -f *.o driver
