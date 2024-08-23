#include <iostream>

bool checkAreNumberDigitsEqual(int number)
{
	unsigned digit = number % 10;
	number /= 10;

	while (number != 0)
	{
		if (number % 10 != digit)
		{
			return false;
		}

		number /= 10;
	}

	return true;
}

int main()
{
	int number;
	std::cin >> number;

	std::cout << checkAreNumberDigitsEqual(number);
}