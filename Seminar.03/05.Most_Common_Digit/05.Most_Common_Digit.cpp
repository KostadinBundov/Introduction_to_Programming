#include <iostream>

int main()
{
	unsigned number;
	std::cin >> number;

	if (number >= 0 && number <= 9)
	{
		std::cout << number;
		return 0;
	}

	int mostCommonDigit = -1;
	unsigned greatestCount = 0;

	for (int i = 0; i < 10; i++)
	{
		unsigned numberCopy = number;
		unsigned currentCount = 0;

		while (numberCopy != 0)
		{
			if (numberCopy % 10 == i)
			{
				currentCount++;
			}

			numberCopy /= 10;
		}

		if (currentCount > greatestCount)
		{
			mostCommonDigit = i;
			greatestCount = currentCount;
		}
	}

	std::cout << mostCommonDigit;
}