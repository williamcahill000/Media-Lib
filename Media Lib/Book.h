#pragma once
#include <iostream>
#include "Media.h"

class Book : Media {
protected:
	int weeksNYT;
public:
	Book();
	int getWeeks() { return weeksNYT; }
	void setWeeks(int w) { weeksNYT = w; }
	void incrementWeeks(int wi) { weeksNYT += wi; }
};