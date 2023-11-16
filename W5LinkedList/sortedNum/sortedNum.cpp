#include <iostream>

bool hasDigit(unsigned number, int digit)
{
	while (number != 0)
	{
		int current = number % 10;
		if (current == digit)
		{
			return true;
		}
		number /= 10;
	}
	return false;
}

int main()
{
	unsigned userInput;
	std::cin >> userInput;

	//int arr[] { 1,2,3 };

	//bool digits[10]{ 0 };

	//unsigned composedNumber = 0;
	//unsigned counter = 1;

	for (int i = 0; i < 10; i++)
	{
		if (hasDigit(userInput, i))
		{
			std::cout << i;
		}
		//digits[i] = hasDigit(userInput, i);
		/*if (hasDigit(userInput, i))
		{
			composedNumber += (i * counter);
			counter *= 10;
		}*/
	}
	
	/*for (int i = 0; i < 10; i++)
	{
		if (digits[i])
		{
			std::cout << i;
		}
	}*/
	//std::cout << composedNumber;
}
