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
#include "stdafx.h"
#include "transactionfactory.h"

//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	Sets the elements inside the array to NULL
// Except for 1 17 7 18
//---------------------------------------------------------------------------
TransactionFactory::TransactionFactory()
{
	for (int i = 0; i < MAX_POOL_SIZE; i++)
		transactionPool[i] = NULL; 

	
	transactionPool[1] = new Borrow; 
	transactionPool[17] = new Return;
	transactionPool[7] = new History;
	transactionPool[18] = new Show;
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	All the aray elements are deleted and set to NULL
//---------------------------------------------------------------------------
TransactionFactory::~TransactionFactory()
{
	for (int i = 0; i < MAX_POOL_SIZE; i++)
	{
		delete transactionPool[i]; 
		transactionPool[i] = NULL; 
	}
}

//---------------------------------------------------------------------------
// Create
// Preconditions:	None
// Postconditions:	Transaction is created 
// Goes into transactionPool array and calls the transaction's 
// create function to create the transaction 
//---------------------------------------------------------------------------
Transaction* TransactionFactory::Create(const char& c) const
{
	int index = hash(c); 

	if (transactionPool[index] != NULL)
		return transactionPool[index]->Create();
	else
		return NULL; 
}

//---------------------------------------------------------------------------
// hash
// Preconditions:	none
// Postconditions:	Retruns an int corresponding to chars alphabet's index
//---------------------------------------------------------------------------
int TransactionFactory::hash(const char& c) const
{
	return c - 'A'; 
}
