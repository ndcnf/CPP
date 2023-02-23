#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	std::string		str(argv[1]);
	std::stack<int>	stack;
	int				new_digit = 0;
	int				b = 0;
	// bool			valid = false;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		// std::cout << str[i] << std::endl;
		bool	valid = false;
		if (isspace(str[i]))
			i++;
		if (isdigit(str[i]))
		{
			// unsigned int digit = std::atoi(str[i]);
			stack.push((str[i] - '0')); ///atoi plus elegant mais je trouve pas une facon convenable de la mettre
			new_digit = str[i] - '0';
			valid = true;
		}
		if (str[i] == '*')
		{
			b = stack.top();
			stack.pop();
			b *= stack.top();
			stack.pop();
			stack.push(b);
			valid = true;
		}
		if (str[i] == '+')
		{
			b = stack.top();
			stack.pop();
			b = stack.top() + b;
			stack.pop();
			stack.push(b);
			valid = true;
		}
		if (str[i] == '-')
		{
			b = stack.top();
			stack.pop();
			b = stack.top() - b;
			stack.pop();
			stack.push(b);
			valid = true;
		}
		if (str[i] == '/')
		{
			b = stack.top();
			stack.pop();
			b = stack.top() / b;
			stack.pop();
			stack.push(b);
			valid = true;
		}
		if (!valid)
		{
			std::cout << "Error." << std::endl;
			return (1);
		}
	}

	while (!stack.empty())
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}

	return (0);
}
