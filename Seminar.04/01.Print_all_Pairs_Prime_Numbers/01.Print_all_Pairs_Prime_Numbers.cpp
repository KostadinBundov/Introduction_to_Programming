#include <iostream>

static bool isPrime(int number)
{
	if (number <= 1)
	{
		return false;
	}

	double sqrtValue = sqrt(number);

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
	unsigned n;
	std::cin >> n;

	for (int i = 6; i < n; i+=6)
	{
		int firstValue = i - 1;
		int secondValue = i + 1;

		if (isPrime(firstValue) && isPrime(secondValue))
		{
			std::cout << firstValue << " " << secondValue << std::endl;
		}
	}
}