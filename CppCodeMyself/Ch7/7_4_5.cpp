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
다음과 같이 해서는 안된다
class Foo
{
public:
	std::shared_ptr<Foo> get_shared_Pointer() {
		return shared_ptr<Foo>(this); 객체 자기 자신의 주소를 가리키는 shared_ptr 를 만들어서 넘긴다는 아이디어
	}
};

왜 안되느냐 => 중복 삭제가 발생한다.
shared_ptr 복제 생성자를 이용해서 리소스를 공유하는 것이 아니라
각각의 shared_ptr 이 하나의 객체를 공유하는 상황이 되버려서, 객체는 한번만 생성되는데 소멸을 두번하는 상황이 발생한다
*/

int main()
{
	// Foo 객체를 가리키는 shared_ptr 를 만든다
	auto ptr1 = std::make_shared<Foo>();
	// shared_ptr 인 ptr1 이 가리키는 객체의 소유권을 공유하는 shared_ptr 를 리턴한다.
	auto ptr2 = ptr1->get_shared_Pointer(); // ptr1 과 ptr2 는 같은 객체를 공유한다.

	std::cout << ptr1.use_count() << std::endl;
	std::cout << ptr2.use_count() << std::endl;

	// shared_ptr 인 ptr1 이 가리키는 객체의 소유권을 추적하는 weak_ptr 를 리턴한다
	auto ptr3 = ptr1->get_weak_Pointer(); // ptr3 는 ptr1 이 객체를 잘 가지고 있는 지를 추적한다. 관리한다.

	ptr1.reset();
	std::cout << ptr2.use_count() << std::endl;

	if (ptr3.lock() != nullptr) std::cout << "아직 리소스가 ptr2 에 의해 유지되고 있다." << std::endl;
	else std::cout << "리소스가 해제 됐다." << std::endl;

	ptr2.reset(); // shared_ptr 를 모두 리셋했다.
	if (ptr3.lock() != nullptr) std::cout << "아직 리소스가 ptr2 에 의해 유지되고 있다." << std::endl;
	else std::cout << "리소스가 해제 됐다." << std::endl;
}