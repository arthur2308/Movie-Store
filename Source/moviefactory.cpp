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
#include "stdafx.h"
#include "moviefactory.h"


//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	MoviePool array's elements are set to NULL, except 
//					2, 3, and 5
//---------------------------------------------------------------------------
MovieFactory::MovieFactory()
{
	for (int i = 0; i < MAX_POOL_SIZE; i++)		// sets every element to NULL
	{
		moviePool[i] = NULL;
	}

	moviePool[2] = new Classic;
	moviePool[3] = new Drama;
	moviePool[5] = new Comedy;
	
}

//---------------------------------------------------------------------------
// Virtual Destructor
// Preconditions:	None
// Postconditions:	All the aray elements are deleted and set to NULL
//---------------------------------------------------------------------------
MovieFactory::~MovieFactory()
{
	for (int i = 0; i < MAX_POOL_SIZE; i++)		//deletes elements 
	{
		delete moviePool[i];
		moviePool[i] = NULL;
	}
}

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	Movie is created 
// Goes into moviePool array and calls the genres create function to create 
// the movie
//---------------------------------------------------------------------------
Movie* MovieFactory::Create(const char& c) const
{
	int index = hash(c);

	if (moviePool[index] != NULL)
	{
		return moviePool[index]->Create();
	}
	else
	{
		return NULL;
	}

}

//---------------------------------------------------------------------------
// hash
// Preconditions:	none
// Postconditions:	Retruns an int corresponding to chars alphabet's index
//---------------------------------------------------------------------------
int MovieFactory::hash(const char& c) const
{
	return c - 'A';
}