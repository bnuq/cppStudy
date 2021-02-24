#include <iostream>
#include <string>
#include <vector>

#include "3_Spreadsheet.h"

using namespace std;

// 생성자
Spreadsheet::Spreadsheet(size_t width, size_t height)
	: mWidth(width), mHeight(height)
{	
	mCells = new SpreadsheetCell * [mWidth]; 

	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}



// 소멸자
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
	// 실제로 데이터 멤버를 교체하는 작염은 <utility> 에서 제공하는 std::swap 함수를 이용한다.

	using std::swap; // 여기서 부터 그냥 swap 이 std::swap 을 뜻한다는 뜻.

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells); // 두 포인터가 가리키던 주소값을 교환해준다.
}


// 복제 후 맞바꾸기 패턴을 적용한 대입 연산자
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	if (this == &rhs) return *this;

	Spreadsheet temp(rhs); 
	
	swap(*this, temp);
	return *this;
}

// swap 을 이용한 이동 생성자
Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept
	: Spreadsheet()
{
	swap(*this, src);
}


// swap 을 이용한 이동 대입 연산자
// 역시 복사 후 맞바꾸기 패턴을 이용
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{

	Spreadsheet temp(std::move(rhs));

	swap(*this, temp);
	return *this;
}

// 메서드
void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell) // 셀에 값을 쓰는 함수
{
	verifyCoordinate(x, y);
	mCells[x][y] = cell;
}


// const 오버로딩 된 두 메서드 구현
// 코드 중복을 피하기 위해 const_cast() 패턴을 이용
// 먼저 const 버전은 그대로 구현
const SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y) const
{
	cout << "const 버전 메서드" << endl;
	verifyCoordinate(x, y);
	return mCells[x][y];
}
// non-const 버전은 const 버전을 재활용
// non-const 객체를 as_const() 를 이용해 const 레퍼런스로 캐스팅하고
// const 버전을 호출한 다음 리턴 값으로 const 레퍼런스를 받는다.
// 이후 const_cast() 를 호출하여 const 를 제거해 그냥 레퍼런스를 리턴한다.
SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	cout << "non-const 버전 메서드" << endl;
	return const_cast<SpreadsheetCell&>(std::as_const(*this).getCellAt(x, y));
	// as_const() 가 안된다면 static_cast<const Spreadsheet&>(*this) 로 사용
}


// 헬퍼 메서드
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



/* 명시적으로 오버로딩 제거하기 */
class Myclass
{
public:
	void foo(int i) {}
	void foo(double) = delete; // foo 메서드에 double 이 주어지는 경우는 절대 쓰지 않는다고, 명시적으로 삭제
};




int main()
{
	// non-const 객체
	Spreadsheet sheet1(5, 6);
	SpreadsheetCell& cell1 = sheet1.getCellAt(1, 1);

	// const 객체
	const Spreadsheet sheet2(5, 6);
	const SpreadsheetCell& cell2 = sheet2.getCellAt(1, 1);



	Myclass C;
	// 하나의 메서드에 대해, 2가지 방식으로 호출이 가능했지만
	// double 버전에 대해서 명시적으로 삭제한 이후엔 불가능하다.
	C.foo(123); // int
//	C.foo(12.3); // double 이 주어졌지만 컴파일러가 12.3 을 12 로 자동 변환해서 호출함.

}