/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		September 28, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds
{
	template <size_t N, typename T>
	class Set
	{
		T m_element[N]{};
		size_t m_numOfElements{};
	public:
		size_t size() const;
		const T& get(size_t idx) const;
		void operator +=(const T& item);
	};

	// returns the current number of elements in the collection
	template<size_t N, typename T>
	size_t Set<N, T>::size() const
	{
		return this->m_numOfElements;
	}

	// returns a reference to the element at the index idx of the statically allocated array (assume the parameter is valid)
	template<size_t N, typename T>
	const T& Set<N, T>::get(size_t idx) const
	{
		return this->m_element[idx];
	}

	// if the collection has the capacity for another element, adds a copy of item to the collection, otherwise does nothing
	template<size_t N, typename T>
	void Set<N, T>::operator+=(const T& item)
	{
		if (this->m_numOfElements < N) {
			this->m_element[this->m_numOfElements] = item;
			++this->m_numOfElements;
		}
		else {
			return;
		}
	}
}

#endif // !SDDS_SET_H