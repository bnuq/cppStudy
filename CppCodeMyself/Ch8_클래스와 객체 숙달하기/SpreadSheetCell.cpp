#include "SpreadsheetCell.h" // ���� Ŭ���� ���� �ڵ带 �ҷ�����
#include <iostream>
using namespace std;


// Cell �� value �� ������ִ� �Լ�
void printCell(const SpreadsheetCell& cell)
{
	cout << cell.getValue() << endl;
}



/*
// ����Ʈ ������
����� ����Ʈ �����ڰ� �����ϱ� ������, �� �ڵ�� ��� �����Ѵ�.
SpreadsheetCell::SpreadsheetCell()
{
	// mValue = 0; ������ ��� ����� ���ÿ� �ʱ�ȭ�ϰ� ������ �� ���嵵 �ʿ����.
}
*/



// ������
// ������ �̴ϼȶ������� �̿��Ͽ� ������ ����� �ʱ갪�� ����
// ���� ������ ����� ���� ����Ʈ �����ڰ� ���ǵ� �ִٸ�, ������ ����� ������ �� ����Ʈ �����ڰ� ȣ��Ǳ� ������, ������ �̴ϼȶ������� ���� �ʾƵ� �ȴ�.
SpreadsheetCell::SpreadsheetCell(double initialValue) : mValue(initialValue)
{
//	setValue(initialValue); // ������ ������ �޼��带 �̿��Ѵ�
}
/*
SpreadsheetCell::SpreadsheetCell(string_view initalValue)
{
	setString(initalValue); // ���ó� �޼��带 �̿��Ͽ� ������ ��� ���� �����Ѵ�

	* �� �����ڿ��� �ٸ� �����ڸ� ȣ���� ���� �ִ�
	* �μ��� ���� string_view �� double �� �ٲ� ��, double �� �μ��� �޴� �����ڸ� ȣ��
	SpreadsheetCell(stringToDouble(initalValue));

	* �ٵ� �̷��� �ϸ� �ǵ��� ��� ������ �ȵȴ�
	* �׳� ���������� �̸����� �ӽð�ü�� �����ƴٰ� ����� ��
	* �̰� �ϰ� �ʹٸ� ���� ������, delegating constructor �� ����ؾ� �Ѵ�
	
}
*/
/*
���� �����ڸ� ����ϴ� ���,
�ݵ�� ������ �̴ϼȶ��������� �ٸ� �����ڸ� ȣ���ؾ� �ϸ�
�װ� �ܿ� �ٸ� ���� ������ �̴ϼȶ������� ������ �ȵȴ�.
*/
// �μ��� ���� string_view �� double �� �ٲ� ��, double ���� �μ��� �޴� �ٸ� �����ڸ� ȣ��
// string_view �����ڰ� �� ���� �ٸ� �����ڿ� �Ѱ�����, ���� ������
// ������ ���� �� double �����ڴ�, Ÿ�� ������
// Ÿ�� �����ڰ� ������ �Ŀ�, ���� �������� �ڵ尡 ����ȴ�.
SpreadsheetCell::SpreadsheetCell(string_view initialValue) : SpreadsheetCell(stringToDouble(initialValue))
{

}

/*
���� ������
src �� mValue ����, this �� mValue �� �ʱ갪���� �Ѵ�.
*/
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) : mValue(src.mValue) { }



// ���� ���� ������
SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	// ���� �������� ���, �ڱ� �ڽ��� ������ �� �����Ƿ� �� ��츦 �ݵ�� ����Ѵ�
	if (&rhs == this) return *this;

	// ���� ���� ������ �̹Ƿ�, �ڽ��� ������ ����鿡 ���ؼ��� ��� ���� ���� �����ڸ� ȣ���Ѵ�
	mValue = rhs.mValue;

	return *this; // ������ ����� ����
}





// �� ������ Ŭ������ �޼��带 �����Ѵ�

void SpreadsheetCell::setValue(double inValue)
{
	mValue = inValue;
	/*
	// mValue �� �����ϰ� ���� �� ���� ����ϰ� �ʹ�
	printCell(*this); // this �����ͷ� ���� ��ü�� �Լ��� �μ��� �ѱ��
	*/
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
