#include <iostream>

const char ERROR_SYMBOL = '!';

bool checkIsCapitalLetter(char symbol)
{
	return 'A' <= symbol && symbol <= 'Z';
}

bool checkIsSmallLetter(char symbol)
{
	return 'a' <= symbol && symbol <= 'z';
}

char convertToCapitalLetter(char symbol)
{
	if (checkIsSmallLetter(symbol))
	{
		return symbol - 'a' + 'A';
	}
	else if (checkIsCapitalLetter(symbol))
	{
		return symbol;
	}
	else
	{
		return ERROR_SYMBOL;
	}
}

int main()
{
	char symbol;
	std::cin >> symbol;

	std::cout << convertToCapitalLetter(symbol);
}