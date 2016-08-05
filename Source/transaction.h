//---------------------------------------------------------------------------
// TRANSACTION.H
// Class for transaction
//---------------------------------------------------------------------------
// Transaction class:	Used to create, setData, and perform transactions
//	- Create, overriden by subclasses
//	- setData, parses istream and sets the variables
//	- << operator, displays  action, customer, and the movie
//
// Implementation and assumptions:
//	- Uses virtual classes that are then overriden by Transactions's 
//		subclasses
//---------------------------------------------------------------------------
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
using namespace std;


#include "customer.h"
#include "movie.h"

class Store;


class Transaction
{
//---------------------------------------------------------------------------
// << operator
// Preconditions:	None
// Postconditions:	Displays action Customer and movie
// Calls the Display function
//---------------------------------------------------------------------------
	friend ostream& operator<<(ostream&, const Transaction&); 

public:

//---------------------------------------------------------------------------
// Default Constructor
// Preconditions:	None
// Postconditions:	Perfomed is false
//---------------------------------------------------------------------------
	Transaction();

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	Deletes tempMovie
//---------------------------------------------------------------------------
	~Transaction();

//---------------------------------------------------------------------------
// Create
// Virtual class overriden by subclass
// Implementation details are in the subclass
//---------------------------------------------------------------------------
	virtual Transaction* Create() const = 0; 

//---------------------------------------------------------------------------
// setData
// Preconditions: istream is well-formed
// Postconditions: all the variables are set accroding to the istream
// Create customer object, movieFactory, sets all of their variables 
// appropriately
//---------------------------------------------------------------------------
	virtual bool setData(istream&, Store&); 

//---------------------------------------------------------------------------
// Perform
// Virtual class overriden by subclass
// Implementation details are in the subclass
//---------------------------------------------------------------------------
	virtual bool Perform(Store&) = 0; 

protected:
	char action;			// Transaction type
	bool performed;			// check if transaction is performed
	Customer* customer;		// Customer object
	Movie* movie;			// Movie object
	Movie* tempMovie = NULL;	// TempMovie object

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	Displays action Customer and Movie
//---------------------------------------------------------------------------
	virtual void Display(ostream&) const;
};

#endif