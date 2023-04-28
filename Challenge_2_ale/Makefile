CXX      ?= g++
CXXFLAGS ?= -std=c++20 -O3 -fPIC
CPPFLAGS ?= -O3 -Wall -pedantic -I. 
LDFLAGS = 
LIBS = 

# LINK.o := $(LINK.cc) # Use C++ linker.

.PHONY: all clean distclean

all: main

main: main.o Solver.o
	$(CXX) $(LDFLAGS) main.o Solver.o -o main

main.o: main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c main.cpp

Solver.o: Solver.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Solver.cpp

clean:
	$(RM) *.o

distclean: clean
	$(RM) *~
	$(RM) main