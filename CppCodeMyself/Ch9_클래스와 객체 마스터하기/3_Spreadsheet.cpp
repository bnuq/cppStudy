#include <iostream>
#include <string>
#include <vector>

#include "3_Spreadsheet.h"

using namespace std;

// ������
Spreadsheet::Spreadsheet(size_t width, size_t height)
	: mWidth(width), mHeight(height)
{	
	mCells = new SpreadsheetCell * [mWidth]; 

	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}



// �Ҹ���
Spreadsheet::~Spreadsheet()
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}

	delete[] mCells;
	mCells = nullptr;
}


Spreadsheet::Spreadsheet(const Spreadsheet& src)
	: Spreadsheet(src.mWidth, src.mHeight)
{

	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}


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
	if (this == &rhs) return *this;

	Spreadsheet temp(rhs); 
	
	swap(*this, temp);
	return *this;
}

// swap �� �̿��� �̵� ������
Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept
	: Spreadsheet()
{
	swap(*this, src);
}


// swap �� �̿��� �̵� ���� ������
// ���� ���� �� �¹ٲٱ� ������ �̿�
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{

	Spreadsheet temp(std::move(rhs));

	swap(*this, temp);
	return *this;
}

// �޼���
void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell) // ���� ���� ���� �Լ�
{
	verifyCoordinate(x, y);
	mCells[x][y] = cell;
}


// const �����ε� �� �� �޼��� ����
// �ڵ� �ߺ��� ���ϱ� ���� const_cast() ������ �̿�
// ���� const ������ �״�� ����
const SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y) const
{
	cout << "const ���� �޼���" << endl;
	verifyCoordinate(x, y);
	return mCells[x][y];
}
// non-const ������ const ������ ��Ȱ��
// non-const ��ü�� as_const() �� �̿��� const ���۷����� ĳ�����ϰ�
// const ������ ȣ���� ���� ���� ������ const ���۷����� �޴´�.
// ���� const_cast() �� ȣ���Ͽ� const �� ������ �׳� ���۷����� �����Ѵ�.
SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	cout << "non-const ���� �޼���" << endl;
	return const_cast<SpreadsheetCell&>(std::as_const(*this).getCellAt(x, y));
	// as_const() �� �ȵȴٸ� static_cast<const Spreadsheet&>(*this) �� ���
}


// ���� �޼���
void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
	if ((x >= mWidth) || (y >= mHeight)) throw std::out_of_range("");
}
void Spreadsheet::cleanup() noexcept
{
	for (size_t i = 0; i < mWidth; i++)
		delete[] mCells[i];

	delete[] mCells;
	mCells = nullptr;
	mWidth = mHeight = 0;
}



/* ��������� �����ε� �����ϱ� */
class Myclass
{
public:
	void foo(int i) {}
	void foo(double) = delete; // foo �޼��忡 double �� �־����� ���� ���� ���� �ʴ´ٰ�, ��������� ����
};




int main()
{
	// non-const ��ü
	Spreadsheet sheet1(5, 6);
	SpreadsheetCell& cell1 = sheet1.getCellAt(1, 1);

	// const ��ü
	const Spreadsheet sheet2(5, 6);
	const SpreadsheetCell& cell2 = sheet2.getCellAt(1, 1);



	Myclass C;
	// �ϳ��� �޼��忡 ����, 2���� ������� ȣ���� ����������
	// double ������ ���ؼ� ��������� ������ ���Ŀ� �Ұ����ϴ�.
	C.foo(123); // int
//	C.foo(12.3); // double �� �־������� �����Ϸ��� 12.3 �� 12 �� �ڵ� ��ȯ�ؼ� ȣ����.

}