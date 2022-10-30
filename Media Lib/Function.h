#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Media.h"

void readFile(vector<Media>& m);
//pre: Reads the csv file with an empty media type vector
//post: Loads Media type vector

void printVector(vector<Media> m);
//pre: takes loaded media vector
//post: prints title and author

void printMenu(vector<Media> m);

void printBookList(vector<Media> m);

void printSongList(vector<Media> m);

void printMovieList(vector<Media> m);

void printList(vector<Media> m);

void printTotals(vector<Media> m);

void addContent(vector<Media>& m);