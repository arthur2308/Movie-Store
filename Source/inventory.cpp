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
#include "stdafx.h"
#include "inventory.h"

//---------------------------------------------------------------------------
// Default Destructor
// Preconditions:	None
// Postconditions:	The hashtable's elements are null but the 2,3 and 5
// Sets every element in the array to NULL but the 2, 3, and 5, corresponding
// to letters in the alphabet for C (Classic) D (Drama) F (Funny) 
//---------------------------------------------------------------------------
Inventory::Inventory()
{
	for (int i = 0; i < MAX_GENRE_COUNT; i++)
	{
		movieBSTHashtable[i] = NULL; 
	}

	movieBSTHashtable[2] = new MovieBST; 
	movieBSTHashtable[3] = new MovieBST;
	movieBSTHashtable[5] = new MovieBST;
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	Deletes all the elements in the array and sets them to 
//					NULL
//---------------------------------------------------------------------------
Inventory::~Inventory()
{
	for (int i = 0; i < MAX_GENRE_COUNT; i++)
	{
		delete movieBSTHashtable[i]; 
		movieBSTHashtable[i] = NULL; 
	}
}

//---------------------------------------------------------------------------
// Insert
// Preconditions:	Movie pointer is passed in
// Postconditions:	Returns true if movie is successfullt inserted, false
//						otherwise
// Create a MovieBST pointer checks of it's not null and uses Insert()
// function to perform the insertion
//---------------------------------------------------------------------------
bool Inventory::Insert(Movie* movie)
{
	MovieBST* targetMovieBST = getMovieBST(movie->getGenre());

	if (targetMovieBST != NULL)
		return targetMovieBST->Insert(movie);

	else
		return false; 
}

//---------------------------------------------------------------------------
// Retrieve
// Preconditions:	Movie target pointer is passed in, and movie result
// Postconditions:	Returns true if movie is successfully found, false
//						otherwise
// Create a MovieBST pointer checks of it's not null and uses Retrieve()
// function to perform the retrieval
//---------------------------------------------------------------------------
bool Inventory::Retrieve(const Movie& target, Movie*& result) const
{
	MovieBST* targetMovieBST = getMovieBST(target.getGenre()); 

	if (targetMovieBST != NULL)
		return targetMovieBST->Retrieve(target, result);
	else
		return false; 
}

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	The trees are displayed
// Loops theough the hashtable with trees checking if not null, then using 
// thei Display() function to display the trees
//---------------------------------------------------------------------------
void Inventory::Display() const
{
	for (int i = 0; i < MAX_GENRE_COUNT; i++)
	{
		if (movieBSTHashtable[i] != NULL)
			movieBSTHashtable[i]->Display();
	}
}

//---------------------------------------------------------------------------
// getMovieBST
// Preconditions:	None
// Postconditions:	Returns an appropriate hash table 
// Uses the index of the hashed character to return the hashtable
//---------------------------------------------------------------------------
MovieBST* Inventory::getMovieBST(const char& c) const
{
	int index = hash(c); 
	return movieBSTHashtable[index]; 
}

//---------------------------------------------------------------------------
// hash
// Preconditions:	English alphabet character is passed in
// Postconditions:	Returns an int correspoding it's alphabetical index 
// Takes a passed in character and subtractes its ASCII value from A's 
// ASCII value to get alphabetical index of the character
//---------------------------------------------------------------------------
int Inventory::hash(const char& c) const
{
	return c - 'A'; 
}