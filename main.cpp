#include <iostream>
#include <string>

int main(int argc, const char* argv[]) {
	// const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// int LENGTH = alphabet.length();

	int LENGTH = 128;

	char** vigenere_square = new char*[LENGTH];
	for (std::size_t i = 0; i < LENGTH; i++) {
		vigenere_square[i] = new char[LENGTH];
	}

	std::cout << "ALPHABET_LENGTH: " << LENGTH << std::endl << std::endl;

	// generate vigenere_square
	int steper = 0;
	int temp_steper = 0;
	std::size_t vigenere_column = 0;
	for (std::size_t i = 0; i < LENGTH; i++) {
		temp_steper = steper;
		vigenere_column = 0;
		do {
			// vigenere_square[i][vigenere_column] = alphabet[temp_steper];
			vigenere_square[i][vigenere_column] = (char)temp_steper;
			temp_steper++;
			if (temp_steper == LENGTH) {
				temp_steper = 0;
			}
			vigenere_column++;
		} while (temp_steper != steper);
		steper++;
	}


	// print vigenere_square
	/*
	for (std::size_t i = 0; i < LENGTH; i++) {
		for (std::size_t j = 0; j < LENGTH; j++) {
			std::cout << vigenere_square[i][j];
		}
		std::cout << std::endl;
	}
	*/

	std::cout << std::endl;
	std::cout << vigenere_square[90][92] << std::endl;
	// delete vigenere_suare
	for (std::size_t i = 0; i < LENGTH; i++) {
		delete[] vigenere_square[i];
	}
	delete[] vigenere_square;

	return 0;
}
