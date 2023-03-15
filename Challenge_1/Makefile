CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I.  #-I./include #TODO: DA RIVEDERE I PATH

LDFLAGS ?= 
LDLIBS  ?= 


SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
HEADERS = $(wildcard *.hpp)


exe_sources = $(filter main%.cpp,$(SRCS))
EXEC = $(exe_sources:.cpp=)


CNHPP ?= CrankNicolson.hpp
CNCPP ?= CrankNicolson.cpp

.PHONY = all clean distclean

.DEFAULT_GOAL = all

all: $(EXEC)

$(EXEC): $(OBJS)
	#$(CXX) $(LDFLAGS) $(CXXFLAGS) $< -o main $(LDLIBS)
	$(CXX)  $(CXXFLAGS) $(OBJS) -o main 

# %.o: main.cpp CrankNicolson.cpp #CrankNicolson.hpp

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $(SRCS)
	#$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) main.cpp


clean:
	$(RM) *.o

distclean: clean
	$(RM) *~
