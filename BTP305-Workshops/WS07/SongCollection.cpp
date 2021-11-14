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
#include <numeric>
#include <string>
#include <list>
#include <iterator>
#include <cstring>

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
				newSong.m_title = extract(song, 0, 25);
				newSong.m_artist = extract(song, 25, 25);
				newSong.m_album = extract(song, 50, 25);
				this->trim(newSong.m_title);
				this->trim(newSong.m_artist);
				this->trim(newSong.m_album);
				try { newSong.m_year = std::stoi(extract(song, 75, 5)); }
				catch (...) { newSong.m_year = 0; };
				try { newSong.m_length = std::stoi(extract(song, 80, 5)); }
				catch (...) { newSong.m_length = 0; };
				try { newSong.m_price = std::stod(extract(song, 85, 5)); }
				catch (...) { newSong.m_price = 0.0; };
				this->m_songs.push_back(newSong);
			}
		}
		file.close();
	}

	void SongCollection::display(std::ostream& os)
	{
		std::for_each(this->m_songs.cbegin(), this->m_songs.cend(), [&os](const Song& song) { os << song << std::endl; });

		auto add = [](size_t sum, const Song& song) -> size_t
		{
			return sum += song.m_length;
		};
		size_t sum = std::accumulate(m_songs.cbegin(), m_songs.cend(), 0, add);
		
		auto hr = sum / 3600;
		auto min = (sum - hr * 3600) / 60;
		auto sec = (sum - hr * 3600) % 60;

		auto fill = os.fill();
		os << "----------------------------------------------------------------------------------------\n";
		os << "| " << std::setw(77) << std::right << "Total Listening Time: " << hr << ":"
			<< std::setw(2) << std::setfill('0') << min << ":" << std::setw(2) << sec << " |" << std::endl;;
		os.fill(fill);
	}

	void SongCollection::sort(const char* by)
	{
		auto compare = [&by](const Song& a, const Song& b)
		{
			if (strcmp(by, "title") == 0)
				return a.m_title < b.m_title;
			if (strcmp(by, "album") == 0)
				return a.m_album < b.m_album;
			if (strcmp(by, "length") == 0)
				return a.m_length < b.m_length;
			return false;
		};
		std::sort(this->m_songs.begin(), this->m_songs.end(), compare);
	}

	void SongCollection::cleanAlbum()
	{
		auto fixAlbum = [](Song& song) -> Song
		{
			if (song.m_album == "[None]")
				song.m_album = "";
			return song;
		};
		std::transform(m_songs.begin(), m_songs.end(), m_songs.begin(), fixAlbum);
	}

	bool SongCollection::inCollection(const char* artistName)
	{
		auto found = [artistName](const Song& song) -> bool
		{
			return song.m_artist == artistName;
		};
		auto result = std::find_if(m_songs.cbegin(), m_songs.cend(), found);
		return result != m_songs.cend();
	}

	std::list<Song> SongCollection::getSongsForArtist(const char* artistName) const
	{
		std::list<Song> ret{};
		std::copy_if(m_songs.begin(), m_songs.end(), std::back_inserter(ret),
					 [artistName](const Song& song) { return song.m_artist == artistName; });
		return ret;
	}

	std::ostream& operator<<(std::ostream& os, const Song& theSong)
	{
		auto fill = os.fill();
		os << "| " << std::setw(20) << std::left << theSong.m_title
			<< " | " << std::setw(15) << theSong.m_artist
			<< " | " << std::setw(20) << theSong.m_album
			<< " | " << std::setw(6) << std::right << ((theSong.m_year) ? std::to_string(theSong.m_year) : " ")
			<< " | " << theSong.m_length / 60 << ":" << std::setw(2) << std::setfill('0') << theSong.m_length % 60
			<< " | " << theSong.m_price << " |";
		os.fill(fill);
		return os;
	}
}