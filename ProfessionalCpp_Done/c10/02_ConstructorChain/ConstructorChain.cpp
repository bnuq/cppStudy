#include <iostream>

using namespace std;

class Something
{
public:
	Something() { cout << "2"; }
	virtual ~Something() { cout << "2"; }
};


// virtual 속성은 자식 클래스에 자동으로 적용되지만.
// 그냥 애초에 모든 메서드에 virtual 을 쓰는 것이 편하다.
// 특히 모든 소멸자는 virtual 로 선언하는 것이 바람직하다.
class Base
{
public:
	Base() { cout << "1"; }
	virtual ~Base() { cout << "1"; } // 컴파일러가 자동으로 생성하는 소멸자는 virtual 이 아니므로, 따로 정의하거나 default 로 명시적 지정이 필요하다.
};



class Derived : public Base 
{
public:
	// Derived 객체가 생성되면, 먼저 부모 클래스인 Base 클래스의 디폴트 생성자를 실행한다. => 1
	Derived() { cout << "3"; } // 부모 클래스 생성자를 호출하고, 데이터 멤버들을 모두 생성한 다음에 생성자 본문을 실행한다. => 3
	
	

	// 객체가 소멸할 때, 현재 소멸자를 먼저 호출.
	// 이후 데이터 멤버를 생성할 때와 반대 순서로 삭제
	// 마지막으로 부모 클래스의 소멸자를 호출
	virtual ~Derived() { cout << "3"; }

private:
	Something mDataMember; // 생성자 본문을 시행하기 전, static 으로 선언하지 않은 데이터 멤버를 코드에 나타난 순서대로 생성한다. 
	// 이때 데이터 멤버가 객체인 경우, 디폴트 생성자를 실행한다. => 2
};


int main()
{
//	Derived myDerived; // 123 출력


	Base* ptr = new Derived();

	delete ptr; // 소멸자에 virtual 이 선언되어 있었기 때문에, ptr 이 해제될 때 => 가리키는 객체인 Derived 의 소멸자가 호출된다.
	// 소멸자들에 virtual 선언이 없었다면, ptr 이 해제될 때 => 바로 Base 의 소멸자가 호출 => 1231 출력.

	return 0;
}

