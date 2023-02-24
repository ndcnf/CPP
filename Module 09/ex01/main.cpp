#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw (RPN::argsError());

		std::string		str(argv[1]);
		RPN				rpn;

		for (unsigned int i = 0; i < str.length(); i++)
		{
			if (!isspace(str[i]))
				rpn.operation(str[i]);
		}
		if (rpn.getCountOperators() != (rpn.getCountDigits() - 1))
			throw (RPN::impossibleError());
		rpn.printResult();
		return (0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
