#include <iostream>

int main()
{
	int* myArray = new int[8];

	// ���� �� ���� �ǹ̰� ����.
	myArray[2] = 33;
	*(myArray + 2) = 33;
	/*
	������ ���� ��, �����Ͱ� ����Ű�� Ÿ���� �̿��Ѵ�.
	myArray �� int Ÿ���� ����Ű�� �����Ƿ�
	myArray+2 �� ù ��° ��� ĭ���� ���� �ι� �Ѿ��
	*/

	int* otherPtr = myArray + 3;
	// ������ ���꿡�� ������ �̿��ϸ�,
	// �� ������ ���̿� �����Ϳ� ������ Ÿ���� ���Ұ� �� �� �ִ� �� �� �� �ִ�
	std::cout << otherPtr - myArray << std::endl; // �� ������ ���̿��� int �� 3�� �����Ѵ�
}