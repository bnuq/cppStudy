#include "Derived.h"

int main()
{
	Base base1;
	base1.someMethod();

	Derived der1; // Base 클래스 상속받았기에
	der1.someMethod(); // Derived 객체에서 Base 클래스의 멤버함수를 사용할 수 있다.
	der1.someOtherMethod(); // Derived class method


	/* Derived 타입 객체는 Base 타입 객체의 모든 멤버를 가지고 있다 => Derived 타입은 Base 타입 이기도 하다. 
	에그마요 베이컨 샌드위치는 에그마요 샌드위치이다. 
	반대로 Base 클래스는 Derived 클래스의 존재 자체를 모른다 => 완전 남 */
}