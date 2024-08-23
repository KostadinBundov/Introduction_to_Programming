#include <iostream>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void shakerSort(int* arr, size_t size)
{
	int endIndex = size / 2;

	int lastSwappedIndex = size - 1;

	for (int i = 0; i < endIndex; i++)
	{
		int currentLastSwapped = 0;

		for (int j = i; j < lastSwappedIndex; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				currentLastSwapped = j;
			}
		}

		if (currentLastSwapped == 0)
		{
			break;
		}

		lastSwappedIndex = currentLastSwapped;

		for (int j = currentLastSwapped; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}

int main()
{
	size_t size;
	std::cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	shakerSort(arr, size);

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	delete[] arr;
}