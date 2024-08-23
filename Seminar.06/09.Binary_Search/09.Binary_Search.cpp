#include <iostream>

constexpr unsigned MAX_LENGT_ARR = 1024;

int bbinarySearch(const int* arr, size_t size, int number)
{
	unsigned start = 0;
	unsigned end = size - 1;

	int index = -1;

	while (start <= end)
	{
		unsigned middle = start + (end - start) / 2;

		if (arr[middle] > number)
		{
			end = middle - 1;
		}
		else if (arr[middle] < number)
		{
			start = middle + 1;
		}
		else
		{
			index = middle;
			break;
		}
	}

	return index;
}

int main()
{
	unsigned size;
	std::cin >> size;

	int arr[MAX_LENGT_ARR];

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	int searchedElement;
	std::cin >> searchedElement;

	std::cout << bbinarySearch(arr, size, searchedElement);
}