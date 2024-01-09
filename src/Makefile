#macros (i.e., variables) for a makefile
CXX = c++
CFLAGS = -c
LINKER = -o
CXXSOURCE = helloSFML.cpp PlayerFuncts.cpp ScoreFuncts.cpp WorldFuncts.cpp
HEADERS = helloSFML.hpp PlayerFuncts.hpp ScoreFuncts.hpp WorldFuncts.hpp

# Default target when running "make," which calls "program"
all: program

#echo prints the following, used to ensure the macros were correct 
printM:
	@echo CXX: $(CXX)
	@echo CFLAGS: $(CFLAGS)
	@echo CXXSOURCE: $(CXXSOURCE)
	@echo HEADERS: $(HEADERS)

#this will compile the changed files
program: $(CXXSOURCE) $(HEADERS)
	$(CXX) $(CFLAGS) $(CXXSOURCE)
	$(CXX) helloSFML.o PlayerFuncts.o ScoreFuncts.o WorldFuncts.o $(LINKER) program

# Defines a target for cleaning up the project
.PHONY: clean

# 'make clean' will remove the executable and the .o files
clean:
	rm -rf *.o
	rm program

# 'make run' will run the executable
run: program
	./program
