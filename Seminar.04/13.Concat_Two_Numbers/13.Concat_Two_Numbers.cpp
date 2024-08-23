#include <iostream>

int reverseNumber(int number)
{
	int reversedNumber = 0;

	while (number != 0)
	{
		(reversedNumber *= 10) += number % 10;
		number /= 10;
	}

	return reversedNumber;
}

int concatTwoNumbers(int firstNumber, int secondNumber)
{
	if (firstNumber == 0)
	{
		return 0;
	}

	if (secondNumber == 0)
	{
		return firstNumber * 10;
	}

	int reversedNumber = reverseNumber(secondNumber);

	while (reversedNumber != 0)
	{
		(firstNumber *= 10) += (reversedNumber % 10);
		reversedNumber /= 10;
	}

	while (secondNumber % 10 == 0)
	{
		firstNumber *= 10;
		secondNumber /= 10;
	}

	return firstNumber;
}

int main()
{
	int firstNumber, secondNumber;
	std::cin >> firstNumber >> secondNumber;

	std::cout << concatTwoNumbers(firstNumber, secondNumber);
}