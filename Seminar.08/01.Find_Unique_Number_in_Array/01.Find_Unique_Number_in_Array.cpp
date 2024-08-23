#include <iostream>

int findUniqueElement(const int* arr, size_t size)
{
	int result = 0;

	for (int i = 0; i < size; i++)
	{
		result ^= arr[i];
	}

	return result;
}

int main()
{
	constexpr size_t SIZE = 1024;

	unsigned length;
	std::cin >> length;

	int arr[SIZE];

	for (int i = 0; i < length; i++)
	{
		std::cin >> arr[i];
	}

	std::cout << findUniqueElement(arr, length);
}