#include <iostream>
#include <memory> // ����Ʈ �����͸� ����ϴ� �� �ʿ�

void processInt(int* ptr)
{
	std::cout << *ptr << std::endl;
}

class Foo {
public:
	// �μ��� ���� ����Ʈ �����͸� ������ ����� '�̵�' ��Ų��
	Foo(std::unique_ptr<int> data) : mData(std::move(data)) { }
private:
	std::unique_ptr<int> mData;
};

// ���� �޸𸮸� �Ҵ��ϴ� �Լ�
int* malloc_int(int value)
{
	int* p = (int*)malloc(sizeof(int));
	*p = value;
	std::cout << "my malloc" << std::endl;
	return p;
}


int main()
{
	// auto �� make_unique �� �̿��Ͽ� int Ÿ���� ����Ű�� unique ����Ʈ �����͸� ����
	auto myIntSmartPtr1 = std::make_unique<int>();
	// �����ڰ� �Ű������� �޴´ٸ� �Ұ�ȣ�� �־��ش�
	auto myIntSmartPtr2 = std::make_unique<int>(7);

	// make_unique �� ������� �ʰ� unique_ptr �� ����� ���
	std::unique_ptr<int> myIntSmartPtr3(new int(10)); // �Ұ�ȣ �ȿ� �����Ҵ��� �޸� �ּҸ� �ִ´�

	// make_unique ����� �� ����


	// ����Ʈ �����͵� �Ȱ��� * �� -> �� �̿��Ͽ� �������Ѵ�
	std::cout << *myIntSmartPtr3 << std::endl;


	// processInt(myIntSmartPtr2); �Ϲ� �����͸� �޴� �Լ��� ����Ʈ �����͸� ������ �� ����
	
	// get( ) �޼��带 �̿�, ���� �����Ϳ� ������ �� �ִ�.
	processInt(myIntSmartPtr2.get()); // myIntSmartPtr2.get() => int* �� �ȴ�


	// reset( ) �޼��带 ���, unique_ptr ���� �����͸� �����Ѵ�.
	myIntSmartPtr3.reset(); // ���ҽ� ���� �� nullptr �� �ʱ�ȭ
	if (myIntSmartPtr3 == nullptr) std::cout << "nullptr" << std::endl;

	// reset( ) �޼���� ���� ������ ���� �� �ٸ� �����ͷ� ������ ���� �ִ�
	myIntSmartPtr1.reset(new int(99));
	std::cout << *myIntSmartPtr1 << std::endl;



	// release( ) �޼��� => unique_ptr �� ���� �������� ���踦 ���� �� �ִ�.
	// ���ҽ��� ���� ���� �����͸� ������ �� ����Ʈ �����͸� nullptr �� ����
	int* otherPtr = myIntSmartPtr1.release(); // ����Ʈ �������� �������� �����Ѵ�
	// myIntSmartPtr1 == nullptr �� �Ǿ���ȴ�.
	processInt(otherPtr);
	delete otherPtr; // ���� �����ʹ� ���� �����ؾ� �Ѵ�
	otherPtr = nullptr;


	/*
	unique_ptr �� �ܵ� �������� ǥ��, ������ �� ����. 2���� �����Ͱ� �ϳ��� ��ü�� ����ų �� ����.
	std::move( ) �� �̿��ϸ� �ϳ��� unique_ptr �� �ٸ� ������ �̵���ų �� �ִ�.
	�������� ��������� �����ϴ� �뵵
	*/
	auto SmartPtr = std::make_unique<int>(42); // ����Ʈ �����͸� �ϳ� �����
	// Foo ��ü�� ����� ���� �μ��� ����Ʈ �����͸� ���� ���� std::move �� �̿��� �̵� ��Ų��
	Foo f(std::move(SmartPtr));


	
	// ���� C ��Ÿ���� ���� �Ҵ� �迭�� unique_ptr �� ����Ű��
	auto myVariableSizeArray = std::make_unique<int[]>(10); // int 10���� ������ �����Ҵ� �迭
	

	// unique_ptr �� �޸𸮸� �Ҵ��ϴ� ����� �����ϴ� ����� ������ �� �ִ�
	// Ŀ���� ������
	// ����Ʈ �������� �μ��� �����Ҵ��� �޸� �ּҿ� �����ϴ� �Լ��� ����
	std::unique_ptr<int, decltype(free)*> intPtr(malloc_int(42), free);
	// decltype(free) => free �Լ��� Ÿ���� �˾Ƴ��� ���� ���
	// ���ø� Ÿ�� �Ű������� �ݵ�� �Լ��� ���� ������ Ÿ���̿��� �Ѵ�. �׷��� * ���� ����

}