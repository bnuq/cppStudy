#include "SpreadsheetCell.h" // 먼저 클래스 정의 코드를 불러오고
#include <iostream>
using namespace std;


// Cell 의 value 를 출력해주는 함수
void printCell(const SpreadsheetCell& cell)
{
	cout << cell.getValue() << endl;
}



/*
// 디폴트 생성자
명시적 디폴트 생성자가 존재하기 때문에, 이 코드는 없어도 무관한다.
SpreadsheetCell::SpreadsheetCell()
{
	// mValue = 0; 데이터 멤버 선언과 동시에 초기화하고 있으니 이 문장도 필요없다.
}
*/



// 생성자
// 생성자 이니셜라이저를 이용하여 데이터 멤버의 초깃값을 설정
// 만약 데이터 멤버에 대한 디폴트 생성자가 정의돼 있다면, 데이터 멤버가 생성될 때 디폴트 생성자가 호출되기 때문에, 생성자 이니셜라이저에 쓰지 않아도 된다.
SpreadsheetCell::SpreadsheetCell(double initialValue) : mValue(initialValue)
{
//	setValue(initialValue); // 생성자 내에서 메서드를 이용한다
}
/*
SpreadsheetCell::SpreadsheetCell(string_view initalValue)
{
	setString(initalValue); // 역시나 메서드를 이용하여 데이터 멤버 값을 설정한다

	* 한 생성자에서 다른 생성자를 호출할 수도 있다
	* 인수로 받은 string_view 를 double 로 바꾼 뒤, double 을 인수로 받는 생성자를 호출
	SpreadsheetCell(stringToDouble(initalValue));

	* 근데 이렇게 하면 의도한 대로 실행이 안된다
	* 그냥 내부적으로 이름없는 임시객체가 생성됐다가 사라질 뿐
	* 이걸 하고 싶다면 위임 생성자, delegating constructor 를 사용해야 한다
	
}
*/
/*
위임 생성자를 사용하는 경우,
반드시 생성자 이니셜라이저에서 다른 생성자를 호출해야 하며
그것 외에 다른 것이 생성자 이니셜라이저에 있으면 안된다.
*/
// 인수로 받은 string_view 를 double 로 바꾼 뒤, double 값을 인수로 받는 다른 생성자를 호출
// string_view 생성자가 할 일을 다른 생성자에 넘겼으니, 위임 생성자
// 실제로 일을 한 double 생성자는, 타깃 생성자
// 타깃 생성자가 리턴할 후에, 위임 생성자의 코드가 진행된다.
SpreadsheetCell::SpreadsheetCell(string_view initialValue) : SpreadsheetCell(stringToDouble(initialValue))
{

}

/*
복제 생성자
src 의 mValue 값을, this 의 mValue 의 초깃값으로 한다.
*/
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) : mValue(src.mValue) { }



// 복사 대입 연산자
SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	// 대입 연산자의 경우, 자기 자신을 대입할 수 있으므로 그 경우를 반드시 고려한다
	if (&rhs == this) return *this;

	// 복사 대입 연산자 이므로, 자신의 데이터 멤버들에 대해서도 모두 복사 대입 연산자를 호출한다
	mValue = rhs.mValue;

	return *this; // 대입한 결과를 리턴
}





// 그 다음에 클래스의 메서드를 정의한다

void SpreadsheetCell::setValue(double inValue)
{
	mValue = inValue;
	/*
	// mValue 를 설정하고 나서 그 값을 출력하고 싶다
	printCell(*this); // this 포인터로 현재 객체를 함수의 인수로 넘긴다
	*/
}
double SpreadsheetCell::getValue() const
{
	return mValue;
}

// string_view 값은 값 복사로 인수를 넘긴다
void SpreadsheetCell::setString(string_view inString)
{
	mValue = stringToDouble(inString); // 헬퍼 메서드를 이용한다
}
string SpreadsheetCell::getString() const
{
	return doubleToString(mValue); // 역시 헬퍼 메서드를 이용한다
}

string SpreadsheetCell::doubleToString(double inValue) const
{
	return to_string(inValue); // to_string 함수 이용
}
double SpreadsheetCell::stringToDouble(string_view inString) const
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
