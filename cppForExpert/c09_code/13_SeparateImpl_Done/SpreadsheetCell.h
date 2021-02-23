#pragma once

#include <cstddef> // size_t 타입 사용에 필요
#include <string>
#include <string_view> // string_view 는 const char* 값과 문자열 길이를 가지고 있다. 값으로 전달한다.

class SpreadsheetCell
{
public:
	SpreadsheetCell() = default; // 컴파일러가 자동으로 만들어주는 생성자 사용
	SpreadsheetCell(double initialValue);
	/* explicit 키워드, string_view 타입을 값으로 복사 받았을 때,
	자동으로 SpreadsheetCell 타입을 만드는 것을 막는다. */
	explicit SpreadsheetCell(std::string_view initialValue); 


	/* 게터와 세터를 통해서만 데이터 멤버에 접근할 수 있도록 한다. */


	// 비슷한 기능을 하는 메서드들의 이름을 통일, 메서드 오버로딩. 받는 매개변수로 메서드를 구분한다.
	void set(double inValue);
	void set(std::string_view inString);
/*	std::string set(std::string_view inString);
	매개변수 목록과 이름이 같은데, 리턴값만 다를 수는 없다. */


	// const 함수. 데이터 멤버를 바꾸지 않는다는 것을 보장
	// 인라인 메서드. inline 키워드가 없어도, 클래스 정의에서 함수 정의를 쓰면 자동으로 인식.
	double getValue() const { mNumAccesses++; return mValue; }
	std::string getString() const { mNumAccesses++; return doubleToString(mValue); }


	// static member func. 클래스 단위 적용. static member 만 접근 가능.
	static std::string doubleToString(double inValue); 
	static double stringToDouble(std::string_view inString);


	/* 축약형 연산자 오비로딩. 왼쪽에 반드시 객체가 와야하기 때문에, 교환법칙 고려안함, 
	그래서 메서드로 선언해도 문제 없음. */
	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);

private:
	// 데이터 멤버는 모두 private 로 지정
	double mValue = 0;
	mutable size_t mNumAccesses = 0; // mutable 키워드. 클래스 정의에서 써준다. const 메서드에서 변경가능함을 알림.
};



/* 여러 연산자들 오버로딩 선언. 교환 법칙을 성립하기 위해서, 외부 함수로 선언.
클래스를 정의하는 헤더파일에 같이 선언되어야 한다.
좌변을 뜻하는 lhs, 우변을 뜻하는 rhs. 각 피연산자를 빠르게 가져오되 변형하지 않는다는 의미로 const 레퍼런스 이용 */
SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
