#pragma once
/*
클래스를 정의하고
멤버를 선언한다
*/

// SpreadsheetCell 이 문자열도 지원하도록 한다
#include <string>
#include <string_view>

class SpreadsheetCell {
	void test(); // 기본적으로 private 접근 제한자
public:
	
//	SpreadsheetCell(); // 디폴트 생성자

	/* 
	* 명시적 디폴트 생성자. 컴파일러에서 자동으로 제공하는 디폴트 생성자
	* 객체 멤버들에 대해서도 그들의 디폴트 생성자를 호출한다.
	* 단 기본 타입은 제외.
	* 클래스 구현 코드에 디폴트 생성자를 작성하지 않아도 된다.
	*/
	SpreadsheetCell() = default;
	
	/*
	* 명시적으로 삭제된 생성자
	* 컴파일러가 디폴트 생성자를 만들면 안될 때 사용
	SpreadsheetCell() = delete;
	*/

	// 생성자
	SpreadsheetCell(double initalValue);
	// 생성자 오버로딩
	SpreadsheetCell(std::string_view initialValue);

	/*
	복제 생성자.
	다른 객체와 똑같은 객체를 생성
	*/
	SpreadsheetCell(const SpreadsheetCell& src);
	/*
	* 명시적으로 디폴트로 만든 복제 생성자	
	* 컴파일러가 만드는 복제 생성자
	SpreadsheetCell(const SpreadsheetCell& src) = default;
	데이터 멤버들에 대하여
	기본 타입이면 값을 똑같이 복사
	객체 타입이면 그 객체의 복제 생성자를 호출
	*/
	/*
	* 명시적으로 삭제된 복제 생성자
	* 객체를 더이상 복제할 수 없게 된다
	* 객체를 값으로 전달하지 않을 때 설정
	* SpreadsheetCell(const SpreadsheetCell& src) = delete;
	*/



	// 복제 대입 연산자
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs); // rhs = 우변 이라는 뜻. 좌변이 대입 연산자를 호출하고 그 인자로 우변이 들어간다.

	/*
	명시적으로 컴파일러가 자동으로 생성하는 대입 연산자를 사용
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs) = default;
	명시적으로 대입 연산자를 삭제
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs) = delete;
	*/


	// 메서드 선언
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
	double mValue = 0; // 멤버 변수 선언과 동시에 초기화 가능.


	/*
	* 내부에서 double 과 string 간의 변환을 도와주는 메서드
	* private 헬퍼 메서드
	*/
	std::string doubleToString(double inValue) const;
	double stringToDouble(std::string_view inString) const;

}; // 클래스 정의는 문장, statement, 세미콜론으로 끝난다






// struct 의 디폴트 접근 제한자는 public. 그 외는 class 와 같다.
struct SpreadsheetCell2 {
	void test(); // 기본적으로 public 접근 제한자
public:
	// 메서드 선언
	void setValue(double inValue);
	double getValue() const;
private:
	// 데이터 멤버 선언
	double mValue; // Cell 에 저장하는 숫자 값
};

