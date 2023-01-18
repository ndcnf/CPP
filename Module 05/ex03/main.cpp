/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:29:08 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/18 16:47:35 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	{
		try
		{
			std::cout	<< "-------- An intern is in charge of a robotomy request --------" << std::endl;

			Intern		someRandomIntern;
			Bureaucrat	demedeu("Julien", 3);
			AForm* rrf;

			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << demedeu << std::endl;

			demedeu.signForm(*rrf);
			demedeu.executeForm(*rrf);

			delete rrf;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

	}

	std::cout << std::endl;

	{
		try
		{
			std::cout	<< "-------- An intern is in charge of a shrubbery creation --------" << std::endl;

			Intern		someRandomIntern;
			Bureaucrat	demedeu("Julien", 3);
			AForm* rrf;

			rrf = someRandomIntern.makeForm("shrubbery creation", "Knight of Ni");
			std::cout << demedeu << std::endl;

			demedeu.signForm(*rrf);
			demedeu.executeForm(*rrf);

			delete rrf;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			std::cout	<< "-------- An intern is in charge of a presidential pardon --------" << std::endl;

			Intern		someRandomIntern;
			Bureaucrat	demedeu("Julien", 3);
			AForm* rrf;

			rrf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
			std::cout << demedeu << std::endl;

			demedeu.signForm(*rrf);
			demedeu.executeForm(*rrf);

			delete rrf;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			std::cout	<< "-------- An intern is in charge of random form. It's a disaster. --------" << std::endl;

			Intern		someRandomIntern;
			Bureaucrat	demedeu("Julien", 3);
			AForm* rrf;

			rrf = someRandomIntern.makeForm("", "Arthur Dent");
			std::cout << demedeu << std::endl;

			demedeu.signForm(*rrf);
			demedeu.executeForm(*rrf);

			delete rrf;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	return (0);
}
