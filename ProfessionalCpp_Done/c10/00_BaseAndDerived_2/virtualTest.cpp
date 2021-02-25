#include "Derived.h"
#include <iostream>

using namespace std;

int main()
{
	Derived myDerived;
	myDerived.go(); // Derived 객체에서 호출하니까, Derived version's go() 메서드가 호출된다.
	// 이때 go() 메서드는 베이스 클래스의 메서드를 오버라이드한 것이 아닌, Derived 클래스에 별개로 만들어진 새로 생성된 메서드다.


	Base& baseRef = myDerived; // 베이스 클래스 레퍼런스로 파생 클래스를 가리킴
	baseRef.go(); // Base version's go() 메서드 호출
	// 베이스 클래스 내에서 virtual 키워드가 없었기 때문에, go() 메서드를 파생 클래스에서 오버라이드 했는지 찾아보지도 않는다.
}