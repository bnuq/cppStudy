#include <iostream>
#include <memory> // ����Ʈ ������ ��뿡 �ʿ�

class Slime {
public:
	Slime(int n = 10) : level(n) {}
	void print() { std::cout << level << std::endl; }
	void levelup() { level++; }
	void set(int n) { level = n; }
private:
	int level;
};

// �Ϲ� ������ �����͸� �μ��� �޴� �Լ�
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
	�������� ����Ű�� shared_ptr �� �����
	auto �� ����Ѵ�. auto == shared_ptr<Slime>
	make_shared �� ����ϴ� ���� ȿ�����̴�.
	��ü�� ����Ʈ �����ڸ� ȣ���Ѵٴ� �ǹ̷� �� ��ȣ�� ���
	*/
	auto mySlimePtr1 = std::make_shared<Slime>();
	auto mySlimePtr2 = std::make_shared<Slime>(19);
	
	// shared_ptr �� * �� -> �� �̿��Ͽ� �������� �����ϴ�.
	mySlimePtr1->print();
	(*mySlimePtr2).print();


	// C ��Ÿ�� ���� �Ҵ� �迭�� ����ų �� �ִ� // �ȵǴµ�???
	//auto mySlimePtr3 = std::make_unique<int[]>(7); // ������ ��ü�� 9���� �迭


	/*
	get( ) �޼��� ����
	���� �����Ϳ� ������ �� �ִ�
	�Ϲ� �����͸� �޴� �Լ��� ����Ʈ �����͸� �ѱ� �� �����ϴ�
	*/
	levelUpSlime(mySlimePtr1.get());
	// ������ ����Ʈ �����ʹ� ����Ű�� ��ü�� ����Ű�� �ִ�
	mySlimePtr1->print();


	/*
	reset( ) �޼��� ����
	���� ������ ����. nullptr �� �ʱ�ȭ�ȴ�
	�ʿ��ϴٸ� �Ǵٸ� ��ü�� ����ų �� �ִ�
	*/
	mySlimePtr1.reset();
	if (mySlimePtr1 == nullptr) std::cout << "Ptr1 is nullptr" << std::endl;
	
	// mySlimePtr2.reset(new int(100)); => ����. �̹� mySlimePtr2 �� Ÿ���� shared_ptr<Slime> �̴�
	mySlimePtr2.reset(new Slime(100));
	mySlimePtr2->print();


	/*
	shared_ptr �� ���۷��� ī���� ��Ŀ������ ����
	�ϳ��� ��ü�� ���� shared_ptr �� ����ų �� �ְ�
	������ shared_ptr �� ���ŵǳʰ� ���µ� �� ���ҽ��� �����ȴ�
	������ 
	*/
	auto mySlimePtr3 = std::make_shared<Slime>(30);
	auto mySlimePtr4 = mySlimePtr3; // ������ �������� �����ؼ� ����Ŵ
	auto mySlimePtr5(mySlimePtr3); // �̷��Ե� ����

	std::cout << mySlimePtr5.use_count() << std::endl; // ������ ���ҽ��� ����Ű�� ����Ʈ ������ ���� ���
	mySlimePtr3.reset();
	mySlimePtr5->print(); // ���ҽ��� ����Ű�� �� �ϳ��� �����ص� �ٸ� shared_ptr �� ����ִ�
	std::cout << mySlimePtr5.use_count() << std::endl;
	mySlimePtr4.reset();
	std::cout << mySlimePtr5.use_count() << std::endl;
	mySlimePtr5.reset();
	std::cout << mySlimePtr5.use_count() << std::endl; // ��� ����Ʈ ������ ����. 30 ������ ���ҽ��� �����ȴ�



	/*4*/
	// shared_ptr ������ �μ��� �޸𸮸� �Ҵ��ϴ� �Լ��� �����ϴ� �Լ��� �����ؼ� �־��� �� �ִ�

	std::shared_ptr<Slime> bossSlime(malloc_Slime(99), free);
	bossSlime->print();

}