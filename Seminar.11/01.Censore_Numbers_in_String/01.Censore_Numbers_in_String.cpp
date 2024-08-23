#include <iostream>

bool checkIsNumber(char ch)
{
	return '0' <= ch && ch <= '9';
}

unsigned getOtherSymbolsCount(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned counter = 0;

	while (*str)
	{
		if (!checkIsNumber(*str))
		{
			counter++;
		}
		
		str++;
	}

	return counter;
}

unsigned getNumbersCount(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned counter = 0;

	while (*str)
	{
		if (checkIsNumber(*str) && !checkIsNumber(*(str + 1)))
		{
			counter++;
		}

		str++;
	}

	return counter;
}

void censoreNumber(const char* str, char* censoredStr)
{
	if (!str || !censoredStr)
	{
		return;
	}

	while (*str)
	{
		if (!checkIsNumber(*str))
		{
			*censoredStr = *str;
			censoredStr++;
		}
		else if (checkIsNumber(*str) && !checkIsNumber(*(str + 1)))
		{
			*censoredStr = '*';
			censoredStr++;
		}

		str++; 
	}
}

char* censoreStr(const char* str)
{
	if (!str)
	{
		return nullptr;
	}
	
	size_t size = getNumbersCount(str) + getOtherSymbolsCount(str);
	char* censoredStr = new char[size + 1];
	censoredStr[size] = '\0';
	
	censoreNumber(str, censoredStr);

	return censoredStr;
}

int main()
{
	constexpr size_t STR_MAX_LENGTH = 1024;
	char str[STR_MAX_LENGTH];

	std::cin.getline(str, STR_MAX_LENGTH);

	char* censoredStr = censoreStr(str);

	std::cout << censoredStr;

	delete[] censoredStr;
}