/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 6, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include "Restaurant.h"

namespace sdds
{
	// stores copies of all reservations received as param
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		this->m_count = cnt;
		this->m_res = new Reservation[this->m_count];
		for (auto i = 0u; i < this->m_count; ++i)
		{
			this->m_res[i] = *reservations[i];
		}
	}

	// copy constructor
	Restaurant::Restaurant(const Restaurant& src)
	{
		*this = src;
	}

	// move constructor
	Restaurant::Restaurant(Restaurant&& src) noexcept
	{
		*this = std::move(src);
	}

	// copy-assignment operator
	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		if (this != &src)
		{
			this->m_count = src.m_count;
			delete[] this->m_res;
			this->m_res = new Reservation[this->m_count];
			for (auto i = 0u; i < this->m_count; ++i)
			{
				this->m_res[i] = src.m_res[i];
			}
		}
		return *this;
	}

	// move-assignment operator
	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept
	{
		if (this != &src)
		{
			this->m_count = src.m_count;
			delete[] this->m_res;
			this->m_res = src.m_res;
			src.m_count = 0;
			src.m_res = nullptr;
		}
		return *this;
	}

	size_t Restaurant::size() const
	{
		return this->m_count;
	}
	
	// destructor
	Restaurant::~Restaurant()
	{
		delete[] this->m_res;
	}

	// inserts the content of a Restaurnt object into an ostream object
	std::ostream& operator<<(std::ostream& os, const Restaurant& rest)
	{
		static size_t CALL_CNT = 0;
		++CALL_CNT;
		auto size = rest.size();

		os << "--------------------------\n"
			<< "Fancy Restaurant (" << CALL_CNT << ")\n"
			<< "--------------------------\n";

		if (size == 0)
		{
			os << "This restaurant is empty!\n"
				<< "--------------------------\n";
		}
		else
		{
			for (auto i = 0u; i < size; ++i)
			{ 
				os << rest.m_res[i];
			}
			os << "--------------------------\n";
		}
		return os;
	}
}