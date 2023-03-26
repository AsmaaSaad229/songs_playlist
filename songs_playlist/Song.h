#pragma once
#include <string>
#include <tuple>
#include <iomanip>
class Song
{
	friend std::ostream& operator<<(std::ostream& os, const Song& s);
	friend bool operator == (Song& lhs, Song& rhs);
	friend bool operator < (Song& lhs, Song& rhs);

	std::string name;
	std::string artist;
	const int rating;
public:
	Song() = default;
	Song(std::string name, std::string artist, int rating);

	std::string get_name()const {
		return name;
	}
	std::string get_artist() const{
		return artist;
	}
	int get_rating() const{
		return rating;
	}
};

