#include "Derived.h"
#include <iostream>

using namespace std;

int main()
{
	Derived myDerived;
	Base& baseRef = myDerived; // ���̽� Ŭ���� ���۷����� �Ļ� Ŭ���� ��ü�� ����Ŵ
	baseRef.someMethod(1.1); // �Ļ� Ŭ����, Derived ������ someMethod() �� ȣ��ȴ�. �Ļ� Ŭ�������� �������̵� �����Ƿ�, �Ļ� Ŭ���� ������ ȣ��


	otherDerived myOtherDerived;
	Base& baseOtherRef = myOtherDerived; // �ٸ� �Ļ� Ŭ���� ��ü�� ����Ŵ
	baseOtherRef.someMethod(1.1); // Base Ŭ���� ������ someMethod() �� ȣ��ȴ�.
	/* Base ���۷����� Base Ŭ������ someMethod() �� ȣ���Ϸ� �߰�, 
	otherDerived Ŭ�������� Base Ŭ������ someMethod() �� �������̵��� �޼��尡 �����Ƿ�,
	Base ���۷����� Base ������ someMethod() �� ȣ���ϰ� �� ��. */
}