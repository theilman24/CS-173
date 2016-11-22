#include <iostream>
using namespace std;


template<class T>
Set<T>::Set	(void)
{  
}

//===============================================================================

template<class T>
Set<T>::Set	(const Set & x)	: list(x.list)
{  
}

//===============================================================================


template<class T>
Set<T>::~Set(void)
{  
}


//===============================================================================

template<class T>
Set<T> &   Set<T>::operator=  (const Set & source)
{
	list = source.list;
	return *this;

}

//===============================================================================



template<class T>
void  Set<T>::insert  (const T& x)  
{
	int y = list.index(x);
	if (y == -1)
		list.append(x);
	else;  //Don't add anything
}

//===============================================================================

template<class T>
T	Set<T>::remove	(const T & x)
{
	int y = list.index(x);
	
	if(list.index(x) != -1)
		list.pop(y);
	else;
		

}

//===============================================================================

template<class T>
bool  Set<T>::contains	(const T &x )
{
	int y = list.index(x);
	if (y== -1)
		return false;
	else
		return true;
}


//==============================================================================
template<class T>
Set<T>	Set<T>::operator+ ( const Set  &x) const	
{
	Set<T> s;
	
	s = x;


	return s;
	
		
}


//==============================================================================
/*
template<class T>
Set<T>	Set<T>::operator* ( const Set &x) const	
{
	Set<T> s;
	
		
	if(list.index(x) == -1)
		s.append(x);
	
	return s;
}


//===============================================================================

*/

template<class T>
int	Set<T>::size  	(void) const	
{
	return list.length();
}





