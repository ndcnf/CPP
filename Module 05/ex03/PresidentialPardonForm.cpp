/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:25:32 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/18 16:41:08 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

//////////////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm():
	AForm("pardon request", LVL_SIGN_PRE, LVL_EXEC_PRE),
	_target("a random victim")
{
	// std::cout << "Someone did something worse than Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm(target, LVL_SIGN_PRE, LVL_EXEC_PRE),
	_target(target)
{
	// std::cout << "Someone did something worse than Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):
	AForm(src)
{
	*this = src;
	std::cout	<< "a carbone copy has been made."
				<< std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout	<< "President Beeblebrox just stole the Heart of Gold and took off." << std::endl;
}

std::string		PresidentialPardonForm::getTarget() const
{
	return (_target);
}

//////////////////////////////////////////////////////////////////////

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	// try
	// {
		if (executor.getGrade() > this->getExecGrade())
			throw(Bureaucrat::GradeTooLowException());

		std::cout	<< _target
					<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
	// }
// 	catch(RobotomyFailed &e)
// 	{
// 		std::cout	<< "The drill jammed and exploded. Please dispose of "
// 					<< _target
// 					<< " body."
// 					<< std::endl;
// 	}
}
