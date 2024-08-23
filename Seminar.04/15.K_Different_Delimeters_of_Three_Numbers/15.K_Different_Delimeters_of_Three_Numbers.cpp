#include <iostream>

bool checkIsPrime(int number)
{
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

unsigned getNumberPrimeDivisorsCount(int number)
{
	unsigned count = 0;

	for (int i = 2; i <= number; i++)
	{
		if (number % i == 0 && checkIsPrime(i)) 
		{
			count++;
		}
	}

	return count;
}

unsigned getCommonDivisorsCount(int start, int end, int countCommonDivisors)
{
	int result = 0;

	for (int i = start; i <= end; i++)
	{
		if (getNumberPrimeDivisorsCount(i) == countCommonDivisors)
		{
			result++;
		}
	}

	return result;
}

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	std::cout << getCommonDivisorsCount(a, b, c);
}