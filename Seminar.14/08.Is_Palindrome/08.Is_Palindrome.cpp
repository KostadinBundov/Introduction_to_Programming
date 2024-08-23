#include <iostream>

bool isPalindromeRec(const char* str, size_t size)
{
	if (size <= 1)
	{
		return true;
	}

	return *str == str[size - 1] && isPalindromeRec(str + 1, size - 2);
}

bool isPalindrome(const char* str)
{
	return isPalindromeRec(str, strlen(str));
}

int main()
{
	constexpr size_t SIZE = 1024;
	char str[SIZE];

	std::cin.getline(str, SIZE);

	std::cout << isPalindrome(str);
}