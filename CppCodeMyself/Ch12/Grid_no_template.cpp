/*
템플릿을 사용하지 않고 Grid 클래스 구현해보기 -> '다형성'을 이용
제네릭 게임 보드를 만들고 싶다. -> 게임 종류에 상관없이 게임의 말들을 모두 저장할 수 있는 게임보드를 만들자.
*/

#include <memory> // 스마트 포인터 사용에 필요
#include <vector>
#include <stdexcept> // std::out_of_range 사용에 필요
#include <utility> // std::swap, std::as_const 에 필요


/*
게임 보드가 GamePiece 객체를 저장하게 하고,
다양한 게임 말들은 GamePiece 클래스를 상속하게 한다.
그러면 게임 보드에 다양한 게임 말들을 저장할 수 있다.
다형성을 이용한 사례.
*/

class GamePiece // 순수 가상 메서드를 가지고 있으므로, '추상 베이스 클래스' 이다.
{
public:
	// virtual = 0; 을 가지는 순수 가상 메서드
	// GamePiece 를 상속하는 객체는 이 메서드를 반드시 재정의, 구현해야 한다.
	virtual std::unique_ptr<GamePiece> clone() const = 0; // GamePiece 객체를 복제하는 기능. 정확히는 객체를 복제하고 그 객체를 가리키는 포인터를 리턴
};

class ChessPiece : public GamePiece // 체스 말을 의미하는 객체
{
public:
	// override keyword, 베이스 클래스의 메서드를 오버라이드 한다는 것을 명시
	virtual std::unique_ptr<GamePiece> clone() const override;
};
std::unique_ptr<GamePiece> ChessPiece::clone() const
{
	// make_unique 에 *this 를 인수로 넣었고
	// make_unique 는 복제 생성자를 호출, *this 와 같은 값을 가지는 객체를 새로 생성
	// 그리고 새로 만든 객체를 가리키는 unique_ptr 를 리턴한다
	return std::make_unique<ChessPiece>(*this);
}

class GameBoard
{
public:
	explicit GameBoard(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	GameBoard(const GameBoard& src); // 복제 생성자
	virtual ~GameBoard() = default; // 가상 디폴트 소멸자
	GameBoard& operator=(const GameBoard& rhs); // 대입 연산자

	// 이동 생성자와 이동 대입 연산자를 명시적으로 디폴트로 저장한다.
	GameBoard(GameBoard&& src) = default;
	GameBoard& operator=(GameBoard&& src) = default;
	/*
	 인수로 지정한 위치의 unique_ptr 를 복제하지 않고 레퍼런스로 리턴
	 그래서 at 메서드로 접근을 하면, 배열에 있는 실제 객체에 접근이 가능하다.
	 해당 레퍼런스가 필요할 때마다 at() 을 호출해서 바로 사용하는 방식
	 레퍼런스 리턴, const 레퍼런스 리턴 2가지 모두 준비
	 */
	std::unique_ptr<GamePiece>& at(size_t x, size_t y);
	const std::unique_ptr<GamePiece>& at(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }
	
	// static data member, 객체가 아닌 클래스에 소속
	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

	friend void swap(GameBoard& first, GameBoard& second) noexcept;

private:
	size_t mWidth, mHeight;
	void verifyCoordinate(size_t x, size_t y) const;
	/*
	GamePiece 를 저장하는 부분. 객체를 직접저장하지 않고
	객체를 가리키는 unique_ptr 를 저장하는 vector,
	들의 vector 로 구성
	*/
	std::vector<std::vector<std::unique_ptr<GamePiece>>> mCells;
};
//--------------------------------------------------------------------------------------------------------------------//

GameBoard::GameBoard(size_t width, size_t height) : mWidth(width), mHeight(height)
{
	// vector / resize() 메서드 = count 만큼 배열의 원소 갯수를 조절
	mCells.resize(mWidth);
	// vector 안에 있는 vector 들도 모두 resize 해야 하기 때문에 레퍼런스를 이용한다
	// auto 는 const, & 를 잊기 때문에 추가로 적어줘야 한다
	for (auto& column : mCells)
		column.resize(mHeight);
}

// 적절한 크기의 메모리를 할당하는 작업을, 비복제 생성자에 위임한다.
GameBoard::GameBoard(const GameBoard& src) : GameBoard(src.mWidth, src.mHeight) // 생성자 이니셜라이저
{
	// 비복제 생성자로 벡터의 크기를 할당한 다음, 복제하는 작업을 수행한다.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			// vector 를 resize() 로 초기화하면, 기본값인 0 으로 초기화된다.
			if (src.mCells[i][j]) // 벡터의 요소 값이 0 이 아닐 때, 즉 이미 어떤 값을 저장하고 있을 때
				mCells[i][j] = src.mCells[i][j]->clone();
		}
	}
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight)
		// 범위를 벗어났다는 것을 알리는 except
		throw std::out_of_range("");
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
	using std::swap; // 값을 복사하지 않고 swap 해준다.

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells); // swap 을 vector 에 사용할 수 있다.
}

GameBoard& GameBoard::operator=(const GameBoard& rhs) // 대입 연산자
{
	// 자기 자신에게 대입하는 경우를 체크
	if (this == &rhs)
		return *this;

	GameBoard temp(rhs); // 임시 인스턴스에 매개변수를 복제한 뒤
	swap(*this, temp); // 임시 인스턴스와 자신을 맞 바꾸기
	return *this; // 그리고 결과인 자기자신을 리턴
}

// const unique_ptr<GamePiece> => 스마트 포인터를 const 화. 포인터가 다른 것을 가리키지 못하게 한다.
// unique_ptr<const GamePiece> => 스마트 포인터가 const 를 가리킨다. 가리키는 값을 변경하지 못함.
const std::unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

// const 레퍼런스를 리턴하는 메서드를 이용, 코드 중복을 피한다. 스콧 메이어의 const_cast() 패턴
std::unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y)
{
	/*
	as_const(*this) => 현재 객체 값을 가리키는? 나타내는? const 레퍼런스를 리턴
	이후 at 메서드를 호출해서 const unique_ptr 를 리턴한 다음
	const_cast 를 이용하여 그냥 레퍼런스 타입으로 캐스팅한다
	*/
	return const_cast<std::unique_ptr<GamePiece>&>(std::as_const(*this).at(x, y));
}


int main()
{
	GameBoard chessBoard(5, 5);
	auto pawn = std::make_unique<ChessPiece>(); // ChessPiece 객체를 하나 만들고 그걸 가리키는 스마트 포인터를 리턴. 그게 pawn

	chessBoard.at(3, 3) = std::move(pawn);
	chessBoard.at(0, 1) = std::make_unique<ChessPiece>();
	chessBoard.at(0, 1) = nullptr;
}