#pragma once
#include <iostream>
using namespace std;

class Base
{
public:
	Base() {}

	// �Ҹ��ڸ� virtual �� �����ϰ� ������, ���� Ư���� �۾��� �ʿ����� �������� �����Ϸ��� �ڵ����� ������ִ� �Ҹ��ڸ� ����ϱ� ���� default Ű���带 ���ش�.
	virtual ~Base() = default;


	// �޼��带 final �� ������ �� �ִ�.
	virtual void someMethod() final;
};

class Derived : public Base
{
public:
	Derived() // �����ڿ��� �޸𸮸� �Ҵ��ϰ�
	{
		mString = new char[30];
		cout << "mString �� �޸𸮰� ���� �Ҵ�Ǿ���" << endl;
	}

	/*
	// virtual Ű���尡 ���, ���̽� Ŭ�������� �Ҹ��ڸ� virtual �� ���������Ƿ�
	// �Ļ� Ŭ���������� �Ҹ��ڴ� virtual �� �����Ѵ�.
	~Derived() // �Ҹ��ڿ��� �޸𸮸� �������ش�
	{
		delete[] mString;
		cout << "mString �� �Ҵ�� �޸𸮰� �����Ǿ���" << endl;
	}
	*/

	// �׷��� ��������� virtual Ű���带 ���� �� ����.
	virtual ~Derived()
	{
		delete[] mString;
		cout << "mString �� �Ҵ�� �޸𸮰� �����Ǿ���" << endl;
	}




	// final �� ������ �޼���� �Ļ� Ŭ�������� �������̵� �� �� ����
//	virtual void someMethod() override; ������ ����. 

private:
	char* mString;
};


/* Ŭ������ final �� �������� �ʾҴٸ�,
�Ҹ��ڸ� ������ ��� �޼��带 virtual �� �����ϴ� ���� ����.
�� �����ڴ� virtual �� ������ �ʿ䰡 ���� �ؼ��� �ȵȴ�. */