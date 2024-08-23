#include <iostream>

bool isPrimeNumber(unsigned number)
{
	unsigned sqrtValue = sqrt(number);

	for (int i = 2; i <= sqrtValue; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	unsigned number;
	std::cin >> number;

	for (int i = 2; i <= number ; i++)
	{
		if (isPrimeNumber(i))
		{
			int count = 0;

			while (number % i == 0)
			{
				count++;
				number /= i;
			}

			if (count != 0)
			{
				std::cout << i << "^" << count << " * ";
			}
		}
	}
}