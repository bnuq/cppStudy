#include <memory>
#include <iostream>

class Slime {
public:
	Slime(int n) : level(n) {}
	int level;
};

int main()
{
	// ���� 30 �������� ����Ű�� shared_ptr
	auto slimePtr = std::make_shared<Slime>(30);

	/*
	* �ٸ����
	* slimePtr �� ����Ű�� �������� �����ϸ鼭
	* �� �������� ������ ����Ų��
	* �� shared_ptr �� �����Ǿ� ������ ��ü�� �����ȴ�
	* ( ������ ������, ����� ������ ) �� �μ��� shared_ptr �� �����
	*/
	auto levelPtr = std::shared_ptr<int>(slimePtr, &slimePtr->level);
	/*
	* slimePtr = ������ ������, ���۷��� ī���ÿ� ���
	* &(slimePtr->level) = ����� ������, ��¥ ����Ű�� �޸�
	*/
	
	std::cout << *levelPtr << std::endl; // �������ϸ� ����� �����Ͱ� ����Ű�� level �� ���� �� �ִ�
	std::cout << levelPtr.get() << std::endl; // get( ) �޼��带 �̿��ϸ� ����� �����͸� ���� �� �ִ�

	
}