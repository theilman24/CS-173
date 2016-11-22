#include <iostream>
#include "list.h"
using namespace std;

int main ( void )
{
//==============================================================================
//		List made of int's
//==============================================================================
	
	printf("======= Creating a list of int's =============\n");
	List<int> list;
	list.append(1);
	list.append(2);				
	list.append(3);
	list.append(4);
	printf("List [1, 2, 3, 4] = %s\n",list.str().c_str());
	list.pop(1);
	list.pop(0);
	printf("List [3, 4] = %s\n",list.str().c_str());
	list.insert(0,5);
	list.insert(2,12);
	printf("List [5, 3, 12, 4] = %s\n",list.str().c_str());
	printf("list length = 4 = %d\n",list.length());

	
//==============================================================================
//		List made of char's
//==============================================================================
	
	printf("======= Creating a list of char's =============\n");
	List<char> list2;
	list2.append('A');
	list2.append('B');
	list2.append('C');
	list2.append('C');
	printf("List [A, B, C, D] = %s\n",list2.str().c_str());
	list2.pop(1);
	list2.pop(0);
	printf("List [C, D] = %s\n",list2.str().c_str());
	list2.insert(0,'T');
	list2.insert(2,'H');
	printf("List [T, C, H, D] = %s\n",list2.str().c_str());
	printf("list length = 4 = %d\n",list2.length());		// returns ASCII value?
	
	
	
	return 0;	
}
