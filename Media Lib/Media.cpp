#include "Media.h"

Media::Media() {
	type = ' ';
	title = " ";
	keyName = " ";
	rating = -1;
	genre = " ";
	length = -1;
	yearReleased = -1;
}

Media::Media(char type, string title, string keyName, int rating, string genre, int length, int yearReleased) {
	this->type = type;
	this->title = title;
	this->keyName = keyName;
	this->rating = rating;
	this->genre = genre;
	this->length = length;
	this->yearReleased = yearReleased;
}