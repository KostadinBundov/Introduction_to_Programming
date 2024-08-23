#include <iostream>

int main()
{
	int inputNumber;
	std::cin >> inputNumber;

	bool isValidGrade = (2 <= inputNumber && inputNumber <= 6);

	std::cout << isValidGrade;
}