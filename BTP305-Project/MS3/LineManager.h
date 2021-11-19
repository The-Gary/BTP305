/*
Name: Yousef Majidinejad
Seneca Student ID: 101306207
Seneca email: ymajidinejad@myseneca.ca
Date of completion: November 19, 2021
I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#ifndef SDDS_LINE_MANAGER_H
#define SDDS_LINE_MANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include "Workstation.h"

namespace sdds
{
	class LineManager
	{
		std::vector<Workstation*> m_vActiveLine{};
		size_t m_stOrderCount{};
		Workstation* m_firstStation{};

	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif