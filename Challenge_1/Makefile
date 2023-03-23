CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I.  
LDFLAGS ?= 
LDLIBS  ?= 


SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = $(wildcard *.hpp)


EXEC = main

# Flags for the muParser 
###############################################################
SRCS_MUPARSER ?= main_muparser.cpp
OBJS_MUPARSER = $(SRCS_MUPARSER:.cpp=.o)
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


$(EXEC_MUPARSER): $(OBJS_MUPARSER)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDFLAGS_MUPARSER) $(OBJS_MUPARSER) $(LIBS) $(LIB_MUPARSER) -o main_muparser

$(OBJS_MUPARSER): $(SRCS_MUPARSER) $(HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CPPFLAG_MUPARSER) $(CXXFLAGS) $(SRCS_MUPARSER)
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