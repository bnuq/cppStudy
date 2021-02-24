#include <memory>
#include <iostream>

class Simple {
public:
	Simple() { std::cout << "������ ȣ��" << std::endl; }
	~Simple() { std::cout << "�Ҹ��� ȣ��" << std::endl; }
};


int main()
{
	/*
	* �ϳ��� ��ü�� �����Ҵ��ϰ�
	* �� shared_ptr �� �ϳ��� ��ü�� ����Ű�� ��Ȳ
	* ������ �ѹ��� �Ҹ��ڰ� �ι� ȣ��Ǹ鼭 ������ �߻���
	*/
//	Simple* simplePtr = new Simple(); // ������ ȣ��
//	std::shared_ptr<Simple> smartPtr1(simplePtr); // ���α׷� ���� �� �Ҹ��� ȣ��
//	std::shared_ptr<Simple> smartPtr2(simplePtr); // ���α׷� ���� �� �Ҹ��� ȣ��


	/*
	* shared_ptr �� �ϳ��� ��ü�� ���ÿ� ����Ű����
	* shared_ptr �� ���� �����ڸ� �̿��ؾ� �Ѵ�
	* �����ϰ��� �ϴ� �޸��� �ּҸ� ���� �������� �ʰ�, �����Ϸ��� shared_ptr �� ���纻�� �����
	* �׷��� �ߺ� ������ �߻����� �ʴ´�
	*/
	auto smartPtr1 = std::make_shared<Simple>();
	auto smartPtr2(smartPtr1);
	std::shared_ptr<Simple> smartPtr3(smartPtr2);
}