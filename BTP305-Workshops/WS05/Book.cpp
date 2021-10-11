#include "Book.h"
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

namespace sdds
{
	// receives a reference to an unmodifiable string that contains informaiton about the book;
	// extracts the information from the string by parsing it and stores the token in the object's attributes
	// removes leading and trailing white spaces
	// AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
	Book::Book(const std::string& strBook)
	{
		std::string temp = strBook;
		this->m_author = extract(temp, ",");
		this->m_title = extract(temp, ",");
		this->m_country = extract(temp, ",");
		this->m_price = std::stod(extract(temp, ","));
		this->m_year = std::stoi(extract(temp, ","));
		this->m_desc = extract(temp, "\n");

	}

	const std::string& Book::title() const
	{
		return this->m_title;
	}

	const std::string& Book::country() const
	{
		return this->m_country;
	}

	const size_t& Book::year() const
	{
		return this->m_year;
	}

	double& Book::price()
	{
		return this->m_price;
	}

	std::string Book::extract(std::string& str, const char* delim)
	{
		auto idx = str.find(delim);
		std::string ret = str.substr(0, idx);
		this->trim(ret);
		str.erase(0, idx + 1);
		return ret;
	}

	void Book::trim(std::string& str)
	{
		auto begin = str.find_first_not_of(' ');
		auto end = str.find_last_not_of(' ');
		auto range = end - begin + 1;
		str = str.substr(begin, range);
	}

	/*
	the author printed on a field of size 20; RIGHT
	the title printed on a field of size 22; RIGHT
	the country printed on a field of size 5; RIGHT
	the year printed on a field of size 4; RIGHT
	the price printed on a field of size 6, with 2 decimal digits; RIGHT
	the description printed with LEFT alignment
	see alignment in the sample output.
	*/
	std::ostream& operator<<(std::ostream& os, const Book& src)
	{
		os << std::setw(20) << std::right << src.m_author << " | "
			<< std::setw(22) << src.m_title << " | "
			<< std::setw(5) << src.m_country << " | "
			<< std::setw(4) << src.m_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << src.m_price << " | "
			<< src.m_desc << std::endl;
		return os;
	}
}