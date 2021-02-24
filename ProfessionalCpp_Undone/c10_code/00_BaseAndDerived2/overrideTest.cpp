#include "Derived.h"
#include <iostream>

using namespace std;

int main()
{
	Derived myDerived;
	Base& baseRef = myDerived; // 베이스 클래스 레퍼런스로 파생 클래스 객체를 가리킴
	baseRef.someMethod(1.1); // 파생 클래스, Derived 버전의 someMethod() 가 호출된다. 파생 클래스에서 오버라이드 했으므로, 파생 클래스 버전을 호출


	otherDerived myOtherDerived;
	Base& baseOtherRef = myOtherDerived; // 다른 파생 클래스 객체를 가리킴
	baseOtherRef.someMethod(1.1); // Base 클래스 버전의 someMethod() 가 호출된다.
	/* Base 레퍼런스가 Base 클래스의 someMethod() 를 호출하려 했고, 
	otherDerived 클래스에는 Base 클래스의 someMethod() 를 오버라이드한 메서드가 없으므로,
	Base 레퍼런스는 Base 버전의 someMethod() 를 호출하게 된 것. */
}