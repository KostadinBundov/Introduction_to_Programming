#include <iostream>

int main()
{
	unsigned sum;
	std::cin >> sum;

	unsigned countHundred = sum / 100;
	sum %= 100;

	unsigned countFifty = sum / 50;
	sum %= 50;

	unsigned countTwenty = sum / 20;
	sum %= 20;

	unsigned countTen = sum / 10;
	sum %= 10;

	unsigned countFive = sum / 5;
	sum %= 5;

	unsigned countTwo = sum / 2;
	
	unsigned countOne = sum %= 2;

	std::cout << countHundred << "x100lv " << countFifty << "x50lv " << countTwenty << "x20lv " << countTen << "x10lv " << countFive << "x5lv " << countTwo << "x2lv " << countOne << "x1lv ";
}