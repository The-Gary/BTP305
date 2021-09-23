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
#include <iomanip>
#include "TimedEvents.h"

namespace sdds
{
	TimedEvents::TimedEvents()
	{
	};

	void TimedEvents::startClock()
	{
		this->m_startTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		this->m_endTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* name)
	{
		if (this->m_nRecords < MAX_EVENTS) {
			this->m_eventsArr[this->m_nRecords].m_eventName = name;
			this->m_eventsArr[this->m_nRecords].m_timeUnit = "nanoseconds";
			auto nanoSeconds = std::chrono::duration_cast<std::chrono::nanoseconds>(this->m_endTime - this->m_startTime);
			this->m_eventsArr[this->m_nRecords].m_eventDuration = nanoSeconds;
			++this->m_nRecords;
		}
	}

	std::ostream& operator<<(std::ostream& ostr, const TimedEvents& events)
	{
		ostr << "--------------------------\n";
		ostr << "Execution Times:\n";
		ostr << "--------------------------\n";

		for (auto i = 0; i < events.m_nRecords; ++i) {
			ostr << std::setw(21) << std::left << events.m_eventsArr[i].m_eventName << ' ';
			ostr << std::setw(13) << std::right << events.m_eventsArr[i].m_eventDuration.count() << ' ';
			ostr << events.m_eventsArr[i].m_timeUnit << '\n';
			ostr << "--------------------------\n";
		}
		return ostr;
	}
}