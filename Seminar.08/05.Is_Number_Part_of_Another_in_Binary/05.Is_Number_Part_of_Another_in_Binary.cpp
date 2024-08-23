#include <iostream>

bool isPartOfNumber(int firstNumber, int secondNumber)
{
	int kBits = 0;
	int temp = secondNumber;

	while (temp > 0)
	{
		kBits++;
		temp >>= 1;
	}

	while (firstNumber >= secondNumber)
	{
		if ((firstNumber & ((1 << kBits) - 1)) == secondNumber)
		{
			return true;
		}

		firstNumber >>= 1;
	}

	return false;
}

int main()
{
	int firstNumber, secondNumber;
	std::cin >> firstNumber >> secondNumber;

	std::cout << isPartOfNumber(firstNumber, secondNumber);
}