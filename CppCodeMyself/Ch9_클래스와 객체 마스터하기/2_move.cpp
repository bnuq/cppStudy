#include <iostream>
#include <string>

using namespace std;

/*
* std::move( ) 의 역할
* lvalue 를 rvalue 로 캐스팅한다, 우측값으로 해석할 수 있음을 알린다
* 그래서 이동 의미론을 이용할 수 있게 해준다.
*/

int main()
{
	string name1 = "aaa", name2 = "bbb";

	string name3(name1); // name3 = aaa
	string name4(std::move(name2)); // name4 = bbb 이고 name2 의 메모리는 비어버린다.
	// string 의 이동 생성자를 사용. name2 객체를 우측값으로 보고 동적 할당된 메모리 소유권을 바꿔버린다.
	// 그래서 name4 가 원래 가지고 있던 "" 가 name2 로 넘어가고 대신 name4 가 "bbb" 를 가지게 된다.

	cout << "name1 = " << name1 << endl
		<< "name2 = " << name2 << endl 
		<< "name3 = " << name3 << endl
		<< "name4 = " << name4 << endl;



	cout << endl << endl;



	name2 = std::move(name3); // name2 = aaa 이고 name3 는 비어버린다.
	// string 의 이동 대입 연산자 사용.


	cout << "name1 = " << name1 << endl
		<< "name2 = " << name2 << endl
		<< "name3 = " << name3 << endl
		<< "name4 = " << name4 << endl;
}

/*
* std::move() 는 좌측값을 우측값으로 캐스팅해주는 역할
* 기존에 좌측값이였던 변수에 대해서 이동의미론을 이용할 수 있게 해준다.
* 
* 컴파일러가 자동으로 만드는 이동 생성자, 이동 대입 연산자의 경우
* 동적으로 할당된 메모리는 swap, 교환을 해서 메모리 할당에 대한 소유권을 바꿔주고
* 할당되지 않은 그냥 기본 타입의 경우에는 바꾸지 않는 것 같다.( 이거는 추측 )
*/



/*
* <utility> 의 std::swap 이 어떻게 구현되어 있는가
*/
template <typename T>
void swapMove(T& a, T& b)
{
	T temp(std::move(a)); // a 객체를 rvalue 로 캐스팅, 그 후 이동 생성자 호출하여 T 와 a 의 메모리 소유권을 교환 // a 가 비어있는 상태, temp = 'a'
	a = std::move(b); // b 객체를 rvalue 로 캐스팅. 이동 대입 연산자 호출. a 와 b 의 메모리 소유권 교환 // b 가 비어있는 상태, a = 'b'
	b = std::move(temp); // temp 객체를 rvalue 로 캐스팅. 이동 대입 연산자 호출. b 와 temp 의 메모리 소유권 교환 // temp 가 비어있다. b = 'a'
}
