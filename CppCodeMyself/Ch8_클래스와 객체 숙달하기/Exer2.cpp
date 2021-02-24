#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	// 생성자에 필요한 인수는, 객체를 선언할 때 소괄호를 이용하여 넣어준다
	SpreadsheetCell aCell(9.9), anotherCell(8.8);

	// 스마트 포인터를 만들 때도 소괄호에 넣어 인수를 생성자로 전달한다
	auto smartCellPtr = make_unique<SpreadsheetCell>(7.7);

	SpreadsheetCell* cellPtr = new SpreadsheetCell(6.6);
	delete cellPtr;
	cellPtr = nullptr;


	/* 다른 생성자를 이용하여 객체를 만든다 */
	SpreadsheetCell aThird(5.5);
	SpreadsheetCell aFourth("4.4");
	auto aFifth = make_unique<SpreadsheetCell>("3.3");

	cout << aFourth.getString() << endl;
	cout << aFifth->getString() << endl;



	// 객체 배열은 디폴트 생성자가 있어야 가능하다
	SpreadsheetCell cells[3];
	SpreadsheetCell* heapCells = new SpreadsheetCell[3];
	delete heapCells;
	heapCells = nullptr;

	SpreadsheetCell cells2[3] = { SpreadsheetCell(0), SpreadsheetCell(1), SpreadsheetCell(2) }; // 배열에 들어갈 초기값을 하나씩 줄 수도 있다

	// 스택에서 디폴트 생성자 호출. 소괄호 자체가 필요없다.
	SpreadsheetCell defaultCell;
	/*
	// 왜냐하면 함수 선언과 헷갈리기 때문에. 소괄호를 생략해주어야 한다.
	SpreadsheetCell defaultCell2();
	defaultCell2.getValue(3.3);
	*/


	// 힙에서 디폴트 생성자 호출. 이때는 소괄호를 써준다
	auto defaultHeapCell = make_unique<SpreadsheetCell>();
	/*
	SpreadsheetCell* dafaultHeapCell2 = new SpreadsheetCell();
	SpreadsheetCell* dafaultHeapCell2 = new SpreadsheetCell;
	도 가능
	*/

}