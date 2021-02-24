#pragma once
#include <cstddef> // size_t Ÿ�� ��뿡 �ʿ�
#include "2_SpreadsheetCell.h" // ������ spreadsheetCell Ÿ���� 2���� �迭�� �����
#include <string>
#include <iostream>


class Spreadsheet
{
public:
	// ������
	Spreadsheet(size_t width, size_t height);



	// �Ҹ���
	~Spreadsheet();
	/* 
	* �Ҹ��ڴ� �μ��� ���� �ʰ�
	* �ͼ����� ���� �߻���Ű�� �ʴ� noexcept �Լ��̴�. => ���� �ʾƵ� �⺻������ ����
	*/



	// ���� ������
	Spreadsheet(const Spreadsheet& src); // ���� ������ �ٸ� source ��ü�� ���� �ϰ�
	/*
	Ŭ���� ���� �޸� �����Ҵ��� ���� ��, ��������� �� ��ü�� ���� ������ ���� ���� �ִ�.
	Spreadsheet(const Spreadsheet& src) = delete;
	�� Ŭ������ ��ü�� �Լ��� ��ü�� �����ϴ� ���� ����( �Լ� ������ ���ڸ� ���� �� ���� ���� )
	�Լ��� �޼��忡�� �� Ŭ������ ��ü�� �����ϴ� ���� ���´�.( ȣ���� �ʿ��� ���� ���� ���� �� ���� ���� )
	*/



	// ���� ������
	Spreadsheet& operator=(const Spreadsheet& rhs); // ���� ������ ���� ��ü�� ���� �Ѵ�.
	/*
	���� Ŭ���� ���� �޸� �����Ҵ��� ���� ��, ��������� ��ü�� �����ϴ� �� ��ü�� ���� ���� �ִ�.
	Spreadsheet& operator=(const Spreadsheet& rhs) = delete;
	�� Ŭ������ ��ü�� ���� �����ϴ� �� ��ü�� ���ƹ�����.
	*/


	// �̵� �����ڿ� �̵� ���� �����ڿ����� �ͼ����� �߻��ؼ��� �ȵȴ� ==> ǥ�� ���̺귯���� ȣȯ���� �����ϱ� ���� �ʿ�??
	// �̵� ������
	Spreadsheet(Spreadsheet&& src) noexcept;


	// �̵� ���� ������
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;



	// ���� �Լ� swap( ). ���� �� �¹ٲٱ� ������ ���� friend �� ���
	// �ͼ����� �߻���Ű�� �ʴ´�.
	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept; // friend ���� ��ü�� ������Ÿ�� ����, �ٸ� ������ swap �Լ� ������ �� �� �ʿ䰡 ����.



	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);



	void nonThrowingFunc() noexcept { } // ���� �ͼ����� ������ �ʴ� �Լ��� noexcept Ű���尡 �ٴ´�.
	// ���⼭ �ͼ����� �߻��ϸ� ���α׷��� �����.

private:
//	bool inRange(size_t value, size_t upper) const; // �ش� value �� upper ���� �����ϴ� �� Ȯ���ϴ� �޼���
	/* �޼��� ���Ǻκп��� �ڵ��ߺ��� ���� �Ͼ�Ƿ�, inRange �޼��� ��� Ȯ�ε� �ϰ� �ͼ��ǵ� ������ �޼��带 ���� �����. */

	void verifyCoordinate(size_t x, size_t y) const; // ��ǥ���� ��ȿ���� Ȯ���ϰ� �ͼ����� ������ ���� �޼���


	// �̵� �ǹ̷п� ���� ���� �޼���
	void cleanup() noexcept; // �Ҹ��ڿ� �̵� ���� �����ڿ��� ���
	void moveFrom(Spreadsheet& src) noexcept; // ���� ��ü�� ��� ������ ��� ��ü�� �̵���Ų ��, ���� ��ü�� ����



	// ����Ʈ ������ �߰�. ����ڰ� ����Ʈ �����ڸ� ����� ���� ���� ������, �̸� private ������ �����Ѵ�.
	Spreadsheet() = default; // �����Ϸ��� �ڵ����� ������ �ִ� ���� ����ϰڴ�.


	size_t mWidth;
	size_t mHeight;
	SpreadsheetCell** mCells = nullptr; // SpreadsheetCell �� �ּҸ� ����Ų��, �ּ��� �ּҸ� �����Ѵ�.

	std::string mName;
};

