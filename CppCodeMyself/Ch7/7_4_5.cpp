#include <memory>
#include <iostream>

class Foo : public std::enable_shared_from_this<Foo>
{
public:
	std::shared_ptr<Foo> get_shared_Pointer() {
		return shared_from_this();
	}
	std::weak_ptr<Foo> get_weak_Pointer() {
		return weak_from_this();
	}
};

/*
������ ���� �ؼ��� �ȵȴ�
class Foo
{
public:
	std::shared_ptr<Foo> get_shared_Pointer() {
		return shared_ptr<Foo>(this); ��ü �ڱ� �ڽ��� �ּҸ� ����Ű�� shared_ptr �� ���� �ѱ�ٴ� ���̵��
	}
};

�� �ȵǴ��� => �ߺ� ������ �߻��Ѵ�.
shared_ptr ���� �����ڸ� �̿��ؼ� ���ҽ��� �����ϴ� ���� �ƴ϶�
������ shared_ptr �� �ϳ��� ��ü�� �����ϴ� ��Ȳ�� �ǹ�����, ��ü�� �ѹ��� �����Ǵµ� �Ҹ��� �ι��ϴ� ��Ȳ�� �߻��Ѵ�
*/

int main()
{
	// Foo ��ü�� ����Ű�� shared_ptr �� �����
	auto ptr1 = std::make_shared<Foo>();
	// shared_ptr �� ptr1 �� ����Ű�� ��ü�� �������� �����ϴ� shared_ptr �� �����Ѵ�.
	auto ptr2 = ptr1->get_shared_Pointer(); // ptr1 �� ptr2 �� ���� ��ü�� �����Ѵ�.

	std::cout << ptr1.use_count() << std::endl;
	std::cout << ptr2.use_count() << std::endl;

	// shared_ptr �� ptr1 �� ����Ű�� ��ü�� �������� �����ϴ� weak_ptr �� �����Ѵ�
	auto ptr3 = ptr1->get_weak_Pointer(); // ptr3 �� ptr1 �� ��ü�� �� ������ �ִ� ���� �����Ѵ�. �����Ѵ�.

	ptr1.reset();
	std::cout << ptr2.use_count() << std::endl;

	if (ptr3.lock() != nullptr) std::cout << "���� ���ҽ��� ptr2 �� ���� �����ǰ� �ִ�." << std::endl;
	else std::cout << "���ҽ��� ���� �ƴ�." << std::endl;

	ptr2.reset(); // shared_ptr �� ��� �����ߴ�.
	if (ptr3.lock() != nullptr) std::cout << "���� ���ҽ��� ptr2 �� ���� �����ǰ� �ִ�." << std::endl;
	else std::cout << "���ҽ��� ���� �ƴ�." << std::endl;
}