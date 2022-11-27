#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Media.h"


class Movie : Media {
private:
	vector<string> stars;
public:
	vector<string> getStars();
	void setStars(vector<string> s);
};