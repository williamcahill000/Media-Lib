#include <string>
#include <iostream>
#include "Media.h" 
#include "song.h"
using namespace std;

Music::Music()
	:Media()
{
	//uses Media constructor as well as class specific items. Default
	artist = "";
	duration = 0;
}

Music::Music(char type, string t, string a, int r, string g, int p, int yr)
	:Media(type, t, r, yr, g)
{
	//uses Media constructor as well as class specific items
	artist = a;
	duration = p;
}
//  all getters & setters (from .h file) need to be added 
void    Music::setArtist(string art) {
	artist = art;
}
void    Music::setDuration(int dur) {
	duration = dur;
}
string  Music::getArtist() {
	return artist;
}
int     Music::getDuration() {
	return duration;
}
void Music::print() { return; }
void Music::print(ostream& o) { return; }