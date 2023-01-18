/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:54:45 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/18 16:52:05 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout	<< "A new intern has been hired. For free, yay."
				<< std::endl;
}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern &Intern::operator=(Intern const & rhs)
{
	return (*this);
}

Intern::~Intern()
{
	std::cout	<< "An intern has been fired."
				<< std::endl;
}

AForm* Intern::shrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::robotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::pardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string formName, std::string targetForm)
{
	if (formName.empty())
		throw(NoForm());

	std::string	forms[N_FORMS] =	{"shrubbery creation",
									"robotomy request",
									"presidential pardon"};
	AForm		*form[N_FORMS] =	{shrubberyForm(targetForm),
									robotomyForm(targetForm),
									pardonForm(targetForm)};

	for (int i = 0; i < N_FORMS; i++)
	{
		if (formName == forms[i])
		{
			std::cout	<< "Intern creates "
						<< formName
						<< " for "
						<< targetForm
						<< std::endl;

			for (int j = i; j < N_FORMS; j++)
			{
				if (j != i)
					delete (form[j]);
			}
			return (form[i]);
		}
		else
			delete (form[i]);
	}
	return (NULL);
}

const char* Intern::NoForm::what() const throw()
{
	return ("Error: No form name has been entered.");
}
