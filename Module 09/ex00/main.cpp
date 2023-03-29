#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		std::cout	<< "//////////////////////////////////" << std::endl
					<< "// WELCOME TO BITCOIN SIMULATOR //" << std::endl
					<< "//////////////////////////////////" << std::endl;

		if (argc != 2)
			throw (BitcoinExchange::argsError());

		std::string			file = argv[1];
		std::string			data = "data.csv";
		BitcoinExchange		btc;

		if (!btc.getFileContentDB(data))
			throw (BitcoinExchange::fileError());

		if (!btc.getFileContentInput(file))
			throw (BitcoinExchange::fileError());

		btc.printResult();

		// for (int i = 1; i < argc; i++)
		// {
		// 	std::string str(argv[i]);
		// 	for (unsigned int j = 0; j < str.length(); j++)
		// 	{
		// 		if (!isdigit(argv[i][j]))
		// 			throw(BitcoinExchange::invalidDataError());
		// 	}
		// }

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
