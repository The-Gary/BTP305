/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		September 22, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <chrono>
#include <string>
#include <iostream>

#ifndef SDDS_TIMED_EVENT_H
#define SDDS_TIMED_EVENT_H

const int MAX_EVENTS = 10;
namespace sdds
{
	class TimedEvents
	{
		int m_nRecords{};
		std::chrono::steady_clock::time_point m_startTime{};
		std::chrono::steady_clock::time_point m_endTime{};
		struct Event
		{
			std::string m_eventName{};
			std::string m_timeUnit{};
			std::chrono::steady_clock::duration m_eventDuration{};
		};
		Event m_eventsArr[MAX_EVENTS]{};
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char*);
		friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
	};
}

#endif // !TIMED_EVENET_H
