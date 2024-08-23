#include <iostream>

bool isSmallLetter(char ch)
{
	return 'a' <= ch && ch <= 'z';
}

bool isCapitalLetter(char ch)
{
	return 'A' <= ch && ch <= 'Z';
}

void getSmallAndUpperLettersCount(const char* str, size_t& smallLettersCount, size_t& capitalLettersCount)
{
	if (!str)
	{
		return;
	}

	while (*str)
	{
		if (isSmallLetter(*str))
		{
			smallLettersCount++;
		}
		else if (isCapitalLetter(*str))
		{
			capitalLettersCount++;
		}

		str++;
	}
}

void splitSmallAndCapitalLetters(const char* str, char* smallLetters, char* capitalLetters)
{
	if (!str || !smallLetters || !capitalLetters)
	{
		return;
	}

	while (*str)
	{
		if (isSmallLetter(*str))
		{
			*smallLetters = *str;
			smallLetters++;
		}
		else if (isCapitalLetter(*str))
		{
			*capitalLetters = *str;
			capitalLetters++;
		}

		str++;
	}
}

void splitString(const char* str, char*& smallLetters, char*& capitalLetters)
{
	if (!str)
	{
		return;
	}

	size_t smallLettersCount = 0;
	size_t capitalLettersCount = 0;
	getSmallAndUpperLettersCount(str, smallLettersCount, capitalLettersCount);

	smallLetters = new char[smallLettersCount + 1];
	capitalLetters = new char[capitalLettersCount + 1];
	smallLetters[smallLettersCount] = capitalLetters[capitalLettersCount] = '\0';

	splitSmallAndCapitalLetters(str, smallLetters, capitalLetters);
}

int main()
{
	constexpr size_t STR_MAX_LENGTH = 1024;
	char str[STR_MAX_LENGTH];

	std::cin.getline(str, STR_MAX_LENGTH);

	char* smallLetters = nullptr;
	char* capitalLetters= nullptr;

	splitString(str, smallLetters, capitalLetters);

	std::cout << smallLetters << std::endl;
	std::cout << capitalLetters << std::endl;

	delete[] smallLetters;
	delete[] capitalLetters;
}