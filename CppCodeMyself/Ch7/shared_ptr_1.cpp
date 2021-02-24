#include <iostream>
#include <memory> // 스마트 포인터 사용에 필요

class Slime {
public:
	Slime(int n = 10) : level(n) {}
	void print() { std::cout << level << std::endl; }
	void levelup() { level++; }
	void set(int n) { level = n; }
private:
	int level;
};

// 일반 슬라임 포인터를 인수로 받는 함수
void levelUpSlime(Slime* pS)
{
	pS->levelup();
}


Slime* malloc_Slime(int l)
{
	Slime* pS = (Slime*)malloc(sizeof(Slime));
	pS->set(l);
	return pS;
}

int main()
{
	/* 
	슬라임을 가리키는 shared_ptr 를 만들기
	auto 를 사용한다. auto == shared_ptr<Slime>
	make_shared 를 사용하는 것이 효율적이다.
	객체의 디폴트 생성자를 호출한다는 의미로 빈 괄호를 사용
	*/
	auto mySlimePtr1 = std::make_shared<Slime>();
	auto mySlimePtr2 = std::make_shared<Slime>(19);
	
	// shared_ptr 도 * 와 -> 를 이용하여 역참조가 가능하다.
	mySlimePtr1->print();
	(*mySlimePtr2).print();


	// C 스타일 동적 할당 배열을 가리킬 수 있다 // 안되는데???
	//auto mySlimePtr3 = std::make_unique<int[]>(7); // 슬라임 객체가 9개인 배열


	/*
	get( ) 메서드 제공
	내부 포인터에 접근할 수 있다
	일반 포인터를 받는 함수에 스마트 포인터를 넘길 때 유용하다
	*/
	levelUpSlime(mySlimePtr1.get());
	// 여전히 스마트 포인터는 가리키던 객체를 가리키고 있다
	mySlimePtr1->print();


	/*
	reset( ) 메서드 제공
	내부 포인터 해제. nullptr 로 초기화된다
	필요하다면 또다른 객체를 가리킬 수 있다
	*/
	mySlimePtr1.reset();
	if (mySlimePtr1 == nullptr) std::cout << "Ptr1 is nullptr" << std::endl;
	
	// mySlimePtr2.reset(new int(100)); => 에러. 이미 mySlimePtr2 의 타입은 shared_ptr<Slime> 이다
	mySlimePtr2.reset(new Slime(100));
	mySlimePtr2->print();


	/*
	shared_ptr 은 레퍼런스 카운팅 메커니즘을 따라
	하나의 객체를 여러 shared_ptr 이 가리킬 수 있고
	마지막 shared_ptr 이 제거되너가 리셋될 때 리소스가 해제된다
	동일한 
	*/
	auto mySlimePtr3 = std::make_shared<Slime>(30);
	auto mySlimePtr4 = mySlimePtr3; // 동일한 슬라임을 공유해서 가리킴
	auto mySlimePtr5(mySlimePtr3); // 이렇게도 가능

	std::cout << mySlimePtr5.use_count() << std::endl; // 동일한 리소스를 가리키는 스마트 포인터 갯수 출력
	mySlimePtr3.reset();
	mySlimePtr5->print(); // 리소스를 가리키는 것 하나를 리셋해도 다른 shared_ptr 은 살아있다
	std::cout << mySlimePtr5.use_count() << std::endl;
	mySlimePtr4.reset();
	std::cout << mySlimePtr5.use_count() << std::endl;
	mySlimePtr5.reset();
	std::cout << mySlimePtr5.use_count() << std::endl; // 모든 스마트 포인터 해제. 30 슬라임 리소스가 해제된다



	/*4*/
	// shared_ptr 생성자 인수로 메모리를 할당하는 함수와 해제하는 함수를 지정해서 넣어줄 수 있다

	std::shared_ptr<Slime> bossSlime(malloc_Slime(99), free);
	bossSlime->print();

}