/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		September 22, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <string>

#ifndef SDDS_STRING_SET_H
#define SDDS_STRING_SET_H

namespace sdds
{
	class StringSet
	{
		std::string* m_strings{};
		size_t m_size{};
	public:
		StringSet(){};
		StringSet(const char*);
		StringSet(const StringSet&);
		StringSet& operator=(const StringSet&);
		StringSet(StringSet&&);
		StringSet& operator=(StringSet&&);
		~StringSet();
		size_t size() const;
		std::string operator[](size_t);
	};
}

#endif // !SDDS_STRING_SET_H
