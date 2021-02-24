#include <iostream>

/*
���� = �޸� �� ĭ
�� ���ڿ� �پ��ִ� ���̺�, ��, �̸�ǥ = ���� �̸�
���ھȿ� ��� �ִ� ������ = ������ ����� ��
*/

void exer1_1()
{
	// automatic variable, stack �� ����
	int i = 7;

	// ptr ������ ���ÿ� ����
	int* ptr = nullptr; // �׻� �����͸� nullptr �̳� ������ �����͸� ����Ű���� �ʱ�ȭ�Ѵ�
	// new Ű���带 �̿��ϸ� �� �޸𸮰� �Ҵ�ȴ�. ���� �޸𸮴� �׻� ���� �Ҵ�
	ptr = new int; // �� �Ҵ�� �޸𸮸� �����Ͱ� ����Ų��
	
	// ���� ������ �� �ٷ� ǥ��
	int* ptr2 = new int;

	// handle �� ���ÿ� ����
	int** handle = nullptr; // int* �� ����Ű�� handle. int* �� ������, �ּҸ� �����Ѵ�.
	// �����Ҵ��� �޸𸮴� ��� ���� ����
	handle = new int*; // int* �� ������ �� �ִ� �޸𸮸� �Ҵ��ϰ� �� �����͸� handle �� ����
	*handle = new int; // int �� ������ �� �ִ� �޸𸮸� �Ҵ��ϰ� �� �����͸� handle �� ����Ű�� �޸𸮿� ����

}
//============================================================================//

void leaky()
{
	new int; // int �� ���� ������ŭ�� �Ҵ��ϰ�, �Ҵ�� �޸𸮿� ���� �����͸� �Ҿ� ����
	std::cout << "��� int �ϳ��� �Ҿ���ȴ�." << std::endl;
}

class Foo {
};

void exer1_2()
{
	int* ptr = new int;
	// �Ҵ��� �޸��� �����͸� delete ����� �޸𸮰� �����ȴ�
	delete ptr;
	ptr = nullptr; // �����. nullptr �� �ٽ� �ʱ�ȭ

	/*
	malloc �Լ� => �μ��� ������ ����Ʈ ����ŭ �޸𸮸� �Ҵ�
	�Ҵ� �� � Ÿ���� ����Ű�� ������ ������ ��������� ����
	*/
	Foo* myFoo = (Foo*)malloc(sizeof(Foo));
	free(myFoo);
	/*
	new �� �޸� �Ҵ� + ��ü���� ����� �ش�
	�⺻ �����ڸ� ȣ���Ѵٴ� �ǹ̿��� ���ȣ�� ��������� ǥ��
	*/
	Foo* myOtherFoo = new Foo();
	// delete �� �Ҹ��� ȣ��, ��ü�� ���������� �����Ѵ�
	delete myOtherFoo;

	/*
	�⺻������ new �� �޸� �Ҵ��� �����ϸ� ���α׷��� ����ȴ�
	�ͼ����� �߻�
	*/
	// �ͼ����� �߻���Ű�� �ʴ� new. nullptr �� �����Ѵ�
	int* ptr2 = new(std::nothrow) int;
}
//============================================================================//

void exer1_3()
{
	/*
	int �� ������ �� �ִ� 5���� ���ӵ� ������ ���ÿ� �Ҵ�
	���ÿ� �����ϴ� �迭�� ũ��� ������ �ð��� �����Ǿ�� �Ѵ� => ������̿��� �Ѵ�
	*/
	int myArray[5];
	/*
	int �� ������ �� �ִ� 5���� ���ӵ� ������ �� �޸𸮿� �Ҵ�
	�� ������ ����Ű�� �����͸� ������ ����
	*/
	int* myArrayPtr = new int[5];
	// new[] �� delete[] �� �޸� ������ �Ѵ�
	delete[] myArrayPtr;
	myArrayPtr = nullptr;
}

// �迭�� ���� �Ҵ��ϸ� ���� �ð��� �迭�� ũ�⸦ ���� �� �ִ�
// �迭 ��ü�� �� �� �Ҵ��ϸ� ũ�⸦ �ٲ� �� ����
int* createIntArray(int n)
{
	size_t numInts = n;
	int* intArr = new int[n];
	return intArr; // �̶� intArr = �������� �Ҵ�� �迭, dynamically allocated array.
}

class Sample
{
public:
	Sample() { std::cout << "Constructor" << std::endl; } // ����Ʈ ������
	~Sample() { std::cout << "Destructor" << std::endl; }
};

void exer1_3_2()
{
	/*
	new[N] �� �̿��Ͽ� ��ü�� ��� N���� ����� ���ӵ� ������ �Ҵ�
	new[ ] �� ȣ���ϸ� �� ��ü���� ����Ʈ ������, ���� �μ� �����ڰ� ȣ��ȴ�
	�� ����Ʈ �����ڰ� ������ ��ü�迭�� �� �����
	*/
	Sample* mySampleArray = new Sample[4]; // ����Ʈ �����ڰ� 4 �� ȣ��ȴ�
	delete[] mySampleArray; // �� ���� ��ü���� �Ҹ��ڸ� ȣ��. �� 4 �� ȣ��ȴ�
	mySampleArray = nullptr;

	// ������ �迭�� ���ؼ��� �� ���Ұ� ����Ű�� ��ü�� ������ �����ؾ� �Ѵ�
	const size_t size = 4;
	Sample** mySamplePtrArray = new Sample * [size];
	// �� ������ ���� ��ü�� �Ҵ�
	for (size_t i = 0; i < size; i++) { mySamplePtrArray[i] = new Sample(); }
	// �� �����Ͱ� ����Ű�� �Ҵ�� ��ü�� �����Ѵ�
	for (size_t i = 0; i < size; i++) { delete mySamplePtrArray[i]; }
	// �迭�� �����Ѵ�
	delete[] mySamplePtrArray; // new[ ] �� �����ϴ� delete[ ]
	mySamplePtrArray = nullptr;
}

char** allocateCharacterBoard(size_t xDimension, size_t yDimension)
{
	char** myArray = new char* [xDimension];
	
	for (size_t i = 0; i < xDimension; i++)
	{
		myArray[i] = new char[yDimension];
	}
	return myArray;
}
void releaseCharacterBoard(char** myArray, size_t xDimension)
{
	for (size_t i = 0; i < xDimension; i++)
	{
		delete[] myArray[i];
	}
	delete[] myArray;
}

int main()
{
	int* ptr = new(std::nothrow) int(8);
	std::cout << *ptr << std::endl;
	delete ptr;
}