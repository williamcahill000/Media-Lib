#pragma once
#include <iostream>
#include "Media.h"

class Book : Media {
private:
	int weeksNYT;
public:
	int getWeeks();
	void setWeeks(int w);
	void incrementWeeks(int wi);
};