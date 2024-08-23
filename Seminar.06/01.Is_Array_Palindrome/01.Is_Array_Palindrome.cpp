#include <iostream>

bool isArrayPalindrome(const int* arr, size_t size)
{
	unsigned border = size / 2;

	for (int i = 0; i < border; i++)
	{
		if (arr[i] != arr[size - i - 1])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	constexpr unsigned size = 7;
	int arr[size];
	
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	std::cout << isArrayPalindrome(arr, size);
}