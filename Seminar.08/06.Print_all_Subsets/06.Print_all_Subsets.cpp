#include <iostream>

int powerOfTwo(int k)
{
	return 1 << k;
}

void printSubset(const int* arr, size_t size, unsigned mask)
{
	std::cout << "[ ";

	for (int i = 0; i < size; i++)
	{
		if (mask % 2 != 0)
		{
			std::cout << arr[i] << " ";
		}

		mask /= 2;
	}

	std::cout << "] " << std::endl;
}

void generateSubsets(const int* arr, size_t size)
{
	int border = powerOfTwo(size);

	for (int i = 0; i < border; i++)
	{
		printSubset(arr, size, i);
	}
}

int main()
{
	constexpr size_t SIZE = 1024;

	int length;
	std::cin >> length;

	int arr[SIZE];

	for (int i = 0; i < length; i++)
	{
		std::cin >> arr[i];
	}

	generateSubsets(arr, length);
}