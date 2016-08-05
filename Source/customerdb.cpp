//---------------------------------------------------------------------------
// CUSTOMERDB.H
// Class for customers' database
//---------------------------------------------------------------------------
// Customer's database class:	Used to store customer object. 
//								Fucntionality includes:
//	- Adding a customer to the database
//	- Retrieving a customer from the database
//	- Displaying the database
//
// Implementation and assumptions:
//	- Maximum number of customers is 10,000
//	- Uses a hash table to store customer objects
//---------------------------------------------------------------------------
#include "stdafx.h"
#include "customerdb.h"

//---------------------------------------------------------------------------
// Deafult Destructor
// Preconditions:	None
// Postconditions:	All array elements are NULL	
// Sets every element in the array to NULL
//---------------------------------------------------------------------------
CustomerDB::CustomerDB()
{
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		customerHashtable[i] = NULL;
	}
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	Deletes all the elements in the array and sets them to 
//					NULL
//---------------------------------------------------------------------------
CustomerDB::~CustomerDB()
{
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		delete customerHashtable[i]; 
		customerHashtable[i] = NULL;
	}
}

//---------------------------------------------------------------------------
// AddCustomer
// Preconditions:	Customer pointer is passed in
// Postconditions:	Customer is added to the database
// Checks the index of the customer, checks if the index in the array is not 
// taken, sets the customer in the array and returns true
//---------------------------------------------------------------------------
bool CustomerDB::AddCustomer(Customer* customer)
{
	int index = customer->getID(); 

	if (index < 0 || index > 9999)
		return false;

	else if (customerHashtable[index] != NULL)
		return false; 

	else
	{
		customerHashtable[index] = customer; 
		return true;
	}
}

//---------------------------------------------------------------------------
// getCustomer
// Preconditions:	Appropriate ID is passed in (0 < x <= 9999)
// Postconditions:	Customer pointer is returned 
// Goes to the hashtable and retrieves the custumer by their ID
//---------------------------------------------------------------------------
Customer* CustomerDB::getCustomer(const int& id) const
{
	if (id < 0 || id > 9999)
		return NULL;

	else
		return customerHashtable[id]; 
}

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	All of the customers in the databse are displayede
// Iterates through the hash table and prints out to console the customers
//---------------------------------------------------------------------------
void CustomerDB::Display() const
{
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if (customerHashtable[i] != NULL)
		{
			cout << *(customerHashtable[i]) << endl;
		}
	}
}