#include <iostream>

bool isDigit(char ch)
{
	return '0' <= ch && ch <= '9';
}

unsigned convertToDigit(char ch)
{
	return ch - '0';
}

char convertToSymbol(int digit)
{
	return '0' + digit;
}

int convertToNumber(const char* str)
{
	if (!str)
	{
		return 0;
	}

	int number = 0;

	while (*str)
	{
		if (!isDigit(*str))
		{
			return 0;
		}

		(number *= 10) += convertToDigit(*str);
		str += 1;
	}

	return number;
}

size_t digitsCount(int number)
{
	if (number == 0)
	{
		return 1;
	}

	size_t counter = 0;

	while (number != 0)
	{
		counter++;
		number /= 10;
	}

	return counter;
}

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

void myStrcat(char* first, const char* second)
{
	if (!first || !second)
	{
		return;
	}

	size_t firstLength = myStrlen(first);
	first += firstLength;

	myStrcpy(second, first);
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

	return (*first - *second);
}



int myStratoi(const char* str)
{
	if (*str == '-')
	{
		return -1 * convertToNumber(str + 1);
	}
	else
	{
		return convertToNumber(str);
	}
}

void myToString(int number, char* str)
{
	size_t length = digitsCount(number);

	int endIndex = 0;

	if (number < 0)
	{
		str[0] = '-';
		length += 1;
		endIndex = 1;
		number *= -1;
	}

	for (int i = length - 1; i >= endIndex; i--)
	{
		str[i] = convertToSymbol(number % 10);
		number /= 10;
	}

	str[length] = '\0';
}

int main()
{
	char str[100]{ "Test for length!" };

	std::cout << myStrlen(str) << std::endl;

	char strcpy[20];
	myStrcpy(str, strcpy);
	std::cout << strcpy << std::endl;

	char str2[]{ "String to concat!" };
	myStrcat(str, str2);
	std::cout << str << std::endl;

	std::cout << myStrcmp(str, str) << std::endl;
	std::cout << myStrcmp(str, str2) << std::endl;

	char strNumber[]{ "270" };
	int number = myStratoi(strNumber);
	std::cout << number << std::endl;

	char numberToStr[10];
	myToString(number, numberToStr);
	std::cout << numberToStr << std::endl;
}