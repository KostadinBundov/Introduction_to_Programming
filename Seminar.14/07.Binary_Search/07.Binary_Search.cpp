#include <iostream>

bool binarySearch(const int* arr, int number, int start, int end)
{
	if (start > end)
	{
		return false;
	}

	int middle = start + (end - start) / 2;

	if (arr[middle] > number)
	{
		return binarySearch(arr, number, start, middle - 1);
	}
	else if (arr[middle] < number)
	{
		return binarySearch(arr, number, middle + 1, end);
	}
	else
	{
		return true;
	}
}

bool binarySearchVol2(const int* arr, size_t size, int number)
{
	if (size == 0)
	{
		return false;
	}

	int middle = size / 2;

	if (arr[middle] == number)
	{
		return true;
	}

	if (arr[middle] > number)
	{
		return binarySearchVol2(arr, middle, number);
	}
	else
	{
		return binarySearchVol2(arr + middle + 1, size - middle - 1, number);
	}
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

	//std::cout << binarySearch(arr, number, 0, size - 1);
	std::cout << binarySearchVol2(arr, size, number);
}