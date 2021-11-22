// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		November 18, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <memory>
#include <algorithm>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); i++)
			for (size_t j = 0; j < price.size(); j++)
				if (desc[i].code == price[j].code)
				{
					auto* newProduct = new Product(desc[i].desc, price[j].price);
					newProduct->validate();
					priceList += newProduct;
					delete newProduct;
				}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); i++)
			for (size_t j = 0; j < price.size(); j++)
				if (desc[i].code == price[j].code)
				{
					std::unique_ptr<Product> newProduct(new Product(desc[i].desc, price[j].price));
					newProduct->validate();
					priceList += newProduct;
				}
		return priceList;
	}
}