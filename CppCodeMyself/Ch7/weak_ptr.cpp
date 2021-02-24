#include <memory>
#include <iostream>

class Simple {
public:
	Simple() { std::cout << "생성자 호출" << std::endl; }
	~Simple() { std::cout << "소멸자 호출" << std::endl; }
};

void useResource(std::weak_ptr<Simple>& weakSimple)
{
	auto resource = weakSimple.lock(); // lock( ) 메서드. weak_ptr 에 저장된 shared_ptr 를 리턴한다
	if (resource) std::cout << "Resource still alive" << std::endl; // shared_ptr 이 아직 존재한다
	else std::cout << "Resoruce has been freed" << std::endl; // shared_ptr 이 해제가 돼서 nullptr 이 저장되어 있다
}


int main()
{
	// Simple 객체를 가리키는 shared_ptr 를 만든다.
	auto sharedPtr = std::make_shared<Simple>();

	// sharedPtr 이 가리키는 Simple 객체, 리소스의 레퍼런스를 관리하는 weak_ptr 를 만든다.
	std::weak_ptr<Simple> weakPtr(sharedPtr);
	std::weak_ptr<Simple> weakPtr2(weakPtr);
	
	useResource(weakPtr);
	useResource(weakPtr2);

	/*
	* shared_ptr 를 해제한다. 
	* 그러면 weak_ptr 이 살아 있더라도 리소스는 해제된다
	*/
	sharedPtr.reset();
	
	useResource(weakPtr);
	useResource(weakPtr2);

}