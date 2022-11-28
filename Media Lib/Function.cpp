#include "Function.h"

void readFile(vector<Media>& m) {
	//Checks for csv file and if it's valid
	ifstream inFile;
	inFile.open("mediaList.txt");
	if (!inFile.is_open()) {
		cout << "Files did not open\n";
		return;
	}
	//Creates a output file for error records
	ofstream outFile;
	outFile.open("output.txt");
	if (!outFile.is_open()) {
		cout << "Error opening file\n";
		return;
	}
	//Reads the csv file and loads the media vector according to if it's a book, movie, or song (Inspired by file reading code from class and hotel project)
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
			//error checking, any errors records will be sent to outfile
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
				outFile << "Error: ";
				for (int i = 1; i < tempV.size(); i++) {
					outFile << tempV[i] << ", ";
				}
				outFile << endl;
				outFile << "previous record has an stoi error" << endl << endl;
				getline(inFile, inString);
				continue;
			}
		}
		if (tempV[0] == "M") {
			//error checking, any errors records will be sent to outfile
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
				outFile << "Error: ";
				for (int i = 1; i < tempV.size(); i++) {
					outFile << tempV[i] << ", ";
				}
				outFile << endl;
				outFile << "previous record has an stoi error" << endl << endl;
				getline(inFile, inString);
				continue;
			}
		}
		if (tempV[0] == "S") {
			//error checking, any errors records will be sent to outfile
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
				outFile << "Error: ";
				for (int i = 1; i < tempV.size(); i++) {
					outFile << tempV[i] << ", ";
				}
				outFile << endl;
				outFile << "previous record has an stoi error" << endl << endl;
				getline(inFile, inString);
				continue;
			}
		}
		if (tempV[0] == "Q") {
			break;
		}
	}
	outFile.close();
	inFile.close();
}

void printMenu(vector<Media> m) {
	bool quit = false;
	while (quit != true) {
		char choice;
		string movie;
		cout << endl;
		cout << "Welcome to the Media Library" << endl << endl;
		cout << "\t\tMenu Choices" << endl;
		cout << "M - Print Movie List" << endl;
		cout << "B - Print Book List" << endl;
		cout << "S - Print Song List" << endl;
		cout << "A - Print All Media" << endl;
		cout << "F - Find the Movie the Star is in" << endl;
		cout << "G - Print Stars for a Given Movie" << endl;
		cout << "N - Add New Media" << endl;
		cout << "T - Print Media Counts" << endl;
		cout << "Q - Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;
		//If an invalid choice is given for the menu it will loop and reshow the menu
		if (choice != 'M' && choice != 'B' && choice != 'S' && choice != 'A' && choice != 'T' && choice != 'N' && choice != 'F' && choice != 'G' && choice != 'Q') {
			cin.clear();
			cin.ignore();
			cout << "Bad input, use input as directed!" << endl;
			continue;
		}

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
			case 'F':
				continue;
			case 'G':
				cout << "Enter a movie you would like to find the stars for: ";
				cin >> movie;
				listMovieStars(movie, m);
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
		if (choice == 'Q')
			break;
	}
}

void printBookList(vector<Media> m) {
	//I coudln't get the output to look pretty with /t nor was I sure how to use setw unless I did it to every single media line.
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
	//I coudln't get the output to look pretty with /t nor was I sure how to use setw unless I did it to every single media line.
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
	//I coudln't get the output to look pretty with /t nor was I sure how to use setw unless I did it to every single media line.
	cout << "\t\tYOUR MOVIE LIST" << endl << endl;
	cout << "#\t\t   TITLE\t\tYEAR\  RATING" << endl;
	for (int i = 0; i < m.size(); i++) {
		if (m[i].getType() == 'M') {
			cout << setw(2) << i << " " << setw(40) << left<<  m[i].getTitle() << " " << setw(10) <<  m[i].getYearReleased() << " " << setw(5) <<  m[i].getRating() << endl;
		}
	}
	cout << endl;
}

void printList(vector<Media> m) {
	//I coudln't get the output to look pretty with /t nor was I sure how to use setw unless I did it to every single media line.
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
	//Not done statically with the media class, but it updates with added media
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
	cin.clear();
	cin.ignore();

	cout << "Enter Title: ";
	getline(cin, title);

	cout << "Enter Name (Artist, director, author): ";
	getline(cin, name);

	cout << "Enter Genre: ";
	cin >> genre;

	cout << "Enter Rating: ";
	cin >> rating;
	while (true) { // checks if the input is good, if not it will ask for proper input
		if (cin.fail() || rating < 0 || rating > 10) {
			cout << "Invalid input!" << endl;
			cin.clear();
			cin.ignore();
			cout << "Enter Rating: ";
			cin >> rating;
		}
		else
			break;
	}


	cout << "Enter Length: ";
	cin >> length;
	while (true) { // checks if the input is good, if not it will ask for proper input
		if (cin.fail()) {
			cout << "Invalid input!" << endl;
			cin.clear();
			cin.ignore();
			cout << "Enter Rating: ";
			cin >> rating;
		}
		else
			break;
	}

	cout << "Enter Year: ";
	cin >> year;
	while (true) { // checks if the input is good, if not it will ask for proper input
		if (cin.fail() || year < 1900 || year > 2022) {
			cout << "Invalid input!" << endl;
			cin.clear();
			cin.ignore();
			cout << "Enter Rating: ";
			cin >> rating;
		}
		else
			break;
	}
	//pushes new media onto the media vector
	Media tempMedia(type, title, name, rating, genre, length, year);
	m.push_back(tempMedia);
	cout << title << " was added to your list";
	}

void listMovieStars(string movie, vector<Media*>& mediaLib) {
	vector <string> temp;
	bool found = false;
	for (int i = 0; i < mediaLib.size(); i++) {
		if (mediaLib.at(i)->getTitle() == movie) {
			found = true;
			cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "THE STARS OF THE MOVIE " << movie << " ARE:  \n";
			static_cast<Movie*>(mediaLib.at(i))->getStars();
			break;
		}
	}
	if (!found) {
		cout << "\nSorry, but the movie: \'" << movie << "\' is not found in list." << endl;
	}
}