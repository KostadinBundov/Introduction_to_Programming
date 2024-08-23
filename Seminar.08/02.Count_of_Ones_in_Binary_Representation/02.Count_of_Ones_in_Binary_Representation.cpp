#include <iostream>

unsigned getCountOfOnes(int number)
{
	unsigned count = 0;

	while (number != 0)
	{
		number &= (number - 1);
		count++;
	}

	return count;
}

int main()
{
	int number;
	std::cin >> number;

	std::cout << getCountOfOnes(number);
}