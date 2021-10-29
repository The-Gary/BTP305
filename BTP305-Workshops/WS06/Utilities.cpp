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
#include <sstream>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* ret = nullptr;
		std::string sRecord{};
		std::stringstream record;

		std::getline(in, sRecord, '\n');
		record << sRecord;

		size_t idx = sRecord.find_first_not_of(' ');
		if (idx != std::string::npos)
		{
			char tag = sRecord.at(idx);
			if (tag == 'c' || tag == 'C')
				ret = new Car(record);

			else if (tag == 'r' || tag == 'R')
				ret = new Racecar(record);

			else
			{
				std::string err("Unrecognized record type: [");
				err += tag;
				err += "]";
				throw err;
			}
		}
		return ret;
	}
}