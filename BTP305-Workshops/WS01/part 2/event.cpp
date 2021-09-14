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
#include <cstring>
#include "event.h"
unsigned int g_sysClock = 0;
namespace sdds
{
	Event::Event() : m_desc {nullptr}
	{
	};

	Event::Event(const Event& other)
	{
		*this = other;
	}

	Event& Event::operator=(const Event& other)
	{
		if (this != &other) {
			this->m_time = other.m_time;
			delete[] this->m_desc;
			this->set(other.m_desc);
		}
		return *this;
	}

	Event::~Event()
	{
		delete[] this->m_desc;
	}

	void Event::display()const
	{
		static int counter{};
		++counter;
		if (this->m_desc) {
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
		if (name) {
			size_t nameLen = strlen(name);
			this->m_desc = new char[nameLen + 1];
			std::strcpy(this->m_desc, name);
			this->m_time = ::g_sysClock;
		}
		else {
			this->m_desc = nullptr;
			this->m_time = 0;
		}
	}
}