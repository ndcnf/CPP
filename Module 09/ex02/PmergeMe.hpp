#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <algorithm>
# include <stdexcept>
# include <utility>
# include <ctime>
# include <limits>

# include <list>
# include <vector>
# include <set>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe();

		void	duplicateDetector(int argc, char *argv[]);

		void	sortWithVector(int argc, char *argv[]);
		void	sortWithList(int argc, char *argv[]);

		void	pairingVector(int num, char *argv[]);
		void	swapPairVector();
		void	copyVector();
		void	sortBinarySearchVector();

		void	pairingList(int num, char *argv[]);
		void	swapPairList();
		void	copyList();
		void	sortBinarySearchList();

		void	printResultVector();
		void	printResultList();

		clock_t	getTimeVector();
		clock_t	getTimeList();

		class maxIntError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Numbers must be integers only.");
				}
		};

		class argsError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Arguments error.");
				}
		};

		class invalidDataError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Invalid characters.");
				}
		};

		class DuplicateError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Duplicate found. They are not allowed.");
				}
		};

	private:
		std::list< std::pair<int, int> >	_list;
		std::list<int>						_sortedList;
		std::vector< std::pair<int, int> >	_vector;
		std::vector<int>					_sortedVector;
		clock_t								_timeVector;
		clock_t								_timeList;
};

#endif
