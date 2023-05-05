CXX      ?= g++
CXXFLAGS ?= -std=c++20 -O3 -fPIC
CPPFLAGS ?= -O3 -Wall -pedantic -I. 
LDFLAGS = 
LIBS = 

# LINK.o := $(LINK.cc) # Use C++ linker.

EXEC = main
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.PHONY = all $(EXEC) $(OBJS) clean distclean #$(DEPEND)

.DEFAULT_GOAL = all


all: $(EXEC)

$(EXEC): $(OBJS)	
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $(OBJS)  -o main 

$(OBJS): %.o: %.cpp
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $(SRCS)

clean:
	$(RM) *.o result.txt

distclean: clean
	$(RM) $(EXEC)
	$(RM) *~