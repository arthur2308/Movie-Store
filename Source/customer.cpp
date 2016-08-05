//---------------------------------------------------------------------------
// CUSTOMER.H
// Class for customers
//---------------------------------------------------------------------------
// Customer class:	Used to create customer object
//	- == operator Checks if the movies are the same
//	- != operator Checks if the movies are not the same
//	- < operator Checks if the compared movie is less than "this" movie
//	- < operator Checks if the compared movie is more than "this" movie
//
// Implementation and assumptions:
//	- Overrides Movie's create and setTempData functions
//---------------------------------------------------------------------------
#include "stdafx.h"
#include "customer.h"

//---------------------------------------------------------------------------
// Deafult Destructor
// Preconditions:	None
// Postconditions:	sets last and first to empty string, and id to -1
//---------------------------------------------------------------------------
Customer::Customer()
{
	last = first = "";
	id = -1; 
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	No leaks
//---------------------------------------------------------------------------
Customer::~Customer()
{
}

//---------------------------------------------------------------------------
// Overloaded output operator
// Preconditions:	Customer is passed in with appropriate values
// Postconditions:	Prints ou to the console Customer's data
//---------------------------------------------------------------------------
ostream& operator<<(ostream& os, const Customer& customer)
{
	os << customer.id << " " << customer.last << " " << customer.first; 
	return os; 
}

//---------------------------------------------------------------------------
// setData
// Preconditions:	istream is well-formed
// Postconditions:	Parses istream and sets the variables accordingly
//					returns true if successful, false otherwise
//---------------------------------------------------------------------------
bool Customer::setData(istream& input)
{
	input >> id; 

	if (id < 0 || id > MAX_ID)
		return false; 
	
	else
	{
		input >> last >> first; 
		return true; 
	}
}

//---------------------------------------------------------------------------
// getID
// Preconditions:	Nonde
// Postconditions:	Returns int ID of the customer object
//---------------------------------------------------------------------------
int Customer::getID() const
{
	return id; 
}

//---------------------------------------------------------------------------
// getTransactionList
// Preconditions:	None
// Postconditions:	Returns reference to the transaction list object
//---------------------------------------------------------------------------
TransactionList& Customer::getTransactionList()
{
	return transactionList;
}

//---------------------------------------------------------------------------
// AddMovie
// Preconditions:	Movie object is passed in
// Postconditions:	Adds the movie the movieList and returns true
//---------------------------------------------------------------------------
bool Customer::AddMovie(Movie* movie)
{
	movieList.push_back(movie); 
	return true; 
}

//---------------------------------------------------------------------------
// RemoveMovie
// Preconditions:	Movie exists in the movieList
// Postconditions:	Removes the movie from the movieList and returns true;
//---------------------------------------------------------------------------
bool Customer::RemoveMovie(Movie* movie)
{
	if (HasMovie(movie))
	{
		movieList.remove(movie);
		return true;
	}

	else
		return false; 
}

//---------------------------------------------------------------------------
// HasMovie
// Preconditions:	Movie object is passed in
// Postconditions:	Returns true or false, depending if the movie exists
//---------------------------------------------------------------------------
bool Customer::HasMovie(Movie* movie) const
{
	list<Movie*>::const_iterator it;						// iterator
	it = find(movieList.begin(), movieList.end(), movie);	// iterates 

	if (it != movieList.end())			// if not found
		return true;

	else								// if found
		return false;	
}

//---------------------------------------------------------------------------
// DisplayHistory
// Preconditions:	None
// Postconditions:	Calls transactionList's Display fucntion
//---------------------------------------------------------------------------
void Customer::DisplayHistory() const
{
	transactionList.Display(); 
}
