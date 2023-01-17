/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestFormForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:14:03 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/17 11:52:02 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

//////////////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm():
	AForm("drill request", LVL_SIGN_ROB, LVL_EXEC_ROB),
	_target("a random victim")
{
	std::cout << "plugs the drill into the electricity socket" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm(target, LVL_SIGN_ROB, LVL_EXEC_ROB),
	_target(target)
{
	std::cout << "plugs the drill into the electricity socket" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):
	AForm(src)
{
	*this = src;
	std::cout	<< "a carbone copy has been made."
				<< std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout	<< "Drill is cooling off." << std::endl;
}

std::string		RobotomyRequestForm::getTarget() const
{
	return (_target);
}

//////////////////////////////////////////////////////////////////////

const char* RobotomyRequestForm::RobotomyFailed::what() const throw()
{
	return ("Drill failed. Better luck next time.");
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > this->getExecGrade())
			throw(Bureaucrat::GradeTooLowException());

		std::cout << "* LOUD DRILL NOISES *" << std::endl;

		if (_target.length() % 2)
			throw(RobotomyFailed());

		std::cout	<< "Robotomy on "
					<< _target
					<< " has been successful." << std::endl;
	}
	catch(RobotomyFailed &e)
	{
		std::cout	<< "The drill jammed and exploded. Please dispose of "
					<< _target
					<< " body."
					<< std::endl;
	}
}
