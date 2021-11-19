/*
Name: Yousef Majidinejad
Seneca Student ID: 101306207
Seneca email: ymajidinejad@myseneca.ca
Date of completion: November 19, 2021
I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include <string>
#include <iostream>
#include "CustomerOrder.h"
#include "Station.h"
namespace sdds
{
	extern std::deque<CustomerOrder> pending;
	extern std::deque<CustomerOrder> completed;
	extern std::deque<CustomerOrder> incomplete;

	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_dqOrders{};
		Workstation* m_pNextStation{};
	public:
		Workstation(const std::string& name);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator +=(CustomerOrder&& newOrder);

		// moving or copying the object not allowed
		Workstation(const Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation& operator=(Workstation&&) = delete;
	};
}
#endif