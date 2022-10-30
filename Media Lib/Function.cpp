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
			try {
				int r = stoi(tempV[3]);
				int l = stoi(tempV[5]);
				int y = stoi(tempV[6]);
				Media tempMedia('B', tempV[1], tempV[2], r, tempV[4], l, y);

				m.push_back(tempMedia);
				getline(inFile, inString);
				continue;
			}
			catch (...) {
				cout << "Error: ";
				for (int i = 0; i < tempV.size(); i++) {
					cout << tempV[i] << ", ";
				}
				cout << endl;
				getline(inFile, inString);
				continue;
			}
		}
		if (tempV[0] == "M") {
			try {
				int r = stoi(tempV[3]);
				int l = stoi(tempV[5]);
				int y = stoi(tempV[6]);
				Media tempMedia('M', tempV[1], tempV[2], r, tempV[4], l, y);

				m.push_back(tempMedia);
				getline(inFile, inString);
				continue;
			}
			catch (...) {
				cout << "Error: ";
				for (int i = 0; i < tempV.size(); i++) {
					cout << tempV[i] << ", ";
				}
				cout << endl;
				getline(inFile, inString);
				continue;
			}
		}
		if (tempV[0] == "S") {
			try {
				int r = stoi(tempV[3]);
				int l = stoi(tempV[5]);
				int y = stoi(tempV[6]);
				Media tempMedia('S', tempV[1], tempV[2], r, tempV[4], l, y);

				m.push_back(tempMedia);
				getline(inFile, inString);
				continue;
			}
			catch (...) {
				cout << "Error: ";
				for (int i = 0; i < tempV.size(); i++) {
					cout << tempV[i] << ", ";
				}
				cout << endl;
				getline(inFile, inString);
				continue;
			}
		}
		if (tempV[0] == "Q") {
			break;
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

void printMenu(vector<Media> m) {
	bool quit = false;
	while (quit != true) {
		char choice;
		cout << "Welcome to the Media Library" << endl << endl;
		cout << "\t\tMenu Choices" << endl;
		cout << "M - Print Movie List" << endl;
		cout << "B - Print Book List" << endl;
		cout << "S - Print Song List" << endl;
		cout << "A - Print All Media" << endl;
		cout << "N - Add New Media" << endl;
		cout << "T - Print Media Counts" << endl;
		cout << "Q - Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
			case 'M':
				printMovieList(m);
				continue;
			case 'B':
				printBookList(m);
				continue;
			case 'S':
				printSongList(m);
				continue;
			case 'A':
				printList(m);
				continue;
			case 'T':
				printTotals(m);
				continue;
			case 'N':
				addContent(m);
				continue;
			case 'Q':
				break;
		}
	}
}

void printBookList(vector<Media> m) {
	cout << "\t\tYOUR BOOK LIST" << endl << endl;
	cout << "#\t\t   TITLE\t\tYEAR\  RATING" << endl;
	for (int i = 0; i < m.size(); i++) {
		if (m[i].getType() == 'B') {
			cout << i << " " << m[i].getTitle() << " " << m[i].getYearReleased() << " " << m[i].getRating() << endl;
		}
	}
	cout << endl;
}

void printSongList(vector<Media> m) {
	cout << "\t\tYOUR SONG LIST" << endl << endl;
	cout << "#\t\t   TITLE\t\tYEAR\  RATING" << endl;
	for (int i = 0; i < m.size(); i++) {
		if (m[i].getType() == 'S') {
			cout << i << " " << m[i].getTitle() << " " << m[i].getYearReleased() << " " << m[i].getRating() << endl;
		}
	}
	cout << endl;
}

void printMovieList(vector<Media> m) {
	cout << "\t\tYOUR MOVIE LIST" << endl << endl;
	cout << "#\t\t   TITLE\t\tYEAR\  RATING" << endl;
	for (int i = 0; i < m.size(); i++) {
		if (m[i].getType() == 'M') {
			cout << i << " " << m[i].getTitle() << " " << m[i].getYearReleased() << " " << m[i].getRating() << endl;
		}
	}
	cout << endl;
}

void printList(vector<Media> m) {
	cout << "\t\tYOUR BOOK LIST" << endl << endl;
	cout << "#\t\t   TITLE\t\tYEAR\  RATING" << endl;
	for (int i = 0; i < m.size(); i++) {
		if (m[i].getType() == 'B' || m[i].getType() == 'S' || m[i].getType() == 'M') {
			cout << i << " " << m[i].getTitle() << " " << m[i].getYearReleased() << " " << m[i].getRating() << endl;
		}
	}
	cout << endl;
}

void printTotals(vector<Media> m) {
	int movies = 0;
	int songs = 0;
	int books = 0;
	for (int i = 0; i < m.size(); i++) {
		if (m[i].getType() == 'B')
			books += 1;
		if (m[i].getType() == 'S')
			songs += 1;
		if (m[i].getType() == 'M')
			movies += 1;
	}
	cout << "YOUR MEDIA LIBRARY" << endl << endl;
	cout << "#\t TYPE" << endl;
	cout << movies << "\tMovies" << endl;
	cout << books << "\tBooks" << endl;
	cout << songs << "\tSongs" << endl;
	cout << (movies + books + songs) << "\tItems" << endl;
}

void addContent(vector<Media>& m) {
	char type;
	string title, name, genre;
	int rating, length, year;
	cout << "Enter the type of media you would like to add: ";
	cin >> type;
	cout << "Enter Title: ";
	cin >> title;
	cout << "Enter Name (Artist, director, author): ";
	cin >> name;
	cout << "Enter Genre: ";
	cin >> genre;
	cout << "Enter Rating: ";
	cin >> rating;
	cout << "Enter Length: ";
	cin >> length;
	cout << "Enter Year: ";	
	cin >> year;
	Media tempMedia(type, title, name, rating, genre, length, year);
	m.push_back(tempMedia);
	cout << title << " was added to your list";
}
