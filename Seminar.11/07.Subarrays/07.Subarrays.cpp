#include <iostream>

unsigned powerOfTwo(unsigned n)
{
	return 1 << n;
}

int* formSubarray(const int* arr, size_t size, int mask)
{
	int currentSize = 0;
	int* subArr = new int[size + 1];
	size_t index = 1;

	for (int i = 0; i < size; i++)
	{
		if (mask % 2 != 0)
		{
			currentSize++;
			subArr[index++] = arr[i];
		}

		mask /= 2;
	}

	subArr[0] = currentSize;

	return subArr;
}

void formSubarrays(const int* arr, size_t size, size_t subbarraysCount, int** subArrays)
{
	for (int i = 1; i <= subbarraysCount; i++)
	{
		subArrays[i - 1] = formSubarray(arr, size, i);
	}
}

void print(int** subbarrays, size_t subbarraysCount)
{
	for (int i = 0; i < subbarraysCount; i++)
	{
		for (int j = 0; j < subbarrays[i][0]; j++)
		{
			std::cout << subbarrays[i][j + 1] << " ";
		}

		std::cout << std::endl;
	}
}

void free(int** subbarrays, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] subbarrays[i];
	}
	
	delete[] subbarrays;
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
	
	size_t subbarraysCount = powerOfTwo(size) - 1;
	int** subbarrays = new int* [subbarraysCount] {nullptr};

	formSubarrays(arr, size, subbarraysCount, subbarrays);
	print(subbarrays, subbarraysCount);
	free(subbarrays, subbarraysCount);
}