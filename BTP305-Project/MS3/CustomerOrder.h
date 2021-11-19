/*
Name: Yousef Majidinejad
Seneca Student ID: 101306207
Seneca email: ymajidinejad@myseneca.ca
Date of completion: November 3, 2021
I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#ifndef SDDS_CUSTOMER_ORDER_H
#define SDDS_CUSTOMER_ORDER_H
#include <string>
#include <iostream>
#include "Station.h"

namespace sdds
{
	class CustomerOrder
	{
		struct Item
		{
			std::string m_sItemName{};
			size_t m_stSerialNumer{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_sItemName(src) {};
		};

		std::string m_sName{};
		std::string m_sProduct{};
		size_t m_stCntItem{};
		Item** m_pLstItem{};
		static size_t s_stWidthField;

	public:
		CustomerOrder() = default;
		CustomerOrder(const std::string& src);
		CustomerOrder(const CustomerOrder& src);					// copy ctor; throws exception
		CustomerOrder(CustomerOrder&& src) noexcept;				// move ctor
		CustomerOrder& operator=(const CustomerOrder&) = delete;	// copy assignment; not allowed
		CustomerOrder& operator=(CustomerOrder&& src) noexcept;		// move assignment
		~CustomerOrder();
	
	public:
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif // !SDDS_CUSTOMER_ORDER_H
