#include <iostream>

int myMax(int a, int b)
{
	return a > b ? a : b;
}

int maxElement(const int* arr, size_t size)
{
	if (size == 0)
	{
		return INT32_MIN;
	}

	return myMax(*arr, maxElement(arr + 1, size - 1));
}

int maxElementVol2(const int* arr, size_t size)
{
	if (size == 0)
	{
		return INT32_MIN;
	}

	if (size == 1)
	{
		return *arr;
	}

	int middle = size / 2;

	return myMax(maxElementVol2(arr, middle), maxElementVol2(arr + middle, size - middle));
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

	std::cout << maxElementVol2(arr, size);
}