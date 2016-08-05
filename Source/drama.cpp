//---------------------------------------------------------------------------
// DRAMA.H
// Class for drama movies
//---------------------------------------------------------------------------
// Drama class:  class used by dramas, specifies how to perform 
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
#include "drama.h"

//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	char genre is set to F', actorLast and actorFirst are 
//					initialized to empty strings
//---------------------------------------------------------------------------
Drama::Drama()
{
	genre = 'D'; 
}

//---------------------------------------------------------------------------
// Virtual Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
Drama::~Drama()
{
}

//---------------------------------------------------------------------------
// Operator ==
// Preconditions:	None
// Postconditions:	Returns true if title and director are the same, false 
//					otherwise
// Uses dynamic casting that unlike static casting finds the object's class
// at runtime
//---------------------------------------------------------------------------
bool Drama::operator==(const Movie& movie) const
{
	return director == dynamic_cast<const Drama&>(movie).director &&
		title == dynamic_cast<const Drama&>(movie).title; 
}

//---------------------------------------------------------------------------
// Operator !=
// Preconditions:	None
// Postconditions:	Returns true if title and director are the same, false 
//					otherwise
// Calls the == operator to return true if the == operator returns false
//---------------------------------------------------------------------------
bool Drama::operator!=(const Movie& movie) const
{
	return (*this == movie);
}

//---------------------------------------------------------------------------
// Operator <
// Preconditions:	None
// Postconditions:	Returns true if title and director are less than, false
//					otherwise
// Uses dynamic casting that unlike static casting finds the object's class
// at runtime
//---------------------------------------------------------------------------
bool Drama::operator<(const Movie& movie) const
{
	if (*this == dynamic_cast<const Drama&>(movie))
		return false;

	else if (director > dynamic_cast<const Drama&>(movie).director)
		return false;

	else if (title > dynamic_cast<const Drama&>(movie).title)
		return false;

	else
		return true; 
}

//---------------------------------------------------------------------------
// Operator >
// Preconditions:	None
// Postconditions:	Returns true if title and director are more than, false 
//					otherwise
// Calls the < operator to return true if the < operator returns false
//---------------------------------------------------------------------------
bool Drama::operator>(const Movie& movie) const
{
	return !(*this < movie) && !(*this == movie); 
}

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	Returns new Classic object 
//---------------------------------------------------------------------------
Movie* Drama::Create() const
{
	return new Drama; 
}

//---------------------------------------------------------------------------
// setTempData
// Preconditions:	istream is well-formed
// Postconditions:	Parses istream and sets the variables accordingly
//					returns true if successful, false otherwise
//---------------------------------------------------------------------------
bool Drama::setTempData(istream& MovieStream)
{
	MovieStream.ignore(1, ' ');
	getline(MovieStream, director, ','); 
	MovieStream.ignore(1, ' ');
	getline(MovieStream, title, ',');

	return true; 
}
