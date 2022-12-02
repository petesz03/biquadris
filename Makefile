CXX=g++ 
CXXFLAGS=-std=c++14 -Wall -O -MMD -Werror=vla # use -MMD to generate dependencies
SOURCES= level4.cc  # list of all .cc files in the current directory
OBJECTS=${SOURCES:.cc=.o}  # .o files depend upon .cc files with same names
DEPENDS=${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .cc file
EXEC=biquadris

# First target in the makefile is the default target.
${EXEC}: ${OBJECTS}
		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11
#   strip ${EXEC}

%.o: %.cc 
		${CXX} -c -o $@ $< ${CXXFLAGS}

-include ${DEPENDS}

.PHONY: clean
clean:
		rm  -f ${OBJECTS} ${DEPENDS} ${EXEC}