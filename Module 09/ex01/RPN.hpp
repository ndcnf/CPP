#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	public:
		RPN(int i);
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);
		~RPN();

	private:
		int	_input;

		RPN();
};

#endif
