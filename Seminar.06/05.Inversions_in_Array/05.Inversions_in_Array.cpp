#include <iostream>

unsigned getInversionsCount(const int* arr, size_t size)
{
	unsigned count = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				count++;
			}
		}
	}

	return count;
}

int main()
{
	constexpr unsigned size = 1024;
	int arr[size];

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	std::cout << getInversionsCount(arr, n);
}