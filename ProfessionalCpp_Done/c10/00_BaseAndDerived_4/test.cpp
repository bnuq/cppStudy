#include "dtor.h"

int main()
{
	Base* ptr = new Derived(); // Derived ��ü�� �����Ҵ��ϰ� �̰��� Base �����ͷ� ����Ŵ
	// �׷��� Derived �� �����Ҵ��ϸ鼭, Derived �� ������ ȣ�� => mString �Ҵ�

	delete ptr; // Base �����Ͱ� ����Ű�� �޸� ���� => Base �����Ͷ�, ~Base() �� ȣ��. ~Derived() �� ȣ����� �ʴ´�.
	// Derived ��ü���� �����Ҵ� �ƴ� mString �� �������� �ʴ´�.
	// �Ҹ��ڸ� virtual �� �������� �ʾұ� �����̴�.
}