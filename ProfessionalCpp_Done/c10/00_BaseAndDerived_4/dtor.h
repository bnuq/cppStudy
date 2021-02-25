#pragma once
#include <iostream>
using namespace std;

class Base
{
public:
	Base() {}
	~Base() {}
};

class Derived : public Base
{
public:
	Derived() // 생성자에서 메모리를 할당하고
	{
		mString = new char[30];
		cout << "mString 에 메모리가 동적 할당되었다" << endl;
	}

	~Derived() // 소멸자에서 메모리를 해제해준다
	{
		delete[] mString;
		cout << "mString 에 할당된 메모리가 해제되었다" << endl;
	}

private:
	char* mString;
};