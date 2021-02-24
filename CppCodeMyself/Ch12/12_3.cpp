#include <iostream>
#include <optional>

static const size_t NOT_FOUND = static_cast<size_t>(-1);

template <typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		if (arr[i] == value) return i;

	return NOT_FOUND;
}

template <typename T>
std::optional<size_t> Find2(const T& value, const T* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		if (arr[i] == value) return i;

	return {};
}


int main()
{
	char arr[] = "spoej";
	std::cout << Find('o', arr, 5) << std::endl;

	int arr2[] = { 2,3,4,1,2,0 };
	std::cout << Find(1, arr2, 6) << std::endl;

	char arr3[] = "spoej";
	std::cout << Find2('j', arr3, 5).value_or(1000) << std::endl;

	int arr4[] = { 2,3,4,1,2,0 };
	std::cout << Find2(9, arr4, 6).value_or(1000) << std::endl;

}