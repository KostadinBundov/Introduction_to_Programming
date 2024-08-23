#include <iostream>

bool isArrayPalindrome(const int* arr, size_t startIndex, size_t endIndex)
{
	size_t size = endIndex - startIndex;

	unsigned border = size / 2;

	for (int i = startIndex; i < border; i++)
	{
		if (arr[i] != arr[size - i - 1])
		{
			return false;
		}
	}

	return true;
}

bool checkIsArrConcatOfPalindromes(const int* arr, size_t size)
{
	size_t endIndex = 0;

	while (endIndex < size)
	{
		if (isArrayPalindrome(arr, 0, endIndex) && isArrayPalindrome(arr, endIndex, size))
		{
			return true;
		}

		endIndex++;
	}

	return false;
}

int main()
{
	constexpr unsigned size = 9;
	int arr[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	std::cout << checkIsArrConcatOfPalindromes(arr, size);
}