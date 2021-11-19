#include <iostream>
#include <stack>

bool is_operator(const char &c)
{
	switch (c)
	{
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
		return true;
	default:
		return false;
	}
}

void handle_plus_minus(std::stack<char> &stack)
{
	while (!stack.empty() && stack.top() != '(')
	{
		std::cout << stack.top();
		stack.pop();
	}
}

void handle_mul_div(std::stack<char> &stack) {
	while (!stack.empty() && (stack.top() == '*' || stack.top() == '/'))
	{
		std::cout << stack.top();
		stack.pop();
	}
}

int main()
{
	std::string str;
	std::stack<char> stack;

	std::cin >> str;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (!is_operator(str[i]))
		{
			std::cout << str[i];
			continue;
		}
		switch (str[i])
		{
		case '*':
		case '/':
			handle_mul_div(stack);
		case '(':
			stack.push(str[i]);
			break;
		case '+':
		case '-':
		case ')':
			handle_plus_minus(stack);
			if (str[i] != ')')
				stack.push(str[i]);
			else
				stack.pop();
			break;
		}
	}
	while (!stack.empty())
		handle_plus_minus(stack);
	std::cout << std::endl;
	return 0;
}
