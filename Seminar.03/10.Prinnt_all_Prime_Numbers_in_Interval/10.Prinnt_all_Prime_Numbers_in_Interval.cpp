#include <iostream>

bool isPrime(int number)
{
	int sqrtValue = sqrt(number);

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
	int a, b;
	std::cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		if (isPrime(i))
		{
			std::cout << i << " ";
		}
	}
}