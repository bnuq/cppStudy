#include "Derived.h"
#include <iostream>

using namespace std;

int main()
{
	Base myBase;
	Derived myDerived;


	myBase.func1();
	// virtual �޼��带 ȣ���ϹǷ� myBase ��ü�� vtable �� ���� => vtable ���� func1() �׸��� �Լ� �����Ͱ� ����Ű�� �ڵ带 ȣ��
	// �ش� ��ü�� Base ��ü�̱� ������ Base vtable �� ���� => Base::func1() �� ȣ���ϰ� �ȴ�.

	myDerived.func1();
	// virtual �޼��带 ȣ���ϹǷ� myDerived ��ü�� vtable �� ���� => vtable ���� func1() �׸��� �Լ� �����Ͱ� ����Ű�� �ڵ带 ȣ��
	// �ش� ��ü�� Derived ��ü�̱� ������ Derived vtable �� ���� => func1()�� �Ļ� Ŭ�������� �������̵� ���� �ʾҴ� => Base::func1() �� ȣ���ϰ� �ȴ�.
}