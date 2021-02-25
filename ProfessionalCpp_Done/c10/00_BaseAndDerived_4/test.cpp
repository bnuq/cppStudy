#include "dtor.h"

int main()
{
	Base* ptr = new Derived(); // Derived 객체를 동적할당하고 이것을 Base 포인터로 가리킴
	// 그러면 Derived 를 동적할당하면서, Derived 의 생성자 호출 => mString 할당

	delete ptr; // Base 포인터가 가리키는 메모리 해제 => Base 포인터라서, ~Base() 만 호출. ~Derived() 는 호출되지 않는다.
	// Derived 객체에서 동적할당 됐던 mString 이 해제되지 않는다.
	// 소멸자를 virtual 로 선언하지 않았기 때문이다.
}