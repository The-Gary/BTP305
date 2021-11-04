/*
Name: Yousef Majidinejad
Seneca Student ID: 101306207
Seneca email: ymajidinejad@myseneca.ca
Date of completion: October 30, 2021
I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>

namespace sdds
{
	class Station
	{
		int m_iId{};
		std::string m_sName{};
		std::string m_sDesc{};
		size_t m_stSerialNum{};
		size_t m_stQuantity{};
		static size_t s_stWidthField;
		static size_t s_stIdGenerator;
	public:
		Station(const std::string& record);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}

#endif // !SDDS_STATION_H
