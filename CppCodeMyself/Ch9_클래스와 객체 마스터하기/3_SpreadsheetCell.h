#pragma once
#include <string>
#include <string_view>

#include <iostream>

class SpreadsheetCell {
public:
	
	SpreadsheetCell() = default;
	SpreadsheetCell(double initalValue);
	SpreadsheetCell(std::string_view initialValue);

	SpreadsheetCell(const SpreadsheetCell& src) = default;
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs) = default;

	/*
	void setValue(double inValue);
	void setString(std::string_view inString);
	*/
	// set 하는 기능이 동일한 두 메서드는 메서드 오버로딩을 이용해, 동일한 이름으로 통일한다.
	void set(double inValue);
	void set(std::string_view inString);

	/* const 메서드
	* 객체의 데이터 멤버를 절대로 변경하지 않는다는 것을 보장한다.
	* const 객체 아니면 const 객체에 대한 레퍼런스, 포인터는 const 메서드만 사용할 수 있다.
	* const 는 메서드 프로토타입의 일부분, 메서드 구현 시에도 꼭 적어야 한다.
	* static 메서드를 const 로 선언할 수 없다.
	*/
	double getValue() const;
	std::string getString() const;


	static void test_static() { std::cout << "public 영역의 static member function" << std::endl; }

private:

	double mValue = 0; 

	// const 메서드에서도 변경이 가능한 mutable 데이터 멤버
	mutable size_t mNumAccesses = 0;

	/* 밑의 두 헬퍼 메서드는 특정 객체 정보에 접근하지 않는다. 
	* 객체 단위가 아닌 클래스 단위에 적용된다. 
	* 이러한 메서드를 static 메서드 라 한다.( 정적 멤버 함수 )
	* 메서드 앞에 static 선언을 한다.
	* 정적 멤버 함수에는 const 를 사용할 수 없다.( 객체 변형을 막는다는 개념이 없으니까? )
	*/ 
	static std::string doubleToString(double inValue);
	static double stringToDouble(std::string_view inString);

	

};