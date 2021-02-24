#pragma once
#include <string>
#include <string_view>

class Foo
{
public:
	Foo() = default;
	Foo(int n) { }
};

class SpreadsheetCell {
public:
	/* 
	* 명시적 디폴트 생성자. 컴파일러에서 자동으로 제공하는 디폴트 생성자
	*/
	SpreadsheetCell() = default;

	// 생성자
	SpreadsheetCell(double initalValue);
	SpreadsheetCell(std::string_view initialValue);

	/*
	* 명시적으로 디폴트로 만든 복제 생성자	
	*/
	SpreadsheetCell(const SpreadsheetCell& src) = default;
	
	/*
	명시적으로 컴파일러가 자동으로 생성하는 대입 연산자를 사용
	*/
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs) = default;



	void setValue(double inValue);
	double getValue() const;
	void setString(std::string_view inString);
	std::string getString() const;

private:
	/*
	* 데이터 멤버 선언
	* Cell 에 저장하는 숫자 값
	* 문자열이 입력되도, 저장은 double 타입으로 한다
	*/
	// 멤버 변수 선언과 동시에 초기화 가능.
	// 생성자 이니셜라이저 실행 후 실행. 기본 타입만 가능.
	// 객체 멤버의 생성자를 고르는 것은 불가능
	double mValue = 0; 
	Foo foo;
//	Foo foo(8);


	/*
	* 내부에서 double 과 string 간의 변환을 도와주는 메서드
	* private 헬퍼 메서드
	*/
	std::string doubleToString(double inValue) const;
	double stringToDouble(std::string_view inString) const;

}; // 클래스 정의는 문장, statement, 세미콜론으로 끝난다