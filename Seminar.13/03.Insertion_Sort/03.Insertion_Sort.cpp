#include <iostream>

void insertionSort(int* arr, size_t size)
{
	for (int j = 1; j < size; j++)
	{
		int index = j - 1;
		int value = arr[j];

		while (index >= 0 && arr[index] > value)
		{
			arr[index + 1] = arr[index];
			index--;
		}

		arr[index + 1] = value;
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

	insertionSort(arr, size);

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	delete[] arr;
}