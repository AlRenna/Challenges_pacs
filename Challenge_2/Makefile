############################################################
#
# An example of Makefile for the course on 
# Advanced Programming for Scientific Computing
# It should be modified for adapting it to the various examples
#
############################################################
#
# The environmental variable PACS_ROOT should be set to the
# root directory where the examples reside. In practice, the directory
# where this file is found. The resolution of PACS_ROOT is made in the
# Makefile.h file, where other important variables are also set.
# The only user defined variable that must be set in this file is
# the one indicating where Makefile.h resides

#
include Makefile.inc
#
# You may have an include file also in the current directory
#
-include Makefile.inc

#
# The general setting is as follows:
# mains are identified bt main_XX.cpp
# all other files are XX.cpp
#

# get all files *.cpp
SRCS=$(wildcard *.cpp)
# get the corresponding object file
OBJS = $(SRCS:.cpp=.o)
# get all headers in the working directory
HEADERS=$(wildcard *.hpp)
#
exe_sources=$(filter main%.cpp,$(SRCS))
EXEC=$(exe_sources:.cpp=)

CPPFLAGS ?= -O3 -Wall -I. -I${mkEigenInc} -IExamples/utilities #-pedantic
CXXFLAGS+=-fPIC
LDFLAGS= $(OPTFLAGS) -Wl,-rpath,.
LDLIBS=-L. -lFactory -ldl
#========================== ORA LA DEFINIZIONE DEGLI OBIETTIVI
.phony= all clean distclean doc

.DEFAULT_GOAL = all

all: $(DEPEND) library $(EXEC)

library: libFactory.so libNewton.so libSolver.so 

libFactory.so: FactoryTraits.o
	$(CXX)  $(CPPFLAGS) $(OPTFLAGS) -shared FactoryTraits.o  -o libFactory.so 

libNewton.so: newton.o Solver.o
	$(CXX)  $(CPPFLAGS) $(OPTFLAGS) -shared newton.o Solver.o  -L. -lFactory -o libNewton.so



clean:
	$(RM) -f $(EXEC) $(OBJS)

distclean:
	$(MAKE) clean
	$(RM) -f ./doc $(DEPEND)
	$(RM) *.out *.bak *~ *.so

doc:
	doxygen $(DOXYFILE)

$(EXEC): main_solver.o Solver.o SolverFactory.o


$(OBJS): $(SRCS)


$(DEPEND): $(SRCS)
	$(RM) $(DEPEND)
	for f in $(SRCS); do \
	$(CXX) $(STDFLAGS) $(CPPFLAGS) -MM $$f >> $(DEPEND); \
	done

-include $(DEPEND)




