#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	SpreadsheetCell myCell(9), anotherCell, otherCell;
	// myCell ��ü�� ���� anotherCell ��ü�� �����Ѵ�
	// anotherCell �� ���� ���� �����ڰ� myCell �� �μ��� �޾Ҵ�.
//	anotherCell = myCell; // ����, copy �� �ƴϴ�. ����, assign �̴�!

	// ���� ����� �� ������ ���� ����
	anotherCell.operator=(myCell);

	cout << anotherCell.getValue() << endl;

	otherCell = anotherCell = myCell; // ���� �����ڴ� ���� �� ����� �����Ѵ�.
}