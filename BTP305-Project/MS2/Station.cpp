/*
Name: Yousef Majidinejad
Seneca Student ID: 101306207
Seneca email: ymajidinejad@myseneca.ca
Date of completion: October 30, 2021
I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace sdds
{
	
	size_t Station::s_stWidthField = 0;
	size_t Station::s_stIdGenerator = 0;

	Station::Station(const std::string& record)
	{
		Utilities util{};
		size_t next_pos = 0;
		bool more = true;

		// set ID
		++Station::s_stIdGenerator;
		this->m_iId = Station::s_stIdGenerator;

		// extract name, serial number, quantity, and update length if necessary and finally extract description
		this->m_sName = util.extractToken(record, next_pos, more);
		this->m_stSerialNum = std::stoi(util.extractToken(record, next_pos, more));
		this->m_stQuantity = std::stoi(util.extractToken(record, next_pos, more));
		size_t length = util.getFieldWidth();
		if (Station::s_stWidthField < length)
			Station::s_stWidthField = length;
		this->m_sDesc = util.extractToken(record, next_pos, more);
	}

	// returns the name of the current Station object
	const std::string& Station::getItemName() const
	{
		return this->m_sName;
	}

	// returns the next serial number to be used on the assembly line and increments m_serialNumber
	size_t Station::getNextSerialNumber()
	{
		return this->m_stSerialNum++;
	}

	// returns the remaining quantity of items in the Station object
	size_t Station::getQuantity() const
	{
		return this->m_stQuantity;
	}

	// subtracts 1 from the available quantity; should not drop below 0.
	void Station::updateQuantity()
	{
		if (this->m_stQuantity > 0)
			--this->m_stQuantity;
	}

	// inserts information about the current object into stream os
	void Station::display(std::ostream & os, bool full) const
	{
		auto fill = os.fill();
		os << "[" << std::setfill('0') << std::setw(3) << std::right << this->m_iId << "] Item: ";
		os << std::setfill(fill) << std::setw(Station::s_stWidthField) << std::left << this->m_sName;
		os << " [" << std::setfill('0') << std::setw(6) << std::right << this->m_stSerialNum << "]";
		os.fill(fill);

		if (full)
		{
			os << std::left << " Quantity: " << std::setw(Station::s_stWidthField) << this->m_stQuantity;
			os << " Description: " << this->m_sDesc << std::endl;
		}
		else
		{
			os << std::endl;
		}
	}

}