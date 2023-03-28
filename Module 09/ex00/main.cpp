#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw (BitcoinExchange::argsError());

		std::string			file = argv[1];
		std::string			data = "data.cs";
		BitcoinExchange		btc;

		std::cout << "Checking db" << std::endl;
		if (!btc.getFileContentDB(data))
			throw (BitcoinExchange::fileError());

		std::cout << "checking input" << std::endl;
		if (!btc.getFileContentInput(file))
			throw (BitcoinExchange::fileError());

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
	// catch (BitcoinExchange::argsError &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// catch (BitcoinExchange::fileError &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
