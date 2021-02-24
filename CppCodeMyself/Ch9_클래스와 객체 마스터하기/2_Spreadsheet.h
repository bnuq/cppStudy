#pragma once
#include <cstddef> // size_t 타입 사용에 필요
#include "2_SpreadsheetCell.h" // 기존의 spreadsheetCell 타입의 2차원 배열을 만든다
#include <string>
#include <iostream>


class Spreadsheet
{
public:
	// 생성자
	Spreadsheet(size_t width, size_t height);



	// 소멸자
	~Spreadsheet();
	/* 
	* 소멸자는 인수를 받지 않고
	* 익셉션을 절대 발생시키지 않는 noexcept 함수이다. => 쓰지 않아도 기본적으로 적용
	*/



	// 복제 생성자
	Spreadsheet(const Spreadsheet& src); // 복제 생성은 다른 source 객체로 부터 하고
	/*
	클래스 내에 메모리 동적할당이 있을 때, 명시적으로 이 객체의 복제 생성을 막을 수도 있다.
	Spreadsheet(const Spreadsheet& src) = delete;
	이 클래스의 객체를 함수에 객체로 전달하는 것을 막고( 함수 내에서 인자를 받을 때 복제 생성 )
	함수나 메서드에서 이 클래스의 객체를 리턴하는 것을 막는다.( 호출한 쪽에서 리턴 값을 받을 때 복제 생성 )
	*/



	// 대입 연산자
	Spreadsheet& operator=(const Spreadsheet& rhs); // 대입 연산은 우항 객체로 부터 한다.
	/*
	역시 클래스 내에 메모리 동적할당이 있을 때, 명시적으로 객체에 대입하는 것 자체를 막을 수도 있다.
	Spreadsheet& operator=(const Spreadsheet& rhs) = delete;
	이 클래스의 객체에 무언가 대입하는 것 자체를 막아버린다.
	*/


	// 이동 생성자와 이동 대입 연산자에서는 익셉션이 발생해서는 안된다 ==> 표준 라이브러리와 호환성을 유지하기 위해 필요??
	// 이동 생성자
	Spreadsheet(Spreadsheet&& src) noexcept;


	// 이동 대입 연산자
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;



	// 비멤버 함수 swap( ). 복제 후 맞바꾸기 패턴을 위해 friend 로 등록
	// 익셉션을 발생시키지 않는다.
	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept; // friend 선언 자체가 프로토타입 역할, 다른 곳에서 swap 함수 선언을 또 할 필요가 없다.



	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);



	void nonThrowingFunc() noexcept { } // 절대 익셉션을 던지지 않는 함수는 noexcept 키워드가 붙는다.
	// 여기서 익셉션이 발생하면 프로그램은 멈춘다.

private:
//	bool inRange(size_t value, size_t upper) const; // 해당 value 가 upper 내에 존재하는 지 확인하는 메서드
	/* 메서드 정의부분에서 코드중복이 많이 일어나므로, inRange 메서드 대신 확인도 하고 익셉션도 던지는 메서드를 새로 만든다. */

	void verifyCoordinate(size_t x, size_t y) const; // 좌표값이 유효한지 확인하고 익셉션을 던지는 헬퍼 메서드


	// 이동 의미론에 쓰일 헬퍼 메서드
	void cleanup() noexcept; // 소멸자와 이동 대입 연산자에서 사용
	void moveFrom(Spreadsheet& src) noexcept; // 원본 객체의 멤버 변수를 대상 객체로 이동시킨 뒤, 원본 객체를 리셋



	// 디폴트 생성자 추가. 사용자가 디폴트 생성자를 사용할 일은 없기 때문에, 이를 private 영역에 선언한다.
	Spreadsheet() = default; // 컴파일러가 자동으로 생성해 주는 것을 사용하겠다.


	size_t mWidth;
	size_t mHeight;
	SpreadsheetCell** mCells = nullptr; // SpreadsheetCell 의 주소를 가리킨다, 주소의 주소를 저장한다.

	std::string mName;
};

