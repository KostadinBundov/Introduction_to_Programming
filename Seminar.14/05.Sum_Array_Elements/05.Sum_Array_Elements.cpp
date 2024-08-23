#include <iostream>

int sumArr(const int* arr, int index)
{
	if (index < 0)
	{
		return 0;
	}

	return arr[index] + sumArr(arr, index - 1);
}

int containsElement(const int* arr, size_t size)
{
	if (size == 0)
	{
		return 0;
	}

	return *arr + containsElement(arr+1, size - 1);
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

	std::cout << containsElement(arr, size);
}