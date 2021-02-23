#pragma once

#include "SpreadsheetCell.h"
#include <memory> // 스마트 포인터 사용

// 포워드 선언, 전방 선언. 클래스가 서로를 참조할 때 사용. 이런 이름의 클래스가 있다~ 는 걸 알림.
class SpreadsheetApplication;

class Spreadsheet // Spreadsheet 클래스가 인터페이스 클래스. 클라이언트에 노출되는 클래스.
{
public: // 구현 클래스와 똑같은 public 메서드를 제공. 

	Spreadsheet(const SpreadsheetApplication& theApp, // 전방선언을 했기 때문에 SpreadsheetApplication 클래스를 쓸 수 있다.
		size_t width = kMaxWidth, size_t height = kMaxHeight); // 생성자 디폴트 인수 사용.
	Spreadsheet(const Spreadsheet& src);
	
	// 데이터 멤버 중 unique_ptr 타입이 있기 때문에, 사용자 선언 소멸자가 있어야 한다??
	// 스마트 포인터를 사용하면 소멸자가 자동으로 생성되지 않나봐?
	~Spreadsheet();

	Spreadsheet& operator=(const Spreadsheet& rhs); // 대입 연산자

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	size_t getId() const;


	/* static const data member. const static 써도 돼. 클래스 상수로 사용.
	처음 선언할 때만 static const 쓰고, 클래스 내에서는 일반 데이터 멤버처럼 사용.
	일반 static data member 와 다르게 선언만으로 정의까지 완료된다. 소스코드에서 따로 또 정의할 필요 없다. */
	static const size_t kMaxHeight = 100;
	static const size_t kMaxWidth = 100;

	
	// 전역함수 friend 선언
	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;

	
private:
	// 이전 Spreadsheet.h 와는 다르게 private 데이터 멤버와 메서드가 클라이언트에 노출되지 않는다.

	class Impl; // Impl 클래스는 구현 클래스. 중첩 클래스. 이런 중첩 클래스가 private 에 있다고 선언.
	// private 영역에 선언됐기에, 인터페이스 클래스인 Spreadsheet 클래스만 접근이 가능하다.

	// 데이터 멤버는 이것 하나만 가진다.
	std::unique_ptr<Impl> mImpl; // 구현 클래스 객체에 대한 스마트 포인터. 핌플 이디엄, 브릿지 패턴.
};

/* Spreadsheet::Impl 클래스의 정의는 다른 헤더파일에 작성한다. 그래도 된다. */