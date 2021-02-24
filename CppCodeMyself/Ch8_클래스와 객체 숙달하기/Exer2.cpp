#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	// �����ڿ� �ʿ��� �μ���, ��ü�� ������ �� �Ұ�ȣ�� �̿��Ͽ� �־��ش�
	SpreadsheetCell aCell(9.9), anotherCell(8.8);

	// ����Ʈ �����͸� ���� ���� �Ұ�ȣ�� �־� �μ��� �����ڷ� �����Ѵ�
	auto smartCellPtr = make_unique<SpreadsheetCell>(7.7);

	SpreadsheetCell* cellPtr = new SpreadsheetCell(6.6);
	delete cellPtr;
	cellPtr = nullptr;


	/* �ٸ� �����ڸ� �̿��Ͽ� ��ü�� ����� */
	SpreadsheetCell aThird(5.5);
	SpreadsheetCell aFourth("4.4");
	auto aFifth = make_unique<SpreadsheetCell>("3.3");

	cout << aFourth.getString() << endl;
	cout << aFifth->getString() << endl;



	// ��ü �迭�� ����Ʈ �����ڰ� �־�� �����ϴ�
	SpreadsheetCell cells[3];
	SpreadsheetCell* heapCells = new SpreadsheetCell[3];
	delete heapCells;
	heapCells = nullptr;

	SpreadsheetCell cells2[3] = { SpreadsheetCell(0), SpreadsheetCell(1), SpreadsheetCell(2) }; // �迭�� �� �ʱⰪ�� �ϳ��� �� ���� �ִ�

	// ���ÿ��� ����Ʈ ������ ȣ��. �Ұ�ȣ ��ü�� �ʿ����.
	SpreadsheetCell defaultCell;
	/*
	// �ֳ��ϸ� �Լ� ����� �򰥸��� ������. �Ұ�ȣ�� �������־�� �Ѵ�.
	SpreadsheetCell defaultCell2();
	defaultCell2.getValue(3.3);
	*/


	// ������ ����Ʈ ������ ȣ��. �̶��� �Ұ�ȣ�� ���ش�
	auto defaultHeapCell = make_unique<SpreadsheetCell>();
	/*
	SpreadsheetCell* dafaultHeapCell2 = new SpreadsheetCell();
	SpreadsheetCell* dafaultHeapCell2 = new SpreadsheetCell;
	�� ����
	*/

}