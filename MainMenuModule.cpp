#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "MainMenuModule.h"
//#include "Product.h"			// should include this here or in Source.cpp? Don't need Product.h here because Book.h already has access to Product.h
#include "Book.h"				// should include this here too?

using namespace std;

// Terms used for the switch statement, in the order of the contents contained in the file
#define TITLE 0
#define AUTHOR 1
#define PUBLISHER 2
#define ISBN 3
#define RPRICE 4
#define WSPRICE 5
#define QUANT 6
#define DATEADD 7			// DateAdd hasn't been included in booklist yet

// Function prototypes
void open();


// use throw and catch to validate file name ?

bool Menu()
{

	open();

	bool running = true;
	while (running)
	{
		int i = 0;
		cout << "                        Serendipity Booksellers                       " << endl;
		cout << "                               Main Menu                              " << endl;
		cout << endl;
		cout << "                    1. Cashier Module                                 " << endl;
		cout << "                    2. Invetory Database Module                       " << endl;
		cout << "                    3. Report Module                                  " << endl;
		cout << "                    4. Quit                                           " << endl;
		cout << endl;
		cout << "Enter your choice(e.g '4'): ";
		cin >> i;
		while (i > 4 || i < 1)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid Choice" << endl;
			cout << "Enter your choice(e.g '4'): ";
			cin >> i;
		}
		if (i == 1)
		{
			cashier();
		}
		else if (i == 2)
		{
			InventoryDatabase();
		}
		else if (i == 3)
		{
			report();
			///**/ commen added
		}
		else
		{
			running = false;
		}
	}
	return true;
}


/* Function open -- Pseudocode  below */
// function open
// return or enter an array
// read the values
// then set to array
// set arraysize[1000]
// use >>>     array i = new book[size];
// then clost the file

// have the size of array


// Function open -- returns an int
// The purpose of this function is to get the information from the booklist text file, read the content, and create Book objects based on the information included in the file.
void open() // (string _bookname_, int size)				// where should this function be located? should take an array? or should create an array dynamically depending on the size of the book?
{
	// declare variables
	Book book[1024];			// array of Product
	int bookCount = 0;			// counter for the number of book titles in the database
	int tmpWord = 0;			// counter for the nth term in the line of book info
	string word;				// used to take string values from file

	// variables for book oject
	long long int isbn = 0;
	string author;
	string publisher;
	int quantity = 0;
	string title;
	double wholeCost = 0;
	double retailCost = 0;
	string date;


	// open booklist file
	fstream file;
	file.open("booklist.txt", ios::in);


	// read words from file and assign the words to the appropriate variables.
	while (file >> word)
	{
		// increment book count once it reads the first content of book info. bookCount is indexed 1.
		if (tmpWord == 0)
		{
			bookCount++;
		}

		// if reach the end of the line, create an object. Semicolon indicates the end of one book
		if (tmpWord == 7)// (word == ";")
		{
			// create book object with the variables

			book[bookCount - 1] = Book(isbn, author, publisher, quantity, title, wholeCost, retailCost);		// will also need to include "date added"
			// reset the tmp word count to 0
			tmpWord = 0;
			cout << endl;
			continue;
		}

		// Use a switch statement to handle appropriate values
		switch (tmpWord)
		{
		case TITLE:
			title = word;
			break;
		case AUTHOR:
			author = word;
			break;
		case PUBLISHER:
			publisher = word;
			break;
		case ISBN:
			isbn = stoll(word);		// convert string to long long
			break;
		case RPRICE:
			wholeCost = stod(word);
			break;
		case WSPRICE:
			retailCost = stod(word);
			break;
		case QUANT:
			quantity = stoi(word);
			break;
		case DATEADD:
			date = word;
			break;
		}


		// increment word count
		tmpWord++;
	}
	
	for (int i = 0; i < bookCount; i++)
	{
		cout << book[i].getName() << endl;
		cout << book[i].getQuantity() << endl;
		cout << book[i].getRetailCost() << endl;
		cout << book[i].getWholesaleCost() << endl << endl;
		cout << book[i].getAuthor() << endl;
		cout << book[i].getISBN() << endl;

	}

}





// Open  the file
// get information word by word
// assign that into the variables
// create book object

//string auth, title;
//long long int Isbn;
//for (int i = 0; i < count; i++)
//{
//	book[i](Isbn, auth, title, asdf asdf, asd f, ad f, adsf);
//}








//cout << endl << tmpWord << endl;
//cout << bookCount << endl;


//cout << word << endl;


// read word by word. the word will be typecasted to an long long int and will be assigned to price of long long int data type.

// First, work on getting the data from the file.

// Set the values to the Book object.



// Create book object based on the count:
// Book(arg, arg, arg, arg)

// will create the Product book array of 1000 as default ------ // later find ways to make sure there is no memory leak. however since we're not dynamically allocating the Product/Book array, memory leak will not happen.

// Will read the contents and assign the values to the Books

// count will be able to change when books are added or deleted

// returns count -- the number of book titles


// Opens the input file. 








//==================================================================

// use switch to select where to assign the string value




/* Pseudocode 2 */
// input --> array, size of array, file name
// open file
// read input
// create new object from file
// close file
// return bool -- success.
// try, catch.
// will return int --
// if fails, will throw a character. if it catches a character, then it fails.
// try catch will also throw sth.
// main func will be try catch
// if catches sth wrong, will save data <-  m?
// if throw exception, will throw catch.
// throw and catch -- 


// bool readInput(____ [], int size, get the entire file name)








//string word;
//int last;
//char clast;
//string slast;
//int day;
//int month;
//int year;
//int counter = 0;



//    while (inputFile >> word)
//    {
//        if (word[word.length()-1] == '~')
//        {
//            cout << "\n\n";
//        }
//        cout << word;
//    }






/* Notes added */
/*
SetBookObject.cpp



*/

//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;


