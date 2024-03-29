#include "PmergeMe.hpp"

/* this argument `jot -r 3000 1 1000 | tr '\n' ' '` is possible, but
*  not a valid input here, because no duplicates are allowed and with
*  3000 numbers between 1 and 1000, it's impossible.
*  try with ./PmergeMe `jot -r 3000 1 2000000 | tr '\n' ' '`, there are more chances
*  to have unique numbers. */
int	main(int argc, char *argv[])
{
	try
	{
		if (argc < 2)
			throw (PmergeMe::argsError());

		for (int i = 1; i < argc; i++)
		{
			if (atol(argv[i]) > std::numeric_limits<int>::max())
				throw(PmergeMe::maxIntError());

			std::string str(argv[i]);
			for (unsigned int j = 0; j < str.length(); j++)
			{
				if (!isdigit(argv[i][j]))
					throw(PmergeMe::invalidDataError());
			}
		}

		PmergeMe		pm;

		pm.duplicateDetector(argc, argv);

		std::cout << "Before: " << std::setw(2);
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl;

		pm.sortWithVector(argc, argv);
		pm.sortWithList(argc, argv);

		std::cout << "After: " << std::setw(3);
		pm.printResultVector();

		////////////////////////////////////////////////////////////////////////
		// If you prefer to see the results via list, instead of vector
		////////////////////////////////////////////////////////////////////////
		// std::cout << "After: " << std::setw(3);
		// pm.printResultList();
		////////////////////////////////////////////////////////////////////////

		std::cout	<< "Time to process a range of " << std::setw(4) << argc - 1
					<< " elements with std::vector: ";
		std::cout	<< std::setw(3)
					<< pm.getTimeVector()
					<< " us";
		std::cout	<< std::endl;

		std::cout	<< "Time to process a range of " << std::setw(4) << argc - 1
					<< " elements with std::list: ";
		std::cout	<< std::setw(3)
					<< pm.getTimeList()
					<< " us";
		std::cout	<< std::endl;

		return (0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
