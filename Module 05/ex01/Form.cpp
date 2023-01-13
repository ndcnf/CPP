/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:47:17 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/13 15:14:14 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():
	_signed(false),
	_name("a piece of paper"),
	_signGrade(3),
	_execGrade(5)
{

}

Form::Form(std::string name, int signGrade, int execGrade):
	_signed(false),
	_name(name),
	_signGrade(signGrade),
	_execGrade(execGrade)
{

}

Form::Form(Form const & src):
	_signed(false),
	_name(src._name),
	_signGrade(src._signGrade),
	_execGrade(src._execGrade)
{

}

Form::~Form()
{

}

Form &Form::operator=(Form const & rhs)
{

}


std::ostream	&operator<<(std::ostream & o, Form const & rhs)
{
	std::string	printSignature;

	if (rhs.getFormSigned())
		printSignature = "signed";
	else
		printSignature = "not signed";

	o	<< "This form needs the following: " << std::endl
		<< "Execution grade: " << rhs.getExecGrade() << std::endl
		<< "Signature grade: " << rhs.getSignGrade() << std::endl
		<< "The form is " << printSignature;

	return (o);
}

void	Form::beSigned(Bureaucrat &b)
{

}
