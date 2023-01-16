/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:47:17 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/16 10:29:14 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//////////////////////////////////////////////////////////////////////
//TODO La construction ne semble pas se faire correctement. L'exeception de FORM est appellee dans le main sous "-------- This form is eligible, finally --------" avec too low

Form::Form():
	_signed(false),
	_name("a piece of paper"),
	_signGrade(3),
	_execGrade(5)
{
	std::cout	<< _name << " needs to be filed." << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade):
	_signed(false),
	_name(name),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	if ((_signGrade < 1) || (_execGrade < 1))
		throw (Bureaucrat::GradeTooHighException());
	else if ((_signGrade > 150) || (_execGrade > 150))
		throw (Bureaucrat::GradeTooLowException());

	std::cout	<< _name << " needs to be filed." << std::endl;
}

Form::Form(Form const & src):
	_signed(false),
	_name(src._name),
	_signGrade(src._signGrade),
	_execGrade(src._execGrade)
{
	std::cout	<< "a clone has been summoned." << std::endl;
}

Form::~Form()
{
	std::cout	<< _name << " has been filed... in the shredder." << std::endl;
}

Form &Form::operator=(Form const & rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return (*this);
}

//////////////////////////////////////////////////////////////////////

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getSignGrade())
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_signed = true;
}

//////////////////////////////////////////////////////////////////////

std::string		Form::getName() const
{
	return (_name);
}

int				Form::getFormSigned() const
{
	return (_signed);
}

int				Form::getSignGrade() const
{
	return (_signGrade);
}

int				Form::getExecGrade() const
{
	return (_execGrade);
}

//////////////////////////////////////////////////////////////////////
//TODO Ici non plus, cela n'est pas appele dans le main.

std::ostream	&operator<<(std::ostream & o, Form const & rhs)
{
	std::string	printSignature;

	if (rhs.getFormSigned())
		printSignature = "signed";
	else
		printSignature = "not yet signed";

	o	<< "This form needs the following: " << std::endl
		<< "- Execution grade: " << rhs.getExecGrade() << std::endl
		<< "- Signature grade: " << rhs.getSignGrade() << std::endl
		<< "- The form is " << printSignature;

	return (o);
}

