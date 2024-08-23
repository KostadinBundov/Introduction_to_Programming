#include <iostream>

int main()
{
	unsigned number;
	std::cin >> number;

	bool isPrime = true;
	int upperBound = sqrt(number);

	for (int i = 2; i <= upperBound; i++)
	{
		if (number % i == 0)
		{
			isPrime = false;
			break;
		}
	}


	if (isPrime)
	{
		std::cout << "prime";
	}
	else
	{
		std::cout << "not prime";
	}
}