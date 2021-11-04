/* 
Name: Yousef Majidinejad
Seneca Student ID: 101306207
Seneca email: ymajidinejad@myseneca.ca
Date of completion: October 30, 2021
I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <string>

namespace sdds
{
	class Utilities
	{
		size_t m_stWidthField = 1;
		static char s_cDelimiter;
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}

#endif // !SDDS_UTILITIES_H
