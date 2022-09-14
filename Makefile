output: main.o SYMBOL.o
	g++ -o runtable main.o SYMBOL.o

main.o: main.cpp
	g++ -c main.cpp

SYMBOL.o: SYMBOL.h SYMBOL.cpp
	g++ -c SYMBOL.cpp

clean:
	rm runtable main.o SYMBOL.o