//---------------------------------------------------------------------------
// SHOW.H
// Class that performs a show transaction
//
//---------------------------------------------------------------------------
// Show class: inherits functinality from the Transaction class, and 
// overrides part of its functionality: 
//		- Create function, returns new Show object
//		- Perfom function, adds transaction to transaction list and displays
//			the transactions
//---------------------------------------------------------------------------
#include "stdafx.h"
#include "show.h"

//---------------------------------------------------------------------------
// Default Constructor
// Preconditions:	None
// Postconditions:	Transaction's char "action" is set to 'B'
//---------------------------------------------------------------------------
Show::Show()
{
	action = 'S'; 
}

//---------------------------------------------------------------------------
// Default Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
Show::~Show()
{
}

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	New show object is returned
// Overrides Transaction's virtual Create
//---------------------------------------------------------------------------
Transaction* Show::Create() const
{
	return new Show; 
}

//---------------------------------------------------------------------------
// setData
// Preconditions:	None
// Postconditions:	true
//---------------------------------------------------------------------------
bool Show::setData(istream& transactionStream, Store& store)
{
	return true; 
}

//---------------------------------------------------------------------------
// Perform
// Preconditions:	None
// Postconditions:	Transactions are displayed
// Overrides Transactions virtual Perform. Inserts the transaction into 
// the transaction list and then Displays the transactions
//---------------------------------------------------------------------------
bool Show::Perform(Store& store)
{
	performed = true; 
	store.getTransactionList().Insert(this); 
	store.getInventory().Display(); 

	return true; 
}

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	"Show trabsactoin is in the ostream"
//---------------------------------------------------------------------------
void Show::Display(ostream& os) const
{
	os << "Show transaction";
}