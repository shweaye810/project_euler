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

driver: problem19.o calendar.o
	$(CC) problem19.o calendar.o -g -o driver

problem19.o: problem19.cpp
	$(CC) $(CFLAGS) problem19.cpp

calendar.o: calendar.cpp calendar.h
	$(CC) $(CFLAGS) calendar.cpp

clean:
	rm -f *.o driver
