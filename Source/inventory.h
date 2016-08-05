//---------------------------------------------------------------------------
// INVENTORY.H
// Class for inventory
//---------------------------------------------------------------------------
// Inventory class:	Used to insert, retrieve and display movies in the 
//					MovieBST class
//	- Adding a movie to the Binary Search Tree from MovieBST class
//	- Retrieving a movie from a Binary Search Tree 
//	- Displaying the the trees
//
// Implementation and assumptions:
//	- Maximum number of genres is set to number of English alphabet letters
//	- Uses a hash table to store trees
//---------------------------------------------------------------------------
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream> 
using namespace std; 

#include "movie.h"
#include "moviebst.h" 

class Inventory
{
public:

//---------------------------------------------------------------------------
// Default Constructor
// Preconditions:	None
// Postconditions:	The hashtable's elements are null but the 2,3 and 5
// Sets every element in the array to NULL but the 2, 3, and 5, corresponding
// to letters in the alphabet for C (Classic) D (Drama) F (Funny) 
//---------------------------------------------------------------------------
	Inventory();

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	Deletes all the elements in the array and sets them to 
//					NULL
//---------------------------------------------------------------------------
	~Inventory();

//---------------------------------------------------------------------------
// Insert
// Preconditions:	Movie pointer is passed in
// Postconditions:	Returns true if movie is successfullt inserted, false
//						otherwise
// Create a MovieBST pointer checks of it's not null and uses Insert()
// function to perform the insertion
//---------------------------------------------------------------------------
	bool Insert(Movie*); 

//---------------------------------------------------------------------------
// Retrieve
// Preconditions:	Movie target pointer is passed in, and movie result
// Postconditions:	Returns true if movie is successfully found, false
//						otherwise
// Create a MovieBST pointer checks of it's not null and uses Retrieve()
// function to perform the retrieval
//---------------------------------------------------------------------------
	bool Retrieve(const Movie&, Movie*&) const; 

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	The trees are displayed
// Loops theough the hashtable with trees checking if not null, then using 
// thei Display() function to display the trees
//---------------------------------------------------------------------------
	void Display() const; 

private: 
	static const int MAX_GENRE_COUNT = 26;	// letters in the alphabet
	MovieBST* movieBSTHashtable[MAX_GENRE_COUNT]; // table stroing tree ptrs

//---------------------------------------------------------------------------
// getMovieBST
// Preconditions:	None
// Postconditions:	Returns an appropriate hash table 
// Uses the index of the hashed character to return the hashtable
//---------------------------------------------------------------------------
	MovieBST* getMovieBST(const char &) const; 

//---------------------------------------------------------------------------
// hash
// Preconditions:	English alphabet character is passed in
// Postconditions:	Returns an int correspoding it's alphabetical index 
// Takes a passed in character and subtractes its ASCII value from A's 
// ASCII value to get alphabetical index of the character
//---------------------------------------------------------------------------
	int hash(const char&) const; 
};

#endif