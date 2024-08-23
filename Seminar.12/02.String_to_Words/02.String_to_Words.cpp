#include <iostream>

bool isLetter(char ch)
{
	return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

size_t getWordsCount(const char* str)
{
	if (!str)
	{
		return 0;
	}

	size_t counter = 0;

	while (*str)
	{
		if (isLetter(*str) && !isLetter(*(str + 1)))
		{
			counter++;
		}

		str++;
	}

	return counter;
}

void skipInvalidCharacters(char*& str)
{
	if (!str)
	{
		return;
	}

	while (*str && !isLetter(*str))
	{
		str++;
	}
}

size_t getWordLength(const char* str)
{
	size_t length = 0;

	while (*str && isLetter(*str))
	{
		length++;
		str++;
	}

	return length;
}

char* extractWord(char*& str)
{
	size_t length = getWordLength(str);
	char* word = new char[length + 1];
	word[length] = '\0';

	for (int i = 0; i < length; i++)
	{
		word[i] = str[i];
	}

	str += length;

	return word;
}

char** splitWords(char* str, size_t& wordsCount)
{
	if (!str)
	{
		return nullptr;
	}

	wordsCount = getWordsCount(str);

	char** words = new char* [wordsCount] {nullptr};
	size_t index = 0;

	while (*str)
	{
		skipInvalidCharacters(str);

		if (!(*str))
		{
			break;
		}

		words[index++] = extractWord(str);
	}

	return words;
}

void print(char** words, size_t wordsCount)
{
	for (int i = 0; i < wordsCount; i++)
	{
		std::cout << words[i] << std::endl;
	}
}

void free(char** words, size_t wordsCount)
{
	for (int i = 0; i < wordsCount; i++)
	{
		delete[] words[i];
	}

	delete[] words;
}

int main()
{
	constexpr size_t STR_MAX_LENGTH = 1024;

	char str[STR_MAX_LENGTH];

	std::cin.getline(str, STR_MAX_LENGTH);

	size_t wordsCount = 0;

	char** words = splitWords(str, wordsCount);

	print(words, wordsCount);
	free(words, wordsCount);
}