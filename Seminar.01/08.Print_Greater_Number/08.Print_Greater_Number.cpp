#include <iostream>

int main()
{
	int firstNumber, secondNumber;

	std::cin >> firstNumber >> secondNumber;

	bool isFirstGreater = firstNumber > secondNumber;

	std::cout << firstNumber* isFirstGreater + secondNumber * !isFirstGreater;
}