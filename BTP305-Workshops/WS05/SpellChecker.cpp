/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 11, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include "SpellChecker.h"

namespace sdds
{
	// loads the arrays from filename
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream fin(filename);
		if (!fin)
		{
			throw "Bad file name!";
		}
		
		std::string str{};
		size_t idx = 0;
		do
		{
			std::getline(fin, str);
			if (fin)
			{
				auto spaceBegin = str.find_first_of(' ');
				auto spaceEnd = str.find_last_of(' ');
				this->m_badWords[idx] = str.substr(0, spaceBegin);
				this->m_goodWords[idx] = str.substr(++spaceEnd);
				++idx;
			}
		}
		while (fin);
		fin.close();
	}

	// searches text and replaces any misspelled words with the correct version
	// counts how many times each misspelled word has been replaced
	void SpellChecker::operator()(std::string & text)
	{
		size_t idx = 0;
		auto length = 0u;
		for (auto i = 0u; i < MAX_SIZE; ++i)
		{
			do
			{
				idx = text.find(this->m_badWords[i]);
				
				if (idx != std::string::npos)
				{
					length = this->m_badWords[i].length();
					text.replace(idx, length, this->m_goodWords[i]);
					++this->m_cnt[i];
				}
			}
			while (idx != std::string::npos);
		}
	}

	void SpellChecker::showStatistics(std::ostream& os) const
	{
		os << "Spellchecker Statistics\n";
		os << std::right;
		for (auto i = 0u; i < MAX_SIZE; ++i)
		{
			os << std::setw(15) << this->m_badWords[i] << ": " << this->m_cnt[i] << " replacements" << std::endl;
		}
		os << std::left;
	}
}