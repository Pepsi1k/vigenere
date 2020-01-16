
all: vigenere

vigenere: main.o
	g++ main.o -o a.out

main.o: main.cpp
	g++ -c main.cpp 

clean: 
	rm -rf *.o

