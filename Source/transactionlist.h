//---------------------------------------------------------------------------
// TRANSACTIONLIST.H
// Class for Transaction List
//---------------------------------------------------------------------------
//Transaction List class:  class used to store transactions in a list
//   Implements the following operations for the list
//	- Insert, inserts a transaction in the list
//	- isEpmty, checks if the list is empty 
//	- Display, displays the list 
//
// Implementation and assumptions:
//	- Uses a "linked-list" like structure
//---------------------------------------------------------------------------
#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

#include <iostream>
using namespace std; 

class Transaction; //forward declaration 

class TransactionList
{
public:
//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	head and tail are set to NULL
//---------------------------------------------------------------------------
	TransactionList();

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	List is Empty
// Goes through the list and deletes the nodes and then sets them to NULL
//---------------------------------------------------------------------------
	~TransactionList(); 

//---------------------------------------------------------------------------
// isEmpty
// Preconditions:	None
// Postconditions:	Return true or false depending on if the list is Empty 
// Checks if the head is NULL
//---------------------------------------------------------------------------
	bool isEmpty() const; 

//---------------------------------------------------------------------------
// Insert
// Preconditions:	None 
// Postconditions:	Transaction is inserted into the list
// Goes through the list and places the transaction at the end
//---------------------------------------------------------------------------
	void Insert(Transaction*); 

//---------------------------------------------------------------------------
// Display
// Preconditions:	None 
// Postconditions:	Transactions are printed out on the console
//---------------------------------------------------------------------------
	void Display() const; 


private: 

	struct Node			// declaring node structure 
	{
		Node* next = NULL; 
		Transaction* transaction;	// transaction pointer
	};

	Node* head;			// head pointer
	Node* tail;			// tail pointer 
};

#endif

