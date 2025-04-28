#yoav1.nach@gmail.com

program: Main.o SquareMat.o
	g++ -o program  Main.o SquareMat.o

Main.o: Main.cpp
	g++ -c  Main.cpp -o Main.o

SquareMat.o:SquareMat.cpp
	g++ -c SquareMat.cpp -o SquareMat.o 

clear:
	rm -f Main.o SquareMat.o program tests.o test

test: tests.o SquareMat.o
	g++  SquareMat.cpp  tests.o -o test

tests.o: tests.cpp
	g++ -c -o tests.o tests.cpp

valgrind: program 
	valgrind ./program