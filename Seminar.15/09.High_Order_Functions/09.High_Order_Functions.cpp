#include <iostream>

bool isDigit(char ch)
{
	return '0' <= ch && ch <= '9';
}

void printOnlyValidCharacters(const char* str, bool (*condition)(char))
{
	if (!str)
	{
		return;
	}

	while (*str)
	{
		if (condition(*str))
		{
			std::cout << (*str);
		}

		str++;
	}
}

int main()
{
	printOnlyValidCharacters("abc341XY12", isDigit);
	std::cout << std::endl;
	printOnlyValidCharacters("abc341XY12", [](char ch) {return ch > 'A'; });
}