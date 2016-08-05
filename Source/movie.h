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
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string> 
#include <sstream> 
using namespace std;

class Movie
{
	friend ostream& operator<<(ostream&, const Movie&);

public:

//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	director, title, year, format, and count are set to their
//					defaults
//---------------------------------------------------------------------------
	Movie();

//---------------------------------------------------------------------------
// Virtual Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
	virtual ~Movie();

//	virtual == operator Checks if the movies are the same
//	Implemnted in subclasses
	virtual bool operator==(const Movie&) const;

//	virtual != operator Checks if the movies are not the same
//	Implemnted in subclasses
	virtual bool operator!=(const Movie&) const;

//---------------------------------------------------------------------------
// Less than operator 
// Preconditions:	None
// Postconditions:	returns true if director, title, and year are less than 
//					the compared movie
//---------------------------------------------------------------------------
	virtual bool operator<(const Movie&) const = 0;

//---------------------------------------------------------------------------
// More than operator 
// Preconditions:	None
// Postconditions:	returns true if director, title, and year are more than 
//					the compared movie
//---------------------------------------------------------------------------
	virtual bool operator>(const Movie&) const = 0;

//---------------------------------------------------------------------------
// getGenre
// Preconditions:	None
// Postconditions:	returns genre char 
//---------------------------------------------------------------------------
	char getGenre() const;

//---------------------------------------------------------------------------
// getCount
// Preconditions:	None
// Postconditions:	returns count int 
//---------------------------------------------------------------------------
	int getCount() const;

//---------------------------------------------------------------------------
// IncrementCount
// Preconditions:	None
// Postconditions:	Adds one to count variable
// First makes sure that count is not more than 10
//---------------------------------------------------------------------------
	bool IncrementCount();

//---------------------------------------------------------------------------
// DecrementCount
// Preconditions:	None
// Postconditions:	Subtracts one from count variable
// First makes sure that count is not more less than 0
//---------------------------------------------------------------------------
	bool DecrementCount();

// Create
// Returns a Movie pointer
// Implemented in sublclasses
	virtual Movie* Create() const = 0;

//---------------------------------------------------------------------------
// setData
// Preconditions:	istream is well-formed
// Postconditions:	The variables are appropriately initialized
// Parses the istream and sets the variables
//---------------------------------------------------------------------------
	virtual bool setData(istream&);

// setTempData
// Returns a true or false if successful setting
// Implemented in sublclasses
	virtual bool setTempData(istream&) = 0; 


protected:
	string director;	// movie director fname, lname 
	string title;		// movie title
	int year;			// year movie was released
	char format;		// movie format
	char genre;			// movie genre
	int count;			// movie count
	static const int MAX_COUNT = 10;	// MAX COUNT is set to 10

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	The variables are displayed on the console
//---------------------------------------------------------------------------
	virtual void Display(ostream &) const;
};

#endif