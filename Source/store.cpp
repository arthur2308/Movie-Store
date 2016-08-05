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
#include "stdafx.h"
#include "store.h"

//---------------------------------------------------------------------------
// Default Constructor
// Preconditions:	None
// Postconditions:	Default values
//---------------------------------------------------------------------------
Store::Store(void)
{
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	Default values
//---------------------------------------------------------------------------
Store::~Store(void)
{
}

//---------------------------------------------------------------------------
// getMovieFactory
// Preconditions:	None
// Postconditions:	return MovieFactory reference 
//---------------------------------------------------------------------------
MovieFactory& Store::getMovieFactory()
{
	return movieFactory; 
}

//---------------------------------------------------------------------------
// getTransactionList
// Preconditions:	None
// Postconditions:	return TransactionList reference 
//---------------------------------------------------------------------------
TransactionList& Store::getTransactionList()
{
	return transactionList;
}

//---------------------------------------------------------------------------
// getCustomerDB
// Preconditions:	None
// Postconditions:	return CustomerDB reference 
//---------------------------------------------------------------------------
CustomerDB& Store::getCustomerDB()
{
	return customerDB;
}

//---------------------------------------------------------------------------
// getInventory
// Preconditions:	None
// Postconditions:	return Inventory reference 
//---------------------------------------------------------------------------
Inventory& Store::getInventory()
{
	return inventory; 
}

//---------------------------------------------------------------------------
// ProcessMovieFile
// Preconditions:	File exists
// Postconditions:	The data from the file is appropriately set
// Goes through the files and instatiates all the objects according to the 
// contents of the data file 
//---------------------------------------------------------------------------
bool Store::ProcessMovieFile(const string & filename)
{
	ifstream myfile(filename);

	if (!myfile)
	{
		cout << "ERROR: movie file could not be opened" << endl;
		return false;
	}

	while (!myfile.eof())			// goes through the file
	{
		char genre;
		myfile >> genre;

		Movie* movie = movieFactory.Create(genre); //creates a movie 

		if (movie != NULL)
		{
			movie->setData(myfile);					// sets the data
			inventory.Insert(movie);				// Inserts 
		}

		else
		{
			string dump; 
			getline(myfile, dump); 
		}
	}
	return true;
}

//---------------------------------------------------------------------------
// ProcessCustomerFile
// Preconditions:	File exists
// Postconditions:	The data from the file is appropriately set
// Goes through the files and instatiates all the objects according to the 
// contents of the data file 
//---------------------------------------------------------------------------
bool Store::ProcessCustomerFile(const string& filename)
{
	ifstream myfile(filename); 

	if (!myfile)
	{
		cout << "ERROR: movie file could not be opened" << endl;
		return false;
	}

	while (!myfile.eof())			// goes through the file
	{
		Customer* customer = new Customer;  //creates a customer 

		if (customer->setData(myfile))		// sets the data
		{
			customerDB.AddCustomer(customer); 
		}

		else
		{
			delete customer; 
			string dump; 
			getline(myfile, dump); 
		}
	}
	return true; 
}

//---------------------------------------------------------------------------
// ProcessTransactionFile
// Preconditions:	File exists
// Postconditions:	The data from the file is appropriately set
// Goes through the files and instatiates all the objects according to the 
// contents of the data file 
//---------------------------------------------------------------------------
bool Store::ProcessTransactionFile(const string& filename)
{
	ifstream myfile(filename); 

	if (!myfile)
	{
		return false;
		cout << "ERROR: movie file could not be opened" << endl;
	}

	while (true)				// goes through the file
	{
		char action;
		myfile >> action;

		if (myfile.eof())
			break;
		
		// Creates a transaction object
		Transaction* transaction = transactionFactory.Create(action);

		if (transaction != NULL)
		{
			if (!transaction->setData(myfile, *this))	//sets data
			{
				delete transaction;
				continue;
			}

			if (!transaction->Perform(*this))	//perform the transaction
			{
				delete transaction;
				continue;
			}
		}

		else
		{
			cout << "ERROR: invalid transaction type" << endl;
			string dump;
			getline(myfile, dump);
		}
		
	}
	return true; 
}

