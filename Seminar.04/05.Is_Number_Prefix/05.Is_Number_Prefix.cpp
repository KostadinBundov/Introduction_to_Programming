#include <iostream>

unsigned reverseNumber(unsigned number)
{
	unsigned reversedNumber = 0;

	while (number != 0)
	{
		(reversedNumber *= 10) += number % 10;
		number /= 10;
	}

	return reversedNumber;
}

bool isSuffix(int source, int value)
{
	while (value != 0)
	{
		if (value % 10 != source % 10)
		{
			return false;
		}

		value /= 10;
		source /= 10;
	}

	return true;
}

bool isPrefix(int source, int value)
{
	if (source != 0 && value == 0)
	{
		return false;
	}

	//return isSuffix(reverseNumber(source), reverseNumber(value)); // if the numbers don't end with zero

	while (source >= value)
	{
		if (value == source)
		{
			return true;
		}
		
		source /= 10;
	}

	return false;
}

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::cout << isPrefix(n, k);
}