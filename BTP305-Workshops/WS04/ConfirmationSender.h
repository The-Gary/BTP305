/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 7, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_CONFIRMATION_SENDER_H
#define SDDS_CONFIRMATION_SENDER_H
#include <iostream>
#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** m_reservations{};
		size_t m_size{};
	public:
		ConfirmationSender(){};
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src) noexcept;
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender& operator=(ConfirmationSender&& src) noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		bool find(const Reservation& res) const;
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src);
		~ConfirmationSender()
		{
			delete[] m_reservations;
		};
	};
}
#endif // !SDDS_CONFIRMATION_SENDER_H

