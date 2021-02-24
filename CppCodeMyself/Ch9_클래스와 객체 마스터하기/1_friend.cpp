#include <iostream>
using namespace std;

class Obj1; // Obj1 �̶�� �̸��� ������ Ŭ������ �����Ѵٴ� ���� �˷��� �ش�.

class Obj3
{
public:
	/*
	* Obj3 Ŭ�������� Obj1 Ŭ������ private ����� ������ ������ �޼���
	* Obj1 Ŭ���� ������ friend ������ �ϱ� ���� ���� �տ��� Ŭ���� ���ǿ� �޼��� ������ �Ͽ���.
	* 
	* �׷��� �����Ϸ��� �μ��� �޴� Obj1 �� ���ؼ� ���� ���Ѵ� => �ٽ� �տ��� Obj1 �̶�� Ŭ������ �ִٴ� ���� �˷��־�� �Ѵ�.
	* �޼��� ������ Obj1 �� private ����� �����ϴ� �� �����ϰ� ������, �����Ϸ��� Obj1 �� private ����� ���� ���Ѵ�
	* => �� �޼����� ���Ǵ� Obj1 Ŭ���� ���ǰ� ���� ������ �����ؾ� �Ѵ�.
	*/
	void processObj(const Obj1& o);

	// �ٸ� �޼���� ������ �Ұ����ϴ�.
	void otherMethod(const Obj1& o) { cout << "Obj1 �� private ����� ���� �Ұ���" /* << o.nData */ << endl; }
};


class Obj1
{
public:
	Obj1(int n = 0) : nData(n) { }

private:
	int nData;

	/* friend �� �޾Ƶ��� Ŭ������ �Լ����� �ݵ�� �����ϴ� Ŭ���� ������ �����Ѵ�. */

	/* 
	* �ٸ� Ŭ���� Obj2 ��ü�� friend �� ����
	* Obj2 Ŭ������ �ִ� ��� �޼������ Obj1 �� protected, private ����� ������ �����ϴ�.
	* �̷� ��ü�� �����Ѵ�~ �� �� �˷��ִ� ����
	* Obj2 �� Ŭ���� ���Ǹ� �ڿ��� �ص� ������.
	*/ 
	friend class Obj2; // ���� Bar_1 �� Foo �� ��� ����� ������ �����ϴ�

	/*
	* Ư�� Ŭ����( Obj3 )�� Ư�� �޼���( processObj )���� friend �� ����
	* �ش� Ŭ������ �̷��� �޼��尡 �����Ѵٴ� ���� �̸� �����Ϸ��� �˰� �־�� �Ѵ�.
	* �׷��� Obj3 Ŭ������ ���ǿ� �޼��� ������ �տ� �����ؾ� �Ѵ�.
	*/
	friend void Obj3::processObj(const Obj1& o); // �޼����� ������Ÿ���� �̿�

	/*
	* standalone �Լ��� friend �� ����. �Ϲ� �Լ������� Obj1 ����� ������ �����ϴ�
	* �ռ� Ŭ���� ����ó��, friend ���� ��ü�� �Լ� ������Ÿ�� ������ �Ѵ�.
	* �ٸ� ������ �� �� �Լ��� ������ �ʿ䰡 ����.
	*/
	friend void dumpObj(const Obj1& f);
};


void Obj3::processObj(const Obj1& o)
{
	std::cout << "Obj1 �� private ��� ���� " << o.nData << std::endl;
}


class Obj2
{
public:
	// Obj2 Ŭ�������� Obj1 Ŭ������ private ����� ������ �����ϴ�
	// �޼��带 ������ �� friend �� ���� �ʴ´�.
	void print(const Obj1& f) { std::cout << "Obj1 �� private ��� ���� " << f.nData << std::endl; }
};


// �Լ��� ������ �� friend �� ���� �ʴ´�. 
void dumpObj(const Obj1& o)
{
	std::cout << "Obj1 �� private ��� ���� " << o.nData << std::endl;
}

int main()
{
	Obj1 sampleObj1(100);

	Obj2 sampleObj2;
	Obj3 sampleObj3;

	sampleObj2.print(sampleObj1);
	sampleObj3.processObj(sampleObj1);

	dumpObj(sampleObj1);
}