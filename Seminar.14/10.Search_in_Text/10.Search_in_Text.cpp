#include <iostream>

bool isPreffix(const char* str, const char* text)
{
	if (*text == '\0')
	{
		return true;
	}

	return *str == *text && isPreffix(str + 1, text + 1);
}

bool searchInTextRec(const char* str, size_t size1, const char* text, size_t size2)
{
	if (size1 < size2)
	{
		return false;
	}

	return isPreffix(str, text) || searchInTextRec(str + 1, size1 - 1, text + 1, size2 - 1);
}

bool searchInText(const char* str, const char* text)
{
	return searchInTextRec(str, strlen(str), text, strlen(text));
}

int main()
{
	constexpr size_t SIZE = 1024;
	char str[SIZE];
	char searched[SIZE];

	std::cin.getline(str, SIZE);
	std::cin.getline(searched, SIZE);

	std::cout << searchInText(str, searched);
}