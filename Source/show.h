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
#ifndef SHOW_H
#define SHOW_H

#include <iostream>
using namespace std; 

#include "transaction.h"
#include "store.h"

class Store; 

class Show : public Transaction
{
public:

//---------------------------------------------------------------------------
// Default Constructor
// Preconditions:	None
// Postconditions:	Transaction's char "action" is set to 'B'
//---------------------------------------------------------------------------
	Show();

//---------------------------------------------------------------------------
// Default Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
	~Show();

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	New show object is returned
// Overrides Transaction's virtual Create
//---------------------------------------------------------------------------
	virtual Transaction* Create() const; 

//---------------------------------------------------------------------------
// setData
// Preconditions:	None
// Postconditions:	true
//---------------------------------------------------------------------------
	virtual bool setData(istream&, Store&); 

//---------------------------------------------------------------------------
// Perform
// Preconditions:	None
// Postconditions:	Transactions are displayed
// Overrides Transactions virtual Perform. Inserts the transaction into 
// the transaction list and then Displays the transactions
//---------------------------------------------------------------------------
	virtual bool Perform(Store&);

private: 
//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	"Show trabsactoin is in the ostream"
//---------------------------------------------------------------------------
	virtual void Display(ostream&) const; 
};

#endif

