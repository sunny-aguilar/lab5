# File: 	makefile
# Author: 	Sandro Aguilar
# Date: 	February 2019
# Description:	Makefile for Lab 5

# Variables to control Makefile operation

CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x

OBJECTS = main.o
OBJECTS += recursion.o
OBJECTS += menu.o

HPPs = recursion.hpp
HPPs += menu.hpp

CPPs = main.cpp
CPPs += recursion.cpp
CPPs += menu.cpp


# Targets needed to bring the executable up to date
Rec: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o Rec $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

recursion.o: recursion.hpp

menu.o: menu.hpp


# Clean-up operations
clean:
	rm Rec *.o

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./Rec

zip:
	zip -D Lab5_Aguilar_Sandro.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf
