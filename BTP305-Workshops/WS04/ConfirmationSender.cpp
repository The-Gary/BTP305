/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 7, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <iostream>
#include "ConfirmationSender.h"

namespace sdds
{
	// copy constructor
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}

	// move constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept
	{
		*this = std::move(src);
	}

	//copy-assignment operator
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src)
		{
			this->m_size = src.m_size;
			delete[] this->m_reservations;
			this->m_reservations = new const Reservation*[this->m_size];
			for (size_t i = 0; i < this->m_size; ++i)
			{
				this->m_reservations[i] = src.m_reservations[i];
			}
		}
		return *this;
	}

	// move-assignment operator
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept
	{
		if (this != &src)
		{
			this->m_size = src.m_size;
			delete[] this->m_reservations;
			this->m_reservations = src.m_reservations;
			src.m_size = 0;
			src.m_reservations = nullptr;
		}
		return *this;
	}

	// adds the reservation res to the array of reservation itself
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		if (!this->find(res))
		{
			// make a new resized array of Reservations pointers
			const Reservation** resized = new const Reservation*[this->m_size + 1];
			// copy each index of current instance's array into the new resized array
			for (auto i = 0u; i < this->m_size; ++i)
			{
				resized[i] = this->m_reservations[i];
			}
			// delete current instance's array
			delete[] this->m_reservations;
			// point m_reservations to the resized array
			this->m_reservations = resized;
			// add the address of parameter res to the last index of resized array
			this->m_reservations[this->m_size] = &res;
			// update array size
			++this->m_size;
		}
		return *this;
	}

	// removes the reservation res from the array by skipping copying it into resized
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		if (this->find(res))
		{
			const Reservation** resized = new const Reservation*[this->m_size - 1];
			auto j = 0u; // this counter keeps track which index needs to be skipped when copying into resized
			for (auto i = 0u; i < this->m_size; ++i)
			{
				if (this->m_reservations[i] != &res)
				{
					resized[j] = this->m_reservations[i];
					++j;
				}
			}
			delete[] this->m_reservations;
			this->m_reservations = resized;
			--this->m_size;
		}
		return *this;
	}

	// searches the array of reservations* and returns true if the address of res exists in the array
	inline bool ConfirmationSender::find(const Reservation& res) const
	{
		bool match = false;
		if (this->m_size > 0)
		{
			for (auto i = 0u; i < this->m_size && !match; ++i)
			{
				match = (this->m_reservations[i] == &res);
			}
		}
		return match;
	}

	// inserts the content of a ConfirmationSender into an ostream object
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src)
	{
		os << "--------------------------\n"
			<< "Confirmations to Send\n"
			<< "--------------------------\n";
		if (src.m_size == 0)
		{
			os << "There are no confirmations to send!\n"
				<< "--------------------------\n";
		}
		else
		{
			for (auto i = 0u; i < src.m_size; ++i)
			{
				os << *src.m_reservations[i];
			}
			os << "--------------------------\n";
		}
			
		return os;
	}

}
