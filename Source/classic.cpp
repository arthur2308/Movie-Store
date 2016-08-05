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
#include "stdafx.h"
#include "classic.h"

//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	char genre is set to 'C', actorLast and actorFirst are 
//					initialized to empty strings
//---------------------------------------------------------------------------
Classic::Classic()
{
	genre = 'C';
	actorLast = ""; 
	actorFirst = ""; 
}

//---------------------------------------------------------------------------
// Virtual Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
Classic::~Classic()
{
}

//---------------------------------------------------------------------------
// Operator ==
// Preconditions:	None
// Postconditions:	Returns true if director, title, actor's/actresse's name, 
//					year, and month are the same, false otherwise
// Uses dynamic casting that unlike static casting finds the object's class
// at runtime
//---------------------------------------------------------------------------
bool Classic::operator==(const Movie& movie) const
{
	return director == dynamic_cast<const Classic&>(movie).director &&
		title == dynamic_cast<const Classic&>(movie).title &&
		actorLast == dynamic_cast<const Classic&>(movie).actorLast &&
		actorFirst == dynamic_cast<const Classic&>(movie).actorFirst &&
		year == dynamic_cast<const Classic&>(movie).year &&
		month == dynamic_cast<const Classic&>(movie).month;
}

//---------------------------------------------------------------------------
// Operator !=
// Preconditions:	None
// Postconditions:	Returns true if director, title, actor's/actresse's name, 
//					year, and month are the same, false otherwise
// Calls the == operator to return true if the == operator return false
//---------------------------------------------------------------------------
bool Classic::operator!=(const Movie& movie) const
{
	return !(*this == movie);
}

//---------------------------------------------------------------------------
// Operator <
// Preconditions:	None
// Postconditions:	Returns true if director, title, actor's/actresse's name, 
//					year, and month are less than, false otherwise
// Uses dynamic casting that unlike static casting finds the object's class
// at runtime
//---------------------------------------------------------------------------
bool Classic::operator<(const Movie& movie) const
{
	if (*this == movie)
		return false;

	else if (year > dynamic_cast<const Classic&>(movie).year)
		return false;

	else if (month > dynamic_cast <const Classic&> (movie).month)
		return false;

	else if (actorLast > dynamic_cast<const Classic&> (movie).actorLast)
		return false;

	else if (actorFirst > dynamic_cast<const Classic&> (movie).actorFirst)
		return false;

	else
		return true;
}

//---------------------------------------------------------------------------
// Operator >
// Preconditions:	None
// Postconditions:	Returns true if director, title, actor's/actresse's name, 
//					year, and month are more than, false otherwise
// Calls the < operator to return true if the < operator return false
//---------------------------------------------------------------------------
bool Classic::operator>(const Movie& movie) const
{
	return !(*this < movie) && !(*this == movie);
}

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	Returns new Classic object 
//---------------------------------------------------------------------------
Movie* Classic::Create() const
{
	return new Classic;
}

//---------------------------------------------------------------------------
// setData
// Preconditions:	istream is well-formed
// Postconditions:	Parses istream and sets the variables accordingly
//					returns true if successful, false otherwise
//---------------------------------------------------------------------------
bool Classic::setData(istream& input)
{
	string strMonth, strYear;

	input.ignore(1, ' ');
	getline(input, director, ',');
	input.ignore(1, ' ');
	getline(input, title, ',');
	input.ignore(1, ' ');
	getline(input, actorFirst, ' ');
	getline(input, actorLast, ' ');
	getline(input, strMonth, ' ');
	getline(input, strYear);

	month = stoi(strMonth);
	year = stoi(strYear);

	return true;
}

//---------------------------------------------------------------------------
// setTempData
// Preconditions:	istream is well-formed
// Postconditions:	Parses istream and sets the variables accordingly
//					returns true if successful, false otherwise
//---------------------------------------------------------------------------
bool Classic::setTempData(istream& input)
{
	input.ignore(1, ' ');
	input >> month;
	input >> year; 
	input >> actorFirst;
	input >> actorLast; 

	return true; 
}

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	Sets the ostream to the movie's metadata
//---------------------------------------------------------------------------
void Classic::Display(ostream& os) const
{
	os << genre << " " << director << ", " << title << ", " << actorFirst <<
		" " << actorLast << " " << month << " " << year;
}