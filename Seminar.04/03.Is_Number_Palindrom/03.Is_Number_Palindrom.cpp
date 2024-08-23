#include <iostream>

unsigned reverseNumber(unsigned number)
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
	int number;
	std::cin >> number;

	if (number == reverseNumber(number))
	{
		std::cout << "Palindrom";
	}
	else
	{
		std::cout << "Not a palindrom";
	}
}