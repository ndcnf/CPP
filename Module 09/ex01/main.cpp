#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	std::string		str(argv[1]);
	std::stack<int>	stack;
	int				new_digit = 0;
	int				b = 0;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (isspace(str[i]))
			i++;
		if (isdigit(str[i]))
		{
			// unsigned int digit = std::atoi(str[i]);
			stack.push((str[i] - '0')); ///atoi plus elegant mais je trouve pas une facon convenable de la mettre
			new_digit = str[i] - '0';
		}
		if (str[i] == '*')
		{
			b = stack.top();
			stack.pop();
			b *= stack.top();
			stack.pop();
			stack.push(b);
		}
		if (str[i] == '+')
		{
			b = stack.top();
			stack.pop();
			b = stack.top() + b;
			stack.pop();
			stack.push(b);
		}
		if (str[i] == '-')
		{
			b = stack.top();
			stack.pop();
			b = stack.top() - b;
			stack.pop();
			stack.push(b);
		}
		if (str[i] == '/')
		{
			b = stack.top();
			stack.pop();
			b = stack.top() / b;
			stack.pop();
			stack.push(b);
		}
	}

	while (!stack.empty())
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}

	return (0);
}
