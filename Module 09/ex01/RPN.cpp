#include "RPN.hpp"

RPN::RPN(): _countDigits(0), _countOperators(0)
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
	_countDigits = rhs._countDigits;
	_countOperators = rhs._countOperators;
	return (*this);
}

int		RPN::getCountDigits() const
{
	return (_countDigits);
}

int		RPN::getCountOperators() const
{
	return (_countOperators);
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
		_countDigits++;
		_valid = true;
	}
	else if (c == '*' || c == '+' || c == '-' || c == '/')
	{
		if (_countDigits < 2)
			throw (impossibleError());
		_countOperators++;
		_operand = _stack.top();
		if (_stack.size() < 2)
			throw (impossibleError());
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
	if (_countOperators == (_countDigits - 1))
	{
		while (!_stack.empty())
		{
			std::cout << _stack.top() << std::endl;
			_stack.pop();
		}
	}
}
