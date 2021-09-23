/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		September 22, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <fstream>
#include <string>
#include "StringSet.h"

namespace sdds
{
	StringSet::StringSet(const char* fileName)
	{
		std::ifstream fin;
		fin.open(fileName);
		if (fin.is_open()) {
			char temp{};
			while (!fin.fail()) {
				fin.get(temp);
				this->m_count += (temp == ' ');
			}
			++this->m_count; // for the last word
			this->m_strings = new std::string[this->m_count];
			fin.clear();
			fin.seekg(0);
			auto i = 0;
			while (!fin.fail()) {
				std::getline(fin, this->m_strings[i], ' ');
				++i;
			}
		}
	}

	StringSet::StringSet(const StringSet& other)
	{
		*this = other;
	}

	StringSet& StringSet::operator=(const StringSet& other)
	{
		if (this != &other) {
			this->m_count = other.m_count;
			delete[] this->m_strings;
			this->m_strings = new std::string[this->m_count];
			for (size_t i = 0; i < this->m_count; ++i) {
				this->m_strings[i] = other.m_strings[i];
			}
		}
		return *this;
	}

	StringSet::StringSet(StringSet&& other)
	{
		*this = std::move(other);
	}

	StringSet& StringSet::operator=(StringSet&& other)
	{
		if (this != &other) {
			this->m_count = other.m_count;
			delete[] this->m_strings;
			this->m_strings = other.m_strings;
			other.m_strings = nullptr;
		}
		return *this;
	}

	StringSet::~StringSet()
	{
		delete[] this->m_strings;
	}

	size_t StringSet::size() const
	{
		return this->m_count;
	}

	std::string StringSet::operator[](size_t index)
	{
		return (index <= this->m_count && index >= 0 && m_strings) ? this->m_strings[index] : std::string{};
	}
}