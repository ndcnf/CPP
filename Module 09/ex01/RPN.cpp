#include "RPN.hpp"

RPN::RPN(): _count(0)
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
	_count = rhs._count;
	return (*this);
}

RPN::~RPN()
{

}

void	RPN::operation(char c)
{
	_valid = false;

	if (isdigit(c))
	{
		_stack.push((c - '0'));
		_count++;
		_valid = true;
	}
	else if (c == '*' || c == '+' || c == '-' || c == '/')
	{
		if (_count < 2)
			throw (impossibleError());
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
			if (_operand == 0)
			{
				_valid = false;
				throw impossibleError();
			}
			_operand = _stack.top() / _operand;
		}
		_stack.pop();
		_stack.push(_operand);
		_valid = true;
	}
	if (!_valid)
		throw invalidDataError();
}

void	RPN::printResult()
{
	if (_stack.size() != 1)
		throw (impossibleError());
	while (!_stack.empty())
	{
		std::cout << _stack.top() << std::endl;
		_stack.pop();
	}
}
