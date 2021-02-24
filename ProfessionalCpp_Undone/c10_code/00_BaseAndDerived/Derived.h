#pragma once
#include "Base.h"

/* 이 클래스가 다른 클래스를 확장할 것이라고 선언해야 한다, 알려야 한다.
* Derived 클래스가 Base 클래스를 상속한다, Base 클래스를 물려 받는다고 알림.
* Derived class = Base class 의 파생 클래스, 서브 클래스다. */
class Derived : public Base 
{
public:
	// 모든 메서드를 virtual 로 선언하는 것이 바람직하다.

	/*
	override 키워드. 파생 클래스에서 베이스 클래스의 메서드 동작을 바꾸려 할때, 오버라이드할 때 사용
	베이스 클래스 메서드의 선언을 똑같이 쓰고 override 키워드를 붙여 동작을 파생 클래스에서 변경한다는 것을 알린다.
	*/
	virtual void someMethod() override; // override 키워드가 필수는 아니다.
/*	void someMethod() override;  메서드나 소멸자를 virtual 로 선언하면 파생클래스에서도 virtual 상태가 유지된다.
	즉 someMethod() 메서드 선언 시에 virtual 을 쓰지 않아도 여전히 virtual 로 선언한 것이나 마찬가지인 상태다. */


	virtual void someOtherMethod();
};

/* 파생 클래스는 부모 클래스의 public, protected 의 모든 메서드, 데이터 멤버를 자신의 클래스에서 정의한 것처럼 사용할 수 있다. */








// Base 를 상속받은 Derived 를 상속받는 DerivedDerived 클래스
class DerivedDerived : public Derived
{

};

// Base 를 상속받는 또다른 클래스 Derived2
class Derived2 : public Base
{

};