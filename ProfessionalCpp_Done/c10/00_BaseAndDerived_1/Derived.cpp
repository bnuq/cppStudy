#include "Derived.h"
#include <iostream>
using namespace std;


void Derived::someMethod() // �޼��带 ������ ���� virtual, override Ű���带 �����Ѵ�.
{
	cout << "Derived Ŭ�������� someMethod() �޼����� ������ �����Ͽ���." << endl;
}




/* Derived Ŭ������ �θ� Ŭ������ Base Ŭ������ public, protected ������ ����� �����Ӱ� ����� �� �ִ�. */
void Derived::someOtherMethod()
{
	cout << "Derived Ÿ�Կ��� Base Ŭ������ ��� �����Ϳ� ������ �����ϴ�" << endl
		<< "mProtectedInt = " << mProtectedInt << endl // ��ġ �ڽ��� ������ ����� ��ó�� �����Ӱ� ���
		<< "private �������� �������� ���Ѵ�." << endl;
}

/* � Ŭ������ ������ ����� �޼��带
protected �� ���� => �Ļ� Ŭ�������� ������ �����ϴ�.
private �� ���� => �Ļ� Ŭ�������� ������ �Ұ����ϴ�.
� Ŭ������ ���� ��, ���� ���� ���� �� �ؿ� �ִ� �Ļ� Ŭ�������� �����ϴ� ���� ����ؾ� �Ѵ�. 
*/