#include <string>
#include <iostream>

// 좌측값, lvalue => 이름있는 변수
// 우측값, rvalue => 임시 값, 리터럴, 값
/* 일반적으로 임시 객체는 const type& 으로 취급하지만,
우측값 레퍼런스, && 를 사용하는 오버로딩이 있다면 그것을 사용한다
*/

void handleMessage(std::string& message)
{
	std::cout << "이 버전의 함수는 좌측값, lvalue 만을 다룬다." << std::endl;
}
void handleMessage(const std::string& message)
{
	std::cout << "이 버전의 함수는 좌측값, lvalue 를 다룰 수 있다." << std::endl;
	std::cout << "밑의 우측값 레퍼런스를 다루는 함수가 없었다면 이 함수가 우측값까지 처리했을 것이다." << std::endl;
}

void helper(std::string&& mes)
{
	// 우측값 레퍼런스 매개변수를 받아서, 뭔가 처리를 도와주는 helper 함수가 있다고 하자.
}


void  handleMessage(std::string&& message) // string 우측값 레퍼런스 타입인 message 자체는 좌측값이다. 이름있는 변수니까
{
	std::cout << " 이 버전의 함수는 &&, 우측값 레퍼런스를 사용하므로 "
		"우측값을 처리하는 함수가 된다." << std::endl;

	// 매개변수 message 를 helper 함수에서 처리하고 싶다면
	// message 가 좌측값이니까 이를 우측값으로 바꿔주는 std::move( ) 메서드를 이용해야 한다.
	helper(std::move(message));
	//	helper(message); => 그냥 쓰면 컴파일 에러
}


int main()
{
	std::string a = "Hello";
	std::string b = "World";

	handleMessage(a);

	handleMessage("world"); // 리터럴을 전달
	handleMessage(a + b); // 전달된 인수 a+b 는 임시 변수니까, 매개변수로 넘기고 나서 함수 리턴 후에 사라진다.


	// <utility> 의 std::move( ) 함수를 이용하면, 좌측값을 우측값으로 캐스팅할 수 있다??
	handleMessage(std::move(a)); // 우측값 레퍼런스 버전을 호출.
	handleMessage(a);
}