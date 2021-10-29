/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 27, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (const auto& item : this->m_vehicles)
			{
				if (test(item))
				{
					vehicles.push_back(item);
				}
			}
		}
	};
}

#endif // !SDDS_AUTOSHOP_H
