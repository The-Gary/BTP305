/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 6, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace sdds
{
	class Restaurant
	{
		Reservation* m_res{};
		size_t m_count{};
	public:
		Restaurant(){};
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& src);
		Restaurant(Restaurant&& src) noexcept;
		Restaurant& operator=(const Restaurant& src);
		Restaurant& operator=(Restaurant&& src) noexcept;
		size_t size() const;
		~Restaurant();
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& rest);
	};
}

#endif // !SDDS_RESTAURANT_H
