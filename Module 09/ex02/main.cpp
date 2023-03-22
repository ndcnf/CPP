#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		if (argc < 2)
			throw (PmergeMe::argsError());

		for (int i = 1; i < argc; i++)
		{
			std::string str(argv[i]);
			for (unsigned int j = 0; j < str.length(); j++)
			{
				if (!isdigit(argv[i][j]))
					throw(PmergeMe::invalidDataError());
			}
		}

		PmergeMe	pm;

		std::cout << "Before: " << std::setw(2);
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl;

		pm.sortWithVector(argc, argv);
		// pm.sortWithList(argc, argv);


		std::cout << "After: " << std::setw(3);
		pm.printResultVector();

		std::cout	<< "Time to process a range of " << std::setw(4) << argc - 1
					<< " elements with std::vector: ";
		std::cout	<< std::setw(3) << "[TIME HERE]";//time a rajouter
		std::cout	<< std::endl;

		std::cout	<< "Time to process a range of " << std::setw(4) << argc - 1
					<< " elements with std::list: ";
		std::cout	<< std::setw(3) << "[TIME HERE]";//time a rajouter
		std::cout	<< std::endl;

		return (0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
