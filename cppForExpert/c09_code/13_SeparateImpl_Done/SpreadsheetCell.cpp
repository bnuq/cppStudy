#include "SpreadsheetCell.h"
#include <stdexcept> // ���ܸ� ������ �� �ʿ�.

using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue)
	: mValue(initialValue)
{
}

SpreadsheetCell::SpreadsheetCell(string_view initialValue) // �޼��带 ������ �� explicit Ű���带 ���� �ʴ´�.
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

string SpreadsheetCell::doubleToString(double inValue) // �޼��带 ������ �� static Ű���带 ���� �ʴ´�.
{
	return to_string(inValue); // string �� �����ϴ� to_string( ) �Լ�
}

double SpreadsheetCell::stringToDouble(string_view inString) // �޼��带 ������ �� static Ű���带 ���� �ʴ´�.
{
	// string_view Ÿ���� data( ) �޼���. ����Ű�� const char* ����.
	return strtod(inString.data(), nullptr); // string �� double Ÿ������ �ٲ��ִ� strtod( ) �Լ�
}

// ��ü�� ������ ����� ������ ��, get/set �Լ� �̿�
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
	if (rhs.getValue() == 0) { // �������� ���, 0���� ������ ��� ����
		throw invalid_argument("Divide by zero.");
	}
	return SpreadsheetCell(lhs.getValue() / rhs.getValue());
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
	set(getValue() + rhs.getValue());
	return *this; // ����� �����ڴ� �ڱ� �ڽ��� �����ϰ� �ڽ��� ����
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

// == �� < �� �����ϰ�, ������ �����ڴ� �� �Ѹ��� �̿��� ������ ���� �ִ�.
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
