#include <iostream>
using namespace std;

class Obj1; // Obj1 이라는 이름을 가지는 클래스가 존재한다는 것을 알려만 준다.

class Obj3
{
public:
	/*
	* Obj3 클래스에서 Obj1 클래스의 private 멤버에 접근이 가능한 메서드
	* Obj1 클래스 내에서 friend 선언을 하기 위해 먼저 앞에서 클래스 정의와 메서드 선언을 하였다.
	* 
	* 그런데 컴파일러는 인수로 받는 Obj1 에 대해서 알지 못한다 => 다시 앞에서 Obj1 이라는 클래스가 있다는 것을 알려주어야 한다.
	* 메서드 내에서 Obj1 의 private 멤버에 접근하는 걸 정의하고 싶지만, 컴파일러는 Obj1 의 private 멤버를 알지 못한다
	* => 이 메서드의 정의는 Obj1 클래스 정의가 끝난 다음에 진행해야 한다.
	*/
	void processObj(const Obj1& o);

	// 다른 메서드는 접근이 불가능하다.
	void otherMethod(const Obj1& o) { cout << "Obj1 의 private 멤버에 접근 불가능" /* << o.nData */ << endl; }
};


class Obj1
{
public:
	Obj1(int n = 0) : nData(n) { }

private:
	int nData;

	/* friend 로 받아들일 클래스나 함수들은 반드시 제공하는 클래스 내에서 지정한다. */

	/* 
	* 다른 클래스 Obj2 전체를 friend 로 선언
	* Obj2 클래스에 있는 모든 메서드들은 Obj1 의 protected, private 멤버에 접근이 가능하다.
	* 이런 객체가 존재한다~ 는 걸 알려주는 역할
	* Obj2 의 클래스 정의를 뒤에서 해도 괜찮다.
	*/ 
	friend class Obj2; // 이제 Bar_1 는 Foo 의 모든 멤버에 접근이 가능하다

	/*
	* 특정 클래스( Obj3 )의 특정 메서드( processObj )만을 friend 로 선언
	* 해당 클래스에 이러한 메서드가 존재한다는 것을 미리 컴파일러가 알고 있어야 한다.
	* 그래서 Obj3 클래스의 정의와 메서드 선언이 앞에 존재해야 한다.
	*/
	friend void Obj3::processObj(const Obj1& o); // 메서드의 프로토타입을 이용

	/*
	* standalone 함수를 friend 로 선언. 일반 함수에서도 Obj1 멤버에 접근이 가능하다
	* 앞선 클래스 선언처럼, friend 선언문 자체가 함수 프로토타입 역할을 한다.
	* 다른 곳에서 또 이 함수를 선언할 필요가 없다.
	*/
	friend void dumpObj(const Obj1& f);
};


void Obj3::processObj(const Obj1& o)
{
	std::cout << "Obj1 의 private 멤버 값은 " << o.nData << std::endl;
}


class Obj2
{
public:
	// Obj2 클래스에서 Obj1 클래스의 private 멤버에 접근이 가능하다
	// 메서드를 정의할 때 friend 를 쓰지 않는다.
	void print(const Obj1& f) { std::cout << "Obj1 의 private 멤버 값은 " << f.nData << std::endl; }
};


// 함수를 정의할 때 friend 를 쓰지 않는다. 
void dumpObj(const Obj1& o)
{
	std::cout << "Obj1 의 private 멤버 값은 " << o.nData << std::endl;
}

int main()
{
	Obj1 sampleObj1(100);

	Obj2 sampleObj2;
	Obj3 sampleObj3;

	sampleObj2.print(sampleObj1);
	sampleObj3.processObj(sampleObj1);

	dumpObj(sampleObj1);
}