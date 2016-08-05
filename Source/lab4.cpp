#include <iostream>
using namespace std; 

#include "stdafx.h"
#include "store.h"

int main()
{
	Store s;
	s.ProcessCustomerFile("customer.txt");
	s.ProcessMovieFile("movie.txt");
	s.ProcessTransactionFile("transaction.txt"); 

	return 0; 
}

