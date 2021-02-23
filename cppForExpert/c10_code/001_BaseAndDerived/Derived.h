#pragma once
#include "Base.h"

/* 이 클래스가 다른 클래스를 확장할 것이라고 선언해야 한다, 알려야 한다.
* Derived 클래스가 Base 클래스를 상속한다, Base 클래스를 물려 받는다고 알림.
* Derived class = Base class 의 파생 클래스, 서브 클래스다. */
class Derived : public Base 
{
public:
	void someOtherMethod() { }
};

// Base 를 상속받은 Derived 를 상속받는 DerivedDerived 클래스
class DerivedDerived : public Derived
{

};

// Base 를 상속받는 또다른 클래스 Derived2
class Derived2 : public Base
{

};