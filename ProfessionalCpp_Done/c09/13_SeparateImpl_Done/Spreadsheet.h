#pragma once

#include "SpreadsheetCell.h"
#include <memory> // ����Ʈ ������ ���

// ������ ����, ���� ����. Ŭ������ ���θ� ������ �� ���. �̷� �̸��� Ŭ������ �ִ�~ �� �� �˸�.
class SpreadsheetApplication;

class Spreadsheet // Spreadsheet Ŭ������ �������̽� Ŭ����. Ŭ���̾�Ʈ�� ����Ǵ� Ŭ����.
{
public: // ���� Ŭ������ �Ȱ��� public �޼��带 ����. 

	Spreadsheet(const SpreadsheetApplication& theApp, // ���漱���� �߱� ������ SpreadsheetApplication Ŭ������ �� �� �ִ�.
		size_t width = kMaxWidth, size_t height = kMaxHeight); // ������ ����Ʈ �μ� ���.
	Spreadsheet(const Spreadsheet& src);
	
	// ������ ��� �� unique_ptr Ÿ���� �ֱ� ������, ����� ���� �Ҹ��ڰ� �־�� �Ѵ�??
	// ����Ʈ �����͸� ����ϸ� �Ҹ��ڰ� �ڵ����� �������� �ʳ���?
	~Spreadsheet();

	Spreadsheet& operator=(const Spreadsheet& rhs); // ���� ������

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	size_t getId() const;


	/* static const data member. const static �ᵵ ��. Ŭ���� ����� ���.
	ó�� ������ ���� static const ����, Ŭ���� �������� �Ϲ� ������ ���ó�� ���.
	�Ϲ� static data member �� �ٸ��� �������� ���Ǳ��� �Ϸ�ȴ�. �ҽ��ڵ忡�� ���� �� ������ �ʿ� ����. */
	static const size_t kMaxHeight = 100;
	static const size_t kMaxWidth = 100;

	
	// �����Լ� friend ����
	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;

	
private:
	// ���� Spreadsheet.h �ʹ� �ٸ��� private ������ ����� �޼��尡 Ŭ���̾�Ʈ�� ������� �ʴ´�.

	class Impl; // Impl Ŭ������ ���� Ŭ����. ��ø Ŭ����. �̷� ��ø Ŭ������ private �� �ִٰ� ����.
	// private ������ ����Ʊ⿡, �������̽� Ŭ������ Spreadsheet Ŭ������ ������ �����ϴ�.

	// ������ ����� �̰� �ϳ��� ������.
	std::unique_ptr<Impl> mImpl; // ���� Ŭ���� ��ü�� ���� ����Ʈ ������. ���� �̵��, �긴�� ����.
};

/* Spreadsheet::Impl Ŭ������ ���Ǵ� �ٸ� ������Ͽ� �ۼ��Ѵ�. �׷��� �ȴ�. */