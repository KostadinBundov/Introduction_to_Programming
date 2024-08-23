#include <iostream>

size_t getSeparatorCount(char* str, char separator)
{
	if (!str)
	{
		return 0;
	}

	size_t count = 0;

	while (*str)
	{
		if (*str == separator)
		{
			count++;
		}

		str++;
	}

	return count;
}

size_t getSeparatorIndex(char* str, char separator)
{
	if (!str)
	{
		return 0;
	}

	int index = 0;

	while (true)
	{
		if (*str == separator || *str == '\0')
		{
			return index;
		}

		index++;
		str++;
	}

	return index;
}

void copyNChars(const char* source, char* dest, unsigned N)
{
	for (int i = 0; i < N; i++)
	{
		dest[i] = source[i];
	}
}

char** split(char* str, char separator)
{
	if (!str)
	{
		return nullptr;
	}

	size_t splitsCount = getSeparatorCount(str, separator) + 1;
	char** splits = new char* [splitsCount + 1] { nullptr};

	size_t currentIndex = 0;

	while (*str)
	{
		size_t separatorIndex = getSeparatorIndex(str, separator);

		char* currentSplit = new char[separatorIndex + 1];
		currentSplit[separatorIndex] = '\0';
		copyNChars(str, currentSplit, separatorIndex);

		splits[currentIndex++] = currentSplit;
		str += separatorIndex;

		if (*str == separator)
		{
			str++;
		}
	}

	return splits;
}

void print(char** words)
{
	while(*words)
	{
		std::cout << *words << std::endl;
		words++;
	}
}

void free(char** words)
{
	size_t index = 0;

	while (words[index])
	{
		delete[] words[index];
		index++;
	}

	delete[] words;
}

int main()
{
	constexpr size_t STR_MAX_LENGTH = 1024;

	char str[STR_MAX_LENGTH];

	std::cin.getline(str, STR_MAX_LENGTH);

	char separator;
	std::cin >> separator;

	char** words = split(str, separator);

	print(words);
	free(words);
}