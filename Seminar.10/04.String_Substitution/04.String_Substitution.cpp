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

bool isPrefix(const char* text, const char* pattern)
{
	if (!text || !pattern)
	{
		return false;
	}

	while (*text && *pattern)
	{
		if (*text != *pattern)
		{
			return false;
		}

		text++;
		pattern++;
	}


	return true;
}

void shiftStringRight(char* str, size_t count, size_t startIndex, size_t& strLength)
{
	size_t endIndex;

	for (int i = 0; i < count; i++)
	{
		endIndex = strLength + count;

		for (int i = endIndex; i > startIndex; i--)
		{
			str[i] = str[i - 1];
		}

		strLength = endIndex + 1;
	}
}


void shiftStringLeft(char* str, size_t count, size_t startIndex, size_t& strLength)
{
	for (int k = 0; k < count; k++)
	{	
		for (int i = startIndex + 1; i < strLength; i++)
		{
			str[i] = str[i + 1];
		}

		strLength -= 1;
	}
}

void myInsert(char* str, const char* text, size_t startIndex, size_t strLength)
{
	if (!str || !text)
	{
		return;
	}

	// we assume that the last index inserted at will not overflow 1024, as we don't use dynamic memory
	// that's why I only check the startIndex
	if (startIndex >= strLength)
	{
		return;
	}

	while (*text)
	{
		str[startIndex] = *text;
		text++;
		startIndex++;
	}
}

void substituteText(char* text, const char* whereText, const char* whatText)
{
	if (!text || !whereText || !whatText)
	{
		return;
	}

	char* textCopy = text;

	unsigned currentIndex = 0;

	size_t textLength = myStrlen(text);
	int whereLength = myStrlen(whereText);
	int whatLength = myStrlen(whatText);

	int shiftsCount =  whereLength - whatLength;

	while (*textCopy)
	{
		if (isPrefix(textCopy, whereText))
		{
			if (shiftsCount > 0)
			{
				shiftStringLeft(text, shiftsCount, currentIndex, textLength);
			}
			else if (shiftsCount < 0)
			{
				shiftStringRight(text, shiftsCount * (- 1), currentIndex, textLength);
			}

			myInsert(text, whatText, currentIndex, textLength);

			textCopy += whatLength;
			currentIndex += whatLength;
		}
		else
		{
			textCopy++;
			currentIndex++;
		}
	}
}

int main()
{
	constexpr size_t STR_MAX_SIZE = 1024;

	char text[STR_MAX_SIZE];
	char where[STR_MAX_SIZE];
	char what[STR_MAX_SIZE];

	std::cin.getline(text, STR_MAX_SIZE);
	std::cin.getline(where, STR_MAX_SIZE);
	std::cin.getline(what, STR_MAX_SIZE);

	substituteText(text, where, what);

	std::cout << text;
}