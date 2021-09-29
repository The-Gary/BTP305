/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		September 28, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>

namespace sdds
{
	template<typename V, typename K>
	class Pair
	{
		V m_value{};
		K m_key{};
	public:
		Pair(){}; // default constructor 
		Pair(const K& key, const V& value);
		const V& value() const;
		const K& key() const;
		virtual void display(std::ostream& os) const;
	};

	// copies the values referred to by the parameteres into the instance variables
	template <typename V, typename K>
	Pair<V, K>::Pair(const K& key, const V& value)
	{
		this->m_key = key;
		this->m_value = value;
	}

	// returns the value component of the pair
	template<typename V, typename K>
	const V& Pair<V, K>::value() const
	{
		return this->m_value;
	}

	// returns the key component of the pair
	template<typename V, typename K>
	const K& Pair<V, K>::key() const
	{
		return this->m_key;
	}

	// inserts into stream os the key and the value of the pair
	template<typename V, typename K>
	void Pair<V, K>::display(std::ostream& os) const
	{
		os << this->m_key << " : " << this->m_value << std::endl;
	}

	// free helper: calls the member function display() on pair to insert a pair into the os
	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair)
	{
		pair.display(os);
		return os;
	}

}
#endif // !SDDS_PAIR_H
