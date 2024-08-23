#include <iostream>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void generatePermutations(int* arr, size_t size, size_t currentIndex = 0)
{
	if (currentIndex == size - 1)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}

		std::cout << std::endl;
	}
	else
	{
		for (int i = currentIndex; i < size; i++)
		{
			swap(arr[currentIndex], arr[i]);
			generatePermutations(arr, size, currentIndex + 1);
			swap(arr[currentIndex], arr[i]);
		}
	}
}

int main()
{
	size_t size;
	std::cin >> size;

	int* nums = new int[size];

	for (int i = 1; i <= size; i++)
	{
		nums[i - 1] = i;
	}

	generatePermutations(nums, size);

	delete[] nums;
}