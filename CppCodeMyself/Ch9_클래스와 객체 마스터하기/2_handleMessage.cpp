#include <string>
#include <iostream>

// ������, lvalue => �̸��ִ� ����
// ������, rvalue => �ӽ� ��, ���ͷ�, ��
/* �Ϲ������� �ӽ� ��ü�� const type& ���� ���������,
������ ���۷���, && �� ����ϴ� �����ε��� �ִٸ� �װ��� ����Ѵ�
*/

void handleMessage(std::string& message)
{
	std::cout << "�� ������ �Լ��� ������, lvalue ���� �ٷ��." << std::endl;
}
void handleMessage(const std::string& message)
{
	std::cout << "�� ������ �Լ��� ������, lvalue �� �ٷ� �� �ִ�." << std::endl;
	std::cout << "���� ������ ���۷����� �ٷ�� �Լ��� �����ٸ� �� �Լ��� ���������� ó������ ���̴�." << std::endl;
}

void helper(std::string&& mes)
{
	// ������ ���۷��� �Ű������� �޾Ƽ�, ���� ó���� �����ִ� helper �Լ��� �ִٰ� ����.
}


void  handleMessage(std::string&& message) // string ������ ���۷��� Ÿ���� message ��ü�� �������̴�. �̸��ִ� �����ϱ�
{
	std::cout << " �� ������ �Լ��� &&, ������ ���۷����� ����ϹǷ� "
		"�������� ó���ϴ� �Լ��� �ȴ�." << std::endl;

	// �Ű����� message �� helper �Լ����� ó���ϰ� �ʹٸ�
	// message �� �������̴ϱ� �̸� ���������� �ٲ��ִ� std::move( ) �޼��带 �̿��ؾ� �Ѵ�.
	helper(std::move(message));
	//	helper(message); => �׳� ���� ������ ����
}


int main()
{
	std::string a = "Hello";
	std::string b = "World";

	handleMessage(a);

	handleMessage("world"); // ���ͷ��� ����
	handleMessage(a + b); // ���޵� �μ� a+b �� �ӽ� �����ϱ�, �Ű������� �ѱ�� ���� �Լ� ���� �Ŀ� �������.


	// <utility> �� std::move( ) �Լ��� �̿��ϸ�, �������� ���������� ĳ������ �� �ִ�??
	handleMessage(std::move(a)); // ������ ���۷��� ������ ȣ��.
	handleMessage(a);
}