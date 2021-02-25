#pragma once
#include "Base.h"

class Derived : public Base
{
public:
	virtual void func2() override {}

	/* Derived ��ü�� vtable �� ������. �� �׸񿡴� ��ӹ��� func1 �޼���� �������̵��� func2 �޼��忡 ���� �Լ� �����Ͱ� ����Ǿ� �ִ�. 
	func1() �� �������̵����� �ʾұ⿡ �ش� �Լ� �����ʹ� Base::func1() ���� �ڵ带 ����Ų��.
	func2() �� �������̵� �߱� ������ �ش� �Լ� �����ʹ� Derived::func2() ���� �ڵ带 ����Ų��. */


	void nonVirtualFunc() {}
};