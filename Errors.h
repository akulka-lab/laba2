#pragma once
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

enum errorsCode
{
	IndexOutOfRange,
	ZeroSize,
	NULLPointer,
	NegativeSize,
};

void errors(int errorCode, const char* nameFunction) 
{
	if (errorCode == IndexOutOfRange)  
		cout << "Index out of range in " << nameFunction<<endl; 

	else if (errorCode == ZeroSize)  
		cout << "ZeroSize in " << nameFunction << endl; 

	else if (errorCode == NULLPointer)  
		cout << "NULLPointer in " << nameFunction << endl; 

	else if (errorCode == NegativeSize)  
		cout << "NegativeSize in " << nameFunction << endl; 
}