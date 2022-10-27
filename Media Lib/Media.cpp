#include "Media.h"

Media::Media() {
	char type = ' ';
	string title = " ";
	string keyName = " ";
	int rating = -1;
	string genre = " ";
	int length = -1;
	int yearReleased = -1;
}

Media::Media(string type, string title, string keyName, int rating, string genre, int length, int yearReleased) {
	string type = type;
	string title = title;
	string keyName = keyName;
	int rating = rating;
	string genre = genre;
	int length = length;
	int yearReleased = yearReleased;
}