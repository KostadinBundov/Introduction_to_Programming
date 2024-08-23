#include <iostream>

static unsigned reverseNumber(unsigned number)
{
	unsigned reversedNumber = 0;

	while (number != 0)
	{
		(reversedNumber *= 10) += number % 10;
		number /= 10;
	}

	return reversedNumber;
}

int main()
{
	unsigned number;
	std::cin >> number;

	std::cout << reverseNumber(number);
}