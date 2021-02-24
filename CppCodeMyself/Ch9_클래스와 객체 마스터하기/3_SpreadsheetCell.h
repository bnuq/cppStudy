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
	// set �ϴ� ����� ������ �� �޼���� �޼��� �����ε��� �̿���, ������ �̸����� �����Ѵ�.
	void set(double inValue);
	void set(std::string_view inString);

	/* const �޼���
	* ��ü�� ������ ����� ����� �������� �ʴ´ٴ� ���� �����Ѵ�.
	* const ��ü �ƴϸ� const ��ü�� ���� ���۷���, �����ʹ� const �޼��常 ����� �� �ִ�.
	* const �� �޼��� ������Ÿ���� �Ϻκ�, �޼��� ���� �ÿ��� �� ����� �Ѵ�.
	* static �޼��带 const �� ������ �� ����.
	*/
	double getValue() const;
	std::string getString() const;


	static void test_static() { std::cout << "public ������ static member function" << std::endl; }

private:

	double mValue = 0; 

	// const �޼��忡���� ������ ������ mutable ������ ���
	mutable size_t mNumAccesses = 0;

	/* ���� �� ���� �޼���� Ư�� ��ü ������ �������� �ʴ´�. 
	* ��ü ������ �ƴ� Ŭ���� ������ ����ȴ�. 
	* �̷��� �޼��带 static �޼��� �� �Ѵ�.( ���� ��� �Լ� )
	* �޼��� �տ� static ������ �Ѵ�.
	* ���� ��� �Լ����� const �� ����� �� ����.( ��ü ������ ���´ٴ� ������ �����ϱ�? )
	*/ 
	static std::string doubleToString(double inValue);
	static double stringToDouble(std::string_view inString);

	

};