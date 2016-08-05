//---------------------------------------------------------------------------
// HISTORY.H
// Class that performs a history transaction
//
//---------------------------------------------------------------------------
// History class: inherits functinality from the Transaction class, and 
// overrides part of its fucntionality: 
//		- Create function, returns new History object
//		- Perfom function, Displays Customer's history
//		- setData function takes a stream, parses it and finds the customer 
//			by their ID
// Implementation and assumptions:
//		- The perform function sets performed to true and inserts "this" 
//			into transaction list 
//---------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H

#include <iostream> 
using namespace std; 

#include "transaction.h"
#include "store.h"
class Store; 

class History : public Transaction
{
public:
//---------------------------------------------------------------------------
// Default Constructor
// Preconditions:	None
// Postconditions:	Transaction's char "action" is set to 'B'
//---------------------------------------------------------------------------
	History();

//---------------------------------------------------------------------------
// Default Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
	~History();

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	New history object is returned
// Overrides Transaction's virtual Create
//---------------------------------------------------------------------------
	virtual Transaction* Create() const; 

//---------------------------------------------------------------------------
// setData
// Preconditions:	istream is well-formed
// Postconditions:	returns true if customer with ID is not NULL 
// Overrides Transaction's virtual setData.
//---------------------------------------------------------------------------
	virtual bool setData(istream&, Store&);

//---------------------------------------------------------------------------
// Perform
// Preconditions:	None
// Postconditions:	Customer's history is displayed on the console
// Sets Perfomed to true, gets the store and inserts "this" transaction,
// goes to history and calls their DisplayHistory() function 
//---------------------------------------------------------------------------
	virtual bool Perform(Store&); 

private: 
//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	"History transaction" is displayed on the console
//---------------------------------------------------------------------------
	virtual void Display(ostream& os) const; 
};

#endif

