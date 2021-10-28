/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 27, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include "Autoshop.h"

namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		this->m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";
		/*for (auto it = this->m_vehicles.cbegin(); it != this->m_vehicles.cend(); ++it)
			(*it)->display(out);*/ // -> alternative
		for (const auto& vehicle : this->m_vehicles)
			vehicle->display(out);
		out << "--------------------------------" << std::endl;
	}
}