CXX=g++ 
CXXFLAGS=-std=c++14 -Wall -O -MMD -Werror=vla # use -MMD to generate dependencies
# SOURCES=$(wildcard *.cc)
SOURCES= block.cc board.cc graphicdisplay.cc iblock.cc jblock.cc lblock.cc level.cc level0.cc level1.cc level2.cc level3.cc level4.cc oblock.cc player.cc posn.cc sblock.cc subject.cc tblock.cc textdisplay.cc window.cc zblock.cc main.cc # list of all .cc files in the current directory
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
