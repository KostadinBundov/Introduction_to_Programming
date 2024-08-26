#include <iostream>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int* arr, size_t size)
{
	int lastSwappedIndex = size - 1;

	for (int i = 0; i < size; i++)
	{
		int currentLastSwapped = 0;

		for (int j = 0; j < lastSwappedIndex; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				currentLastSwapped = j;
			}
		}

		if(currentLastSwapped == 0)
		{
			break;
		}

		lastSwappedIndex = currentLastSwapped;
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

	bubbleSort(arr, size);

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	delete[] arr;
}