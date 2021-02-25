#pragma once

class Base
{
public:
	virtual void someMethod(double d);

	void go(); // virtual 로 선언되지 않는 메서드
};