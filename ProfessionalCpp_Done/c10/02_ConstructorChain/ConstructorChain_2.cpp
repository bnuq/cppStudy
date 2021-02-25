#include <iostream>

using namespace std;

class Something
{
public:
	Something() { cout << "2"; }
	Something(int i) { cout << i << " 로 Something 객체 초기화" << endl; }

	virtual ~Something() { cout << "2"; }
};

class Base
{
public:
	Base() { cout << "1"; }
	Base(int i) { cout << i << " 로 Base 객체 초기화" << endl; }

	virtual ~Base() { cout << "1"; }
};

class Derived : public Base
{
public:
	// 부모 클래스를 디폴트 생성자가 아닌 다른 생성자로 초기화하려는 경우, 생성자 이니셜라이저를 이용해 생성자를 체인으로 엮는다.
	// 파생 클래스는 반드시 컴파일러에 베이스 클래스 생성자를 호출하는 방법을 생성자 이니셜라이저를 통해 알려줘야 한다.
	// 이 경우에도 Derived 객체가 생성되면 가장 먼저 Base(9) 생성자를 호출한다.
	Derived() : Base(9) { cout << "3"; }
	
	// Derived 생성자에서 받은 인수를 이용해 Base 생성자를 호출할 수 도 있다.
	// 객체 데이터 멤버도 디폴트 생성자가 아닌 다른 생성자로 초기화하고 싶다면 생성자 이니셜라이저를 통해 호출할 생성자를 알려준다.
	// 생성자 이니셜라이저 내 순서는 초기화 순서가 아니다.
	Derived(int i) : mDataMember(i), Base(i) { cout << i << " 로 Derived 객체 초기화" << endl; }

	// 베이스 클래스 생성자에 데이터 멤버를 전달할 수는 없다. 왜냐하면, 베이스 클래스 생성자가 호출되고 나서 데이터 멤버가 초기화되기 때문에.
	Derived(double d) : Base(nData) { } // 컴파일 에러가 발생하지는 않네



	virtual ~Derived() { cout << "3"; }

private:
	Something mDataMember;
	int nData=0;
};

/*
int main()
{
	Derived myDerived(10);

	return 0;
}
*/