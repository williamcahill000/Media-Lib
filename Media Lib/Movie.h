#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Media.h"


class Movie : public Media {
protected:
	vector<string> stars;
public:
	Movie(vector<string> s);
	vector<string> getStars()       { return stars; }
	void setStars(vector<string> s) { stars = s; }
};