#include <iostream>
#include <string>

using namespace std;

/* �θ� �޼��带 ȣ���ϴ� ���� */



class Book
{
public:
	virtual ~Book() = default; // �Ҹ���, virtual �� ���� ��������� �Ѵ�.
	virtual string getDescription() const { return "Book"; }
	virtual int getHeight() const { return 120; }
};

class Paperback : public Book
{
public:
	virtual string getDescription() const override {
		// �θ� Ŭ������ �޼��带 ȣ���Ѵٴ� ���� :: �����ڸ� ���� ��������� ǥ��
		return "Paperback " + Book::getDescription(); // �θ� Ŭ������ �޼��带 ȣ���ϰ�, �ڽ��� ���� ��� �߰�
	}
};

class Romance : public Paperback
{
public:
	virtual string getDescription() const override {
		return "Romance " + Paperback::getDescription(); // ���� �θ� Ŭ������ �޼��带 ȣ���ؼ� �̿�
	}
	/* Paperback Ŭ�������� getHeight() �޼��尡 ���µ�,
	�� ��� C++ �� ���� �ڵ带 ã������ �ڵ����� Ŭ���� ������ �Ž��� �ö� Ž��
	�ڵ����� Book::getHeight() �޼���� ó���ϰ� �ȴ�. */
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
	cout << novel.getDescription() << endl; // ���: "Romance Paperback Book"
	cout << book.getDescription() << endl;  // ���: "Book"
	cout << novel.getHeight() << endl;      // ���: "60"
	cout << book.getHeight() << endl;       // ���: "120"

	return 0;
}
