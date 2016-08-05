//---------------------------------------------------------------------------
// MOVIEFACTORY.H
// Class for MovieFactory
//---------------------------------------------------------------------------
//MovieFactory class:  Class creates movies. Uses an array to store genres
//	- Create, Creates a genre movie in the moviePools array 
//	- hash return ASCII value of char minus ASCII value of 'A'
//
// Implementation and assumptions:
//	- MAX POOL SIZE is set to 26
//	- Uses an array for MoviePool
//---------------------------------------------------------------------------
#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

#include "classic.h"
#include "movie.h"
#include "comedy.h"
#include "drama.h"

#include <iostream> 
using namespace std;

class MovieFactory
{
public:
//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	MoviePool array's elements are set to NULL, except 
//					2, 3, and 5
//---------------------------------------------------------------------------
	MovieFactory();

//---------------------------------------------------------------------------
// Virtual Destructor
// Preconditions:	None
// Postconditions:	All the aray elements are deleted and set to NULL
//---------------------------------------------------------------------------
	~MovieFactory();

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	Movie is created 
// Goes into moviePool array and calls the genres create function to create 
// the movie
//---------------------------------------------------------------------------
	Movie* Create(const char&) const;

private:
	static const int MAX_POOL_SIZE = 26;	// MAX POOL SIZE is set to 26
	Movie* moviePool[MAX_POOL_SIZE];		// Array is created 

//---------------------------------------------------------------------------
// hash
// Preconditions:	none
// Postconditions:	Retruns an int corresponding to chars alphabet's index
//---------------------------------------------------------------------------
	int hash(const char&) const;		
};

#endif
