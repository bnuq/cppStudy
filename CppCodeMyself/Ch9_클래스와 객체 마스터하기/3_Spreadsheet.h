#pragma once
#include <cstddef> // size_t 타입 사용에 필요
#include "3_SpreadsheetCell.h" // 기존의 spreadsheetCell 타입의 2차원 배열을 만든다
#include <string>
#include <iostream>


class Spreadsheet
{
public:

	// 디폴트 인수 지정
	Spreadsheet(size_t width = 100, size_t height = 100); // 메서드를 선언하는 코드에서만 지정가능.
	~Spreadsheet();
	
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet& operator=(const Spreadsheet& rhs);

	Spreadsheet(Spreadsheet&& src) noexcept;
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;

	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;


	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	
	// const 오버로딩 => 동일한 이름의 메서드가 const 여부로 구분된다.
	SpreadsheetCell& getCellAt(size_t x, size_t y); // non-const 객체는 이 non-const 메서드를 호출
	const SpreadsheetCell& getCellAt(size_t x, size_t y) const; // const 객체는 이 const 메서드를 호출
	// 리턴도 const 객체 레퍼런스를 리턴한다.


	void nonThrowingFunc() noexcept { }

private:

	void verifyCoordinate(size_t x, size_t y) const;

	void cleanup() noexcept;
	void moveFrom(Spreadsheet& src) noexcept;

	Spreadsheet() = default;


	size_t mWidth;
	size_t mHeight;
	SpreadsheetCell** mCells = nullptr; // SpreadsheetCell 의 주소를 가리킨다, 주소의 주소를 저장한다.

	std::string mName;
};

