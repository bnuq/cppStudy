#include <iostream>

void doubleInts1(int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] *= 2;
}

// ������, int *  �� �ƴ� �迭 �Ű�����, int [] �� �ᵵ �Ȱ��� �۵��Ѵ�.
// �ֳ��ϸ� �����Ϸ��� �迭 �Ű������� �����ͷ� �ٲ��ֱ� ������.
void doubleInts(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] *= 2;
}

// �Լ� ������Ÿ�Կ��� �迭 �Ű����� ���ȣ ���̿� ���� ���ڴ� �����Ѵ�. ���� 3���� ����� �����ϴ�
void doubleInts3(int*, size_t);
void doubleInts3(int[], size_t);
void doubleInts3(int[2], size_t);



// ���̸� �˰� �ִ� ���� �迭�� ���۷��� ���޹������ �Լ��� �����ϴ� ���
// �� �迭���� ������ �� ����
void doubleIntsStack(int(&theArray)[4]); // ũ�Ⱑ 4�� ���� �迭�� �μ��� �޴� �Լ�

// �Լ� ���ø��� ����ϸ� ���� �迭�� ũ�⸦ �����Ϸ��� �˾Ƴ� �� �ִ�
template<size_t N>
void doubleIntsStack2(int(&theArray)[N]) // �μ��� �迭�� �����鼭 ������ N �� �˾Ƴ� �� �ִ�
{
	// �˾Ƴ� N �� �̿��Ͽ� �ݺ� ������ ���
	for (size_t i = 0; i < N; i++)
		theArray[i] *= 2;
}



void printArr(int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << arr[i] << "  ";
	std::cout << std::endl;
}
template <size_t N>
void printArr2(int(&arr)[N])
{
	for (size_t i = 0; i < N; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	int myIntArray[10];
	// �迭�� �̸� = �迭�� �ּ� = ù ��° ������ �ּ�
	// ���� �Ҵ�� �迭 �Ӹ� �ƴ϶�
	// ���� �迭�� �����ͷ� ������ �� �ִ�.
	int* myIntPtr = myIntArray; // ���� �迭�� �̸����� �迭 ù ��° ���Ҹ� ����ų �� �ִ�
	
	// �����ͷ� �迭 �����ϱ�
	myIntPtr[3] = 10;

	// ���� �迭�� �����ͷ� �����ϴ� ����� �迭�� �Լ��� �ѱ� �� �����ϴ�

	// �� �迭�� ���
	size_t arrSize = 4;
	int* heapArr = new int[arrSize] {1, 2, 3, 4}; // ���� �Ҵ��ϸ鼭 �ʱ�ȭ�� �� �ִ�.
	// �迭�� ����Ű�� �����ͷ� �Լ��� �ѱ�
	doubleInts(heapArr, arrSize);
	printArr(heapArr, arrSize);

	delete[] heapArr;
	heapArr = nullptr;



	// ���� �迭�� ���
	int stackArr[] = { 2,4,6,8,10,12 };
	// C++17 �������� �迭�� ũ�⸦ ���ϴ� �� std::size() ���
	arrSize = std::size(stackArr);
	// arrSize = sizeof(stackArr) / sizeof(stackArr[0]); C++17 ���� ���

	// �迭 �̸�, �迭 ������ �Լ��� ����. �����Ϸ��� �迭�� ���� �����ͷ� ��ȯ�� �ش�
	doubleInts(stackArr, arrSize);
	printArr(stackArr, arrSize);
	
	// �迭�� ù ��° ����� �ּҸ� �Լ��� ����.
	doubleInts(&stackArr[0], arrSize);
	printArr(&stackArr[0], arrSize);

	
	/*
	�����Ϸ��� �迭�� �Լ��� �����ϴ� �κ��� �����ͷ� ����Ѵ�.
	�迭 �������� ������ �迭�� �����ͷ� ������ �� �ִ�.
	�����Ϸ��� �Լ��� �����ϴ� �迭�� �׻� �����ͷ� ����Ѵ�.
	*/

	
	
	// �Լ� ���ø��� �̿��� �Լ����� �̿�
	doubleIntsStack2(stackArr);
	printArr2(stackArr);
}