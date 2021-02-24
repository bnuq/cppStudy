#include "3_SpreadsheetCell.h" // ���� Ŭ���� ���� �ڵ带 �ҷ�����
#include <iostream>
using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue) : mValue(initialValue)
{
}
SpreadsheetCell::SpreadsheetCell(string_view initialValue) 
	: SpreadsheetCell(stringToDouble(initialValue))
{
}


void SpreadsheetCell::set(double inValue)
{
	mValue = inValue;
}
// string_view ���� �� ����� �μ��� �ѱ��
void SpreadsheetCell::set(string_view inString)
{
	mValue = stringToDouble(inString); // ���� �޼��带 �̿��Ѵ�
}

// const �޼���� �޼��� �����ÿ��� const Ű���带 �ݵ�� ���´�.
// const �޼��� �ȿ����� �� ������ ������� �ٷ� ��, ������ ����� ���� const ���۷����� ���� ��ó�� �ൿ�Ѵ�.
// mutable ������ ����� ������ �����ϴ�
/*
inline Ű���� ���, �ζ��� �޼���� �������.
�� �޼��带 ȣ���ϴ� �κп� �޼��� ������ �״�� ���� �ִ´�.
*/
inline double SpreadsheetCell::getValue() const
{
	mNumAccesses++;
	return mValue;
}
inline string SpreadsheetCell::getString() const
{
	mNumAccesses++;
	return doubleToString(mValue); // ���� ���� �޼��带 �̿��Ѵ�
}



/* static �޼��带 ������ ��, static Ű���带 �����ص� �ȴ�.
* �� static �޼���� Ư�� ��ü�� ���� ȣ����� �����Ƿ� this �����͸� ����� �� ����.
* ���� Ư�� ��ü�� ������ �ʾ����Ƿ�, non-static ������ ����� ����� �� ����. static ������ ������� ������ �� �ִ�. 
* ���� Ŭ���� �ȿ����� static �޼��带 �Ϲ� �Լ�ó�� ȣ���� �� �ִ�.
* 
*/
string SpreadsheetCell::doubleToString(double inValue)
{
	return to_string(inValue); // to_string �Լ� �̿�
}
double SpreadsheetCell::stringToDouble(string_view inString)
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



int main()
{
	// Ŭ���� �ۿ��� ���� ��� �Լ��� ȣ���� ���� Ŭ���� �̸� :: �� �̿��Ͽ� �����Ѵ�
	SpreadsheetCell::test_static();


	// �Ϲ� ��ü�� const �޼���, non-const �޼��� ��� ȣ�� ����
	SpreadsheetCell tempCell1(9);
	tempCell1.set(8); // non-const �޼��� ȣ��
	cout << tempCell1.getValue() << endl; // const �޼��� ȣ��

	// ��ü�� const �� ����, const �޼��常 ȣ�� ����
	const SpreadsheetCell tempCell2(99);
//	tempCell2.setValue(88); // non-const �޼��� ȣ�� �Ұ���
	cout << tempCell2.getValue() << endl; // const �޼��� ȣ��

	// const ��ü�� ���� ���۷���, const �޼��常 ȣ�� ����
	const SpreadsheetCell& refCell = tempCell1;
//	refCell.setValue(88);
	cout << refCell.getValue() << endl; // const �޼��� ȣ��

	// const ��ü�� ���� ������, 
	const SpreadsheetCell* ptrCell = &tempCell1;
//	ptrCell->setValue(88);
	cout << ptrCell->getValue() << endl;

	// �����Ͱ� const �ѰŸ� ��� ������
	SpreadsheetCell* const ptrCell2 = &tempCell1;
	ptrCell2->set(77);
	cout << ptrCell2->getValue() << endl;

}