#include "Derived.h"
#include <iostream>
using namespace std;


void Derived::someMethod(double d)
{
	cout << "Derived 클래스의 someMethod() 메서드" << endl
		<< d << endl;
}



void Derived::go()
{
	cout << "go() called on Derived" << endl;
}







void otherDerived::someMethod(int i)
{
	cout << "otherDerived 클래스에서 잘못 오버라이드한 someMethod() 메서드" << endl;
}