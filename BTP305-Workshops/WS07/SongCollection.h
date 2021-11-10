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
#include <list>

namespace sdds
{
	struct Song
	{
		std::string m_artist{};
		std::string m_title{};
		std::string m_album{};
		double m_price{};
		size_t m_year{};
		size_t m_length{};
	};

	class SongCollection
	{
		std::vector<Song> m_songs{};
		std::string extract(const std::string& song, size_t begin, size_t range);
		void trim(std::string& str);
	public:
		SongCollection(const char* fileName);
		void display(std::ostream& os);
		void sort(const char* by);
		void cleanAlbum();
		bool inCollection(const char* artistName);
		std::list<Song> getSongsForArtist(const char* artistName) const;
	};

	std::ostream& operator<<(std::ostream& os, const Song& theSong);
}

#endif