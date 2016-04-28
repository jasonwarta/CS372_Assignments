#makefile for VendingMachine project

COMPILER=g++
STD=c++11

FLAGS = -std=$(STD) -Wall -pedantic -Wno-deprecated-declarations 

DEPEND = main
FILES = main.o

all: $(DEPEND)
	$(COMPILER) $(FLAGS) $(FILES) -o main

main: main.cpp
	$(COMPILER) $(FLAGS) -c main.cpp

clean:
	rm -f *.o main 2> /dev/null