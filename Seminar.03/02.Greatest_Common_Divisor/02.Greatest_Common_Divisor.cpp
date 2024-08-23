#include <iostream>

int main()
{
	unsigned firstNumber, secondNumber;
	std::cin >> firstNumber >> secondNumber;

	if (firstNumber > secondNumber)
	{
		unsigned temp = firstNumber;
		firstNumber = secondNumber;
		secondNumber = temp;
	}

	while (firstNumber % secondNumber != 0)
	{
		unsigned temp = firstNumber;
		firstNumber = secondNumber;
		secondNumber = temp % secondNumber;
	}

	std::cout << secondNumber;
}