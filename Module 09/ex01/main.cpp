#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	std::string		str(argv[1]);
	// std::stack<int>	stack;
	RPN	rpn;
	// int				b = 0;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (!isspace(str[i]))
			rpn.operation(str[i]);
		// std::cout << i << std::endl;

		// bool	valid = false;
		// if (isspace(str[i]))
		// 	i++;
		// if (isdigit(str[i]))
		// {
		// 	// stack.push(std::atoi(str[i]));
		// 	stack.push((str[i] - '0')); ///atoi plus elegant mais je trouve pas une facon convenable de la mettre
		// 	valid = true;
		// }
		// if (str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/')
		// {
		// 	b = stack.top();
		// 	stack.pop();

		// 	if (str[i] == '*')
		// 		b = stack.top() * b;
		// 	if (str[i] == '+')
		// 		b = stack.top() + b;
		// 	if (str[i] == '-')
		// 		b = stack.top() - b;
		// 	if (str[i] == '/')
		// 	{
		// 		// if (b == 0)
		// 		// {
		// 		// 	valid = false;
		// 		// 	return ;
		// 		// }
		// 		b = stack.top() / b;
		// 	}
		// 	stack.pop();
		// 	stack.push(b);
		// 	valid = true;
		// }
		// if (!valid)
		// {
		// 	std::cout << "Error." << std::endl;
		// 	return (1);
		// }
	}

	rpn.printResult();
	// while (!stack.empty())
	// {
	// 	std::cout << stack.top() << std::endl;
	// 	stack.pop();
	// }

	return (0);
}
