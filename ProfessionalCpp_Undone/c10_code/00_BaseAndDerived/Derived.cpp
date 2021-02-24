#include "Derived.h"
#include <iostream>
using namespace std;


void Derived::someMethod() // 메서드를 정의할 때는 virtual, override 키워드를 생략한다.
{
	cout << "Derived 클래스에서 someMethod() 메서드의 동작을 변경하였다." << endl;
}




/* Derived 클래스의 부모 클래스인 Base 클래스의 public, protected 데이터 멤버를 자유롭게 사용할 수 있다. */
void Derived::someOtherMethod()
{
	cout << "Derived 타입에서 Base 클래스의 멤버 데이터에 접근이 가능하다" << endl
		<< "mProtectedInt = " << mProtectedInt << endl // 마치 자신의 데이터 멤버인 것처럼 자유롭게 사용
		<< "private 영역에는 접근하지 못한다." << endl;
}

/* 어떤 클래스의 데이터 멤버나 메서드를
protected 로 선언 => 파생 클래스에서 접근이 가능하다.
private 로 선언 => 파생 클래스에서 접근이 불가능하다.
어떤 클래스를 봤을 때, 위를 보지 말고 그 밑에 있는 파생 클래스에서 접근하는 것을 고려해야 한다. 
*/