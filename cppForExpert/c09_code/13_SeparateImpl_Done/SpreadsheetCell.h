#pragma once

#include <cstddef> // size_t Ÿ�� ��뿡 �ʿ�
#include <string>
#include <string_view> // string_view �� const char* ���� ���ڿ� ���̸� ������ �ִ�. ������ �����Ѵ�.

class SpreadsheetCell
{
public:
	SpreadsheetCell() = default; // �����Ϸ��� �ڵ����� ������ִ� ������ ���
	SpreadsheetCell(double initialValue);
	/* explicit Ű����, string_view Ÿ���� ������ ���� �޾��� ��,
	�ڵ����� SpreadsheetCell Ÿ���� ����� ���� ���´�. */
	explicit SpreadsheetCell(std::string_view initialValue); 


	/* ���Ϳ� ���͸� ���ؼ��� ������ ����� ������ �� �ֵ��� �Ѵ�. */


	// ����� ����� �ϴ� �޼������ �̸��� ����, �޼��� �����ε�. �޴� �Ű������� �޼��带 �����Ѵ�.
	void set(double inValue);
	void set(std::string_view inString);
/*	std::string set(std::string_view inString);
	�Ű����� ��ϰ� �̸��� ������, ���ϰ��� �ٸ� ���� ����. */


	// const �Լ�. ������ ����� �ٲ��� �ʴ´ٴ� ���� ����
	// �ζ��� �޼���. inline Ű���尡 ���, Ŭ���� ���ǿ��� �Լ� ���Ǹ� ���� �ڵ����� �ν�.
	double getValue() const { mNumAccesses++; return mValue; }
	std::string getString() const { mNumAccesses++; return doubleToString(mValue); }


	// static member func. Ŭ���� ���� ����. static member �� ���� ����.
	static std::string doubleToString(double inValue); 
	static double stringToDouble(std::string_view inString);


	/* ����� ������ ����ε�. ���ʿ� �ݵ�� ��ü�� �;��ϱ� ������, ��ȯ��Ģ �������, 
	�׷��� �޼���� �����ص� ���� ����. */
	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);

private:
	// ������ ����� ��� private �� ����
	double mValue = 0;
	mutable size_t mNumAccesses = 0; // mutable Ű����. Ŭ���� ���ǿ��� ���ش�. const �޼��忡�� ���氡������ �˸�.
};



/* ���� �����ڵ� �����ε� ����. ��ȯ ��Ģ�� �����ϱ� ���ؼ�, �ܺ� �Լ��� ����.
Ŭ������ �����ϴ� ������Ͽ� ���� ����Ǿ�� �Ѵ�.
�º��� ���ϴ� lhs, �캯�� ���ϴ� rhs. �� �ǿ����ڸ� ������ �������� �������� �ʴ´ٴ� �ǹ̷� const ���۷��� �̿� */
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
