#include <iostream>
using namespace std;

class Base
{
public:
	virtual void someMethod() { cout << "Base ���� �޼���" << endl; }
};

class Derived : public Base
{
public:
	virtual void someMethod() { cout << "Derived ���� �޼���" << endl; }
};





int main()
{
	Derived derivedObj;


	/* �ڽ� Ŭ���� ��ü��
	�θ� Ŭ���� Ÿ������ ĳ�����ϰų�
	�θ� Ŭ���� ��ü�� ������ �� �ִ�.
	�� �� ���� ���, �ڽ� Ŭ�������� Ư���� ������� �����̽��� �߻��Ѵ�. */
	Base baseObj = derivedObj;

	baseObj.someMethod(); // �����̽� �߻�, Base ���� �޼��� ȣ��




	/* �Ļ� Ŭ���� ��ü��
	���̽� Ŭ���� Ÿ���� �����ͳ� ���۷����� ����ų �� �ִ�.
	�׸��� �̰�쿣 �����̽��� �߻����� �ʴ´�. */
	Base& baseRef = derivedObj; // ���̽� Ŭ���� Ÿ������ �Ļ� Ŭ���� ���� = ��ĳ����

	baseRef.someMethod(); // �����̽� �߻�����, Derived ���� �޼��� ȣ��



	/* �ݴ�� ���̽� Ŭ������ �Ļ� Ŭ������ ĳ�����ϴ� �� = �ٿ� ĳ���� 
	�������� �߸� �ƴ�. */
	Derived* derivedPtr = static_cast<Derived*>(&baseObj); // &baseObj �� Base Ÿ�� ������ ���ε�, �̸� Derived Ÿ�� ������ ������ ���� ����ȯ

	
	/* �ٿ� ĳ������ �ʿ��� ���, dynamic_cast() �� ��� => �߸��� ĳ������ ��� ó������ �ʴ´�.
	dynamic_cast() �� vtable �� �ִ� ��ü���� ��밡���ϴ�.
	���н� �������� ��� ���� nullptr, ��ü ���۷����� ��� std::bad_cast �ͼ����� �߻���Ų��. */
	Derived* downCasting = dynamic_cast<Derived*>(&baseObj);
	if (downCasting == nullptr) {}

}







