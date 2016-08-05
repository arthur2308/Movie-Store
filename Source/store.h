//---------------------------------------------------------------------------
// STORE.H
// Class for the store
//---------------------------------------------------------------------------
// Store class:	Used to process Movie Files, Customer Files, Transaction
//				Files, has getters: 
//	- getInventory, returns Inventory
//	- getcustomerDB, returns customerDB
//	- getMovieFactory, returns Movie Factory
//  - getTransactionList. returns Transaction List
//
// Implementation and assumptions:
//	- has the following objects: Inventory, customerDB, movieFactory, 
//  - transactionList and transaction Factory
//---------------------------------------------------------------------------
#ifndef STORE_H
#define STORE_H

#include <iostream> 
#include <string> 
#include <fstream>
using namespace std;

#include "customer.h"
#include "movie.h"
#include "moviefactory.h"
#include "transaction.h"
#include "transactionfactory.h" 
#include "transactionlist.h"
#include "inventory.h" 
#include "customerdb.h"

class Store
{
public:
//---------------------------------------------------------------------------
// Default Constructor
// Preconditions:	None
// Postconditions:	Default values
//---------------------------------------------------------------------------
	Store();

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	Default values
//---------------------------------------------------------------------------
	~Store();

//---------------------------------------------------------------------------
// getInventory
// Preconditions:	None
// Postconditions:	return Inventory reference 
//---------------------------------------------------------------------------
	Inventory& getInventory(); 

//---------------------------------------------------------------------------
// getCustomerDB
// Preconditions:	None
// Postconditions:	return CustomerDB reference 
//---------------------------------------------------------------------------
	CustomerDB& getCustomerDB(); 

//---------------------------------------------------------------------------
// getMovieFactory
// Preconditions:	None
// Postconditions:	return MovieFactory reference 
//---------------------------------------------------------------------------
	MovieFactory& getMovieFactory(); 

//---------------------------------------------------------------------------
// getTransactionList
// Preconditions:	None
// Postconditions:	return TransactionList reference 
//---------------------------------------------------------------------------
	TransactionList& getTransactionList(); 

//---------------------------------------------------------------------------
// ProcessMovieFile
// Preconditions:	File exists
// Postconditions:	The data from the file is appropriately set
// Goes through the files and instatiates all the objects according to the 
// contents of the data file 
//---------------------------------------------------------------------------
	bool ProcessMovieFile(const string &);

//---------------------------------------------------------------------------
// ProcessCustomerFile
// Preconditions:	File exists
// Postconditions:	The data from the file is appropriately set
// Goes through the files and instatiates all the objects according to the 
// contents of the data file 
//---------------------------------------------------------------------------
	bool ProcessCustomerFile(const string &);

//---------------------------------------------------------------------------
// ProcessTransactionFile
// Preconditions:	File exists
// Postconditions:	The data from the file is appropriately set
// Goes through the files and instatiates all the objects according to the 
// contents of the data file 
//---------------------------------------------------------------------------
	bool ProcessTransactionFile(const string &);

private:
	Inventory inventory;			// inventory class object
	CustomerDB customerDB;			// CustomerDB class object 
	MovieFactory movieFactory;		// movieFactory class object
	TransactionList transactionList; // transactionList class object
	TransactionFactory transactionFactory;	// transactionFactory class obj
};

#endif 