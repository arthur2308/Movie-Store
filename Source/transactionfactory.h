//---------------------------------------------------------------------------
//TRANSACTIONFACTORY.H
// Class for TransactionFactory
//---------------------------------------------------------------------------
//TransactionFactory class:  Class creates transactions. 
//							 Uses an array to store them
//	- Create, Creates a transaction the transactionPool array 
//	- hash return ASCII value of char minus ASCII value of 'A'
//
// Implementation and assumptions:
//	- MAX POOL SIZE is set to 26
//	- Uses an array for transactionPool
//---------------------------------------------------------------------------
#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <iostream> 

using namespace std; 

#include "transaction.h"
#include "borrow.h" 
#include "return.h"
#include "history.h"
#include "show.h"

class TransactionFactory
{
public:
//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	Sets the elements inside the array to NULL
// Except for 1 17 7 18
//---------------------------------------------------------------------------
	TransactionFactory();

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	All the aray elements are deleted and set to NULL
//---------------------------------------------------------------------------
	~TransactionFactory();

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	Transaction is created 
// Goes into transactionPool array and calls the transaction's 
// create function to create the transaction 
//---------------------------------------------------------------------------
	Transaction* Create(const char&) const;

private: 
	static const int MAX_POOL_SIZE = 26; // set to 26
	Transaction* transactionPool[MAX_POOL_SIZE];	// Creating the array 

//---------------------------------------------------------------------------
// hash
// Preconditions:	none
// Postconditions:	Retruns an int corresponding to chars alphabet's index
//---------------------------------------------------------------------------
	int hash(const char&) const; 
};

#endif

