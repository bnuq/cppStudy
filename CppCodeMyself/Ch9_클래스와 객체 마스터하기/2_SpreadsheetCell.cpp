#include "2_SpreadsheetCell.h" // 먼저 클래스 정의 코드를 불러오고
#include <iostream>
using namespace std;

/*
* 객체 데이터 멤버에 대해서는, C++ 이 자동으로 디폴트 생성자로 초기화해 주거나
* 생성자 이니셜라이저에서 특정 생성자에 필요한 인수를 넘겨준다.
*/
SpreadsheetCell::SpreadsheetCell(double initialValue) : mValue(initialValue), foo(9)
{

}
SpreadsheetCell::SpreadsheetCell(string_view initialValue) 
	: SpreadsheetCell(stringToDouble(initialValue))
{

}



// 그 다음에 클래스의 메서드를 정의한다
void SpreadsheetCell::setValue(double inValue)
{
	mValue = inValue;
}
double SpreadsheetCell::getValue() const
{
	return mValue;
}
// string_view 값은 값 복사로 인수를 넘긴다
void SpreadsheetCell::setString(string_view inString)
{
	mValue = stringToDouble(inString); // 헬퍼 메서드를 이용한다
}
string SpreadsheetCell::getString() const
{
	return doubleToString(mValue); // 역시 헬퍼 메서드를 이용한다
}

// 헬퍼 메서드
string SpreadsheetCell::doubleToString(double inValue) const
{
	return to_string(inValue); // to_string 함수 이용
}
double SpreadsheetCell::stringToDouble(string_view inString) const
{
	// string_view 의 data( ) 메서드. 가리키는 const char* 를 반환한다.
	return strtod(inString.data(), nullptr); // strtod 함수 이용
}
/*
* strtod 함수
* double strtod( const char* nptr, char** endptr );
* 숫자로 구성된 문자열 nptr 를 double 타입으로 반환
* 계산할 수 없는 문자를 발견하면 그 위치 주소를 endptr 이 가리키도록 설정
*/
