#include <initializer_list> // std::initializer_list<T> ���ø��� ���
#include <stdexcept> // ���ܸ� ������ ���� �ʿ�
#include <vector>
#include <iostream>

using namespace std;


/*
¦�� ���� ���Ҹ� ���� initializer_list<T> �� �Ű������� �޴� Ŭ����
¦�� ���� �ƴϸ� ���ܸ� ������
*/
class EvenSequence
{
public:
	/*
	�̴ϼȶ����� ����Ʈ ������
	ù ��° �Ű������� initializer_list<T> �� �ް�
	�ٸ� �Ű������� ���ų� ����Ʈ ���� ����
	*/
	EvenSequence(initializer_list<double> args)
	{
		// size( ) �޼���, initializer_list<T> �� ������ ������ �˾Ƴ� �� �ִ�.
		if (args.size() % 2 != 0)
			throw invalid_argument("������ ������ ¦������ �ƴϴ�");
		/*
		* 
		// vector �� reserve( ) �޼���, ������ ������ �̸� �����Ѵ�.
		mSequence.reserve(args.size());
		// ���� ��� for ������ initializer_list<T> �� �� ���ҿ� ������ �� �ִ�
		for (const auto& value : args)
			mSequence.push_back(value);

		*/


		/*
		���� ������ �����ϰ�, �� ���ҿ� �����Ͽ� �����ϴ� ������ 
		vector �� assign( ) �޼���� �ѹ��� ���� �� �ִ�.
		*/
		mSequence.assign(args); // initializer_lsit<T> �� �μ��� �ٷ� �ִ´�.	
		

	}

	void dump() const
	{
		// vector �� �� ���ҵ鵵 ���� ��� for ������ ���� �����ϴ�
		for (const auto& value : mSequence)
			cout << value << ", ";
		cout << endl;
	}

private:
	vector<double> mSequence; // �μ��� ���� ������ ����
};


int main()
{
	// �߰�ȣ�� ���� �ִ� ����? �迭? �� initializer_list<T> ��.
	EvenSequence seq1 = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	seq1.dump();
	

	// ��·�� �����ڴϱ�, ��ȣ ��ȣ ���� ��ü ���� �ٷ� �μ��� �� ���� �ִ�.
	EvenSequence seq2{ 11.0, 12.0, 13.0, 14.0, 15.0, 16.0 };
	// EvenSequence seq2({ 11.0, 12.0, 13.0, 14.0, 15.0, 16.0 });
	seq2.dump();


	try {
		EvenSequence seq3 = { 7.0, 8.0, 9.0 };
		seq3.dump();
	}
	// invalid_argument ���ܰ� �߻��Ѵٸ� const ���۷����� �޾�
	catch (const invalid_argument& e) {
		cout << e.what() << endl; // what( ) �޼���, ������ ���ڿ��� �����Ѵ�.
	}



	/* ǥ�� ���̺귯���� ���� Ŭ������ ��� '�̴ϼȶ����� ����Ʈ ������' �� �����Ѵ� */
	vector<string> myVec{ "apple", "samsung" };
}