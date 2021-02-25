#pragma once
#include <iostream>
using namespace std;

class Base
{
public:
	Base() {}

	// 소멸자를 virtual 로 지정하고 싶은데, 딱히 특별한 작업이 필요하지 않을때는 컴파일러가 자동으로 만들어주는 소멸자를 사용하기 위해 default 키워드를 써준다.
	virtual ~Base() = default;


	// 메서드를 final 로 지정할 수 있다.
	virtual void someMethod() final;
};

class Derived : public Base
{
public:
	Derived() // 생성자에서 메모리를 할당하고
	{
		mString = new char[30];
		cout << "mString 에 메모리가 동적 할당되었다" << endl;
	}

	/*
	// virtual 키워드가 없어도, 베이스 클래스에서 소멸자를 virtual 로 선언했으므로
	// 파생 클래스에서도 소멸자는 virtual 를 유지한다.
	~Derived() // 소멸자에서 메모리를 해제해준다
	{
		delete[] mString;
		cout << "mString 에 할당된 메모리가 해제되었다" << endl;
	}
	*/

	// 그래도 명시적으로 virtual 키워드를 쓰는 게 좋지.
	virtual ~Derived()
	{
		delete[] mString;
		cout << "mString 에 할당된 메모리가 해제되었다" << endl;
	}




	// final 로 지정된 메서드는 파생 클래스에서 오버라이드 할 수 없다
//	virtual void someMethod() override; 컴파일 에러. 

private:
	char* mString;
};


/* 클래스를 final 로 선언하지 않았다면,
소멸자를 포함한 모든 메서드를 virtual 로 선언하는 것이 좋다.
단 생성자는 virtual 로 선언할 필요가 없고 해서도 안된다. */