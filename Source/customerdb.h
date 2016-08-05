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
#ifndef CUSTOMERDB_H
#define CUSTOMERDB_H

#include <iostream>
using namespace std; 

#include "customer.h"

class CustomerDB
{
public:
//---------------------------------------------------------------------------
// Default Destructor
// Preconditions:	None
// Postconditions:	All array elements are NULL	
// Sets every element in the array to NULL
//---------------------------------------------------------------------------
	CustomerDB();

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	Deletes all the elements in the array and sets them to 
//					NULL
//---------------------------------------------------------------------------
	~CustomerDB();

//---------------------------------------------------------------------------
// AddCustomer
// Preconditions:	Customer pointer is passed in
// Postconditions:	Customer is added to the database
// Checks the index of the customer, checks if the index in the array is not 
// taken, sets the customer in the array and returns true
//---------------------------------------------------------------------------
	bool AddCustomer(Customer*); 

//---------------------------------------------------------------------------
// getCustomer
// Preconditions:	Appropriate ID is passed in (0 < x <= 9999)
// Postconditions:	Customer pointer is returned 
// Goes to the hashtable and retrieves the custumer by their ID
//---------------------------------------------------------------------------
	Customer* getCustomer(const int&) const; 

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	All of the customers in the databse are displayede
// Iterates through the hash table and prints out to console the customers
//---------------------------------------------------------------------------
	void Display() const; 

private: 
	static const int MAX_CUSTOMERS = 10000;			// constant of max customers
	Customer* customerHashtable[MAX_CUSTOMERS];		// hash table for customers
};

#endif

