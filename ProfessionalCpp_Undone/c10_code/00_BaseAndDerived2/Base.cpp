#include "Base.h"
#include <iostream>
using namespace std;


void Base::someMethod(double d)
{
	cout << "이 메서드는 Base 의 someMethod() 메서드다" << endl
		<< d << endl;
}