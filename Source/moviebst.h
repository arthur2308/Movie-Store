//---------------------------------------------------------------------------
// MOVIEBST.H
// Class for Movie Binary Search Trees
//---------------------------------------------------------------------------
// Movie Binary Search Trees class:  class used by Movie Binary Search Trees, 
//										specifies how to perform 
//   the following operations with the trees:
//	- Insert, inserts a movie node in a tree
//	- Retrieve, retrieves a movie node from a tree
//	- makeEmpty, empties the tree
//	- Display, displays contents of the tree
//
// Implementation and assumptions:
//	- Uses recursive helper functions
//---------------------------------------------------------------------------
#ifndef MOVIEBST_H
#define MOVIEBST_H

#include <iostream>
using namespace std; 

#include "movie.h"

class MovieBST
{
public:
//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	root is set to NULL
//---------------------------------------------------------------------------
	MovieBST();

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	Tree is Empty
// Calls the makeEmpty() function to delete everything in the tree
//---------------------------------------------------------------------------
	~MovieBST();

//---------------------------------------------------------------------------
// Insert
// Preconditions:	None 
// Postconditions:	Movie is inserted into the tree
// Calls InsertHelper to insert the movie 
//---------------------------------------------------------------------------
	bool Insert(Movie*); 

//---------------------------------------------------------------------------
// Retrieve
// Preconditions:	None 
// Postconditions:	The result will be the found m ovie and the function will
//					return true or false; 
// Calls RetrieveHelper to retrive the movie 
//---------------------------------------------------------------------------
	bool Retrieve(const Movie&, Movie*&) const; 

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	Contents of tree is displayed
// Calls the DisplayHelper() function
//---------------------------------------------------------------------------
	void Display() const; 

private: 
	struct Node				// tree Node declaration
	{
		Movie* movie;		// movie pointer
		Node* left;			// left child pointer
		Node* right;		// right child pointer
	};
	Node* root;				// root pointer

//---------------------------------------------------------------------------
// InsertHelper
// Preconditions:	root is passed in 
// Postconditions:	Movie is inserted into the tree
// Creates a node to insert goes thrrough the tree and places the node into 
// appropriate place
	bool InsertHelper(Node*&, Movie*); 

//---------------------------------------------------------------------------
// RetrieveHelper
// Preconditions:	None 
// Postconditions:	The result will be the found movie and the function will
//					return true or false; 
// See if the current movie is the target movie, if not check the left 
// subtree then right
//---------------------------------------------------------------------------
	bool RetrieveHelper(const Movie&, Movie*&, const Node*) const; 

//---------------------------------------------------------------------------
// makeEmpty
// Preconditions:	None 
// Postconditions:	The tree will be Empty 
// Calls makeEmpty helper to empty the tree
//---------------------------------------------------------------------------
	void makeEmpty(); 

//---------------------------------------------------------------------------
// makeEmptyHelper
// Preconditions:	None 
// Postconditions:	The tree will be Empty 
// Traverse the tree recursively and delete the data and set pointers to 
// NULL
//---------------------------------------------------------------------------
	void EmptyHelper(Node*&); 

//---------------------------------------------------------------------------
// DisplayHelper
// Preconditions:	root is passed in 
// Postconditions:	Contents of tree is displayed
// Recursively goes through the tree and diplays its contents 
//---------------------------------------------------------------------------
	void DisplayHelper(const Node*) const;
};

#endif

