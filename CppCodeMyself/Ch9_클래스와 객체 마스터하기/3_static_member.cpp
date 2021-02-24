#include <iostream>

using namespace std;

class Slime
{
public:
	// ���� ������ ����� ��ü ���� ������ �ƴ� Ŭ���� ���� �����̴ϱ�, �����ڿ��� �ʱ�ȭ �� �� ����.
	Slime() = default;

	static int mSize;
	static void setSize(int size);
	static void setColor(char color);

private:
	static char mColor;
	int level;
};


/* static �޼���� Ư����ü�� �������� �����Ƿ� non-static ����� ������ �� ����.
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