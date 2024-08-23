#include <iostream>

int findLeastRemovedElement(const int* arr, size_t size)
{
	int start = 0;
	int end = size - 1;
	int firstElement = arr[0];

	while (start <= end)
	{
		int middle = start + (end - start) / 2;

		if (middle < arr[middle] - firstElement)
		{
			end = middle - 1;
		}
		else if (middle >= arr[middle] - firstElement)
		{
			start = middle + 1;
		}
	}

	return arr[end] + 1;
}

int main()
{
	constexpr unsigned size = 7;
	int arr[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	std::cout << findLeastRemovedElement(arr, size) << std::endl;
}