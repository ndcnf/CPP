/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:29:08 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/16 10:34:00 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	{
		std::cout	<< "-------- Here is a form --------" << std::endl;

		try
		{
			Form	form("Jean-Charles", 6, 7);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout	<< "-------- Here is an anonymous form --------" << std::endl;

		try
		{
			Form	form;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout	<< "-------- This form is too exclusive to sign --------" << std::endl;

		try
		{
			Form	form("Universe Peace Treaty", 0, 7);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout	<< "-------- This form is too exclusive to execute --------" << std::endl;

		try
		{
			Form	form("Universe Peace Treaty", 12, 0);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout	<< "-------- This form can be signed by anyone in the world therefore shouldn\'nt --------" << std::endl;

		try
		{
			Form	form("A LIDL receipt", 300, 1);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout	<< "-------- This form can be executed by anyone in the world therefore shouldn\'nt --------" << std::endl;

		try
		{
			Form	form("A LIDL receipt", 1, 300);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout	<< "-------- This form is eligible --------" << std::endl;

		try
		{
			Bureaucrat	jeltz("Prostetnic Vogon Jeltz", 10);
			Bureaucrat	zarny("Zarniwoop", 20);
			Form		form("House Peace Treaty", 10, 20);

			std::cout	<< form << std::endl;
			jeltz.signForm(form);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
	}

	std::cout << std::endl;


	{
		std::cout	<< "-------- This form is eligible, but too exlusive for you --------" << std::endl;

		try
		{
			Bureaucrat	jeltz("Prostetnic Vogon Jeltz", 11);
			Bureaucrat	zarny("Zarniwoop", 20);
			Form		form("World Peace Treaty", 10, 20);

			std::cout	<< form << std::endl;
			jeltz.signForm(form);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
	}

	std::cout << std::endl;


	{
		std::cout	<< "-------- This form is eligible and even an intern could sign. You're more qualified than an intern. --------" << std::endl;

		try
		{
			Bureaucrat	jeltz("Prostetnic Vogon Jeltz", 11);
			Bureaucrat	zarny("Zarniwoop", 20);
			Form		form("Inner Peace Treaty", 150, 150);

			std::cout	<< form << std::endl;
			jeltz.signForm(form);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout	<< e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	//////////////////////////////////////////////////////////////////////
	// EARLIER TESTS
	//////////////////////////////////////////////////////////////////////

	// {
	// 	std::cout	<< "-------- Three random vogons, grade 150, networking --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	jeltz("Prostetnic Vogon Jeltz", 150);
	// 		Bureaucrat	vogon;
	// 		Bureaucrat	nobody = jeltz;

	// 		std::cout	<< jeltz << std::endl;
	// 		std::cout	<< vogon << std::endl;
	// 		std::cout	<< nobody << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- Two random vogons, grade 1, networking --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	mown("Constant Mown", 1);
	// 		Bureaucrat	zarny("Zarniwoop", 1);

	// 		std::cout	<< mown << std::endl;
	// 		std::cout	<< zarny << std::endl;
	// 		// mown.signForm()
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// 	std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- A random vogons made a mistake and is demoted. It ends badly. --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	guard("Vogon Guard Corps", 150);

	// 		std::cout	<< guard << std::endl;

	// 		guard.demoteBureaucrat();
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// 	std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- A random vogons made a mistake and is demoted. They're sad. --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	kwaltz("Prostetnic Kwaltz", 1);

	// 		std::cout	<< kwaltz << std::endl;

	// 		kwaltz.demoteBureaucrat();
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// 	std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- A random vogon made something kinda okay and is promoted. Already at the top --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	kwaltz("Prostetnic Kwaltz", 1);

	// 		std::cout	<< kwaltz << std::endl;

	// 		kwaltz.promoteBureaucrat();
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// 	std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- A random vogon made something kinda okay and is promoted. They are happy. --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	guard("Vogon Guard Corps", 150);

	// 		std::cout	<< guard << std::endl;

	// 		guard.promoteBureaucrat();
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// 	std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- A random made nothing, but is too low graded  --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	guard("Vogon Guard Corps", 151);

	// 		std::cout	<< guard << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// 	std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- A random made nothing, but is too high graded  --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	kwaltz("Prostetnic Kwaltz", 0);

	// 		std::cout	<< kwaltz << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	return (0);
}
