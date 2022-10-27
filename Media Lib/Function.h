#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Media.h"

void readFile(vector<Media>& m);
//pre: Reads the csv file with an empty media type vector
//post: Loads Media type vector

void printVector(vector<Media> m);