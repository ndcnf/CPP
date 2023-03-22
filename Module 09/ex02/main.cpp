#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		(void)argv;
		if (argc < 2)
			throw (PmergeMe::argsError());

		std::cout << "Before: " << std::setw(2);
		// Boucle qui va afficher toutes les valeurs entrées
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl;

		std::cout << "After: " << std::setw(3);
		// Boucle qui va afficher toutes les valeurs triées
		std::cout << std::endl;


		std::cout	<< "Time to process a range of " << std::setw(3) << argc - 1
					<< " elements with std::vector: "; //<< setw(9) << time a rajouter
		std::cout	<< std::endl;

		std::cout	<< "Time to process a range of " << std::setw(3) << argc - 1
					<< " elements with std::set: "; //<< setw(9) << time a rajouter
		std::cout	<< std::endl;

		return (0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
