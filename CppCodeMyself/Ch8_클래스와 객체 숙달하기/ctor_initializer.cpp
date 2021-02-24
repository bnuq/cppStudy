#include <iostream>

using namespace std;

class Level
{
public:
	/*
	* Level Ŭ������ ����Ʈ �����ڰ� ����.
	* �ݵ�� int ���� �ϳ� �޾ƾ� ��ü�� ������ �� �ִ�.
	*/
	Level(int n) { }
};

class Character
{
public:
	/*
	* ĳ���� Ŭ������ ������ �����ڰ� �����Ѵ�.
	* �׸��� Level Ŭ���� ��ü�� ������ ����� ������.
	*/
	Character();
private:
	Level mLev;
};

/*
ĳ���� Ŭ������ ����Ʈ �����ڴ�, �ڽ��� ������ ������� ����Ʈ �����ڸ� ȣ���Ϸ� �Ѵ�.
�ٵ� ���� Ŭ������ ����Ʈ �����ڰ� ����??
��ó�� ����Ʈ �����ڰ� ���� ��쿡 ������ �̴ϼȶ������� �̿��Ͽ�, ��ü ������ �ʿ��� �ʱ갪�� �־��ش�.
*/
Character::Character() : mLev(10)
{

}


// ������ ��Ÿ���� Ŭ����. �ȿ� ������ ����ִ�.
class Wallet
{
public:
	Wallet(int coins) : mCoins(coins) { cout << "Coins = " << mCoins << endl; }
private:
	int mCoins;
};

// ������ ��Ÿ���� Ŭ����. �ȿ� ������ ������ �ִ�.
class Bag
{
public:
	Bag(int coins);
private:
	int bCoins;
	Wallet bWallet;
//	int bCoins;
};

/*
* ���� ������ �Է¹޾�, ����ȿ� �ִ� ���� ������ �ʱ�ȭ�ϰ�
* ����ȿ� �ִ� ���� ������ ����ȿ� �ִ� ������ �ʱ�ȭ�Ѵ�.
* 
* �̶� �ʱ�ȭ �Ǵ� ������ ������ �̴ϼȶ������� ������ ������ �ƴ�
* Ŭ���� ���ǿ� ���� ������ ����� ������ ���� �����ȴ�.
* ��, Ŭ���� ���ǿ� �� ������ �߿��ϰ�, ������ �̴ϼȶ������� ���� ������ �߿����� �ʴ�.
*/

Bag::Bag(int coins) : bWallet(bCoins), bCoins(coins)
{
	cout << "bCoins = " << bCoins << endl;
}

int main()
{
	Character man;
	Bag bag(10);
}