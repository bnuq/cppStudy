#include <iostream>
#include <memory> // 스마트 포인터를 사용하는 데 필요

void processInt(int* ptr)
{
	std::cout << *ptr << std::endl;
}

class Foo {
public:
	// 인수로 받은 스마트 포인터를 데이터 멤버로 '이동' 시킨다
	Foo(std::unique_ptr<int> data) : mData(std::move(data)) { }
private:
	std::unique_ptr<int> mData;
};

// 정수 메모리를 할당하는 함수
int* malloc_int(int value)
{
	int* p = (int*)malloc(sizeof(int));
	*p = value;
	std::cout << "my malloc" << std::endl;
	return p;
}


int main()
{
	// auto 와 make_unique 를 이용하여 int 타입을 가리키는 unique 스마트 포인터를 만듦
	auto myIntSmartPtr1 = std::make_unique<int>();
	// 생성자가 매개변수를 받는다면 소괄호에 넣어준다
	auto myIntSmartPtr2 = std::make_unique<int>(7);

	// make_unique 를 사용하지 않고 unique_ptr 를 만드는 방법
	std::unique_ptr<int> myIntSmartPtr3(new int(10)); // 소괄호 안에 동적할당한 메모리 주소를 넣는다

	// make_unique 방법이 더 좋다


	// 스마트 포인터도 똑같이 * 와 -> 를 이용하여 역참조한다
	std::cout << *myIntSmartPtr3 << std::endl;


	// processInt(myIntSmartPtr2); 일반 포인터를 받는 함수에 스마트 포인터를 전달할 수 없다
	
	// get( ) 메서드를 이용, 내부 포인터에 접근할 수 있다.
	processInt(myIntSmartPtr2.get()); // myIntSmartPtr2.get() => int* 가 된다


	// reset( ) 메서드를 사용, unique_ptr 내부 포인터를 해제한다.
	myIntSmartPtr3.reset(); // 리소스 해제 후 nullptr 로 초기화
	if (myIntSmartPtr3 == nullptr) std::cout << "nullptr" << std::endl;

	// reset( ) 메서드로 내부 포인터 해제 후 다른 포인터로 변경할 수도 있다
	myIntSmartPtr1.reset(new int(99));
	std::cout << *myIntSmartPtr1 << std::endl;



	// release( ) 메서드 => unique_ptr 와 내부 포인터의 관계를 끊을 수 있다.
	// 리소스에 대한 내부 포인터를 리턴한 뒤 스마트 포인터를 nullptr 로 설정
	int* otherPtr = myIntSmartPtr1.release(); // 스마트 포인터의 소유권을 해제한다
	// myIntSmartPtr1 == nullptr 이 되어버렸다.
	processInt(otherPtr);
	delete otherPtr; // 이제 포인터는 직접 해제해야 한다
	otherPtr = nullptr;


	/*
	unique_ptr 는 단독 소유권을 표현, 복사할 수 없다. 2개의 포인터가 하나의 객체를 가리킬 수 없다.
	std::move( ) 를 이용하면 하나의 unique_ptr 를 다른 곳으로 이동시킬 수 있다.
	소유권을 명시적으로 이전하는 용도
	*/
	auto SmartPtr = std::make_unique<int>(42); // 스마트 포인터를 하나 만들고
	// Foo 객체를 만들기 위해 인수로 스마트 포인터를 넣을 때도 std::move 를 이용해 이동 시킨다
	Foo f(std::move(SmartPtr));


	
	// 기존 C 스타일의 동적 할당 배열을 unique_ptr 로 가리키기
	auto myVariableSizeArray = std::make_unique<int[]>(10); // int 10개를 가지는 동적할당 배열
	

	// unique_ptr 가 메모리를 할당하는 방법과 해제하는 방법을 설정할 수 있다
	// 커스텀 제거자
	// 스마트 포인터의 인수로 동적할당한 메모리 주소와 해제하는 함수를 전달
	std::unique_ptr<int, decltype(free)*> intPtr(malloc_int(42), free);
	// decltype(free) => free 함수의 타입을 알아내기 위해 사용
	// 템플릿 타입 매개변수는 반드시 함수에 대한 포인터 타입이여야 한다. 그래서 * 까지 붙임

}