//==============================================================================
// Matt Kretchmar
// April 27, 2015
// main.cc
//==============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "set.h"

using namespace std;

int main ( void )
{
    Set<char> s1, s2, s3;
    
    s1.insert('A');
    s1.insert('B');
    s1.insert('C');
    s1.insert('A');
    
    
    
    cout << "s1 = " << s1 << endl;
    cout << "s1 size = " << s1.size() << endl;
    
    s2.insert('A');
    s2.insert('B');
    s2.insert('D');
    s2.insert('E');
    
    cout << "s2 = " << s2 << endl;
    cout << "s2 size = " << s2.size() << endl;
  
    s3 = s1 + s2;
  
    cout << "s3 = s1 + s2 = " << s3 << endl;
    cout << "s3 size = " << s3.size() << endl;
    /* 
    s3 = s1 * s2;
    cout << "s3 = s1 * s2 = " << s3 << endl;
    cout << "s3 size = " << s3.size() << endl;
    */
    return 0;
}