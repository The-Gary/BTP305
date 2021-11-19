/*
Name: Yousef Majidinejad
Seneca Student ID: 101306207
Seneca email: ymajidinejad@myseneca.ca
Date of completion: November 19, 2021
I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Workstation.h"
#include "Utilities.h"

namespace sdds
{
	/*receives the name of the file that identifies the active stations on the assembly line (example: AssemblyLine.txt)
	 *and the collection of workstations available for configuring the assembly line.
	 *This function stores the workstations in the order received from the file in the activeLine instance variable.
	 *It loads the contents of the file, stores the address of the next workstation in each element of the collection,
	 *identifies the first station in the assembly line and stores its address in the m_firstStation attribute.
	 *This function also updates the attribute that holds the total number of orders in the pending queue.
	 *If something goes wrong, this constructor reports an error.**/
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		std::fstream fin(file);

		if (!fin)
			throw "Could not open file";

		std::string record{};
		std::string currentStation{}, nextStation{};
		size_t next_pos{};
		bool more{};

		Utilities::setDelimiter('|');
		Utilities util{};
		while (fin)
		{
			getline(fin, record);
			if (fin)
			{
				next_pos = 0;
				more = true;

				currentStation = util.extractToken(record, next_pos, more);
				auto it = std::find_if(stations.cbegin(), stations.cend(), [currentStation](const Workstation* ws) { return ws->getItemName() == currentStation; });
				m_vActiveLine.push_back(*it);

				if (more)
				{
					nextStation = util.extractToken(record, next_pos, more);
					it = std::find_if(stations.cbegin(), stations.cend(), [nextStation](const Workstation* ws) { return ws->getItemName() == nextStation; });
					m_vActiveLine.back()->setNextStation(*it);
				}
			}
		}

		// update order count
		m_stOrderCount = pending.size();

		// determine the first workstation
		std::for_each(m_vActiveLine.cbegin(), m_vActiveLine.cend(), [this](Workstation* ws)
					  {
						  const std::string& stationName = ws->getItemName();
						  auto search = [stationName](const Workstation* otherWs)
						  {
							  if (otherWs->getNextStation())
								  return stationName == otherWs->getNextStation()->getItemName();

							  return false;
						  };
						  bool found = std::any_of(m_vActiveLine.cbegin(), m_vActiveLine.cend(), search);
						  if (!found)
							  m_firstStation = ws;
					  });
		fin.close();
	}

	// reorders the workstations present in the instance variable activeLine (loaded by the constructor) 
	// and stores the reordered collection in the same instance variable. 
	// The elements in the reordered collection start with the first station, proceeds to the next, and so forth until the end of the line
	void LineManager::linkStations()
	{
		// bring the first station to the front of the queue
		auto search = [this](const Workstation* ws)
		{
			return ws->getItemName() == m_firstStation->getItemName();
		};

		if (m_vActiveLine.front()->getItemName() != m_firstStation->getItemName())
		{
			auto firstStation = std::find_if(m_vActiveLine.begin(), m_vActiveLine.end(), search);
			std::swap(m_vActiveLine.front(), *firstStation);
		}

		// link the rest of the stations
		// new vector, loop through old, find next station, push to new
		// in the end, clear old, then old = new
		for (auto& workstation : m_vActiveLine)
		{
			bool endOfLine = !workstation->getNextStation();
			const std::string& nextStationName = !endOfLine ? workstation->getNextStation()->getItemName() : "";

			auto found = std::find_if(m_vActiveLine.begin(), m_vActiveLine.end(), [nextStationName](const Workstation* ws)
									  {
										  return nextStationName == ws->getItemName();
									  });
			if (workstation->getNextStation())
			{
				auto nextStation = &workstation + 1;
				std::swap(*nextStation, *found);
			}
			if (m_vActiveLine.back()->getNextStation() == nullptr) // <-- not entirely sure if this is a good idea. could potentially produce a bug
				break; 
		}
	}

	bool LineManager::run(std::ostream& os)
	{
		static size_t RUN_CNT = 0;
		++RUN_CNT;

		os << "Line Manager Iteration: " << RUN_CNT << std::endl;

		if (!pending.empty())
		{
			*m_firstStation += std::move(pending.front());
			pending.pop_front();
		}
		for (const auto& ws : m_vActiveLine)
		{
			ws->fill(os);
		}
		for (const auto& ws : m_vActiveLine)
		{
			ws->attemptToMoveOrder();
		}
		if ((incomplete.size() + completed.size()) == m_stOrderCount)
			return true;
		return false;
	}

	void LineManager::display(std::ostream& os) const
	{
		std::for_each(m_vActiveLine.cbegin(), m_vActiveLine.cend(), [&os](const Workstation* ws) { ws->display(os); });
	}

}