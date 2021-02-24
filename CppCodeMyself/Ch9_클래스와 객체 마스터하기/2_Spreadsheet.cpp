#include <iostream>
#include <string>
#include <vector>

#include "2_Spreadsheet.h"

using namespace std;

// ������
Spreadsheet::Spreadsheet(size_t width, size_t height)
	: mWidth(width), mHeight(height) // ������ ��� �޸𸮸� Ȯ���ϸ鼭 �ʱ�ȭ
{
	cout << "�Ϲ� �μ��� �޴� ������ ȣ��" << endl;

	// �����ڿ��� ��ü�� �����ϸ鼭, ��ü�� �ʿ��� �޸𸮸� ���� �Ҵ��Ѵ�.

	mCells = new SpreadsheetCell * [mWidth]; 
	/* mCells �� ��ü ������ ����Ų��.
	* ��ü ������ SpreadsheetCell �ּҵ��� ����.
	* �� SpreadsheetCell �ּҵ��� ������ SpreadsheetCell �迭�� ����Ų��.
	*/

	for (size_t i = 0; i < mWidth; i++) { // ��ü �迭���� �� ��ҿ� ����
		mCells[i] = new SpreadsheetCell[mHeight]; // �� ��Ҵ� ������ SpreadsheetCell �迭�� �Ҵ���, ����Ų��.
	}
}



// �Ҹ���
Spreadsheet::~Spreadsheet() // ��ü�� �Ҹ��� �� �Ҹ��� ȣ��, �����ڿ��� ���� �Ҵ��� �޸𸮸� �����Ѵ�
{
	cout << "�Ҹ��� ȣ��" << endl;

	// ���� mCells �� �� ���ҵ��� ����Ű�� �ִ� SpreadsheetCell �迭�� �����ؾ� �Ѵ�
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}

	// �� ��ҵ��� �����ߴٸ� ��ü �迭�� �����Ѵ�
	delete[] mCells;
	mCells = nullptr; // ������ �����ʹ� nullptr �� ����Ű�� ���� �����ϴ�.
}



// ���� ������
/* �����Ϸ����� ���� �����ڸ� ����ϸ�
* ������ Ÿ�Կ� ���ؼ�, ���� ����, ��Ʈ ���� ������ ����.
* ���� ���簡 �ƴ� ���� ����� ����Ű�� �Ǵ� ������ �߻��Ѵ�.
* �׷��� ���� ���縦 �ϵ��� ������ �Ѵ�.
*/
Spreadsheet::Spreadsheet(const Spreadsheet& src)
	: Spreadsheet(src.mWidth, src.mHeight) // ���� �����ڸ� �̿�. src �� ������ ����� �̿��Ͽ� �ϴ� �޸𸮸� �����Ҵ��Ѵ�.
{
	cout << "���� ������ ȣ��" << endl;

	// ���� ���� ���� ����
	// ���� ������ ���п�, this->mCells �� �ʱ�ȭ���� �ʰ� �׳� ������� �ִ� ����.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j]; // SpreadsheetCell �� ���� �����ڸ� �̿��Ͽ�, ���� �ϳ��� �����Ѵ�.
		}
	}
}



// ���� ������
/*
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	// ���� �����ڴ� �ڱ� �ڽ��� �����ϴ� ��Ȳ�� ���� ���� üũ�Ѵ�.
	if (this == &rhs) return *this; // ������ ������ �ƴϰ� ���۷��� ����


	* ���� �����ڴ� �̹� ������� ��ü�� �ٸ� ��ü ���� �����ϴ� ���̹Ƿ�
	* ���� ��ü�� �ִ� ������ ����� ����� ������ �ʿ��ϴ�.
	*
	// ���� �޸� ����
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;


	// ���ο� �޸� �Ҵ�
	mWidth = rhs.mWidth;
	mHeight = rhs.mHeight;

	mCells = new SpreadsheetCell* [mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}


	// �����͸� �����Ѵ�
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = rhs.mCells[i][j]; // SpreadsheetCell �� ���� �����ڸ� �̿��Ͽ�, ���� �ϳ��� �����Ѵ�.
		}
	}


	return *this;

������ = �ϴ����� ���Ƽ� ������ ���� ���Ⱑ ũ��. ���� ��� �ͼ����� �߻��ϴ� ���, ������ �ǳʶپ� ������.
}
*/
/* ���������� ó���� �ϰų�, 
* �ͼ����� �߰��� �߻��ϴ� ��� this ��ü�� �ǵ帮�� �ʰ� �ϰ� �ʹ�. �׷��� ��ü�� ���������� ���°� ���� �ʴ´�.
* `���� �� �¹ٲٱ�` ������ �̿��Ͽ�, ���� �����ڸ� ������.
*/
void swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
	// ������ ������ ����� ��ü�ϴ� �ۿ��� <utility> ���� �����ϴ� std::swap �Լ��� �̿��Ѵ�.

	using std::swap; // ���⼭ ���� �׳� swap �� std::swap �� ���Ѵٴ� ��.

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells); // �� �����Ͱ� ����Ű�� �ּҰ��� ��ȯ���ش�.
}


// ���� �� �¹ٲٱ� ������ ������ ���� ������
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	cout << "���� ���� ������ ȣ��" << endl;

	// ���� �����ڴ� �׻� ���� �ڱ� �ڽ��� �����ϴ� �� Ȯ��
	if (this == &rhs) return *this;

	// �����ϴ� �������� � �ͼ����� �߻��� �� ������ �ӽ� �ν��Ͻ��� �켱 ���ڸ� �����Ѵ�.
	Spreadsheet temp(rhs); // ���� �����ڸ� �̿��ؼ� temp ��ü�� rhs ��ü �� ����
	
	// �ӽ� ��ü�� �����ϴ� ������ �ƹ� ������ �����ٸ�, ���� ��ü�� �ӽ� ��ü�� ������ ����� ��ü. 
	// �����ϰ��� �ϴ� ��ü�� ���� ����� ����, �ƹ� ���� ���� �� ��������ٸ� ������ü�� ����������� ����Ű�� �Ѵ�?
	swap(*this, temp); // swap �Լ��� noexcept �̹Ƿ� �ͼ����� �߻����� �ʴ´�.
	return *this;
}



// �̵� ������ => ��ü�� �������� �ʰ� �̵���Ų��...
/*
Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept // �ͼ����� �߻���Ű�� �ʴ´�.
{
	* ������ �̴ϼȶ������� �����ϱ�...
	�⺻ Ÿ�� ��� ������ �׳� ����⸸ �ϰ� �ʱ�ȭ�� ���Ѵ�.
	��ü ��� �������� ����Ʈ �����ڸ� ȣ���Ѵ�. ~ �� ��ü�� ����Ʈ �����ڰ� �����Ѵٸ�.
	�̷ν� �ϴ� ��ü�� ����� ����.
	*
	std::cout << "�̵� ������ ȣ��" << std::endl;
	moveFrom(src); // ���� moveFrom ���� �޼��带 �̿�, src �� ������ �������� �������� src �� �� ��ü�� ����� ������.
}
*/
/*
* ������ ����� �����ϴ� �޼��尡 swap() �� moveFrom() 2����.
* ���� ������ ����� �߰��ϰų� �����Ѵٸ� 2���� �Լ��� ��� �����ؾ� �Ѵ� => ���ŷӴ�.
* �ϳ��� ����ϴ� ���� �����ϹǷ�, �̵� �����ڿ� �̵� ���� �����ڸ� ��� swap() �޼��常 �̿��Ͽ� ��������.
*/
// swap �� �̿��� �̵� ������
Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept
	: Spreadsheet() // ���� ������, ����Ʈ �����ڸ� �̿��� ���� ��ü�� �����.
{
	cout << "�̵� ������ ȣ��" << endl;

	swap(*this, src); // src �� *this ��ü�� �����͸� ��ȯ. src �� �������̶� ���� ����� ���̴�.
}




// �̵� ���� ������
/*
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{
	// ���� �����ڴ� �׻� �ڱ� �ڽ��� �����ϴ� �������� ���� Ȯ���Ѵ�.
	if (this == &rhs) return *this;

	cleanup(); // *this �� ������ �ִ� ���� �޸𸮸� ����. *this ��ü�� �� ��ü���� ����� ������.

	moveFrom(rhs); // rhs �� ���� �����͸� �������� rhs �� �� ��ü�� ��������

	return *this;
}
*/
// swap �� �̿��� �̵� ���� ������
// ���� ���� �� �¹ٲٱ� ������ �̿�
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{
	cout << "�̵� ���� ������ ȣ��" << endl;

	// rhs �� ������ ���۷��� �̹Ƿ�, rhs ��ü�� �ӽ� �ν��Ͻ��� ���� ������ �Ϸ� �Ѵٸ� �̵� �����ڸ� �̿��ϴ� ���� ȿ�����̴�.
	Spreadsheet temp(std::move(rhs)); // std::move() �� �̿��� rhs �� ���������� ����

	swap(*this, temp); // ������ �ӽ� �ν��Ͻ��� *this ��ü�� ��ȯ
	return *this;
}

// �޼���
void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell) // ���� ���� ���� �Լ�
{
//	if (!inRange(x, mWidth) || !inRange(y, mHeight)) throw out_of_range(""); // �����ϴ� ��ǥ���� ������ �����, out_of_range ���ܸ� ������
	/* �̿� ���� �ڵ� �ߺ��� �Ͼ�� �ʰ� �ڵ带 ¥�� �Ѵ�. */
	
	verifyCoordinate(x, y); // ���⼭ �ͼ����� �߻����� ������ ���� �������� �̵�
	// �ߺ��Ǵ� �۾��� �ش� �۾��� �ϴ� �޼��带 ȣ���ؼ� �ذ�

	mCells[x][y] = cell; // cell �� ���� ����� SpreadsheetCell
	/* SpreadsheetCell ���� ���� �����ڸ� �̿��Ͽ� ��ü�� �ִ� ���� �����ؿ´�. */
}
SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
//	if (!inRange(x, mWidth) || !inRange(y, mHeight)) throw out_of_range(""); 

	verifyCoordinate(x, y); // ���⼭ �ͼ����� �߻����� ������ ���� �������� �̵�
	// �ߺ��Ǵ� �۾��� �ش� �۾��� �ϴ� �޼��带 ȣ���ؼ� �ذ�

	return mCells[x][y]; // �ش� ��ǥ�� �ִ� SpreadsheetCell ���۷����� �����Ѵ�. => ������ �� �ְ�.
}



// ���� �޼���
void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
	if ((x >= mWidth) || (y >= mHeight)) throw std::out_of_range(""); // x �� y �� �迭�� �����ϴ� index ���̴ϱ�, ��ü ������ ���� ���� ������ �ȵȴ�.
}


void Spreadsheet::cleanup() noexcept
{
	for (size_t i = 0; i < mWidth; i++)
		delete[] mCells[i]; // mCells �� �� ���ҵ��� ����Ű�� SpreadsheetCell �迭�� ����

	delete[] mCells; // SpreadsheetCell* �迭�� ����
	mCells = nullptr;
	mWidth = mHeight = 0; // mCells ��ü�� �����Ǿ����Ƿ�, �ʺ�� ���̵� 0 ������ �����.
}


void Spreadsheet::moveFrom(Spreadsheet& src) noexcept // src ��ü�� �����͸� *this ��ü�� �ѱ�� �Լ�
{
	// �����Ϳ� ���� ���� ����, �������� *this ��ü�� �ѱ��
	// �Ʒ� 3 ��� ������ ���, �⺻Ÿ���̱� ������ ���� ����, ������ ���� �̵���.
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	mCells = src.mCells; // this->mCells �� src ��ü�� mCells �� ����Ű�� �迭�� ����Ű���� �Ѵ�. ���� �ּҸ� ����.


	// ��ü ������ ����� ��� std::move() �� �̿��Ͽ� �̵����Ѿ� �Ѵ�.
	// std::string mName �̶�� ������ ����� �ִٸ�, std::move( ) �� �̿��Ͽ� �̵���Ų��.
	mName = std::move(src.mName);


	// ������ �������� *this �� �Ѿ���Ƿ� src �� �����͸� ����, src �� �����ؾ� �Ѵ�.
	src.mWidth = 0;
	src.mHeight = 0;
	src.mCells = nullptr;
	// src.mName �� �ʱ�ȭ�ϴ� ������ ����???



	/* src ��ü�� mCells �� ����Ű�� �迭�� *this ��ü�� mCells �� ���� ����Ű�� ������
	src �� mCells �� �ƹ��͵� ����Ű�� �ʵ���, nullptr �� �����Ѵ�.
	�׷��� src �� �Ҹ��ڰ� ȣ��� ��, ������ src �� ������ �ִ� mCells �� �������� �ʰ� �ȴ�.
	*/
}





Spreadsheet createObject()
{
	return Spreadsheet(2, 3);
}









int main()
{
	Spreadsheet finalScore(1,1);

	finalScore.setCellAt(0, 0, SpreadsheetCell(3.3));

	Spreadsheet test(std::move(finalScore));
	std::cout << (test.getCellAt(0, 0)).getValue() << std::endl;


	vector<Spreadsheet> vec;
	for (int i = 0; i < 2; i++) {
		cout << "Iteration " << i << endl;
		vec.push_back(Spreadsheet(100, 100)); 
		/*
		* Spreadsheet ������ �̿� �ؼ� Spreadsheet(100,100) �ӽ� ��ü�� �����
		* �̵� �����ڸ� �̿��Ͽ� vector �� ��ݸ��� �ӽ� ��ü�� �̵���Ų��.
		* 
		* vector �� ũ�Ⱑ �������Ǵ� ���, ������ vector ���� ���ο� vector �� ��ü�� �̵����Ѿ� �Ѵ�.
		* �׷��� �� ��쿡�� �̵� �����ڰ� ȣ��ȴ�.		
		*/
		cout << endl;
	}

	
	Spreadsheet s(2, 3);

	// createObject() �Լ��� ������� ���� ��, �ӽ� ��ü�� �̵� ���� �����ڰ� `������ ���۷���`�� �޾�
	// ������ ���۷����� �������� �ӽ� ����� �޴� �ӽ� ��ü�� ���� �����ڸ� �̿��ؼ� ������ ���� �Ŵ�.
	// �ٵ� ������ ���۷����� �̿��ϴ� �̵� ���� �����ڰ� �����ϱ�, �Լ� ���� ���� �׳� �״�� ���������� �̿�.
	s = createObject(); // �̵� ���� �����ڸ� �̿��ؼ�, s �� �Լ� ���� ���� ����
	// �̵� ���� ������ ������, �̵� �����ڸ� ȣ��


	Spreadsheet s2(5, 6);
	s2 = s; // ���� ���� ������ �̿�, �ٸ� ��ü�� �� ����.
	// ���� ���� ������ ������, ���� �����ڸ� ȣ��
	// �׸��� ���� �����ڴ� �Ϲ� �����ڸ� ȣ��

	Spreadsheet s3 = createObject(); // �̵� �����ڸ� �̿�. �Լ� ���� ���� �̿��ؼ� ���ο� ��ü ����
	
}

/* �̵� �ǹ̷��� �������� ������,
�̵� �����ڿ� �̵� ���� �����ڸ� ȣ���ϴ� �κ���
��� ���� �����ڿ� ���� ���� �����ڷ� ��ü�ȴ�.
*/