/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 5, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/
#include "Reservation.h"
#include <iomanip>

namespace sdds
{
	// Extracts information about the reservation from the string and stores the tokens in the instance's attributes
	// also removes all leading and trailing spaces from the beginning and the end of any token extracted from the string
	// ID:NAME,EMAIL,PARTY_SIZE,DAY,HOUR
	sdds::Reservation::Reservation(const std::string& res)
	{
		std::string temp = res;
		this->m_reserveId = extract(temp, ":");
		this->m_reserveName = extract(temp, ",");
		this->m_reserveEmail = extract(temp, ",");
		this->m_reserveSize = std::stoi(extract(temp, ","));
		this->m_reserveDay = std::stoi(extract(temp, ","));
		this->m_reserveHour = std::stoi(temp);
	}

	// updates the attributes with received values. Assumes params don't require validation
	void sdds::Reservation::update(int day, int time)
	{
		this->m_reserveDay = day;
		this->m_reserveHour = time;
	}

	// extracts and returns a string from the string param up to delim param
	// and removes the extracted string from the param string
	std::string Reservation::extract(std::string& str, const char* delim)
	{
		auto idx = str.find(delim);
		std::string ret = str.substr(0, idx);
		this->trim(ret);
		str.erase(0, idx + 1);
		return ret;
	}

	// removes leading and trailing white space from the received reference param
	void Reservation::trim(std::string& str)
	{
		auto begin = str.find_first_not_of(' ');
		auto end = str.find_last_not_of(' ');
		auto range = end - begin + 1;
		str = str.substr(begin, range);
	}

	// returns a string depending on time of the day
	inline std::string Reservation::timeStr() const
	{
		std::string ret{};
		if (this->m_reserveHour >= 6 && this->m_reserveHour <= 9)
		{
			ret = "Breakfast";
		}
		else if (this->m_reserveHour >= 11 && this->m_reserveHour <= 15)
		{
			ret = "Lunch";
		}
		else if (this->m_reserveHour >= 17 && this->m_reserveHour <= 21)
		{
			ret = "Dinner";
		}
		else
		{
			ret = "Drinks";
		}
		return ret;
	}

	// insertion operator to insert the contents of a reservation object into an ostream object
	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		os << "Reservation " << std::setw(10) << std::right << res.m_reserveId << ":   "
			<< std::setw(20) << res.m_reserveName + "  "
			<< std::setw(20) << std::left << "<" + res.m_reserveEmail + ">" << "    "
			<< res.timeStr() << " on day " << res.m_reserveDay << " @ "
			<< res.m_reserveHour << ":00 for "
			<< res.m_reserveSize << ((res.m_reserveSize == 1) ? " person." : " people.") << std::endl;
		return os;
	}

}
