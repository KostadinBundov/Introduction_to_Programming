#include <iostream>

bool checkIsLetter(char ch)
{
	return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

unsigned getWordsCount(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned counter = 0;

	while (*str)
	{
		if (checkIsLetter(*str) && !checkIsLetter(*(str + 1)))
		{
			counter++;
		}

		str++;
	}

	return counter;
}

int main()
{
	constexpr size_t STR_MAX_SIZE = 1024;

	char str[STR_MAX_SIZE];

	std::cin.getline(str, STR_MAX_SIZE);

	std::cout << getWordsCount(str);
}