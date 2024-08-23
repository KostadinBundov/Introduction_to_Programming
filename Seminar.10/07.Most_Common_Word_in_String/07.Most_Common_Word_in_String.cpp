#include <iostream>

constexpr size_t ROWS_MAX_COUNT = 30;
constexpr size_t STR_MAX_LENGTH = 1024 + 1;

char words[ROWS_MAX_COUNT][STR_MAX_LENGTH + 1];


int convertToDigit(char ch)
{
	return ch - '0' + 0;
}

char convertToCharacter(int digit)
{
	return digit + '0';
}

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

void myToLower(char* str)
{
	if (!str)
	{
		return;
	}

	while (*str)
	{
		*str = convertCharToLower(*str);
		str++;
	}
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

int getWordRowIndex(const char* word, size_t count)
{
	for (int i = 0; i < ROWS_MAX_COUNT; i++)
	{
		if (myStrcmp(words[i] + 1, word) == 0)
		{
			return i;
		}
	}

	return -1;
}

void increaseWordCount(int rowIndex)
{
	int newCount = convertToDigit(words[rowIndex][0]) + 1;
	
	words[rowIndex][0] = convertToCharacter(newCount);
}

void addWord(const char* word, size_t& count)
{
	int rowIndex = getWordRowIndex(word, count);

	if (rowIndex == -1)
	{
		myStrcpy(word, words[count] + 1);
		count++;
	}
	else
	{
		increaseWordCount(rowIndex);
	}
}

void splitWords(char* str, size_t& count)
{
	if (!str)
	{
		return;
	}

	char word[STR_MAX_LENGTH];

	while (*str)
	{
		extractWord(str, word);
		
		addWord(word, count);

		skipInvalidCharacters(str);
	}
}

int getMostCommonWordRowIndex(size_t count)
{
	int mostOccurrences = INT32_MIN;
	int rowIndex = -1;

	for (int i = 0; i < count; i++)
	{
		int currentOccurrences = convertToDigit(words[i][0]);

		if (mostOccurrences < currentOccurrences)
		{
			mostOccurrences = currentOccurrences;
			rowIndex = i;
		}
	}

	return rowIndex;
}

void findMostCommonWord(char* str, char* mostCommonWord)
{
	size_t rowsCount = 0;
	myToLower(str);
	splitWords(str, rowsCount);

	int mostCommonWordRowIndex = getMostCommonWordRowIndex(rowsCount);

	myStrcpy(words[mostCommonWordRowIndex] + 1, mostCommonWord);
}

int main()
{
	char str[STR_MAX_LENGTH];
	std::cin.getline(str, STR_MAX_LENGTH);

	char mostCommonWord[STR_MAX_LENGTH];
	findMostCommonWord(str, mostCommonWord);

	std::cout << mostCommonWord;
}