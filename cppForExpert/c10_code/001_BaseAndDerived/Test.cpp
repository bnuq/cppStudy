#include "Derived.h"

int main()
{
	Base base1;
	base1.someMethod();

	Derived der1; // Base Ŭ���� ��ӹ޾ұ⿡
	der1.someMethod(); // Derived ��ü���� Base Ŭ������ ����Լ��� ����� �� �ִ�.
	der1.someOtherMethod(); // Derived class method


	/* Derived Ÿ�� ��ü�� Base Ÿ�� ��ü�� ��� ����� ������ �ִ� => Derived Ÿ���� Base Ÿ�� �̱⵵ �ϴ�. 
	���׸��� ������ ������ġ�� ���׸��� ������ġ�̴�. 
	�ݴ�� Base Ŭ������ Derived Ŭ������ ���� ��ü�� �𸥴� => ���� �� */
}