#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>

int main(int argc, const char* argv[]) {
	// const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// int LENGTH = alphabet.length();

	std::cout << "argc: " << argc << std::endl;
	if (argc != 3) {
		return 1;
	}


	std::ifstream in_file(argv[1]);
	std::ifstream out_file;

	std::string key((std::istreambuf_iterator<char>(in_file)),
		std::istreambuf_iterator<char>());

	in_file.close();
	in_file.open(argv[2]);
	std::string file((std::istreambuf_iterator<char>(in_file)),
		std::istreambuf_iterator<char>());
	std::cout << "key: " << key;
	std::cout << "key_length: " << key.length() << std::endl;
	std::cout << "file: " << file;
	std::cout << "file_length: " << file.length() << std::endl;
	if ((key.lenght() < 2) || (file.length() < 2)) {
		return 2;
	}

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


	// encrypting
	for (std::size_t i_file = 0; i_file < file.length(); i_file) {

		file[i_file] 
	}
	

	// delete vigenere_suare
	for (std::size_t i = 0; i < LENGTH; i++) {
		delete[] vigenere_square[i];
	}
	delete[] vigenere_square;

	return 0;
}
