#include "Spreadsheet.h"
#include "SpreadsheetImpl.h"
#include <utility> // std::swap() 사용


/* 인터페이스 클래스의 생성자에서 구현 클래스의 객체를 반드시 생성해주어야 한다. 
그리고 만든 구현 클래스 객체를 가리켜야 한다. */
Spreadsheet::Spreadsheet(const SpreadsheetApplication &theApp, size_t width, size_t height)
{
	// 인수를 그대로 전달, Impl 생성자를 호출하여 Impl 객체를 만든다음 그것을 unique_ptr 로 가리킴
	mImpl = std::make_unique<Impl>(theApp, width, height);
}

Spreadsheet::Spreadsheet(const Spreadsheet& src) // 복제 연산자
{
	/* Impl 클래스의 생성자를 호출하지 않고, src.mImpl unique_ptr 을 역참조한 값을 인수로 넣었다. 즉 src의 Impl 객체. 
	unique_ptr 의 복제 생성자는 가리키는 대상의 포인터가 아닌, 가리키는 대상의 레퍼런스를 인수로 받는다.
	따라서 src 객체의 mImpl 이 가리키는 Impl 객체 자체를 인수로 넘겼고, unique_ptr 복제 생성자는 이를 레퍼런스로 받는 것 
	그러면 *this 객체의 mImpl 은 *src.mImpl 객체를 복제한 객체를 만들고, 그다음에 그것을 가리키게 된다. */
	mImpl = std::make_unique<Impl>(*src.mImpl); // unique_ptr 은 한 객체를 한 포인터만 가리킨다.
}

// unique_ptr 를 썼지만 딱히 동적할당한 메모리가 없기 때문에 소멸자가 할 일이 없다. default dtor 사용
// 클래스 구현 파일, cpp 에서도 디폴트 지정이 가능하다.
Spreadsheet::~Spreadsheet() = default;



// 인터페이스 클래스의 메서드들은, 단순히 구현 클래스 Impl, 객체에 있는 동일한 이름의 메서드를 호출한다.
// 따라서 구현 클래스의 코드가 변경이 되도, 이 Spreadsheet.cpp 는 영향을 안 받는다. 컴파일 할 일이 줄어든다.
void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	mImpl->setCellAt(x, y, cell);
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	return mImpl->getCellAt(x, y);
}

size_t Spreadsheet::getId() const
{
	return mImpl->getId();
}


// Spreadsheet 대입
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) // 대입 연산자
{
	// unique_ptr 의 역참조를 이용해, Impl 클래스의 대입 연산자를 이용.
	*mImpl = *rhs.mImpl; // rhs 의 Impl 객체를 *this 의 Impl 객체에 대입한다. 직접 객체 대입, 객체 복사
	return *this;
}


// 함수 정의 시, friend 키워드는 없어도 된다.
void swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
	using std::swap;

	// std::swap() 를 unique_ptr 에 대해서도 쓸 수 있다.
	swap(first.mImpl, second.mImpl); // 두 포인터가 저장하고 있는 값을 교환
}
