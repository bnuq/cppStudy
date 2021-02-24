#include <iostream>

void doubleInts1(int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] *= 2;
}

// 포인터, int *  가 아닌 배열 매개변수, int [] 를 써도 똑같이 작동한다.
// 왜냐하면 컴파일러가 배열 매개변수를 포인터로 바꿔주기 때문에.
void doubleInts(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] *= 2;
}

// 함수 프로토타입에서 배열 매개변수 대괄호 사이에 나온 숫자는 무시한다. 다음 3가지 방식은 동일하다
void doubleInts3(int*, size_t);
void doubleInts3(int[], size_t);
void doubleInts3(int[2], size_t);



// 길이를 알고 있는 스택 배열을 레퍼런스 전달방식으로 함수에 전달하는 방법
// 힙 배열에는 적용할 수 없다
void doubleIntsStack(int(&theArray)[4]); // 크기가 4인 스택 배열만 인수로 받는 함수

// 함수 템플릿을 사용하면 스택 배열의 크기를 컴파일러가 알아낼 수 있다
template<size_t N>
void doubleIntsStack2(int(&theArray)[N]) // 인수로 배열을 받으면서 사이즈 N 을 알아낼 수 있다
{
	// 알아낸 N 을 이용하여 반복 범위로 사용
	for (size_t i = 0; i < N; i++)
		theArray[i] *= 2;
}



void printArr(int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << arr[i] << "  ";
	std::cout << std::endl;
}
template <size_t N>
void printArr2(int(&arr)[N])
{
	for (size_t i = 0; i < N; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	int myIntArray[10];
	// 배열의 이름 = 배열의 주소 = 첫 번째 원소의 주소
	// 힙에 할당된 배열 뿐만 아니라
	// 스택 배열도 포인터로 접근할 수 있다.
	int* myIntPtr = myIntArray; // 스택 배열의 이름으로 배열 첫 번째 원소를 가리킬 수 있다
	
	// 포인터로 배열 접근하기
	myIntPtr[3] = 10;

	// 스택 배열을 포인터로 접근하는 기능은 배열을 함수에 넘길 때 유용하다

	// 힙 배열의 경우
	size_t arrSize = 4;
	int* heapArr = new int[arrSize] {1, 2, 3, 4}; // 동적 할당하면서 초기화할 수 있다.
	// 배열을 가리키는 포인터로 함수에 넘김
	doubleInts(heapArr, arrSize);
	printArr(heapArr, arrSize);

	delete[] heapArr;
	heapArr = nullptr;



	// 스택 배열의 경우
	int stackArr[] = { 2,4,6,8,10,12 };
	// C++17 에서부터 배열의 크기를 구하는 데 std::size() 사용
	arrSize = std::size(stackArr);
	// arrSize = sizeof(stackArr) / sizeof(stackArr[0]); C++17 이전 방식

	// 배열 이름, 배열 변수를 함수로 전달. 컴파일러가 배열에 대한 포인터로 변환해 준다
	doubleInts(stackArr, arrSize);
	printArr(stackArr, arrSize);
	
	// 배열의 첫 번째 요소의 주소를 함수로 전달.
	doubleInts(&stackArr[0], arrSize);
	printArr(&stackArr[0], arrSize);

	
	/*
	컴파일러는 배열을 함수로 전달하는 부분을 포인터로 취급한다.
	배열 문법으로 선언한 배열은 포인터로 접근할 수 있다.
	컴파일러는 함수로 전달하는 배열을 항상 포인터로 취급한다.
	*/

	
	
	// 함수 템플릿을 이용한 함수들을 이용
	doubleIntsStack2(stackArr);
	printArr2(stackArr);
}