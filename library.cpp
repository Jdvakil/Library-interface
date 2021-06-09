//
// Created by Jay Darshan Vakil on 01/10/2021.
//
// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library


#include "library.h"

using namespace std;

/*
* The default and the only constructor for the library. Sets the name of the library and sets the number of books to 0.
* <PRECONDITIONS> The user enters a valid name of the library.
* <POSTCONDITION> Library object will be initialized correctly and the following public methods will be
			available for the users' use.
* <Param> LibName The name of the library.
*/
Library::Library(const string& LibName) {
	Library::libraryName = LibName;
	Library::numOfBooks = 0;
}

// destructor
// nothing on heap
Library::~Library() {
	// destructor
}



/*
* Checks if a book, passed as a parameter, is in the library or not.
* <PRECONDITION> The user inputs a valid book name in the form of a string.
* <POSTCONDITION> The method will check if the book is in the library or not.
* <Param> BookName The name of the book that is to be checked if it is in the library or not.
* <return> True If the book is in the library
* <return> False If the book is not in the library or the number of books is 0.
*/
bool Library::isInLibrary(const string& BookName) const {
	if (Library::numOfBooks == 0)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < Library::numOfBooks; i++)
		{
			if (Library::booksInTheLibrary[i] == BookName)
			{
				return true;
			}
		}
		return false;
	}
}

/*
* This method uses an overloading operator += to add a Library passed as a parameter to this library.
* <PRECONDITION> The input parameter is a valid Library object.
* <POSTCONDITION> The method will add another library to this library successfully
* <PARAM> other Another library object to be added to this library
* <RETURN> Returns this library with the added books from the other library.
*/
Library& Library::operator+=(const Library& other)
{
	if (Library::MAX - Library::numOfBooks >= other.numOfBooks)//Check if there is enough space to accomodate the other library to be added in 
		//the current library.
	{
		for each (string otherBooks in other.booksInTheLibrary)
		{
			this->addBook(otherBooks);
		}
	}
	return *this;
}

/* This method adds a new unique book to the library.
* <PRECONDITION> The user enters a valid, unique book name that is not in the library and the number of books is
*				 under 100.
* <POSTCONDITION> The method will add a new book to the library.
* <Param> BookName The title of the book to be added to the library.
* <Return> True If the title/book was added to the library successfully.
* <Return> False If a book with the same title already exists in the library.
*/
bool Library::addBook(const string& BookName) {
	if (Library::numOfBooks == MAX)
	{
		return false;
	}
	else
	{
		if (Library::isInLibrary(BookName))
		{
			return false;
		}
		else
		{
			Library::booksInTheLibrary[Library::numOfBooks] = BookName;
			Library::numOfBooks++;
			return true;
		}
	}
	return false;
}

/*
* This method removes a book from the library.
* <PRECONDITION> The user enters a valid book title that exists in the library.
* <POSTCONDITION> The method will remove the book successfully.
* <Param> BookName The name of the book to be removed.
* <Return> True If the book was removed from the library.
* <Return> False If the book does not exist in the library or was not removed.
*/
bool Library::removeBook(const string& BookName) {
	//Uses the findBookIndex method to locate the index of the book for it to be replaced with the last added book. 
	int indexOfBook = Library::findBookIndex(BookName);
	if (indexOfBook == -1 || Library::numOfBooks == 0)
	{
		return false;
	}
	Library::booksInTheLibrary[indexOfBook] = Library::booksInTheLibrary[Library::numOfBooks - 1];
	Library::numOfBooks--;
	return true;
}

/*
* This method prints out a list of all the books in the library.
* <PRECONDITION> The number of books in the library is not 0.
* <POSTCONDITION> The method will print out every single book in the library with indexing.
*/
void Library::listAllBooks() const {
	if (Library::numOfBooks == 0)
	{
		cout << "No book found in the library, please add some books and try again." << endl;
	}
	else
	{
		cout << "Books in: " << Library::libraryName << endl;
		for (int i = 0; i < Library::numOfBooks; i++)
		{
			cout << i + 1 << ") " << Library::booksInTheLibrary[i] << endl;
		}
	}
}

/*
* This method finds and returns the index of a book from the library.
* <PRECONDITION> The user enters a valid book name.
* <POSTCONDITION> The method will find the index of the book from the array.
* <Param> BookName The name of the book to find its index
* <Return> the index of the book or -1 if the book is not in the library.
*/
int Library::findBookIndex(const string& BookName) const {
	if (Library::numOfBooks == 0)
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < Library::numOfBooks; i++)
		{
			if (Library::booksInTheLibrary[i] == BookName)
			{
				return i;
			}
		}
		return -1;
	}
}

/*
* This method displays the library in the form of a string output.
*/
ostream& operator<<(ostream& Out, const Library& Lib) {
	Out << "Books in: " << Lib.libraryName << endl;
	for (int i = 0; i < Lib.numOfBooks; i++)
	{
		Out << Lib.booksInTheLibrary[i] << endl;
	}
	return Out;
}