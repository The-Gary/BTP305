/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		September 28, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_PAIR_SUMMABLE_H
#define SDDS_PAIR_SUMMABLE_H

#include <iomanip>
#include "Pair.h"

namespace sdds
{
	template <typename V, typename K>
	class PairSummable : public Pair<V, K>
	{
		static V s_sumValue;			// holds the initial value for the summation
		static size_t s_minWidth;		// minimum field width for columnar output; updated every time a new pair is constructed
	public:
		PairSummable(){};
		PairSummable(const K& key, const V& value = {});
		bool isCompatibleWith(const PairSummable<V, K>& b) const;
		PairSummable<V, K>& operator+=(const PairSummable<V, K>& right);
		void display(std::ostream& os) const override;
	};

	
	template<typename V, typename K>
	V PairSummable<V, K>::s_sumValue{};

	template<typename V, typename K>
	size_t PairSummable<V, K>::s_minWidth{};
	
	// calls the base class constructor passing the two parameters to it and updates the field width if necessary
	template <typename V, typename K>
	PairSummable<V, K>::PairSummable(const K& key, const V& value) : Pair<V, K>(key, value) // Pair<V, K>(key, value)
	{
		s_sumValue = {};
		if (s_minWidth < key.size()) {
			s_minWidth = key.size();
		}
	}

	// returns true if the parameter has the same key as the current object, false otherwise
	template<typename V, typename K>
	bool PairSummable<V, K>::isCompatibleWith(const PairSummable<V, K>& b) const
	{
		return (this->key() == b.key());
	}

	// adds the value of the parameter object to the value of the current object and returns a reference to the current object.
	// assumes the current object and the parameter object have the same key
	template<typename V, typename K>
	PairSummable<V, K>& PairSummable<V, K>::operator+=(const PairSummable<V, K>& src)
	{
		// 
		*this = PairSummable(src.key(), this->value() + src.value());
		return *this;
	}
	
	// specialization:
	// for V = std::string and K = std::string, concatenates the values stored using ", " as a separtor
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& src)
	{
		*this = PairSummable(src.key(), s_sumValue + src.value());
		s_sumValue = this->value() + ", ";
		return *this;
	}

	// sets the alignment to left and the field width to the value of the static attribute for all K types
	// then calls the base class version of display(), and finally restore allignment to right
	template<typename V, typename K>
	void PairSummable<V, K>::display(std::ostream& os) const
	{
		os << std::left << std::setw(PairSummable<V, K>::s_minWidth);
		this->Pair<V, K>::display(os);
		os << std::right;
	}

}

#endif // !SDDS_PAIR_SUMMABLE_H


