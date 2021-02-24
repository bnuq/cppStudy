#include <iostream>
#include <string>
#include <vector>

#include "2_Spreadsheet.h"

using namespace std;

// 생성자
Spreadsheet::Spreadsheet(size_t width, size_t height)
	: mWidth(width), mHeight(height) // 데이터 멤버 메모리를 확보하면서 초기화
{
	cout << "일반 인수를 받는 생성자 호출" << endl;

	// 생성자에서 객체를 생성하면서, 객체에 필요한 메모리를 동적 할당한다.

	mCells = new SpreadsheetCell * [mWidth]; 
	/* mCells 는 전체 집합을 가리킨다.
	* 전체 집합은 SpreadsheetCell 주소들의 집합.
	* 각 SpreadsheetCell 주소들은 각자의 SpreadsheetCell 배열을 가리킨다.
	*/

	for (size_t i = 0; i < mWidth; i++) { // 전체 배열에서 각 요소에 접근
		mCells[i] = new SpreadsheetCell[mHeight]; // 각 요소는 각자의 SpreadsheetCell 배열을 할당해, 가리킨다.
	}
}



// 소멸자
Spreadsheet::~Spreadsheet() // 객체가 소멸할 때 소멸자 호출, 생성자에서 동적 할당한 메모리를 해제한다
{
	cout << "소멸자 호출" << endl;

	// 먼저 mCells 내 각 원소들이 가리키고 있는 SpreadsheetCell 배열을 해제해야 한다
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}

	// 각 요소들을 해제했다면 전체 배열을 해제한다
	delete[] mCells;
	mCells = nullptr; // 해제한 포인터는 nullptr 를 가리키는 것이 안전하다.
}



// 복제 생성자
/* 컴파일러에서 복제 생성자를 사용하면
* 포인터 타입에 대해서, 얕은 복제, 비트 단위 복제를 진행.
* 깊은 복사가 아닌 같은 대상을 가리키게 되는 현상이 발생한다.
* 그래서 깊은 복사를 하도록 만들어야 한다.
*/
Spreadsheet::Spreadsheet(const Spreadsheet& src)
	: Spreadsheet(src.mWidth, src.mHeight) // 위임 생성자를 이용. src 의 데이터 멤버를 이용하여 일단 메모리를 동적할당한다.
{
	cout << "복제 생성자 호출" << endl;

	// 이후 깊은 복사 진행
	// 위임 생성자 덕분에, this->mCells 는 초기화되지 않고 그냥 만들어져 있는 상태.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j]; // SpreadsheetCell 의 대입 연산자를 이용하여, 값을 하나씩 복사한다.
		}
	}
}



// 대입 연산자
/*
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	// 대입 연산자는 자기 자신을 대입하는 상황을 가장 먼저 체크한다.
	if (this == &rhs) return *this; // 포인터 리턴이 아니고 레퍼런스 리턴


	* 대입 연산자는 이미 만들어진 객체에 다른 객체 값을 대입하는 것이므로
	* 기존 객체에 있던 데이터 멤버를 지우는 과정이 필요하다.
	*
	// 기존 메모리 해제
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;


	// 새로운 메모리 할당
	mWidth = rhs.mWidth;
	mHeight = rhs.mHeight;

	mCells = new SpreadsheetCell* [mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}


	// 데이터를 복사한다
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = rhs.mCells[i][j]; // SpreadsheetCell 의 대입 연산자를 이용하여, 값을 하나씩 복사한다.
		}
	}


	return *this;

문제점 = 하는일이 많아서 문제가 생길 여기가 크다. 예를 들어 익셉션이 발생하는 경우, 과정을 건너뛰어 버린다.
}
*/
/* 정상적으로 처리를 하거나, 
* 익셉션이 중간에 발생하는 경우 this 객체를 건드리지 않게 하고 싶다. 그래야 객체가 비정상적인 상태가 되지 않는다.
* `복제 후 맞바꾸기` 패턴을 이용하여, 대입 연산자를 만들자.
*/
void swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
	// 실제로 데이터 멤버를 교체하는 작염은 <utility> 에서 제공하는 std::swap 함수를 이용한다.

	using std::swap; // 여기서 부터 그냥 swap 이 std::swap 을 뜻한다는 뜻.

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells); // 두 포인터가 가리키던 주소값을 교환해준다.
}


// 복제 후 맞바꾸기 패턴을 적용한 대입 연산자
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	cout << "복제 대입 연산자 호출" << endl;

	// 대입 연산자는 항상 먼저 자기 자신을 대입하는 지 확인
	if (this == &rhs) return *this;

	// 복사하는 과정에서 어떤 익셉션이 발생할 수 있으니 임시 인스턴스에 우선 인자를 복사한다.
	Spreadsheet temp(rhs); // 복제 생성자를 이용해서 temp 객체에 rhs 객체 값 복제
	
	// 임시 객체에 복사하는 과정에 아무 문제가 없었다면, 원본 객체와 임시 객체의 데이터 멤버를 교체. 
	// 대입하고자 하는 객체를 먼저 만들어 놓고, 아무 문제 없이 잘 만들어졌다면 원본객체가 만들어진것을 가리키게 한다?
	swap(*this, temp); // swap 함수가 noexcept 이므로 익셉션이 발생하지 않는다.
	return *this;
}



// 이동 생성자 => 객체를 복사하지 않고 이동시킨다...
/*
Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept // 익셉션을 발생시키지 않는다.
{
	* 생성자 이니셜라이저가 없으니까...
	기본 타입 멤버 변수는 그냥 만들기만 하고 초기화는 안한다.
	객체 멤버 변수들은 디폴트 생성자를 호출한다. ~ 그 객체의 디폴트 생성자가 존재한다면.
	이로써 일단 객체를 만들어 낸다.
	*
	std::cout << "이동 생성자 호출" << std::endl;
	moveFrom(src); // 이후 moveFrom 헬프 메서드를 이용, src 의 데이터 소유권을 가져오고 src 는 빈 객체로 만들어 버린다.
}
*/
/*
* 데이터 멤버에 접근하는 메서드가 swap() 과 moveFrom() 2개다.
* 만약 데이터 멤버를 추가하거나 수정한다면 2개의 함수를 모두 수정해야 한다 => 번거롭다.
* 하나만 사용하는 것이 유리하므로, 이동 생성자와 이동 대입 연산자를 모두 swap() 메서드만 이용하여 구현하자.
*/
// swap 을 이용한 이동 생성자
Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept
	: Spreadsheet() // 위임 생성자, 디폴트 생성자를 이용해 먼저 객체를 만든다.
{
	cout << "이동 생성자 호출" << endl;

	swap(*this, src); // src 와 *this 객체의 데이터를 교환. src 는 우측값이라 이후 사라질 것이다.
}




// 이동 대입 연산자
/*
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{
	// 대입 연산자는 항상 자기 자신을 대입하는 것인지를 먼저 확인한다.
	if (this == &rhs) return *this;

	cleanup(); // *this 가 가지고 있던 기존 메모리를 해제. *this 객체를 빈 객체가로 만들어 버린다.

	moveFrom(rhs); // rhs 로 부터 데이터를 가져오고 rhs 는 빈 객체로 만들어버려

	return *this;
}
*/
// swap 을 이용한 이동 대입 연산자
// 역시 복사 후 맞바꾸기 패턴을 이용
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{
	cout << "이동 대입 연산자 호출" << endl;

	// rhs 는 우측값 레퍼런스 이므로, rhs 객체로 임시 인스턴스를 복사 생성을 하려 한다면 이동 생성자를 이용하는 것이 효율적이다.
	Spreadsheet temp(std::move(rhs)); // std::move() 를 이용해 rhs 를 우측값으로 변경

	swap(*this, temp); // 복사한 임시 인스턴스와 *this 객체를 교환
	return *this;
}

// 메서드
void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell) // 셀에 값을 쓰는 함수
{
//	if (!inRange(x, mWidth) || !inRange(y, mHeight)) throw out_of_range(""); // 접근하는 좌표값이 범위를 벗어나면, out_of_range 예외를 던진다
	/* 이와 같은 코드 중복이 일어나지 않게 코드를 짜야 한다. */
	
	verifyCoordinate(x, y); // 여기서 익셉션이 발생하지 않으면 다음 문장으로 이동
	// 중복되는 작업은 해당 작업을 하는 메서드를 호출해서 해결

	mCells[x][y] = cell; // cell 은 복사 대상인 SpreadsheetCell
	/* SpreadsheetCell 복사 대입 연산자를 이용하여 객체에 있는 값을 복사해온다. */
}
SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
//	if (!inRange(x, mWidth) || !inRange(y, mHeight)) throw out_of_range(""); 

	verifyCoordinate(x, y); // 여기서 익셉션이 발생하지 않으면 다음 문장으로 이동
	// 중복되는 작업은 해당 작업을 하는 메서드를 호출해서 해결

	return mCells[x][y]; // 해당 좌표에 있는 SpreadsheetCell 레퍼런스를 리턴한다. => 수정할 수 있게.
}



// 헬퍼 메서드
void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
	if ((x >= mWidth) || (y >= mHeight)) throw std::out_of_range(""); // x 와 y 는 배열에 접근하는 index 값이니까, 전체 갯수와 같은 값을 가지면 안된다.
}


void Spreadsheet::cleanup() noexcept
{
	for (size_t i = 0; i < mWidth; i++)
		delete[] mCells[i]; // mCells 의 각 원소들이 가리키는 SpreadsheetCell 배열을 해제

	delete[] mCells; // SpreadsheetCell* 배열도 해제
	mCells = nullptr;
	mWidth = mHeight = 0; // mCells 전체가 해제되었으므로, 너비와 높이도 0 값으로 만든다.
}


void Spreadsheet::moveFrom(Spreadsheet& src) noexcept // src 객체의 데이터를 *this 객체로 넘기는 함수
{
	// 데이터에 대한 얕은 복제, 소유권을 *this 객체로 넘긴다
	// 아래 3 멤버 변수의 경우, 기본타입이기 때문에 얕은 복사, 대입을 통해 이동함.
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	mCells = src.mCells; // this->mCells 가 src 객체의 mCells 가 가리키던 배열을 가리키도록 한다. 같은 주소를 저장.


	// 객체 데이터 멤버의 경우 std::move() 를 이용하여 이동시켜야 한다.
	// std::string mName 이라는 데이터 멤버가 있다면, std::move( ) 를 이용하여 이동시킨다.
	mName = std::move(src.mName);


	// 데이터 소유권이 *this 로 넘어갔으므로 src 의 데이터를 제거, src 를 리셋해야 한다.
	src.mWidth = 0;
	src.mHeight = 0;
	src.mCells = nullptr;
	// src.mName 을 초기화하는 과정은 없네???



	/* src 객체의 mCells 가 가리키던 배열을 *this 객체의 mCells 가 이제 가리키고 있으니
	src 의 mCells 가 아무것도 가리키지 않도록, nullptr 를 대입한다.
	그러면 src 의 소멸자가 호출될 때, 기존에 src 가 가지고 있던 mCells 가 해제되지 않게 된다.
	*/
}





Spreadsheet createObject()
{
	return Spreadsheet(2, 3);
}









int main()
{
	Spreadsheet finalScore(1,1);

	finalScore.setCellAt(0, 0, SpreadsheetCell(3.3));

	Spreadsheet test(std::move(finalScore));
	std::cout << (test.getCellAt(0, 0)).getValue() << std::endl;


	vector<Spreadsheet> vec;
	for (int i = 0; i < 2; i++) {
		cout << "Iteration " << i << endl;
		vec.push_back(Spreadsheet(100, 100)); 
		/*
		* Spreadsheet 생성자 이용 해서 Spreadsheet(100,100) 임시 객체를 만들고
		* 이동 생성자를 이용하여 vector 에 방금만든 임시 객체를 이동시킨다.
		* 
		* vector 의 크기가 재조정되는 경우, 기존의 vector 에서 새로운 vector 로 객체를 이동시켜야 한다.
		* 그래서 이 경우에도 이동 생성자가 호출된다.		
		*/
		cout << endl;
	}

	
	Spreadsheet s(2, 3);

	// createObject() 함수로 만들어진 리턴 값, 임시 객체를 이동 대입 연산자가 `우측값 레퍼런스`로 받아
	// 우측값 레퍼런스가 없었으면 임시 결과를 받는 임시 객체를 복사 생성자를 이용해서 만들어야 했을 거다.
	// 근데 우측값 레퍼런스를 이용하는 이동 대입 연산자가 있으니까, 함수 리턴 값을 그냥 그대로 우측값으로 이용.
	s = createObject(); // 이동 대입 연산자를 이용해서, s 에 함수 리턴 값을 대입
	// 이동 대입 연산자 내에서, 이동 생성자를 호출


	Spreadsheet s2(5, 6);
	s2 = s; // 복사 대입 연산자 이용, 다른 객체의 값 대입.
	// 복사 대입 연산자 내에서, 복사 생성자를 호출
	// 그리고 복제 생성자는 일반 생성자를 호출

	Spreadsheet s3 = createObject(); // 이동 생성자를 이용. 함수 리턴 값을 이용해서 새로운 객체 생성
	
}

/* 이동 의미론을 구현하지 않으면,
이동 생성자와 이동 대입 연산자를 호출하는 부분은
모두 복제 생성자와 복제 대입 연산자로 대체된다.
*/