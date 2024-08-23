#include <iostream>

const char ERROR_SYMBOL = '!';

char checkIsADigit(char symbol)
{
	if (symbol >= '0' && symbol <= '9')
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

	std::cout << checkIsADigit(symbol);
}