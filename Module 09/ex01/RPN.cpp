#include "RPN.hpp"

RPN::RPN(int i): _input(i)
{

}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN &RPN::operator=(RPN const &rhs)
{
	_input = rhs._input;
	return (*this);
}

RPN::~RPN()
{

}

