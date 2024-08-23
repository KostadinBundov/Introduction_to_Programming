#include <iostream>

void generatePermutations(bool* arr, size_t size, unsigned index = 0)
{
	if (index == size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i];
		}

		std::cout << std::endl;
	}
	else
	{
		arr[index] = 0;
		generatePermutations(arr, size, index + 1);

		arr[index] = 1;
		generatePermutations(arr, size, index + 1);
	}
}

int main()
{
	size_t size;
	std::cin >> size;

	bool* arr = new bool[size] {false};

	generatePermutations(arr, size);

	delete[] arr;
}