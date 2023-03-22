#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <algorithm>
# include <stdexcept>

# include <list>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe();

		void	pairUp(int i);
		// void	startTimer();
		void	sortWithVector(int argc, char *argv[]);
		void	sortWithList(int argc, char *argv[]);
		void	printResultVector();

		class argsError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Arguments error.");
				}
		};

		class impossibleError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Operation impossible.");
				}
		};

		class invalidDataError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Invalid characters.");
				}
		};

	private:
		std::list<int>		_list;
		std::vector<int>	_vector;


};

#endif
