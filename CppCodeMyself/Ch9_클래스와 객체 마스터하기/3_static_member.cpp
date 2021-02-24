#include <iostream>

using namespace std;

class Slime
{
public:
	// 정적 데이터 멤버는 객체 단위 적용이 아닌 클래스 단위 적용이니까, 생성자에서 초기화 할 수 없다.
	Slime() = default;

	static int mSize;
	static void setSize(int size);
	static void setColor(char color);

private:
	static char mColor;
	int level;
};


/* static 메서드는 특정객체에 속해있지 않으므로 non-static 멤버에 접근할 수 없다.
*/
void Slime::setSize(int size)
{
	mSize = size;
//	level = 100;
}
void Slime::setColor(char color)
{
	mColor = color;
}
void print(const Slime& s)
{
	Slime::mSize *= 2;
	
	cout << "Size is " << mSize << endl
		<< "Color is " << mColor << endl;
}