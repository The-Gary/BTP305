/*
Name:		Yousef Majidinejad
Student ID:	101306207
Email:		ymajidinejad@myseneca.ca
Section:	NAA
Date:		November 9, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_SONG_COLLECTION_H
#define SDDS_SONG_COLLECTION_H

#include <string>
#include <vector>
#include <iostream>

namespace sdds
{
	struct Song
	{
		std::string m_sArtist{};
		std::string m_sTitle{};
		std::string m_sAlbum{};
		double m_dPrice{};
		size_t m_stYear{};
		size_t m_stLength{};
	};

	class SongCollection
	{
		std::vector<Song> m_vSongs{};
		std::string extract(const std::string& song, size_t begin, size_t range);
		void trim(std::string& str);
	public:
		SongCollection(const char* fileName);
		void display(std::ostream& os);
	};

	std::ostream& operator<<(std::ostream& os, const Song& theSong);
}

#endif