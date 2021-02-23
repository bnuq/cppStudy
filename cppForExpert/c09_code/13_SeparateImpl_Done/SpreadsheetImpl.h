#pragma once

#include <cstddef>
#include "Spreadsheet.h"
#include "SpreadsheetCell.h"


/* Spreadsheet 의 중첩 클래스의 정의를 다른 헤더 파일에 나눠서 작성. 
Impl 클래스의 정의가 필요할 때, 컴파일러가 자동으로 이 헤더파일을 찾는다? 
Spreadsheet 의 중첩 클래스이므로 :: 연산자를 이용하여 그 소속을 명확히 밝힌다. */
class Spreadsheet::Impl // 중첩 클래스임을 알림.
{
public: // public method, 인터페이스는 인터페이스 클래스와 동일하다.
	Impl(const SpreadsheetApplication& theApp,
		size_t width, size_t height);
	Impl(const Impl& src); // 복제 생성자
	~Impl();
	Impl& operator=(const Impl& rhs); // 대입 연산자

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	size_t getId() const;


	/* Spreadsheet::Impl 클래스는 Spreadsheet 클래스의 private 영역에 존재. 외부에서 클래스 자체에 접근 불가능. 
	그래서 외부함수 swap 을 firend 선언할 수 없다. => 내부 private 메서드에 swap 을 추가. */


private: // 기존 Spreadsheet 클래스가 가지고 있던 non-public 데이터 멤버, 메서드를 가지고 있다.
	void verifyCoordinate(size_t x, size_t y) const;
	void swap(Impl& other) noexcept; // friend swap() 을 대신할 추가된 메서드. 익셉션이 발생하지 않는 noexcept
	// 중첩 클래스이지만, 매개변수에 쓰일 때는 Spreadsheet:: 쓸 필요없이 그냥 클래스 이름만 적어도 된다.


	// C++는 데이터 멤버 선언과 동시에 초기화를 지원한다.
	size_t mId = 0;
	size_t mWidth = 0;
	size_t mHeight = 0;
	SpreadsheetCell** mCells = nullptr;

	const SpreadsheetApplication& mTheApp; // const 객체를 가리키는 레퍼런스.


	// static data member, 클래스 단위로 적용. 기본적으로 0으로 초기화된다.
	static size_t sCounter;
};
