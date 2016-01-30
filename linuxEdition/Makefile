#
# Makefile
#

# compiler to use
# CXX = clang++
CXX ?= clang++

# flags to pass compiler
CXXFLAGS = -ggdb3 -O0 -std=c++14 -stdlib=libc++ -Wall -Werror -pedantic-errors

# flags for the CPP  PreProcessor
CPPFLAGS =

# The maintainer's variant of CXXFLAGS
AM_CXXFLAGS =

# The command used to actually compile a C++ source file.
# The file name is appended to form the complete command line.
CXXCOMPILE =

# The command used to actually link a C++ program
CXXLINK = -lc++abi

# name for executable
EXE = main

# space-separated list of header files
HDRS = *.h

# space-separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS =  -lm -lpthread

# space-separated list of source files
SRCS = *.cpp

# automatically generated list of object files
 OBJS = $(SRCS:.cpp=.o)


# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(AM_CXXFLAGS) $(CXXCOMPILE) $(CXXLINK) -o $@ $(SRCS) $(LIBS)

# dependencies
$(OBJS): $(HDRS) Makefile

# housekeeping
clean:
	rm -f core *.o
