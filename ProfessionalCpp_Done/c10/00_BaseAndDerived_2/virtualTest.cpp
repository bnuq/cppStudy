#include "Derived.h"
#include <iostream>

using namespace std;

int main()
{
	Derived myDerived;
	myDerived.go(); // Derived ��ü���� ȣ���ϴϱ�, Derived version's go() �޼��尡 ȣ��ȴ�.
	// �̶� go() �޼���� ���̽� Ŭ������ �޼��带 �������̵��� ���� �ƴ�, Derived Ŭ������ ������ ������� ���� ������ �޼����.


	Base& baseRef = myDerived; // ���̽� Ŭ���� ���۷����� �Ļ� Ŭ������ ����Ŵ
	baseRef.go(); // Base version's go() �޼��� ȣ��
	// ���̽� Ŭ���� ������ virtual Ű���尡 ������ ������, go() �޼��带 �Ļ� Ŭ�������� �������̵� �ߴ��� ã�ƺ����� �ʴ´�.
}