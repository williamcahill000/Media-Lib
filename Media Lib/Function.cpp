#include "Function.h"

void readFile(vector<Media>& m) {
	ifstream inFile;
	inFile.open("mediaList.csv");
	if (!inFile.is_open()) {
		cout << "Files did not open\n";
		return;
	}

	string inString, tempString;
	vector<string> tempV;

	getline(inFile, inString);
	while (inFile.good()) {
		stringstream inSS(inString);
		tempV.clear();
		while (getline(inSS, tempString, ',')) {
			tempV.push_back(tempString);
		}
		if (tempV[0] == "B") {
			tempV[0].c_str();
			Media tempMedia((tempV[0], tempV[1], tempV[2], stoi(tempV[3]), tempV[4], stoi(tempV[5]), stoi(tempV[6])));
			m.push_back(tempMedia);
			getline(inFile, inString);
			continue;
		}
	}
}


void printVector(vector<Media> m) {
	ofstream outFile;
	outFile.open("output.txt");
	if (!outFile.is_open()) {
		cout << "Error opening file\n";
		return;
	}

	for (int i = 0; i < m.size(); i++) {
		outFile << m[i].getTitle() << " " << m[i].getKeyName() << endl;
	}
}