#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Media.h"

void readFile(vector<Media>& m);
//pre:Files are open in main and accessible
//post: Reads the data from csv file and loads into media vector and creates an error report.

void printMenu(vector<Media> m);
//pre: None
//post: Prints the menu for user to choose options and verifies correct option is chosen

void printBookList(vector<Media> m);
//pre: None
//post: Will print the appriopriate list

void printSongList(vector<Media> m);
//pre: None
//post: Will print the appriopriate list

void printMovieList(vector<Media> m);
//pre: None
//post: Will print the appriopriate list

void printList(vector<Media> m);
//pre: None
//post: Will print the appriopriate list

void printTotals(vector<Media> m);
//pre: None
//post: Prints the total count of movies, books and songs in the library

void addContent(vector<Media>& m);
//pre: None
//post: Prompt the user to enter the type of media to add. it will accept strings for all parameters.