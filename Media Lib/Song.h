#pragma once
#include <iostream>
#include "Media.h"

class Song : Media {
private:
	bool top40;
public:
	int getWeeks();
	void setWeeks(int w);
	void incrementWeeks(int wi);
};