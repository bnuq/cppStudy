#include "dtorVirtual.h"

int main()
{
	Base* ptr = new Derived(); // Derived 객체를 동적할당하고 이것을 Base 포인터로 가리킴
	// 그러면 Derived 를 동적할당하면서, Derived 의 생성자 호출 => mString 할당


	ptr->someMethod();

	delete ptr; // Base 포인터가 가리키는 메모리 해제 => Base 포인터라서, ~Base() 를 호출
	// 그런데 소멸자가 virtual 선언이 되어 있으므로, 오버라이드 된 메서드를 호출 => ~Derived() 를 호출
	// Derived 객체에서 동적할당 됐던 mString 이 해제되게 된다.
}