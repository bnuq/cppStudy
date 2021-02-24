#include "SpreadSheetCell.h"
#include <iostream>

using namespace std;

/*
* Cell 의 value 를 출력해주는 함수
* 외부 소스코드에서 정의됐다는 의미로 extern 키워드를 넣었다.
*/
extern void printCell(const SpreadsheetCell& cell);

int main()
{
	/* 스택에 생성한 객체 */
	SpreadsheetCell sheet1, sheet2;

	// 비정적 멤버는 각 객체에 대해 실행한다
	sheet1.setValue(9.9);
	sheet2.setValue(99.9);

	sheet1.setString("88.88");
	cout << sheet2.getString() << endl;


	/* 힙에 생성한 객체 */
	SpreadsheetCell* sheetPtr = new SpreadsheetCell(); // new 연산자 이용
	sheetPtr->setValue(77.7);
	cout << sheetPtr->getString() << endl;
	printCell(*sheetPtr);

	delete sheetPtr;
	sheetPtr = nullptr;


	/* 스마트 포인터를 이용 */
	auto smartSheetPtr = make_unique<SpreadsheetCell>();
	/*
	다음도 가능하다
	동적 할당한 주소를 스마트 포인터 생성자 인수로 넣는다.
	unique_ptr<SpreadsheetCell> smartSheetPtr(new SpreadsheetCell());
	*/
	smartSheetPtr->setValue(66.6);
	cout << smartSheetPtr->getString() << endl;
	printCell(*smartSheetPtr);

}