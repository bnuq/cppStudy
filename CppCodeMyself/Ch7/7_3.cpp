#include <iostream>

int main()
{
	int* myArray = new int[8];

	// 다음 두 식은 의미가 같다.
	myArray[2] = 33;
	*(myArray + 2) = 33;
	/*
	포인터 연산 시, 포인터가 가리키는 타입을 이용한다.
	myArray 는 int 타입을 가리키고 있으므로
	myArray+2 는 첫 번째 요소 칸으로 부터 두번 넘어간다
	*/

	int* otherPtr = myArray + 3;
	// 포인터 연산에서 뺄셈을 이용하면,
	// 두 포인터 사이에 포인터에 지정한 타입의 원소가 몇 개 있는 지 알 수 있다
	std::cout << otherPtr - myArray << std::endl; // 두 포인터 사이에는 int 가 3개 존재한다
}