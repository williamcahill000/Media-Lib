#pragma once
#include <iostream>
#include <string>
using namespace std;

class Media {
private:
	char type;
	string title;
	string keyName;
	int rating;
	string genre;
	int length;
	int yearReleased;
public:
	Media();
	Media(string type, string title, string keyName, int rating, string genre, int length, int yearReleased);

	char getType()        { return type; }
	string getTitle()     { return title; }
	string getKeyName()   { return keyName; }
	int getRating()       { return rating; }
	string getGenre()     { return genre; }
	int getLength()       { return length; }
	int getYearReleased() { return yearReleased; }

	void setType(char t)         { type = t; }
	void setTitle(string t)      { title = t; }
	void setKeyName(string k)    { keyName = k; }
	void setRating(int r)        { rating = r; }
	void setGenre(string g)      { genre = g; }
	void setLength(int l)        { length = l; }
	void setYearReleased(int yr) { yearReleased = yr; }
};