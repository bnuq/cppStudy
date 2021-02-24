#include <memory>
#include <iostream>

class Simple {
public:
	Simple() { std::cout << "������ ȣ��" << std::endl; }
	~Simple() { std::cout << "�Ҹ��� ȣ��" << std::endl; }
};

void useResource(std::weak_ptr<Simple>& weakSimple)
{
	auto resource = weakSimple.lock(); // lock( ) �޼���. weak_ptr �� ����� shared_ptr �� �����Ѵ�
	if (resource) std::cout << "Resource still alive" << std::endl; // shared_ptr �� ���� �����Ѵ�
	else std::cout << "Resoruce has been freed" << std::endl; // shared_ptr �� ������ �ż� nullptr �� ����Ǿ� �ִ�
}


int main()
{
	// Simple ��ü�� ����Ű�� shared_ptr �� �����.
	auto sharedPtr = std::make_shared<Simple>();

	// sharedPtr �� ����Ű�� Simple ��ü, ���ҽ��� ���۷����� �����ϴ� weak_ptr �� �����.
	std::weak_ptr<Simple> weakPtr(sharedPtr);
	std::weak_ptr<Simple> weakPtr2(weakPtr);
	
	useResource(weakPtr);
	useResource(weakPtr2);

	/*
	* shared_ptr �� �����Ѵ�. 
	* �׷��� weak_ptr �� ��� �ִ��� ���ҽ��� �����ȴ�
	*/
	sharedPtr.reset();
	
	useResource(weakPtr);
	useResource(weakPtr2);

}