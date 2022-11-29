#pragma once
#include <vector>
#include "Media.h"
using namespace std;

int  readData(istream& i, ostream& o, vector<Media*>& m);
char menu();
void printList(vector<Media*>& cinema, char type, string word);
void printList(vector<Media*>& cinema);
vector<string> starsFromMovies(vector<Media*>& cinema, string tempMovieName);
vector<string> moviesFromStar(vector<Media*>& cinema, string tempStarName);