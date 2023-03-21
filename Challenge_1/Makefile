CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I.  
LDFLAGS ?= 
LDLIBS  ?= 


SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
HEADERS = $(wildcard *.hpp)


exe_sources = $(filter main%.cpp,$(SRCS))
EXEC = $(exe_sources:.cpp=)


.PHONY = all clean distclean

.DEFAULT_GOAL = all

all: $(EXEC)

$(EXEC): $(OBJS)
	#$(CXX) $(LDFLAGS) $(CXXFLAGS) $< -o main $(LDLIBS)
	$(CXX)  $(CXXFLAGS) $(OBJS) -o main 


$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $(SRCS)


clean:
	$(RM) *.o

distclean: clean
	$(RM) *~
	$(RM) main