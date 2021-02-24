#include <memory>
#include <iostream>

class Slime {
public:
	Slime(int n) : level(n) {}
	int level;
};

int main()
{
	// 레벨 30 슬라임을 가리키는 shared_ptr
	auto slimePtr = std::make_shared<Slime>(30);

	/*
	* 앨리어싱
	* slimePtr 가 가리키는 슬라임을 공유하면서
	* 그 슬라임의 레벨만 가리킨다
	* 두 shared_ptr 이 삭제되야 슬라임 객체가 해제된다
	* ( 소유한 포인터, 저장된 포인터 ) 를 인수로 shared_ptr 를 만든다
	*/
	auto levelPtr = std::shared_ptr<int>(slimePtr, &slimePtr->level);
	/*
	* slimePtr = 소유한 포인터, 레퍼런스 카운팅에 사용
	* &(slimePtr->level) = 저장된 포인터, 진짜 가리키는 메모리
	*/
	
	std::cout << *levelPtr << std::endl; // 역참조하면 저장된 포인터가 가리키는 level 을 얻을 수 있다
	std::cout << levelPtr.get() << std::endl; // get( ) 메서드를 이용하면 저장된 포인터를 얻을 수 있다

	
}