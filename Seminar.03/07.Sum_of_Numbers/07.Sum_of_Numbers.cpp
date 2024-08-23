#include <iostream>

int main()
{
	int sum = 0;
	int inputNumber;

	std::cin >> inputNumber;

	while (true)
	{
		if (inputNumber == 0)
		{
			break;
		}

		sum += inputNumber;
		std::cin >> inputNumber;
	}

	std::cout << sum;
}