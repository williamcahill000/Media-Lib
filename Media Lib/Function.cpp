#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Function.h"
#include "Media.h"
#include "Book.h"
#include "Movie.h"
#include "Song.h"
using namespace std;

int readData(istream& inFile, ostream& outFile, vector<Media*>& mediaLib) {
    cout << "\n\n\nLoading Data File\n\n\n";
    //outFile << "" << endl;
    string inLine, title, director, genre, tempStr, testChar, name, author;
    int rating, duration, year, pages;
    vector<string> stars;
    vector<string> row;
    char choice = ' ';

    while (inFile.good()) {
        getline(inFile, inLine);
        testChar = inLine.substr(0, 1);
        if (testChar == "Q")
            break;

        //read data in string vector
        row.clear();
        stringstream inSS(inLine);
        while (getline(inSS, tempStr, ',')) {
            row.push_back(tempStr);
        }

        //parse data for Book type
        if (testChar == "B") {
            title = row[1];
            author = row[2];
            genre = row[4];
            try {
                rating = stoi(row[3]);
                pages = stoi(row[5]);
                year = stoi(row[6]);
            }
            catch (invalid_argument& e) {
                //outFile << "" << endl;
                string msg = "\nERROR: " + inLine.substr(0, inLine.length() - 2);
                outFile << msg << "\nPrevious record has an " << e.what() << " error\n\n";
                continue;
            }
            catch (string a) {
                cout << a << endl;
                exit(1);
            }
            char type = 'B';
            Book* tempBook = new Book(type, title, author, rating, genre, pages, year);

            mediaLib.push_back(tempBook);
            Media::mediaCounts[0]++;
            Media::mediaCounts[1] += 1;
            // all other data types need to be added
        }
        else if (testChar == "M") {
            char type = 'M';
            title = row[1];
            director = row[2];
            genre = row[4];
            try {
                rating = stoi(row[3]);
                duration = stoi(row[5]);
                year = stoi(row[6]);
                stars.clear();
                for (int i = 7; i < row.size(); i++) {
                    string newStuff = row[i];
                    if (i == row.size() - 1) {
                        newStuff.resize(newStuff.size());
                    }
                    stars.push_back(newStuff);
                }
                Movie* tempMovie = new Movie(type, title, director, rating, genre, duration, year, stars);
                mediaLib.push_back(tempMovie);
                Media::mediaCounts[0]++;
                Media::mediaCounts[2]++;
            }
            catch (invalid_argument& e) {
                string msg = "\nERROR: " + inLine.substr(0, inLine.length() - 2);
                outFile << msg << "\nPrevious record has an " << e.what() << " error\n\n";
                continue;
            }
            catch (string a) {
                cout << a << endl;
                exit(1);
            }
        }
        else if (testChar == "S") {
            char type = 'S';
            title = row[1];
            director = row[2];
            genre = row[4];
            try {
                rating = stoi(row[3]);
                duration = stoi(row[5]);
                year = stoi(row[6]);
                Music* tempMusic = new Music(type, title, director, rating, genre, duration, year);
                mediaLib.push_back(tempMusic);
                Media::mediaCounts[0]++;
                Media::mediaCounts[3]++;
            }
            catch (invalid_argument& e) {
                string msg = "\nERROR: " + inLine.substr(0, inLine.length() - 2);
                outFile << msg << "\nPrevious record has an " << e.what() << " error\n\n";
                continue;
            }
            catch (string a) {
                cout << a << endl;
                exit(1);
            }
        }
    }
    return 0;
}

char menu() {
    char tempChoice;
    cout << "MENU CHOICES" << endl;
    cout << "M - Print Movie List" << endl;
    cout << "B - Print Book List" << endl;
    cout << "S - Print Song List" << endl;
    cout << "A - Print All Media" << endl;
    cout << "G - Print Stars for a Given Movie" << endl;
    cout << "F - Find the Movie the Star is in" << endl;
    cout << "T - Print Media Counts" << endl;
    cout << "Q - Quit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> tempChoice;
    tempChoice = toupper(tempChoice);
    cout << "***" << tempChoice << endl;
    return tempChoice;
}

void printList(vector<Media*>& cinema, char type, string word) {
    cout << "\t\t\t\tYOUR " << word << " LIST" << endl;
    cout << "#         Title                             YEAR    RATING" << endl;
    int counter = 1;
    for (int i = 0; i < cinema.size(); i++) {
        if (cinema[i]->getType() == type) {
            cout << left << setw(4) << counter << left << setw(40) << cinema[i]->getTitle() << setw(8) << cinema[i]->getYearReleased() << cinema[i]->getRating() << endl;
            counter++;
        }
    }
}

void printList(vector<Media*>& cinema) {
    cout << "\t\t\t\tYOUR MEDIA LIST" << endl;
    cout << "#         Title                             YEAR    RATING" << endl;
    int counter = 1;
    for (int i = 0; i < cinema.size(); i++) {
        //if(cinema[i]->getType() == type){
        cout << left << setw(4) << counter << left << setw(40) << cinema[i]->getTitle() << setw(8) << cinema[i]->getYearReleased() << cinema[i]->getRating() << endl;
        counter++;
        //}
    }
}

vector<string> starsFromMovies(vector<Media*>& cinema, string tempMovieName) {
    vector<string> empty;
    for (int i = 0; i < cinema.size(); i++) {
        if (cinema[i]->getType() == 'M') {
            if (cinema[i]->getTitle() == tempMovieName) {
                //cout << cinema[i].getStars().size();
                return static_cast<Movie*>(cinema[i])->getStars();
            }
        }
    }
    return empty;
}

vector<string> moviesFromStar(vector<Media*>& cinema, string tempStarName) {
    vector<string> movieNames;
    for (int i = 0; i < cinema.size(); i++) {
        if (cinema[i]->getType() == 'M') {
            for (int j = 0; j < static_cast<Movie*>(cinema[i])->getStars().size(); j++) {
                //cout << cinema[i].getStars().at(j) << endl;
                string cinemaListString = static_cast<Movie*>(cinema[i])->getStars().at(j);
                //str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
                if (cinemaListString == tempStarName) {
                    movieNames.push_back(cinema[i]->getTitle());
                }
            }
        }
    }
    return movieNames;
}