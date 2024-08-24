#include <iostream>

unsigned getDigitOccurrences(int number, unsigned digit)
{
	if (number == digit)
	{
		return 1;
	}
	
	unsigned counter = 0;

	while (number != 0)
	{
		if (number % 10 == digit)
		{
			counter++;
		}

		number /= 10;
	}

	return counter;
}

bool checkForRandomPermutation(int inputNumber, int searchedNumber)
{
	if (inputNumber == searchedNumber)
	{
		return true;
	}
	
	for (int i = 0; i < 10; i++)
	{
		unsigned inInputCount = getDigitOccurrences(inputNumber, i);
		unsigned inSearchedCount = getDigitOccurrences(searchedNumber, i);

		if (inInputCount < inSearchedCount)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int a, b;
	std::cin >> a >> b;

	std::cout << checkForRandomPermutation(a, b);
}