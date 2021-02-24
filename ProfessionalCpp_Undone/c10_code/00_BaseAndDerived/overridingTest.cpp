#include "Derived.h"
#include <iostream>

using namespace std;

int main()
{
	Base myBase;
	myBase.someMethod(); // Base 클래스의 someMethod() 호출

	Derived myDerived;
	myDerived.someMethod(); // Derived 클래스에서 오버라이드한 someMethod() 호출


	/* 포인터, 레퍼런스가 파생 클래스 객체를 가리키는 경우에 오버라이드한 메서드를 호출한다면,
	가리켜지고 있는 객체 자신이 스스로 어떤 클래스인지 알기 때문에, 가리켜지는 객체에 적합한 메서드가 호출된다. 
	*/
	Base& baseRef = myDerived; // 파생 클래스를 가리키는 Base 레퍼런스
	baseRef.someMethod(); // Base 레퍼런스가 가리키고 있는 Derived 클래스의 someMethod() 가 호출된다. 파생 클래스 버전이 호출.

	Base* basePtr = &myDerived;
	basePtr->someMethod();
	

	/* 하지만 어디까지나 베이스 클래스 포인터나 레퍼런스는 베이스 클래스의 메서드만 호출이 가능. virtual 키워드 때문에 오버라이드 된 버전을 호출한거다.
	베이스 클래스에 없는 파생 클래스만의 메서드나 멤버에는 접근이 불가능 하다. */
//	baseRef.someOtherMethod();


	/* Base 객체가 어떤 메모리 영역을 차지하고 있고
	Derived 객체는 Base 객체가 차지하는 영역 + 추가 멤버 영역을 차지한다.
	베이스 클래스 포인터나 레퍼런스로 파생 클래스 객체를 가리키는 경우, 파생 클래스 객체 메모리 영역에서 베이스 클래스 메모리 영역만 가리키는 꼴. 
	그래서 베이스 클래스 멤버가 아닌 다른 멤버에 접근할 수 없고,
	만약 베이스 클래스의 메서드가 virtual 로 선언되어 있는 경우엔, 그것을 오버라이드한 파생 클래스의 virtual 메서드에 접근하게 되는 것. */




	/* 파생 클래스는 베이스 클래스의 일종이기도 하다.
	파생 클래스를 베이스 클래스로 캐스팅(형변환) 하거나
	파생 클래스 객체를 베이스 클래스 객체에 대입할 수 있다. 
	=> 이 경우 파생 클래스의 정보는 사라진다. */
	Base anotherBase = myDerived; // 베이스 클래스에 파생 클래스를 대입
	anotherBase.someMethod(); // anotherBase 는 완전히 Base 객체. Base 클래스 버전의 someMethod() 가 호출된다.


	/* 파생 클래스를 베이스 클래스로 캐스팅하거나, 베이스 클래스에 대입을 하게 되면
	파생 클래스 객체의 메모리 영역에서 베이스 클래스에 해당되는 부분만 살아남고, 나머지는 다 잘려나가게 되는 모양새다. 
	=> 파생 클래스의 데이터 멤버나 오버라이드된 메서드가 삭제되는 현상 = 슬라이싱, Slicing */
}