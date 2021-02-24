#pragma once
#include <string>
#include <string_view>

class Foo
{
public:
	Foo() = default;
	Foo(int n) { }
};

class SpreadsheetCell {
public:
	/* 
	* ����� ����Ʈ ������. �����Ϸ����� �ڵ����� �����ϴ� ����Ʈ ������
	*/
	SpreadsheetCell() = default;

	// ������
	SpreadsheetCell(double initalValue);
	SpreadsheetCell(std::string_view initialValue);

	/*
	* ��������� ����Ʈ�� ���� ���� ������	
	*/
	SpreadsheetCell(const SpreadsheetCell& src) = default;
	
	/*
	��������� �����Ϸ��� �ڵ����� �����ϴ� ���� �����ڸ� ���
	*/
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs) = default;



	void setValue(double inValue);
	double getValue() const;
	void setString(std::string_view inString);
	std::string getString() const;

private:
	/*
	* ������ ��� ����
	* Cell �� �����ϴ� ���� ��
	* ���ڿ��� �Էµǵ�, ������ double Ÿ������ �Ѵ�
	*/
	// ��� ���� ����� ���ÿ� �ʱ�ȭ ����.
	// ������ �̴ϼȶ����� ���� �� ����. �⺻ Ÿ�Ը� ����.
	// ��ü ����� �����ڸ� ���� ���� �Ұ���
	double mValue = 0; 
	Foo foo;
//	Foo foo(8);


	/*
	* ���ο��� double �� string ���� ��ȯ�� �����ִ� �޼���
	* private ���� �޼���
	*/
	std::string doubleToString(double inValue) const;
	double stringToDouble(std::string_view inString) const;

}; // Ŭ���� ���Ǵ� ����, statement, �����ݷ����� ������