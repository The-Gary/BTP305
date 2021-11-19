/*
Name: Yousef Majidinejad
Seneca Student ID: 101306207
Seneca email: ymajidinejad@myseneca.ca
Date of completion: November 19, 2021
I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#include <string>
#include <iostream>
#include "Workstation.h"
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds
{
	std::deque<CustomerOrder> pending{};
	std::deque<CustomerOrder> completed{};
	std::deque<CustomerOrder> incomplete{};

	Workstation::Workstation(const std::string& name) : Station(name) {};

	// fills the order at the front of the queue, if there are CustomerOrders in the queue; otherwise, does nothing
	void Workstation::fill(std::ostream& os)
	{
		if (!m_dqOrders.empty() && !m_dqOrders.front().isFilled())
		{
			m_dqOrders.front().fillItem(*this, os);
		}
	}

	/*	attempts to move the order at the front of the queue to the next station in the assembly line:
	 *		if there is no next station in the assembly line, then the order is moved into completed queue
	 *	if the order cannot be filled (not enough inventory), move the order to the next station.
	 *		if there is no next station in the assembly line, then the order is moved into incomplete queue
	 *	if an order has been moved, return true; false otherwise	*/
	bool Workstation::attemptToMoveOrder()
	{
		if (!m_dqOrders.empty())
		{
			CustomerOrder& currentOrder = m_dqOrders.front();
			

			bool allItemsFilled = currentOrder.isItemFilled(this->getItemName());
			/*if (allItemsFilled && !m_pNextStation) // all items are not filled and there is no next station
			{
				// then move order into the incomplete queue
				incomplete.push_back((std::move(currentOrder)));
				return true;
			}*/

			// if the item handled by the station is filled or the station is out of inventory
			// move order into the next station
			if (allItemsFilled || Station::getQuantity() == 0)
			{
				if (m_pNextStation)
				{
					*m_pNextStation += std::move(currentOrder);
					m_dqOrders.pop_front();
					return true;
				}

				bool isCompleted = currentOrder.isFilled();
				if (isCompleted) // order is filled
				{
					// move order into completed queue
					completed.push_back(std::move(currentOrder));
					m_dqOrders.pop_front();
					return true;
				}

				incomplete.push_back((std::move(currentOrder)));
				return true;
			}

		}
		return false;
	}

	// stores the address of the referenced Workstation object in the pointer to the m_pNextStation. Parameter defaults to nullptr.
	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}

	// returns the address of the next Workstation
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	// inserts the name of the Item for which the current object is responsible for into stream os following the format: ITEM_NAME --> NEXT_ITEM_NAME
	void Workstation::display(std::ostream& os) const
	{
		os << getItemName() << ((m_pNextStation == nullptr) ? " --> End of Line" : " --> " + m_pNextStation->getItemName()) << std::endl;
	}

	// moves the CustomerOrder referenced in parameter newOrder to the back of the queue
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_dqOrders.push_back(std::move(newOrder));
		return *this;
	}

}