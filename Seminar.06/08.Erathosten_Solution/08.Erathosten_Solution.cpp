#include <iostream>

void markCompositeNumbers(bool* arr, size_t size, unsigned number)
{
	unsigned next = number + number;

	while (next <= size)
	{
		arr[next] = true;
		next += number;
	}
}

void erathostenSolution(bool* arr, size_t size)
{
	for (int i = 2; i <= size; i++)
	{
		if (!arr[i])
		{
			std::cout << i << " ";
			markCompositeNumbers(arr, size, i);
		}
	}
}

int main()
{
	unsigned number;
	std::cin >> number;

	bool arr[1024]{ false };
	erathostenSolution(arr, number);
}