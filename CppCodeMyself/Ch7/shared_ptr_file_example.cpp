/*
shared_ptr �� ���� �����͸� �����ϴ� ��
shared_ptr �� �޸𸮰� �ƴ� �ٸ� ���ҽ����� ������ �� �ִ�
*/

#include <fstream> // ���� ���� Ÿ��, �Լ� ��뿡 �ʿ�
#include <iostream>
#include <memory> // ����Ʈ ������ ���

// ������ �ݴ� ������ �ϴ� Ŀ���� �Լ�
void CloseFile(FILE* filePtr)
{
	if (filePtr == nullptr) return; // ������ �� �����ִ� ���

	fclose(filePtr); // ������ �ݴ´�
	std::cout << "File closed" << std::endl;
}

int main()
{
	FILE* f = fopen("data.txt", "w"); // ���� �ϳ��� ����

	/*
	* ����Ʈ �����͸� �̿��Ͽ� ������ ����Ų��
	* ����Ʈ ������ �����ڿ� ( ����Ű���� �ϴ� �޸� �ּ�, �����ϴ� �Լ� ) �� �־ Ŀ���� �� �� �ִ�
	* �� �������� fopen �� fclose �� ¦ ������
	* ����Ʈ �����ʹϱ�, ���� �� ������ �ݴ� ���� �������� �ʾƵ� �ȴ�
	*/
	std::shared_ptr<FILE> filePtr(f, CloseFile); 

	if (filePtr == nullptr) std::cerr << "Error opening file" << std::endl;
	else std::cout << "File opened" << std::endl;

	return 0;
}