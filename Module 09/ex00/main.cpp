#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw (BitcoinExchange::argsError());

		// std::string		fileContent;
		std::string		file = argv[1];
		std::string		data = "data.csv";

		BitcoinExchange		btc;

		btc.getFileContent(data);
		btc.getFileContent(file);

		// fileContent = btc.getFileContent(data);
		// fileContent = btc.getFileContent(file);

		// btc.checkDateValidity();

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
