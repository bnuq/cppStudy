#include <memory>
#include <iostream>

class Simple {
public:
	Simple() { std::cout << "생성자 호출" << std::endl; }
	~Simple() { std::cout << "소멸자 호출" << std::endl; }
};


int main()
{
	/*
	* 하나의 객체를 동적할당하고
	* 두 shared_ptr 이 하나의 객체를 가리키는 상황
	* 생성자 한번에 소멸자가 두번 호출되면서 에러가 발새애
	*/
//	Simple* simplePtr = new Simple(); // 생성자 호출
//	std::shared_ptr<Simple> smartPtr1(simplePtr); // 프로그램 종료 후 소멸자 호출
//	std::shared_ptr<Simple> smartPtr2(simplePtr); // 프로그램 종료 후 소멸자 호출


	/*
	* shared_ptr 가 하나의 객체를 동시에 가리키려면
	* shared_ptr 의 복사 생성자를 이용해야 한다
	* 공유하고자 하는 메모리의 주소를 직접 지정하지 않고, 공유하려는 shared_ptr 의 복사본을 만든다
	* 그래야 중복 삭제가 발생하지 않는다
	*/
	auto smartPtr1 = std::make_shared<Simple>();
	auto smartPtr2(smartPtr1);
	std::shared_ptr<Simple> smartPtr3(smartPtr2);
}