#pragma once

class Base
{
public:
	/*
	virtual 키워드. 메서드를 선언할 때 가장 앞에 적는다.
	virtual 키워드로 선언된 메서드만 파생 클래스에서 오버라이드 할 수 있다.
	일반적으로 모든 메서드를 virtual 로 선언하는 것이 좋다.
	*/
	virtual void someMethod(); // 파생 클래스에서 이 someMethod() 메서드를 오버라이드 할 수 있게 허용한다는 뜻 => 메서드 오버라이딩

	virtual void anotherMethod(double d);
protected:
	int mProtectedInt;
private:
	int mPrivateInt;
};


// 클래스를 정의할 때 사용하는 final 키워드
class otherBase final // 다른 클래스가 이 클래스를 상속할 수 없다. 이 클래스 밑으로 파생 클래스가 발생하지 않는다.
{

};

/*
class otherDerived : public otherBase  => 에러. final 선언된 클래스를 상속할 수 없다.
{

};
*/