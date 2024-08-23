#include <iostream>

bool isSmallLetter(char ch)
{
	return 'a' <= ch && ch <= 'z';
}

bool isCapitalLetter(char ch)
{
	return 'A' <= ch && ch <= 'Z';
}

void countSmallAndCapitalLetters(const char* str, unsigned& smallLetters, unsigned& capitalLetters)
{
	if (!*str)
	{
		return;
	}

	if (isSmallLetter(*str))
	{
		smallLetters++;
	}
	else if (isCapitalLetter(*str))
	{
		capitalLetters++;
	}
	
	return countSmallAndCapitalLetters(str + 1, smallLetters, capitalLetters);
}

int main()
{
	constexpr size_t SIZE = 1024;
	char str[SIZE];

	std::cin.getline(str, SIZE);

	unsigned small = 0;
	unsigned capital = 0;

	countSmallAndCapitalLetters(str, small, capital);

	std::cout << small << " " << capital;
}