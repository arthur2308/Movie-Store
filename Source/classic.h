//---------------------------------------------------------------------------
// CLASSIC.H
// Class for classic movies
//---------------------------------------------------------------------------
// Classic class:  class used by classics, specifies how to perform 
//   the following operations with the movies (primarily used for sorting):
//	- == operator Checks if the movies are the same
//	- != operator Checks if the movies are not the same
//	- < operator Checks if the compared movie is less than "this" movie
//	- < operator Checks if the compared movie is more than "this" movie
//
// Implementation and assumptions:
//	- stores month, actor's last name, actor's first name
//	- Overrides Movie's create, setData, and setTempData functions
//	- Has a private Display function
//---------------------------------------------------------------------------

#ifndef CLASSIC_H
#define CLASSIC_H

#include <iostream> 

using namespace std;

#include "movie.h" 

class Classic : public Movie
{
public:
//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	char genre is set to 'C', actorLast and actorFirst are 
//					initialized to empty strings
//---------------------------------------------------------------------------
	Classic();
	
//---------------------------------------------------------------------------
// Virtual Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
	virtual ~Classic();

//---------------------------------------------------------------------------
// Operator ==
// Preconditions:	None
// Postconditions:	Returns true if director, title, actor's/actresse's name, 
//					year, and month are the same, false otherwise
// Uses dynamic casting that unlike static casting finds the object's class
// at runtime
//---------------------------------------------------------------------------
	virtual bool operator==(const Movie&) const;
	
//---------------------------------------------------------------------------
// Operator !=
// Preconditions:	None
// Postconditions:	Returns true if director, title, actor's/actresse's name, 
//					year, and month are the same, false otherwise
// Calls the == operator to return true if the == operator return falls
//---------------------------------------------------------------------------
	virtual bool operator!=(const Movie&) const;
	
//---------------------------------------------------------------------------
// Operator <
// Preconditions:	None
// Postconditions:	Returns true if director, title, actor's/actresse's name, 
//					year, and month are less than, false otherwise
// Uses dynamic casting that unlike static casting finds the object's class
// at runtime
//---------------------------------------------------------------------------
	virtual bool operator<(const Movie&) const;
	
//---------------------------------------------------------------------------
// Operator >
// Preconditions:	None
// Postconditions:	Returns true if director, title, actor's/actresse's name, 
//					year, and month are more than, false otherwise
// Calls the < operator to return true if the < operator return falls
//---------------------------------------------------------------------------
	virtual bool operator>(const Movie&) const;

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	Returns new Classic object 
//---------------------------------------------------------------------------
	virtual Movie* Create() const;

//---------------------------------------------------------------------------
// setData
// Preconditions:	istream is well-formed
// Postconditions:	Parses istream and sets the variables accordingly
//					returns true if successful, false otherwise
//---------------------------------------------------------------------------
	virtual bool setData(istream&); 

//---------------------------------------------------------------------------
// setTempData
// Preconditions:	istream is well-formed
// Postconditions:	Parses istream and sets the variables accordingly
//					returns true if successful, false otherwise
//---------------------------------------------------------------------------
	virtual bool setTempData(istream&);

private:
	int month;						// int of the month the movie was released
	string actorLast;				// actor's last name
	string actorFirst;				// actor's first name

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	Sets the ostream to the movie's metadata
//---------------------------------------------------------------------------
	virtual void Display(ostream&) const;
};


#endif
