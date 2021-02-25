#include <iostream>

using namespace std;

class Something
{
public:
	Something() { cout << "2"; }
	virtual ~Something() { cout << "2"; }
};


// virtual �Ӽ��� �ڽ� Ŭ������ �ڵ����� ���������.
// �׳� ���ʿ� ��� �޼��忡 virtual �� ���� ���� ���ϴ�.
// Ư�� ��� �Ҹ��ڴ� virtual �� �����ϴ� ���� �ٶ����ϴ�.
class Base
{
public:
	Base() { cout << "1"; }
	virtual ~Base() { cout << "1"; } // �����Ϸ��� �ڵ����� �����ϴ� �Ҹ��ڴ� virtual �� �ƴϹǷ�, ���� �����ϰų� default �� ����� ������ �ʿ��ϴ�.
};



class Derived : public Base 
{
public:
	// Derived ��ü�� �����Ǹ�, ���� �θ� Ŭ������ Base Ŭ������ ����Ʈ �����ڸ� �����Ѵ�. => 1
	Derived() { cout << "3"; } // �θ� Ŭ���� �����ڸ� ȣ���ϰ�, ������ ������� ��� ������ ������ ������ ������ �����Ѵ�. => 3
	
	

	// ��ü�� �Ҹ��� ��, ���� �Ҹ��ڸ� ���� ȣ��.
	// ���� ������ ����� ������ ���� �ݴ� ������ ����
	// ���������� �θ� Ŭ������ �Ҹ��ڸ� ȣ��
	virtual ~Derived() { cout << "3"; }

private:
	Something mDataMember; // ������ ������ �����ϱ� ��, static ���� �������� ���� ������ ����� �ڵ忡 ��Ÿ�� ������� �����Ѵ�. 
	// �̶� ������ ����� ��ü�� ���, ����Ʈ �����ڸ� �����Ѵ�. => 2
};


int main()
{
//	Derived myDerived; // 123 ���


	Base* ptr = new Derived();

	delete ptr; // �Ҹ��ڿ� virtual �� ����Ǿ� �־��� ������, ptr �� ������ �� => ����Ű�� ��ü�� Derived �� �Ҹ��ڰ� ȣ��ȴ�.
	// �Ҹ��ڵ鿡 virtual ������ �����ٸ�, ptr �� ������ �� => �ٷ� Base �� �Ҹ��ڰ� ȣ�� => 1231 ���.

	return 0;
}

