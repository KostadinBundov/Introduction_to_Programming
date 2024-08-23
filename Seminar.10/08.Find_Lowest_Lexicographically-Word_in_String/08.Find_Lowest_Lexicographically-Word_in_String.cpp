#include <iostream>

constexpr size_t STR_MAX_SIZE = 1024;

bool isCapitalLetter(char ch)
{
	return 'A' <= ch && ch <= 'Z';
}

bool isSmallLetter(char ch)
{
	return 'a' <= ch && ch <= 'z';
}

bool checkIsLetter(char ch)
{
	return isCapitalLetter(ch) || isSmallLetter(ch);
}

char convertCharToLower(char ch)
{
	if (isCapitalLetter(ch))
	{
		ch = ch - 'A' + 'a';
	}

	return ch;
}

int myStrcmp(const char* first, const char* second)
{
	if (!first || !second)
	{
		return -2;
	}

	while (*first && *second && (*first == *second))
	{
		first += 1;
		second += 1;
	}

	return convertCharToLower(*first) - convertCharToLower(*second);
}

void myStrcpy(const char* source, char* dest)
{
	if (!source || !dest)
	{
		return;
	}

	while (*source)
	{
		*dest = *source;
		source += 1;
		dest += 1;
	}

	*dest = '\0';
}

void extractWord(char*& str, char* word)
{
	while (*str && checkIsLetter(*str))
	{
		*word = *str;
		word++;
		str++;
	}

	*word = '\0';
}

void skipInvalidCharacters(char*& str)
{
	while (*str && !checkIsLetter(*str))
	{
		str++;
	}
}

void findLowestWord(char* str, char* word)
{
	if (!str || !word)
	{
		return;
	}

	char currentWord[1024];

	while (*str)
	{
		extractWord(str, currentWord);

		int result = myStrcmp(word, currentWord);

		if (result > 0)
		{
			myStrcpy(currentWord, word);
		}

		skipInvalidCharacters(str);
	}
}

int main()
{
	char str[STR_MAX_SIZE];

	std::cin.getline(str, STR_MAX_SIZE);

	char searchedWord[STR_MAX_SIZE]{ "zzzz" };

	findLowestWord(str, searchedWord);

	std::cout << searchedWord;
}