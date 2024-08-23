#include <iostream>

bool checkAreNumberDigitsSorted(int number)
{
	unsigned lastDigit = number % 10;
	number /= 10;

	bool ascending = true;
	bool descending = true;

	while (number != 0)
	{
		unsigned currentDigit = number % 10;

		if (currentDigit > lastDigit)
		{
			ascending = false;
		}
		else if (currentDigit < lastDigit)
		{
			descending = false;
		}

		lastDigit = currentDigit;
		number /= 10;
	}

	return ascending || descending;
}

int main()
{
	int number;
	std::cin >> number;

	std::cout << checkAreNumberDigitsSorted(number);
}