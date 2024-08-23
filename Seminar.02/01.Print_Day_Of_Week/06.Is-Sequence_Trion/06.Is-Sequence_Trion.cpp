#include <iostream>

int main()
{
	int firstNum, secondNum, thirdNum, fourthNum, fifthNum;
	std::cin >> firstNum >> secondNum >> thirdNum >> fourthNum >> fifthNum;

	if ((firstNum <= secondNum && secondNum >= thirdNum && thirdNum <= fourthNum && fourthNum >= fifthNum)
		|| (firstNum >= secondNum && secondNum <= thirdNum && thirdNum >= fourthNum && fourthNum <= fifthNum))
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}
}