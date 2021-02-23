#include "Spreadsheet.h"
#include "SpreadsheetImpl.h"
#include <utility> // std::swap() ���


/* �������̽� Ŭ������ �����ڿ��� ���� Ŭ������ ��ü�� �ݵ�� �������־�� �Ѵ�. 
�׸��� ���� ���� Ŭ���� ��ü�� �����Ѿ� �Ѵ�. */
Spreadsheet::Spreadsheet(const SpreadsheetApplication &theApp, size_t width, size_t height)
{
	// �μ��� �״�� ����, Impl �����ڸ� ȣ���Ͽ� Impl ��ü�� ������� �װ��� unique_ptr �� ����Ŵ
	mImpl = std::make_unique<Impl>(theApp, width, height);
}

Spreadsheet::Spreadsheet(const Spreadsheet& src) // ���� ������
{
	/* Impl Ŭ������ �����ڸ� ȣ������ �ʰ�, src.mImpl unique_ptr �� �������� ���� �μ��� �־���. �� src�� Impl ��ü. 
	unique_ptr �� ���� �����ڴ� ����Ű�� ����� �����Ͱ� �ƴ�, ����Ű�� ����� ���۷����� �μ��� �޴´�.
	���� src ��ü�� mImpl �� ����Ű�� Impl ��ü ��ü�� �μ��� �Ѱ��, unique_ptr ���� �����ڴ� �̸� ���۷����� �޴� �� 
	�׷��� *this ��ü�� mImpl �� *src.mImpl ��ü�� ������ ��ü�� �����, �״����� �װ��� ����Ű�� �ȴ�. */
	mImpl = std::make_unique<Impl>(*src.mImpl); // unique_ptr �� �� ��ü�� �� �����͸� ����Ų��.
}

// unique_ptr �� ������ ���� �����Ҵ��� �޸𸮰� ���� ������ �Ҹ��ڰ� �� ���� ����. default dtor ���
// Ŭ���� ���� ����, cpp ������ ����Ʈ ������ �����ϴ�.
Spreadsheet::~Spreadsheet() = default;



// �������̽� Ŭ������ �޼������, �ܼ��� ���� Ŭ���� Impl, ��ü�� �ִ� ������ �̸��� �޼��带 ȣ���Ѵ�.
// ���� ���� Ŭ������ �ڵ尡 ������ �ǵ�, �� Spreadsheet.cpp �� ������ �� �޴´�. ������ �� ���� �پ���.
void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	mImpl->setCellAt(x, y, cell);
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	return mImpl->getCellAt(x, y);
}

size_t Spreadsheet::getId() const
{
	return mImpl->getId();
}


// Spreadsheet ����
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) // ���� ������
{
	// unique_ptr �� �������� �̿���, Impl Ŭ������ ���� �����ڸ� �̿�.
	*mImpl = *rhs.mImpl; // rhs �� Impl ��ü�� *this �� Impl ��ü�� �����Ѵ�. ���� ��ü ����, ��ü ����
	return *this;
}


// �Լ� ���� ��, friend Ű����� ��� �ȴ�.
void swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
	using std::swap;

	// std::swap() �� unique_ptr �� ���ؼ��� �� �� �ִ�.
	swap(first.mImpl, second.mImpl); // �� �����Ͱ� �����ϰ� �ִ� ���� ��ȯ
}
