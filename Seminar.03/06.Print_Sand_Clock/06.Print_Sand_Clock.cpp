#include <iostream>

int main()
{
	unsigned number;
	std::cin >> number;

	if (number % 2 == 0)
	{
		std::cout << "The input number must be odd!" << std::endl;
		return 0;
	}


	for (int i = number; i > 1; i-= 2)
	{
		unsigned bound = (number - i) / 2;
		for (int k = 0; k < bound; k++)
		{
			std::cout << " ";
		}

		for (int j = 0; j < i; j++)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	for (int i = 1; i <= number; i+=2)
	{
		unsigned bound = (number - i) / 2;
		for (int k = 0; k < bound; k++)
		{
			std::cout << " ";
		}

		for (int j = 0; j < i; j++)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}
}