#include <iostream>

unsigned max(int a, int b)
{
	return a > b ? a : b;
}

unsigned longestSequence(char* str, unsigned currentLength = 0, unsigned maxLength = 0)
{
	if (!*str)
	{
		return max(currentLength, maxLength);
	}

	if (*str == 'a')
	{
		currentLength += 1;
	}
	else
	{
		maxLength = max(currentLength, maxLength);
		currentLength = 0;
	}

	return longestSequence(str + 1, currentLength, maxLength);
}

int main()
{
	char str[1024];;
	std::cin.getline(str, 1024);
	std::cout << longestSequence(str);
}