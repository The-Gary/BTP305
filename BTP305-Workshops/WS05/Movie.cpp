/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 11, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <string>
#include <iostream>
#include <iomanip>
#include "Movie.h"

namespace sdds
{
	Movie::Movie(const std::string& strMovie)
	{
		std::string temp(strMovie);
		this->m_title = this->extract(temp, ',');
		this->m_year = std::stoi(this->extract(temp, ','));
		this->m_desc = this->extract(temp);
	}

	const std::string& Movie::title() const
	{
		return this->m_title;
	}

	std::string Movie::extract(std::string& str, const char delim)
	{
		auto idx = str.find(delim);
		std::string ret(str.substr(0, idx));
		str.erase(0, idx + 1);
		return this->trim(ret);
	}

	std::string Movie::extract(std::string& str)
	{
		return this->trim(str.substr(0));
	}

	std::string Movie::trim(const std::string& str) const
	{
		auto begin = str.find_first_not_of(' ');
		auto end = str.find_last_not_of(' ');
		auto range = end - begin + 1;
		return str.substr(begin, range);
	}

	std::ostream& operator<<(std::ostream& os, const Movie& src)
	{
		os << std::setw(40) << std::right << src.m_title << " | " << std::setw(4) << src.m_year << " | " << src.m_desc << std::endl;
		return os;
	}
}