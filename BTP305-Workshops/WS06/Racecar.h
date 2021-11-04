/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 27, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <iostream>
#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster = 0.0;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const override;
		double topSpeed() const override;
	};
}

#endif // !SDDS_RACECAR_H
