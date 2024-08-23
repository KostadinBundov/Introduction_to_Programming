#include <iostream>

int main()
{
	unsigned firstNumber, secondNumber;
	std::cin >> firstNumber >> secondNumber;

	unsigned max = firstNumber > secondNumber ? firstNumber : secondNumber;
	unsigned lcmCandidate = max;

	while (lcmCandidate % firstNumber != 0 || lcmCandidate % secondNumber != 0)
	{
		lcmCandidate += max;
	}

	std::cout << lcmCandidate;
}