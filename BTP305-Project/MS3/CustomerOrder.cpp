/*
Name: Yousef Majidinejad
Seneca Student ID: 101306207
Seneca email: ymajidinejad@myseneca.ca
Date of completion: November 3, 2021
I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#include <string>
#include <iostream>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Station.h"

namespace sdds
{
	size_t CustomerOrder::s_stWidthField = 0;

	CustomerOrder::CustomerOrder(const std::string& src) 
	{
		Utilities util{};
		size_t next_pos = 0;
		bool more = true;

		// extract customer name and product name
		this->m_sName = util.extractToken(src, next_pos, more);
		this->m_sProduct = util.extractToken(src, next_pos, more);

		// count how many items are to be retrieved
		char c = util.getDelimiter();
		for (auto i = next_pos; i < src.length() ; ++i)
			this->m_stCntItem += (src[i] == c);

		// allocate memory and populate items
		this->m_pLstItem = new Item*[++m_stCntItem];
		for (auto i = 0u; i < this->m_stCntItem; ++i)
		{
			const std::string& itemName = util.extractToken(src, next_pos, more);
			this->m_pLstItem[i] = new Item(itemName);
		}

		// update width
		auto width = util.getFieldWidth();
		if (CustomerOrder::s_stWidthField < width)
			CustomerOrder::s_stWidthField = width;
	}

	// copy ctor
	CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		throw "copying is not allowed";
	}

	// move ctor
	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}

	// move assignment
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src)
		{
			for (auto i = 0u; i < this->m_stCntItem ; i++)
				delete this->m_pLstItem[i];

			delete[] this->m_pLstItem;
			this->m_pLstItem = src.m_pLstItem;
			this->m_sName = src.m_sName;
			this->m_sProduct = src.m_sProduct;
			this->m_stCntItem = src.m_stCntItem;
			
			src.m_pLstItem = nullptr;
			src.m_sName.clear();
			src.m_sProduct.clear();
			src.m_stCntItem = 0;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		for (auto i = 0u; i < this->m_stCntItem ; i++)
			delete this->m_pLstItem[i];
		delete[] this->m_pLstItem;
	}

	// returns true if all the items in the order have been filled; false otherwise
	bool CustomerOrder::isFilled() const
	{
		bool ret = true;
		for (auto i = 0u; i < m_stCntItem && ret ; i++)
			if (!m_pLstItem[i]->m_isFilled)
				ret = false;
		return ret;
	}

	// returns true if all items specified by itemName have been filled. if the item doesn't exist in the order, it returns true
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool ret = true;
		for (auto i = 0u; i < m_stCntItem && ret; i++)
			if (m_pLstItem[i]->m_sItemName == itemName)
				if (!m_pLstItem[i]->m_isFilled)
					ret = false;
		return ret;
	}

	// if the order contains an item handled by the station, it fills all items in the order
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		const std::string& itemName = station.getItemName();
		auto quantity = station.getQuantity();

		for (size_t i = 0; i < m_stCntItem; i++)
		{
			// determine if the current order contains an item handled by the station
			if (m_pLstItem[i]->m_sItemName == itemName)
			{
				if (quantity > 0)
				{
					station.updateQuantity();

					m_pLstItem[i]->m_stSerialNumer = station.getNextSerialNumber();
					m_pLstItem[i]->m_isFilled = true;

					os << "    Filled " << m_sName << ", " << m_sProduct << " [" << itemName << "]" << std::endl;
				}
				else if (quantity == 0 && !m_pLstItem[i]->m_isFilled)
					os << "    Unable to fill " << m_sName << ", " << m_sProduct << " [" << itemName << "]" << std::endl;
			}
		}
	}

	// displays the state of the current object
	void CustomerOrder::display(std::ostream& os) const
	{
		auto fill = os.fill();
		os << m_sName << " - " << m_sProduct << '\n';
		for (auto i = 0u; i < m_stCntItem ; i++)
		{
			os << "[" << std::setw(6) << std::right << std::setfill('0') << m_pLstItem[i]->m_stSerialNumer << "] "
				<< std::setfill(fill) << std::left << std::setw(CustomerOrder::s_stWidthField) 
				<< m_pLstItem[i]->m_sItemName << " - "
				<< ((m_pLstItem[i]->m_isFilled) ? "FILLED" : "TO BE FILLED") << std::endl;
		}
	}

}