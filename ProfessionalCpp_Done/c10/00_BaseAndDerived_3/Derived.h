#pragma once
#include "Base.h"

class Derived : public Base
{
public:
	virtual void func2() override {}

	/* Derived 객체도 vtable 을 가진다. 각 항목에는 상속받은 func1 메서드와 오버라이드한 func2 메서드에 대한 함수 포인터가 저장되어 있다. 
	func1() 은 오버라이드하지 않았기에 해당 함수 포인터는 Base::func1() 구현 코드를 가리킨다.
	func2() 는 오버라이드 했기 때문에 해당 함수 포인터는 Derived::func2() 구현 코드를 가리킨다. */


	void nonVirtualFunc() {}
};