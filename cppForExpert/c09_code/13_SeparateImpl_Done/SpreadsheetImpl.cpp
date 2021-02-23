#include "SpreadsheetImpl.h"
#include "Spreadsheet.h"
#include <stdexcept>
#include <utility> // std::swap()
#include <algorithm> // std::min() 함수 사용.


// static data member 는 소스코드, 메서드 정의 파일에서 한번 정의를 해주어야 한다. => 메모리 할당.
size_t Spreadsheet::Impl::sCounter; // 변수 정의할 때, static 키워드를 쓰지 않는다.


Spreadsheet::Impl::Impl(const SpreadsheetApplication& theApp,
	size_t width, size_t height)
	: mId(sCounter++)
	, mWidth(std::min(width, Spreadsheet::kMaxWidth))
	, mHeight(std::min(height, Spreadsheet::kMaxHeight))
	, mTheApp(theApp) // 레퍼런스 타입은 선언과 동시에 초기화해야 한다. => 생성자 이니셜라이저를 반드시 사용해야 한다.
					  // 이후에 레퍼런스 값을 변경할 수 없다.
{
	mCells = new SpreadsheetCell*[mWidth]; // 전체 배열
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight]; // 각 원소가 또 배열을 가리킨다.
	}
}

Spreadsheet::Impl::~Impl()
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}


/* 중첩 클래스의 메서드 이름의 경우 :: 연산자로 소속을 밝혀야 하지만
매개변수에서 쓰는 경우, 소속 밝힐 필요없이 그냥 사용해도 된다. */
Spreadsheet::Impl::Impl(const Impl& src) // 복제 생성자
	: Impl(src.mTheApp, src.mWidth, src.mHeight) // 위임 생성자 사용
{
	// 이 생성자의 ctor-이니셜라이저는 먼저 적절한 양의 메모리를 할당하는 작업을
	// 비복제 버전의 생성자에게 위임한다.

	// 그러고 나서 실제로 값을 복제하는 작업을 수행한다.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

void Spreadsheet::Impl::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

void Spreadsheet::Impl::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	verifyCoordinate(x, y);
	mCells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::Impl::getCellAt(size_t x, size_t y)
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

void Spreadsheet::Impl::swap(Impl& other) noexcept // swap() 는 noexcept
{
	using std::swap;

	swap(mWidth, other.mWidth);
	swap(mHeight, other.mHeight);
	swap(mCells, other.mCells);
}


/* 중첩 클래스를 리턴 타입에 적는 경우, :: 연산자로 소속을 밝혀야 하지만
매개변수에서 쓰는 경우, 소속 밝힐 필요없이 그냥 사용해도 된다. */
Spreadsheet::Impl& Spreadsheet::Impl::operator=(const Impl& rhs) // 복제 대입 연산자
{
	// 자신을 대입하는지 확인한다. => 대입 연산자니까
	if (this == &rhs) {
		return *this;
	}

	// 복제 후 맞바꾸기(copy-and-swap) 패턴 적용
	Impl temp(rhs); // 모든 작업을 임시 인스턴스에서 처리한다. 익셉션이 발생해도 *this 객체에는 영향이 없게 하기 위해
	swap(temp); // 예외를 발생하지 않는 연산으로만 처리한다.
	return *this;
}

size_t Spreadsheet::Impl::getId() const
{
	return mId;
}
