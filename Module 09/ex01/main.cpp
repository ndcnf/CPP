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
			std::cout << "digit pushed: " << str[i] << std::endl;
			stack.push((str[i] - '0')); ///atoi plus elegant mais je trouve pas une facon convenable de la mettre
			new_digit = str[i] - '0';
		}
		if (str[i] == '*')
		{
			std::cout << str[i] << std::endl;
			b = stack.top();
			stack.pop();
			b *= stack.top();
			stack.pop();
			stack.push(b);

			std::cout << "B: " << b << std::endl;

		}
		if (str[i] == '+')
		{
			std::cout << str[i] << std::endl;
			b = stack.top() + new_digit;
		}
		if (str[i] == '-')
		{
			std::cout << str[i] << std::endl;
		}
		if (str[i] == '/')
		{
			std::cout << str[i] << std::endl;
		}
		// std::cout << "TOP INTERM: " << stack.top() << std::endl;
		// std::cout << "new_digit : " << new_digit << std::endl;
		// std::cout << "b : " << b << std::endl;

	}

	std::cout << "SIZE: " << stack.size() << std::endl;
	// for (unsigned int in = 0; in < stack.size(); in++)
	while (!stack.empty())
	{
		std::cout << "FOR top " << stack.top() << std::endl;
		stack.pop();
	}

	return (0);
}
