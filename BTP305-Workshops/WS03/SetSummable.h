/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		September 28, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_SET_SUMMABLE_H
#define SDDS_SET_SUMMABLE_H

#include <string>
#include "Set.h"

namespace sdds
{
	template <size_t N, typename T>
	class SetSummable : public Set<N, T>
	{
	public:
		T accumulate(const std::string& filter) const;
	};

	// accumulates into a local object of type T the subset of all the elements in the collection that satisfy filter
	template <size_t N, typename T>
	T SetSummable<N, T>::accumulate(const std::string& filter) const
	{
		T localObj(filter);
		size_t size = this->size();
		for (size_t i = 0; i <= size; ++i) {
			if (this->get(i).isCompatibleWith(localObj)) {
				localObj += this->get(i);
			}
		}
		return localObj;
	}
}

#endif // !SDDS_SET_SUMMABLE_H
