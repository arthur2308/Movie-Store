//---------------------------------------------------------------------------
// MOVIE.H
// Class for  movies
//---------------------------------------------------------------------------
// Movie class:  class used by movies, consists mostly of virtual classes
//					used by Movie's subclasses: Drama, Funny, Classic
//	- == operator Checks if the movies are the same
//	- != operator Checks if the movies are not the same
//	- < operator Checks if the compared movie is less than "this" movie
//	- < operator Checks if the compared movie is more than "this" movie
//
// Implementation and assumptions:
//	- MAX COUNT is set to 10 
//	- stores director, title, year, format, genre, count, and max count
//---------------------------------------------------------------------------
#include "stdafx.h"
#include "movie.h"

//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	director, title, year, format, and count are set to their
//					defaults
//---------------------------------------------------------------------------
Movie::Movie()
{
	director = "";
	title = "";
	year = -1;
	format = ' ';
	count = 10;
}

//---------------------------------------------------------------------------
// Virtual Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
Movie::~Movie()
{
}

//---------------------------------------------------------------------------
// Output operator 
// Preconditions:	None
// Postconditions:	ostream is returned
// Calls the Display function 
//---------------------------------------------------------------------------
ostream& operator<<(ostream& os, const Movie& movie)
{
	movie.Display(os);
	return os;
}

//---------------------------------------------------------------------------
// Equality operator 
// Preconditions:	None
// Postconditions:	returns true if director, title, and year are the same
//---------------------------------------------------------------------------
bool Movie::operator==(const Movie& movie) const
{
	return director == movie.director && title == movie.title &&
		year == movie.year;
}

//---------------------------------------------------------------------------
// Inequality operator 
// Preconditions:	None
// Postconditions:	returns true if director, title, and year are not same
//---------------------------------------------------------------------------
bool Movie::operator!=(const Movie& movie) const
{
	return !(*this == movie);
}

//---------------------------------------------------------------------------
// getGenre
// Preconditions:	None
// Postconditions:	returns genre char 
//---------------------------------------------------------------------------
char Movie::getGenre() const
{
	return genre;
}

//---------------------------------------------------------------------------
// getCount
// Preconditions:	None
// Postconditions:	returns count int 
//---------------------------------------------------------------------------
int Movie::getCount() const
{
	return count;
}

//---------------------------------------------------------------------------
// Less than operator 
// Preconditions:	None
// Postconditions:	returns true if director, title, and year are less than 
//					the compared movie
//---------------------------------------------------------------------------
bool Movie::operator<(const Movie& rMovie) const
{
	if (title.compare(rMovie.title) < 0)
	{
		return false;
	}

	if (director.compare(rMovie.director) < 0)
	{
		return false;
	}

	if (year < rMovie.year && format < rMovie.format)
	{
		return false;
	}
	return true;
}

//---------------------------------------------------------------------------
// More than operator 
// Preconditions:	None
// Postconditions:	returns true if director, title, and year are more than 
//					the compared movie
//---------------------------------------------------------------------------
bool Movie::operator>(const Movie& rMovie) const
{
	return !(*this < rMovie);
}

//---------------------------------------------------------------------------
// IncrementCount
// Preconditions:	None
// Postconditions:	Adds one to count variable
// First makes sure that count is not more than 10
//---------------------------------------------------------------------------
bool Movie::IncrementCount()
{
	if (count < 10)
	{
		count++;
		return true;
	}
	else
	{
		return false;
	}
}

//---------------------------------------------------------------------------
// DecrementCount
// Preconditions:	None
// Postconditions:	Subtracts one from count variable
// First makes sure that count is not more less than 0
//---------------------------------------------------------------------------
bool Movie::DecrementCount()
{
	if (count > 0)
	{
		count--;
		return true;
	}
	else
	{
		return false;
	}
}

//---------------------------------------------------------------------------
// setData
// Preconditions:	istream is well-formed
// Postconditions:	The variables are appropriately initialized
// Parses the istream and sets the variables
//---------------------------------------------------------------------------
bool Movie::setData(istream& input)
{
	string strYear;

	input.ignore(1, ' ');
	getline(input, director, ',');
	input.ignore(1, ' ');
	getline(input, title, ',');
	input.ignore(1, ' ');
	getline(input, strYear);

	year = stoi(strYear);

	return true;
}

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	The variables are displayed on the console
//---------------------------------------------------------------------------
void Movie::Display(ostream &os) const
{
	os << genre << " " << director << ", " << title << ", " << year;
}

