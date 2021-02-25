#pragma once

class Base
{
public:
	/*
	virtual Ű����. �޼��带 ������ �� ���� �տ� ���´�.
	virtual Ű����� ����� �޼��常 �Ļ� Ŭ�������� �������̵� �� �� �ִ�.
	�Ϲ������� ��� �޼��带 virtual �� �����ϴ� ���� ����.
	*/
	virtual void someMethod(); // �Ļ� Ŭ�������� �� someMethod() �޼��带 �������̵� �� �� �ְ� ����Ѵٴ� �� => �޼��� �������̵�

	virtual void anotherMethod(double d);
protected:
	int mProtectedInt;
private:
	int mPrivateInt;
};


// Ŭ������ ������ �� ����ϴ� final Ű����
class otherBase final // �ٸ� Ŭ������ �� Ŭ������ ����� �� ����. �� Ŭ���� ������ �Ļ� Ŭ������ �߻����� �ʴ´�.
{

};

/*
class otherDerived : public otherBase  => ����. final ����� Ŭ������ ����� �� ����.
{

};
*/