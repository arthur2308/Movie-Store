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
#include "stdafx.h"
#include "transaction.h"
#include "store.h"

//---------------------------------------------------------------------------
// Default Constructor
// Preconditions:	None
// Postconditions:	Perfomed is false
//---------------------------------------------------------------------------
Transaction::Transaction()
{
	performed = false; 
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	Deletes tempMovie
//---------------------------------------------------------------------------
Transaction::~Transaction()
{
	delete tempMovie; 
}


//---------------------------------------------------------------------------
// setData
// Preconditions: istream is well-formed
// Postconditions: all the variables are set accroding to the istream
// Create customer object, movieFactory, sets all of their variables 
// appropriately
//---------------------------------------------------------------------------
bool Transaction::setData(istream& input, Store& store)
{
	int tempID;
	char tempFormat; 
	char tempGenre; 
	string dump;

	input >> tempID; 

	customer = store.getCustomerDB().getCustomer(tempID);	// customer obj

	if (customer == NULL)
	{
		cout << "ERROR: customer doesn't exist" << endl;
		getline(input, dump);
		return false; 
	}

	input >> tempFormat; 

	if (tempFormat != 'D')						// check video format
	{
		cout << "ERROR: invalid video format" << endl; 
		getline(input, dump); 
		return false; 
	}

	input >> tempGenre; 

	tempMovie = store.getMovieFactory().Create(tempGenre); //tempMovie

	if (tempMovie == NULL)					// checks the movie genre
	{
		cout << "ERROR: invalid movie genre" << endl; 
		getline(input, dump); 
		return false; 
	}

	if (!tempMovie->setTempData(input))			// sets the data 
	{
		cout << "ERROR: invalid movie data" << endl; 
		getline(input, dump); 
		return false; 
	}
	return true; 
}

//---------------------------------------------------------------------------
// << operator
// Preconditions:	None
// Postconditions:	Displays action Customer and movie
// Calls the Display function
//---------------------------------------------------------------------------
ostream& operator<<(ostream& os, const Transaction& transaction)
{
	transaction.Display(os); 
	return os; 
}

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	Displays action Customer and Movie
//---------------------------------------------------------------------------
void Transaction::Display(ostream& os) const
{
	os << action << " " << *customer << " " << *movie; 
}
