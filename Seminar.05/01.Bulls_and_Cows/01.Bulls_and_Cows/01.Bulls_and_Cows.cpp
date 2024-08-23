#include <iostream>

bool checkIfNumberContainsDigit(int number, unsigned digit)
{
	if (digit == 0 && number == 0)
	{
		return false;
	}

	while (number != 0)
	{
		if (number % 10 == digit)
		{
			return true;
		}

		number /= 10;
	}

	return false;
}

bool checkAreDigitsUnique(int number)
{
	while (number != 0)
	{
		unsigned digit = number % 10;
		int numberCopy = number / 10;

		if(checkIfNumberContainsDigit(number / 10, digit))
		{
			return false;
		}

		number /= 10;
	}

	return true;
}

unsigned getDigitsCount(int number)
{
	if (number == 0)
	{
		return 1;
	}

	unsigned count = 0;

	while (number != 0)
	{
		number /= 10;
		count++;
	}

	return count;
}

bool isValidInput(int number)
{
	return number > 0 && getDigitsCount(number) == 4;
}

int input()
{
	int input;

	do
	{
		std::cin >> input;
	} while (!isValidInput(input));

	return input;
}

unsigned getCowsCount(int guessNumber, int currentNumber, unsigned bullsCount)
{
	unsigned counter = 0;

	while (guessNumber != 0)
	{
		unsigned digit = guessNumber % 10;

		if (checkIfNumberContainsDigit(currentNumber, digit))
		{
			counter++;
		}

		guessNumber /= 10;
	}

	return counter - bullsCount;
}

unsigned getBullsCount(int guessNumber, int currentNumber)
{
	unsigned counter = 0;

	while (guessNumber != 0)
	{
		if (guessNumber % 10 == currentNumber % 10)
		{
			counter++;
		}

		guessNumber /= 10;
		currentNumber /= 10;
	}

	return counter;
}

void evaluateSuggestedNumber(int guessNumber, int currentNumber, unsigned& bullsCount, unsigned& cowsCount)
{
	bullsCount = getBullsCount(guessNumber, currentNumber);
	cowsCount = getCowsCount(guessNumber, currentNumber, bullsCount);
}

int main()
{
	int searchedNumber;
	std::cin >> searchedNumber;

	int guessNumber;

	while (true)
	{
		guessNumber = input();

		if (guessNumber == searchedNumber)
		{
			std::cout << "The number is " << searchedNumber;
			break;
		}

		unsigned bullsCount = 0;
		unsigned cowsCount = 0;

		evaluateSuggestedNumber(searchedNumber, guessNumber, bullsCount, cowsCount);

		std::cout << "You have: " << bullsCount << " bulls and " << cowsCount << " cows";
	}
}