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
#include "stdafx.h"
#include "comedy.h"

//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	char genre is set to F', actorLast and actorFirst are 
//					initialized to empty strings
//---------------------------------------------------------------------------
Comedy::Comedy()
{
	genre = 'F'; 
}

//---------------------------------------------------------------------------
// Virtual Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
Comedy::~Comedy()
{
}

//---------------------------------------------------------------------------
// Operator ==
// Preconditions:	None
// Postconditions:	Returns true if title and year are the same, false 
//					otherwise
// Uses dynamic casting that unlike static casting finds the object's class
// at runtime
//---------------------------------------------------------------------------
bool Comedy::operator==(const Movie& movie) const
{
	return title == dynamic_cast<const Comedy&>(movie).title &&
		year == dynamic_cast<const Comedy&>(movie).year;
}

//---------------------------------------------------------------------------
// Operator !=
// Preconditions:	None
// Postconditions:	Returns true if title and year are the same, false 
//					otherwise
// Calls the == operator to return true if the == operator returns false
//---------------------------------------------------------------------------
bool Comedy::operator!=(const Movie& movie) const
{
	return !(*this == movie); 
}

//---------------------------------------------------------------------------
// Operator <
// Preconditions:	None
// Postconditions:	Returns true if title and year are less than, false
//					otherwise
// Uses dynamic casting that unlike static casting finds the object's class
// at runtime
//---------------------------------------------------------------------------
bool Comedy::operator<(const Movie& movie) const
{
	if (*this == dynamic_cast<const Comedy&>(movie))
		return false;

	else if (title > dynamic_cast<const Comedy&>(movie).title)
		return false;

	else if (year > dynamic_cast<const Comedy&>(movie).year)
		return false;

	else
		return true; 
}

//---------------------------------------------------------------------------
// Operator >
// Preconditions:	None
// Postconditions:	Returns true if title and year are more than, false 
//					otherwise
// Calls the < operator to return true if the < operator returns false
//---------------------------------------------------------------------------
bool Comedy::operator>(const Movie& movie) const
{
	return !(*this < movie && !(*this == movie));
}

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	Returns new Classic object 
//---------------------------------------------------------------------------
Movie* Comedy::Create() const
{
	return new Comedy;
}

//---------------------------------------------------------------------------
// setTempData
// Preconditions:	istream is well-formed
// Postconditions:	Parses istream and sets the variables accordingly
//					returns true if successful, false otherwise
//---------------------------------------------------------------------------
bool Comedy::setTempData(istream& movieStream)
{
	string strYear; 

	movieStream.ignore(1, ' '); 
	getline(movieStream, title, ',');
	movieStream.ignore(1, ' ');
	getline(movieStream, title, ',');

	year = stoi(strYear); 

	return true; 
}






