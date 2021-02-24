#pragma once
#include <cstddef> // size_t Ÿ�� ��뿡 �ʿ�
#include "3_SpreadsheetCell.h" // ������ spreadsheetCell Ÿ���� 2���� �迭�� �����
#include <string>
#include <iostream>


class Spreadsheet
{
public:

	// ����Ʈ �μ� ����
	Spreadsheet(size_t width = 100, size_t height = 100); // �޼��带 �����ϴ� �ڵ忡���� ��������.
	~Spreadsheet();
	
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet& operator=(const Spreadsheet& rhs);

	Spreadsheet(Spreadsheet&& src) noexcept;
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;

	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;


	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	
	// const �����ε� => ������ �̸��� �޼��尡 const ���η� ���еȴ�.
	SpreadsheetCell& getCellAt(size_t x, size_t y); // non-const ��ü�� �� non-const �޼��带 ȣ��
	const SpreadsheetCell& getCellAt(size_t x, size_t y) const; // const ��ü�� �� const �޼��带 ȣ��
	// ���ϵ� const ��ü ���۷����� �����Ѵ�.


	void nonThrowingFunc() noexcept { }

private:

	void verifyCoordinate(size_t x, size_t y) const;

	void cleanup() noexcept;
	void moveFrom(Spreadsheet& src) noexcept;

	Spreadsheet() = default;


	size_t mWidth;
	size_t mHeight;
	SpreadsheetCell** mCells = nullptr; // SpreadsheetCell �� �ּҸ� ����Ų��, �ּ��� �ּҸ� �����Ѵ�.

	std::string mName;
};

