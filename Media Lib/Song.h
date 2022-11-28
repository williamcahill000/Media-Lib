#pragma once
#include <iostream>
#include "Media.h"
#include "Book.h"
#include "Movie.h"

class Song : Book {
private:
	bool top40;
public:
	Song();
	int getWeeks() { return weeksNYT; }
	void setWeeks(int w) { weeksNYT = w; }
	void incrementWeeks(int wi) { weeksNYT += wi; }
};