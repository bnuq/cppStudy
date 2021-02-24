#include <iostream>

using namespace std;

class Level
{
public:
	/*
	* Level 클래스는 디폴트 생성자가 없다.
	* 반드시 int 값을 하나 받아야 객체를 생성할 수 있다.
	*/
	Level(int n) { }
};

class Character
{
public:
	/*
	* 캐릭터 클래스는 디폴스 생성자가 존재한다.
	* 그리고 Level 클래스 객체를 데이터 멤버로 가진다.
	*/
	Character();
private:
	Level mLev;
};

/*
캐릭터 클래스의 디폴트 생성자는, 자신의 데이터 멤버들의 디폴트 생성자를 호출하려 한다.
근데 레벨 클래스는 디폴트 생성자가 없네??
이처럼 디폴트 생성자가 없는 경우에 생성자 이니셜라이저를 이용하여, 객체 생성에 필요한 초깃값을 넣어준다.
*/
Character::Character() : mLev(10)
{

}


// 지갑을 나타내는 클래스. 안에 동전이 들어있다.
class Wallet
{
public:
	Wallet(int coins) : mCoins(coins) { cout << "Coins = " << mCoins << endl; }
private:
	int mCoins;
};

// 가방을 나타내는 클래스. 안에 동전과 지갑이 있다.
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
* 동전 갯수를 입력받아, 가방안에 있는 동전 갯수를 초기화하고
* 가방안에 있는 동전 갯수로 가방안에 있는 지갑을 초기화한다.
* 
* 이때 초기화 되는 순서는 생성자 이니셜라이저에 쓰여진 순서가 아닌
* 클래스 정의에 나온 데이터 멤버의 순서에 의해 결정된다.
* 즉, 클래스 정의에 쓴 순서가 중요하고, 생성자 이니셜라이저에 쓰인 순서는 중요하지 않다.
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