CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I.  
LDFLAGS ?= 
LDLIBS  ?= 


SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = $(wildcard *.hpp)


exe_sources = $(filter main%.cpp,$(SRCS))
EXEC = main

# Flags for the muParser 
###############################################################
CPPFLAG_MUPARSER ?= -IExamples/include 
EXEC_MUPARSER     = main_muparser
LDFLAGS_MUPARSER ?= -LExamples/lib -Wl,-rpath=Examples/lib
LIB_MUPARSER     ?= -lmuparser
###############################################################


.PHONY = all clean distclean

.DEFAULT_GOAL = all

all: $(EXEC) $(EXEC_MUPARSER)

# MUPARSER
###############################################################
$(EXEC_MUPARSER).o: %.o: %.cpp newton.hpp muparser_fun.hpp theta.hpp
	$(CXX) -c $(CPPFLAGS) $(CPPFLAG_MUPARSER) $(CXXFLAGS) $<

$(EXEC_MUPARSER): %: %.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDFLAGS_MUPARSER) $< $(LIBS) $(LIB_MUPARSER) -o $@
###############################################################

$(EXEC): $(OBJS)
	$(CXX)  $(CXXFLAGS) $(OBJS) -o main 


$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $(SRCS)


clean:
	$(RM) *.o *.png *.txt result.txt

distclean: clean
	$(RM) *~
	$(RM) main main_muparser