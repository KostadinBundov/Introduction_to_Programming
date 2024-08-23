#include <iostream>

size_t myStrlen(const char* str)
{
	if (!str)
	{
		return 0;
	}

	size_t length = 0;

	while (*str)
	{
		length++;
		str += 1;
	}

	return length;
}

bool isPreffix(const char* str, const char* pattern)
{
	if (!str || !pattern)
	{
		return false;
	}

	while (*str && *pattern)
	{
		if (*str == *pattern)
		{
			str += 1;
			pattern += 1;
		}
		else
		{
			return false;
		}
	}

	return *pattern == '\0';
}

bool searchInText(const char* str, const char* pattern)
{
	if (!str || !pattern)
	{
		return false;
	}

	size_t textLength = myStrlen(str);
	size_t patternLength = myStrlen(pattern);

	while (textLength >= patternLength)
	{
		if (isPreffix(str, pattern))
		{
			return true;
		}

		str += 1;
		textLength--;

	}

	return false;
}

int main()
{
	char str[1024];
	char pattern[1024];

	std::cin.getline(str, 1024);
	std::cin.getline(pattern, 1024);

	std::cout << searchInText(str, pattern);
}