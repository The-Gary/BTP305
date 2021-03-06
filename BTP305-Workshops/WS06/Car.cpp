/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 27, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Car.h"

namespace sdds
{
	Car::Car(std::istream& istr)
	{
		std::string field{};
		size_t idx{};

		istr.ignore(256, ',');
		getline(istr, this->m_maker, ',');
		getline(istr, field, ',');

		idx = field.find_first_not_of(' ');
		if (idx == std::string::npos)
			this->m_condition = 'n';
		else
		{
			char con = field.at(idx);
			if (con == 'n' || con == 'u' || con == 'b')
				this->m_condition = con;
			else
				throw "Invalid record!";
		}

		getline(istr, field, '\n');
		idx = field.find(',');
		if (idx != std::string::npos) // if ',' is found in the extracted field, put what is after the ',' back in the stream
		{
			std::string putback(field.substr(++idx));
			istr.putback('\n'); // getline removes the delimeter; must put it back first
			for (auto it = putback.cend() - 1; it != putback.cbegin(); --it) // put back in the reverse order of extraction
				istr.putback(*it);

			field = field.substr(0, idx);
		}
		try
		{
			this->m_topSpeed = std::stod(field);
		}
		catch(const std::invalid_argument&)
		{
			throw "Invalid record!";
		}
		
		size_t begin = this->m_maker.find_first_not_of(' ');
		size_t end = this->m_maker.find_last_not_of(' ');
		this->m_maker = this->m_maker.substr(begin, end - begin + 1);
	}

	std::string Car::condition() const
	{
		std::string ret{};
		if (this->m_condition == 'n')
			ret = "new";
		else if (this->m_condition == 'u')
			ret = "used";
		else
			ret = "broken";
		return ret;
	}

	double Car::topSpeed() const
	{
		return this->m_topSpeed;
	}
	void Car::display(std::ostream& out) const
	{
		out << "| " << std::setw(10) << std::right << this->m_maker << " | "
			<< std::setw(6) << std::left << this->condition() << " | "
			<< std::setw(6) << std::setprecision(2) << std::fixed << this->topSpeed() << " |";
	}
}