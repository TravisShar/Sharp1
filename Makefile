output: main.o SymbolTable.o
	g++ -o runtable main.o SymbolTable.o

main.o: main.cpp
	g++ -c main.cpp

SymbolTable.o: SymbolTable.h SymbolTable.cpp
	g++ -c SymbolTable.cpp

clean:
	rm runtable main.o SymbolTable.o
