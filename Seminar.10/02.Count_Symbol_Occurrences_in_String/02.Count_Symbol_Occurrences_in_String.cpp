#include <iostream>

unsigned countSymbolOccurrences(const char* str, char symbol)
{
	if (!str)
	{
		return 0;
	}

	int counter = 0;

	while (*str)
	{
		if ((*str) == symbol)
		{
			counter++;
		}

		str += 1;
	}

	return counter;
}

int main()
{
	char str[]{ "Search the letter a" };
	char symbol = ' ';

	std::cout << countSymbolOccurrences(str, symbol);
}