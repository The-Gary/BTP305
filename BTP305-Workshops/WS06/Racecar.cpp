/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 27, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <sstream>
#include "Racecar.h"
#include "Car.h"

namespace sdds
{
	Racecar::Racecar(std::istream& in) : Car::Car(in)
	{
		std::string field{};
		std::getline(in, field, '\n');
		
		try
		{
			this->m_booster = std::stod(field);
		}
		catch (const std::invalid_argument&)
		{
			// if stod() fails, m_booster remains 0.0; nothing needs to happen.
		}
	}
	void Racecar::display(std::ostream & out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		double ret = Car::topSpeed();
		ret *= 1 + this->m_booster;
		return ret;
	}
}