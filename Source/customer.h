//---------------------------------------------------------------------------
// CUSTOMER.H
// Class for customers
//---------------------------------------------------------------------------
// Customer class:	Used to create customer object
//	- == operator Checks if the movies are the same
//	- != operator Checks if the movies are not the same
//	- < operator Checks if the compared movie is less than "this" movie
//	- < operator Checks if the compared movie is more than "this" movie
//
// Implementation and assumptions:
//	- Overrides Movie's create and setTempData functions
//---------------------------------------------------------------------------
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream> 
#include <list> 
#include <queue>
#include <string>
#include <algorithm>

using namespace std; 

#include "movie.h"

#include "transactionlist.h" 

class Transaction; //forward declaration 

class Customer
{
//---------------------------------------------------------------------------
// Overloaded output operator
// Preconditions:	Customer is passed in with appropriate values
// Postconditions:	Prints ou to the console Customer's data
//---------------------------------------------------------------------------
	friend ostream& operator<<(ostream&, const Customer&); 

public: 
//---------------------------------------------------------------------------
// Deafult Destructor
// Preconditions:	None
// Postconditions:	sets last and first to empty string, and id to -1
//---------------------------------------------------------------------------
	Customer(); 

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
	~Customer(); 

//---------------------------------------------------------------------------
// setData
// Preconditions:	istream is well-formed
// Postconditions:	Parses istream and sets the variables accordingly
//					returns true if successful, false otherwise
//---------------------------------------------------------------------------
	bool setData(istream&); 

//---------------------------------------------------------------------------
// getID
// Preconditions:	Nonde
// Postconditions:	Returns int ID of the customer object
//---------------------------------------------------------------------------
	int getID() const; 

//---------------------------------------------------------------------------
// getTransactionList
// Preconditions:	None
// Postconditions:	Returns reference to the transaction list object
//---------------------------------------------------------------------------
	TransactionList& getTransactionList(); 

//---------------------------------------------------------------------------
// AddMovie
// Preconditions:	Movie object is passed in
// Postconditions:	Adds the movie the movieList and returns true
//---------------------------------------------------------------------------
	bool AddMovie(Movie*); 

//---------------------------------------------------------------------------
// RemoveMovie
// Preconditions:	Movie exists in the movieList
// Postconditions:	Removes the movie from the movieList and returns true;
//---------------------------------------------------------------------------
	bool RemoveMovie(Movie*); 

//---------------------------------------------------------------------------
// HasMovie
// Preconditions:	Movie object is passed in
// Postconditions:	Returns true or false, depending if the movie exists
//---------------------------------------------------------------------------
	bool HasMovie(Movie*) const; 

//---------------------------------------------------------------------------
// DisplayHistory
// Preconditions:	None
// Postconditions:	Calls transactionList's Display fucntion
//---------------------------------------------------------------------------
	void DisplayHistory() const; 


private: 
	string last;						// last name of the customer
	string first;						// first name of the customer
	int id;								// id of the customer
	const int MAX_ID = 9999;			// costant idetifying maximum ID

	list<Movie*> movieList;				// movie List
	TransactionList transactionList;	// transaction List
};

#endif 