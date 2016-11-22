/*
Taylor Heilman
list class using doubly linked lists
list.cc
*/


#include "list.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

//==========================================
//			Default Constructor
//==========================================
List::List ( void )
{
	head = NULL,                          
	tail = NULL,                                   
	currentFwd = head;                                
	currentRev = tail;                                
	size = 0; 

}


/*

//==========================================
//				Destructor
//==========================================

List::~List   ( void )
{
    Link * temp = head;
	while( temp != 0 ) {
    	Link* next = temp->next;
    	delete temp;
   		temp = next;
}
	head = 0;
}




*/