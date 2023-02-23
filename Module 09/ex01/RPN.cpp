#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN &RPN::operator=(RPN const &rhs)
{
	_stack = rhs._stack;
	_operand = rhs._operand;
	_valid = rhs._valid;
	return (*this);
}

RPN::~RPN()
{

}

void	RPN::operation(char c)
{
	_valid = false;

	// if (isspace(str[i]))
	// 	i++;
	if (isdigit(c))
	{
		_stack.push((c - '0'));
		_valid = true;
	}
	if (c == '*' || c == '+' || c == '-' || c == '/')
	{
		_operand = _stack.top();
		_stack.pop();

		if (c == '*')
			_operand = _stack.top() * _operand;
		if (c == '+')
			_operand = _stack.top() + _operand;
		if (c == '-')
			_operand = _stack.top() - _operand;
		if (c == '/')
		{
			// if (_operand == 0)
			// {
			// 	_valid = false;
			// 	return ;
			// }
			_operand = _stack.top() / _operand;
		}
		_stack.pop();
		_stack.push(_operand);
		_valid = true;

	}
	// std::cout << "STR[I]" << str[i] << std::endl;

	// printResult();
	if (!_valid)
	{
		std::cout << "Error." << std::endl;
		// return ; //throw
	}
}

void	RPN::printResult()
{
	while (!_stack.empty())
	{
		std::cout << _stack.top() << std::endl;
		_stack.pop();
	}
}
