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
#include "stdafx.h"
#include "transactionlist.h"

//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	head and tail are set to NULL
//---------------------------------------------------------------------------
TransactionList::TransactionList()
{
	head = tail = NULL;
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	List is Empty
// Goes through the list and deletes the nodes and then sets them to NULL
//---------------------------------------------------------------------------
TransactionList::~TransactionList()
{
	while (head != NULL)		// goes through the list 
	{
		Node* temp = head->next; 
		delete head->transaction;		// deletes transaction
		head->transaction = NULL; 
		delete head;			// deletes head 
		head = temp; 
	}

	head = NULL;			// deletes pointers
	tail = NULL;
}

//---------------------------------------------------------------------------
// isEmpty
// Preconditions:	None
// Postconditions:	Return true or false depending on if the list is Empty 
// Checks if the head is NULL
//---------------------------------------------------------------------------
bool TransactionList::isEmpty() const
{
	return head == NULL; 
}

//---------------------------------------------------------------------------
// Insert
// Preconditions:	None 
// Postconditions:	Transaction is inserted into the list
// Goes through the list and places the transaction at the end
//---------------------------------------------------------------------------
void TransactionList::Insert(Transaction* transaction)
{
	Node* insNode = new Node; 
	insNode->transaction = transaction;		// sets transaction 

	if (head == NULL)						// checks if empty 
	{
		head = tail = insNode;
	}

	else if (head->next == NULL)
	{
		head->next = insNode;
		tail = insNode; 
	}

	else
	{
		tail->next = insNode;				//traversing
		tail = insNode; 
	}
}

//---------------------------------------------------------------------------
// Display
// Preconditions:	None 
// Postconditions:	Transactions are printed out on the console
//---------------------------------------------------------------------------
void TransactionList::Display() const
{
	Node* current = head; 

	while (current != NULL)
	{
		//cout << *(current->transaction) << endl;
		current = current->next; 
	}
}
