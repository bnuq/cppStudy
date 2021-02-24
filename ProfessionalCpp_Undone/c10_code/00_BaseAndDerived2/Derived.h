#pragma once
#include "Base.h"

class Derived : public Base
{
public:
	/* 실수로 override 키워드를 빼먹은 경우
	* 베이스 클래스에 있는 메서드를 오버라이드 하지 않고, virtual 메서드로 새로 정의해버렸다.
	* 하지만, 원래 override 키워드는 생략이 가능해서
	* 실제로는 Derived 클래스가 someMethod() 메서드를 오버라이드하게 된다.
	*/
	virtual void someMethod(double d);
};


class otherDerived : public Base
{
public:
	/* 베이스 클래스 메서드를 오버라이드 하려는데, 
	실수로 override 키워드도 적지 않고 매개변수 타입도 잘못 적었다고 가정하자.
	
	보통 베이스 클래스의 메서드를 수정하고, 파생 클래스 업데이트를 잊었을 때 이와 같은 상황이 발생한다. */
	virtual void someMethod(int i);
	/* 이 경우, 일치하는 메서드가 베이스 클래스에 없으므로, 
	otherDerived 클래스에서 새로운 virtual 메서드를 생성한 게 된다. 
	즉, 오로지 otherDerived 클래스만의 메서드가 된다. */



	/* override 키워드를 적었다면 위와 같은 상황이 발생하지 않았을 것이다.
	override 키워드 => 이 메서드는 반드시 베이스 클래스의 메서드를 오버라이드한다는 뜻.
	virtual void someMethod(int i) override; => 베이스 클래스 메서드에 이와 일치하는 메서드가 없으므로 컴파일 에러가 발생한다.
	*/
};