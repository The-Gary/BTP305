/*
Name: Yousef Majidinejad
Seneca Student ID: 101306207
Seneca email: ymajidinejad@myseneca.ca
Date of completion:
I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#include "Utilities.h"

namespace sdds
{
	char Utilities::s_cDelimiter = '\0';

	// sets the field width of the current object to the value of parameter newWidth
	void Utilities::setFieldWidth(size_t newWidth)
	{
		this->m_stWidthField = newWidth;
	}

	// returns the field width of the current object
	size_t Utilities::getFieldWidth() const
	{
		return this->m_stWidthField;;
	}

	// extracts a token from string str referred to by the first parameter
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string ret{};
		if (str.at(next_pos) == this->s_cDelimiter)
		{
			more = false;
			throw "Token found at position";
		}

		size_t idx = str.find(Utilities::s_cDelimiter, next_pos + 1);
		if (idx != std::string::npos)
		{
			size_t range = idx - next_pos;
			ret = str.substr(next_pos, range);
			next_pos = ++idx;
			more = true;
		}
		else
		{
			more = false;
			ret = str.substr(next_pos);
		}

		size_t length = ret.length();
		if (this->m_stWidthField < length)
			this->m_stWidthField = length;
		
		return ret;
	}
	
	// static: sets the delimiter for this class to the character received
	void Utilities::setDelimiter(char newDelimiter)
	{
		Utilities::s_cDelimiter = newDelimiter;
	}

	// static: returns the delimiter for this class
	char Utilities::getDelimiter()
	{
		return Utilities::s_cDelimiter;
	}
}