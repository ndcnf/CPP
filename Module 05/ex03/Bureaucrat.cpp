/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:15:25 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/17 17:18:35 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//////////////////////////////////////////////////////////////////////

Bureaucrat::Bureaucrat():
	_name("a random Vogon"),
	_grade(150)
{
	// std::cout	<< _name << " [" << _grade << "]"
	// 			<< " glares into the void of their life."
	// 			<< std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name),
	_grade(grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	// else
	// {
		// std::cout	<< _name << " [" << _grade << "]"
		// 			<< " glares into the void of their life."
		// 			<< std::endl;
	// }
}

Bureaucrat::Bureaucrat(Bureaucrat const & src):
	_name(src.getName())
{
	*this = src;
	std::cout	<< "an other identical mindless bureaucrat has been cloned from "
				<< this->_name
				<< std::endl;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout	<< _name << " [" << _grade << "]"
	// 			<< " sighs and vanishes in their cubicule."
	// 			<< std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
	{
		// _name = rhs._name;
		_grade = rhs._grade;
	}
	return (*this);
}

//////////////////////////////////////////////////////////////////////

std::string		Bureaucrat::getName() const
{
	return (_name);
}

int				Bureaucrat::getGrade() const
{
	return (_grade);
}

//////////////////////////////////////////////////////////////////////

void	Bureaucrat::promoteBureaucrat()
{
	if ((this->_grade - 1) < 1)
		throw (GradeTooHighException());
	else
	{
		this->_grade--;
		std::cout	<< "Congrats! " << _name << " Your grade is now: "
					<< _grade << std::endl;
	}
}

void	Bureaucrat::demoteBureaucrat()
{
	if ((this->_grade + 1) > 150)
		throw (GradeTooLowException());
	else
	{
		this->_grade++;
		std::cout	<< "What have you done " << _name << "?? Your grade is now: "
					<< _grade << std::endl;
	}
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout	<< this->getName()
					<< " signed "
					<< f.getName()
					<< "."
					<< std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout	<< this->getName()
					<< " couldn\'t sign "
					<< f.getName()
					<< ". Reason: "
					<< e.what()
					<< std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & f)
{
	try
	{
		if (!f.getFormSigned())
			throw(AForm::NotSigned());
		if (this->_grade > f.getExecGrade())
			throw(GradeTooLowException());
		else
		{
			std::cout	<< this->getName()
						<< " executed "
						<< f.getName()
						<< "."
						<< std::endl;

			f.execute(*this);
		}
	}
	catch(std::exception &e)
	{
		std::cout	<< this->getName()
					<< " couldn\'t execute "
					<< f.getName()
					<< ". Reason: "
					<< e.what()
					<< std::endl;
	}










	// if (this->_grade <= f.getExecGrade() && f.getFormSigned())
	// {
	// 	std::cout	<< this->getName()
	// 				<< " executed "
	// 				<< f.getName()
	// 				<< "."
	// 				<< std::endl;
	// 	f.execute(*this);
	// }
	// else
	// {
	// 	std::cout	<< this->getName()
	// 				<< " could\'nt execute "
	// 				<< f.getName()
	// 				<< " because their grade is too low."
	// 				<< std::endl;
	// }
}

//////////////////////////////////////////////////////////////////////

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

//////////////////////////////////////////////////////////////////////

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o	<< "Hello, my name is "	<< rhs.getName()
		<< " grade, "			<< rhs.getGrade()
		<< ". Have you taken a ticket?";
	return (o);
}
