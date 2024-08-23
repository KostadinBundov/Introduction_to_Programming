#include <iostream>

unsigned getDigitsCount(int number)
{
	unsigned digitsCount = 0;

	while (number != 0)
	{
		digitsCount++;
		number /= 10;
	}

	return digitsCount;
}

int main()
{
	int number;
	std::cin >> number;

	unsigned digitsCount = getDigitsCount(number);
	unsigned middle = digitsCount / 2;

	int newNumber = 0;
	int multiplier = 1;

	for (int i = 0; i < digitsCount; i++)
	{
		if ((i == middle) || (i == middle - 1 && digitsCount % 2 == 0))
		{
			number /= 10;
			continue;
		}

		newNumber = (number % 10) * multiplier + newNumber;
		number /= 10;
		multiplier *= 10;
	}

	std::cout << newNumber + 1;
}