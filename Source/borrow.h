//---------------------------------------------------------------------------
// BORROW.H
// Class that performs a borrow transaction
//
//---------------------------------------------------------------------------
// Borrow class: inherits functinality from the Transaction class, and 
// overrides part of its functionality: 
//		- Create function, returns new Borrow object
//		- Perfom function, Adds movie to the customer's object
//
// Implementation and assumptions:
//		- The perform function checks if the movie exists, if customer 
//			already has the movie
//		- If the requested movie passes the checks, the movie count is 
//			decremented, the movie is added to the customer, and Transaction
//			is added to the transaction list
//---------------------------------------------------------------------------

#ifndef BORROW_H
#define BORROW_H

#include <iostream> 
using namespace std;

#include "transaction.h"
#include "store.h"

class Store; 

class Borrow : public Transaction
{
public:
//---------------------------------------------------------------------------
// Default Constructor
// Preconditions:	None
// Postconditions:	Transaction's char "action" is set to 'B'
//---------------------------------------------------------------------------
	Borrow();

//---------------------------------------------------------------------------
// Default Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
	~Borrow();

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	New borrow object is returned
// Overrides Transaction's virtual Create
//---------------------------------------------------------------------------
	virtual Transaction* Create() const; 

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
	virtual bool Perform(Store&); 
};

#endif

