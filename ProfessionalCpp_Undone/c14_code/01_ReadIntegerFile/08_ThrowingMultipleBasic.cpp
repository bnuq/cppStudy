#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>

using namespace std;

vector<int> readIntegerFile(string_view fileName)
{
	ifstream inputStream(fileName.data());
	if (inputStream.fail()) {
		// ���� ���� ����: �ͼ����� ������.
		throw runtime_error("Unable to open the file.");
	}

	// ���Ͽ� ��� �������� �ϳ��� �о ���Ϳ� �߰��Ѵ�.
	vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}

	if (!inputStream.eof()) {
		// ���� ��(EOF)�� �������� �ʾҴ�.
		// �ٽ� ���� ������ �д� ���߿� ������ �߻��ߴ�.
		// ���� �ͼ����� ������.
		throw runtime_error("Error reading the file.");
	}

	return integers;
}

int main()
{
	const string fileName = "IntegerFile.txt";
	vector<int> myInts;

	try {
		myInts = readIntegerFile(fileName);
	} catch (const exception& e) {
		cerr << e.what() << endl;
		return 1;
	}

	for (const auto& element : myInts) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}