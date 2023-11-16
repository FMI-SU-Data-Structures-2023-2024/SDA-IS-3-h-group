#include <iostream>
#include <stack>
#include <stack>
#include <cctype>

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

int main() {
	std::stack<int> numbers;
	char expression[1024];
	std::cin.getline(expression, 1024);
	
	char* currentPosition = expression;
	while (*currentPosition != '\0')
	{
		if (*currentPosition == ' ')
		{
			currentPosition += 1;
			continue;
		}

		if (isdigit(*currentPosition))
		{
			int number = 0;
			for (; isdigit(*currentPosition); ++currentPosition)
			{
				number = number*10 + (*currentPosition-'0');
			}
			numbers.push(number);
			continue;
		}

		int el2 = numbers.top();
		numbers.pop();
		int el1 = numbers.top();
		numbers.pop();
		switch (*currentPosition) {
		case '-':
			numbers.push(el1 - el2);
			break;
		case '+':
			numbers.push(el1 + el2);
			break;
		case '*':
			numbers.push(el1 * el2);
			break;
		case '/':
			numbers.push(el1 / el2);
			break;
		}
	}

	std::cout << numbers.top();

	return 0;
}