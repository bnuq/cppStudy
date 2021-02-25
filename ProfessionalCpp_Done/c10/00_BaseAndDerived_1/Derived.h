#pragma once
#include "Base.h"

/* �� Ŭ������ �ٸ� Ŭ������ Ȯ���� ���̶�� �����ؾ� �Ѵ�, �˷��� �Ѵ�.
* Derived Ŭ������ Base Ŭ������ ����Ѵ�, Base Ŭ������ ���� �޴´ٰ� �˸�.
* Derived class = Base class �� �Ļ� Ŭ����, ���� Ŭ������. */
class Derived : public Base 
{
public:
	// ��� �޼��带 virtual �� �����ϴ� ���� �ٶ����ϴ�.

	/*
	override Ű����. �Ļ� Ŭ�������� ���̽� Ŭ������ �޼��� ������ �ٲٷ� �Ҷ�, �������̵��� �� ���
	���̽� Ŭ���� �޼����� ������ �Ȱ��� ���� override Ű���带 �ٿ� ������ �Ļ� Ŭ�������� �����Ѵٴ� ���� �˸���.
	*/
	virtual void someMethod() override; // override Ű���尡 �ʼ��� �ƴϴ�.
/*	void someMethod() override;  �޼��峪 �Ҹ��ڸ� virtual �� �����ϸ� �Ļ�Ŭ���������� virtual ���°� �����ȴ�.
	�� someMethod() �޼��� ���� �ÿ� virtual �� ���� �ʾƵ� ������ virtual �� ������ ���̳� ���������� ���´�. */


	virtual void someOtherMethod();
};

/* �Ļ� Ŭ������ �θ� Ŭ������ public, protected �� ��� �޼���, ������ ����� �ڽ��� Ŭ�������� ������ ��ó�� ����� �� �ִ�. */








// Base �� ��ӹ��� Derived �� ��ӹ޴� DerivedDerived Ŭ����
class DerivedDerived : public Derived
{

};

// Base �� ��ӹ޴� �Ǵٸ� Ŭ���� Derived2
class Derived2 : public Base
{

};