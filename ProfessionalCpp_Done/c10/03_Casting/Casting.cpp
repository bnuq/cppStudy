#include <iostream>
using namespace std;

class Base
{
public:
	virtual void someMethod() { cout << "Base 버전 메서드" << endl; }
};

class Derived : public Base
{
public:
	virtual void someMethod() { cout << "Derived 버전 메서드" << endl; }
};





int main()
{
	Derived derivedObj;


	/* 자식 클래스 객체를
	부모 클래스 타입으로 캐스팅하거나
	부모 클래스 객체에 대입할 수 있다.
	이 두 가지 경우, 자식 클래스만의 특성이 사라지는 슬라이싱이 발생한다. */
	Base baseObj = derivedObj;

	baseObj.someMethod(); // 슬라이싱 발생, Base 버전 메서드 호출




	/* 파생 클래스 객체를
	베이스 클래스 타입의 포인터나 레퍼런스로 가리킬 수 있다.
	그리고 이경우엔 슬라이싱이 발생하지 않는다. */
	Base& baseRef = derivedObj; // 베이스 클래스 타입으로 파생 클래스 참조 = 업캐스팅

	baseRef.someMethod(); // 슬라이싱 발생안함, Derived 버전 메서드 호출



	/* 반대로 베이스 클래스를 파생 클래스로 캐스팅하는 것 = 다운 캐스팅 
	디자인이 잘못 됐다. */
	Derived* derivedPtr = static_cast<Derived*>(&baseObj); // &baseObj 는 Base 타입 포인터 값인데, 이를 Derived 타입 포인터 값으로 강제 형변환

	
	/* 다운 캐스팅이 필요한 경우, dynamic_cast() 를 사용 => 잘못된 캐스팅의 경우 처리하지 않는다.
	dynamic_cast() 는 vtable 이 있는 객체에만 사용가능하다.
	실패시 포인터의 경우 값이 nullptr, 객체 레퍼런스의 경우 std::bad_cast 익셉션을 발생시킨다. */
	Derived* downCasting = dynamic_cast<Derived*>(&baseObj);
	if (downCasting == nullptr) {}

}







