#include "Derived.h"
#include <iostream>
using namespace std;


void Derived::someMethod(double d)
{
	cout << "Derived Ŭ������ someMethod() �޼���" << endl
		<< d << endl;
}



void Derived::go()
{
	cout << "go() called on Derived" << endl;
}







void otherDerived::someMethod(int i)
{
	cout << "otherDerived Ŭ�������� �߸� �������̵��� someMethod() �޼���" << endl;
}