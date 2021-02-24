/*
shared_ptr 로 파일 포인터를 저장하는 예
shared_ptr 를 메모리가 아닌 다른 리소스에도 적용할 수 있다
*/

#include <fstream> // 파일 관련 타입, 함수 사용에 필요
#include <iostream>
#include <memory> // 스마트 포인터 사용

// 파일을 닫는 역할을 하는 커스텀 함수
void CloseFile(FILE* filePtr)
{
	if (filePtr == nullptr) return; // 파일이 안 열려있는 경우

	fclose(filePtr); // 파일을 닫는다
	std::cout << "File closed" << std::endl;
}

int main()
{
	FILE* f = fopen("data.txt", "w"); // 파일 하나를 연다

	/*
	* 스마트 포인터를 이용하여 파일을 가리킨다
	* 스마트 포인터 생성자에 ( 가리키고자 하는 메모리 주소, 해제하는 함수 ) 를 넣어서 커스텀 할 수 있다
	* 이 예에서는 fopen 과 fclose 를 짝 지었다
	* 스마트 포인터니까, 이제 이 파일을 닫는 일은 걱정하지 않아도 된다
	*/
	std::shared_ptr<FILE> filePtr(f, CloseFile); 

	if (filePtr == nullptr) std::cerr << "Error opening file" << std::endl;
	else std::cout << "File opened" << std::endl;

	return 0;
}