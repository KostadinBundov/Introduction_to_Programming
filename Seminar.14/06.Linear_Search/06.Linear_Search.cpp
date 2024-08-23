#include <iostream>

bool binarySearch(const int* arr, size_t size, int number)
{
	if (size == 0)
	{
		return false;
	}

	return *arr == number || binarySearch(arr + 1, size - 1, number);
}

int main()
{
	int size;
	std::cin >> size;

	int arr[100];

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	int number;
	std::cin >> number;

	std::cout << binarySearch(arr, size, number);
}