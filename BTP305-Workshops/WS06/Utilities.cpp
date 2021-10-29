/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 27, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <iostream>
#include <string>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* ret = nullptr;
		std::string field{};
		std::getline(in, field, ',');

		size_t idx = field.find_first_not_of(' ');
		if (idx != std::string::npos)
		{
			char tag = field.at(idx);
			if (tag == 'c' || tag == 'C')
			{
				ret = new Car(in);
				//in.ignore();
			}
			else if (tag == 'r' || tag == 'R')
			{
				ret = new Racecar(in);
				//in.ignore();
			}
			else
			{
				in.ignore(256, '\n');
				std::string err("Unrecognized record type: [");
				err += tag;
				err += "]";
				throw err;
			}
		}
		return ret;
	}
}