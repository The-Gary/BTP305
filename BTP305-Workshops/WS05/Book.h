/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 11, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>
#include <iostream>

namespace sdds
{
	class Book
	{
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		std::string m_desc{};
		size_t m_year{};
		double m_price{};
	public:
		Book(){};
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		std::string extract(std::string& str, const char* delim);
		void trim(std::string& str);
		friend std::ostream& operator<<(std::ostream& os, const Book& src);
	};
}
#endif // !SDDS_BOOK_H
