#include <iostream>

bool isSmallLetter(char ch)
{
	return 'a' <= ch && ch <= 'z';
}

unsigned getSmallLettersCount(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned counter = 0;

	while (*str)
	{
		if (isSmallLetter(*str))
		{
			counter++;
		}

		str++;
	}

	return counter;
}

void getLettersOccurrences(const char* str, unsigned* alphabet)
{
	if (!str || !alphabet)
	{
		return;
	}

	while (*str)
	{
		if (isSmallLetter(*str))
		{
			alphabet[*str - 'a']++;
		}

		str++;
	}
}

void addLeterCountTimes(char* str, char letter, unsigned& index, unsigned count)
{
	for (int i = 0; i < count; i++)
	{
		str[index] = letter;
		index++;
	}
}

void sortStr(const char* str, char* sortedStr)
{
	if (!str || !sortedStr)
	{
		return;
	}

	unsigned index = 0;

	constexpr size_t alphabetSize = 'z' - 'a' + 1;
	unsigned alphabet[alphabetSize]{ 0 };

	getLettersOccurrences(str, alphabet);

	for (int i = 0; i < alphabetSize; i++)
	{
		addLeterCountTimes(sortedStr, 'a' + i, index, alphabet[i]);
	}
}

char* formString(const char* str)
{
	size_t size = getSmallLettersCount(str);

	char* sortedStr = new char[size + 1];
	sortedStr[size] = '\0';

	sortStr(str, sortedStr);

	return sortedStr;
}

int main()
{
	constexpr size_t STR_MAX_LENGTH = 1024;
	char str[STR_MAX_LENGTH];

	std::cin.getline(str, STR_MAX_LENGTH);

	char* smallLettersSorted = formString(str);

	std::cout << smallLettersSorted << std::endl;

	delete[] smallLettersSorted;
}