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
	Derived() // �����ڿ��� �޸𸮸� �Ҵ��ϰ�
	{
		mString = new char[30];
		cout << "mString �� �޸𸮰� ���� �Ҵ�Ǿ���" << endl;
	}

	~Derived() // �Ҹ��ڿ��� �޸𸮸� �������ش�
	{
		delete[] mString;
		cout << "mString �� �Ҵ�� �޸𸮰� �����Ǿ���" << endl;
	}

private:
	char* mString;
};