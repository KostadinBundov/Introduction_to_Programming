#include <iostream>

void getMaxAndMinDigit(int number, int& min, int& max)
{
	if (number == 0)
	{
		min = number;
		max = number;

		return;
	}

	while (number != 0)
	{
		int currDigit = number % 10;

		if (currDigit >= max)
		{
			max = currDigit;
		}

		if (currDigit <= min)
		{
			min = currDigit;
		}

		number /= 10;
	}
}

int main()
{
	int number;
	std::cin >> number;

	int min = 10;
	int max = -1;

	getMaxAndMinDigit(number, min, max);

	std::cout << max << " " << min;
}