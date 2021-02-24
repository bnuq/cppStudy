#pragma once

#include <cstddef>
#include "Spreadsheet.h"
#include "SpreadsheetCell.h"


/* Spreadsheet �� ��ø Ŭ������ ���Ǹ� �ٸ� ��� ���Ͽ� ������ �ۼ�. 
Impl Ŭ������ ���ǰ� �ʿ��� ��, �����Ϸ��� �ڵ����� �� ��������� ã�´�? 
Spreadsheet �� ��ø Ŭ�����̹Ƿ� :: �����ڸ� �̿��Ͽ� �� �Ҽ��� ��Ȯ�� ������. */
class Spreadsheet::Impl // ��ø Ŭ�������� �˸�.
{
public: // public method, �������̽��� �������̽� Ŭ������ �����ϴ�.
	Impl(const SpreadsheetApplication& theApp,
		size_t width, size_t height);
	Impl(const Impl& src); // ���� ������
	~Impl();
	Impl& operator=(const Impl& rhs); // ���� ������

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	size_t getId() const;


	/* Spreadsheet::Impl Ŭ������ Spreadsheet Ŭ������ private ������ ����. �ܺο��� Ŭ���� ��ü�� ���� �Ұ���. 
	�׷��� �ܺ��Լ� swap �� firend ������ �� ����. => ���� private �޼��忡 swap �� �߰�. */


private: // ���� Spreadsheet Ŭ������ ������ �ִ� non-public ������ ���, �޼��带 ������ �ִ�.
	void verifyCoordinate(size_t x, size_t y) const;
	void swap(Impl& other) noexcept; // friend swap() �� ����� �߰��� �޼���. �ͼ����� �߻����� �ʴ� noexcept
	// ��ø Ŭ����������, �Ű������� ���� ���� Spreadsheet:: �� �ʿ���� �׳� Ŭ���� �̸��� ��� �ȴ�.


	// C++�� ������ ��� ����� ���ÿ� �ʱ�ȭ�� �����Ѵ�.
	size_t mId = 0;
	size_t mWidth = 0;
	size_t mHeight = 0;
	SpreadsheetCell** mCells = nullptr;

	const SpreadsheetApplication& mTheApp; // const ��ü�� ����Ű�� ���۷���.


	// static data member, Ŭ���� ������ ����. �⺻������ 0���� �ʱ�ȭ�ȴ�.
	static size_t sCounter;
};
