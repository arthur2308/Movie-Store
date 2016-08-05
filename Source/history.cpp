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
#include "stdafx.h"
#include "history.h"

//---------------------------------------------------------------------------
// Default Constructor
// Preconditions:	None
// Postconditions:	Transaction's char "action" is set to 'B'
//---------------------------------------------------------------------------
History::History()
{
	action = 'H'; 
}

//---------------------------------------------------------------------------
// Default Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
History::~History()
{
}

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	New history object is returned
// Overrides Transaction's virtual Create
//---------------------------------------------------------------------------
Transaction* History::Create() const
{
	return new History; 
}

//---------------------------------------------------------------------------
// setData
// Preconditions:	istream is well-formed
// Postconditions:	returns true if customer with ID is not NULL 
// Overrides Transaction's virtual setData.
//---------------------------------------------------------------------------
bool History::setData(istream& transactionStream, Store& store)
{
	int tempID; 
	string dump; 
	transactionStream >> tempID; 

	customer = store.getCustomerDB().getCustomer(tempID); 

	if (customer == NULL)
	{
		getline(transactionStream, dump); 
		return false; 
	}

	return true;
}

//---------------------------------------------------------------------------
// Perform
// Preconditions:	None
// Postconditions:	Customer's history is displayed on the console
// Sets Perfomed to true, gets the store and inserts "this" transaction,
// goes to history and calls their DisplayHistory() function 
//---------------------------------------------------------------------------
bool History::Perform(Store& store)
{
	performed = true; 
	store.getTransactionList().Insert(this); 
	customer->DisplayHistory(); 

	return true; 
}

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	"History transaction" is displayed on the console
//---------------------------------------------------------------------------
void History::Display(ostream& os) const
{
	os << "History transaction"; 
}
