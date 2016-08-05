//---------------------------------------------------------------------------
// BORROW.H
// Class that performs a borrow transaction
//
//---------------------------------------------------------------------------
// Borrow class: inherits functinality from the Transaction class, and 
// overrides part of its fucntionality: 
//		- Create fucntion, returns new Borrow object
//		- Perfom fucntion, Adds movie to the customer's object
//
// Implementation and assumptions:
//		- The perform fucntion checks if the movie exists, if customer 
//			already has the movie
//		- If the requested movie passes the checks, the movie count is 
//			decremented, the movie is added to the customer, and Transaction
//			is added to the transaction list
//---------------------------------------------------------------------------
#include "stdafx.h"
#include "borrow.h"

//---------------------------------------------------------------------------
// Default Constructor
// Preconditions:	None
// Postconditions:	Transaction's char "action" is set to 'B'
//---------------------------------------------------------------------------
Borrow::Borrow()
{
	action = 'B'; 
}

//---------------------------------------------------------------------------
// Default Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
Borrow::~Borrow()
{
}

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	New borrow object is returned
// Overrides Transaction's virtual Create
//---------------------------------------------------------------------------
Transaction* Borrow::Create() const
{
	return new Borrow; 
}

//---------------------------------------------------------------------------
// Perform
// Preconditions:	Movie exists, Movie Count is not 0, Customer doen't have 
//					the movie 
// Postconditions:	Customer has the movie, movie count is decremented
// Overrides Transactions virtual Perform. Before Performing the transaction
// the fucntion checks for validity. Then adds the movie to customer sets 
// performed variable to true and adds the transaction to the transaction
// list
//---------------------------------------------------------------------------
bool Borrow::Perform(Store& store)
{
	store.getInventory().Retrieve(*tempMovie, movie); 

	if (movie == NULL)
	{
		performed = false; 
		return false; 
	}

	else if (movie->getCount() < 1)
	{
		performed = false; 
		return false; 
	}

	else if (customer->HasMovie(movie))
	{
		performed = false;
		return false;
	}

	else if (!movie->DecrementCount())
		return false; 

	else
	{
		customer->AddMovie(movie); 
		performed = true; 
		customer->getTransactionList().Insert(this); 

		return true; 
	}
}