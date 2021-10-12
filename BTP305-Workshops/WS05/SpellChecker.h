/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 11, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_SPELL_CHECKER_H
#define SDDS_SPELL_CHECKER_H

#include <string>
#include <iostream>

namespace sdds
{
	constexpr auto MAX_SIZE = 6u;
	class SpellChecker
	{
		std::string m_badWords[MAX_SIZE] {};
		std::string m_goodWords[MAX_SIZE] {};
		size_t m_cnt[MAX_SIZE]{};
	public:
		SpellChecker(){};
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& os) const;
	};
}
#endif // !SDDS_SPELL_CHECKER_H
