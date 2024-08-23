#include <iostream>

int getSplitIndex(const int* arr, size_t size)
{
	if (!arr)
	{
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			return i + 1;
		}
	}

	return -1;
}

void merge(const int* arr, size_t size, int* sortedArr, size_t firstArrStartIndex, size_t secondArrStartIndex)
{
	size_t firstArrIndex = firstArrStartIndex;
	size_t secondArrIndex = secondArrStartIndex;

	while (firstArrIndex < secondArrStartIndex && secondArrIndex < size)
	{
		if (arr[firstArrIndex] <= arr[secondArrIndex])
		{
			*sortedArr = arr[firstArrIndex];
			firstArrIndex++;
		}
		else
		{
			*sortedArr = arr[secondArrIndex];
			secondArrIndex++;
		}

		sortedArr++;
	}

	while (firstArrIndex < secondArrStartIndex)
	{
		*sortedArr = arr[firstArrIndex];
		sortedArr++;
		firstArrIndex++;
	}

	while (secondArrIndex < size)
	{
		*sortedArr = arr[secondArrIndex];
		sortedArr++;
		secondArrIndex++;
	}
}

void sortArray(int* arr, size_t size)
{
	if (!arr)
	{
		return;
	}

	int secondArrStartIndex = getSplitIndex(arr, size);

	if (secondArrStartIndex == -1)
	{
		return;
	}

	int* sortedArr = new int[size];
	merge(arr, size, sortedArr, 0, secondArrStartIndex);

	for (int i = 0; i < size; i++)
	{
		arr[i] = sortedArr[i];
	}

	delete[] sortedArr;
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

	sortArray(arr, size);

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}