#include "Song.h"

Song::Song(std::string name, std::string artist, int rating):name{name}, artist{ artist }, rating{rating}{}

std::ostream& operator<<(std::ostream& os, const Song& s) {
	os <<  s.name <<s.artist << s.rating;
	return os;
}

bool operator==(Song &lhs, Song& rhs) {
	return std::tie(lhs.name, lhs.artist, lhs.rating)
		== std::tie(rhs.name, rhs.artist, rhs.rating);
}

bool operator < (Song& lhs, Song& rhs) {
	return std::tie(lhs.name, lhs.artist, lhs.rating)
		< std::tie(rhs.name, rhs.artist, rhs.rating);
}
