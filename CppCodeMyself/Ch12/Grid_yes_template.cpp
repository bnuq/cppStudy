#include <optional>

template <typename T>
class Grid
{
public:
	explicit Grid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	// 소멸자에 virtual 이 필요하기 때문에, 소멸자를 직접 선언하게 됐다.
	// 그래서 복제 생성자, 복제 대입 생성자가 자동으로 생성이 안된다.
	virtual ~Grid() = default;

	// 그래서 복제 생성자, 복제 대입 생성자가 자동으로 생성되도록 명시적으로 표시
	Grid(const Grid& src) = default;
	Grid<T>& operator=(const Grid& rhs) = default;

	// 이동 생성자, 이동 대입 생성자가 자동으로 생성되도록 명시적으로 표시
	Grid(Grid&& src) = default;
	Grid<T>& operator=(Grid&& rhs) = default;

	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;

	size_t getHeigth() const { return mHeight; }
	size_t getWidth() const { return mWidth; }

	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::optional<T>>> mCells;
	size_t mWidth, mHeight;

	// 0 초기화 문법
	T test = T();
};

template <typename T>
Grid<T>::Grid(size_t width, size_t height) : mWidth(width), mHeight(height)
{
	mCells.resize(mWidth);

	for (auto& column : mCells)
		column.resize(mHeight);
}

template <typename T>
void Grid<T>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight)
		throw std::out_of_range("");
}

template <typename T>
const std::optional<T>& Grid<T>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

template <typename T>
std::optional<T>& Grid<T>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}