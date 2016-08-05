//---------------------------------------------------------------------------
// COMEDY.H
// Class for comedy movies
//---------------------------------------------------------------------------
// Comedy class:  class used by comedies, specifies how to perform 
//   the following operations with the movies (primarily used for sorting):
//	- == operator Checks if the movies are the same
//	- != operator Checks if the movies are not the same
//	- < operator Checks if the compared movie is less than "this" movie
//	- < operator Checks if the compared movie is more than "this" movie
//
// Implementation and assumptions:
//	- Overrides Movie's create and setTempData functions
//---------------------------------------------------------------------------
#ifndef COMEDY_H
#define COMEDY_H

#include <iostream>
using namespace std; 

#include "movie.h"
class Comedy : public Movie
{
public:
//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	char genre is set to F', actorLast and actorFirst are 
//					initialized to empty strings
//---------------------------------------------------------------------------
	Comedy();

//---------------------------------------------------------------------------
// Virtual Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
	virtual ~Comedy();

//---------------------------------------------------------------------------
// Operator ==
// Preconditions:	None
// Postconditions:	Returns true if title and year are the same, false 
//					otherwise
// Uses dynamic casting that unlike static casting finds the object's class
// at runtime
//---------------------------------------------------------------------------
	virtual bool operator==(const Movie&) const; 

//---------------------------------------------------------------------------
// Operator !=
// Preconditions:	None
// Postconditions:	Returns true if title and year are the same, false 
//					otherwise
// Calls the == operator to return true if the == operator returns false
//---------------------------------------------------------------------------
	virtual bool operator!=(const Movie&) const; 

//---------------------------------------------------------------------------
// Operator <
// Preconditions:	None
// Postconditions:	Returns true if title and year are less than, false
//					otherwise
// Uses dynamic casting that unlike static casting finds the object's class
// at runtime
//---------------------------------------------------------------------------
	virtual bool operator<(const Movie&) const; 

//---------------------------------------------------------------------------
// Operator >
// Preconditions:	None
// Postconditions:	Returns true if title and year are more than, false 
//					otherwise
// Calls the < operator to return true if the < operator returns false
//---------------------------------------------------------------------------
	virtual bool operator>(const Movie&) const; 

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	Returns new Classic object 
//---------------------------------------------------------------------------
	virtual Movie* Create() const; 

//---------------------------------------------------------------------------
// setTempData
// Preconditions:	istream is well-formed
// Postconditions:	Parses istream and sets the variables accordingly
//					returns true if successful, false otherwise
//---------------------------------------------------------------------------
	virtual bool setTempData(istream&); 
};

#endif
