#include <iostream>
#include <string>

using namespace std;

/* 부모 메서드를 호출하는 패턴 */



class Book
{
public:
	virtual ~Book() = default; // 소멸자, virtual 로 직접 정의해줘야 한다.
	virtual string getDescription() const { return "Book"; }
	virtual int getHeight() const { return 120; }
};

class Paperback : public Book
{
public:
	virtual string getDescription() const override {
		// 부모 클래스의 메서드를 호출한다는 것을 :: 연산자를 통해 명시적으로 표시
		return "Paperback " + Book::getDescription(); // 부모 클래스의 메서드를 호출하고, 자신이 조금 기능 추가
	}
};

class Romance : public Paperback
{
public:
	virtual string getDescription() const override {
		return "Romance " + Paperback::getDescription(); // 역시 부모 클래스의 메서드를 호출해서 이용
	}
	/* Paperback 클래스에는 getHeight() 메서드가 없는데,
	이 경우 C++ 는 구현 코드를 찾기위해 자동으로 클래스 계층을 거슬러 올라가 탐색
	자동으로 Book::getHeight() 메서드로 처리하게 된다. */
	virtual int getHeight() const override { return Paperback::getHeight() / 2; }
};

class Technical : public Book
{
public:
	virtual string getDescription() const override {
		return "Technical " + Book::getDescription();
	}
};

int main()
{
	Romance novel;
	Book book;
	cout << novel.getDescription() << endl; // 결과: "Romance Paperback Book"
	cout << book.getDescription() << endl;  // 결과: "Book"
	cout << novel.getHeight() << endl;      // 결과: "60"
	cout << book.getHeight() << endl;       // 결과: "120"

	return 0;
}
