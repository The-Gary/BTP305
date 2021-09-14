/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		September 12, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned int g_sysClock;

namespace sdds
{
	class Event
	{
		char* m_desc{};
		unsigned int m_time{};
	public:
		Event();
		Event(const Event& other);
		Event& operator=(const Event& other);
		~Event();
		void display()const;
		void set(char* name = nullptr);
	};
}

#endif
