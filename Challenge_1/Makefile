CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I. -I./include #TODO: DA RIVEDERE I PATH


#TODO: da chiedere a formaggia 
#TODO: quali librerie ????? 
LDFLAGS ?= 
LDLIBS  ?= 

#  EXEC = main  

CNHPP ?= CrankNicolson.hpp
CNCPP ?= CrankNicolson.cpp

.PHONY: all clear distclear

all: main

main: main.o # CrankNicolson.o
	$(CXX) $(LDFLAGS) $(CXXFLAGS) main.o -o main $(LDLIBS)

# %.o: main.cpp CrankNicolson.cpp #CrankNicolson.hpp

main.o: main.cpp CrankNicolson.cpp #CrankNicolson.hpp
# $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<  
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) main.cpp


clean:
	$(RM) *.o

distclean: clean
	$(RM) *~
