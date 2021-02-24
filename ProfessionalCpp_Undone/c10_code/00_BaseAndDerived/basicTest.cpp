#include "Derived.h"

int main()
{
	Base base1;
	base1.someMethod();
//	base1.someOtherMethod(); Base class can't call Derived class method


	Derived der1; // Base 클래스 상속받았기에
	der1.someMethod(); // Derived 객체에서 Base 클래스의 멤버함수를 사용할 수 있다.
	der1.someOtherMethod(); // Derived class method


	/* Derived 타입 객체는 Base 타입 객체의 모든 멤버를 가지고 있다 => Derived 타입은 Base 타입 이기도 하다.
	* 하지만 Base 타입은 Derived 타입이 아니다.
	
	에그마요 베이컨 샌드위치는 에그마요 샌드위치이다. 
	반대로 Base 클래스는 Derived 클래스의 존재 자체를 모른다 => 완전 남 
	*/

	// der1 객체는 Derived 타입이면서 동시에 Base 타입으로 취급할 수 있다.


	// 어떤 클래스 객체를 포인터나 레퍼런스로 가리킬 때, 해당 클래스의 파생 클래스까지 가리킬 수 있다.
	Base* basePtr; // Base class 를 가리키는 포인터
	
	basePtr = &base1; // Base 가리킴
	basePtr->someMethod();

	basePtr = &der1; // Base class 의 파생 클래스인 Derived 타입을 가리킴. => Derived 타입 객체를 Derived 타입이 아닌 Base 타입으로 볼 수 있기 때문에 가능?
//	basePtr->SomeOtherMethod(); 하지만 Base 포인터로 Derived 클래스 메서드를 호출할 수는 없다. 왜냐면, Base 타입으로 보고 있으니까.


	Base& baseRef1 = base1; // 레퍼런스의 경우
	Base& baseRef2 = der1; // 파생 클래스 객체를 레퍼런스로 가리킴


	Derived* derivedPtr;
//	derivedPtr = &base1; 객체 포인터가 자신의 부모 클래스, 베이스 클래스를 가리킬 수 는 없다.
	derivedPtr = &der1; // Derived pointer 가 Derived 타입을 가리킴


	
}