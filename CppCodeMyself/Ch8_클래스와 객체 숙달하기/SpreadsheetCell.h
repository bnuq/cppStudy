#pragma once
/*
Ŭ������ �����ϰ�
����� �����Ѵ�
*/

// SpreadsheetCell �� ���ڿ��� �����ϵ��� �Ѵ�
#include <string>
#include <string_view>

class SpreadsheetCell {
	void test(); // �⺻������ private ���� ������
public:
	
//	SpreadsheetCell(); // ����Ʈ ������

	/* 
	* ����� ����Ʈ ������. �����Ϸ����� �ڵ����� �����ϴ� ����Ʈ ������
	* ��ü ����鿡 ���ؼ��� �׵��� ����Ʈ �����ڸ� ȣ���Ѵ�.
	* �� �⺻ Ÿ���� ����.
	* Ŭ���� ���� �ڵ忡 ����Ʈ �����ڸ� �ۼ����� �ʾƵ� �ȴ�.
	*/
	SpreadsheetCell() = default;
	
	/*
	* ��������� ������ ������
	* �����Ϸ��� ����Ʈ �����ڸ� ����� �ȵ� �� ���
	SpreadsheetCell() = delete;
	*/

	// ������
	SpreadsheetCell(double initalValue);
	// ������ �����ε�
	SpreadsheetCell(std::string_view initialValue);

	/*
	���� ������.
	�ٸ� ��ü�� �Ȱ��� ��ü�� ����
	*/
	SpreadsheetCell(const SpreadsheetCell& src);
	/*
	* ��������� ����Ʈ�� ���� ���� ������	
	* �����Ϸ��� ����� ���� ������
	SpreadsheetCell(const SpreadsheetCell& src) = default;
	������ ����鿡 ���Ͽ�
	�⺻ Ÿ���̸� ���� �Ȱ��� ����
	��ü Ÿ���̸� �� ��ü�� ���� �����ڸ� ȣ��
	*/
	/*
	* ��������� ������ ���� ������
	* ��ü�� ���̻� ������ �� ���� �ȴ�
	* ��ü�� ������ �������� ���� �� ����
	* SpreadsheetCell(const SpreadsheetCell& src) = delete;
	*/



	// ���� ���� ������
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs); // rhs = �캯 �̶�� ��. �º��� ���� �����ڸ� ȣ���ϰ� �� ���ڷ� �캯�� ����.

	/*
	��������� �����Ϸ��� �ڵ����� �����ϴ� ���� �����ڸ� ���
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs) = default;
	��������� ���� �����ڸ� ����
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs) = delete;
	*/


	// �޼��� ����
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
	double mValue = 0; // ��� ���� ����� ���ÿ� �ʱ�ȭ ����.


	/*
	* ���ο��� double �� string ���� ��ȯ�� �����ִ� �޼���
	* private ���� �޼���
	*/
	std::string doubleToString(double inValue) const;
	double stringToDouble(std::string_view inString) const;

}; // Ŭ���� ���Ǵ� ����, statement, �����ݷ����� ������






// struct �� ����Ʈ ���� �����ڴ� public. �� �ܴ� class �� ����.
struct SpreadsheetCell2 {
	void test(); // �⺻������ public ���� ������
public:
	// �޼��� ����
	void setValue(double inValue);
	double getValue() const;
private:
	// ������ ��� ����
	double mValue; // Cell �� �����ϴ� ���� ��
};

