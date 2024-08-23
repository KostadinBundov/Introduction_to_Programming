#include <iostream>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void shakerSort(int* arr, size_t size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int smallestElementIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[smallestElementIndex] > arr[j])
			{
				smallestElementIndex = j;
			}
		}

		if (smallestElementIndex != i)
		{
			swap(arr[i], arr[smallestElementIndex]);
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