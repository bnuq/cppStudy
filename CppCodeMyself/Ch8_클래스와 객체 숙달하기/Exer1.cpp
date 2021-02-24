#include "SpreadSheetCell.h"
#include <iostream>

using namespace std;

/*
* Cell �� value �� ������ִ� �Լ�
* �ܺ� �ҽ��ڵ忡�� ���ǵƴٴ� �ǹ̷� extern Ű���带 �־���.
*/
extern void printCell(const SpreadsheetCell& cell);

int main()
{
	/* ���ÿ� ������ ��ü */
	SpreadsheetCell sheet1, sheet2;

	// ������ ����� �� ��ü�� ���� �����Ѵ�
	sheet1.setValue(9.9);
	sheet2.setValue(99.9);

	sheet1.setString("88.88");
	cout << sheet2.getString() << endl;


	/* ���� ������ ��ü */
	SpreadsheetCell* sheetPtr = new SpreadsheetCell(); // new ������ �̿�
	sheetPtr->setValue(77.7);
	cout << sheetPtr->getString() << endl;
	printCell(*sheetPtr);

	delete sheetPtr;
	sheetPtr = nullptr;


	/* ����Ʈ �����͸� �̿� */
	auto smartSheetPtr = make_unique<SpreadsheetCell>();
	/*
	������ �����ϴ�
	���� �Ҵ��� �ּҸ� ����Ʈ ������ ������ �μ��� �ִ´�.
	unique_ptr<SpreadsheetCell> smartSheetPtr(new SpreadsheetCell());
	*/
	smartSheetPtr->setValue(66.6);
	cout << smartSheetPtr->getString() << endl;
	printCell(*smartSheetPtr);

}