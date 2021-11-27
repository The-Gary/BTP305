// Workshop 9 - Multi-Threading
// SecureData.cpp
// 
/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		November 27, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		/*// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
		auto f = std::bind(converter, text, key, nbytes, Cryptor());

		auto size = nbytes / 4;
		std::thread t1(f, text, key, size);
		std::thread t2(f, text + size, key, size);
		std::thread t3(f, text + (size*2), key, size);
		auto s = nbytes - (size * 3);
		std::thread t4(f, text + (size*3), key, s - 1);

		t1.join();
		t2.join();
		t3.join();
		t4.join();

		encoded = !encoded;*/
		auto f = std::bind(converter, text, key, nbytes, Cryptor());

		auto size = nbytes / 4;
		int s{};

		thread t1(f, text, key, size, Cryptor());
		s += size;
		thread t2(f, text + s, key, size, Cryptor());
		s += size;
		thread t3(f, text + s, key, size, Cryptor());
		size = nbytes - s;
		thread t4(f, text + s, key, size, Cryptor());

		t1.join();
		t2.join();
		t3.join();
		t4.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// DONE: open a binary file for writing
			std::fstream binFout(file, std::ios::out | std::ios::binary | std::ios::trunc);

			// DONE: write data into the binary file
			//         and close the file
			if (!binFout)
			{
				throw "Could not open file";
			}
			binFout.write(text, nbytes);
			binFout.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// DONE: open binary file for reading
		std::fstream binFin(file, std::ios::in | std::ios::binary);

		// DONE: - allocate memory here for the file content
		binFin.seekg(0, std::ios::end);
		nbytes = (int)binFin.tellg();

		delete[] text;
		text = new char[nbytes];


		// DONE: - read the content of the binary file
		binFin.seekg(ios::beg);
		int i = 0;
		binFin >> noskipws;
		while (binFin)
			binFin >> text[i++];

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
		binFin.close();
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
