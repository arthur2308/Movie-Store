//---------------------------------------------------------------------------
// RETURN.H
// Class that performs a return transaction
//
//---------------------------------------------------------------------------
// Return class: inherits functinality from the Transaction class, and 
// overrides part of its functionality: 
//		- Create function, returns new Return object
//		- Perfom function, Removes a movie from the customer's object
//
// Implementation and assumptions:
//		- The perform function checks if the movie exists, if customer 
//			already has the movie
//		- If the requested movie passes the checks, the movie count is 
//			incremented, the movie is removed from customer, and Transaction
//			is added to the transaction list
//---------------------------------------------------------------------------
#ifndef RETURN_H
#define RETURN_H

#include <iostream> 
using namespace std; 

#include "store.h"
#include "transaction.h"

class Store; 

class Return : public Transaction
{
public:

//---------------------------------------------------------------------------
// Default Constructor
// Preconditions:	None
// Postconditions:	Transaction's char "action" is set to 'R'
//---------------------------------------------------------------------------
	Return();

//---------------------------------------------------------------------------
// Default Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
	~Return();

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	New return object is returned
// Overrides Transaction's virtual Return
//---------------------------------------------------------------------------
	virtual Transaction* Create() const; 

//---------------------------------------------------------------------------
// Perform
// Preconditions:	Movie exists, Movie Count is not 10 or more
// Postconditions:	Customer doesnt have the movie
// Overrides Transactions virtual Perform. Before Performing the transaction
// the fucntion checks for validity. Then removes the movie from customer,
//	sets performed variable to true and adds the transaction to the 
//	transaction list
//---------------------------------------------------------------------------
	virtual bool Perform(Store&); 
};

#endif 
