#pragma once
#include "Base.h"

/* �� Ŭ������ �ٸ� Ŭ������ Ȯ���� ���̶�� �����ؾ� �Ѵ�, �˷��� �Ѵ�.
* Derived Ŭ������ Base Ŭ������ ����Ѵ�, Base Ŭ������ ���� �޴´ٰ� �˸�.
* Derived class = Base class �� �Ļ� Ŭ����, ���� Ŭ������. */
class Derived : public Base 
{
public:
	void someOtherMethod() { }
};

// Base �� ��ӹ��� Derived �� ��ӹ޴� DerivedDerived Ŭ����
class DerivedDerived : public Derived
{

};

// Base �� ��ӹ޴� �Ǵٸ� Ŭ���� Derived2
class Derived2 : public Base
{

};