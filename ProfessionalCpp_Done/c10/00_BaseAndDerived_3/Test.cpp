#include "Derived.h"
#include <iostream>

using namespace std;

int main()
{
	Base myBase;
	Derived myDerived;


	myBase.func1();
	// virtual 메서드를 호출하므로 myBase 객체의 vtable 을 참고 => vtable 에서 func1() 항목의 함수 포인터가 가리키는 코드를 호출
	// 해당 객체는 Base 객체이기 때문에 Base vtable 을 참고 => Base::func1() 을 호출하게 된다.

	myDerived.func1();
	// virtual 메서드를 호출하므로 myDerived 객체의 vtable 을 참고 => vtable 에서 func1() 항목의 함수 포인터가 가리키는 코드를 호출
	// 해당 객체는 Derived 객체이기 때문에 Derived vtable 을 참고 => func1()은 파생 클래스에서 오버라이드 하지 않았다 => Base::func1() 을 호출하게 된다.
}