CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I. -I${mkEigenInc} -IExamples/include #-pedantic
LDFLAGS ?= -LExamples/lib -Wl,-rpath=Examples/lib  #in order to use the previous newtonslover
LDLIBS   ?= 
LINK.o := $(LINK.cc) # Use C++ linker.

#DEPEND = make.dep

EXEC = main
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.PHONY = all $(EXEC) $(OBJS) clean distclean #$(DEPEND)

.DEFAULT_GOAL = all


all: $(EXEC)

$(EXEC): $(OBJS) # $(CXX) $(CPPFLAGS) $(CXXFLAGS) -MM $${file} >> main;  cool this alone could create both obj files and ececoutable 'main'
	
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $(OBJS)  -o main 

$(OBJS): %.o: %.cpp
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $(SRCS)

clean:
	$(RM) *.o

distclean: clean
	$(RM) $(EXEC)
	$(RM) *~