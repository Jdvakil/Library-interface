/*
* This is the main class for the object Library. In this file, the program carries out functionalities defined in the
* library class and header file.
* @author Jay Darshan Vakil
* @Version 1/10/2021
*/

#include "library.h"
using namespace std;

/*
* Test method 1 to test the object Library
*/
void test1() {
	Library Libs("UWB");
	Libs.addBook("Don Quixote");
	Libs.addBook("In Search of Lost Time");
	Libs.addBook("Ulysses");
	Libs.addBook("The Odyssey");
	Libs.listAllBooks();

	// should generate already in library message and return true
	bool Result = Libs.isInLibrary("The Odyssey");
	assert(Result);

	// cannot add book twice, result should be false
	Result = Libs.addBook("The Odyssey");
	assert(!Result);

	// test remove, result should be true
	Result = Libs.removeBook("The Odyssey");
	assert(Result);

	// not in library, result should be false
	Result = Libs.isInLibrary("The Odyssey");
	assert(!Result);

	// cannot remove twice, result should be false
	Result = Libs.removeBook("The Odyssey");
	assert(!Result);

	cout << "\n" << Libs << endl;
}

/*
* Test method 2 to test the object library.
*/
void test2() {
	Library lib2("Personal Library");
	lib2.addBook("Diary of a wimpy kid");
	lib2.addBook("1984");
	lib2.addBook("Astrophysics for people in a hurry");
	lib2.addBook("A fault in our stars");
	lib2.listAllBooks();

	bool Result = lib2.isInLibrary("1984");
	assert(Result);

	//should be 1 or true
	cout << "1984 is in the library: " << Result << endl;

	Result = lib2.removeBook("Diary of a wimpy kid");
	assert(Result);

	//should be 1 or true
	cout << "Diary of a wimpy kid is removed: " << Result << endl;

	Result = lib2.removeBook("Diary of a wimpy kid");
	assert(!Result);

	//should be 0 or false
	cout << "Diary of a wimpy kid is removed: " << Result << endl;

	lib2.listAllBooks();
	Result = lib2.addBook("DaVinci Code");
	assert(Result);

	cout << "DaVinci Code is added to the library: " << Result << endl;

	cout << "\n" << lib2 << endl;
} 

void test3() {
	Library lib("test");
	Library lib2("library 2");
	lib.addBook("one");
	lib.addBook("two");
	lib2.addBook("three");
	lib2.addBook("four");
	cout << lib << endl;
	cout << lib2 << endl;
	cout << "Adding libraries" << endl;
	lib.operator+=(lib2);
	cout << (lib) << endl;
}

/*
* This method brings the two tests together and prints it to the console when called in the main method.
*/
void testAll() {
	/*test1();
	cout << "test 1 complete, test 2 in progress\n" << endl;
	test2();*/
	test3();
	cout << "Successfully completed all tests." << endl;
}

/*
* This is the main method, this is where the two tests are called from testAll() method and printed to the console.
*/
int main() {
	testAll();
	return 0;
}