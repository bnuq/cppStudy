/*
���ø��� ������� �ʰ� Grid Ŭ���� �����غ��� -> '������'�� �̿�
���׸� ���� ���带 ����� �ʹ�. -> ���� ������ ������� ������ ������ ��� ������ �� �ִ� ���Ӻ��带 ������.
*/

#include <memory> // ����Ʈ ������ ��뿡 �ʿ�
#include <vector>
#include <stdexcept> // std::out_of_range ��뿡 �ʿ�
#include <utility> // std::swap, std::as_const �� �ʿ�


/*
���� ���尡 GamePiece ��ü�� �����ϰ� �ϰ�,
�پ��� ���� ������ GamePiece Ŭ������ ����ϰ� �Ѵ�.
�׷��� ���� ���忡 �پ��� ���� ������ ������ �� �ִ�.
�������� �̿��� ���.
*/

class GamePiece // ���� ���� �޼��带 ������ �����Ƿ�, '�߻� ���̽� Ŭ����' �̴�.
{
public:
	// virtual = 0; �� ������ ���� ���� �޼���
	// GamePiece �� ����ϴ� ��ü�� �� �޼��带 �ݵ�� ������, �����ؾ� �Ѵ�.
	virtual std::unique_ptr<GamePiece> clone() const = 0; // GamePiece ��ü�� �����ϴ� ���. ��Ȯ���� ��ü�� �����ϰ� �� ��ü�� ����Ű�� �����͸� ����
};

class ChessPiece : public GamePiece // ü�� ���� �ǹ��ϴ� ��ü
{
public:
	// override keyword, ���̽� Ŭ������ �޼��带 �������̵� �Ѵٴ� ���� ���
	virtual std::unique_ptr<GamePiece> clone() const override;
};
std::unique_ptr<GamePiece> ChessPiece::clone() const
{
	// make_unique �� *this �� �μ��� �־���
	// make_unique �� ���� �����ڸ� ȣ��, *this �� ���� ���� ������ ��ü�� ���� ����
	// �׸��� ���� ���� ��ü�� ����Ű�� unique_ptr �� �����Ѵ�
	return std::make_unique<ChessPiece>(*this);
}

class GameBoard
{
public:
	explicit GameBoard(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	GameBoard(const GameBoard& src); // ���� ������
	virtual ~GameBoard() = default; // ���� ����Ʈ �Ҹ���
	GameBoard& operator=(const GameBoard& rhs); // ���� ������

	// �̵� �����ڿ� �̵� ���� �����ڸ� ��������� ����Ʈ�� �����Ѵ�.
	GameBoard(GameBoard&& src) = default;
	GameBoard& operator=(GameBoard&& src) = default;
	/*
	 �μ��� ������ ��ġ�� unique_ptr �� �������� �ʰ� ���۷����� ����
	 �׷��� at �޼���� ������ �ϸ�, �迭�� �ִ� ���� ��ü�� ������ �����ϴ�.
	 �ش� ���۷����� �ʿ��� ������ at() �� ȣ���ؼ� �ٷ� ����ϴ� ���
	 ���۷��� ����, const ���۷��� ���� 2���� ��� �غ�
	 */
	std::unique_ptr<GamePiece>& at(size_t x, size_t y);
	const std::unique_ptr<GamePiece>& at(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }
	
	// static data member, ��ü�� �ƴ� Ŭ������ �Ҽ�
	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

	friend void swap(GameBoard& first, GameBoard& second) noexcept;

private:
	size_t mWidth, mHeight;
	void verifyCoordinate(size_t x, size_t y) const;
	/*
	GamePiece �� �����ϴ� �κ�. ��ü�� ������������ �ʰ�
	��ü�� ����Ű�� unique_ptr �� �����ϴ� vector,
	���� vector �� ����
	*/
	std::vector<std::vector<std::unique_ptr<GamePiece>>> mCells;
};
//--------------------------------------------------------------------------------------------------------------------//

GameBoard::GameBoard(size_t width, size_t height) : mWidth(width), mHeight(height)
{
	// vector / resize() �޼��� = count ��ŭ �迭�� ���� ������ ����
	mCells.resize(mWidth);
	// vector �ȿ� �ִ� vector �鵵 ��� resize �ؾ� �ϱ� ������ ���۷����� �̿��Ѵ�
	// auto �� const, & �� �ر� ������ �߰��� ������� �Ѵ�
	for (auto& column : mCells)
		column.resize(mHeight);
}

// ������ ũ���� �޸𸮸� �Ҵ��ϴ� �۾���, ���� �����ڿ� �����Ѵ�.
GameBoard::GameBoard(const GameBoard& src) : GameBoard(src.mWidth, src.mHeight) // ������ �̴ϼȶ�����
{
	// ���� �����ڷ� ������ ũ�⸦ �Ҵ��� ����, �����ϴ� �۾��� �����Ѵ�.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			// vector �� resize() �� �ʱ�ȭ�ϸ�, �⺻���� 0 ���� �ʱ�ȭ�ȴ�.
			if (src.mCells[i][j]) // ������ ��� ���� 0 �� �ƴ� ��, �� �̹� � ���� �����ϰ� ���� ��
				mCells[i][j] = src.mCells[i][j]->clone();
		}
	}
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight)
		// ������ ����ٴ� ���� �˸��� except
		throw std::out_of_range("");
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
	using std::swap; // ���� �������� �ʰ� swap ���ش�.

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells); // swap �� vector �� ����� �� �ִ�.
}

GameBoard& GameBoard::operator=(const GameBoard& rhs) // ���� ������
{
	// �ڱ� �ڽſ��� �����ϴ� ��츦 üũ
	if (this == &rhs)
		return *this;

	GameBoard temp(rhs); // �ӽ� �ν��Ͻ��� �Ű������� ������ ��
	swap(*this, temp); // �ӽ� �ν��Ͻ��� �ڽ��� �� �ٲٱ�
	return *this; // �׸��� ����� �ڱ��ڽ��� ����
}

// const unique_ptr<GamePiece> => ����Ʈ �����͸� const ȭ. �����Ͱ� �ٸ� ���� ����Ű�� ���ϰ� �Ѵ�.
// unique_ptr<const GamePiece> => ����Ʈ �����Ͱ� const �� ����Ų��. ����Ű�� ���� �������� ����.
const std::unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

// const ���۷����� �����ϴ� �޼��带 �̿�, �ڵ� �ߺ��� ���Ѵ�. ���� ���̾��� const_cast() ����
std::unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y)
{
	/*
	as_const(*this) => ���� ��ü ���� ����Ű��? ��Ÿ����? const ���۷����� ����
	���� at �޼��带 ȣ���ؼ� const unique_ptr �� ������ ����
	const_cast �� �̿��Ͽ� �׳� ���۷��� Ÿ������ ĳ�����Ѵ�
	*/
	return const_cast<std::unique_ptr<GamePiece>&>(std::as_const(*this).at(x, y));
}


int main()
{
	GameBoard chessBoard(5, 5);
	auto pawn = std::make_unique<ChessPiece>(); // ChessPiece ��ü�� �ϳ� ����� �װ� ����Ű�� ����Ʈ �����͸� ����. �װ� pawn

	chessBoard.at(3, 3) = std::move(pawn);
	chessBoard.at(0, 1) = std::make_unique<ChessPiece>();
	chessBoard.at(0, 1) = nullptr;
}