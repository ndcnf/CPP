#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <algorithm>
# include <cctype>
# include <stdexcept>

class RPN
{
	public:
		RPN();
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);
		~RPN();

		void	operation(char c);
		void	printResult();

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
		std::stack<int>	_stack;
		int				_operand;
		bool			_valid;
		int				_count;
};

#endif
