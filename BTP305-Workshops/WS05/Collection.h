/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		October 11, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>
#include <iostream>

namespace sdds
{
	template<typename T>
	class Collection
	{
		std::string m_name{};
		T* m_objects{};
		size_t m_size{};
		void (*m_observer)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection(){};
		Collection(const std::string& name) : m_name{ name }{};
		Collection(const Collection<T>&) = delete;
		Collection(Collection<T>&&) = delete;
		~Collection(){ delete[] this->m_objects; };
		Collection<T>& operator=(const Collection<T>&) = delete;
		Collection<T>& operator=(Collection<T>&&) = delete;
		const std::string& name() const;
		size_t size() const;
		void setObserver(void(*observer)(const Collection<T>&, const T&));
		Collection<T>& operator+=(const T& item);
		T& operator[](size_t idx) const;
		T* operator[](const std::string& title) const;
		friend std::ostream& operator<<(std::ostream& os, const Collection<T>& src)
		{
			for (auto i = 0u; i < src.m_size; ++i)
			{
				os << src.m_objects[i];
			}
			return os;
		};
	};

	template<typename T>
	inline const std::string& Collection<T>::name() const
	{
		return this->m_name;
	}

	template<typename T>
	inline size_t Collection<T>::size() const
	{
		return this->m_size;
	}

	template<typename T>
	inline void Collection<T>::setObserver(void(*observer)(const Collection<T>&, const T&))
	{
		this->m_observer = observer;
	}

	template<typename T>
	inline Collection<T>& Collection<T>::operator+=(const T & item)
	{
		bool found = false;
		for (auto i = 0u; i < this->m_size && !found; ++i)
		{
			found = (this->m_objects[i].title() == item.title());
		}

		if (!found)
		{
			T* resized = new T[this->m_size + 1];
			for (auto i = 0u; i < this->m_size; ++i)
			{
				resized[i] = this->m_objects[i];
			}
			delete[] this->m_objects;
			resized[this->m_size] = item;
			this->m_objects = resized;
			++this->m_size;
			if (m_observer)
			{
				this->m_observer(*this, item);
			}
		}
		return *this;
	}

	template<typename T>
	inline T& Collection<T>::operator[](size_t idx) const
	{
		if (idx >= this->m_size)
		{
			throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(this->m_size) + "] items.");
		}
		return this->m_objects[idx];
		
	}

	template<typename T>
	inline T* Collection<T>::operator[](const std::string& title) const
	{
		T* ret = nullptr;
		for (auto i = 0u; i < this->m_size; ++i)
		{
			if (this->m_objects[i].title() == title)
			{
				ret = &this->m_objects[i];
				break;
			}
		}
		return ret;
	}

}
#endif // !SDDS_COLLECTION_H
