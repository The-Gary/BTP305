/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 11, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>
#include <iostream>

namespace sdds
{
	class Movie
	{
		std::string m_title{};
		std::string m_desc{};
		size_t m_year{};
	public:
		Movie(){};
		Movie(const std::string& strMovie);
		const std::string& title() const;
		std::string extract(std::string& str, const char delim);
		std::string extract(std::string& str);
		std::string trim(const std::string& str) const;
		friend std::ostream& operator<<(std::ostream& os, const Movie& src);
		template<typename T>
		void fixSpelling(T& spellChecker);
	};
	template<typename T>
	inline void Movie::fixSpelling(T& spellChecker)
	{
		spellChecker(this->m_title);
		spellChecker(this->m_desc);
	}
}
#endif // !SDDS_MOVIE_H
