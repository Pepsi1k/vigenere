
all: vigenere

vigenere: encrypt.o
	g++ encrypt.o -o encrypt

encrypt.o: encrypt.cpp
	g++ -c encrypt.cpp 

clean: 
	rm -rf *.o

