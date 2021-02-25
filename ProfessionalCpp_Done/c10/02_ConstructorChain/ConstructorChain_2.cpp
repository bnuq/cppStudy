#include <iostream>

using namespace std;

class Something
{
public:
	Something() { cout << "2"; }
	Something(int i) { cout << i << " �� Something ��ü �ʱ�ȭ" << endl; }

	virtual ~Something() { cout << "2"; }
};

class Base
{
public:
	Base() { cout << "1"; }
	Base(int i) { cout << i << " �� Base ��ü �ʱ�ȭ" << endl; }

	virtual ~Base() { cout << "1"; }
};

class Derived : public Base
{
public:
	// �θ� Ŭ������ ����Ʈ �����ڰ� �ƴ� �ٸ� �����ڷ� �ʱ�ȭ�Ϸ��� ���, ������ �̴ϼȶ������� �̿��� �����ڸ� ü������ ���´�.
	// �Ļ� Ŭ������ �ݵ�� �����Ϸ��� ���̽� Ŭ���� �����ڸ� ȣ���ϴ� ����� ������ �̴ϼȶ������� ���� �˷���� �Ѵ�.
	// �� ��쿡�� Derived ��ü�� �����Ǹ� ���� ���� Base(9) �����ڸ� ȣ���Ѵ�.
	Derived() : Base(9) { cout << "3"; }
	
	// Derived �����ڿ��� ���� �μ��� �̿��� Base �����ڸ� ȣ���� �� �� �ִ�.
	// ��ü ������ ����� ����Ʈ �����ڰ� �ƴ� �ٸ� �����ڷ� �ʱ�ȭ�ϰ� �ʹٸ� ������ �̴ϼȶ������� ���� ȣ���� �����ڸ� �˷��ش�.
	// ������ �̴ϼȶ����� �� ������ �ʱ�ȭ ������ �ƴϴ�.
	Derived(int i) : mDataMember(i), Base(i) { cout << i << " �� Derived ��ü �ʱ�ȭ" << endl; }

	// ���̽� Ŭ���� �����ڿ� ������ ����� ������ ���� ����. �ֳ��ϸ�, ���̽� Ŭ���� �����ڰ� ȣ��ǰ� ���� ������ ����� �ʱ�ȭ�Ǳ� ������.
	Derived(double d) : Base(nData) { } // ������ ������ �߻������� �ʳ�



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