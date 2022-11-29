#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Function.h"
#include "Media.h"
#include "Book.h"
#include "Movie.h"
#include "Song.h"
using namespace std;


int Media::mediaCounts[4] = { 0,0,0,0 };

int main() {
    // open input & output files
    ifstream inFile;
    ofstream outFile;
    //checks for if the files opened
    try {
        inFile.exceptions(ifstream::failbit);
        inFile.open("mediaList.txt");
        outFile.exceptions(ifstream::failbit);
        outFile.open("mediaReport.txt");
    }
    catch (ifstream::failure& fail) {
        cout << "Could not open input file" << endl;
        cout << fail.what() << endl;
        cout << fail.code() << endl;
        exit(1);
    }

    // create vector of media data
    // if you create a class for Media*, this vector would be put 
    // in that class and you would access other functions through the class
    // example myLib.readData(inFile,outFile);
    vector <Media*> myLib;

    // read data into myLib
    readData(inFile, outFile, myLib);

    
    char choice = menu();
    while (choice != 'Q') {
        if (choice == 'M') {
            //Prints the movie list
            printList(myLib, 'M', "MOVIE");
        }
        else if (choice == 'B') {
            //prints the book list
            printList(myLib, 'B', "BOOK");
        }
        else if (choice == 'S') {
            //print the song list
            printList(myLib, 'S', "SONG");
        }
        else if (choice == 'A') {
            //prints the entire list
            printList(myLib);
        }
        else if (choice == 'G') {
            string tempMovieName;
            vector<string> tempStarsList;
            vector<string> returnedStarList;
            cout << "Enter the Movie Name: ";
            cin.ignore();
            //takes in movie name
            getline(cin, tempMovieName);
            cout << endl;
            //returned list of stars from the movie
            returnedStarList = starsFromMovies(myLib, tempMovieName);
            tempStarsList.swap(returnedStarList);
            //Checks if there are any stars at all. If there aren't any, then the movie isn't here because all the movies have stars. Movie stars have to be in movies and movies have to include movie stars. Unless it's an indie movie but then they just make their own stars, so the fact still stands.
            if (tempStarsList.size() == 0) {
                cout << "Sorry, but the movie: \'" << tempMovieName << "\' is not found in your list" << endl;
            }
            else {
                cout << endl;
                cout << endl;
                cout << "************************************" << endl;
                cout << "THE STARS OF THE MOVIE " << tempMovieName << " ARE:" << endl;
                cout << "====================================" << endl;
                for (int i = 0; i < tempStarsList.size(); i++) {
                    cout << tempStarsList[i] << endl;
                }
            }
        }
        else if (choice == 'F') {
            string tempStarName;
            vector<string> tempMoviesList;
            vector<string> returnedMoviesList;
            cout << "Enter the Star's Name: ";
            cin.ignore();
            getline(cin, tempStarName);
            returnedMoviesList = moviesFromStar(myLib, tempStarName);
            tempMoviesList.swap(returnedMoviesList);
            cout << endl;
            //Checks to see if the star has been in any movies. If he's been in 0 movies, then he isn't here.
            if (tempMoviesList.size() == 0) {
                cout << "Sorry, but the star: " << tempStarName << " is not found in any movies in your list" << endl;
            }
            else {
                cout << tempStarName << " appears in the following movie(s):" << endl;
                for (int i = 0; i < tempMoviesList.size(); i++) {
                    cout << tempMoviesList[i] << endl;
                }
            }
        }
        else if (choice == 'T') {
            //checks the static int[] from the Media file that tracks # of inputs
            cout << endl << "YOUR MEDIA LIBRARY\n\n#   TYPE" << endl;
            cout << Media::mediaCounts[1] << " Movies" << endl;
            cout << Media::mediaCounts[2] << " Books" << endl;
            cout << Media::mediaCounts[3] << " Songs" << endl;
            cout << Media::mediaCounts[0] << " Items" << endl;
        }
        cout << endl;
        choice = menu();
    }
}