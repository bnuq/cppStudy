#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	SpreadsheetCell myCell(9), anotherCell, otherCell;
	// myCell 객체의 값을 anotherCell 객체에 대입한다
	// anotherCell 의 복사 대입 연산자가 myCell 을 인수로 받았다.
//	anotherCell = myCell; // 복제, copy 가 아니다. 대입, assign 이다!

	// 다음 문장과 위 문장은 뜻이 같다
	anotherCell.operator=(myCell);

	cout << anotherCell.getValue() << endl;

	otherCell = anotherCell = myCell; // 대입 연산자는 연산 한 결과를 리턴한다.
}