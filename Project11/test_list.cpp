//==============================================================================
// Matt Kretchmar
// April 1, 2015
// list_test.cc
//
// This file does unit testing on each method of the list class.
//==============================================================================

#include "list.h"
#include <assert.h>

//==============================================================================
void default_constructor_test ( void )
{
    List list;
    assert ( list.length() == 0);
    assert ( string(list.str()) == string("[]"));
}

//==============================================================================
void append_test ( void )
{
    List list;
    list.append(5);
    assert ( list.length() == 1);
    assert ( string(list.str()) == string("[5]"));
    list.append(3);
    assert ( list.length() == 2);
    assert ( string(list.str()) == string("[5, 3]"));
    list.append(1);
    assert ( list.length() == 3);
    assert ( string(list.str()) == string("[5, 3, 1]"));
}

//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================

int main ( void )
{
    default_constructor_test();
    append_test();
    
    return 0;
}