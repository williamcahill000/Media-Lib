#include <string>
#include <iostream>
#include "Media.h" 
#include "Book.h"
using namespace std;

Book::Book()
	:Media()
{
	//uses Media constructor as well as class specific items
	author = " ";
	pages = 0;
}

Book::Book(char type, string t, string a, int r, string g, int p, int yr)
	: Media(type, t, r, yr, g)
{
	//uses Media constructor as well as class specific items
	author = a;
	pages = p;
}

string Book::getAuthor() { return author; }
int    Book::getPages() { return pages; }
void   Book::setAuthor(string a) { author = a; }
void   Book::setPages(int p) { pages = p; }
void   Book::print(ostream& o) {
	o << "Book: " << title << " : " << author << endl;
}