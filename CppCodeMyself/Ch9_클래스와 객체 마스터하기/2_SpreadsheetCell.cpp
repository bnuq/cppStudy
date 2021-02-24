#include "2_SpreadsheetCell.h" // ���� Ŭ���� ���� �ڵ带 �ҷ�����
#include <iostream>
using namespace std;

/*
* ��ü ������ ����� ���ؼ���, C++ �� �ڵ����� ����Ʈ �����ڷ� �ʱ�ȭ�� �ְų�
* ������ �̴ϼȶ��������� Ư�� �����ڿ� �ʿ��� �μ��� �Ѱ��ش�.
*/
SpreadsheetCell::SpreadsheetCell(double initialValue) : mValue(initialValue), foo(9)
{

}
SpreadsheetCell::SpreadsheetCell(string_view initialValue) 
	: SpreadsheetCell(stringToDouble(initialValue))
{

}



// �� ������ Ŭ������ �޼��带 �����Ѵ�
void SpreadsheetCell::setValue(double inValue)
{
	mValue = inValue;
}
double SpreadsheetCell::getValue() const
{
	return mValue;
}
// string_view ���� �� ����� �μ��� �ѱ��
void SpreadsheetCell::setString(string_view inString)
{
	mValue = stringToDouble(inString); // ���� �޼��带 �̿��Ѵ�
}
string SpreadsheetCell::getString() const
{
	return doubleToString(mValue); // ���� ���� �޼��带 �̿��Ѵ�
}

// ���� �޼���
string SpreadsheetCell::doubleToString(double inValue) const
{
	return to_string(inValue); // to_string �Լ� �̿�
}
double SpreadsheetCell::stringToDouble(string_view inString) const
{
	// string_view �� data( ) �޼���. ����Ű�� const char* �� ��ȯ�Ѵ�.
	return strtod(inString.data(), nullptr); // strtod �Լ� �̿�
}
/*
* strtod �Լ�
* double strtod( const char* nptr, char** endptr );
* ���ڷ� ������ ���ڿ� nptr �� double Ÿ������ ��ȯ
* ����� �� ���� ���ڸ� �߰��ϸ� �� ��ġ �ּҸ� endptr �� ����Ű���� ����
*/
