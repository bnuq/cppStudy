#include "Derived.h"

int main()
{
	Base base1;
	base1.someMethod();
//	base1.someOtherMethod(); Base class can't call Derived class method


	Derived der1; // Base Ŭ���� ��ӹ޾ұ⿡
	der1.someMethod(); // Derived ��ü���� Base Ŭ������ ����Լ��� ����� �� �ִ�.
	der1.someOtherMethod(); // Derived class method


	/* Derived Ÿ�� ��ü�� Base Ÿ�� ��ü�� ��� ����� ������ �ִ� => Derived Ÿ���� Base Ÿ�� �̱⵵ �ϴ�.
	* ������ Base Ÿ���� Derived Ÿ���� �ƴϴ�.
	
	���׸��� ������ ������ġ�� ���׸��� ������ġ�̴�. 
	�ݴ�� Base Ŭ������ Derived Ŭ������ ���� ��ü�� �𸥴� => ���� �� 
	*/

	// der1 ��ü�� Derived Ÿ���̸鼭 ���ÿ� Base Ÿ������ ����� �� �ִ�.


	// � Ŭ���� ��ü�� �����ͳ� ���۷����� ����ų ��, �ش� Ŭ������ �Ļ� Ŭ�������� ����ų �� �ִ�.
	Base* basePtr; // Base class �� ����Ű�� ������
	
	basePtr = &base1; // Base ����Ŵ
	basePtr->someMethod();

	basePtr = &der1; // Base class �� �Ļ� Ŭ������ Derived Ÿ���� ����Ŵ. => Derived Ÿ�� ��ü�� Derived Ÿ���� �ƴ� Base Ÿ������ �� �� �ֱ� ������ ����?
//	basePtr->SomeOtherMethod(); ������ Base �����ͷ� Derived Ŭ���� �޼��带 ȣ���� ���� ����. �ֳĸ�, Base Ÿ������ ���� �����ϱ�.


	Base& baseRef1 = base1; // ���۷����� ���
	Base& baseRef2 = der1; // �Ļ� Ŭ���� ��ü�� ���۷����� ����Ŵ


	Derived* derivedPtr;
//	derivedPtr = &base1; ��ü �����Ͱ� �ڽ��� �θ� Ŭ����, ���̽� Ŭ������ ����ų �� �� ����.
	derivedPtr = &der1; // Derived pointer �� Derived Ÿ���� ����Ŵ


	
}