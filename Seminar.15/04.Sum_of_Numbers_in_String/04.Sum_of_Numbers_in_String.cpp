#include <iostream>

bool isDigit(char ch)
{
	return '0' <= ch && ch <= '9';
}

unsigned longestSequence(char* str, unsigned currentNumber = 0, unsigned sum = 0)
{
	if (!*str)
	{
		return sum + currentNumber;
	}

	if (!isDigit(*str))
	{
		sum += currentNumber;
		currentNumber = 0;
	}
	else
	{
		(currentNumber *= 10) += *str -  '0';
	}

	return longestSequence(str + 1, currentNumber, sum);
}

int main()
{
	char str[1024];;
	std::cin.getline(str, 1024);
	std::cout << longestSequence(str);
}