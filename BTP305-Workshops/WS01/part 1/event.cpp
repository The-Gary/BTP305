/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		September 12, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <iostream>
#include <iomanip>
#include "event.h"
unsigned int g_sysClock = 0;
namespace sdds
{
	Event::Event()
	{
		this->m_desc[0] = '\n';
		this->m_time = ::g_sysClock;
	};

	void Event::display()const
	{
		static int counter{};
		++counter;
		if (this->m_desc[0] != 0) {
			int hour = 0, min = 0, sec = 0;
			hour = this->m_time / 3600;
			min = (this->m_time / 60) % 60;
			sec = this->m_time % 60;
			auto def = std::cout.fill();
			std::cout << std::setw(2) << counter << ". ";
			std::cout.fill('0');
			std::cout<< std::setw(2) << hour << ":" << std::setw(2) << min << ":" << std::setw(2) << sec << " => ";
			std::cout.fill(def);
			for (auto i = 0; i < strlen(this->m_desc); ++i) {
				std::cout << this->m_desc[i];
			}
			std::cout << std::endl;
		}
		else {
			std::cout << std::setw(2) << counter << ". " << "| No Event |" << std::endl;
		}
	}

	void Event::set(char* name)
	{
		// TODO: correct the if condition below; missing "if array not empty"
		if (name) {
			std::strcpy(this->m_desc, name);
			this->m_time = ::g_sysClock;
		}
		else {
			this->m_desc[0] = 0;
			this->m_time = 0;
		}
	}
}