#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		(void)argv;
		if (argc != 2)
			throw (BitcoinExchange::argsError());

		BitcoinExchange		btc;

		btc.checkDateValidity();

		// for (int i = 1; i < argc; i++)
		// {
		// 	std::string str(argv[i]);
		// 	for (unsigned int j = 0; j < str.length(); j++)
		// 	{
		// 		if (!isdigit(argv[i][j]))
		// 			throw(BitcoinExchange::invalidDataError());
		// 	}
		// }

		return (0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
