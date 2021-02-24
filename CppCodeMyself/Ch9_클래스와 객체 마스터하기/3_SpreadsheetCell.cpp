#include "3_SpreadsheetCell.h" // 먼저 클래스 정의 코드를 불러오고
#include <iostream>
using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue) : mValue(initialValue)
{
}
SpreadsheetCell::SpreadsheetCell(string_view initialValue) 
	: SpreadsheetCell(stringToDouble(initialValue))
{
}


void SpreadsheetCell::set(double inValue)
{
	mValue = inValue;
}
// string_view 값은 값 복사로 인수를 넘긴다
void SpreadsheetCell::set(string_view inString)
{
	mValue = stringToDouble(inString); // 헬퍼 메서드를 이용한다
}

// const 메서드는 메서드 구현시에도 const 키워드를 반드시 적는다.
// const 메서드 안에서는 각 데이터 멤버들을 다룰 때, 데이터 멤버에 대한 const 레퍼런스를 가진 것처럼 행동한다.
// mutable 데이터 멤버는 변경이 가능하다
/*
inline 키워드 사용, 인라인 메서드로 만들었다.
이 메서드를 호출하는 부분에 메서드 본문을 그대로 집어 넣는다.
*/
inline double SpreadsheetCell::getValue() const
{
	mNumAccesses++;
	return mValue;
}
inline string SpreadsheetCell::getString() const
{
	mNumAccesses++;
	return doubleToString(mValue); // 역시 헬퍼 메서드를 이용한다
}



/* static 메서드를 구현할 때, static 키워드를 생략해도 된다.
* 단 static 메서드는 특정 객체에 대해 호출되지 않으므로 this 포인터를 사용할 수 없다.
* 또한 특정 객체에 속하지 않았으므로, non-static 데이터 멤버를 사용할 수 없다. static 데이터 멤버에만 접근할 수 있다. 
* 같은 클래스 안에서는 static 메서드를 일반 함수처럼 호출할 수 있다.
* 
*/
string SpreadsheetCell::doubleToString(double inValue)
{
	return to_string(inValue); // to_string 함수 이용
}
double SpreadsheetCell::stringToDouble(string_view inString)
{
	// string_view 의 data( ) 메서드. 가리키는 const char* 를 반환한다.
	return strtod(inString.data(), nullptr); // strtod 함수 이용
}
/*
* strtod 함수
* double strtod( const char* nptr, char** endptr );
* 숫자로 구성된 문자열 nptr 를 double 타입으로 반환
* 계산할 수 없는 문자를 발견하면 그 위치 주소를 endptr 이 가리키도록 설정
*/



int main()
{
	// 클래스 밖에서 정적 멤버 함수를 호출할 때는 클래스 이름 :: 를 이용하여 접근한다
	SpreadsheetCell::test_static();


	// 일반 객체는 const 메서드, non-const 메서드 모두 호출 가능
	SpreadsheetCell tempCell1(9);
	tempCell1.set(8); // non-const 메서드 호출
	cout << tempCell1.getValue() << endl; // const 메서드 호출

	// 객체를 const 로 선언, const 메서드만 호출 가능
	const SpreadsheetCell tempCell2(99);
//	tempCell2.setValue(88); // non-const 메서드 호출 불가능
	cout << tempCell2.getValue() << endl; // const 메서드 호출

	// const 객체에 대한 레퍼런스, const 메서드만 호출 가능
	const SpreadsheetCell& refCell = tempCell1;
//	refCell.setValue(88);
	cout << refCell.getValue() << endl; // const 메서드 호출

	// const 객체에 대한 포인터, 
	const SpreadsheetCell* ptrCell = &tempCell1;
//	ptrCell->setValue(88);
	cout << ptrCell->getValue() << endl;

	// 포인터가 const 한거면 상관 없지만
	SpreadsheetCell* const ptrCell2 = &tempCell1;
	ptrCell2->set(77);
	cout << ptrCell2->getValue() << endl;

}