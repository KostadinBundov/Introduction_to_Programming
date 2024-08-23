#include <iostream>

bool isCapitalLetter(char ch)
{
	return 'A' <= ch && ch <= 'Z';
}

bool isSmallLetter(char ch)
{
	return 'a' <= ch && ch <= 'z';
}

void convertCharToLower(char& ch)
{
	if (isCapitalLetter(ch))
	{
		ch =  ch - 'A' + 'a';
	}
}

void convertCharToUpper(char& ch)
{
	if (isSmallLetter(ch))
	{
		ch = ch - 'a' + 'A';
	}
}

void myToLower(char* str)
{
	if (!str)
	{
		return;
	}

	while (*str)
	{
		convertCharToLower(*str);
		str++;
	}
}

void toUpper(char* str)
{
	if (!str)
	{
		return;
	}

	while (*str)
	{
		convertCharToUpper(*str);
		str++;
	}
}

int main()
{
	{
		constexpr size_t STR_MAX_SIZE = 1024;

		char str[STR_MAX_SIZE];

		std::cin.getline(str, STR_MAX_SIZE);

		myToLower(str);

		std::cout << str;
	}

	/*{
		constexpr size_t STR_MAX_SIZE = 1024;

		char str[STR_MAX_SIZE];

		std::cin.getline(str, STR_MAX_SIZE);

		toUpper(str);

		std::cout << str;
	}*/
}