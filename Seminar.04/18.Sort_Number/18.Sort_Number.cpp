#include <iostream>

unsigned getDigitsCount(int number, int digit)
{
	if (number == 0 && digit == 0)
	{
		return 1;
	}

	unsigned count = 0;

	while (number != 0)
	{
		if (number % 10 == digit)
		{
			count++;
		}

		number /= 10;
	}

	return count;
}

void concatDigitToNumber(int& number, int digit, int count)
{
	for (int i = 0; i < count; i++)
	{
		(number *= 10) += digit;
	}
}

int sortNumberDigits(int number)
{
	int result = 0;

	for (int i = 1; i <= 9; i++)
	{
		unsigned countDigit = getDigitsCount(number, i);
		concatDigitToNumber(result, i, countDigit);
	}

	return result;
}

int main()
{
	int number;
	std::cin >> number;

	std::cout << sortNumberDigits(number);
}