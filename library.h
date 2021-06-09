//
// Created by Yusuf Pisan on 3/26/18.
//
//Modified by Jay Darshan Vakil on 1/10/2021.
//This header file sets the "Interface" for the Library program used in library.cpp file. 
//

#ifndef ASS1_LIBRARY_H
#define ASS1_LIBRARY_H

#include <string>
#include <iostream>
#include <ostream>
#include <cassert>

// Only for class code, OK to use namespace
using namespace std;

// Library holds books - can add, remove and list books
class Library {

public:
	/*
		Public default constructor. Initializes the Library object
	*/
	Library(const string& Name);

	// destructor
	virtual ~Library();

	/*
		Method to add a new book to the library, returns true if added, false if book wasn't added.
	*/
	bool addBook(const string& BookName);

	/*
		remove a book. return true if successfully removed, false if book not in library
	*/
	bool removeBook(const string& BookName);

	// list all books
	void listAllBooks() const;

	// true if book found in library
	bool isInLibrary(const string& BookName) const;

	// display all books in library
	friend ostream& operator<<(ostream& Out, const Library& Lib);

	Library& operator+=(const Library& other);
private:

	//The name of the library
	string libraryName;

	//The number of books in the library
	int numOfBooks;

	//The max amount of books that can be added to the library.
	static const int MAX = 100;

	//Array to store the books in the library
	string booksInTheLibrary[MAX];

	//Find the index of a certain book 
	int findBookIndex(const string& BookName) const;
};

#endif  // ASS1_LIBRARY_H
