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

driver: problem20.o big_int.o
	$(CC) problem20.o big_int.o -g -o driver

problem20.o: problem20.cpp
	$(CC) $(CFLAGS) problem20.cpp

big_int.o: big_int.h big_int.cpp
	$(CC) $(CFLAGS) big_int.cpp

clean:
	rm -f *.o driver
