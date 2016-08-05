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
#include "stdafx.h"
#include "moviebst.h"

//---------------------------------------------------------------------------
// Default Constructor 
// Preconditions:	None
// Postconditions:	root is set to NULL
//---------------------------------------------------------------------------
MovieBST::MovieBST()
{
	root = NULL; 
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:	None
// Postconditions:	Tree is Empty
// Calls the makeEmpty() function to delete everything in the tree
//---------------------------------------------------------------------------
MovieBST::~MovieBST()
{
	makeEmpty();
}

//---------------------------------------------------------------------------
// Display
// Preconditions:	None
// Postconditions:	Contents of tree is displayed
// Calls the DisplayHelper() function
//---------------------------------------------------------------------------
void MovieBST::Display() const
{
	if (root == NULL)
		return;
	else
		DisplayHelper(root); 
}

//---------------------------------------------------------------------------
// DisplayHelper
// Preconditions:	root is passed in 
// Postconditions:	Contents of tree is displayed
// Recursively goes through the tree and diplays its contents 
//---------------------------------------------------------------------------
void MovieBST::DisplayHelper(const Node* current) const
{
	if (current != NULL)
	{
		DisplayHelper(current->left);	// get the left subtree
		cout << *(current->movie) << endl;	// display node
		DisplayHelper(current->right);	// get the right subtree
	}
}

//---------------------------------------------------------------------------
// Insert
// Preconditions:	None 
// Postconditions:	Movie is inserted into the tree
// Calls InsertHelper to insert the movie 
//---------------------------------------------------------------------------
bool MovieBST::Insert(Movie* movie)
{
	return InsertHelper(root, movie); 
}

//---------------------------------------------------------------------------
// InsertHelper
// Preconditions:	root is passed in 
// Postconditions:	Movie is inserted into the tree
// Creates a node to insert goes thrrough the tree and places the node into 
// appropriate place
//---------------------------------------------------------------------------
bool MovieBST::InsertHelper(Node*& current, Movie* movie)
{
	if (current == NULL)
	{
		current = new Node();
		current->movie = movie;		// setting the node to the movie
		current->left = NULL;
		current->right = NULL;
		return true;
	}

	if (*(current->movie) == *movie)	// if movie exists
		return false; 

	if (*movie < *(current->movie))		// if less, traverse left subtree
		return InsertHelper(current->left, movie);

	else                               // else traverse right subtree
		return InsertHelper(current->right, movie); 
}

//---------------------------------------------------------------------------
// Retrieve
// Preconditions:	None 
// Postconditions:	The result will be the found m ovie and the function will
//					return true or false; 
// Calls RetrieveHelper to retrive the movie 
//---------------------------------------------------------------------------
bool MovieBST::Retrieve(const Movie& target, Movie*& result) const
{
	return RetrieveHelper(target, result, root); 
}

//---------------------------------------------------------------------------
// RetrieveHelper
// Preconditions:	None 
// Postconditions:	The result will be the found movie and the function will
//					return true or false; 
// See if the current movie is the target movie, if not check the left 
// subtree then right
//---------------------------------------------------------------------------
bool MovieBST::RetrieveHelper(const Movie& target, Movie *& result,
	const Node* current) const
{

	if (current == NULL)			// is Empty
	{
		result = NULL;
		return false;
	}

	if (target == *(current->movie))	// is it the movie
	{
		result = current->movie;
		return true;
	}

	else if (target < *(current->movie))	// if less, check left subtree
		return RetrieveHelper(target, result, current->left); 
	else                                    // check the right subtree
		return RetrieveHelper(target, result, current->right);
}

//---------------------------------------------------------------------------
// makeEmpty
// Preconditions:	None 
// Postconditions:	The tree will be Empty 
// Calls makeEmpty helper to empty the tree
//---------------------------------------------------------------------------
void MovieBST::makeEmpty()
{
	EmptyHelper(root); 
}

//---------------------------------------------------------------------------
// makeEmptyHelper
// Preconditions:	None 
// Postconditions:	The tree will be Empty 
// Traverse the tree recursively and delete the data and set pointers to 
// NULL
//---------------------------------------------------------------------------
void MovieBST::EmptyHelper(Node*& current)
{
	if (current != NULL)
	{
		EmptyHelper(current->left);		// get the left subtree
		EmptyHelper(current->right);	// get the right subtree
		delete current->movie;			// deletes the current movie
		current->movie = NULL;			// sets the movie ptr to NULL
		current->left = NULL;			// sets the left child ptr to NULL
		current->right = NULL;			// sets the right child ptr to NULL
		delete current;					// deletes the current ptr
		current = NULL;					// sets the current ptr to NULL
	}
}
