#include <iostream>

bool containsNumber(const int* arr, size_t size, int number)
{
	if (!arr)
	{
		return false;
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == number)
		{
			return true;
		}
	}

	return false;
}

void rearrangeArr(int* arr, size_t size, int number)
{
	if (!arr)
	{
		return;
	}

	if (!containsNumber(arr, size, number))
	{
		return;
	}

	unsigned leftIndex = 0;
	unsigned rightIndex = size - 1;

	int* rearrangedArr = new int[size];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < number)
		{
			rearrangedArr[leftIndex++] = arr[i];
		}
		else if(arr[i] > number)
		{
			rearrangedArr[rightIndex--] = arr[i];
		}
	}

	rearrangedArr[leftIndex] = number;

	for (int i = 0; i < size; i++)
	{
		arr[i] = rearrangedArr[i];
	}

	delete[] rearrangedArr;
}

int main()
{
	int arr[100];

	unsigned size;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	int number;
	std::cin >> number;

	rearrangeArr(arr, size, number);

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}