#include <iostream>

int myStrcmp(const char* first, const char* second)
{
	if (!first || !second)
	{
		return 0;
	}

	while (*first && *second && *first == *second)
	{
		first++;
		second++;
	}

	return *first - *second;
}

bool isLetter(char ch)
{
	return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

bool isDigit(char ch)
{
	return '0' <= ch && ch <= '9';
}

int getSeparatorIndex(const char* str, char separator)
{
	if (!str)
	{
		return -1;
	}

	int index = 0;

	while (true)
	{
		if (*str == separator || *str == '\0')
		{
			return index;
		}

		str++;
		index++;
	}

	return -1;
}

size_t getSymbolOccurrences(const char* str, char symbol)
{
	if (!str)
	{
		return 0;
	}

	size_t count = 0;

	while (*str)
	{
		if (*str == symbol)
		{
			count++;
		}

		str++;
	}

	return count;
}

void copyWord(const char* str, char* word, size_t index)
{
	for (int i = 0; i < index; i++)
	{
		word[i] = str[i];
	}
}

void skipInvalidCharacters(char*& str)
{
	if (!str)
	{
		return;
	}

	while (*str && !isLetter(*str) && !isDigit(*str))
	{
		str++;
	}
}

char** splitWords(char* str, size_t& wordsCount)
{
	wordsCount = getSymbolOccurrences(str, ' ') + 1;
	char** words = new char* [wordsCount] {nullptr};

	size_t wordIndex = 0;

	while (*str)
	{
		skipInvalidCharacters(str);

		size_t separatorIndex = getSeparatorIndex(str, ' ');
		char* word = new char[separatorIndex + 1];
		word[separatorIndex] = '\0';

		copyWord(str, word, separatorIndex);

		str += separatorIndex;
		words[wordIndex++] = word;

		if (*str == ' ')
		{
			str++;
		}
	}

	return words;
}

void print(char** words, size_t wordsCount, const bool* censoredWords)
{
	for (int i = 0; i < wordsCount; i++)
	{
		if (!censoredWords[i])
		{
			std::cout << words[i] << " ";
		}
		else
		{
			std::cout << "* ";
		}
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

void censore(bool* censoredWords, size_t index)
{
	censoredWords[index] = true;
}

void uncensore(bool* censoredWords, size_t index)
{
	censoredWords[index] = false;
}

int getWordIndex(char** words, size_t wordsCount, const char* word)
{
	for (int i = 0; i < wordsCount; i++)
	{
		if (myStrcmp(word, words[i]) == 0)
		{
			return i;
		}
	}

	return -1;
}

void changeWord(char** words, size_t wordIndex, const char* newWord)
{
	delete[] words[wordIndex];

	size_t length = getSeparatorIndex(newWord, ' ');
	words[wordIndex] = new char[length + 1];
	words[wordIndex][length] = '\0';

	copyWord(newWord, words[wordIndex], length);
}

void input(char** words, bool* censoredWords, size_t wordsCount)
{
	char command[100];
	std::cin >> command;

	if (myStrcmp(command, "censore") == 0)
	{
		size_t index;
		std::cin >> index;
		censore(censoredWords,index);
	}
	else if (myStrcmp(command, "uncensore") == 0)
	{
		size_t index;
		std::cin >> index;
		uncensore(censoredWords, index);
	}
	else if (myStrcmp(command, "change") == 0)
	{
		char word[100];
		std::cin >> word;

		int index = getWordIndex(words, wordsCount, word);

		if (index != -1)
		{
			char newWord[100];
			std::cin >> newWord;

			changeWord(words, index, newWord);
		}
	}
}

int main()
{
	constexpr size_t TEXT_MAX_LENGTH = 2048;
	char text[TEXT_MAX_LENGTH];

	std::cin.getline(text, TEXT_MAX_LENGTH);

	size_t commandsCount;
	std::cin >> commandsCount;

	size_t wordsCount = 0;
	char** words = splitWords(text, wordsCount);
	bool* censoredWords = new bool[wordsCount] {false};

	for (int i = 0; i < commandsCount; i++)
	{
		input(words, censoredWords, wordsCount);
		print(words, wordsCount, censoredWords);
	}

	free(words);
	delete[] censoredWords;
}