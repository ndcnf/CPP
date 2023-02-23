#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <algorithm>
# include <cctype>

class RPN
{
	public:
		RPN();
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);
		~RPN();

		void	operation(char c);
		void	printResult();

	private:
		std::stack<int>	_stack;
		int				_operand;
		bool			_valid;
};

#endif
