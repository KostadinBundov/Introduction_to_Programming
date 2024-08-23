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

void countNumbersOccurrences(const int* arr, size_t size, int* counterArr)
{
	if (!arr || !counterArr)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		counterArr[100 + arr[i]]++;
	}
}

void concatNumberCountTimes(int* arr, size_t& index, int number, int count)
{
	if (!arr)
	{
		return;
	}

	for (int i = 0; i < count; i++)
	{
		arr[index++] = number;
	}
}

void sortArray(int* arr, size_t size)
{
	if (!arr)
	{
		return;
	}

	constexpr size_t tempSize = 201;
	int counterArr[tempSize]{ 0 };

	size_t index = 0;

	countNumbersOccurrences(arr, size, counterArr);

	for (int i = 0; i < tempSize; i++)
	{
		concatNumberCountTimes(arr, index, -100 + i, counterArr[i]);
	}
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