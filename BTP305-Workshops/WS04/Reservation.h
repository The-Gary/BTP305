/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 5, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <iostream>

namespace sdds
{
	class Reservation 
	{
		std::string m_reserveId{};
		std::string m_reserveName{};
		std::string m_reserveEmail{};
		size_t m_reserveSize{};
		size_t m_reserveDay{};
		size_t m_reserveHour{};
	public:
		Reservation(){};
		Reservation(const std::string& res);
		void update(int day, int time);
		std::string extract(std::string& str, const char* delim);
		void trim(std::string& str);
		std::string timeStr() const;
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};
}
#endif // !SDDS_RESERVATION_H
