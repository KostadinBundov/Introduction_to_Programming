#include <iostream>

int myMax(int a, int b)
{
	return a > b ? a : b;
}

bool isDigit(char ch)
{
	return '0' <= ch && ch <= '9';
}

unsigned longestDigitSequence(const char* str, int currentCount = 0, int max = INT32_MIN)
{
	if (!*str)
	{
		max = myMax(currentCount, max);
		return max;
	}

	if (isDigit(*str))
	{
		currentCount += 1;
	}
	else
	{
		max = myMax(currentCount, max);
		currentCount = 0;
	}

	return longestDigitSequence(str + 1, currentCount, max);
}

int main()
{
	constexpr size_t SIZE = 1024;
	char str[SIZE];

	std::cin.getline(str, SIZE);

	std::cout << longestDigitSequence(str);
}
