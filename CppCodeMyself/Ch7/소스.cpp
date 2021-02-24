#include <iostream>

/*
상자 = 메모리 한 칸
그 상자에 붙어있는 레이블, 택, 이름표 = 변수 이름
상자안에 들어 있는 데이터 = 변수에 저장된 값
*/

void exer1_1()
{
	// automatic variable, stack 에 저장
	int i = 7;

	// ptr 변수는 스택에 저장
	int* ptr = nullptr; // 항상 포인터를 nullptr 이나 적절한 포인터를 가리키도록 초기화한다
	// new 키워드를 이용하면 힙 메모리가 할당된다. 동적 메모리는 항상 힙에 할당
	ptr = new int; // 그 할당된 메모리를 포인터가 가리킨다
	
	// 위의 과정을 한 줄로 표현
	int* ptr2 = new int;

	// handle 은 스택에 저장
	int** handle = nullptr; // int* 를 가리키는 handle. int* 의 포인터, 주소를 저장한다.
	// 동적할당한 메모리는 모두 힙에 저장
	handle = new int*; // int* 를 저장할 수 있는 메모리를 할당하고 그 포인터를 handle 에 저장
	*handle = new int; // int 를 저장할 수 있는 메모리를 할당하고 그 포인터를 handle 이 가리키는 메모리에 저장

}
//============================================================================//

void leaky()
{
	new int; // int 를 담을 공간만큼을 할당하고, 할당된 메모리에 대한 포인터를 잃어 버림
	std::cout << "방금 int 하나를 잃어버렸다." << std::endl;
}

class Foo {
};

void exer1_2()
{
	int* ptr = new int;
	// 할당한 메모리의 포인터를 delete 해줘야 메모리가 해제된다
	delete ptr;
	ptr = nullptr; // 사고예방. nullptr 로 다시 초기화

	/*
	malloc 함수 => 인수로 지정된 바이트 수만큼 메모리를 할당
	할당 후 어떤 타입을 가리키는 포인터 인지를 명시적으로 지정
	*/
	Foo* myFoo = (Foo*)malloc(sizeof(Foo));
	free(myFoo);
	/*
	new 는 메모리 할당 + 객체까지 만들어 준다
	기본 생성자를 호출한다는 의미에서 빈괄호를 명시적으로 표현
	*/
	Foo* myOtherFoo = new Foo();
	// delete 는 소멸자 호출, 객체를 정상적으로 제거한다
	delete myOtherFoo;

	/*
	기본적으로 new 가 메모리 할당을 실패하면 프로그램이 종료된다
	익셉션을 발생
	*/
	// 익셉션을 발생시키지 않는 new. nullptr 를 리턴한다
	int* ptr2 = new(std::nothrow) int;
}
//============================================================================//

void exer1_3()
{
	/*
	int 를 저장할 수 있는 5개의 연속된 공간이 스택에 할당
	스택에 생성하는 배열의 크기는 컴파일 시간에 결정되어야 한다 => 상수값이여야 한다
	*/
	int myArray[5];
	/*
	int 를 저장할 수 있는 5개의 연속된 공간이 힙 메모리에 할당
	그 공간을 가리키는 포인터를 변수에 저장
	*/
	int* myArrayPtr = new int[5];
	// new[] 는 delete[] 로 메모리 해제를 한다
	delete[] myArrayPtr;
	myArrayPtr = nullptr;
}

// 배열을 힙에 할당하면 실행 시간에 배열의 크기를 정할 수 있다
// 배열 자체는 한 번 할당하면 크기를 바꿀 수 없다
int* createIntArray(int n)
{
	size_t numInts = n;
	int* intArr = new int[n];
	return intArr; // 이때 intArr = 동적으로 할당된 배열, dynamically allocated array.
}

class Sample
{
public:
	Sample() { std::cout << "Constructor" << std::endl; } // 디폴트 생성자
	~Sample() { std::cout << "Destructor" << std::endl; }
};

void exer1_3_2()
{
	/*
	new[N] 을 이용하여 객체를 담는 N개의 블록을 연속된 공간에 할당
	new[ ] 를 호출하면 각 객체마다 디폴트 생성자, 제로 인수 생성자가 호출된다
	즉 디폴트 생성자가 없으면 객체배열을 못 만든다
	*/
	Sample* mySampleArray = new Sample[4]; // 디폴트 생성자가 4 번 호출된다
	delete[] mySampleArray; // 각 원소 객체마다 소멸자를 호출. 총 4 번 호출된다
	mySampleArray = nullptr;

	// 포인터 배열에 대해서는 각 원소가 가리키는 객체를 일일이 해제해야 한다
	const size_t size = 4;
	Sample** mySamplePtrArray = new Sample * [size];
	// 각 포인터 마다 객체를 할당
	for (size_t i = 0; i < size; i++) { mySamplePtrArray[i] = new Sample(); }
	// 각 포인터가 가리키는 할당된 객체를 삭제한다
	for (size_t i = 0; i < size; i++) { delete mySamplePtrArray[i]; }
	// 배열을 삭제한다
	delete[] mySamplePtrArray; // new[ ] 에 대응하는 delete[ ]
	mySamplePtrArray = nullptr;
}

char** allocateCharacterBoard(size_t xDimension, size_t yDimension)
{
	char** myArray = new char* [xDimension];
	
	for (size_t i = 0; i < xDimension; i++)
	{
		myArray[i] = new char[yDimension];
	}
	return myArray;
}
void releaseCharacterBoard(char** myArray, size_t xDimension)
{
	for (size_t i = 0; i < xDimension; i++)
	{
		delete[] myArray[i];
	}
	delete[] myArray;
}

int main()
{
	int* ptr = new(std::nothrow) int(8);
	std::cout << *ptr << std::endl;
	delete ptr;
}