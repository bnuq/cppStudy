#pragma once

/* C++ 에서 클래스를 컴파일 => 바이너리 객체 생성
바이너리 객체는 => 모든 메서드를 담고 있다
virtual 메서드가 하나 이상 정의된 클래스는 모두 vtable, 가상 테이블을 가지고 있고
이 클래스로 생성된 객체마다 vtatble 에 대한 포인터를 갖게 된다.
메서드를 virtual 로 선언하면 => vtable, 가상 테이블이라 부르는 특수한 메모리 영역에 해당 메서드의 함수 포인터가 저장된다.

virtual 로 선언되지 않는 메서드를 호출하는 부분 => 컴파일 시간에 결정된 코드로 교체된다 == 정적 바인딩, 이른 바인딩, static binding, early binding
virtual 로 선언된 메서드를 호출하는 부분 => 해당 객체의 vtable 을 보고 => 그 시점에서 가장 적합한 메서드를 실행한다 == 동적 바인딩, 늦은 바인딩, dynamic binding, late binding
*/


class Base
{
public:
	virtual void func1() {}
	virtual void func2() {}

	/* virtual 로 선언된 func1, func2 구현 코드에 대한 함수 포인터가 Base 객체 vtable 에 저장된다. 
	vtable 에 있는 각 항목은 해당 메서드의 구현 코드를 가리킨다. */


	// non-virtual 메서드는 vtable 에 속하지 않는다.
	void nonVirtualFunc() {}
};