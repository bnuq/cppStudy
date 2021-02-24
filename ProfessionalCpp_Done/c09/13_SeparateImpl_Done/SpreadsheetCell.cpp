#include "SpreadsheetCell.h"
#include <stdexcept> // 예외를 던지는 데 필요.

using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue)
	: mValue(initialValue)
{
}

SpreadsheetCell::SpreadsheetCell(string_view initialValue) // 메서드를 정의할 땐 explicit 키워드를 적지 않는다.
	: mValue(stringToDouble(initialValue))
{
}

void SpreadsheetCell::set(double inValue)
{
	mValue = inValue;
}

void SpreadsheetCell::set(string_view inString)
{
	mValue = stringToDouble(inString);
}

string SpreadsheetCell::doubleToString(double inValue) // 메서드를 정의할 때 static 키워드를 적지 않는다.
{
	return to_string(inValue); // string 을 리턴하는 to_string( ) 함수
}

double SpreadsheetCell::stringToDouble(string_view inString) // 메서드를 정의할 때 static 키워드를 적지 않는다.
{
	// string_view 타입의 data( ) 메서드. 가리키는 const char* 리턴.
	return strtod(inString.data(), nullptr); // string 을 double 타입으로 바꿔주는 strtod( ) 함수
}

// 객체의 데이터 멤버에 접근할 떈, get/set 함수 이용
SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() + rhs.getValue());
}

SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() - rhs.getValue());
}

SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() * rhs.getValue());
}

SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	if (rhs.getValue() == 0) { // 나눗셈의 경우, 0으로 나누는 경우 주의
		throw invalid_argument("Divide by zero.");
	}
	return SpreadsheetCell(lhs.getValue() / rhs.getValue());
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
	set(getValue() + rhs.getValue());
	return *this; // 축약형 연산자는 자기 자신을 변경하고 자신을 리턴
}

SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs)
{
	set(getValue() - rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs)
{
	set(getValue() * rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs)
{
	if (rhs.getValue() == 0) {
		throw invalid_argument("Divide by zero.");
	}
	set(getValue() / rhs.getValue());
	return *this;
}

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() == rhs.getValue());
}

bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() < rhs.getValue());
}

// == 과 < 만 구현하고, 나머지 연산자는 이 둘만을 이용해 구현할 수도 있다.
bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() > rhs.getValue());
}

bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
//	return (lhs.getValue() != rhs.getValue());
	return !(lhs == rhs);
}

bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
//	return (lhs.getValue() <= rhs.getValue());
	return !(lhs > rhs);
}

bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
//	return (lhs.getValue() >= rhs.getValue());
	return !(lhs < rhs);
}
