/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:47:17 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/17 17:19:06 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():
	_signed(false),
	_name("a piece of paper"),
	_signGrade(3),
	_execGrade(5)
{
	// std::cout	<< _name << " needs to be filed." << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade):
	_signed(false),
	_name(name),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	if ((_signGrade < 1) || (_execGrade < 1))
		throw (Bureaucrat::GradeTooHighException());
	else if ((_signGrade > 150) || (_execGrade > 150))
		throw (Bureaucrat::GradeTooLowException());

	// std::cout	<< _name << " needs to be filed." << std::endl;
}

AForm::AForm(AForm const & src):
	_signed(false),
	_name(src._name),
	_signGrade(src._signGrade),
	_execGrade(src._execGrade)
{
	std::cout	<< "a clone has been summoned." << std::endl;
}

AForm &AForm::operator=(AForm const & rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

AForm::~AForm()
{
	// std::cout	<< _name << " has been filed... in the shredder." << std::endl;
}

//////////////////////////////////////////////////////////////////////

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getSignGrade())
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_signed = true;
}

//////////////////////////////////////////////////////////////////////

std::string		AForm::getName() const
{
	return (_name);
}

int				AForm::getFormSigned() const
{
	return (_signed);
}

int				AForm::getSignGrade() const
{
	return (_signGrade);
}

int				AForm::getExecGrade() const
{
	return (_execGrade);
}

//////////////////////////////////////////////////////////////////////

std::ostream	&operator<<(std::ostream & o, AForm const & rhs)
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

const char* AForm::NotSigned::what() const throw()
{
	return ("This form isn\'t signed.");
}
