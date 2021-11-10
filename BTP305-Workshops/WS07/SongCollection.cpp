/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		November 9, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include "SongCollection.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

namespace sdds
{

	std::string SongCollection::extract(const std::string& song, size_t begin, size_t range)
	{
		return song.substr(begin, range);
	}

	void SongCollection::trim(std::string& str)
	{
		auto begin = str.find_first_not_of(' ');
		auto end = str.find_last_not_of(' ');
		auto range = end - begin + 1;
		str = str.substr(begin, range);
	}

	SongCollection::SongCollection(const char* fileName)
	{
		std::fstream file(fileName, std::ios::in);
		if (!file)
			throw 0;

		std::string song{};
		Song newSong{};

		while (file)
		{
			std::getline(file, song);
			if (file)
			{
				newSong.m_sTitle = extract(song, 0, 25);
				newSong.m_sArtist = extract(song, 25, 25);
				newSong.m_sAlbum = extract(song, 50, 25);
				this->trim(newSong.m_sTitle);
				this->trim(newSong.m_sArtist);
				this->trim(newSong.m_sAlbum);
				try { newSong.m_stYear = std::stoi(extract(song, 75, 5)); }
				catch (...) { newSong.m_stYear = 0; };
				try { newSong.m_stLength = std::stoi(extract(song, 80, 5)); }
				catch (...) { newSong.m_stLength = 0; };
				try { newSong.m_dPrice = std::stod(extract(song, 85, 5)); }
				catch (...) { newSong.m_dPrice = 0.0; };
				this->m_vSongs.push_back(newSong);
			}
		}
		file.close();
	}

	void SongCollection::display(std::ostream& os)
	{
		std::for_each(this->m_vSongs.cbegin(), this->m_vSongs.cend(), [&os](const Song& song) { os << song; });
	}

	std::ostream& operator<<(std::ostream& os, const Song& theSong)
	{
		auto fill = os.fill();
		os << "| " << std::setw(20) << std::left << theSong.m_sTitle
			<< " | " << std::setw(15) << theSong.m_sArtist
			<< " | " << std::setw(20) << theSong.m_sAlbum
			<< " | " << std::setw(6) << std::right << ((theSong.m_stYear) ? std::to_string(theSong.m_stYear) : " ")
			<< " | " << theSong.m_stLength / 60 << ":" << std::setw(2) << std::setfill('0') << theSong.m_stLength % 60
			<< " | " << theSong.m_dPrice << " |" << std::endl;
		os.fill(fill);
		return os;
	}
}