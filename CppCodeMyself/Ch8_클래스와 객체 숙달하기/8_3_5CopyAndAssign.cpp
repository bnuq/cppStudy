#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;


class In
{
public:
	In() { cout << "In 의 디폴트 생성자 실행" << endl; }
	In(const In& in) { cout << "In 의 복제 생성자 실행" << endl; }
};

class Out
{
public:
	Out() { cout << "Out 의 디폴트 생성자 실행" << endl; }
	Out(const Out& out);
private:
	In mInData;
};

// 기존 메커니즘 대로, 재귀적으로 데이터 멤버의 복제 생성자를 먼저 실행하고, 나중에 자신의 복제 생성자를 실행
Out::Out(const Out& out) : mInData(out.mInData)
{
	cout << "Out 의 복제 생성자 실행" << endl;
}

/*
* 생성자 이니셜라이저에 데이터 멤버가 빠져있는 경우
* 생성자 본문으로 들어가기 전, 컴파일러는 무조건 객체 데이터 멤버들을 초기화를 시켜주고자 한다
* 그래서 컴파일러는 빠진 멤버의 디폴트 생성자를 호출하여, 초기화 작업을 처리시킨다.  ->  "In 의 디폴트 생성자 실행" 이 출력된다.
* 
* 생성자 본문을 실행하기 전, 항상 데이터 멤버 모두 초기화된 상태를 가진다.
* 
Out::Out(const Out& out)
{
	mInData = out.mInData; // 여기서는 대입 연산자가 작동하게 된다.
	cout << "Out 의 복제 생성자 실행" << endl;
}
*/

int main()
{
	SpreadsheetCell firstCell(9);

	SpreadsheetCell secondCell(firstCell); // secondCell 은 복제 생성자를 이용하여 만들어짐

	SpreadsheetCell thirdCell = firstCell; // assignment 처럼 보이지만 객체 선언문이야. 복제 생성자를 이용한다.

	SpreadsheetCell fourthCell;
	fourthCell = firstCell; // 이 경우는 이미 생성된 객체에 다른 객체 값을 덮어 씌우는, 대입문. 대입 연산자를 사용한다.



	SpreadsheetCell testCell(100); // 100 을 저장하고 있는 Cell
	string s1;
	// SpreadsheetCell 클래스의 getString( ) 메서드를 이용하여 저장하고 있는 값을 문자열로 리턴 받는다.
	/*
	함수에 인자를 넘길 때와 똑같다.
	getString( ) 이 반환하는 string 을 받기 위해
	이 main 함수에서 복제 생성자를 호출, 우변에 이름없는 임시 객체를 생성
	그리고 그 임시객체를 s1 에 덮어씌우기 위해서 대입 연산자를 호출
	이후 임시객체는 사라진다.
	
	* 즉, 함수 return 에서의 객체를 인수로 받아서 main 함수에 이름없는 객체를 만드는 데 복제 생성자를 호출
	* 임시 객체를 인수로 받아서 s1 에 값을 대입하는데 대입 연산자를 호출
	*/
	s1 = testCell.getString();
	
	// 이 경우 함수로 부터 임시객체를 만드는 데 복제 생성자가 쓰이고, 
	// 임시객체가 s2 선언문에서 초깃값으로 바로 쓰이기 때문에, s2 를 만드는 데 복제 생성자가 또 쓰인다.
	string s2 = testCell.getString();
	string s3(testCell.getString());


	/* 이동 의미론을 이용하면, getString( ) 으로부터 리턴 값을 받아올 때 복제 생성자 대신 이동 생성자를 사용한다 */



	/*
	Out 의 디폴트 생성자 실행.
	만약 Out 과 In 모두 컴파일러가 만들어준 디폴트 생성자를 사용한다면,
	데이터 멤버인 In 의 디폴트 생성자를 먼저 실행하고 그 다음 Out 의 디폴트 생성자가 실행된다.
	*/
	Out o1; 
	/*
	Out 의 복제 생성자 실행.
	만약 Out 과 In 모두 컴파일러가 만들어준 복제 생성자를 사용한다면,
	데이터 멤버인 In 의 복제 생성자를 먼저 실행하고 그 다음 Out 의 복제 생성자가 실행된다.

	직접 정의한 복제 생성자를 사용한다면,
	생성자 이니셜라이저를 이용하여 위의 메커니즘을 직접 구현해 주어야 한다.
	*/
	Out o2(o1);
}