#pragma once
#include "Base.h"

class Derived : public Base
{
public:
	/* �Ǽ��� override Ű���带 ������ ���
	* ���̽� Ŭ������ �ִ� �޼��带 �������̵� ���� �ʰ�, virtual �޼���� ���� �����ع��ȴ�.
	* ������, ���� override Ű����� ������ �����ؼ�
	* �����δ� Derived Ŭ������ someMethod() �޼��带 �������̵��ϰ� �ȴ�.
	*/
	virtual void someMethod(double d);
};


class otherDerived : public Base
{
public:
	/* ���̽� Ŭ���� �޼��带 �������̵� �Ϸ��µ�, 
	�Ǽ��� override Ű���嵵 ���� �ʰ� �Ű����� Ÿ�Ե� �߸� �����ٰ� ��������.
	
	���� ���̽� Ŭ������ �޼��带 �����ϰ�, �Ļ� Ŭ���� ������Ʈ�� �ؾ��� �� �̿� ���� ��Ȳ�� �߻��Ѵ�. */
	virtual void someMethod(int i);
	/* �� ���, ��ġ�ϴ� �޼��尡 ���̽� Ŭ������ �����Ƿ�, 
	otherDerived Ŭ�������� ���ο� virtual �޼��带 ������ �� �ȴ�. 
	��, ������ otherDerived Ŭ�������� �޼��尡 �ȴ�. */



	/* override Ű���带 �����ٸ� ���� ���� ��Ȳ�� �߻����� �ʾ��� ���̴�.
	override Ű���� => �� �޼���� �ݵ�� ���̽� Ŭ������ �޼��带 �������̵��Ѵٴ� ��.
	virtual void someMethod(int i) override; => ���̽� Ŭ���� �޼��忡 �̿� ��ġ�ϴ� �޼��尡 �����Ƿ� ������ ������ �߻��Ѵ�.
	*/
};