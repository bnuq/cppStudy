#include "dtorVirtual.h"

int main()
{
	Base* ptr = new Derived(); // Derived ��ü�� �����Ҵ��ϰ� �̰��� Base �����ͷ� ����Ŵ
	// �׷��� Derived �� �����Ҵ��ϸ鼭, Derived �� ������ ȣ�� => mString �Ҵ�


	ptr->someMethod();

	delete ptr; // Base �����Ͱ� ����Ű�� �޸� ���� => Base �����Ͷ�, ~Base() �� ȣ��
	// �׷��� �Ҹ��ڰ� virtual ������ �Ǿ� �����Ƿ�, �������̵� �� �޼��带 ȣ�� => ~Derived() �� ȣ��
	// Derived ��ü���� �����Ҵ� �ƴ� mString �� �����ǰ� �ȴ�.
}