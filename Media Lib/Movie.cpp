#include <string>
#include <iostream>
#include "Media.h" 
#include "Movie.h"
using namespace std;

Movie::Movie()
	:Media()
{
	//uses Media constructor as well as class specific items. Default
	director = " ";
	duration = 0;
	stars = {};
}

Movie::Movie(char type, string t, string a, int r, string g, int d, int yr, vector<string> s)
	: Media(type, t, r, yr, g)
{
	//uses Media constructor as well as class specific items
	director = a;
	duration = d;
	stars = s;
}

//  all getters & setters (from .h file) need to be added 
void Movie::setDirector(string d) {
	director = d;
}
void Movie::setDuration(int dur) {
	duration = dur;
}
void Movie::setStars(vector<string> starList) {
	stars = starList;
}
string  Movie::getDirector() {
	return director;
}
int     Movie::getDuration() {
	return duration;
}
vector<string> Movie::getStars() {
	return stars;
}
void			Movie::print(ostream& o) {
	o << "Movie: " << title << " : " << director << endl;
}