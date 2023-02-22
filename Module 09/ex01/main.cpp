#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	// (void)argv;

	if (argc != 2)
		return (1);

	std::string	str(argv[1]);

	std::stack<int>	stack;
	// std::stack<int>::iterator	it; //ITERATOR A INTEGRER

	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			i++;
		if (str[i] == '*')
		{
			std::cout << "hello: " << str[i] << std::endl;
		}
		if (str[i] == '+')
		if (str[i] == '-')
		if (str[i] == '/')
	}

	return (0);
}
